/*
 * Streams.cpp
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
#include "Streams.hpp"
#include "StreamsType.hpp"
#include "http/HTTPConnection.hpp"
#include "http/HTTPConnectionManager.h"
#include "logic/AbstractAdaptationLogic.h"
#include "playlist/SegmentChunk.hpp"
#include "SegmentTracker.hpp"
#include <vlc_stream.h>
#include <vlc_demux.h>
#include <vector>
#include <inttypes.h>
#include <math.h>       /* ceil */

using namespace adaptative;
using namespace adaptative::http;
using namespace adaptative::logic;
using namespace std;

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

// #define BUFFER_MSG
#ifdef BUFFER_MSG
    #define PRINT_BUFFER(buff_name, buff)  \
        printf("\033[1;34m[%s@%i::%s()]\033[0mContenido del buffer %s: ", __FILENAME__,__LINE__, __FUNCTION_NAME__, buff_name );  \
        for (std::list<data_download*>::iterator it=buff.begin(); it != buff.end(); ++it){  \
            printf("%p, ", (*it)->buffer);  \
        }  \
        printf("\n");
#else
    #define PRINT_BUFFER(buff_name, buff)
#endif    

#define MAX_BUFFER 5

// #define NO_BUFFER

vlc_mutex_t  lock_conMannager;
#ifndef NO_BUFFER
    vlc_mutex_t  lock;
    vlc_cond_t   no_lleno;
    vlc_cond_t   no_vacio;
#endif
vlc_cond_t   no_connManager;
bool thread_end = false;
HTTPConnectionManager *connManagerGlobal = NULL;

buffer_threadSave *buffer;

void *Stream::EventThread(void *data){
    static_cast<Stream*>(data)->thread_buffer();
    return NULL;
}

void *Stream::thread_buffer(){
    printf("thread_end: %i\n", thread_end);
    while(!eof){
        vlc_mutex_lock(&lock_conMannager);
        while (connManagerGlobal == NULL){ /* No hay connManagerGlobal */
            DEBUG("%s\n", "bloqueo por ausencia de connManager.");
            vlc_cond_wait(&no_connManager, &lock_conMannager); /* se bloquea */
            DEBUG("%s\n", "desbloqueo de connManager");       
        }
        vlc_mutex_unlock(&lock_conMannager);
        read_real(connManagerGlobal); 
    }
    printf("%s\n", "Fin del hilo");
    return NULL;
}


Stream::Stream(demux_t * demux_, const StreamFormat &format_)
{
    DEBUG("%s\n", "CONSTRUCTOR");
    p_demux = demux_;
    type = UNKNOWN;
    format = format_;
    output = NULL;
    adaptationLogic = NULL;
    currentChunk = NULL;
    segmentTracker = NULL;
    eof = false;
    disabled = false;
    streamOutputFactory = NULL;

    #ifndef NO_BUFFER
        buffer = new buffer_threadSave();
        thread_end = false;
        primer_segmento = true;
        vlc_clone( &thread, EventThread, this, VLC_THREAD_PRIORITY_LOW );
        DEBUG("%s\n", "Empieza hilo");
    #endif
}

Stream::~Stream()
{
    DEBUG("%s\n", "Inicia destructor");
    delete currentChunk;
    delete adaptationLogic;
    delete output;
    delete segmentTracker;

    #ifndef NO_BUFFER
        DEBUG("eliminamos el buffer\n");
        buffer->empty();
        delete buffer;
        thread_end = true;
        connManagerGlobal = NULL;
        DEBUG("%s\n", "Hilo terminado");
    #endif
}

StreamType Stream::mimeToType(const std::string &mime)
{
    StreamType mimetype;
    if (!mime.compare(0, 6, "video/"))
        mimetype = VIDEO;
    else if (!mime.compare(0, 6, "audio/"))
        mimetype = AUDIO;
    else if (!mime.compare(0, 12, "application/"))
        mimetype = APPLICATION;
    else /* unknown of unsupported */
        mimetype = UNKNOWN;
    return mimetype;
}

void Stream::create(AbstractAdaptationLogic *logic, SegmentTracker *tracker,
                    const AbstractStreamOutputFactory *factory)
{
    adaptationLogic = logic;
    segmentTracker = tracker;
    streamOutputFactory = factory;
    updateFormat(format);
    #ifndef NO_BUFFER
        buffer->setAdaptationLogic(logic);
        adaptationLogic->setBuffer(buffer);
        buffer->setMaxBufferSize(adaptationLogic->getMaxBufferSize());
        adaptationLogic->inicializar();
    #endif
}

