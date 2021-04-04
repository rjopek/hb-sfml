/*
 * SFML library: RectangleShape.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

/* Graphics/sfRectangleShape */
static HB_GARBAGE_FUNC( hb_sfRectangleShape_destructor )
{
   sfRectangleShape ** ppSfRectangleShape = ( sfRectangleShape ** ) Cargo;

   if( *ppSfRectangleShape )
   {
      sfRectangleShape_destroy( *ppSfRectangleShape );
      *ppSfRectangleShape = NULL;
   }
}

static const HB_GC_FUNCS s_gcSfRectangleShapeFuncs =
{
   hb_sfRectangleShape_destructor,
   hb_gcDummyMark
};

sfRectangleShape * hb_sfRectangleShapeItemGet( PHB_ITEM pItem )
{
   sfRectangleShape ** ppSfRectangleShape = ( sfRectangleShape ** ) hb_itemGetPtrGC( pItem, &s_gcSfRectangleShapeFuncs );

   return ppSfRectangleShape ? *ppSfRectangleShape : NULL;
}

PHB_ITEM hb_sfRectangleShapeItemPut( PHB_ITEM pItem, sfRectangleShape * pSfRectangleShape )
{
   sfRectangleShape ** ppSfRectangleShape = ( sfRectangleShape ** ) hb_gcAllocate( sizeof( sfRectangleShape * ), &s_gcSfRectangleShapeFuncs );

   *ppSfRectangleShape = pSfRectangleShape;
   return hb_itemPutPtrGC( pItem, ppSfRectangleShape );
}

sfRectangleShape * hb_sfRectangleShape_param( int iParam )
{
   sfRectangleShape ** ppSfRectangleShape = ( sfRectangleShape ** ) hb_parptrGC( &s_gcSfRectangleShapeFuncs, iParam );

   if( ppSfRectangleShape && *ppSfRectangleShape )
   {
      return *ppSfRectangleShape;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      return NULL;
   }
}

void hb_sfRectangleShape_ret( sfRectangleShape * pSfRectangleShape )
{
   hb_sfRectangleShapeItemPut( hb_stackReturnItem(), pSfRectangleShape );
}

// sfRectangleShape* sfRectangleShape_create(void);

// sfRectangleShape* sfRectangleShape_copy(const sfRectangleShape* shape);

// void sfRectangleShape_destroy(sfRectangleShape* shape);
HB_FUNC( SFRECTANGLESHAPE_DESTROY )
{
   sfRectangleShape ** ppSfRectangleShape = ( sfRectangleShape ** ) hb_parptrGC( &s_gcSfRectangleShapeFuncs, 1 );

   if( ppSfRectangleShape && *ppSfRectangleShape )
   {
      sfRectangleShape_destroy( *ppSfRectangleShape );
      *ppSfRectangleShape = NULL;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfRectangleShape_setPosition(sfRectangleShape* shape, sfVector2f position);

// void sfRectangleShape_setRotation(sfRectangleShape* shape, float angle);

// void sfRectangleShape_setScale(sfRectangleShape* shape, sfVector2f scale);

// void sfRectangleShape_setOrigin(sfRectangleShape* shape, sfVector2f origin);

// sfVector2f sfRectangleShape_getPosition(const sfRectangleShape* shape);

// float sfRectangleShape_getRotation(const sfRectangleShape* shape);

// sfVector2f sfRectangleShape_getScale(const sfRectangleShape* shape);

// sfVector2f sfRectangleShape_getOrigin(const sfRectangleShape* shape);

// void sfRectangleShape_move(sfRectangleShape* shape, sfVector2f offset);

// void sfRectangleShape_rotate(sfRectangleShape* shape, float angle);

// void sfRectangleShape_scale(sfRectangleShape* shape, sfVector2f factors);

// sfTransform sfRectangleShape_getTransform(const sfRectangleShape* shape);

// sfTransform sfRectangleShape_getInverseTransform(const sfRectangleShape* shape);

// void sfRectangleShape_setTexture(sfRectangleShape* shape, const sfTexture* texture, sfBool resetRect);

// void sfRectangleShape_setTextureRect(sfRectangleShape* shape, sfIntRect rect);

// void sfRectangleShape_setFillColor(sfRectangleShape* shape, sfColor color);

// void sfRectangleShape_setOutlineColor(sfRectangleShape* shape, sfColor color);

// void sfRectangleShape_setOutlineThickness(sfRectangleShape* shape, float thickness);

// const sfTexture* sfRectangleShape_getTexture(const sfRectangleShape* shape);

// sfIntRect sfRectangleShape_getTextureRect(const sfRectangleShape* shape);

// sfColor sfRectangleShape_getFillColor(const sfRectangleShape* shape);

// sfColor sfRectangleShape_getOutlineColor(const sfRectangleShape* shape);

// float sfRectangleShape_getOutlineThickness(const sfRectangleShape* shape);

// size_t sfRectangleShape_getPointCount(const sfRectangleShape* shape);

// sfVector2f sfRectangleShape_getPoint(const sfRectangleShape* shape, size_t index);

// void sfRectangleShape_setSize(sfRectangleShape* shape, sfVector2f size);

// sfVector2f sfRectangleShape_getSize(const sfRectangleShape* shape);

// sfFloatRect sfRectangleShape_getLocalBounds(const sfRectangleShape* shape);

// sfFloatRect sfRectangleShape_getGlobalBounds(const sfRectangleShape* shape);
