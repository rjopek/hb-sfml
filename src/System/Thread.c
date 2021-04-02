/*
 * SFML library: Thread.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

/* System/sfThread */
static HB_GARBAGE_FUNC( hb_sfThread_destructor )
{
   sfThread ** ppSfThread = ( sfThread ** ) Cargo;

   if( *ppSfThread )
   {
      sfThread_destroy( *ppSfThread );
      *ppSfThread = NULL;
   }
}

static const HB_GC_FUNCS s_gcSfThreadFuncs =
{
   hb_sfThread_destructor,
   hb_gcDummyMark
};

sfThread * hb_sfThreadItemGet( PHB_ITEM pItem )
{
   sfThread ** ppSfThread = ( sfThread ** ) hb_itemGetPtrGC( pItem, &s_gcSfThreadFuncs );

   return ppSfThread ? *ppSfThread : NULL;
}

PHB_ITEM hb_sfThreadItemPut( PHB_ITEM pItem, sfThread * pSfThread )
{
   sfThread ** ppSfThread = ( sfThread ** ) hb_gcAllocate( sizeof( sfThread * ), &s_gcSfThreadFuncs );

   *ppSfThread = pSfThread;
   return hb_itemPutPtrGC( pItem, ppSfThread );
}

sfThread * hb_sfThread_param( int iParam )
{
   sfThread ** ppSfThread = ( sfThread ** ) hb_parptrGC( &s_gcSfThreadFuncs, iParam );

   if( ppSfThread && *ppSfThread )
   {
      return *ppSfThread;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      return NULL;
   }
}

void hb_sfThread_ret( sfThread * pSfThread )
{
   hb_sfThreadItemPut( hb_stackReturnItem(), pSfThread );
}

static void entry_point( void* data )
{
   ( void ) data;
}

// sfThread* sfThread_create(void (*function)(void*), void* userData);
HB_FUNC( SFTHREAD_CREATE )
{
   void* userData = hb_sfThread_param( 1 );

   if( userData )
   {
      sfThread_create( entry_point, userData );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfThread_destroy(sfThread* thread);
HB_FUNC( SFTHREAD_DESTROY )
{
   sfThread ** ppSfThread = ( sfThread ** ) hb_parptrGC( &s_gcSfThreadFuncs, 1 );

   if( ppSfThread && *ppSfThread )
   {
      sfThread_destroy( *ppSfThread );
      *ppSfThread = NULL;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfThread_launch(sfThread* thread);
HB_FUNC( SFTHREAD_LAUNCH )
{
   sfThread* thread = hb_sfThread_param( 1 );

   if( thread )
   {
      sfThread_launch( thread );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfThread_wait(sfThread* thread);
HB_FUNC( SFTHREAD_WAIT )
{
   sfThread* thread = hb_sfThread_param( 1 );

   if( thread )
   {
      sfThread_wait( thread );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfThread_terminate(sfThread* thread);
HB_FUNC( SFTHREAD_TERMINATE )
{
   sfThread* thread = hb_sfThread_param( 1 );

   if( thread )
   {
      sfThread_terminate( thread );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}
