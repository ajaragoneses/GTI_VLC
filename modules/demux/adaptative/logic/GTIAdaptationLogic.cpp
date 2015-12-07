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

void GTIAdaptationLogic::updateDownloadRate(size_t size, mtime_t time){
    algorithm->updateDownloadRate(size,time);
}

BaseRepresentation *GTIAdaptationLogic::getCurrentRepresentation(BaseAdaptationSet *adaptSet) const
{
    return algorithm->getCurrentRepresentation(adaptSet);
}

void GTIAdaptationLogic::setCalculateDownloadRate(){
    algorithm->setCalculateDownloadRate();
}

/*************************************************************/

GTIAlgorithm::GTIAlgorithm(buffer_threadSave* buff){
    buffer = buff;
    BufferMax = buffer->getMaxBufferSize();
    BufferHigh = (BufferMax)*90/100;
    BufferLow = (BufferMax)*60/100;
    BufferMin = (BufferMax)*30/100;
    bufferOptimo = (BufferLow + BufferHigh)/2;
    printf("%lli, %lli, %lli, %lli, %lli\n", BufferMax, BufferHigh, BufferLow, BufferMin, bufferOptimo );
}

void GTIAlgorithm::updateDownloadRate(size_t size, mtime_t time)
{  
    if(unlikely(time == 0))
        return;
    
    // totaltime = time;
    totaltime = buffer->getSegmentDuration();
    bandwithAux = size;
//     if(!notificarCambio){
//         bandwithAux += size;
//     } else {
//         bandwithAux = 0;
//         // totaltime = 0;
//         notificarCambio = false;
//     }

}

