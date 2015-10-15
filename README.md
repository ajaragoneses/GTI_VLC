#Versión del VLC para el GTI

__Lista de ficheros modificados__
* /modules/demux/adaptative/Streams.hpp
* /modules/demux/adaptative/Streams.cpp
* /modules/demux/adaptative/SegmentTracker.hpp
* /modules/demux/adaptative/SegmentTracker.cpp


__Comandos basicos de GIT__

```sh
$ git add * # Añade todos los ficheros creados
$ git rm FICHERO # Elimina el fichero dado (para renombrar ficheros)
$ git commit -a -m "MENSAJE" # Hacer un commit
$ git git push # Subir los cambios al servidor
```

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