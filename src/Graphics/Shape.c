/*
 * SFML library: Shape.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

/* Graphics/sfShape */
static HB_GARBAGE_FUNC( hb_sfShape_destructor )
{
   sfShape ** ppSfShape = ( sfShape ** ) Cargo;

   if( *ppSfShape )
   {
      sfShape_destroy( *ppSfShape );
      *ppSfShape = NULL;
   }
}

static const HB_GC_FUNCS s_gcSfShapeFuncs =
{
   hb_sfShape_destructor,
   hb_gcDummyMark
};

sfShape * hb_sfShapeItemGet( PHB_ITEM pItem )
{
   sfShape ** ppSfShape = ( sfShape ** ) hb_itemGetPtrGC( pItem, &s_gcSfShapeFuncs );

   return ppSfShape ? *ppSfShape : NULL;
}

PHB_ITEM hb_sfShapeItemPut( PHB_ITEM pItem, sfShape * pSfShape )
{
   sfShape ** ppSfShape = ( sfShape ** ) hb_gcAllocate( sizeof( sfShape * ), &s_gcSfShapeFuncs );

   *ppSfShape = pSfShape;
   return hb_itemPutPtrGC( pItem, ppSfShape );
}

sfShape * hb_sfShape_param( int iParam )
{
   sfShape ** ppSfShape = ( sfShape ** ) hb_parptrGC( &s_gcSfShapeFuncs, iParam );

   if( ppSfShape && *ppSfShape )
   {
      return *ppSfShape;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      return NULL;
   }
}

void hb_sfShape_ret( sfShape * pSfShape )
{
   hb_sfShapeItemPut( hb_stackReturnItem(), pSfShape );
}

// typedef size_t (*sfShapeGetPointCountCallback)(void*);

// typedef sfVector2f (*sfShapeGetPointCallback)(size_t, void*);

// sfShape* sfShape_create(sfShapeGetPointCountCallback getPointCount, sfShapeGetPointCallback getPoint, void* userData);

// void sfShape_destroy(sfShape* shape);
HB_FUNC( SFSHAPE_DESTROY )
{
   sfShape ** ppSfShape = ( sfShape ** ) hb_parptrGC( &s_gcSfShapeFuncs, 1 );

   if( ppSfShape && *ppSfShape )
   {
      sfShape_destroy( *ppSfShape );
      *ppSfShape = NULL;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfShape_setPosition(sfShape* shape, sfVector2f position);

// void sfShape_setRotation(sfShape* shape, float angle);

// void sfShape_setScale(sfShape* shape, sfVector2f scale);

// void sfShape_setOrigin(sfShape* shape, sfVector2f origin);

// sfVector2f sfShape_getPosition(const sfShape* shape);

// float sfShape_getRotation(const sfShape* shape);

// sfVector2f sfShape_getScale(const sfShape* shape);

// sfVector2f sfShape_getOrigin(const sfShape* shape);

// void sfShape_move(sfShape* shape, sfVector2f offset);

// void sfShape_rotate(sfShape* shape, float angle);

// void sfShape_scale(sfShape* shape, sfVector2f factors);

// sfTransform sfShape_getTransform(const sfShape* shape);

// sfTransform sfShape_getInverseTransform(const sfShape* shape);

// void sfShape_setTexture(sfShape* shape, const sfTexture* texture, sfBool resetRect);

// void sfShape_setTextureRect(sfShape* shape, sfIntRect rect);

// void sfShape_setFillColor(sfShape* shape, sfColor color);

// void sfShape_setOutlineColor(sfShape* shape, sfColor color);

// void sfShape_setOutlineThickness(sfShape* shape, float thickness);

// const sfTexture* sfShape_getTexture(const sfShape* shape);

// sfIntRect sfShape_getTextureRect(const sfShape* shape);

// sfColor sfShape_getFillColor(const sfShape* shape);

// sfColor sfShape_getOutlineColor(const sfShape* shape);

// float sfShape_getOutlineThickness(const sfShape* shape);

// size_t sfShape_getPointCount(const sfShape* shape);

// sfVector2f sfShape_getPoint(const sfShape* shape, size_t index);

// sfFloatRect sfShape_getLocalBounds(const sfShape* shape);

// sfFloatRect sfShape_getGlobalBounds(const sfShape* shape);

// void sfShape_update(sfShape* shape);
