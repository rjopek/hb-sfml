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

      PHB_ITEM pTimeArray = hb_itemArrayNew( 1 );

      hb_arraySetNLL( pTimeArray, 1, times.microseconds );

      hb_itemReturnRelease( pTimeArray );
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

      PHB_ITEM pTimeSpanArray = hb_itemArrayNew( 2 );

         // sfTime offset
         PHB_ITEM pSubarrayTime1 = hb_arrayGetItemPtr( pTimeSpanArray, 1 );

         hb_arrayNew( pSubarrayTime1, 1 );
         hb_arraySetNLL( pSubarrayTime1, 1, timespan.offset.microseconds );

         // sfTime length
         PHB_ITEM pSubarrayTime2 = hb_arrayGetItemPtr( pTimeSpanArray, 2 );

         hb_arrayNew( pSubarrayTime2, 1 );
         hb_arraySetNLL( pSubarrayTime2, 1, timespan.length.microseconds );

      hb_itemReturnRelease( pTimeSpanArray );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfMusic_setLoopPoints(sfMusic* music, sfTimeSpan timePoints);
HB_FUNC( SFMUSIC_SETLOOPPOINTS )
{
   PHB_ITEM pItem;

   sfMusic* music = hb_sfMusic_param( 1 );

   if( music && ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 2 )
   {
      sfTimeSpan timePoints;

      // sfTime offset
      PHB_ITEM pSubarrayTime1 = hb_arrayGetItemPtr( pItem, 1 );

      timePoints.offset.microseconds = hb_arrayGetNLL( pSubarrayTime1, 1 );

      // sfTime length
      PHB_ITEM pSubarrayTime2 = hb_arrayGetItemPtr( pItem, 2 );

      timePoints.length.microseconds = hb_arrayGetNLL( pSubarrayTime2, 1 );

      sfMusic_setLoopPoints( music, timePoints );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

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
HB_FUNC( SFMUSIC_GETCHANNELCOUNT )
{
   const sfMusic* music = hb_sfMusic_param( 1 );

   if( music )
   {
      hb_retni( ( unsigned int ) sfMusic_getChannelCount( music ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// unsigned int sfMusic_getSampleRate(const sfMusic* music);
HB_FUNC( SFMUSIC_GETSAMPLERATE )
{
   const sfMusic* music = hb_sfMusic_param( 1 );

   if( music )
   {
      hb_retni( ( unsigned int ) sfMusic_getSampleRate( music ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfSoundStatus sfMusic_getStatus(const sfMusic* music);
HB_FUNC( SFMUSIC_GETSTATUS )
{
   const sfMusic* music = hb_sfMusic_param( 1 );

   if( music )
   {
      hb_retni( ( sfSoundStatus ) sfMusic_getStatus( music ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfTime sfMusic_getPlayingOffset(const sfMusic* music);
HB_FUNC( SFMUSIC_GETPLAYINGOFFSET )
{
   const sfMusic* music = hb_sfMusic_param( 1 );

   if( music )
   {
      sfTime sftime = sfMusic_getPlayingOffset( music );

      PHB_ITEM pTimeArray = hb_itemArrayNew( 1 );

      hb_arraySetNLL( pTimeArray, 1, sftime.microseconds );

      hb_itemReturnRelease( pTimeArray );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfMusic_setPitch(sfMusic* music, float pitch);
HB_FUNC( SFMUSIC_SETPITCH )
{
   sfMusic* music = hb_sfMusic_param( 1 );

   if( music && hb_param( 1, HB_IT_NUMERIC ) != NULL )
   {
      sfMusic_setPitch( music, ( float ) hb_parnd( 2 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfMusic_setVolume(sfMusic* music, float volume);
HB_FUNC( SFMUSIC_SETVOLUME )
{
   sfMusic* music = hb_sfMusic_param( 1 );

   if( music && hb_param( 1, HB_IT_NUMERIC ) != NULL )
   {
      sfMusic_setVolume( music, ( float ) hb_parnd( 2 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

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
