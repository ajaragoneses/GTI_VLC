/*
 * AlwaysBestAdaptationLogic.cpp
 *****************************************************************************
 * Copyright (C) 2010 - 2011 Klagenfurt University
 *
 * Created on: Aug 10, 2010
 * Authors: Christopher Mueller <christopher.mueller@itec.uni-klu.ac.at>
 *          Christian Timmerer  <christian.timmerer@itec.uni-klu.ac.at>
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
#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "AlwaysBestAdaptationLogic.h"
#include "Representationselectors.hpp"
#include "../playlist/BaseAdaptationSet.h"
#include "../playlist/BaseRepresentation.h"

using namespace adaptative::logic;
using namespace adaptative::playlist;


#define DBG_MSG
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)


#ifdef DBG_MSG
    #define DEBUG(fmt, ...) printf("\033[1;34m[%s]\033[0m "fmt, __FILENAME__, __VA_ARGS__)
#else
    #define DEBUG(fmt, ...)
#endif

/***************************************************************/


AlwaysBestAdaptationLogic::AlwaysBestAdaptationLogic    () :
                           AbstractAdaptationLogic      ()
{
}

BaseRepresentation *AlwaysBestAdaptationLogic::getCurrentRepresentation(BaseAdaptationSet *adaptSet) const
{
    RepresentationSelector selector;
    BaseRepresentation * ret = selector.select(adaptSet);
    return ret;
}

/***************************************************************/



int contador = 0;
int contador2 = 0;
int sumaOresta = 0;
int width = 0;
int height = 0;
std::vector<BaseRepresentation *> ret;

StairsAdaptationLogic::StairsAdaptationLogic    (int w, int h) :
                           AbstractAdaptationLogic      ()
{
	width  = w;
    height = h;
}

BaseRepresentation *StairsAdaptationLogic::getCurrentRepresentation(BaseAdaptationSet *adaptSet) const
{

    if(ret.size() == 0){
		// std::vector<AdaptationSet *> adaptSets = period->getAdaptationSets(type);
        std::vector<BaseRepresentation *> reps = adaptSet->getRepresentations();
		for(uint i = 0; i < reps.size(); i++){
			if(reps[i]->getWidth() == width && reps[i]->getHeight() == height){
				ret.push_back(reps[i]);
			}
		}
		// DEBUG("Size: %i\n", ret.size());
	}	
    // DEBUG("%ix%i -> %i\n", ret[contador]->getWidth(), ret[contador]->getHeight(), ret[contador]->getBandwidth() );

    RepresentationSelector selector;
    if(sumaOresta == 0 && contador2 == 5 ){
	    if(contador < ret.size() ){ 
			contador++;
		}
		if(contador == ret.size()-1){
			sumaOresta++;
		}	
		contador2 = 0;
    }

    if(sumaOresta == 1 && contador2 == 5 ){
	    if(contador > 0 ){
	    	contador--;
	    }
	    if(contador == 0){
	    	sumaOresta--;
	    }

	    contador2 = 0;
	}

	contador2++;

    // DEBUG("contador: %i\n", contador);
    return selector.select(adaptSet, ret[contador]->getBandwidth(), width, height);
}

