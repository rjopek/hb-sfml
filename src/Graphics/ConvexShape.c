/*
 * SFML library: ConvexShape.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

/* Graphics/sfConvexShape */
static HB_GARBAGE_FUNC( hb_sfConvexShape_destructor )
{
   sfConvexShape ** ppSfConvexShape = ( sfConvexShape ** ) Cargo;

   if( *ppSfConvexShape )
   {
      sfConvexShape_destroy( *ppSfConvexShape );
      *ppSfConvexShape = NULL;
   }
}

static const HB_GC_FUNCS s_gcSfConvexShapeFuncs =
{
   hb_sfConvexShape_destructor,
   hb_gcDummyMark
};

sfConvexShape * hb_sfConvexShapeItemGet( PHB_ITEM pItem )
{
   sfConvexShape ** ppSfConvexShape = ( sfConvexShape ** ) hb_itemGetPtrGC( pItem, &s_gcSfConvexShapeFuncs );

   return ppSfConvexShape ? *ppSfConvexShape : NULL;
}

PHB_ITEM hb_sfConvexShapeItemPut( PHB_ITEM pItem, sfConvexShape * pSfConvexShape )
{
   sfConvexShape ** ppSfConvexShape = ( sfConvexShape ** ) hb_gcAllocate( sizeof( sfConvexShape * ), &s_gcSfConvexShapeFuncs );

   *ppSfConvexShape = pSfConvexShape;
   return hb_itemPutPtrGC( pItem, ppSfConvexShape );
}

sfConvexShape * hb_sfConvexShape_param( int iParam )
{
   sfConvexShape ** ppSfConvexShape = ( sfConvexShape ** ) hb_parptrGC( &s_gcSfConvexShapeFuncs, iParam );

   if( ppSfConvexShape && *ppSfConvexShape )
   {
      return *ppSfConvexShape;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      return NULL;
   }
}

void hb_sfConvexShape_ret( sfConvexShape * pSfConvexShape )
{
   hb_sfConvexShapeItemPut( hb_stackReturnItem(), pSfConvexShape );
}

// sfConvexShape* sfConvexShape_create(void);

// sfConvexShape* sfConvexShape_copy(const sfConvexShape* shape);

// void sfConvexShape_destroy(sfConvexShape* shape);
HB_FUNC( SFCONVEXSHAPE_DESTROY )
{
   sfConvexShape ** ppSfConvexShape = ( sfConvexShape ** ) hb_parptrGC( &s_gcSfConvexShapeFuncs, 1 );

   if( ppSfConvexShape && *ppSfConvexShape )
   {
      sfConvexShape_destroy( *ppSfConvexShape );
      *ppSfConvexShape = NULL;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfConvexShape_setPosition(sfConvexShape* shape, sfVector2f position);

// void sfConvexShape_setRotation(sfConvexShape* shape, float angle);

// void sfConvexShape_setScale(sfConvexShape* shape, sfVector2f scale);

// void sfConvexShape_setOrigin(sfConvexShape* shape, sfVector2f origin);

// sfVector2f sfConvexShape_getPosition(const sfConvexShape* shape);

// float sfConvexShape_getRotation(const sfConvexShape* shape);

// sfVector2f sfConvexShape_getScale(const sfConvexShape* shape);

// sfVector2f sfConvexShape_getOrigin(const sfConvexShape* shape);

// void sfConvexShape_move(sfConvexShape* shape, sfVector2f offset);

// void sfConvexShape_rotate(sfConvexShape* shape, float angle);

// void sfConvexShape_scale(sfConvexShape* shape, sfVector2f factors);

// sfTransform sfConvexShape_getTransform(const sfConvexShape* shape);

// sfTransform sfConvexShape_getInverseTransform(const sfConvexShape* shape);

// void sfConvexShape_setTexture(sfConvexShape* shape, const sfTexture* texture, sfBool resetRect);

// void sfConvexShape_setTextureRect(sfConvexShape* shape, sfIntRect rect);

// void sfConvexShape_setFillColor(sfConvexShape* shape, sfColor color);

// void sfConvexShape_setOutlineColor(sfConvexShape* shape, sfColor color);

// void sfConvexShape_setOutlineThickness(sfConvexShape* shape, float thickness);

// const sfTexture* sfConvexShape_getTexture(const sfConvexShape* shape);

// sfIntRect sfConvexShape_getTextureRect(const sfConvexShape* shape);

// sfColor sfConvexShape_getFillColor(const sfConvexShape* shape);

// sfColor sfConvexShape_getOutlineColor(const sfConvexShape* shape);

// float sfConvexShape_getOutlineThickness(const sfConvexShape* shape);

// size_t sfConvexShape_getPointCount(const sfConvexShape* shape);

// sfVector2f sfConvexShape_getPoint(const sfConvexShape* shape, size_t index);

// void sfConvexShape_setPointCount(sfConvexShape* shape, size_t count);

// void sfConvexShape_setPoint(sfConvexShape* shape, size_t index, sfVector2f point);

// sfFloatRect sfConvexShape_getLocalBounds(const sfConvexShape* shape);

// sfFloatRect sfConvexShape_getGlobalBounds(const sfConvexShape* shape);
