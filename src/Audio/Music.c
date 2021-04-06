/*
 * SFML library: Music.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

/* Audio/sfMusic */
static HB_GARBAGE_FUNC( hb_sfMusic_destructor )
{
   sfMusic ** ppSfMusic = ( sfMusic ** ) Cargo;

   if( *ppSfMusic )
   {
      sfMusic_destroy( *ppSfMusic );
      *ppSfMusic = NULL;
   }
}

static const HB_GC_FUNCS s_gcSfMusicFuncs =
{
   hb_sfMusic_destructor,
   hb_gcDummyMark
};

sfMusic * hb_sfMusicItemGet( PHB_ITEM pItem )
{
   sfMusic ** ppSfMusic = ( sfMusic ** ) hb_itemGetPtrGC( pItem, &s_gcSfMusicFuncs );

   return ppSfMusic ? *ppSfMusic : NULL;
}

PHB_ITEM hb_sfMusicItemPut( PHB_ITEM pItem, sfMusic * pSfMusic )
{
   sfMusic ** ppSfMusic = ( sfMusic ** ) hb_gcAllocate( sizeof( sfMusic * ), &s_gcSfMusicFuncs );

   *ppSfMusic = pSfMusic;
   return hb_itemPutPtrGC( pItem, ppSfMusic );
}

sfMusic * hb_sfMusic_param( int iParam )
{
   sfMusic ** ppSfMusic = ( sfMusic ** ) hb_parptrGC( &s_gcSfMusicFuncs, iParam );

   if( ppSfMusic && *ppSfMusic )
   {
      return *ppSfMusic;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      return NULL;
   }
}

void hb_sfMusic_ret( sfMusic * pSfMusic )
{
   hb_sfMusicItemPut( hb_stackReturnItem(), pSfMusic );
}

// sfMusic* sfMusic_createFromFile(const char* filename);
HB_FUNC( SFMUSIC_CREATEFROMFILE )
{
   if( hb_param( 1, HB_IT_STRING )  != NULL )
   {
      hb_sfMusic_ret( sfMusic_createFromFile( hb_parc( 1 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfMusic* sfMusic_createFromMemory(const void* data, size_t sizeInBytes);

// sfMusic* sfMusic_createFromStream(sfInputStream* stream);
HB_FUNC( SFMUSIC_CREATEFROMSTREAM )
{
   sfInputStream* stream = hb_parptr( 1 );

   if( hb_param( 1, HB_IT_INTEGER ) != NULL )
   {
      hb_sfMusic_ret( sfMusic_createFromStream( stream ) );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfMusic_destroy(sfMusic* music);
HB_FUNC( SFMUSIC_DESTROY )
{
   sfMusic ** ppSfMusic = ( sfMusic ** ) hb_parptrGC( &s_gcSfMusicFuncs, 1 );

   if( ppSfMusic && *ppSfMusic )
   {
      sfMusic_destroy( *ppSfMusic );
      *ppSfMusic = NULL;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfMusic_setLoop(sfMusic* music, sfBool loop);
HB_FUNC( SFMUSIC_SETLOOP )
{
   sfMusic* music = hb_sfMusic_param( 1 );

   if( music && hb_param( 2, HB_IT_LOGICAL ) != NULL )
   {
      sfMusic_setLoop( music, hb_parl( 2 ) );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfBool sfMusic_getLoop(const sfMusic* music);
HB_FUNC( SFMUSIC_GETLOOP )
{
   const sfMusic* music = hb_sfMusic_param( 1 );

   if( music )
   {
      hb_retl( sfMusic_getLoop( music ) );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfTime sfMusic_getDuration(const sfMusic* music);
HB_FUNC( SFMUSIC_GETDURATION )
{
   const sfMusic* music = hb_sfMusic_param( 1 );

   if( music )
   {
      sfTime times = sfMusic_getDuration( music );

      PHB_ITEM info = hb_itemArrayNew( 1 );

      hb_arraySetNLL( info, 1, times.microseconds );

      hb_itemReturnRelease( info );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfTimeSpan sfMusic_getLoopPoints(const sfMusic* music);
HB_FUNC( SFMUSIC_GETLOOPPOINTS )
{
   const sfMusic* music = hb_sfMusic_param( 1 );

   if( music )
   {
      sfTimeSpan timespan = sfMusic_getLoopPoints( music );

      PHB_ITEM pGetLoopPointsArray = hb_itemArrayNew( 2 );

      PHB_ITEM pSubarray1 = hb_arrayGetItemPtr( pGetLoopPointsArray, 1 );
      hb_arrayNew( pSubarray1, 1 );
      hb_arraySetNLL( pSubarray1, 1, timespan.offset.microseconds );

      PHB_ITEM pSubarray2 = hb_arrayGetItemPtr( pGetLoopPointsArray, 1 );
      hb_arrayNew( pSubarray2, 1 );
      hb_arraySetNLL( pSubarray2, 1, timespan.length.microseconds );

      hb_itemReturnRelease( pGetLoopPointsArray );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfMusic_setLoopPoints(sfMusic* music, sfTimeSpan timePoints);

// void sfMusic_play(sfMusic* music);
HB_FUNC( SFMUSIC_PLAY )
{
   sfMusic* music = hb_sfMusic_param( 1 );

   if( music )
   {
      sfMusic_play( music );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfMusic_pause(sfMusic* music);
HB_FUNC( SFMUSIC_PAUSE )
{
   sfMusic* music = hb_sfMusic_param( 1 );

   if( music )
   {
      sfMusic_pause( music );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfMusic_stop(sfMusic* music);
HB_FUNC( SFMUSIC_STOP )
{
   sfMusic* music = hb_sfMusic_param( 1 );

   if( music )
   {
      sfMusic_stop( music );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// unsigned int sfMusic_getChannelCount(const sfMusic* music);

// unsigned int sfMusic_getSampleRate(const sfMusic* music);

// sfSoundStatus sfMusic_getStatus(const sfMusic* music);

// sfTime sfMusic_getPlayingOffset(const sfMusic* music);

// void sfMusic_setPitch(sfMusic* music, float pitch);

// void sfMusic_setVolume(sfMusic* music, float volume);

// void sfMusic_setPosition(sfMusic* music, sfVector3f position);

// void sfMusic_setRelativeToListener(sfMusic* music, sfBool relative);

// void sfMusic_setMinDistance(sfMusic* music, float distance);

// void sfMusic_setAttenuation(sfMusic* music, float attenuation);

// void sfMusic_setPlayingOffset(sfMusic* music, sfTime timeOffset);

// float sfMusic_getPitch(const sfMusic* music);

// float sfMusic_getVolume(const sfMusic* music);

// sfVector3f sfMusic_getPosition(const sfMusic* music);

// sfBool sfMusic_isRelativeToListener(const sfMusic* music);

// float sfMusic_getMinDistance(const sfMusic* music);

// float sfMusic_getAttenuation(const sfMusic* music);
