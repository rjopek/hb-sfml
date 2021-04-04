/*
 * SFML library: View.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

/* Graphics/sfView */
static HB_GARBAGE_FUNC( hb_sfView_destructor )
{
   sfView ** ppSfView = ( sfView ** ) Cargo;

   if( *ppSfView )
   {
      sfView_destroy( *ppSfView );
      *ppSfView = NULL;
   }
}

static const HB_GC_FUNCS s_gcSfViewFuncs =
{
   hb_sfView_destructor,
   hb_gcDummyMark
};

sfView * hb_sfViewItemGet( PHB_ITEM pItem )
{
   sfView ** ppSfView = ( sfView ** ) hb_itemGetPtrGC( pItem, &s_gcSfViewFuncs );

   return ppSfView ? *ppSfView : NULL;
}

PHB_ITEM hb_sfViewItemPut( PHB_ITEM pItem, sfView * pSfView )
{
   sfView ** ppSfView = ( sfView ** ) hb_gcAllocate( sizeof( sfView * ), &s_gcSfViewFuncs );

   *ppSfView = pSfView;
   return hb_itemPutPtrGC( pItem, ppSfView );
}

sfView * hb_sfView_param( int iParam )
{
   sfView ** ppSfView = ( sfView ** ) hb_parptrGC( &s_gcSfViewFuncs, iParam );

   if( ppSfView && *ppSfView )
   {
      return *ppSfView;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      return NULL;
   }
}

void hb_sfView_ret( sfView * pSfView )
{
   hb_sfViewItemPut( hb_stackReturnItem(), pSfView );
}

// sfView* sfView_create(void);

// sfView* sfView_createFromRect(sfFloatRect rectangle);

// sfView* sfView_copy(const sfView* view);

// void sfView_destroy(sfView* view);
HB_FUNC( SFVIEW_DESTROY )
{
   sfView ** ppSfView = ( sfView ** ) hb_parptrGC( &s_gcSfViewFuncs, 1 );

   if( ppSfView && *ppSfView )
   {
      sfView_destroy( *ppSfView );
      *ppSfView = NULL;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfView_setCenter(sfView* view, sfVector2f center);

// void sfView_setSize(sfView* view, sfVector2f size);

// void sfView_setRotation(sfView* view, float angle);

// void sfView_setViewport(sfView* view, sfFloatRect viewport);

// void sfView_reset(sfView* view, sfFloatRect rectangle);

// sfVector2f sfView_getCenter(const sfView* view);

// sfVector2f sfView_getSize(const sfView* view);

// float sfView_getRotation(const sfView* view);

// sfFloatRect sfView_getViewport(const sfView* view);

// void sfView_move(sfView* view, sfVector2f offset);

// void sfView_rotate(sfView* view, float angle);

// void sfView_zoom(sfView* view, float factor);
