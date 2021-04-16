/*
 * SFML library: SocketSelector.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

/* Network/sfSocketSelector */
static HB_GARBAGE_FUNC( hb_sfSocketSelector_destructor )
{
   sfSocketSelector ** ppSfSocketSelector = ( sfSocketSelector ** ) Cargo;

   if( *ppSfSocketSelector )
   {
      sfSocketSelector_destroy( *ppSfSocketSelector );
      *ppSfSocketSelector = NULL;
   }
}

static const HB_GC_FUNCS s_gcSfSocketSelectorFuncs =
{
   hb_sfSocketSelector_destructor,
   hb_gcDummyMark
};

PHB_ITEM hb_sfSocketSelectorItemPut( PHB_ITEM pItem, sfSocketSelector * pSfSocketSelector )
{
   sfSocketSelector ** ppSfSocketSelector = ( sfSocketSelector ** ) hb_gcAllocate( sizeof( sfSocketSelector * ), &s_gcSfSocketSelectorFuncs );

   *ppSfSocketSelector = pSfSocketSelector;
   return hb_itemPutPtrGC( pItem, ppSfSocketSelector );
}

sfSocketSelector * hb_sfSocketSelector_param( int iParam )
{
   sfSocketSelector ** ppSfSocketSelector = ( sfSocketSelector ** ) hb_parptrGC( &s_gcSfSocketSelectorFuncs, iParam );

   if( ppSfSocketSelector && *ppSfSocketSelector )
   {
      return *ppSfSocketSelector;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      return NULL;
   }
}

void hb_sfSocketSelector_ret( sfSocketSelector * pSfSocketSelector )
{
   hb_sfSocketSelectorItemPut( hb_stackReturnItem(), pSfSocketSelector );
}

// sfSocketSelector* sfSocketSelector_create(void);

// sfSocketSelector* sfSocketSelector_copy(const sfSocketSelector* selector);

// void sfSocketSelector_destroy(sfSocketSelector* selector);
HB_FUNC( SFSOCKETSELECTOR_DESTROY )
{
   sfSocketSelector ** ppSfSocketSelector = ( sfSocketSelector ** ) hb_parptrGC( &s_gcSfSocketSelectorFuncs, 1 );

   if( ppSfSocketSelector && *ppSfSocketSelector )
   {
      sfSocketSelector_destroy( *ppSfSocketSelector );
      *ppSfSocketSelector = NULL;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfSocketSelector_addTcpListener(sfSocketSelector* selector, sfTcpListener* socket);

// void sfSocketSelector_addTcpSocket(sfSocketSelector* selector, sfTcpSocket* socket);

// void sfSocketSelector_addUdpSocket(sfSocketSelector* selector, sfUdpSocket* socket);

// void sfSocketSelector_removeTcpListener(sfSocketSelector* selector, sfTcpListener* socket);

// void sfSocketSelector_removeTcpSocket(sfSocketSelector* selector, sfTcpSocket* socket);

// void sfSocketSelector_removeUdpSocket(sfSocketSelector* selector, sfUdpSocket* socket);

// void sfSocketSelector_clear(sfSocketSelector* selector);

// sfBool sfSocketSelector_wait(sfSocketSelector* selector, sfTime timeout);

// sfBool sfSocketSelector_isTcpListenerReady(const sfSocketSelector* selector, sfTcpListener* socket);

// sfBool sfSocketSelector_isTcpSocketReady(const sfSocketSelector* selector, sfTcpSocket* socket);

// sfBool sfSocketSelector_isUdpSocketReady(const sfSocketSelector* selector, sfUdpSocket* socket);