void Stream::updateFormat(StreamFormat &newformat)
{
    if( format == newformat && output )
        return;

    delete output;
    format = newformat;
    output = streamOutputFactory->create(p_demux, format);
    if(!output)
        throw VLC_EGENERIC;
    output->setLanguage(language);
    output->setDescription(description);
}

void Stream::setLanguage(const std::string &lang)
{
    language = lang;
}

void Stream::setDescription(const std::string &desc)
{
    description = desc;
}

bool Stream::isEOF() const
{
    return false;
}

mtime_t Stream::getPCR() const
{
    if(!output)
        return 0;
    return output->getPCR();
}

mtime_t Stream::getFirstDTS() const
{
    if(!output)
        return 0;
    return output->getFirstDTS();
}

int Stream::esCount() const
{
    if(!output)
        return 0;
    return output->esCount();
}

bool Stream::operator ==(const Stream &stream) const
{
    return stream.type == type;
}

SegmentChunk * Stream::getChunk()
{
    if (currentChunk == NULL && output)
    {
        if(esCount() && !isSelected())
        {
            disabled = true;
            return NULL;
        }
        currentChunk = segmentTracker->getNextChunk(output->switchAllowed());
        if (currentChunk == NULL){
            eof = true;
            DEBUG("%s\n","eof!");
            buffer->moveInToOut(buffer->bufferInSize());
        }
    }
    return currentChunk;
}

bool Stream::seekAble() const
{
    return (output && output->seekAble());
}

bool Stream::isSelected() const
{
    return output && output->isSelected();
}

bool Stream::reactivate(mtime_t basetime)
{
    if(setPosition(basetime, false))
    {
        disabled = false;
        return true;
    }
    else
    {
        eof = true; /* can't reactivate */
        return false;
    }
}

bool Stream::isDisabled() const
{
    return disabled;
}

Stream::status Stream::demux(HTTPConnectionManager *connManager, mtime_t nz_deadline, bool send)
{
    
    if(!output){
        printf("%s\n","EOF");
        return Stream::status_eof;
    }

    if(nz_deadline + VLC_TS_0 > output->getPCR()) /* not already demuxed */
    {
        /* need to read, demuxer still buffering, ... */
        int read_ret = read(connManager);
        if(read_ret <= 0)
        {
            if(output->isEmpty()){
                DEBUG("%s\n","EOF");
                return Stream::status_eof;
            }
        }
        else if(nz_deadline + VLC_TS_0 > output->getPCR()) /* need to read more */
        {
            return Stream::status_buffering;
        }
    }

    if(send){
        output->sendToDecoder(nz_deadline);
        DEBUG("%s\n","sendToDecoder");
    }
    DEBUG("%s\n","Terminando...");

    return Stream::status_demuxed;
}

size_t Stream::read(HTTPConnectionManager *connManager){
    #ifndef NO_BUFFER 
        size_t readsize = 0;
        if(connManager != connManagerGlobal){
            DEBUG("%s\n", "Recargamos connManagerGlobal");
            vlc_mutex_lock( &lock_conMannager );
            connManagerGlobal = connManager;
            vlc_cond_signal(&no_connManager);
            vlc_mutex_unlock( &lock_conMannager );
        }
        if(eof && buffer->bufferInSize() == 0 && buffer->size() == 0){
            readsize = 0;
        } else {
            buffer_threadSave::data_download* dataInfo = buffer->pop();

            block_t * block = dataInfo->buffer;
            DEBUG("%p\n",block);
            readsize = dataInfo->buffer->i_buffer;
            
            DEBUG("readsize: %i\n", readsize);
            DEBUG("elementos en el buffer (tras borrar): %i\n", buffer->size() );

            if(output){
                output->pushBlock(block, dataInfo->b_segment_head_chunk);
            } else{
                DEBUG("%s\n", "Liberando bloque...");
                block_Release(block);
                DEBUG("%s\n", "Bloque liberado!");
            }
        }
        return readsize;
    #else
        return read_real(connManager);
    #endif    
}

