/*
 * SFML library: Time.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

// sfTime sfTime_Zero;

// float sfTime_asSeconds(sfTime time);
HB_FUNC( SFTIME_ASSECONDS )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 1 )
   {
      sfTime time;

      time.microseconds = hb_arrayGetNLL( pItem, 1 );

      hb_retnd( ( float ) sfTime_asSeconds( time ) );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfInt32 sfTime_asMilliseconds(sfTime time);
HB_FUNC( SFTIME_ASMILLISECONDS )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 1 )
   {
      sfTime time;

      time.microseconds = hb_arrayGetNLL( pItem, 1 );

      hb_retni( ( signed int ) sfTime_asMilliseconds( time ) );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfInt64 sfTime_asMicroseconds(sfTime time);
HB_FUNC( SFTIME_ASMICROSECONDS )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 1 )
   {
      sfTime time;

      time.microseconds = hb_arrayGetNLL( pItem, 1 );

      hb_retnll( sfTime_asMicroseconds( time ) );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfTime sfSeconds(float amount);
HB_FUNC( SFSECONDS )
{
   if( hb_param( 1, HB_IT_NUMERIC ) != NULL )
   {
      sfTime times = sfSeconds( ( float ) hb_parnd( 1 ) );

      PHB_ITEM info = hb_itemArrayNew( 1 );

      hb_arraySetNLL( info, 1, times.microseconds );

      hb_itemReturnRelease( info );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfTime sfMilliseconds(sfInt32 amount);
HB_FUNC( SFMILLISECONDS )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL )
   {
      sfTime times = sfMilliseconds( ( signed int ) hb_parni( 1 ) );

      PHB_ITEM info = hb_itemArrayNew( 1 );

      hb_arraySetNLL( info, 1, times.microseconds );

      hb_itemReturnRelease( info );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfTime sfMicroseconds(sfInt64 amount);
HB_FUNC( SFMICROSECONDS )
{
   if( hb_param( 1, HB_IT_LONG ) != NULL )
   {
      sfTime times = sfMicroseconds( hb_parnl( 1 ) );

      PHB_ITEM info = hb_itemArrayNew( 1 );

      hb_arraySetNLL( info, 1, times.microseconds );

      hb_itemReturnRelease( info );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}
