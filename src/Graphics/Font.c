/*
 * SFML library: Font.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

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

// sfFont* sfFont_createFromFile(const char* filename);
HB_FUNC( SFFONT_CREATEFROMFILE )
{
   if( hb_param( 1, HB_IT_STRING ) != NULL )
   {
      hb_sfFont_ret( sfFont_createFromFile( hb_parc( 1 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfFont* sfFont_createFromMemory(const void* data, size_t sizeInBytes);

// sfFont* sfFont_createFromStream(sfInputStream* stream);

// sfFont* sfFont_copy(const sfFont* font);
HB_FUNC( SFFONT_COPY )
{
   const sfFont* font = hb_sfFont_param( 1 );

   if( font )
   {
      hb_sfFont_ret( sfFont_copy( font ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfFont_destroy(sfFont* font);
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

// sfGlyph sfFont_getGlyph(const sfFont* font, sfUint32 codePoint, unsigned int characterSize, sfBool bold, float outlineThickness);

// float sfFont_getKerning(const sfFont* font, sfUint32 first, sfUint32 second, unsigned int characterSize);

// float sfFont_getLineSpacing(const sfFont* font, unsigned int characterSize);

// float sfFont_getUnderlinePosition(const sfFont* font, unsigned int characterSize);

// float sfFont_getUnderlineThickness(const sfFont* font, unsigned int characterSize);

// const sfTexture* sfFont_getTexture(sfFont* font, unsigned int characterSize);

// sfFontInfo sfFont_getInfo(const sfFont* font);
HB_FUNC( SFFONT_GETINFO )
{
   const sfFont* font = hb_sfFont_param( 1 );

   if( font )
   {
      sfFontInfo sffontinfo = sfFont_getInfo( font );

      PHB_ITEM info = hb_itemArrayNew( 1 );

      hb_arraySetC( info, 1, sffontinfo.family );

      hb_itemReturnRelease( info );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}