size_t Stream::read_real(HTTPConnectionManager *connManager)
{
    bool newSegment = false;

    SegmentChunk *chunk = getChunk();
    if(!chunk){
        return 0;
    }

    if(!chunk->getConnection())
    {
       if(!connManager->connectChunk(chunk)){
            return 0;
       }
    }

    size_t readsize = 0;
    bool b_segment_head_chunk = false;

    /* New chunk, do query */
    if(chunk->getBytesRead() == 0)
    {
        newSegment = true;

        #ifndef NO_BUFFER
            buffer->setTimeScale(segmentTracker->getTimeScale());
            DEBUG("buffer duration: %li\n", buffer->getBufferTotalTimeIn());
        #endif

        int ret = chunk->getConnection()->query(chunk->getPath());
        if( ret != VLC_SUCCESS)
        {
            chunk->getConnection()->releaseChunk();
            currentChunk = NULL;
            delete chunk;
            return 0;
        }
        b_segment_head_chunk = true;
        adaptationLogic->setCalculateDownloadRate();
    }
    /* Because we don't know Chunk size at start, we need to get size
       from content length */
    readsize = chunk->getBytesToRead();
    
    #ifdef LIMIT_CHUNK_SIZE
        DEBUG("Lenght: %i\n", chunk->getLength());
        if (readsize > 32768)
            readsize = 32768;
    #endif

    DEBUG("Readsize: %i\n", readsize);

    block_t *block = block_Alloc(readsize);
    if(!block)
        return 0;

    mtime_t time = mdate();
    ssize_t ret = chunk->getConnection()->read(block->p_buffer, readsize);
    time = mdate() - time;

    #ifndef NO_BUFFER
        int paquetesAExtraer = 0;
        int64_t segundosPorPresentar = 0;
        DEBUG("PATH: %s\n", chunk->getPath().c_str());  
        if(!primer_segmento && checkFreeze(time, chunk)){
            DEBUG("\033[1;31mCONGELACION\033[0m\n");
        }
    #endif

    if(ret < 0)
    {
        block_Release(block);
        chunk->getConnection()->releaseChunk();
        currentChunk = NULL;
        delete chunk;
        return 0;
    }
    else
    {
        block->i_buffer = (size_t)ret;

        adaptationLogic->updateDownloadRate(block->i_buffer, time);
        chunk->onDownload(&block);

        StreamFormat chunkStreamFormat = chunk->getStreamFormat();
        if(output && chunkStreamFormat != output->getStreamFormat())
        {
            msg_Info(p_demux, "Changing stream format");
            updateFormat(chunkStreamFormat);
        }

        if (chunk->getBytesToRead() == 0)
        {
            chunk->getConnection()->releaseChunk();
            currentChunk = NULL;
            delete chunk;
        }
    }

    readsize = block->i_buffer;

    #ifndef NO_BUFFER
        buffer_threadSave::data_download* dataInfo = new buffer_threadSave::data_download;
        dataInfo->buffer = block;
        dataInfo->b_segment_head_chunk = b_segment_head_chunk;
        if(newSegment){
            DEBUG("Nueva duracion: %li\n", chunk->getSegmentDuration());
            dataInfo->duration = chunk->getSegmentDuration();
        }
        buffer->push(dataInfo);

        /*Comprobamos la disponibilidad de segmentos en el buffer de presentacion*/
        movePackages(time, chunk);
        DEBUG("total time buffer (IN): %lli (%lli)\n", buffer->getBufferTotalTimeIn(), buffer->bufferInSize() );
        DEBUG("total time buffer (OUT): %lli (%lli)\n", buffer->getBufferTotalTimeOut(), buffer->size() );
    #else
        if(output)
            output->pushBlock(block, b_segment_head_chunk);
        else
            block_Release(block);
    #endif
    return readsize;
}

bool Stream::setPosition(mtime_t time, bool tryonly)
{
    if(!output)
        return false;

    bool ret = segmentTracker->setPosition(time, output->reinitsOnSeek(), tryonly);
    if(!tryonly && ret)
    {
        output->setPosition(time);
        if(output->reinitsOnSeek())
        {
            if(currentChunk)
            {
                currentChunk->getConnection()->releaseChunk();
                delete currentChunk;
            }
            currentChunk = NULL;
        }
    }
    return ret;
}

mtime_t Stream::getPosition() const
{
    return segmentTracker->getSegmentStart();
}

void Stream::prune()
{
    segmentTracker->pruneFromCurrent();
}

