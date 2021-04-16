/*
 * SFML library: TcpSocket.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

/* Network/sfTcpSocket */
static HB_GARBAGE_FUNC( hb_sfTcpSocket_destructor )
{
   sfTcpSocket ** ppSfTcpSocket = ( sfTcpSocket ** ) Cargo;

   if( *ppSfTcpSocket )
   {
      sfTcpSocket_destroy( *ppSfTcpSocket );
      *ppSfTcpSocket = NULL;
   }
}

static const HB_GC_FUNCS s_gcSfTcpSocketFuncs =
{
   hb_sfTcpSocket_destructor,
   hb_gcDummyMark
};

PHB_ITEM hb_sfTcpSocketItemPut( PHB_ITEM pItem, sfTcpSocket * pSfTcpSocket )
{
   sfTcpSocket ** ppSfTcpSocket = ( sfTcpSocket ** ) hb_gcAllocate( sizeof( sfTcpSocket * ), &s_gcSfTcpSocketFuncs );

   *ppSfTcpSocket = pSfTcpSocket;
   return hb_itemPutPtrGC( pItem, ppSfTcpSocket );
}

sfTcpSocket * hb_sfTcpSocket_param( int iParam )
{
   sfTcpSocket ** ppSfTcpSocket = ( sfTcpSocket ** ) hb_parptrGC( &s_gcSfTcpSocketFuncs, iParam );

   if( ppSfTcpSocket && *ppSfTcpSocket )
   {
      return *ppSfTcpSocket;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      return NULL;
   }
}

void hb_sfTcpSocket_ret( sfTcpSocket * pSfTcpSocket )
{
   hb_sfTcpSocketItemPut( hb_stackReturnItem(), pSfTcpSocket );
}

// sfTcpSocket* sfTcpSocket_create(void);

// void sfTcpSocket_destroy(sfTcpSocket* socket);
HB_FUNC( SFTCPSOCKET_DESTROY )
{
   sfTcpSocket ** ppSfTcpSocket = ( sfTcpSocket ** ) hb_parptrGC( &s_gcSfTcpSocketFuncs, 1 );

   if( ppSfTcpSocket && *ppSfTcpSocket )
   {
      sfTcpSocket_destroy( *ppSfTcpSocket );
      *ppSfTcpSocket = NULL;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfTcpSocket_setBlocking(sfTcpSocket* socket, sfBool blocking);

// sfBool sfTcpSocket_isBlocking(const sfTcpSocket* socket);

// unsigned short sfTcpSocket_getLocalPort(const sfTcpSocket* socket);

// sfIpAddress sfTcpSocket_getRemoteAddress(const sfTcpSocket* socket);

// unsigned short sfTcpSocket_getRemotePort(const sfTcpSocket* socket);

// sfSocketStatus sfTcpSocket_connect(sfTcpSocket* socket, sfIpAddress remoteAddress, unsigned short remotePort, sfTime timeout);

// void sfTcpSocket_disconnect(sfTcpSocket* socket);

// sfSocketStatus sfTcpSocket_send(sfTcpSocket* socket, const void* data, size_t size);

// sfSocketStatus sfTcpSocket_sendPartial(sfTcpSocket* socket, const void* data, size_t size, size_t* sent);

// sfSocketStatus sfTcpSocket_receive(sfTcpSocket* socket, void* data, size_t size, size_t* received);

// sfSocketStatus sfTcpSocket_sendPacket(sfTcpSocket* socket, sfPacket* packet);

// sfSocketStatus sfTcpSocket_receivePacket(sfTcpSocket* socket, sfPacket* packet);
