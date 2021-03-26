/*
 * SFML library: core.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/* Audio/sfMusic */
static HB_GARBAGE_FUNC( hb_sfMusic_destructor )
{
   sfMusic ** ppSfMusic = ( sfMusic ** ) Cargo;

   if( *ppSfMusic )
   {
      sfMusic_destroy( *ppSfMusic );
      *ppSfMusic = NULL;
   }
}

static const HB_GC_FUNCS s_gcSfMusicFuncs =
{
   hb_sfMusic_destructor,
   hb_gcDummyMark
};

sfMusic * hb_sfMusicItemGet( PHB_ITEM pItem )
{
   sfMusic ** ppSfMusic = ( sfMusic ** ) hb_itemGetPtrGC( pItem, &s_gcSfMusicFuncs );

   return ppSfMusic ? *ppSfMusic : NULL;
}

PHB_ITEM hb_sfMusicItemPut( PHB_ITEM pItem, sfMusic * pSfMusic )
{
   sfMusic ** ppSfMusic = ( sfMusic ** ) hb_gcAllocate( sizeof( sfMusic * ), &s_gcSfMusicFuncs );

   *ppSfMusic = pSfMusic;
   return hb_itemPutPtrGC( pItem, ppSfMusic );
}

sfMusic * hb_sfMusic_param( int iParam )
{
   sfMusic ** ppSfMusic = ( sfMusic ** ) hb_parptrGC( &s_gcSfMusicFuncs, iParam );

   if( ppSfMusic && *ppSfMusic )
   {
      return *ppSfMusic;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      return NULL;
   }
}

void hb_sfMusic_ret( sfMusic * pSfMusic )
{
   hb_sfMusicItemPut( hb_stackReturnItem(), pSfMusic );
}

