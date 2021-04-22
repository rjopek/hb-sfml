/*
 * SFML library: Mouse.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

// sfBool sfMouse_isButtonPressed(sfMouseButton button);
HB_FUNC( SFMOUSE_ISBUTTONPRESSED )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL )
   {
      hb_retl( sfMouse_isButtonPressed( ( unsigned int ) hb_parni( 1 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfVector2i sfMouse_getPosition(const sfWindow* relativeTo);
HB_FUNC( SFMOUSE_GETPOSITION )
{
   const sfWindow* relativeTo = hb_sfWindow_param( 1 );

   if( relativeTo )
   {
      sfVector2i sfvector2i = sfMouse_getPosition( relativeTo );

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

// void sfMouse_setPosition(sfVector2i position, const sfWindow* relativeTo);
HB_FUNC( SFMOUSE_SETPOSITION )
{
   PHB_ITEM pItem;

   const sfWindow* relativeTo = hb_sfWindow_param( 2 );

   if( ( pItem = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 2 && relativeTo )
   {
      sfVector2i position;

      position.x = hb_arrayGetNI( pItem, 1 );
      position.y = hb_arrayGetNI( pItem, 2 );

      sfMouse_setPosition( position, relativeTo );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}
