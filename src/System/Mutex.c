/*
 * SFML library: Mutex.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

/* System/sfMutex */
static HB_GARBAGE_FUNC( hb_sfMutex_destructor )
{
   sfMutex ** ppSfMutex = ( sfMutex ** ) Cargo;

   if( *ppSfMutex )
   {
      sfMutex_destroy( *ppSfMutex );
      *ppSfMutex = NULL;
   }
}

static const HB_GC_FUNCS s_gcSfMutexFuncs =
{
   hb_sfMutex_destructor,
   hb_gcDummyMark
};

PHB_ITEM hb_sfMutexItemPut( PHB_ITEM pItem, sfMutex * pSfMutex )
{
   sfMutex ** ppSfMutex = ( sfMutex ** ) hb_gcAllocate( sizeof( sfMutex * ), &s_gcSfMutexFuncs );

   *ppSfMutex = pSfMutex;
   return hb_itemPutPtrGC( pItem, ppSfMutex );
}

sfMutex * hb_sfMutex_param( int iParam )
{
   sfMutex ** ppSfMutex = ( sfMutex ** ) hb_parptrGC( &s_gcSfMutexFuncs, iParam );

   if( ppSfMutex && *ppSfMutex )
   {
      return *ppSfMutex;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      return NULL;
   }
}

void hb_sfMutex_ret( sfMutex * pSfMutex )
{
   hb_sfMutexItemPut( hb_stackReturnItem(), pSfMutex );
}

// sfMutex* sfMutex_create(void);
HB_FUNC( SFMUTEX_CREATE )
{
   hb_sfMutex_ret( sfMutex_create() );
}

// void sfMutex_destroy(sfMutex* mutex);
HB_FUNC( SFMUTEX_DESTROY )
{
   sfMutex ** ppSfMutex = ( sfMutex ** ) hb_parptrGC( &s_gcSfMutexFuncs, 1 );

   if( ppSfMutex && *ppSfMutex )
   {
      sfMutex_destroy( *ppSfMutex );
      *ppSfMutex = NULL;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfMutex_lock(sfMutex* mutex);
HB_FUNC( SFMUTEX_LOCK )
{
   sfMutex* mutex = hb_sfMutex_param( 1 );

   if( mutex )
   {
      sfMutex_lock( mutex );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfMutex_unlock(sfMutex* mutex);
HB_FUNC( SFMUTEX_UNLOCK )
{
   sfMutex* mutex = hb_sfMutex_param( 1 );

   if( mutex )
   {
      sfMutex_unlock( mutex );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}