void Stream::movePackages(mtime_t time, SegmentChunk *chunk){
    if(chunk->getSegmentDuration() > 0){    
        int64_t segundosPorPresentar = time - buffer->getBufferTotalTimeOut();
        int paquetesAExtraer = segundosPorPresentar/chunk->getSegmentDuration();
        /*Comprobamos la disponibilidad de segmentos en el buffer de presentacion*/
        if(primer_segmento){
            DEBUG("primer segmento\n");
            buffer->moveInToOut(1);
            primer_segmento = false;
        }
        else if(buffer->getBufferTotalTimeOut() <= time){
            DEBUG("buffer->getBufferTotalTimeOut() <= time, paquetes a extraer: %lli\n", paquetesAExtraer);
            int64_t timeAux = time - buffer->getBufferTotalTimeOut();
            paquetesAExtraer = timeAux/chunk->getSegmentDuration();
            if(paquetesAExtraer > buffer->bufferInSize()){
                paquetesAExtraer = buffer->bufferInSize();
            }
            buffer->moveInToOut(paquetesAExtraer);
        }
    } else {
        DEBUG("else!\n");
        buffer->moveInToOut(1);
    }
}

int64_t Stream::checkFreeze(mtime_t time, SegmentChunk *chunk){
    bool congelacion = false;
    int duracionCongelacion = 0;
    int64_t segundosPorPresentar = time - buffer->getBufferTotalTimeOut();
    int paquetesAExtraer = segundosPorPresentar/chunk->getSegmentDuration();

    if((buffer->size() == 0) ){
        if(paquetesAExtraer  > buffer->bufferInSize() ){
            // Fijamos que solo se extraiga lo que hay
            paquetesAExtraer = buffer->bufferInSize(); /*bufferCliente.size();*/
            // Se produce congelación y la duración de la misma
            congelacion = true; 
            duracionCongelacion = segundosPorPresentar - buffer->getBufferTotalTimeOut();
            printf("\033[0;36mDuracion congelacion: %i\033[0m\n", duracionCongelacion);
        } else {
            congelacion = false; 
            duracionCongelacion = 0;
        }
    }
    return duracionCongelacion;
}
/*******************************************/

buffer_threadSave::buffer_threadSave(){
    vlc_mutex_init( &lock );
    vlc_cond_init( &no_lleno );
    vlc_cond_init( &no_vacio );
    bufferTotalTimeIn = 0;
    bufferTotalTimeOut = 0;
    timescale = 0;
    sizeBuff = MAX_BUFFER;
}

void buffer_threadSave::setAdaptationLogic(AbstractAdaptationLogic* logic){
    adaptationLogic = logic;
}

void buffer_threadSave::push(data_download* data){
    DEBUG("lock!\n");
    vlc_mutex_lock( &lock );
    while (buffer_interno_out.size() == sizeBuff){ /* si buffer lleno */
        DEBUG("%s%i\n", "bloqueo por buffer lleno: ",buffer_interno_in.size() );
        vlc_cond_wait(&no_lleno, &lock); /* se bloquea */
        DEBUG("%s\n","Desbloqueo del buffer lleno");
    }
    DEBUG("%s\n","push data...");
    buffer_interno_in.push_back(data);
    PRINT_BUFFER("IN", buffer_interno_in);
    PRINT_BUFFER("OUT", buffer_interno_out);
    
    bufferTotalTimeIn += data->duration;
    
    DEBUG("PUSH: %li, TOTAL: %li\n", data->duration, bufferTotalTimeIn);

    PRINT_BUFFER("IN", buffer_interno_in);
    PRINT_BUFFER("OUT", buffer_interno_out);

    vlc_mutex_unlock( &lock );
    vlc_cond_signal(&no_vacio);
    DEBUG("%s\n","unlock!");
}

int buffer_threadSave::size(){
    int ret;
    DEBUG("%s\n","lock!");
    vlc_mutex_lock( &lock );
    ret = buffer_interno_out.size();
    vlc_mutex_unlock( &lock );
    DEBUG("%s\n","unlock!");
    return ret;
}

int buffer_threadSave::bufferInSize(){
    int ret;
    DEBUG("%s\n","lock!");
    vlc_mutex_lock( &lock );
    ret = buffer_interno_in.size();
    vlc_mutex_unlock( &lock );
    DEBUG("%s\n","unlock!");
    return ret;
}

int buffer_threadSave::getSegmentDuration(){
    if(buffer_interno_out.size() <= 0){
        return 0;
    }
    return buffer_interno_out.front()->duration;
}

