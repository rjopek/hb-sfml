/*
 * SFML library: Texture.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

/* Graphics/sfTexture */
static HB_GARBAGE_FUNC( hb_sfTexture_destructor )
{
   sfTexture ** ppSfTexture = ( sfTexture ** ) Cargo;

   if( *ppSfTexture )
   {
      sfTexture_destroy( *ppSfTexture );
      *ppSfTexture = NULL;
   }
}

static const HB_GC_FUNCS s_gcSfTextureFuncs =
{
   hb_sfTexture_destructor,
   hb_gcDummyMark
};

sfTexture * hb_sfTextureItemGet( PHB_ITEM pItem )
{
   sfTexture ** ppSfTexture = ( sfTexture ** ) hb_itemGetPtrGC( pItem, &s_gcSfTextureFuncs );

   return ppSfTexture ? *ppSfTexture : NULL;
}

PHB_ITEM hb_sfTextureItemPut( PHB_ITEM pItem, sfTexture * pSfTexture )
{
   sfTexture ** ppSfTexture = ( sfTexture ** ) hb_gcAllocate( sizeof( sfTexture * ), &s_gcSfTextureFuncs );

   *ppSfTexture = pSfTexture;
   return hb_itemPutPtrGC( pItem, ppSfTexture );
}

sfTexture * hb_sfTexture_param( int iParam )
{
   sfTexture ** ppSfTexture = ( sfTexture ** ) hb_parptrGC( &s_gcSfTextureFuncs, iParam );

   if( ppSfTexture && *ppSfTexture )
   {
      return *ppSfTexture;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      return NULL;
   }
}

void hb_sfTexture_ret( sfTexture * pSfTexture )
{
   hb_sfTextureItemPut( hb_stackReturnItem(), pSfTexture );
}

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
HB_FUNC( SFTEXTURE_DESTROY )
{
   sfTexture ** ppSfTexture = ( sfTexture ** ) hb_parptrGC( &s_gcSfTextureFuncs, 1 );

   if( ppSfTexture && *ppSfTexture )
   {
      sfTexture_destroy( *ppSfTexture );
      *ppSfTexture = NULL;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

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
