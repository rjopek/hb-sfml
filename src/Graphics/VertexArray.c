/*
 * SFML library: VertexArray.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

/* Graphics/sfVertexArray */
static HB_GARBAGE_FUNC( hb_sfVertexArray_destructor )
{
   sfVertexArray ** ppSfVertexArray = ( sfVertexArray ** ) Cargo;

   if( *ppSfVertexArray )
   {
      sfVertexArray_destroy( *ppSfVertexArray );
      *ppSfVertexArray = NULL;
   }
}

static const HB_GC_FUNCS s_gcSfVertexArrayFuncs =
{
   hb_sfVertexArray_destructor,
   hb_gcDummyMark
};

sfVertexArray * hb_sfVertexArrayItemGet( PHB_ITEM pItem )
{
   sfVertexArray ** ppSfVertexArray = ( sfVertexArray ** ) hb_itemGetPtrGC( pItem, &s_gcSfVertexArrayFuncs );

   return ppSfVertexArray ? *ppSfVertexArray : NULL;
}

PHB_ITEM hb_sfVertexArrayItemPut( PHB_ITEM pItem, sfVertexArray * pSfVertexArray )
{
   sfVertexArray ** ppSfVertexArray = ( sfVertexArray ** ) hb_gcAllocate( sizeof( sfVertexArray * ), &s_gcSfVertexArrayFuncs );

   *ppSfVertexArray = pSfVertexArray;
   return hb_itemPutPtrGC( pItem, ppSfVertexArray );
}

sfVertexArray * hb_sfVertexArray_param( int iParam )
{
   sfVertexArray ** ppSfVertexArray = ( sfVertexArray ** ) hb_parptrGC( &s_gcSfVertexArrayFuncs, iParam );

   if( ppSfVertexArray && *ppSfVertexArray )
   {
      return *ppSfVertexArray;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      return NULL;
   }
}

void hb_sfVertexArray_ret( sfVertexArray * pSfVertexArray )
{
   hb_sfVertexArrayItemPut( hb_stackReturnItem(), pSfVertexArray );
}

// sfVertexArray* sfVertexArray_create(void);

// sfVertexArray* sfVertexArray_copy(const sfVertexArray* vertexArray);

// void sfVertexArray_destroy(sfVertexArray* vertexArray);
HB_FUNC( SFVERTEXARRAY_DESTROY )
{
   sfVertexArray ** ppSfVertexArray = ( sfVertexArray ** ) hb_parptrGC( &s_gcSfVertexArrayFuncs, 1 );

   if( ppSfVertexArray && *ppSfVertexArray )
   {
      sfVertexArray_destroy( *ppSfVertexArray );
      *ppSfVertexArray = NULL;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// size_t sfVertexArray_getVertexCount(const sfVertexArray* vertexArray);

// sfVertex* sfVertexArray_getVertex(sfVertexArray* vertexArray, size_t index);

// void sfVertexArray_clear(sfVertexArray* vertexArray);

// void sfVertexArray_resize(sfVertexArray* vertexArray, size_t vertexCount);

// void sfVertexArray_append(sfVertexArray* vertexArray, sfVertex vertex);

// void sfVertexArray_setPrimitiveType(sfVertexArray* vertexArray, sfPrimitiveType type);

// sfPrimitiveType sfVertexArray_getPrimitiveType(sfVertexArray* vertexArray);

// sfFloatRect sfVertexArray_getBounds(sfVertexArray* vertexArray);
