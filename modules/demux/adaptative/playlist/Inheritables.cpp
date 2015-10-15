/*****************************************************************************
 * Inheritables.cpp
 *****************************************************************************
 * Copyright (C) 1998-2015 VLC authors and VideoLAN
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
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

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "Inheritables.hpp"
#include "SegmentTimeline.h"

using namespace adaptative::playlist;

Timelineable::Timelineable()
{
    segmentTimeline.Set(NULL);
}

Timelineable::~Timelineable()
{
    delete segmentTimeline.Get();
}

TimescaleAble::TimescaleAble(TimescaleAble *parent)
{
    timescale.Set(0);
    parentTimescale = parent;
}

TimescaleAble::~TimescaleAble()
{
}

uint64_t TimescaleAble::inheritTimescale() const
{
    if(timescale.Get()){
        // printf("1.===========> %i\n", timescale.Get());
        // printf("1\n");
        return timescale.Get();
    }
    else if(parentTimescale){
        // printf("2\n");
        // printf("2.===========> %i\n", parentTimescale->inheritTimescale());
        return parentTimescale->inheritTimescale();
    }
    else{
        // printf("3\n");
        return 1;
    }
}

