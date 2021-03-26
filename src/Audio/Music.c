/*
 * SFML library: Music.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

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

// void sfMusic_destroy(sfMusic* music);

// void sfMusic_setLoop(sfMusic* music, sfBool loop);

// sfBool sfMusic_getLoop(const sfMusic* music);

// sfTime sfMusic_getDuration(const sfMusic* music);

// sfTimeSpan sfMusic_getLoopPoints(const sfMusic* music);

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

// void sfMusic_stop(sfMusic* music);

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
