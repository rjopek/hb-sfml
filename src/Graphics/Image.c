/*
 * SFML library: Image.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

/* Graphics/sfImage */
static HB_GARBAGE_FUNC( hb_sfImage_destructor )
{
   sfImage ** ppSfImage = ( sfImage ** ) Cargo;

   if( *ppSfImage )
   {
      sfImage_destroy( *ppSfImage );
      *ppSfImage = NULL;
   }
}

static const HB_GC_FUNCS s_gcSfImageFuncs =
{
   hb_sfImage_destructor,
   hb_gcDummyMark
};

sfImage * hb_sfImageItemGet( PHB_ITEM pItem )
{
   sfImage ** ppSfImage = ( sfImage ** ) hb_itemGetPtrGC( pItem, &s_gcSfImageFuncs );

   return ppSfImage ? *ppSfImage : NULL;
}

PHB_ITEM hb_sfImageItemPut( PHB_ITEM pItem, sfImage * pSfImage )
{
   sfImage ** ppSfImage = ( sfImage ** ) hb_gcAllocate( sizeof( sfImage * ), &s_gcSfImageFuncs );

   *ppSfImage = pSfImage;
   return hb_itemPutPtrGC( pItem, ppSfImage );
}

sfImage * hb_sfImage_param( int iParam )
{
   sfImage ** ppSfImage = ( sfImage ** ) hb_parptrGC( &s_gcSfImageFuncs, iParam );

   if( ppSfImage && *ppSfImage )
   {
      return *ppSfImage;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      return NULL;
   }
}

void hb_sfImage_ret( sfImage * pSfImage )
{
   hb_sfImageItemPut( hb_stackReturnItem(), pSfImage );
}

// sfImage* sfImage_create(unsigned int width, unsigned int height);

// sfImage* sfImage_createFromColor(unsigned int width, unsigned int height, sfColor color);

// sfImage* sfImage_createFromPixels(unsigned int width, unsigned int height, const sfUint8* pixels);

// sfImage* sfImage_createFromFile(const char* filename);

// sfImage* sfImage_createFromMemory(const void* data, size_t size);

// sfImage* sfImage_createFromStream(sfInputStream* stream);

// sfImage* sfImage_copy(const sfImage* image);

// void sfImage_destroy(sfImage* image);
HB_FUNC( SFIMAGE_DESTROY )
{
   sfImage ** ppSfImage = ( sfImage ** ) hb_parptrGC( &s_gcSfImageFuncs, 1 );

   if( ppSfImage && *ppSfImage )
   {
      sfImage_destroy( *ppSfImage );
      *ppSfImage = NULL;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfBool sfImage_saveToFile(const sfImage* image, const char* filename);

// sfVector2u sfImage_getSize(const sfImage* image);

// void sfImage_createMaskFromColor(sfImage* image, sfColor color, sfUint8 alpha);

// void sfImage_copyImage(sfImage* image, const sfImage* source, unsigned int destX, unsigned int destY, sfIntRect sourceRect, sfBool applyAlpha);

// void sfImage_setPixel(sfImage* image, unsigned int x, unsigned int y, sfColor color);

// sfColor sfImage_getPixel(const sfImage* image, unsigned int x, unsigned int y);

// const sfUint8* sfImage_getPixelsPtr(const sfImage* image);

// void sfImage_flipHorizontally(sfImage* image);

// void sfImage_flipVertically(sfImage* image);
