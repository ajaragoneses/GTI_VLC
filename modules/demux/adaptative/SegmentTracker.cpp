/*
 * SegmentTracker.cpp
 *****************************************************************************
 * Copyright (C) 2014 - VideoLAN and VLC authors
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/
#include "SegmentTracker.hpp"
#include "playlist/AbstractPlaylist.hpp"
#include "playlist/BaseRepresentation.h"
#include "playlist/BaseAdaptationSet.h"
#include "playlist/Segment.h"
#include "logic/AbstractAdaptationLogic.h"

using namespace adaptative;
using namespace adaptative::logic;
using namespace adaptative::playlist;


#define DBG_MSG
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#ifndef __FUNCTION_NAME__
    #ifdef WIN32   //WINDOWS
        #define __FUNCTION_NAME__   __FUNCTION__  
    #else          //*NIX
        #define __FUNCTION_NAME__   __func__ 
    #endif
#endif



#ifdef DBG_MSG
    #define DEBUG(fmt, ...) printf("\033[1;34m[%s@%i::%s()]\033[0m " fmt, __FILENAME__,__LINE__, __FUNCTION_NAME__,  ##__VA_ARGS__)
#else
    #define DEBUG(fmt, ...)
#endif


SegmentTracker::SegmentTracker(AbstractAdaptationLogic *logic_, BaseAdaptationSet *adaptSet)
{
    count = 0;
    initializing = true;
    indexed = false;
    prevRepresentation = NULL;
    setAdaptationLogic(logic_);
    adaptationSet = adaptSet;
}

SegmentTracker::~SegmentTracker()
{

}

void SegmentTracker::setAdaptationLogic(AbstractAdaptationLogic *logic_)
{
    logic = logic_;
}

void SegmentTracker::resetCounter()
{
    count = 0;
    prevRepresentation = NULL;
}

SegmentChunk * SegmentTracker::getNextChunk(bool switch_allowed)
{
    BaseRepresentation *rep;
    ISegment *segment;

    if(!adaptationSet)
        return NULL;

    if( !switch_allowed ||
       (prevRepresentation && prevRepresentation->getSwitchPolicy() == SegmentInformation::SWITCH_UNAVAILABLE) )
        rep = prevRepresentation;
    else
        rep = logic->getCurrentRepresentation(adaptationSet);

    if ( rep == NULL )
            return NULL;

    if(rep != prevRepresentation)
    {
        prevRepresentation = rep;
        // initializing = true;
    }
    // DEBUG("%s\n", "Entrando en getNextChunk");

    if(initializing)
    {
        DEBUG("%s\n", "initializing");
        initializing = false;
        segment = rep->getSegment(BaseRepresentation::INFOTYPE_INIT);
        if(segment){
        DEBUG("%s\n", "Fin inicializacion");
            return segment->toChunk(count, rep);
        }
    }


    if(!indexed)
    {
        indexed = true;
        segment = rep->getSegment(BaseRepresentation::INFOTYPE_INDEX);
        if(segment)
            return segment->toChunk(count, rep);
    }

    segment = rep->getSegment(BaseRepresentation::INFOTYPE_MEDIA, count);
    if(!segment)
    {
        // printf("RESET!\n");
        resetCounter();
        return NULL;
    }

    SegmentChunk *chunk = segment->toChunk(count, rep);
    if(chunk)
        count++;
    return chunk;
}

int64_t SegmentTracker::getTimeScale(){
    return prevRepresentation->getTimeScale();
}

bool SegmentTracker::setPosition(mtime_t time, bool restarted, bool tryonly)
{
    uint64_t segcount;
    if(prevRepresentation &&
       prevRepresentation->getSegmentNumberByTime(time, &segcount))
    {
        if(!tryonly)
        {
            if(restarted)
                initializing = true;
            count = segcount;
        }
        return true;
    }
    return false;
}

mtime_t SegmentTracker::getSegmentStart() const
{
    if(prevRepresentation)
        return prevRepresentation->getPlaybackTimeBySegmentNumber(count);
    else
        return 0;
}

void SegmentTracker::pruneFromCurrent()
{
    AbstractPlaylist *playlist = adaptationSet->getPlaylist();
    if(playlist->isLive())
        playlist->pruneBySegmentNumber(count);
}
