/*
 * GTIAdaptationLogic.h
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

#ifndef GTIADAPTATIONLOGIC_H_
#define GTIADAPTATIONLOGIC_H_

#include "AbstractAdaptationLogic.h"

namespace adaptative
{
    namespace logic
    {
        class GTIAlgorithm
        {
            private:
                BaseRepresentation* next_rep = NULL;
                BaseRepresentation* actual_rep = NULL;
                BaseRepresentation* next_rep_candidato = NULL;
                buffer_threadSave* buffer = NULL;
                
                bool RunningFastStart = true;
                bool inicializado = false;
                bool init_actual_rep = false;
                bool notificarCambio = false;
                
                int64_t Buff_delay = 0;
                int64_t BufferMax = 0;
                int64_t BufferHigh = 0;
                int64_t BufferLow = 0;
                int64_t BufferMin = 0;
                int64_t bufferOptimo = 0;
                
                // int64_t bandwith = 0;
                int64_t bandwithAux = 0;
                int64_t totaltime = 0;
            
            public:
                GTIAlgorithm(buffer_threadSave* buff);
                BaseRepresentation *getCurrentRepresentation(BaseAdaptationSet *adapSet);
                void updateDownloadRate(size_t size, mtime_t time);
                void setCalculateDownloadRate();
        };

        class StairsAdaptationLogic : public AbstractAdaptationLogic
        {
            public:
                StairsAdaptationLogic           (int w, int h);
                virtual BaseRepresentation *getCurrentRepresentation(BaseAdaptationSet *) const;  
        };

        class GTIAdaptationLogic : public AbstractAdaptationLogic
        {
            public:
                GTIAdaptationLogic           (int w, int h, int buff);
                void updateDownloadRate(size_t size, mtime_t time);
                virtual BaseRepresentation *getCurrentRepresentation(BaseAdaptationSet *) const;
                void inicializar();
                void setCalculateDownloadRate();
                int getMaxBufferSize();
            
            private:
                GTIAlgorithm* algorithm;    

        };

    }
}

#endif /* GTIADAPTATIONLOGIC_H_ */