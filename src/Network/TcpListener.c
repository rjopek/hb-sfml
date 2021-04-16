/*
 * SFML library: TcpListener.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

/* Network/sfTcpListener */
static HB_GARBAGE_FUNC( hb_sfTcpListener_destructor )
{
   sfTcpListener ** ppSfTcpListener = ( sfTcpListener ** ) Cargo;

   if( *ppSfTcpListener )
   {
      sfTcpListener_destroy( *ppSfTcpListener );
      *ppSfTcpListener = NULL;
   }
}

static const HB_GC_FUNCS s_gcSfTcpListenerFuncs =
{
   hb_sfTcpListener_destructor,
   hb_gcDummyMark
};

PHB_ITEM hb_sfTcpListenerItemPut( PHB_ITEM pItem, sfTcpListener * pSfTcpListener )
{
   sfTcpListener ** ppSfTcpListener = ( sfTcpListener ** ) hb_gcAllocate( sizeof( sfTcpListener * ), &s_gcSfTcpListenerFuncs );

   *ppSfTcpListener = pSfTcpListener;
   return hb_itemPutPtrGC( pItem, ppSfTcpListener );
}

sfTcpListener * hb_sfTcpListener_param( int iParam )
{
   sfTcpListener ** ppSfTcpListener = ( sfTcpListener ** ) hb_parptrGC( &s_gcSfTcpListenerFuncs, iParam );

   if( ppSfTcpListener && *ppSfTcpListener )
   {
      return *ppSfTcpListener;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      return NULL;
   }
}

void hb_sfTcpListener_ret( sfTcpListener * pSfTcpListener )
{
   hb_sfTcpListenerItemPut( hb_stackReturnItem(), pSfTcpListener );
}

// sfTcpListener* sfTcpListener_create(void);

// void sfTcpListener_destroy(sfTcpListener* listener);
HB_FUNC( SFTCPLISTENER_DESTROY )
{
   sfTcpListener ** ppSfTcpListener = ( sfTcpListener ** ) hb_parptrGC( &s_gcSfTcpListenerFuncs, 1 );

   if( ppSfTcpListener && *ppSfTcpListener )
   {
      sfTcpListener_destroy( *ppSfTcpListener );
      *ppSfTcpListener = NULL;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfTcpListener_setBlocking(sfTcpListener* listener, sfBool blocking);

// sfBool sfTcpListener_isBlocking(const sfTcpListener* listener);

// unsigned short sfTcpListener_getLocalPort(const sfTcpListener* listener);

// sfSocketStatus sfTcpListener_listen(sfTcpListener* listener, unsigned short port, sfIpAddress address);

// sfSocketStatus sfTcpListener_accept(sfTcpListener* listener, sfTcpSocket** connected);
