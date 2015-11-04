/*
 * GTIAdaptationLogic.cpp
 *****************************************************************************
 * Copyright (C) 2010 - 2011 Klagenfurt University
 *
 * Created on: Aug 10. 2010
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

#include "GTIAdaptationLogic.h"
#include "Representationselectors.hpp"
#include "../playlist/BaseAdaptationSet.h"
#include "../playlist/BaseRepresentation.h"
#include <iostream>

using namespace std;
using namespace adaptative::logic;
using namespace adaptative::playlist;


#define __STDC_FORMAT_MACROS

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#ifndef __FUNCTION_NAME__
    #ifdef WIN32   //WINDOWS
        #define __FUNCTION_NAME__   __FUNCTION__  
    #else          //*NIX
        #define __FUNCTION_NAME__   __func__ 
    #endif
#endif



// #define DBG_MSG
#ifdef DBG_MSG
    #define DEBUG(fmt, ...) printf("\033[1;34m[%s@%i::%s()]\033[0m " fmt, __FILENAME__,__LINE__, __FUNCTION_NAME__,  ##__VA_ARGS__)
#else
    #define DEBUG(fmt, ...)
#endif


/***************************************************************/

#define MAX_CONTADOR 5

int contador = 0;
int contador2 = 1;
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

	printf("Buffer Size desde la logica: %i\n", buffer->size());
    if(adaptSet == NULL){
    	return NULL;
    }

    if(ret.size() == 0){
        std::vector<BaseRepresentation *> reps = adaptSet->getRepresentations();
		DEBUG("Reps Size: %i\n", reps.size());
		for(uint i = 0; i < reps.size(); i++){
			DEBUG("%ix%i --> %i\n", reps[i]->getWidth(), reps[i]->getHeight(), reps[i]->getBandwidth());
			if(reps[i]->getWidth() == width && reps[i]->getHeight() == height){
				ret.push_back(reps[i]);
			}
		}
		DEBUG("Size: %i\n", ret.size());
	}	

    if(sumaOresta == 0 && contador2 == MAX_CONTADOR ){
	    if(contador < ret.size() ){ 
			contador++;
		}
		if(contador == ret.size()-1){
			sumaOresta++;
		}	
		contador2 = 0;
    }

    if(sumaOresta == 1 && contador2 == MAX_CONTADOR ){
	    if(contador > 0 ){
	    	contador--;
	    }
	    if(contador == 0){
	    	sumaOresta--;
	    }

	    contador2 = 0;
	}

	contador2++;

    DEBUG("contador: %i\n", contador);
    DEBUG("%ix%i -> %i\n", ret[contador]->getWidth(), ret[contador]->getHeight(), ret[contador]->getBandwidth() );
    
    RepresentationSelector selector;
    // return selector.select(adaptSet, ret[contador]->getBandwidth(), width, height);

    BaseRepresentation *rep = selector.select(adaptSet, ret[contador]->getBandwidth(), width, height);
    if ( rep == NULL )
    {
        rep = selector.select(adaptSet);
        if ( rep == NULL )
            return NULL;
    }
    return rep;
}


/*************************************************************/

GTIAdaptationLogic::GTIAdaptationLogic    (int w, int h) :
                           AbstractAdaptationLogic      ()
{
    width  = w;
    height = h;
}

void GTIAdaptationLogic::inicializar(){
    algorithm = new GTIAlgorithm(buffer);
}

BaseRepresentation *GTIAdaptationLogic::getCurrentRepresentation(BaseAdaptationSet *adaptSet) const
{
    return algorithm->getCurrentRepresentation(adaptSet);
}

/*************************************************************/

GTIAlgorithm::GTIAlgorithm(buffer_threadSave* buff){
    buffer = buff;
    BufferMax = buffer->getMaxBufferSize();
    BufferHigh = 0.9*BufferMax;
    BufferLow = 0.6*BufferMax;
    BufferMin = 0.3*BufferMax;
    bufferOptimo = 0.5*(BufferLow + BufferHigh);
}


BaseRepresentation * GTIAlgorithm::getCurrentRepresentation(BaseAdaptationSet *adaptSet){
    
    RepresentationSelector selector;
    
    if(!init_actual_rep){
        actual_rep = selector.selectMin(adaptSet);
        init_actual_rep = true;
    }

    BaseRepresentation *Max_rep = selector.select(adaptSet);
    BaseRepresentation *Min_rep = selector.selectMin(adaptSet);
    BaseRepresentation *previous_rep = actual_rep;
    BaseRepresentation *next_rep_candidato = selector.select(adaptSet, previous_rep->getBandwidth());


    float Buff_delay = 0.0;
    int64_t duracion_segmento = 0;

    // printf("Primer if\n");
    if( RunningFastStart 
        && (actual_rep->getBandwidth() != Max_rep->getBandwidth()) 
        // && (BufferLevelMin(t1) <= BufferLevelMin(t2))
        && (actual_rep->getBandwidth() <= 0.75*bandwith) 
        ){
        if(buffer->size() < BufferMin){
            if(next_rep_candidato->getBandwidth() <= 0.33*bandwith){
                next_rep = next_rep_candidato;
            }
        } else if (buffer->size() < BufferLow){
            if(next_rep_candidato->getBandwidth() <= 0.5*bandwith){
                next_rep = next_rep_candidato;
            }
        } else {
            if(next_rep_candidato->getBandwidth() <= 0.75*bandwith){
                next_rep = next_rep_candidato;
            }
            if(buffer->size() > BufferHigh){
                Buff_delay = BufferHigh - duracion_segmento;
            }
        }
    }
    else {
        RunningFastStart = false;
        if( buffer->size() < BufferMin ){
            next_rep = Min_rep;
        }
        else if( buffer->size() < BufferLow ){
            if( (actual_rep->getBandwidth() != Min_rep->getBandwidth()) && (actual_rep->getBandwidth() >= bandwith) ){
                actual_rep = previous_rep;
                // return actual_rep;
            }       
        }
        else if( buffer->size() < BufferHigh){
            if(  (actual_rep->getBandwidth() == Max_rep->getBandwidth()) || (next_rep_candidato->getBandwidth() >= 0.9*bandwith) ){
                Buff_delay = max(BufferHigh - duracion_segmento, bufferOptimo);
            }
        }    
        else{
            if(  (actual_rep == Max_rep) || (next_rep_candidato->getBandwidth() >= 0.9*bandwith) ){
                Buff_delay = max(BufferHigh - duracion_segmento, bufferOptimo);
            }
            else{
                next_rep = next_rep_candidato;
            }
        }
    }

    /***************************************************/

    printf("%i\n",next_rep->getBandwidth() );
    BaseRepresentation *rep = selector.select(adaptSet);
    return rep;
}


