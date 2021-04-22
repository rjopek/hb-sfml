/*
 * SFML library: Touch.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

// sfBool sfTouch_isDown(unsigned int finger);
HB_FUNC( SFTOUCH_ISDOWN )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL )
   {
      hb_retl( sfTouch_isDown( ( unsigned int ) hb_parni( 1 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfVector2i sfTouch_getPosition(unsigned int finger, const sfWindow* relativeTo);
HB_FUNC( SFTOUCH_GETPOSITION )
{
   const sfWindow* relativeTo = hb_sfWindow_param( 1 );

   if( hb_param( 1, HB_IT_INTEGER ) != NULL && relativeTo )
   {
      sfVector2i sfvector2i = sfTouch_getPosition( ( unsigned int ) hb_parni( 1 ), relativeTo );

      PHB_ITEM pVector2iArray = hb_itemArrayNew( 2 );

      hb_arraySetNI( pVector2iArray, 1, sfvector2i.x );
      hb_arraySetNI( pVector2iArray, 2, sfvector2i.y );

      hb_itemReturnRelease( pVector2iArray );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}
