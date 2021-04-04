/*
 * SFML library: VertexBuffer.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

/* Graphics/sfVertexBuffer */
static HB_GARBAGE_FUNC( hb_sfVertexBuffer_destructor )
{
   sfVertexBuffer ** ppSfVertexBuffer = ( sfVertexBuffer ** ) Cargo;

   if( *ppSfVertexBuffer )
   {
      sfVertexBuffer_destroy( *ppSfVertexBuffer );
      *ppSfVertexBuffer = NULL;
   }
}

static const HB_GC_FUNCS s_gcSfVertexBufferFuncs =
{
   hb_sfVertexBuffer_destructor,
   hb_gcDummyMark
};

sfVertexBuffer * hb_sfVertexBufferItemGet( PHB_ITEM pItem )
{
   sfVertexBuffer ** ppSfVertexBuffer = ( sfVertexBuffer ** ) hb_itemGetPtrGC( pItem, &s_gcSfVertexBufferFuncs );

   return ppSfVertexBuffer ? *ppSfVertexBuffer : NULL;
}

PHB_ITEM hb_sfVertexBufferItemPut( PHB_ITEM pItem, sfVertexBuffer * pSfVertexBuffer )
{
   sfVertexBuffer ** ppSfVertexBuffer = ( sfVertexBuffer ** ) hb_gcAllocate( sizeof( sfVertexBuffer * ), &s_gcSfVertexBufferFuncs );

   *ppSfVertexBuffer = pSfVertexBuffer;
   return hb_itemPutPtrGC( pItem, ppSfVertexBuffer );
}

sfVertexBuffer * hb_sfVertexBuffer_param( int iParam )
{
   sfVertexBuffer ** ppSfVertexBuffer = ( sfVertexBuffer ** ) hb_parptrGC( &s_gcSfVertexBufferFuncs, iParam );

   if( ppSfVertexBuffer && *ppSfVertexBuffer )
   {
      return *ppSfVertexBuffer;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      return NULL;
   }
}

void hb_sfVertexBuffer_ret( sfVertexBuffer * pSfVertexBuffer )
{
   hb_sfVertexBufferItemPut( hb_stackReturnItem(), pSfVertexBuffer );
}

// sfVertexBuffer* sfVertexBuffer_create(unsigned int vertexCount, sfPrimitiveType type, sfVertexBufferUsage usage);

// sfVertexBuffer* sfVertexBuffer_copy(const sfVertexBuffer* vertexBuffer);

// void sfVertexBuffer_destroy(sfVertexBuffer* vertexBuffer);
HB_FUNC( SFVERTEXBUFFER_DESTROY )
{
   sfVertexBuffer ** ppSfVertexBuffer = ( sfVertexBuffer ** ) hb_parptrGC( &s_gcSfVertexBufferFuncs, 1 );

   if( ppSfVertexBuffer && *ppSfVertexBuffer )
   {
      sfVertexBuffer_destroy( *ppSfVertexBuffer );
      *ppSfVertexBuffer = NULL;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// unsigned int sfVertexBuffer_getVertexCount(const sfVertexBuffer* vertexBuffer);

// sfBool sfVertexBuffer_update(sfVertexBuffer* vertexBuffer, const sfVertex* vertices, unsigned int vertexCount, unsigned int offset);

// sfBool sfVertexBuffer_updateFromVertexBuffer(sfVertexBuffer* vertexBuffer, const sfVertexBuffer* other);

// void sfVertexBuffer_swap(sfVertexBuffer* left, sfVertexBuffer* right);

// unsigned int sfVertexBuffer_getNativeHandle(sfVertexBuffer* vertexBuffer);

// void sfVertexBuffer_setPrimitiveType(sfVertexBuffer* vertexBuffer, sfPrimitiveType type);

// sfPrimitiveType sfVertexBuffer_getPrimitiveType(const sfVertexBuffer* vertexBuffer);

// void sfVertexBuffer_setUsage(sfVertexBuffer* vertexBuffer, sfVertexBufferUsage usage);

// sfVertexBufferUsage sfVertexBuffer_getUsage(const sfVertexBuffer* vertexBuffer);

// void sfVertexBuffer_bind(const sfVertexBuffer* vertexBuffer);

// sfBool sfVertexBuffer_isAvailable();
