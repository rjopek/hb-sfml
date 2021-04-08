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
HB_FUNC( SFSHAPE_SETPOSITION )
{
   PHB_ITEM pItem;

   sfShape* shape = hb_sfShape_param( 1 );

   if( shape && ( pItem = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 2 )
   {
      sfVector2f position;

      position.x = ( float ) hb_arrayGetND( pItem, 1 );
      position.y = ( float ) hb_arrayGetND( pItem, 2 );

      sfShape_setPosition( shape, position );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfShape_setRotation(sfShape* shape, float angle);
HB_FUNC( SFSHAPE_SETROTATION )
{
   sfShape* shape = hb_sfShape_param( 1 );

   if( shape && hb_param( 2, HB_IT_NUMERIC ) != NULL )
   {
      sfShape_setRotation( shape, ( float ) hb_parnd( 2 ) );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfShape_setScale(sfShape* shape, sfVector2f scale);
HB_FUNC( SFSHAPE_SETSCALE )
{
   PHB_ITEM pItem;

   sfShape* shape = hb_sfShape_param( 1 );

   if( shape && ( pItem = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 2 )
   {
      sfVector2f scale;

      scale.x = ( float ) hb_arrayGetND( pItem, 1 );
      scale.y = ( float ) hb_arrayGetND( pItem, 2 );

      sfShape_setScale( shape, scale );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfShape_setOrigin(sfShape* shape, sfVector2f origin);
HB_FUNC( SFSHAPE_SETORIGIN )
{
   PHB_ITEM pItem;

   sfShape* shape = hb_sfShape_param( 1 );

   if( shape && ( pItem = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 2 )
   {
      sfVector2f origin;

      origin.x = ( float ) hb_arrayGetND( pItem, 1 );
      origin.y = ( float ) hb_arrayGetND( pItem, 2 );

      sfShape_setOrigin( shape, origin );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfVector2f sfShape_getPosition(const sfShape* shape);
HB_FUNC( SFSHAPE_GETPOSITION )
{

   const sfShape* shape = hb_sfShape_param( 1 );

   if( shape )
   {
      sfVector2f sfvector2f = sfShape_getPosition( shape );

      PHB_ITEM info = hb_itemArrayNew( 2 );

      hb_arraySetND( info, 1, ( float ) sfvector2f.x );
      hb_arraySetND( info, 2, ( float ) sfvector2f.y );

      hb_itemReturnRelease( info );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// float sfShape_getRotation(const sfShape* shape);
HB_FUNC( SFSHAPE_GETROTATION )
{

   const sfShape* shape = hb_sfShape_param( 1 );

   if( shape )
   {
      hb_retnd( ( float ) sfShape_getRotation( shape ) );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfVector2f sfShape_getScale(const sfShape* shape);
HB_FUNC( SFSHAPE_GETSCALE )
{

   const sfShape* shape = hb_sfShape_param( 1 );

   if( shape )
   {
      sfVector2f sfvector2f = sfShape_getScale( shape );

      PHB_ITEM info = hb_itemArrayNew( 2 );

      hb_arraySetND( info, 1, ( float ) sfvector2f.x );
      hb_arraySetND( info, 2, ( float ) sfvector2f.y );

      hb_itemReturnRelease( info );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfVector2f sfShape_getOrigin(const sfShape* shape);
HB_FUNC( SFSHAPE_GETORIGIN )
{

   const sfShape* shape = hb_sfShape_param( 1 );

   if( shape )
   {
      sfVector2f sfvector2f = sfShape_getOrigin( shape );

      PHB_ITEM info = hb_itemArrayNew( 2 );

      hb_arraySetND( info, 1, ( float ) sfvector2f.x );
      hb_arraySetND( info, 2, ( float ) sfvector2f.y );

      hb_itemReturnRelease( info );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfShape_move(sfShape* shape, sfVector2f offset);
HB_FUNC( SFSHAPE_MOVE )
{
   PHB_ITEM pItem;

   sfShape* shape = hb_sfShape_param( 1 );

   if( shape && ( pItem = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 2 )
   {
      sfVector2f offset;

      offset.x = ( float ) hb_arrayGetND( pItem, 1 );
      offset.y = ( float ) hb_arrayGetND( pItem, 2 );

      sfShape_move( shape, offset );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfShape_rotate(sfShape* shape, float angle);
HB_FUNC( SFSHAPE_ROTATE )
{
   sfShape* shape = hb_sfShape_param( 1 );

   if( shape && hb_param( 2, HB_IT_NUMERIC ) != NULL )
   {
      sfShape_setRotation( shape, ( float ) hb_parnd( 2 ) );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfShape_scale(sfShape* shape, sfVector2f factors);
HB_FUNC( SFSHAPE_SCALE )
{
   PHB_ITEM pItem;

   sfShape* shape = hb_sfShape_param( 1 );

   if( shape && ( pItem = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 2 )
   {
      sfVector2f factors;

      factors.x = ( float ) hb_arrayGetND( pItem, 1 );
      factors.y = ( float ) hb_arrayGetND( pItem, 2 );

      sfShape_scale( shape, factors );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfTransform sfShape_getTransform(const sfShape* shape);
HB_FUNC( SFSHAPE_GETTRANSFORM )
{
   const sfShape* shape = hb_sfShape_param( 1 );

   if( shape )
   {
      sfTransform sftransform = sfShape_getTransform( shape );

      PHB_ITEM info = hb_itemArrayNew( 9 );

      hb_arraySetND( info, 1, ( float ) sftransform.matrix[ 0 ] );
      hb_arraySetND( info, 2, ( float ) sftransform.matrix[ 1 ] );
      hb_arraySetND( info, 3, ( float ) sftransform.matrix[ 2 ] );
      hb_arraySetND( info, 4, ( float ) sftransform.matrix[ 3 ] );
      hb_arraySetND( info, 5, ( float ) sftransform.matrix[ 4 ] );
      hb_arraySetND( info, 6, ( float ) sftransform.matrix[ 5 ] );
      hb_arraySetND( info, 7, ( float ) sftransform.matrix[ 6 ] );
      hb_arraySetND( info, 8, ( float ) sftransform.matrix[ 7 ] );
      hb_arraySetND( info, 9, ( float ) sftransform.matrix[ 8 ] );

      hb_itemReturnRelease( info );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfTransform sfShape_getInverseTransform(const sfShape* shape);
HB_FUNC( SFSHAPE_GETINVERSETRANSFORM )
{
   const sfShape* shape = hb_sfShape_param( 1 );

   if( shape )
   {
      sfTransform sftransform = sfShape_getInverseTransform( shape );

      PHB_ITEM info = hb_itemArrayNew( 9 );

      hb_arraySetND( info, 1, ( float ) sftransform.matrix[ 0 ] );
      hb_arraySetND( info, 2, ( float ) sftransform.matrix[ 1 ] );
      hb_arraySetND( info, 3, ( float ) sftransform.matrix[ 2 ] );
      hb_arraySetND( info, 4, ( float ) sftransform.matrix[ 3 ] );
      hb_arraySetND( info, 5, ( float ) sftransform.matrix[ 4 ] );
      hb_arraySetND( info, 6, ( float ) sftransform.matrix[ 5 ] );
      hb_arraySetND( info, 7, ( float ) sftransform.matrix[ 6 ] );
      hb_arraySetND( info, 8, ( float ) sftransform.matrix[ 7 ] );
      hb_arraySetND( info, 9, ( float ) sftransform.matrix[ 8 ] );

      hb_itemReturnRelease( info );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfShape_setTexture(sfShape* shape, const sfTexture* texture, sfBool resetRect);
HB_FUNC( SFSHAPE_SETTEXTURE )
{
   sfShape* shape = hb_sfShape_param( 1 );
   const sfTexture* texture = hb_sfTexture_param( 2 );

   if( shape )
   {
      sfShape_setTexture( shape, texture, hb_parl( 3 ) );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfShape_setTextureRect(sfShape* shape, sfIntRect rect);
HB_FUNC( SFSHAPE_SETTEXTURERECT )
{
   PHB_ITEM pItem;

   sfShape* shape = hb_sfShape_param( 1 );

   if( shape && ( pItem = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 4 )
   {
      sfIntRect rect;

      rect.left   = hb_arrayGetNI( pItem, 1 );
      rect.top    = hb_arrayGetNI( pItem, 2 );
      rect.width  = hb_arrayGetNI( pItem, 3 );
      rect.height = hb_arrayGetNI( pItem, 4 );

      sfShape_setTextureRect( shape, rect );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfShape_setFillColor(sfShape* shape, sfColor color);
HB_FUNC( SFSHAPE_SETFILLCOLOR )
{
   PHB_ITEM pItem;

   sfShape* shape = hb_sfShape_param( 1 );

   if( shape && ( pItem = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 4 )
   {
      sfColor color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem, 4 );

      sfShape_setFillColor( shape, color );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfShape_setOutlineColor(sfShape* shape, sfColor color);
HB_FUNC( SFSHAPE_SETOUTLINECOLOR )
{
   PHB_ITEM pItem;

   sfShape* shape = hb_sfShape_param( 1 );

   if( shape && ( pItem = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 4 )
   {
      sfColor color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem, 4 );

      sfShape_setOutlineColor( shape, color );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfShape_setOutlineThickness(sfShape* shape, float thickness);
HB_FUNC( SFSHAPE_SETOUTLINETHICKNESS )
{
   sfShape* shape = hb_sfShape_param( 1 );

   if( shape && hb_param( 2, HB_IT_NUMERIC ) != NULL )
   {
      sfShape_setOutlineThickness( shape, ( float ) hb_parnd( 2 ) );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

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
