#Versión del VLC para el GTI

__Lista de Hitos__

_Algoritmo Buffer_

-  ~~Crear un hilo para descarga de segmentos.~~
-  ~~Crear buffer (de exclusión mutua) de cliente y otro de presentación.~~
-  ~~Obtener la escala de tiempos y la duración de cada segmento.~~
-  Calcular Duración de las congelaciones.

_Algoritmo lógica_

-  ~~Crear una lógica "Escalera".~~
-  Implementar la lógica del algoritmo dado. 


__Lista de ficheros modificados__
* /modules/demux/adaptative/Streams.hpp
* /modules/demux/adaptative/Streams.cpp
* /modules/demux/adaptative/SegmentTracker.hpp
* /modules/demux/adaptative/SegmentTracker.cpp


<!--
__Comandos basicos de GIT__

```sh
$ git add * # Añade todos los ficheros creados
$ git rm FICHERO # Elimina el fichero dado (para renombrar ficheros)
$ git commit -a -m "MENSAJE" # Hacer un commit
$ git git push # Subir los cambios al servidor
```
-->

##Algoritmos

###Algoritmo de la lógica de adaptación

```
INIT
	next_rep := actual_rep
	Buff_delay := 0
	RunningFastStart := true
	BufferHigh := 0,9*BufferMax
	BufferLow := 0,6*BufferMax
	BufferMin := 0,3*BufferMax
	bufferOptimo := 0,5*(BufferLow + BufferHigh)

ALGORITHM

IF  (RunningFastStart) ^
	(actual_rep =/= Max_rep) ^
	(BufferLevelMin(t1) <= BufferLevelMin(t2) )^
	(actual_rep <= 0,75*bandwith )
	THEN
	IF BufferLevel() < bufferMin THEN
		IF next_rep_candidato <= 0,33*bandwith THEN
			next_rep := next_rep_candidato
		ENDIF	 
	ELSE IF BufferLevel() < BufferLevelLow THEN
		IF next_rep_candidato <= 0,5*bandwith THEN
			next_rep := next_rep_candidato
		ENDIF
	ELSE 
		IF next_rep_candidato <= 0,75*bandwith THEN
			next_rep := next_rep_candidato
		ENDIF
		IF BufferLevel() > BufferHigh THEN
			Buff_delay := BufferHigh - duracion_segmento
		ENDIF
	ENDIF
ELSE
	RunningFastStart := false
	IF BufferLevel() < BufferMin THEN
		next_rep := min_rep
	ELSEIF BufferLevel() < BufferLow THEN
		IF  (actual_rep =/= min_rep)^
			(actual_rep >= bandwith)
			THEN
			actual_rep := previous_rep
		ENDIF
	ELSEIF BufferLevel() < BufferHigh THEN
		IF  (actual_rep == max_rep) V
			(next_rep_candidato >= 0.9*bandwith) 
			THEN
			Buff_delay := max(BufferLevelHigh - duracion_segmento, bufferOptimo)
		ENDIF
	ELSE
		IF  (actual_rep == rep_max) V
			(next_rep_candidato >= 0.9*bandwith) 
			THEN
			Buff_delay := max(BufferLevelHigh - duracion_segmento, bufferOptimo)
		ELSE
			next_rep := next_rep_candidato
		ENDIF
	ENDIF
ENDIF	
```


###Algoritmo del buffer

