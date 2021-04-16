
/*
 * SFML library: SoundStream.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

/* Audio/sfSoundStream */
static HB_GARBAGE_FUNC( hb_sfSoundStream_destructor )
{
   sfSoundStream ** ppSfSoundStream = ( sfSoundStream ** ) Cargo;

   if( *ppSfSoundStream )
   {
      sfSoundStream_destroy( *ppSfSoundStream );
      *ppSfSoundStream = NULL;
   }
}

static const HB_GC_FUNCS s_gcSfSoundStreamFuncs =
{
   hb_sfSoundStream_destructor,
   hb_gcDummyMark
};

PHB_ITEM hb_sfSoundStreamItemPut( PHB_ITEM pItem, sfSoundStream * pSfSoundStream )
{
   sfSoundStream ** ppSfSoundStream = ( sfSoundStream ** ) hb_gcAllocate( sizeof( sfSoundStream * ), &s_gcSfSoundStreamFuncs );

   *ppSfSoundStream = pSfSoundStream;
   return hb_itemPutPtrGC( pItem, ppSfSoundStream );
}

sfSoundStream * hb_sfSoundStream_param( int iParam )
{
   sfSoundStream ** ppSfSoundStream = ( sfSoundStream ** ) hb_parptrGC( &s_gcSfSoundStreamFuncs, iParam );

   if( ppSfSoundStream && *ppSfSoundStream )
   {
      return *ppSfSoundStream;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      return NULL;
   }
}

void hb_sfSoundStream_ret( sfSoundStream * pSfSoundStream )
{
   hb_sfSoundStreamItemPut( hb_stackReturnItem(), pSfSoundStream );
}

// typedef sfBool (*sfSoundStreamGetDataCallback)(sfSoundStreamChunk*, void*); ///< Type of the callback used to get a sound stream data
// typedef void   (*sfSoundStreamSeekCallback)(sfTime, void*);                 ///< Type of the callback used to seek in a sound stream

// sfSoundStream* sfSoundStream_create(sfSoundStreamGetDataCallback onGetData, sfSoundStreamSeekCallback onSeek, unsigned int channelCount, unsigned int sampleRate, void* userData);

// void sfSoundStream_destroy(sfSoundStream* soundStream);
HB_FUNC( SFSOUNDSTREAM_DESTROY )
{
   sfSoundStream ** ppSfSoundStream = ( sfSoundStream ** ) hb_parptrGC( &s_gcSfSoundStreamFuncs, 1 );

   if( ppSfSoundStream && *ppSfSoundStream )
   {
      sfSoundStream_destroy( *ppSfSoundStream );
      *ppSfSoundStream = NULL;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfSoundStream_play(sfSoundStream* soundStream);

// void sfSoundStream_pause(sfSoundStream* soundStream);

// void sfSoundStream_stop(sfSoundStream* soundStream);

// sfSoundStatus sfSoundStream_getStatus(const sfSoundStream* soundStream);

// unsigned int sfSoundStream_getChannelCount(const sfSoundStream* soundStream);

// unsigned int sfSoundStream_getSampleRate(const sfSoundStream* soundStream);

// void sfSoundStream_setPitch(sfSoundStream* soundStream, float pitch);

// void sfSoundStream_setVolume(sfSoundStream* soundStream, float volume);

// void sfSoundStream_setPosition(sfSoundStream* soundStream, sfVector3f position);

// void sfSoundStream_setRelativeToListener(sfSoundStream* soundStream, sfBool relative);

// void sfSoundStream_setMinDistance(sfSoundStream* soundStream, float distance);

// void sfSoundStream_setAttenuation(sfSoundStream* soundStream, float attenuation);

// void sfSoundStream_setPlayingOffset(sfSoundStream* soundStream, sfTime timeOffset);

// void sfSoundStream_setLoop(sfSoundStream* soundStream, sfBool loop);

// float sfSoundStream_getPitch(const sfSoundStream* soundStream);

// float sfSoundStream_getVolume(const sfSoundStream* soundStream);

// sfVector3f sfSoundStream_getPosition(const sfSoundStream* soundStream);

// sfBool sfSoundStream_isRelativeToListener(const sfSoundStream* soundStream);

// float sfSoundStream_getMinDistance(const sfSoundStream* soundStream);

// float sfSoundStream_getAttenuation(const sfSoundStream* soundStream);

// sfBool sfSoundStream_getLoop(const sfSoundStream* soundStream);

// sfTime sfSoundStream_getPlayingOffset(const sfSoundStream* soundStream);
