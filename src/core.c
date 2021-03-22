/*
 * SFML library: core.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

static HB_GARBAGE_FUNC( hb_sfWindow_destructor )
{
   sfWindow ** ppSfWindow = ( sfWindow ** ) Cargo;

   if( *ppSfWindow )
   {
      sfWindow_destroy( *ppSfWindow );
      *ppSfWindow = NULL;
   }
}

static const HB_GC_FUNCS s_gcSfWindowFuncs =
{
   hb_sfWindow_destructor,
   hb_gcDummyMark
};

sfWindow * hb_sfWindowItemGet( PHB_ITEM pItem )
{
   sfWindow ** ppSfWindow = ( sfWindow ** ) hb_itemGetPtrGC( pItem, &s_gcSfWindowFuncs );

   return ppSfWindow ? *ppSfWindow : NULL;
}

PHB_ITEM hb_sfWindowItemPut( PHB_ITEM pItem, sfWindow * psfWindow )
{
   sfWindow ** ppSfWindow = ( sfWindow ** ) hb_gcAllocate( sizeof( sfWindow * ), &s_gcSfWindowFuncs );

   *ppSfWindow = psfWindow;
   return hb_itemPutPtrGC( pItem, ppSfWindow );
}

sfWindow * hb_sfWindow_param( int iParam )
{
   sfWindow ** ppSfWindow = ( sfWindow ** ) hb_parptrGC( &s_gcSfWindowFuncs, iParam );

   if( ppSfWindow && *ppSfWindow )
   {
      return *ppSfWindow;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      return NULL;
   }
}

void hb_sfWindow_ret( sfWindow * psfWindow )
{
   hb_sfWindowItemPut( hb_stackReturnItem(), psfWindow );
}

HB_FUNC( sfWindow_DESTROY )
{
   sfWindow ** ppSfWindow = ( sfWindow ** ) hb_parptrGC( &s_gcSfWindowFuncs, 1 );

   if( ppSfWindow && *ppSfWindow )
   {
      sfWindow_destroy( *ppSfWindow );
      *ppSfWindow = NULL;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}
