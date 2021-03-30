/*
 * SFML library: CircleShape.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

/* Graphics/sfCircleShape */
static HB_GARBAGE_FUNC( hb_sfCircleShape_destructor )
{
   sfCircleShape ** ppSfCircleShape = ( sfCircleShape ** ) Cargo;

   if( *ppSfCircleShape )
   {
      sfCircleShape_destroy( *ppSfCircleShape );
      *ppSfCircleShape = NULL;
   }
}

static const HB_GC_FUNCS s_gcSfCircleShapeFuncs =
{
   hb_sfCircleShape_destructor,
   hb_gcDummyMark
};

sfCircleShape * hb_sfCircleShapeItemGet( PHB_ITEM pItem )
{
   sfCircleShape ** ppSfCircleShape = ( sfCircleShape ** ) hb_itemGetPtrGC( pItem, &s_gcSfCircleShapeFuncs );

   return ppSfCircleShape ? *ppSfCircleShape : NULL;
}

PHB_ITEM hb_sfCircleShapeItemPut( PHB_ITEM pItem, sfCircleShape * pSfCircleShape )
{
   sfCircleShape ** ppSfCircleShape = ( sfCircleShape ** ) hb_gcAllocate( sizeof( sfCircleShape * ), &s_gcSfCircleShapeFuncs );

   *ppSfCircleShape = pSfCircleShape;
   return hb_itemPutPtrGC( pItem, ppSfCircleShape );
}

sfCircleShape * hb_sfCircleShape_param( int iParam )
{
   sfCircleShape ** ppSfCircleShape = ( sfCircleShape ** ) hb_parptrGC( &s_gcSfCircleShapeFuncs, iParam );

   if( ppSfCircleShape && *ppSfCircleShape )
   {
      return *ppSfCircleShape;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      return NULL;
   }
}

void hb_sfCircleShape_ret( sfCircleShape * pSfCircleShape )
{
   hb_sfCircleShapeItemPut( hb_stackReturnItem(), pSfCircleShape );
}

// sfCircleShape* sfCircleShape_create(void);

// sfCircleShape* sfCircleShape_copy(const sfCircleShape* shape);

// void sfCircleShape_destroy(sfCircleShape* shape);
HB_FUNC( SFCIRCLESHAPE_DESTROY )
{
   sfCircleShape ** ppSfCircleShape = ( sfCircleShape ** ) hb_parptrGC( &s_gcSfCircleShapeFuncs, 1 );

   if( ppSfCircleShape && *ppSfCircleShape )
   {
      sfCircleShape_destroy( *ppSfCircleShape );
      *ppSfCircleShape = NULL;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfCircleShape_setPosition(sfCircleShape* shape, sfVector2f position);

// void sfCircleShape_setRotation(sfCircleShape* shape, float angle);

// void sfCircleShape_setScale(sfCircleShape* shape, sfVector2f scale);

// void sfCircleShape_setOrigin(sfCircleShape* shape, sfVector2f origin);

// sfVector2f sfCircleShape_getPosition(const sfCircleShape* shape);

// float sfCircleShape_getRotation(const sfCircleShape* shape);

// sfVector2f sfCircleShape_getScale(const sfCircleShape* shape);

// sfVector2f sfCircleShape_getOrigin(const sfCircleShape* shape);

// void sfCircleShape_move(sfCircleShape* shape, sfVector2f offset);

// void sfCircleShape_rotate(sfCircleShape* shape, float angle);

// void sfCircleShape_scale(sfCircleShape* shape, sfVector2f factors);

// sfTransform sfCircleShape_getTransform(const sfCircleShape* shape);

// sfTransform sfCircleShape_getInverseTransform(const sfCircleShape* shape);

// void sfCircleShape_setTexture(sfCircleShape* shape, const sfTexture* texture, sfBool resetRect);

// void sfCircleShape_setTextureRect(sfCircleShape* shape, sfIntRect rect);

// void sfCircleShape_setFillColor(sfCircleShape* shape, sfColor color);

// void sfCircleShape_setOutlineColor(sfCircleShape* shape, sfColor color);

// void sfCircleShape_setOutlineThickness(sfCircleShape* shape, float thickness);

// const sfTexture* sfCircleShape_getTexture(const sfCircleShape* shape);

// sfIntRect sfCircleShape_getTextureRect(const sfCircleShape* shape);

// sfColor sfCircleShape_getFillColor(const sfCircleShape* shape);

// sfColor sfCircleShape_getOutlineColor(const sfCircleShape* shape);

// float sfCircleShape_getOutlineThickness(const sfCircleShape* shape);

// size_t sfCircleShape_getPointCount(const sfCircleShape* shape);

// sfVector2f sfCircleShape_getPoint(const sfCircleShape* shape, size_t index);

// void sfCircleShape_setRadius(sfCircleShape* shape, float radius);

// float sfCircleShape_getRadius(const sfCircleShape* shape);

// void sfCircleShape_setPointCount(sfCircleShape* shape, size_t count);

// sfFloatRect sfCircleShape_getLocalBounds(const sfCircleShape* shape);

// sfFloatRect sfCircleShape_getGlobalBounds(const sfCircleShape* shape);