HB_FUNC( SFMUSIC_DESTROY )
{
   sfMusic ** ppSfMusic = ( sfMusic ** ) hb_parptrGC( &s_gcSfMusicFuncs, 1 );

   if( ppSfMusic && *ppSfMusic )
   {
      sfMusic_destroy( *ppSfMusic );
      *ppSfMusic = NULL;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/* Graphics/sfFont */
static HB_GARBAGE_FUNC( hb_sfFont_destructor )
{
   sfFont ** ppSfFont = ( sfFont ** ) Cargo;

   if( *ppSfFont )
   {
      sfFont_destroy( *ppSfFont );
      *ppSfFont = NULL;
   }
}

static const HB_GC_FUNCS s_gcSfFontFuncs =
{
   hb_sfFont_destructor,
   hb_gcDummyMark
};

sfFont * hb_sfFontItemGet( PHB_ITEM pItem )
{
   sfFont ** ppSfFont = ( sfFont ** ) hb_itemGetPtrGC( pItem, &s_gcSfFontFuncs );

   return ppSfFont ? *ppSfFont : NULL;
}

PHB_ITEM hb_sfFontItemPut( PHB_ITEM pItem, sfFont * pSfFont )
{
   sfFont ** ppSfFont = ( sfFont ** ) hb_gcAllocate( sizeof( sfFont * ), &s_gcSfFontFuncs );

   *ppSfFont = pSfFont;
   return hb_itemPutPtrGC( pItem, ppSfFont );
}

sfFont * hb_sfFont_param( int iParam )
{
   sfFont ** ppSfFont = ( sfFont ** ) hb_parptrGC( &s_gcSfFontFuncs, iParam );

   if( ppSfFont && *ppSfFont )
   {
      return *ppSfFont;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      return NULL;
   }
}

void hb_sfFont_ret( sfFont * pSfFont )
{
   hb_sfFontItemPut( hb_stackReturnItem(), pSfFont );
}

HB_FUNC( SFFONT_DESTROY )
{
   sfFont ** ppSfFont = ( sfFont ** ) hb_parptrGC( &s_gcSfFontFuncs, 1 );

   if( ppSfFont && *ppSfFont )
   {
      sfFont_destroy( *ppSfFont );
      *ppSfFont = NULL;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

/* Graphics/sfRenderWindow */
static HB_GARBAGE_FUNC( hb_sfRenderWindow_destructor )
{
   sfRenderWindow ** ppSfRenderWindow = ( sfRenderWindow ** ) Cargo;

   if( *ppSfRenderWindow )
   {
      sfRenderWindow_destroy( *ppSfRenderWindow );
      *ppSfRenderWindow = NULL;
   }
}

static const HB_GC_FUNCS s_gcSfRenderWindowFuncs =
{
   hb_sfRenderWindow_destructor,
   hb_gcDummyMark
};

sfRenderWindow * hb_sfRenderWindowItemGet( PHB_ITEM pItem )
{
   sfRenderWindow ** ppSfRenderWindow = ( sfRenderWindow ** ) hb_itemGetPtrGC( pItem, &s_gcSfRenderWindowFuncs );

   return ppSfRenderWindow ? *ppSfRenderWindow : NULL;
}

PHB_ITEM hb_sfRenderWindowItemPut( PHB_ITEM pItem, sfRenderWindow * pSfRenderWindow )
{
   sfRenderWindow ** ppSfRenderWindow = ( sfRenderWindow ** ) hb_gcAllocate( sizeof( sfRenderWindow * ), &s_gcSfRenderWindowFuncs );

   *ppSfRenderWindow = pSfRenderWindow;
   return hb_itemPutPtrGC( pItem, ppSfRenderWindow );
}

sfRenderWindow * hb_sfRenderWindow_param( int iParam )
{
   sfRenderWindow ** ppSfRenderWindow = ( sfRenderWindow ** ) hb_parptrGC( &s_gcSfRenderWindowFuncs, iParam );

   if( ppSfRenderWindow && *ppSfRenderWindow )
   {
      return *ppSfRenderWindow;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      return NULL;
   }
}

void hb_sfRenderWindow_ret( sfRenderWindow * pSfRenderWindow )
{
   hb_sfRenderWindowItemPut( hb_stackReturnItem(), pSfRenderWindow );
}

HB_FUNC( SFRENDERWINDOW_DESTROY )
{
   sfRenderWindow ** ppSfRenderWindow = ( sfRenderWindow ** ) hb_parptrGC( &s_gcSfRenderWindowFuncs, 1 );

   if( ppSfRenderWindow && *ppSfRenderWindow )
   {
      sfRenderWindow_destroy( *ppSfRenderWindow );
      *ppSfRenderWindow = NULL;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

/* Graphics/sfSprite */
static HB_GARBAGE_FUNC( hb_sfSprite_destructor )
{
   sfSprite ** ppSfSprite = ( sfSprite ** ) Cargo;

   if( *ppSfSprite )
   {
      sfSprite_destroy( *ppSfSprite );
      *ppSfSprite = NULL;
   }
}

static const HB_GC_FUNCS s_gcSfSpriteFuncs =
{
   hb_sfSprite_destructor,
   hb_gcDummyMark
};

sfSprite * hb_sfSpriteItemGet( PHB_ITEM pItem )
{
   sfSprite ** ppSfSprite = ( sfSprite ** ) hb_itemGetPtrGC( pItem, &s_gcSfSpriteFuncs );

   return ppSfSprite ? *ppSfSprite : NULL;
}

PHB_ITEM hb_sfSpriteItemPut( PHB_ITEM pItem, sfSprite * pSfSprite )
{
   sfSprite ** ppSfSprite = ( sfSprite ** ) hb_gcAllocate( sizeof( sfSprite * ), &s_gcSfSpriteFuncs );

   *ppSfSprite = pSfSprite;
   return hb_itemPutPtrGC( pItem, ppSfSprite );
}

sfSprite * hb_sfSprite_param( int iParam )
{
   sfSprite ** ppSfSprite = ( sfSprite ** ) hb_parptrGC( &s_gcSfSpriteFuncs, iParam );

   if( ppSfSprite && *ppSfSprite )
   {
      return *ppSfSprite;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      return NULL;
   }
}

void hb_sfSprite_ret( sfSprite * pSfSprite )
{
   hb_sfSpriteItemPut( hb_stackReturnItem(), pSfSprite );
}

HB_FUNC( SFSPRITE_DESTROY )
{
   sfSprite ** ppSfSprite = ( sfSprite ** ) hb_parptrGC( &s_gcSfSpriteFuncs, 1 );

   if( ppSfSprite && *ppSfSprite )
   {
      sfSprite_destroy( *ppSfSprite );
      *ppSfSprite = NULL;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

/* Graphics/sfText */
static HB_GARBAGE_FUNC( hb_sfText_destructor )
{
   sfText ** ppSfText = ( sfText ** ) Cargo;

   if( *ppSfText )
   {
      sfText_destroy( *ppSfText );
      *ppSfText = NULL;
   }
}

static const HB_GC_FUNCS s_gcSfTextFuncs =
{
   hb_sfText_destructor,
   hb_gcDummyMark
};

sfText * hb_sfTextItemGet( PHB_ITEM pItem )
{
   sfText ** ppSfText = ( sfText ** ) hb_itemGetPtrGC( pItem, &s_gcSfTextFuncs );

   return ppSfText ? *ppSfText : NULL;
}

PHB_ITEM hb_sfTextItemPut( PHB_ITEM pItem, sfText * pSfText )
{
   sfText ** ppSfText = ( sfText ** ) hb_gcAllocate( sizeof( sfText * ), &s_gcSfTextFuncs );

   *ppSfText = pSfText;
   return hb_itemPutPtrGC( pItem, ppSfText );
}

sfText * hb_sfText_param( int iParam )
{
   sfText ** ppSfText = ( sfText ** ) hb_parptrGC( &s_gcSfTextFuncs, iParam );

   if( ppSfText && *ppSfText )
   {
      return *ppSfText;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      return NULL;
   }
}

void hb_sfText_ret( sfText * pSfText )
{
   hb_sfTextItemPut( hb_stackReturnItem(), pSfText );
}

HB_FUNC( SFTEXT_DESTROY )
{
   sfText ** ppSfText = ( sfText ** ) hb_parptrGC( &s_gcSfTextFuncs, 1 );

   if( ppSfText && *ppSfText )
   {
      sfText_destroy( *ppSfText );
      *ppSfText = NULL;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

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

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/* Window/sfContext */
static HB_GARBAGE_FUNC( hb_sfContext_destructor )
{
   sfContext ** ppSfContext = ( sfContext ** ) Cargo;

   if( *ppSfContext )
   {
      sfContext_destroy( *ppSfContext );
      *ppSfContext = NULL;
   }
}

static const HB_GC_FUNCS s_gcSfContextFuncs =
{
   hb_sfContext_destructor,
   hb_gcDummyMark
};

sfContext * hb_sfContextItemGet( PHB_ITEM pItem )
{
   sfContext ** ppSfContext = ( sfContext ** ) hb_itemGetPtrGC( pItem, &s_gcSfContextFuncs );

   return ppSfContext ? *ppSfContext : NULL;
}

PHB_ITEM hb_sfContextItemPut( PHB_ITEM pItem, sfContext * pSfContext )
{
   sfContext ** ppSfContext = ( sfContext ** ) hb_gcAllocate( sizeof( sfContext * ), &s_gcSfContextFuncs );

   *ppSfContext = pSfContext;
   return hb_itemPutPtrGC( pItem, ppSfContext );
}

sfContext * hb_sfContext_param( int iParam )
{
   sfContext ** ppSfContext = ( sfContext ** ) hb_parptrGC( &s_gcSfContextFuncs, iParam );

   if( ppSfContext && *ppSfContext )
   {
      return *ppSfContext;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      return NULL;
   }
}

void hb_sfContext_ret( sfContext * pSfContext )
{
   hb_sfContextItemPut( hb_stackReturnItem(), pSfContext );
}

HB_FUNC( SFCONTEXT_DESTROY )
{
   sfContext ** ppSfContext = ( sfContext ** ) hb_parptrGC( &s_gcSfContextFuncs, 1 );

   if( ppSfContext && *ppSfContext )
   {
      sfContext_destroy( *ppSfContext );
      *ppSfContext = NULL;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

/* Window/sfWindow */
static HB_GARBAGE_FUNC( hb_sfWindow_destructor )
{
   sfWindow ** ppSfWindow = ( sfWindow ** ) Cargo;

   if( *ppSfWindow )
   {
      sfWindow_destroy( *ppSfWindow );
      *ppSfWindow = NULL;
   }
}

static const HB_GC_FUNCS s_gcSfWindowFuncs =
{
   hb_sfWindow_destructor,
   hb_gcDummyMark
};

sfWindow * hb_sfWindowItemGet( PHB_ITEM pItem )
{
   sfWindow ** ppSfWindow = ( sfWindow ** ) hb_itemGetPtrGC( pItem, &s_gcSfWindowFuncs );

   return ppSfWindow ? *ppSfWindow : NULL;
}

PHB_ITEM hb_sfWindowItemPut( PHB_ITEM pItem, sfWindow * pSfWindow )
{
   sfWindow ** ppSfWindow = ( sfWindow ** ) hb_gcAllocate( sizeof( sfWindow * ), &s_gcSfWindowFuncs );

   *ppSfWindow = pSfWindow;
   return hb_itemPutPtrGC( pItem, ppSfWindow );
}

sfWindow * hb_sfWindow_param( int iParam )
{
   sfWindow ** ppSfWindow = ( sfWindow ** ) hb_parptrGC( &s_gcSfWindowFuncs, iParam );

   if( ppSfWindow && *ppSfWindow )
   {
      return *ppSfWindow;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      return NULL;
   }
}

void hb_sfWindow_ret( sfWindow * pSfWindow )
{
   hb_sfWindowItemPut( hb_stackReturnItem(), pSfWindow );
}

HB_FUNC( SFWINDOW_DESTROY )
{
   sfWindow ** ppSfWindow = ( sfWindow ** ) hb_parptrGC( &s_gcSfWindowFuncs, 1 );

   if( ppSfWindow && *ppSfWindow )
   {
      sfWindow_destroy( *ppSfWindow );
      *ppSfWindow = NULL;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */