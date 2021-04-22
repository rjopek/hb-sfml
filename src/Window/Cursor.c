/*
 * SFML library: Cursor.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

/* Window/sfCursor */
static HB_GARBAGE_FUNC( hb_sfCursor_destructor )
{
   sfCursor ** ppSfCursor = ( sfCursor ** ) Cargo;

   if( *ppSfCursor )
   {
      sfCursor_destroy( *ppSfCursor );
      *ppSfCursor = NULL;
   }
}

static const HB_GC_FUNCS s_gcSfCursorFuncs =
{
   hb_sfCursor_destructor,
   hb_gcDummyMark
};

PHB_ITEM hb_sfCursorItemPut( PHB_ITEM pItem, sfCursor * pSfCursor )
{
   sfCursor ** ppSfCursor = ( sfCursor ** ) hb_gcAllocate( sizeof( sfCursor * ), &s_gcSfCursorFuncs );

   *ppSfCursor = pSfCursor;
   return hb_itemPutPtrGC( pItem, ppSfCursor );
}

sfCursor * hb_sfCursor_param( int iParam )
{
   sfCursor ** ppSfCursor = ( sfCursor ** ) hb_parptrGC( &s_gcSfCursorFuncs, iParam );

   if( ppSfCursor && *ppSfCursor )
   {
      return *ppSfCursor;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      return NULL;
   }
}

void hb_sfCursor_ret( sfCursor * pSfCursor )
{
   hb_sfCursorItemPut( hb_stackReturnItem(), pSfCursor );
}

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

      hb_sfCursor_ret( sfCursor_createFromPixels( ( const unsigned char * ) hb_parptr( 1 ), size, hotspot ) );
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
HB_FUNC( SFCURSOR_DESTROY )
{
   sfCursor ** ppSfCursor = ( sfCursor ** ) hb_parptrGC( &s_gcSfCursorFuncs, 1 );

   if( ppSfCursor && *ppSfCursor )
   {
      sfCursor_destroy( *ppSfCursor );
      *ppSfCursor = NULL;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}