buffer_threadSave::data_download* buffer_threadSave::pop(){
    DEBUG("POP\n");
    DEBUG("%s\n","lock!");
    vlc_mutex_lock( &lock );
    while (buffer_interno_out.size() == 0){
        DEBUG("%s%i\n", "bloqueo por buffer vacio IN: ",buffer_interno_in.size() );
        DEBUG("%s%i\n", "bloqueo por buffer vacio OUT: ",buffer_interno_out.size() );
        vlc_cond_wait(&no_vacio, &lock); /* se bloquea */
        DEBUG("%s\n","Desbloqueo del buffer vacio");
    }

    DEBUG("%s\n","pop data...");
    buffer_threadSave::data_download* ret = buffer_interno_out.front();
    buffer_interno_out.pop_front();
    bufferTotalTimeOut -= ret->duration;
    DEBUG("bufferTotalTimeOut: %li\n", bufferTotalTimeOut);
    vlc_mutex_unlock( &lock );
    vlc_cond_signal(&no_lleno);
    DEBUG("%s\n","unlock!");
    return ret;
}

void buffer_threadSave::setMaxBufferSize(int maxSize){
    printf("Nuevo tamaño: %i\n", maxSize);
    sizeBuff = maxSize;
}

void buffer_threadSave::moveInToOut(int64_t numero_segmentos){
    DEBUG("moveInToOut : %i\n", numero_segmentos);
    data_download* data;
    DEBUG("moviendo!!\n");
    while(numero_segmentos-- >0 && buffer_interno_in.size() > 0){
        data = buffer_interno_in.front();      
        buffer_interno_out.push_back(data);
        DEBUG("%s\n","extraemos...");
        bufferTotalTimeOut += data->duration;
        bufferTotalTimeIn -= data->duration;
        DEBUG("bufferTotalTimeIn: %li\n");
        buffer_interno_in.pop_front();
        DEBUG("%s\n","Desechamos...");
    }
}

void buffer_threadSave::empty(){
    DEBUG("%s\n","lock!");
    vlc_mutex_lock( &lock );
    buffer_interno_in.empty();
    buffer_interno_out.empty();
    vlc_mutex_unlock( &lock );
    DEBUG("%s\n","unlock!");
}

int64_t buffer_threadSave::getBufferTotalTimeIn(){
    DEBUG("%s\n","lock!");
    vlc_mutex_lock( &lock );
    int64_t ret = bufferTotalTimeIn;
    vlc_mutex_unlock( &lock );
    DEBUG("%s\n","unlock!");
    return ret;
}

int64_t buffer_threadSave::getBufferTotalTimeOut(){
    DEBUG("%s\n","lock!");
    vlc_mutex_lock( &lock );
    int64_t ret = bufferTotalTimeOut;
    vlc_mutex_unlock( &lock );
    DEBUG("%s\n","unlock!");
    return ret;
}

int64_t buffer_threadSave::getTimeScale(){
    return timescale;
}

void buffer_threadSave::setTimeScale(int64_t timescale_l){
    vlc_mutex_lock( &lock );
    timescale = timescale_l;
    vlc_mutex_unlock( &lock );
}

int64_t buffer_threadSave::getFreezingTime(){
    return 0;
}

int buffer_threadSave::getMaxBufferSize(){
    return sizeBuff;
}

/*******************************************/

AbstractStreamOutput::AbstractStreamOutput(demux_t *demux, const StreamFormat &format_)
{
    realdemux = demux;
    pcr = VLC_TS_INVALID;
    format = format_;
}

void AbstractStreamOutput::setLanguage(const std::string &lang)
{
    language = lang;
}

void AbstractStreamOutput::setDescription(const std::string &desc)
{
    description = desc;
}

const StreamFormat & AbstractStreamOutput::getStreamFormat() const
{
    return format;
}

AbstractStreamOutput::~AbstractStreamOutput()
{
}

mtime_t AbstractStreamOutput::getPCR() const
{
    return pcr;
}

/*******************************************/

