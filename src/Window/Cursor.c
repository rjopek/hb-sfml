/*
 * SFML library: Cursor.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

// sfCursor* sfCursor_createFromPixels(const sfUint8* pixels, sfVector2u size, sfVector2u hotspot);
HB_FUNC( sfCursor_createFromPixels )
{
   PHB_ITEM pItem1, pItem2;

   if( hb_param( 1, HB_IT_STRING ) != NULL &&
      ( pItem1 = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 2 &&
      ( pItem2 = hb_param( 3, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 2 )
   {
      sfVector2u size;

      size.x = ( unsigned int ) hb_arrayGetNI( pItem1, 1 );
      size.y = ( unsigned int ) hb_arrayGetNI( pItem1, 2 );

      sfVector2u hotspot;

      hotspot.x = ( unsigned int ) hb_arrayGetNI( pItem2, 1 );
      hotspot.y = ( unsigned int ) hb_arrayGetNI( pItem2, 2 );

      hb_sfCursor_ret( sfCursor_createFromPixels( ( const unsigned char * ) hb_parc( 1 ), size, hotspot ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfCursor* sfCursor_createFromSystem(sfCursorType type);
HB_FUNC( SFCURSOR_CREATEFROMSYSTEM )
{
   if( hb_param( 3, HB_IT_INTEGER ) != NULL )
   {
      hb_sfCursor_ret( sfCursor_createFromSystem( hb_parni( 1 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfCursor_destroy(sfCursor* cursor);
/* This function is in the file core.c */