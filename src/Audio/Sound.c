/*
 * SFML library: Sound.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

/* Audio/sfSound */
static HB_GARBAGE_FUNC( hb_sfSound_destructor )
{
   sfSound ** ppSfSound = ( sfSound ** ) Cargo;

   if( *ppSfSound )
   {
      sfSound_destroy( *ppSfSound );
      *ppSfSound = NULL;
   }
}

static const HB_GC_FUNCS s_gcSfSoundFuncs =
{
   hb_sfSound_destructor,
   hb_gcDummyMark
};

PHB_ITEM hb_sfSoundItemPut( PHB_ITEM pItem, sfSound * pSfSound )
{
   sfSound ** ppSfSound = ( sfSound ** ) hb_gcAllocate( sizeof( sfSound * ), &s_gcSfSoundFuncs );

   *ppSfSound = pSfSound;
   return hb_itemPutPtrGC( pItem, ppSfSound );
}

sfSound * hb_sfSound_param( int iParam )
{
   sfSound ** ppSfSound = ( sfSound ** ) hb_parptrGC( &s_gcSfSoundFuncs, iParam );

   if( ppSfSound && *ppSfSound )
   {
      return *ppSfSound;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      return NULL;
   }
}

void hb_sfSound_ret( sfSound * pSfSound )
{
   hb_sfSoundItemPut( hb_stackReturnItem(), pSfSound );
}

// sfSound* sfSound_create(void);
HB_FUNC( SFSOUND_CREATE )
{
   hb_sfSound_ret( sfSound_create() );
}

// sfSound* sfSound_copy(const sfSound* sound);
HB_FUNC( SFSOUND_COPY )
{
   const sfSound* sound = hb_sfSound_param( 1 );

   if( sound )
   {
      hb_sfSound_ret( sfSound_copy( sound ) );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfSound_destroy(sfSound* sound);
HB_FUNC( SFSOUND_DESTROY )
{
   sfSound ** ppSfSound = ( sfSound ** ) hb_parptrGC( &s_gcSfSoundFuncs, 1 );

   if( ppSfSound && *ppSfSound )
   {
      sfSound_destroy( *ppSfSound );
      *ppSfSound = NULL;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfSound_play(sfSound* sound);
HB_FUNC( SFSOUND_PLAY )
{
   sfSound* sound = hb_sfSound_param( 1 );

   if( sound )
   {
      sfSound_play( sound );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfSound_pause(sfSound* sound);
HB_FUNC( SFSOUND_PAUSE )
{
   sfSound* sound = hb_sfSound_param( 1 );

   if( sound )
   {
      sfSound_pause( sound );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfSound_stop(sfSound* sound);
HB_FUNC( SFSOUND_STOP )
{
   sfSound* sound = hb_sfSound_param( 1 );

   if( sound )
   {
      sfSound_stop( sound );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfSound_setBuffer(sfSound* sound, const sfSoundBuffer* buffer);
HB_FUNC( SFSOUND_SETBUFFER )
{
   sfSound* sound = hb_sfSound_param( 1 );
   const sfSoundBuffer* buffer = hb_sfSoundBuffer_param( 2 );

   if( sound && buffer )
   {
      sfSound_setBuffer( sound, buffer );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// const sfSoundBuffer* sfSound_getBuffer(const sfSound* sound);

// void sfSound_setLoop(sfSound* sound, sfBool loop);
HB_FUNC( SFSOUND_SETLOOP )
{
   sfSound* sound = hb_sfSound_param( 1 );

   if( sound && hb_param( 3, HB_IT_LOGICAL ) != NULL )
   {
      sfSound_setLoop( sound, hb_parl( 2 ) );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfBool sfSound_getLoop(const sfSound* sound);
HB_FUNC( SFSOUND_GETLOOP )
{
   const sfSound* sound = hb_sfSound_param( 1 );

   if( sound )
   {
      sfSound_getLoop( sound );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfSoundStatus sfSound_getStatus(const sfSound* sound);

// void sfSound_setPitch(sfSound* sound, float pitch);

// void sfSound_setVolume(sfSound* sound, float volume);

// void sfSound_setPosition(sfSound* sound, sfVector3f position);

// void sfSound_setRelativeToListener(sfSound* sound, sfBool relative);

// void sfSound_setMinDistance(sfSound* sound, float distance);

// void sfSound_setAttenuation(sfSound* sound, float attenuation);

// void sfSound_setPlayingOffset(sfSound* sound, sfTime timeOffset);

// float sfSound_getPitch(const sfSound* sound);

// float sfSound_getVolume(const sfSound* sound);

// sfVector3f sfSound_getPosition(const sfSound* sound);

// sfBool sfSound_isRelativeToListener(const sfSound* sound);

// float sfSound_getMinDistance(const sfSound* sound);

// float sfSound_getAttenuation(const sfSound* sound);

// sfTime sfSound_getPlayingOffset(const sfSound* sound);