BaseStreamOutput::BaseStreamOutput(demux_t *demux, const StreamFormat &format, const std::string &name) :
    AbstractStreamOutput(demux, format)
{
    this->name = name;
    seekable = true;
    restarting = false;
    demuxstream = NULL;
    b_drop = false;
    timestamps_offset = VLC_TS_INVALID;

    fakeesout = new es_out_t;
    if (!fakeesout)
        throw VLC_ENOMEM;

    vlc_mutex_init(&lock);

    fakeesout->pf_add = esOutAdd_Callback;
    fakeesout->pf_control = esOutControl_Callback;
    fakeesout->pf_del = esOutDel_Callback;
    fakeesout->pf_destroy = esOutDestroy_Callback;
    fakeesout->pf_send = esOutSend_Callback;
    fakeesout->p_sys = (es_out_sys_t*) this;

    demuxstream = stream_DemuxNew(realdemux, name.c_str(), fakeesout);
    if(!demuxstream)
        throw VLC_EGENERIC;
}

BaseStreamOutput::~BaseStreamOutput()
{
    if (demuxstream)
        stream_Delete(demuxstream);

    /* shouldn't be any */
    std::list<Demuxed *>::const_iterator it;
    for(it=queues.begin(); it!=queues.end();++it)
        delete *it;

    delete fakeesout;
    vlc_mutex_destroy(&lock);
}

mtime_t BaseStreamOutput::getFirstDTS() const
{
    mtime_t ret = VLC_TS_INVALID;
    vlc_mutex_lock(const_cast<vlc_mutex_t *>(&lock));
    std::list<Demuxed *>::const_iterator it;
    for(it=queues.begin(); it!=queues.end();++it)
    {
        const Demuxed *pair = *it;
        const block_t *p_block = pair->p_queue;
        while( p_block && p_block->i_dts == VLC_TS_INVALID )
        {
            p_block = p_block->p_next;
        }

        if(p_block)
        {
            ret = p_block->i_dts;
            break;
        }
    }
    vlc_mutex_unlock(const_cast<vlc_mutex_t *>(&lock));
    return ret;
}

int BaseStreamOutput::esCount() const
{
    return queues.size();
}

void BaseStreamOutput::pushBlock(block_t *block, bool)
{
    stream_DemuxSend(demuxstream, block);
}

bool BaseStreamOutput::seekAble() const
{
    bool b_canswitch = switchAllowed();
    return (demuxstream && seekable && b_canswitch);
}

void BaseStreamOutput::setPosition(mtime_t nztime)
{
    vlc_mutex_lock(&lock);
    std::list<Demuxed *>::const_iterator it;
    for(it=queues.begin(); it!=queues.end();++it)
    {
        (*it)->drop();
    }

    if(reinitsOnSeek())
    {
        /* disable appending until restarted */
        b_drop = true;
        vlc_mutex_unlock(&lock);
        restart();
        vlc_mutex_lock(&lock);
        b_drop = false;
    }

    pcr = VLC_TS_INVALID;
    vlc_mutex_unlock(&lock);

    es_out_Control(realdemux->out, ES_OUT_SET_NEXT_DISPLAY_TIME,
                   VLC_TS_0 + nztime);
}

bool BaseStreamOutput::restart()
{
    stream_t *newdemuxstream = stream_DemuxNew(realdemux, name.c_str(), fakeesout);
    if(!newdemuxstream)
        return false;

    vlc_mutex_lock(&lock);
    restarting = true;
    stream_t *olddemuxstream = demuxstream;
    demuxstream = newdemuxstream;
    vlc_mutex_unlock(&lock);

    if(olddemuxstream)
        stream_Delete(olddemuxstream);

    return true;
}

bool BaseStreamOutput::reinitsOnSeek() const
{
    return true;
}

bool BaseStreamOutput::switchAllowed() const
{
    bool b_allowed;
    vlc_mutex_lock(const_cast<vlc_mutex_t *>(&lock));
    b_allowed = !restarting;
    vlc_mutex_unlock(const_cast<vlc_mutex_t *>(&lock));
    return b_allowed;
}

bool BaseStreamOutput::isSelected() const
{
    bool b_selected = false;
    vlc_mutex_lock(const_cast<vlc_mutex_t *>(&lock));
    std::list<Demuxed *>::const_iterator it;
    for(it=queues.begin(); it!=queues.end() && !b_selected; ++it)
    {
        const Demuxed *pair = *it;
        if(pair->es_id)
            es_out_Control(realdemux->out, ES_OUT_GET_ES_STATE, pair->es_id, &b_selected);
    }
    vlc_mutex_unlock(const_cast<vlc_mutex_t *>(&lock));
    return b_selected;
}

