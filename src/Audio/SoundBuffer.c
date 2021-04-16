/*
 * SFML library: SoundBuffer.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

/* Audio/sfSoundBuffer */
static HB_GARBAGE_FUNC( hb_sfSoundBuffer_destructor )
{
   sfSoundBuffer ** ppSfSoundBuffer = ( sfSoundBuffer ** ) Cargo;

   if( *ppSfSoundBuffer )
   {
      sfSoundBuffer_destroy( *ppSfSoundBuffer );
      *ppSfSoundBuffer = NULL;
   }
}

static const HB_GC_FUNCS s_gcSfSoundBufferFuncs =
{
   hb_sfSoundBuffer_destructor,
   hb_gcDummyMark
};

PHB_ITEM hb_sfSoundBufferItemPut( PHB_ITEM pItem, sfSoundBuffer * pSfSoundBuffer )
{
   sfSoundBuffer ** ppSfSoundBuffer = ( sfSoundBuffer ** ) hb_gcAllocate( sizeof( sfSoundBuffer * ), &s_gcSfSoundBufferFuncs );

   *ppSfSoundBuffer = pSfSoundBuffer;
   return hb_itemPutPtrGC( pItem, ppSfSoundBuffer );
}

sfSoundBuffer * hb_sfSoundBuffer_param( int iParam )
{
   sfSoundBuffer ** ppSfSoundBuffer = ( sfSoundBuffer ** ) hb_parptrGC( &s_gcSfSoundBufferFuncs, iParam );

   if( ppSfSoundBuffer && *ppSfSoundBuffer )
   {
      return *ppSfSoundBuffer;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      return NULL;
   }
}

void hb_sfSoundBuffer_ret( sfSoundBuffer * pSfSoundBuffer )
{
   hb_sfSoundBufferItemPut( hb_stackReturnItem(), pSfSoundBuffer );
}

// sfSoundBuffer* sfSoundBuffer_createFromFile(const char* filename);

// sfSoundBuffer* sfSoundBuffer_createFromMemory(const void* data, size_t sizeInBytes);

// sfSoundBuffer* sfSoundBuffer_createFromStream(sfInputStream* stream);

// sfSoundBuffer* sfSoundBuffer_createFromSamples(const sfInt16* samples, sfUint64 sampleCount, unsigned int channelCount, unsigned int sampleRate);

// sfSoundBuffer* sfSoundBuffer_copy(const sfSoundBuffer* soundBuffer);

// void sfSoundBuffer_destroy(sfSoundBuffer* soundBuffer);
HB_FUNC( SFSOUNDBUFFER_DESTROY )
{
   sfSoundBuffer ** ppSfSoundBuffer = ( sfSoundBuffer ** ) hb_parptrGC( &s_gcSfSoundBufferFuncs, 1 );

   if( ppSfSoundBuffer && *ppSfSoundBuffer )
   {
      sfSoundBuffer_destroy( *ppSfSoundBuffer );
      *ppSfSoundBuffer = NULL;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfBool sfSoundBuffer_saveToFile(const sfSoundBuffer* soundBuffer, const char* filename);

// const sfInt16* sfSoundBuffer_getSamples(const sfSoundBuffer* soundBuffer);

// sfUint64 sfSoundBuffer_getSampleCount(const sfSoundBuffer* soundBuffer);

// unsigned int sfSoundBuffer_getSampleRate(const sfSoundBuffer* soundBuffer);

// unsigned int sfSoundBuffer_getChannelCount(const sfSoundBuffer* soundBuffer);

// sfTime sfSoundBuffer_getDuration(const sfSoundBuffer* soundBuffer);
