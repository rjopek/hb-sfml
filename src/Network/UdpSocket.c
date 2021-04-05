/*
 * SFML library: UdpSocket.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

/* Network/sfUdpSocket */
static HB_GARBAGE_FUNC( hb_sfUdpSocket_destructor )
{
   sfUdpSocket ** ppSfUdpSocket = ( sfUdpSocket ** ) Cargo;

   if( *ppSfUdpSocket )
   {
      sfUdpSocket_destroy( *ppSfUdpSocket );
      *ppSfUdpSocket = NULL;
   }
}

static const HB_GC_FUNCS s_gcSfUdpSocketFuncs =
{
   hb_sfUdpSocket_destructor,
   hb_gcDummyMark
};

sfUdpSocket * hb_sfUdpSocketItemGet( PHB_ITEM pItem )
{
   sfUdpSocket ** ppSfUdpSocket = ( sfUdpSocket ** ) hb_itemGetPtrGC( pItem, &s_gcSfUdpSocketFuncs );

   return ppSfUdpSocket ? *ppSfUdpSocket : NULL;
}

PHB_ITEM hb_sfUdpSocketItemPut( PHB_ITEM pItem, sfUdpSocket * pSfUdpSocket )
{
   sfUdpSocket ** ppSfUdpSocket = ( sfUdpSocket ** ) hb_gcAllocate( sizeof( sfUdpSocket * ), &s_gcSfUdpSocketFuncs );

   *ppSfUdpSocket = pSfUdpSocket;
   return hb_itemPutPtrGC( pItem, ppSfUdpSocket );
}

sfUdpSocket * hb_sfUdpSocket_param( int iParam )
{
   sfUdpSocket ** ppSfUdpSocket = ( sfUdpSocket ** ) hb_parptrGC( &s_gcSfUdpSocketFuncs, iParam );

   if( ppSfUdpSocket && *ppSfUdpSocket )
   {
      return *ppSfUdpSocket;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      return NULL;
   }
}

void hb_sfUdpSocket_ret( sfUdpSocket * pSfUdpSocket )
{
   hb_sfUdpSocketItemPut( hb_stackReturnItem(), pSfUdpSocket );
}

// sfUdpSocket* sfUdpSocket_create(void);

// void sfUdpSocket_destroy(sfUdpSocket* socket);
HB_FUNC( SFUDPSOCKET_DESTROY )
{
   sfUdpSocket ** ppSfUdpSocket = ( sfUdpSocket ** ) hb_parptrGC( &s_gcSfUdpSocketFuncs, 1 );

   if( ppSfUdpSocket && *ppSfUdpSocket )
   {
      sfUdpSocket_destroy( *ppSfUdpSocket );
      *ppSfUdpSocket = NULL;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfUdpSocket_setBlocking(sfUdpSocket* socket, sfBool blocking);

// sfBool sfUdpSocket_isBlocking(const sfUdpSocket* socket);

// unsigned short sfUdpSocket_getLocalPort(const sfUdpSocket* socket);

// sfSocketStatus sfUdpSocket_bind(sfUdpSocket* socket, unsigned short port, sfIpAddress address);

// void sfUdpSocket_unbind(sfUdpSocket* socket);

// sfSocketStatus sfUdpSocket_send(sfUdpSocket* socket, const void* data, size_t size, sfIpAddress remoteAddress, unsigned short remotePort);

// sfSocketStatus sfUdpSocket_receive(sfUdpSocket* socket, void* data, size_t size, size_t* received, sfIpAddress* remoteAddress, unsigned short* remotePort);

// sfSocketStatus sfUdpSocket_sendPacket(sfUdpSocket* socket, sfPacket* packet, sfIpAddress remoteAddress, unsigned short remotePort);

// sfSocketStatus sfUdpSocket_receivePacket(sfUdpSocket* socket, sfPacket* packet, sfIpAddress* remoteAddress, unsigned short* remotePort);

// unsigned int sfUdpSocket_maxDatagramSize();
