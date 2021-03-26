/*
 * SFML library: Texture.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

// sfTexture* sfTexture_create(unsigned int width, unsigned int height);

// sfTexture* sfTexture_createFromFile(const char* filename, const sfIntRect* area);
HB_FUNC( SFTEXTURE_CREATEFROMFILE )
{
   PHB_ITEM pItem;

   if( hb_param( 1, HB_IT_STRING )  != NULL && ( pItem = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 4 )
   {
      sfIntRect area;

      area.left   = hb_arrayGetNI( pItem, 1 );
      area.top    = hb_arrayGetNI( pItem, 2 );
      area.width  = hb_arrayGetNI( pItem, 3 );
      area.height = hb_arrayGetNI( pItem, 4 );

      hb_sfTexture_ret( sfTexture_createFromFile( hb_parc( 1 ), &area ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfTexture* sfTexture_createFromMemory(const void* data, size_t sizeInBytes, const sfIntRect* area);

// sfTexture* sfTexture_createFromStream(sfInputStream* stream, const sfIntRect* area);

// sfTexture* sfTexture_createFromImage(const sfImage* image, const sfIntRect* area);

// sfTexture* sfTexture_copy(const sfTexture* texture);

// void sfTexture_destroy(sfTexture* texture);
/* This function is in the file core.c */

// sfVector2u sfTexture_getSize(const sfTexture* texture);

// sfImage* sfTexture_copyToImage(const sfTexture* texture);

// void sfTexture_updateFromPixels(sfTexture* texture, const sfUint8* pixels, unsigned int width, unsigned int height, unsigned int x, unsigned int y);

// void sfTexture_updateFromTexture(sfTexture* destination, const sfTexture* source, unsigned int x, unsigned int y);

// void sfTexture_updateFromImage(sfTexture* texture, const sfImage* image, unsigned int x, unsigned int y);

// void sfTexture_updateFromWindow(sfTexture* texture, const sfWindow* window, unsigned int x, unsigned int y);

// void sfTexture_updateFromRenderWindow(sfTexture* texture, const sfRenderWindow* renderWindow, unsigned int x, unsigned int y);

// void sfTexture_setSmooth(sfTexture* texture, sfBool smooth);

// sfBool sfTexture_isSmooth(const sfTexture* texture);

// void sfTexture_setSrgb(sfTexture* texture, sfBool sRgb);

// sfBool sfTexture_isSrgb(const sfTexture* texture);

// void sfTexture_setRepeated(sfTexture* texture, sfBool repeated);

// sfBool sfTexture_isRepeated(const sfTexture* texture);

// sfBool sfTexture_generateMipmap(sfTexture* texture);

// void sfTexture_swap(sfTexture* left, sfTexture* right);

// unsigned int sfTexture_getNativeHandle(const sfTexture* texture);

// void sfTexture_bind(const sfTexture* texture);

// unsigned int sfTexture_getMaximumSize();
