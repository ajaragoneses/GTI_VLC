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

        class StairsAdaptationLogic : public AbstractAdaptationLogic
        {
            public:
                StairsAdaptationLogic           (int w, int h);

                virtual BaseRepresentation *getCurrentRepresentation(BaseAdaptationSet *) const;  
        };

        class GTIAdaptationLogic : public AbstractAdaptationLogic
        {
            public:
                GTIAdaptationLogic           (int w, int h);

                virtual BaseRepresentation *getCurrentRepresentation(BaseAdaptationSet *);
                void inicializar();

            private:
            
                BaseRepresentation* next_rep;
                BaseRepresentation* actual_rep;
                bool RunningFastStart = true;
                float Buff_delay = 0.0;
                float BufferMax = 0.0;
                float BufferHigh = 0.0;
                float BufferLow = 0.0;
                float BufferMin = 0.0;
                float bufferOptimo = 0.0;
                bool inicializado = false;
        };
    }
}

#endif /* GTIADAPTATIONLOGIC_H_ */