/*
 * SFML library: Sleep.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

// void sfSleep(sfTime duration);
HB_FUNC( SFSLEEP )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 1 )
   {
      sfTime duration;

      duration.microseconds = hb_arrayGetNLL( pItem, 1 );

      sfSleep( duration );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}
