/*
 * SFML library: RenderTexture.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

/* Graphics/sfRenderTexture */
static HB_GARBAGE_FUNC( hb_sfRenderTexture_destructor )
{
   sfRenderTexture ** ppSfRenderTexture = ( sfRenderTexture ** ) Cargo;

   if( *ppSfRenderTexture )
   {
      sfRenderTexture_destroy( *ppSfRenderTexture );
      *ppSfRenderTexture = NULL;
   }
}

static const HB_GC_FUNCS s_gcSfRenderTextureFuncs =
{
   hb_sfRenderTexture_destructor,
   hb_gcDummyMark
};

sfRenderTexture * hb_sfRenderTextureItemGet( PHB_ITEM pItem )
{
   sfRenderTexture ** ppSfRenderTexture = ( sfRenderTexture ** ) hb_itemGetPtrGC( pItem, &s_gcSfRenderTextureFuncs );

   return ppSfRenderTexture ? *ppSfRenderTexture : NULL;
}

PHB_ITEM hb_sfRenderTextureItemPut( PHB_ITEM pItem, sfRenderTexture * pSfRenderTexture )
{
   sfRenderTexture ** ppSfRenderTexture = ( sfRenderTexture ** ) hb_gcAllocate( sizeof( sfRenderTexture * ), &s_gcSfRenderTextureFuncs );

   *ppSfRenderTexture = pSfRenderTexture;
   return hb_itemPutPtrGC( pItem, ppSfRenderTexture );
}

sfRenderTexture * hb_sfRenderTexture_param( int iParam )
{
   sfRenderTexture ** ppSfRenderTexture = ( sfRenderTexture ** ) hb_parptrGC( &s_gcSfRenderTextureFuncs, iParam );

   if( ppSfRenderTexture && *ppSfRenderTexture )
   {
      return *ppSfRenderTexture;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      return NULL;
   }
}

void hb_sfRenderTexture_ret( sfRenderTexture * pSfRenderTexture )
{
   hb_sfRenderTextureItemPut( hb_stackReturnItem(), pSfRenderTexture );
}

// sfRenderTexture* sfRenderTexture_create(unsigned int width, unsigned int height, sfBool depthBuffer);

// sfRenderTexture* sfRenderTexture_createWithSettings(unsigned int width, unsigned int height, sfContextSettings settings);

// void sfRenderTexture_destroy(sfRenderTexture* renderTexture);
HB_FUNC( SFRENDERTEXTURE_DESTROY )
{
   sfRenderTexture ** ppSfRenderTexture = ( sfRenderTexture ** ) hb_parptrGC( &s_gcSfRenderTextureFuncs, 1 );

   if( ppSfRenderTexture && *ppSfRenderTexture )
   {
      sfRenderTexture_destroy( *ppSfRenderTexture );
      *ppSfRenderTexture = NULL;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfVector2u sfRenderTexture_getSize(const sfRenderTexture* renderTexture);

// sfBool sfRenderTexture_setActive(sfRenderTexture* renderTexture, sfBool active);

// void sfRenderTexture_display(sfRenderTexture* renderTexture);

// void sfRenderTexture_clear(sfRenderTexture* renderTexture, sfColor color);

// void sfRenderTexture_setView(sfRenderTexture* renderTexture, const sfView* view);

// const sfView* sfRenderTexture_getView(const sfRenderTexture* renderTexture);

// const sfView* sfRenderTexture_getDefaultView(const sfRenderTexture* renderTexture);

// sfIntRect sfRenderTexture_getViewport(const sfRenderTexture* renderTexture, const sfView* view);

// sfVector2f sfRenderTexture_mapPixelToCoords(const sfRenderTexture* renderTexture, sfVector2i point, const sfView* view);

// sfVector2i sfRenderTexture_mapCoordsToPixel(const sfRenderTexture* renderTexture, sfVector2f point, const sfView* view);

// void sfRenderTexture_drawSprite(sfRenderTexture* renderTexture, const sfSprite* object, const sfRenderStates* states);

// void sfRenderTexture_drawText(sfRenderTexture* renderTexture, const sfText* object, const sfRenderStates* states);

// void sfRenderTexture_drawShape(sfRenderTexture* renderTexture, const sfShape* object, const sfRenderStates* states);

// void sfRenderTexture_drawCircleShape(sfRenderTexture* renderTexture, const sfCircleShape* object, const sfRenderStates* states);

// void sfRenderTexture_drawConvexShape(sfRenderTexture* renderTexture, const sfConvexShape* object, const sfRenderStates* states);

// void sfRenderTexture_drawRectangleShape(sfRenderTexture* renderTexture, const sfRectangleShape* object, const sfRenderStates* states);

// void sfRenderTexture_drawVertexArray(sfRenderTexture* renderTexture, const sfVertexArray* object, const sfRenderStates* states);

// void sfRenderTexture_drawVertexBuffer(sfRenderTexture* renderTexture, const sfVertexBuffer* object, const sfRenderStates* states);

// void sfRenderTexture_drawPrimitives(sfRenderTexture* renderTexture, const sfVertex* vertices, size_t vertexCount, sfPrimitiveType type, const sfRenderStates* states);

// void sfRenderTexture_pushGLStates(sfRenderTexture* renderTexture);

// void sfRenderTexture_popGLStates(sfRenderTexture* renderTexture);

// void sfRenderTexture_resetGLStates(sfRenderTexture* renderTexture);

// const sfTexture* sfRenderTexture_getTexture(const sfRenderTexture* renderTexture);

unsigned int sfRenderTexture_getMaximumAntialiasingLevel();

// void sfRenderTexture_setSmooth(sfRenderTexture* renderTexture, sfBool smooth);

// sfBool sfRenderTexture_isSmooth(const sfRenderTexture* renderTexture);

// void sfRenderTexture_setRepeated(sfRenderTexture* renderTexture, sfBool repeated);

// sfBool sfRenderTexture_isRepeated(const sfRenderTexture* renderTexture);

// sfBool sfRenderTexture_generateMipmap(sfRenderTexture* renderTexture);
