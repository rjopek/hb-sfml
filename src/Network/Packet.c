/*
 * SFML library: Packet.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

/* Network/sfPacket */
static HB_GARBAGE_FUNC( hb_sfPacket_destructor )
{
   sfPacket ** ppSfPacket = ( sfPacket ** ) Cargo;

   if( *ppSfPacket )
   {
      sfPacket_destroy( *ppSfPacket );
      *ppSfPacket = NULL;
   }
}

static const HB_GC_FUNCS s_gcSfPacketFuncs =
{
   hb_sfPacket_destructor,
   hb_gcDummyMark
};

PHB_ITEM hb_sfPacketItemPut( PHB_ITEM pItem, sfPacket * pSfPacket )
{
   sfPacket ** ppSfPacket = ( sfPacket ** ) hb_gcAllocate( sizeof( sfPacket * ), &s_gcSfPacketFuncs );

   *ppSfPacket = pSfPacket;
   return hb_itemPutPtrGC( pItem, ppSfPacket );
}

sfPacket * hb_sfPacket_param( int iParam )
{
   sfPacket ** ppSfPacket = ( sfPacket ** ) hb_parptrGC( &s_gcSfPacketFuncs, iParam );

   if( ppSfPacket && *ppSfPacket )
   {
      return *ppSfPacket;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      return NULL;
   }
}

void hb_sfPacket_ret( sfPacket * pSfPacket )
{
   hb_sfPacketItemPut( hb_stackReturnItem(), pSfPacket );
}

// sfPacket* sfPacket_create(void);

// sfPacket* sfPacket_copy(const sfPacket* packet);

// void sfPacket_destroy(sfPacket* packet);
HB_FUNC( SFPACKET_DESTROY )
{
   sfPacket ** ppSfPacket = ( sfPacket ** ) hb_parptrGC( &s_gcSfPacketFuncs, 1 );

   if( ppSfPacket && *ppSfPacket )
   {
      sfPacket_destroy( *ppSfPacket );
      *ppSfPacket = NULL;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfPacket_append(sfPacket* packet, const void* data, size_t sizeInBytes);

// void sfPacket_clear(sfPacket* packet);

// const void* sfPacket_getData(const sfPacket* packet);

// size_t sfPacket_getDataSize(const sfPacket* packet);

// sfBool sfPacket_endOfPacket(const sfPacket* packet);

// sfBool sfPacket_canRead(const sfPacket* packet);

// sfBool   sfPacket_readBool(sfPacket* packet);

// sfInt8   sfPacket_readInt8(sfPacket* packet);

// sfUint8  sfPacket_readUint8(sfPacket* packet);

// sfInt16  sfPacket_readInt16(sfPacket* packet);

// sfUint16 sfPacket_readUint16(sfPacket* packet);

// sfInt32  sfPacket_readInt32(sfPacket* packet);

// sfUint32 sfPacket_readUint32(sfPacket* packet);

// float    sfPacket_readFloat(sfPacket* packet);

// double   sfPacket_readDouble(sfPacket* packet);

// void     sfPacket_readString(sfPacket* packet, char* string);

// void     sfPacket_readWideString(sfPacket* packet, wchar_t* string);

// void sfPacket_writeBool(sfPacket* packet, sfBool);

// void sfPacket_writeInt8(sfPacket* packet, sfInt8);

// void sfPacket_writeUint8(sfPacket* packet, sfUint8);

// void sfPacket_writeInt16(sfPacket* packet, sfInt16);

// void sfPacket_writeUint16(sfPacket* packet, sfUint16);

// void sfPacket_writeInt32(sfPacket* packet, sfInt32);

// void sfPacket_writeUint32(sfPacket* packet, sfUint32);

// void sfPacket_writeFloat(sfPacket* packet, float);

// void sfPacket_writeDouble(sfPacket* packet, double);

// void sfPacket_writeString(sfPacket* packet, const char* string);

// void sfPacket_writeWideString(sfPacket* packet, const wchar_t* string);