```
Buffer<Segmentos> bufferCliente;
Buffer<Segmentos> bufferPresentacion;
int tiempoDescarga;
int duracionSegmento; // en segundos
int bitrateSiguienteSegmento; 
int bitrateAnchoBanda;
int segundosPorPresentar;
bool congelacion = false;
int duracionCongelacion;
int contadorSegmentos = 0;
int segundosDelayBuffer = ??? ;

// Buffer cliente NO vacío
if(bufferCliente.getTotalSecondsInBuffer() != 0){
	// Calcular tiempo de descarga
	tiempoDescarga = (duracionSegmento * bitrateSiguienteSegmento) / bitrateAnchoBanda;

	/*******************/
	// tiempoDescarga = (tamañoSegmento) / bitrateAnchoBanda
	/*******************/

	// Hay más segundos en el buffer de presentacion que lo que se tarda en descargar
	if(bufferPresentacion.getTotalSecondsInBuffer() >= tiempoDescarga){
		// "Empujamos" los segundos del buffer a presentar
		bufferPresentacion.presentSeconds(tiempoDescarga);
	} 
	// NO hay más segundos en el buffer de presentacion que lo que se tarda en descargar
	else {
		// Calculamos cuanto queda por descargar y cuantos paquetes hay que extraer
		segundosPorPresentar = tiempoDescarga - bufferPresentacion.getTotalSecondsInBuffer();
		PaquetesAExtraer = ceil(segundosPorPresentar / duracionSegmento);
		
		// Hay que extraer más paquetes de los que existen
		if(paquetesAExtraer > bufferCliente.size()){
			// Fijamos que solo se extraiga lo que hay
            paquetesAExtraer = bufferCliente.size();
            // Se produce congelación y la duración de la misma
            congelacion = true; 
            duracionCongelacion = segundosPorPresentar - bufferCliente.getTotalSecondsInBuffer();
		}
		// Hay que extraer MENOS de lo que existen en el buffer 
		else {
			congelacion = false; 
			duracionCongelacion = 0;
			// Actualizamos el búfer de presentación: Número de segundos del último segmento que ha salido del búfer, que no se han presentado al usuario.           
			// buffer_presentation = abs(aux_time - segm_decoded*Tseg);
		}
	}

	// Si no hay congelación
	if (!congelacion){	
		// Descargar segmento y mandarlos al buffer de presentacion
		bufferCliente.getSegmentFromServer();
		bufferCliente.sendSegmentsTo(PaquetesAExtraer, bufferPresentacion);
	} 
	// Si hay congelación
	else {
		// Descargar UN segmento y mandarlo al buffer de prensentación
		bufferCliente.getSegmentFromServer();
		bufferCliente.sendSegmentsTo(1, bufferPresentacion);
	}
} 

// Buffer cliente Vacío
else {
	tiempoDescarga = (duracionSegmento * bitrateSiguienteSegmento) / bitrateAnchoBanda;
	PaquetesAExtraer = 0;
 
 	// Si es el primer segmento de la sesión No podemos considerar que ha habido congelación
	if (contadorSegmentos == 1){
        bufferPresentacion.empty();
        congelacion = false;
		duracionCongelacion = 0;
        bufferCliente.getSegmentFromServer();
	} 
	// No es el primer segmento
	else {
		// Hay más segundos en el buffer de presentacion que el tiempo que se tarda en descargar un nuevo segmento
        if(bufferPresentacion.getTotalSecondsInBuffer() >= tiempoDescarga){
        	// Empujamos los segmentos para que se presenten
            bufferPresentacion.presentSeconds(tiempoDescarga);
            // No calculamos aux_time porque no vamos a sacar ningún segmento del búfer de cliente
            // Cancelamos la congelación y obtenemos un nuevo segmento en el buffer del cliente
	        congelacion = false;
			duracionCongelacion = 0;
	        bufferCliente.getSegmentFromServer();        
        } 
        // No hay más segundos en el buffer que el tiempo que se tarda en descargar un nuevo segmento
        else {
        	// Establecemos que hay congelación y calculamos su duración
            congelacion = true;
			duracionCongelacion = tiempoDescarga - bufferPresentacion.getTotalSecondsInBuffer();

			// Vaciamos el buffer cliente y obtenemos un nuevo segmento, que mandamos al buffer de presentación
            bufferCliente.empty();
        	bufferCliente.getSegmentFromServer();
			bufferCliente.sendSegmentsTo(1, bufferPresentacion);
        }                    
	} 
}

// Retraso de la obtención del siguiente segmento
if ((segundosDelayBuffer != 0){
	bufferPresentacion.empty();
	PaquetesAExtraer = ((bufferCliente.getTotalSecondsInBuffer() - segundosDelayBuffer) / duracionSegmento) + 1; 
	bufferCliente.extraerPaquetes(PaquetesAExtraer);
}
```