bool BaseStreamOutput::isEmpty() const
{
    bool b_empty = true;
    vlc_mutex_lock(const_cast<vlc_mutex_t *>(&lock));
    std::list<Demuxed *>::const_iterator it;
    for(it=queues.begin(); it!=queues.end() && b_empty; ++it)
    {
        b_empty = !(*it)->p_queue;
    }
    vlc_mutex_unlock(const_cast<vlc_mutex_t *>(&lock));
    return b_empty;
}

void BaseStreamOutput::sendToDecoder(mtime_t nzdeadline)
{
    vlc_mutex_lock(&lock);
    sendToDecoderUnlocked(nzdeadline);
    vlc_mutex_unlock(&lock);
}

void BaseStreamOutput::sendToDecoderUnlocked(mtime_t nzdeadline)
{
    std::list<Demuxed *>::const_iterator it;
    for(it=queues.begin(); it!=queues.end();++it)
    {
        Demuxed *pair = *it;
        while(pair->p_queue && pair->p_queue->i_dts <= VLC_TS_0 + nzdeadline)
        {
            block_t *p_block = pair->p_queue;
            pair->p_queue = pair->p_queue->p_next;
            p_block->p_next = NULL;

            if(pair->pp_queue_last == &p_block->p_next)
                pair->pp_queue_last = &pair->p_queue;

            realdemux->out->pf_send(realdemux->out, pair->es_id, p_block);
        }
    }
}

void BaseStreamOutput::setTimestampOffset(mtime_t offset)
{
    vlc_mutex_lock(&lock);
    timestamps_offset = VLC_TS_0 + offset;
    vlc_mutex_unlock(&lock);
}

BaseStreamOutput::Demuxed::Demuxed(es_out_id_t *id, const es_format_t *fmt)
{
    p_queue = NULL;
    pp_queue_last = &p_queue;
    recycle = false;
    es_id = id;
    es_format_Init(&fmtcpy, UNKNOWN_ES, 0);
    es_format_Copy(&fmtcpy, fmt);
}

BaseStreamOutput::Demuxed::~Demuxed()
{
    es_format_Clean(&fmtcpy);
    drop();
}

void BaseStreamOutput::Demuxed::drop()
{
    if(p_queue)
    {
        block_ChainRelease(p_queue);
        p_queue = NULL;
        pp_queue_last = &p_queue;
    }
}

/* Static callbacks */
es_out_id_t * BaseStreamOutput::esOutAdd_Callback(es_out_t *fakees, const es_format_t *p_fmt)
{
    BaseStreamOutput *me = (BaseStreamOutput *) fakees->p_sys;
    return me->esOutAdd(p_fmt);
}

int BaseStreamOutput::esOutSend_Callback(es_out_t *fakees, es_out_id_t *p_es, block_t *p_block)
{
    BaseStreamOutput *me = (BaseStreamOutput *) fakees->p_sys;
    return me->esOutSend(p_es, p_block);
}

void BaseStreamOutput::esOutDel_Callback(es_out_t *fakees, es_out_id_t *p_es)
{
    BaseStreamOutput *me = (BaseStreamOutput *) fakees->p_sys;
    me->esOutDel(p_es);
}

int BaseStreamOutput::esOutControl_Callback(es_out_t *fakees, int i_query, va_list ap)
{
    BaseStreamOutput *me = (BaseStreamOutput *) fakees->p_sys;
    return me->esOutControl(i_query, ap);
}

void BaseStreamOutput::esOutDestroy_Callback(es_out_t *fakees)
{
    BaseStreamOutput *me = (BaseStreamOutput *) fakees->p_sys;
    me->esOutDestroy();
}
/* !Static callbacks */

