
/*
 * SFML library: SoundRecorder.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

/* Audio/sfSoundRecorder */
static HB_GARBAGE_FUNC( hb_sfSoundRecorder_destructor )
{
   sfSoundRecorder ** ppSfSoundRecorder = ( sfSoundRecorder ** ) Cargo;

   if( *ppSfSoundRecorder )
   {
      sfSoundRecorder_destroy( *ppSfSoundRecorder );
      *ppSfSoundRecorder = NULL;
   }
}

static const HB_GC_FUNCS s_gcSfSoundRecorderFuncs =
{
   hb_sfSoundRecorder_destructor,
   hb_gcDummyMark
};

sfSoundRecorder * hb_sfSoundRecorderItemGet( PHB_ITEM pItem )
{
   sfSoundRecorder ** ppSfSoundRecorder = ( sfSoundRecorder ** ) hb_itemGetPtrGC( pItem, &s_gcSfSoundRecorderFuncs );

   return ppSfSoundRecorder ? *ppSfSoundRecorder : NULL;
}

PHB_ITEM hb_sfSoundRecorderItemPut( PHB_ITEM pItem, sfSoundRecorder * pSfSoundBuffer )
{
   sfSoundRecorder ** ppSfSoundRecorder = ( sfSoundRecorder ** ) hb_gcAllocate( sizeof( sfSoundRecorder * ), &s_gcSfSoundRecorderFuncs );

   *ppSfSoundRecorder = pSfSoundBuffer;
   return hb_itemPutPtrGC( pItem, ppSfSoundRecorder );
}

sfSoundRecorder * hb_sfSoundRecorder_param( int iParam )
{
   sfSoundRecorder ** ppSfSoundRecorder = ( sfSoundRecorder ** ) hb_parptrGC( &s_gcSfSoundRecorderFuncs, iParam );

   if( ppSfSoundRecorder && *ppSfSoundRecorder )
   {
      return *ppSfSoundRecorder;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      return NULL;
   }
}

void hb_sfSoundRecorder_ret( sfSoundRecorder * pSfSoundBuffer )
{
   hb_sfSoundRecorderItemPut( hb_stackReturnItem(), pSfSoundBuffer );
}

// typedef sfBool (*sfSoundRecorderStartCallback)(void*);                           ///< Type of the callback used when starting a capture
// typedef sfBool (*sfSoundRecorderProcessCallback)(const sfInt16*, size_t, void*); ///< Type of the callback used to process audio data
// typedef void   (*sfSoundRecorderStopCallback)(void*);                            ///< Type of the callback used when stopping a capture

// sfSoundRecorder* sfSoundRecorder_create(sfSoundRecorderStartCallback onStart, sfSoundRecorderProcessCallback onProcess, sfSoundRecorderStopCallback onStop, void* userData);

// void sfSoundRecorder_destroy(sfSoundRecorder* soundRecorder);
HB_FUNC( SFSOUNDRECORDER_DESTROY )
{
   sfSoundRecorder ** ppSfSoundRecorder = ( sfSoundRecorder ** ) hb_parptrGC( &s_gcSfSoundRecorderFuncs, 1 );

   if( ppSfSoundRecorder && *ppSfSoundRecorder )
   {
      sfSoundRecorder_destroy( *ppSfSoundRecorder );
      *ppSfSoundRecorder = NULL;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfBool sfSoundRecorder_start(sfSoundRecorder* soundRecorder, unsigned int sampleRate);

// void sfSoundRecorder_stop(sfSoundRecorder* soundRecorder);

// unsigned int sfSoundRecorder_getSampleRate(const sfSoundRecorder* soundRecorder);

// sfBool sfSoundRecorder_isAvailable(void);

// void sfSoundRecorder_setProcessingInterval(sfSoundRecorder* soundRecorder, sfTime interval);

// const char** sfSoundRecorder_getAvailableDevices(size_t* count);

// const char* sfSoundRecorder_getDefaultDevice();

// sfBool sfSoundRecorder_setDevice(sfSoundRecorder* soundRecorder, const char* name);

// const char* sfSoundRecorder_getDevice(sfSoundRecorder* soundRecorder);

// void sfSoundRecorder_setChannelCount(sfSoundRecorder* soundRecorder, unsigned int channelCount);

// unsigned int sfSoundRecorder_getChannelCount(const sfSoundRecorder* soundRecorder);
