/*
 * SFML library: SoundBufferRecorder.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

/* Audio/sfSoundBufferRecorder */
static HB_GARBAGE_FUNC( hb_sfSoundBufferRecorder_destructor )
{
   sfSoundBufferRecorder ** ppSfSoundBufferRecorder = ( sfSoundBufferRecorder ** ) Cargo;

   if( *ppSfSoundBufferRecorder )
   {
      sfSoundBufferRecorder_destroy( *ppSfSoundBufferRecorder );
      *ppSfSoundBufferRecorder = NULL;
   }
}

static const HB_GC_FUNCS s_gcSfSoundBufferRecorderFuncs =
{
   hb_sfSoundBufferRecorder_destructor,
   hb_gcDummyMark
};

PHB_ITEM hb_sfSoundBufferRecorderItemPut( PHB_ITEM pItem, sfSoundBufferRecorder * pSfSoundBuffer )
{
   sfSoundBufferRecorder ** ppSfSoundBufferRecorder = ( sfSoundBufferRecorder ** ) hb_gcAllocate( sizeof( sfSoundBufferRecorder * ), &s_gcSfSoundBufferRecorderFuncs );

   *ppSfSoundBufferRecorder = pSfSoundBuffer;
   return hb_itemPutPtrGC( pItem, ppSfSoundBufferRecorder );
}

sfSoundBufferRecorder * hb_sfSoundBufferRecorder_param( int iParam )
{
   sfSoundBufferRecorder ** ppSfSoundBufferRecorder = ( sfSoundBufferRecorder ** ) hb_parptrGC( &s_gcSfSoundBufferRecorderFuncs, iParam );

   if( ppSfSoundBufferRecorder && *ppSfSoundBufferRecorder )
   {
      return *ppSfSoundBufferRecorder;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      return NULL;
   }
}

void hb_sfSoundBufferRecorder_ret( sfSoundBufferRecorder * pSfSoundBuffer )
{
   hb_sfSoundBufferRecorderItemPut( hb_stackReturnItem(), pSfSoundBuffer );
}

// sfSoundBufferRecorder* sfSoundBufferRecorder_create(void);

// void sfSoundBufferRecorder_destroy(sfSoundBufferRecorder* soundBufferRecorder);
HB_FUNC( SFSOUNDBUFFERRECORDER_DESTROY )
{
   sfSoundBufferRecorder ** ppSfSoundBufferRecorder = ( sfSoundBufferRecorder ** ) hb_parptrGC( &s_gcSfSoundBufferRecorderFuncs, 1 );

   if( ppSfSoundBufferRecorder && *ppSfSoundBufferRecorder )
   {
      sfSoundBufferRecorder_destroy( *ppSfSoundBufferRecorder );
      *ppSfSoundBufferRecorder = NULL;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfBool sfSoundBufferRecorder_start(sfSoundBufferRecorder* soundBufferRecorder, unsigned int sampleRate);

// void sfSoundBufferRecorder_stop(sfSoundBufferRecorder* soundBufferRecorder);

// unsigned int sfSoundBufferRecorder_getSampleRate(const sfSoundBufferRecorder* soundBufferRecorder);

// const sfSoundBuffer* sfSoundBufferRecorder_getBuffer(const sfSoundBufferRecorder* soundBufferRecorder);

// sfBool sfSoundBufferRecorder_setDevice(sfSoundBufferRecorder* soundBufferRecorder, const char* name);

// const char* sfSoundBufferRecorder_getDevice(sfSoundBufferRecorder* soundBufferRecorder);
