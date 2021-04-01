/*
 * SFML library: Clock.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

/* System/sfClock */
static HB_GARBAGE_FUNC( hb_sfClock_destructor )
{
   sfClock ** ppSfClock = ( sfClock ** ) Cargo;

   if( *ppSfClock )
   {
      sfClock_destroy( *ppSfClock );
      *ppSfClock = NULL;
   }
}

static const HB_GC_FUNCS s_gcSfClockFuncs =
{
   hb_sfClock_destructor,
   hb_gcDummyMark
};

sfClock * hb_sfClockItemGet( PHB_ITEM pItem )
{
   sfClock ** ppSfClock = ( sfClock ** ) hb_itemGetPtrGC( pItem, &s_gcSfClockFuncs );

   return ppSfClock ? *ppSfClock : NULL;
}

PHB_ITEM hb_sfClockItemPut( PHB_ITEM pItem, sfClock * pSfClock )
{
   sfClock ** ppSfClock = ( sfClock ** ) hb_gcAllocate( sizeof( sfClock * ), &s_gcSfClockFuncs );

   *ppSfClock = pSfClock;
   return hb_itemPutPtrGC( pItem, ppSfClock );
}

sfClock * hb_sfClock_param( int iParam )
{
   sfClock ** ppSfClock = ( sfClock ** ) hb_parptrGC( &s_gcSfClockFuncs, iParam );

   if( ppSfClock && *ppSfClock )
   {
      return *ppSfClock;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      return NULL;
   }
}

void hb_sfClock_ret( sfClock * pSfClock )
{
   hb_sfClockItemPut( hb_stackReturnItem(), pSfClock );
}

// sfClock* sfClock_create(void);
HB_FUNC( SFCLOCK_CREATE )
{
   hb_sfClock_ret( sfClock_create() );
}

// sfClock* sfClock_copy(const sfClock* clock);
HB_FUNC( SFCLOCK_COPY )
{
   const sfClock* clock = hb_sfClock_param( 1 );

   if( clock )
   {
      hb_sfClock_ret( sfClock_copy( clock ) );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfClock_destroy(sfClock* clock);
HB_FUNC( SFCLOCK_DESTROY )
{
   sfClock ** ppSfClock = ( sfClock ** ) hb_parptrGC( &s_gcSfClockFuncs, 1 );

   if( ppSfClock && *ppSfClock )
   {
      sfClock_destroy( *ppSfClock );
      *ppSfClock = NULL;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfTime sfClock_getElapsedTime(const sfClock* clock);
HB_FUNC( SFCLOCK_GETELAPSEDTIME )
{
   const sfClock* clock = hb_sfClock_param( 1 );

   if( clock )
   {
      sfTime times = sfClock_getElapsedTime( clock );

      PHB_ITEM info = hb_itemArrayNew( 1 );

      hb_arraySetNLL( info, 1, times.microseconds );

      hb_itemReturnRelease( info );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfTime sfClock_restart(sfClock* clock);
HB_FUNC( SFCLOCK_RESTART )
{
   sfClock* clock = hb_sfClock_param( 1 );

   if( clock )
   {
      sfTime times = sfClock_restart( clock );

      PHB_ITEM info = hb_itemArrayNew( 1 );

      hb_arraySetNLL( info, 1, times.microseconds );

      hb_itemReturnRelease( info );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}
