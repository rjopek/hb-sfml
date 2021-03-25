/*
 * SFML library: core.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

/* sfRenderWindow */
static HB_GARBAGE_FUNC( hb_sfRenderWindow_destructor )
{
   sfRenderWindow ** ppSfRenderWindow = ( sfRenderWindow ** ) Cargo;

   if( *ppSfRenderWindow )
   {
      sfRenderWindow_destroy( *ppSfRenderWindow );
      *ppSfRenderWindow = NULL;
   }
}

static const HB_GC_FUNCS s_gcSfRenderWindowFuncs =
{
   hb_sfRenderWindow_destructor,
   hb_gcDummyMark
};

sfRenderWindow * hb_sfRenderWindowItemGet( PHB_ITEM pItem )
{
   sfRenderWindow ** ppSfRenderWindow = ( sfRenderWindow ** ) hb_itemGetPtrGC( pItem, &s_gcSfRenderWindowFuncs );

   return ppSfRenderWindow ? *ppSfRenderWindow : NULL;
}

PHB_ITEM hb_sfRenderWindowItemPut( PHB_ITEM pItem, sfRenderWindow * pSfRenderWindow )
{
   sfRenderWindow ** ppSfRenderWindow = ( sfRenderWindow ** ) hb_gcAllocate( sizeof( sfRenderWindow * ), &s_gcSfRenderWindowFuncs );

   *ppSfRenderWindow = pSfRenderWindow;
   return hb_itemPutPtrGC( pItem, ppSfRenderWindow );
}

sfRenderWindow * hb_sfRenderWindow_param( int iParam )
{
   sfRenderWindow ** ppSfRenderWindow = ( sfRenderWindow ** ) hb_parptrGC( &s_gcSfRenderWindowFuncs, iParam );

   if( ppSfRenderWindow && *ppSfRenderWindow )
   {
      return *ppSfRenderWindow;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      return NULL;
   }
}

void hb_sfRenderWindow_ret( sfRenderWindow * pSfRenderWindow )
{
   hb_sfWindowItemPut( hb_stackReturnItem(), pSfRenderWindow );
}

HB_FUNC( SFCONTEXT_DESTROY )
{
   sfRenderWindow ** ppSfRenderWindow = ( sfRenderWindow ** ) hb_parptrGC( &s_gcSfRenderWindowFuncs, 1 );

   if( ppSfRenderWindow && *ppSfRenderWindow )
   {
      sfRenderWindow_destroy( *ppSfRenderWindow );
      *ppSfRenderWindow = NULL;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

/* sfWindow */
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

PHB_ITEM hb_sfWindowItemPut( PHB_ITEM pItem, sfWindow * pSfWindow )
{
   sfWindow ** ppSfWindow = ( sfWindow ** ) hb_gcAllocate( sizeof( sfWindow * ), &s_gcSfWindowFuncs );

   *ppSfWindow = pSfWindow;
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

void hb_sfWindow_ret( sfWindow * pSfWindow )
{
   hb_sfWindowItemPut( hb_stackReturnItem(), pSfWindow );
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

/* sfContext */
static HB_GARBAGE_FUNC( hb_sfContext_destructor )
{
   sfContext ** ppSfContext = ( sfContext ** ) Cargo;

   if( *ppSfContext )
   {
      sfContext_destroy( *ppSfContext );
      *ppSfContext = NULL;
   }
}

static const HB_GC_FUNCS s_gcSfContextFuncs =
{
   hb_sfContext_destructor,
   hb_gcDummyMark
};

sfContext * hb_sfContextItemGet( PHB_ITEM pItem )
{
   sfContext ** ppSfContext = ( sfContext ** ) hb_itemGetPtrGC( pItem, &s_gcSfContextFuncs );

   return ppSfContext ? *ppSfContext : NULL;
}

PHB_ITEM hb_sfContextItemPut( PHB_ITEM pItem, sfContext * pSfContext )
{
   sfContext ** ppSfContext = ( sfContext ** ) hb_gcAllocate( sizeof( sfContext * ), &s_gcSfContextFuncs );

   *ppSfContext = pSfContext;
   return hb_itemPutPtrGC( pItem, ppSfContext );
}

sfContext * hb_sfContext_param( int iParam )
{
   sfContext ** ppSfContext = ( sfContext ** ) hb_parptrGC( &s_gcSfContextFuncs, iParam );

   if( ppSfContext && *ppSfContext )
   {
      return *ppSfContext;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      return NULL;
   }
}

void hb_sfContext_ret( sfContext * pSfContext )
{
   hb_sfContextItemPut( hb_stackReturnItem(), pSfContext );
}

HB_FUNC( SFCONTEXT_DESTROY )
{
   sfContext ** ppSfContext = ( sfContext ** ) hb_parptrGC( &s_gcSfContextFuncs, 1 );

   if( ppSfContext && *ppSfContext )
   {
      sfContext_destroy( *ppSfContext );
      *ppSfContext = NULL;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}
