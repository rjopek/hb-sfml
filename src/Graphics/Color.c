/*
 * SFML library: Color.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

/* Graphics/sfColor */

// sfColor sfColor_fromRGB(sfUint8 red, sfUint8 green, sfUint8 blue);
HB_FUNC( SFCOLOR_FROMRGB )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL &&
       hb_param( 2, HB_IT_INTEGER ) != NULL &&
       hb_param( 3, HB_IT_INTEGER ) != NULL )
   {
      sfColor sfcolor = sfColor_fromRGB( ( unsigned char ) hb_parni( 1 ), ( unsigned char ) hb_parni( 2 ), ( unsigned char ) hb_parni( 3 ) );

      PHB_ITEM info = hb_itemArrayNew( 4 );

      hb_arraySetNI( info, 1, ( unsigned char ) sfcolor.r );
      hb_arraySetNI( info, 2, ( unsigned char ) sfcolor.g );
      hb_arraySetNI( info, 3, ( unsigned char ) sfcolor.b );
      hb_arraySetNI( info, 4, ( unsigned char ) sfcolor.a );

      hb_itemReturnRelease( info );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfColor sfColor_fromRGBA(sfUint8 red, sfUint8 green, sfUint8 blue, sfUint8 alpha);
HB_FUNC( SFCOLOR_FROMRGBA )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL &&
       hb_param( 2, HB_IT_INTEGER ) != NULL &&
       hb_param( 3, HB_IT_INTEGER ) != NULL &&
       hb_param( 4, HB_IT_INTEGER ) != NULL )
   {
      sfColor sfcolor = sfColor_fromRGBA( ( unsigned char ) hb_parni( 1 ), ( unsigned char ) hb_parni( 2 ), ( unsigned char ) hb_parni( 3 ), ( unsigned char ) hb_parni( 4 ) );

      PHB_ITEM info = hb_itemArrayNew( 4 );

      hb_arraySetNI( info, 1, ( unsigned char ) sfcolor.r );
      hb_arraySetNI( info, 2, ( unsigned char ) sfcolor.g );
      hb_arraySetNI( info, 3, ( unsigned char ) sfcolor.b );
      hb_arraySetNI( info, 4, ( unsigned char ) sfcolor.a );

      hb_itemReturnRelease( info );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfColor sfColor_fromInteger(sfUint32 color);
HB_FUNC( SFCOLOR_FROMINTEGER )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL )
   {
      sfColor color = sfColor_fromInteger( ( unsigned int ) hb_parni( 1 ) );

      PHB_ITEM info = hb_itemArrayNew( 4 );

      hb_arraySetNI( info, 1, ( unsigned char ) color.r );
      hb_arraySetNI( info, 2, ( unsigned char ) color.g );
      hb_arraySetNI( info, 3, ( unsigned char ) color.b );
      hb_arraySetNI( info, 4, ( unsigned char ) color.a );

      hb_itemReturnRelease( info );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfUint32 sfColor_toInteger(sfColor color);
HB_FUNC( SFCOLOR_TOINTEGER )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 4 )
   {
      sfColor color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem, 4 );

      hb_retni( ( unsigned int ) sfColor_toInteger( color ) );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfColor sfColor_add(sfColor color1, sfColor color2);
HB_FUNC( SFCOLOR_ADD )
{
   PHB_ITEM pItem1, pItem2;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 4 &&
       ( pItem2 = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      sfColor color1;

      color1.r = ( unsigned char ) hb_arrayGetNI( pItem1, 1 );
      color1.g = ( unsigned char ) hb_arrayGetNI( pItem1, 2 );
      color1.b = ( unsigned char ) hb_arrayGetNI( pItem1, 3 );
      color1.a = ( unsigned char ) hb_arrayGetNI( pItem1, 4 );

      sfColor color2;

      color2.r = ( unsigned char ) hb_arrayGetNI( pItem2, 1 );
      color2.g = ( unsigned char ) hb_arrayGetNI( pItem2, 2 );
      color2.b = ( unsigned char ) hb_arrayGetNI( pItem2, 3 );
      color2.a = ( unsigned char ) hb_arrayGetNI( pItem2, 4 );

      sfColor color = sfColor_add( color1, color2 );

      PHB_ITEM info = hb_itemArrayNew( 4 );

      hb_arraySetNI( info, 1, ( unsigned char ) color.r );
      hb_arraySetNI( info, 2, ( unsigned char ) color.g );
      hb_arraySetNI( info, 3, ( unsigned char ) color.b );
      hb_arraySetNI( info, 4, ( unsigned char ) color.a );

      hb_itemReturnRelease( info );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfColor sfColor_subtract(sfColor color1, sfColor color2);
HB_FUNC( SFCOLOR_SUBTRACT )
{
   PHB_ITEM pItem1, pItem2;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 4 &&
       ( pItem2 = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      sfColor color1;

      color1.r = ( unsigned char ) hb_arrayGetNI( pItem1, 1 );
      color1.g = ( unsigned char ) hb_arrayGetNI( pItem1, 2 );
      color1.b = ( unsigned char ) hb_arrayGetNI( pItem1, 3 );
      color1.a = ( unsigned char ) hb_arrayGetNI( pItem1, 4 );

      sfColor color2;

      color2.r = ( unsigned char ) hb_arrayGetNI( pItem2, 1 );
      color2.g = ( unsigned char ) hb_arrayGetNI( pItem2, 2 );
      color2.b = ( unsigned char ) hb_arrayGetNI( pItem2, 3 );
      color2.a = ( unsigned char ) hb_arrayGetNI( pItem2, 4 );

      sfColor color = sfColor_subtract( color1, color2 );

      PHB_ITEM info = hb_itemArrayNew( 4 );

      hb_arraySetNI( info, 1, ( unsigned char ) color.r );
      hb_arraySetNI( info, 2, ( unsigned char ) color.g );
      hb_arraySetNI( info, 3, ( unsigned char ) color.b );
      hb_arraySetNI( info, 4, ( unsigned char ) color.a );

      hb_itemReturnRelease( info );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfColor sfColor_modulate(sfColor color1, sfColor color2);
HB_FUNC( SFCOLOR_MODULATE )
{
   PHB_ITEM pItem1, pItem2;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 4 &&
       ( pItem2 = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      sfColor color1;

      color1.r = ( unsigned char ) hb_arrayGetNI( pItem1, 1 );
      color1.g = ( unsigned char ) hb_arrayGetNI( pItem1, 2 );
      color1.b = ( unsigned char ) hb_arrayGetNI( pItem1, 3 );
      color1.a = ( unsigned char ) hb_arrayGetNI( pItem1, 4 );

      sfColor color2;

      color2.r = ( unsigned char ) hb_arrayGetNI( pItem2, 1 );
      color2.g = ( unsigned char ) hb_arrayGetNI( pItem2, 2 );
      color2.b = ( unsigned char ) hb_arrayGetNI( pItem2, 3 );
      color2.a = ( unsigned char ) hb_arrayGetNI( pItem2, 4 );

      sfColor color = sfColor_modulate( color1, color2 );

      PHB_ITEM info = hb_itemArrayNew( 4 );

      hb_arraySetNI( info, 1, ( unsigned char ) color.r );
      hb_arraySetNI( info, 2, ( unsigned char ) color.g );
      hb_arraySetNI( info, 3, ( unsigned char ) color.b );
      hb_arraySetNI( info, 4, ( unsigned char ) color.a );

      hb_itemReturnRelease( info );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}