es_out_id_t * BaseStreamOutput::esOutAdd(const es_format_t *p_fmt)
{
    es_out_id_t *p_es = NULL;

    vlc_mutex_lock(&lock);

    std::list<Demuxed *>::iterator it;
    bool b_hasestorecyle = false;
    for(it=queues.begin(); it!=queues.end();++it)
    {
        Demuxed *pair = *it;
        b_hasestorecyle |= pair->recycle;

        if( p_es )
            continue;

        if( restarting )
        {
            /* If we're recycling from same format */
            if( es_format_IsSimilar(p_fmt, &pair->fmtcpy) &&
                    p_fmt->i_extra == pair->fmtcpy.i_extra &&
                    !memcmp(p_fmt->p_extra, pair->fmtcpy.p_extra, p_fmt->i_extra) )
            {
                msg_Dbg(realdemux, "reusing output for codec %4.4s", (char*)&p_fmt->i_codec);
                pair->recycle = false;
                p_es = pair->es_id;
            }
        }
    }

    if(!b_hasestorecyle)
    {
        restarting = false;
    }

    if(!p_es)
    {
        es_format_t fmtcpy;
        es_format_Init(&fmtcpy, p_fmt->i_cat, p_fmt->i_codec);
        es_format_Copy(&fmtcpy, p_fmt);
        fmtcpy.i_group = 0;
        if(!fmtcpy.psz_language && !language.empty())
            fmtcpy.psz_language = strdup(language.c_str());
        if(!fmtcpy.psz_description && !description.empty())
            fmtcpy.psz_description = strdup(description.c_str());
        p_es = realdemux->out->pf_add(realdemux->out, &fmtcpy);
        if(p_es)
        {
            Demuxed *pair = new (std::nothrow) Demuxed(p_es, &fmtcpy);
            if(pair)
                queues.push_back(pair);
        }
        es_format_Clean(&fmtcpy);
    }
    vlc_mutex_unlock(&lock);

    return p_es;
}

int BaseStreamOutput::esOutSend(es_out_id_t *p_es, block_t *p_block)
{
    vlc_mutex_lock(&lock);
    if(b_drop)
    {
        block_ChainRelease( p_block );
    }
    else
    {
        if( timestamps_offset > VLC_TS_INVALID )
        {
            if(p_block->i_dts > VLC_TS_INVALID)
                p_block->i_dts += (timestamps_offset - VLC_TS_0);

            if(p_block->i_pts > VLC_TS_INVALID)
                p_block->i_pts += (timestamps_offset - VLC_TS_0);
        }

        std::list<Demuxed *>::const_iterator it;
        for(it=queues.begin(); it!=queues.end();++it)
        {
            Demuxed *pair = *it;
            if(pair->es_id == p_es)
            {
                block_ChainLastAppend(&pair->pp_queue_last, p_block);
                break;
            }
        }
    }
    vlc_mutex_unlock(&lock);
    return VLC_SUCCESS;
}

void BaseStreamOutput::esOutDel(es_out_id_t *p_es)
{
    vlc_mutex_lock(&lock);
    std::list<Demuxed *>::iterator it;
    for(it=queues.begin(); it!=queues.end();++it)
    {
        if((*it)->es_id == p_es)
        {
            sendToDecoderUnlocked(INT64_MAX - VLC_TS_0);
            break;
        }
    }

    if(it != queues.end())
    {
        if(restarting)
        {
            (*it)->recycle = true;
        }
        else
        {
            delete *it;
            queues.erase(it);
        }
    }

    if(!restarting)
        realdemux->out->pf_del(realdemux->out, p_es);

    vlc_mutex_unlock(&lock);
}

int BaseStreamOutput::esOutControl(int i_query, va_list args)
{
    if (i_query == ES_OUT_SET_PCR )
    {
        vlc_mutex_lock(&lock);
        pcr = (int64_t)va_arg( args, int64_t );
        if(pcr > VLC_TS_INVALID && timestamps_offset > VLC_TS_INVALID)
            pcr += (timestamps_offset - VLC_TS_0);
        vlc_mutex_unlock(&lock);
        return VLC_SUCCESS;
    }
    else if( i_query == ES_OUT_SET_GROUP_PCR )
    {
        vlc_mutex_lock(&lock);
        static_cast<void>(va_arg( args, int ));
        pcr = (int64_t)va_arg( args, int64_t );
        if(pcr > VLC_TS_INVALID && timestamps_offset > VLC_TS_INVALID)
            pcr += (timestamps_offset - VLC_TS_0);
        vlc_mutex_unlock(&lock);
        return VLC_SUCCESS;
    }
    else if( i_query == ES_OUT_GET_ES_STATE )
    {
        va_arg( args, es_out_id_t * );
        bool *pb = va_arg( args, bool * );
        *pb = true;
        return VLC_SUCCESS;
    }

    vlc_mutex_lock(&lock);
    bool b_restarting = restarting;
    vlc_mutex_unlock(&lock);

    if( b_restarting )
    {
        return VLC_EGENERIC;
    }

    return realdemux->out->pf_control(realdemux->out, i_query, args);
}

void BaseStreamOutput::esOutDestroy()
{
    realdemux->out->pf_destroy(realdemux->out);
}

