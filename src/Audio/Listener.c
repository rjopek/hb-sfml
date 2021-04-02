/*
 * SFML library: Listener.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

// void sfListener_setGlobalVolume(float volume);
HB_FUNC( SFLISTENER_SETGLOBALVOLUME )
{
   if( hb_param( 1, HB_IT_NUMERIC ) != NULL )
   {
      sfListener_setGlobalVolume( ( float ) hb_parnd( 1 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// float sfListener_getGlobalVolume(void);
HB_FUNC( SFLISTENER_GETGLOBALVOLUME )
{
   hb_retnd( ( float ) sfListener_getGlobalVolume() );
}

// void sfListener_setPosition(sfVector3f position);
HB_FUNC( SFLISTENER_SETPOSITION )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 3 )
   {
      sfVector3f position;

      position.x = ( float ) hb_arrayGetND( pItem, 1 );
      position.y = ( float ) hb_arrayGetND( pItem, 2 );
      position.z = ( float ) hb_arrayGetND( pItem, 3 );

      sfListener_setPosition( position );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfVector3f sfListener_getPosition();
HB_FUNC( SFLISTENER_GETPOSITION )
{
   sfVector3f sfvector3f = sfListener_getPosition( ( unsigned int ) hb_parni( 1 ) );

   PHB_ITEM info = hb_itemArrayNew( 3 );

   hb_arraySetND( info, 1, ( float ) sfvector3f.x );
   hb_arraySetND( info, 2, ( float ) sfvector3f.y );
   hb_arraySetND( info, 3, ( float ) sfvector3f.z );

   hb_itemReturnRelease( info );
}

// void sfListener_setDirection(sfVector3f direction);
HB_FUNC( SFLISTENER_SETDIRECTION )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 3 )
   {
      sfVector3f direction;

      direction.x = ( float ) hb_arrayGetND( pItem, 1 );
      direction.y = ( float ) hb_arrayGetND( pItem, 2 );
      direction.z = ( float ) hb_arrayGetND( pItem, 3 );

      sfListener_setDirection( direction );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfVector3f sfListener_getDirection();
HB_FUNC( SFLISTENER_GETDIRECTION )
{
   sfVector3f sfvector3f = sfListener_getDirection( ( unsigned int ) hb_parni( 1 ) );

   PHB_ITEM info = hb_itemArrayNew( 3 );

   hb_arraySetND( info, 1, ( float ) sfvector3f.x );
   hb_arraySetND( info, 2, ( float ) sfvector3f.y );
   hb_arraySetND( info, 3, ( float ) sfvector3f.z );

   hb_itemReturnRelease( info );
}

// void sfListener_setUpVector(sfVector3f upVector);
HB_FUNC( SFLISTENER_SETUPVECTOR )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 3 )
   {
      sfVector3f upVector;

      upVector.x = ( float ) hb_arrayGetND( pItem, 1 );
      upVector.y = ( float ) hb_arrayGetND( pItem, 2 );
      upVector.z = ( float ) hb_arrayGetND( pItem, 3 );

      sfListener_setUpVector( upVector );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfVector3f sfListener_getUpVector();
HB_FUNC( SFLISTENER_GETUPVECTOR )
{
   sfVector3f sfvector3f = sfListener_getUpVector( ( unsigned int ) hb_parni( 1 ) );

   PHB_ITEM info = hb_itemArrayNew( 3 );

   hb_arraySetND( info, 1, ( float ) sfvector3f.x );
   hb_arraySetND( info, 2, ( float ) sfvector3f.y );
   hb_arraySetND( info, 3, ( float ) sfvector3f.z );

   hb_itemReturnRelease( info );
}