BaseRepresentation * GTIAlgorithm::getCurrentRepresentation(BaseAdaptationSet *adaptSet){
    
    RepresentationSelector selector;
    
    if(!init_actual_rep){
        DEBUG("%s\n", "Iniciando actual_rep...");
        actual_rep = selector.selectMin(adaptSet);
        init_actual_rep = true;
    }

    BaseRepresentation *Max_rep = selector.select(adaptSet);
    BaseRepresentation *Min_rep = selector.selectMin(adaptSet);
    BaseRepresentation *previous_rep = actual_rep;
    BaseRepresentation *next_rep_candidato;


    // float Buff_delay = 0.0;
    int64_t duracion_segmento = 0;




    std::vector<BaseRepresentation *> reps = adaptSet->getRepresentations();
    DEBUG("Reps Size: %i\n", reps.size());
    for(uint i = 0; i < reps.size(); i++){
        DEBUG("%ix%i --> %i\n", reps[i]->getWidth(), reps[i]->getHeight(), reps[i]->getBandwidth());
        if(reps[i]->getWidth() == width && reps[i]->getHeight() == height && reps[i]->getBandwidth() >= previous_rep->getBandwidth()+1){
            next_rep_candidato = reps[i];
            break;
        }
    }

    DEBUG("previous_rep->getBandwidth(): %lli\n", previous_rep->getBandwidth());
    DEBUG("next_rep_candidato->getBandwidth(): %lli\n", next_rep_candidato->getBandwidth()); 


    printf("totaltime: %lli\n",totaltime );

    if(totaltime > 0){
        printf("totaltime: %lli\n", totaltime);
        int64_t bandwith = (1000000*(bandwithAux*16)/totaltime);
        DEBUG("actual_rep->getBandwidth() <= 0.75*bandwith: %lli ,%lli, %lli\n",actual_rep->getBandwidth(), bandwith,(bandwith)*75/100 );
        if( RunningFastStart 
            && (actual_rep->getBandwidth() != Max_rep->getBandwidth()) 
            // && (BufferLevelMin(t1) <= BufferLevelMin(t2))
            && (actual_rep->getBandwidth() <= (bandwith*75/100)) 
            ){
            if(buffer->size() < BufferMin){
                if(next_rep_candidato->getBandwidth() <= (bandwith*33/100)){
                    printf("1. %s\n", "next_rep_candidato->getBandwidth() <= 0.33*bandwith");
                    next_rep = next_rep_candidato;
                }            
            } else if (buffer->size() < BufferLow){
                if(next_rep_candidato->getBandwidth() <= (bandwith*50/100)){
                    printf("2. s\n", "next_rep_candidato->getBandwidth() <= 0.5*bandwith");
                    next_rep = next_rep_candidato;                }
            } else {
                if(next_rep_candidato->getBandwidth() <= (bandwith*50/100)){
                    printf("3. %s\n", "next_rep_candidato->getBandwidth() <= 0.5*bandwith" );
                    next_rep = next_rep_candidato;
                }
                if(buffer->size() > BufferHigh){
                    printf("4. %s\n","buffer->size() > BufferHigh" );
                    // Buff_delay = BufferHigh - totaltime;
                    Buff_delay = BufferHigh;
                    DEBUG("4. Buff_delay: %lli, size: %lli\n", Buff_delay, buffer->size() );
                    // printf("4. Espera...\n" );
                    while(buffer->size() > Buff_delay);
                    // printf("4. Fin de la espera.\n" );
                }
            }
        } else {
            // DEBUG("%i, %i, %i\n", buffer->size() , BufferMin, buffer->size() < BufferMin);
            RunningFastStart = false;
            if( buffer->size() < BufferMin ){
                printf("5. buffer->size() < BufferMin => %lli < %lli\n", buffer->size(), BufferMin);
                next_rep = Min_rep;
            }else if( buffer->size() < BufferLow ){
                if( (actual_rep->getBandwidth() != Min_rep->getBandwidth()) && (actual_rep->getBandwidth() >= bandwith) ){
                    printf("6. %s\n", "(actual_rep->getBandwidth() != Min_rep->getBandwidth()) && (actual_rep->getBandwidth() >= bandwith)");
                    actual_rep = previous_rep;
                    return actual_rep;
                }       
            }else if( buffer->size() < BufferHigh){
                if(  (actual_rep->getBandwidth() == Max_rep->getBandwidth()) || (next_rep_candidato->getBandwidth() >= (bandwith/100)*90) ){
                    printf("7. %s\n", "(actual_rep->getBandwidth() == Max_rep->getBandwidth()) || (next_rep_candidato->getBandwidth() >= 0.9*bandwith)");
                    // Buff_delay = max(BufferHigh - totaltime, bufferOptimo);
                    Buff_delay = max((int64_t)buffer->size() - 1, bufferOptimo);
                    // Buff_delay = max(buffer->size(), bufferOptimo);
                    DEBUG("7. Buff_delay: %lli, size: %lli\n", Buff_delay, buffer->size() );
                    DEBUG("7. Espera...\n" );
                    while(buffer->size() > Buff_delay);
                    DEBUG("7. Fin de la espera.\n" );

                }
            }else{
                if(  (actual_rep == Max_rep) || (next_rep_candidato->getBandwidth() >= (bandwith/100)*90) ){
                    printf("8. %s\n", "(actual_rep == Max_rep) || (next_rep_candidato->getBandwidth() >= 0.9*bandwith)");
                    // Buff_delay = max(buffer->size() - totaltime, bufferOptimo);
                    Buff_delay = max((int64_t)buffer->size() - 1, bufferOptimo);

                    // Buff_delay = max(buffer->size(), bufferOptimo);
                    // printf("%lli\n",totaltime );
                    // printf("%lli\n",bufferOptimo );

                    DEBUG("8. Espera...\n");
                    while(buffer->size() > Buff_delay);
                    DEBUG("8. Fin de la espera.\n" );

                    printf("8. Buff_delay: %lli, size: %lli\n", Buff_delay, buffer->size() );
                }
                else{
                    printf("9. %s\n", "Else");
                    next_rep = next_rep_candidato;
                }
            }
        }
    } else {
        printf("%s\n", "10. next_rep = actual_rep (default)");
        next_rep = actual_rep;
    }

    /***************************************************/

    printf("====> buffer->size(): %i\n", buffer->size());
    printf("====> next_rep->getBandwidth(): %i\n",next_rep->getBandwidth() );
    actual_rep = next_rep;
    return actual_rep;
}

void GTIAlgorithm::setCalculateDownloadRate(){
    // printf("CAMBIO!!\n");
    notificarCambio = true;
}