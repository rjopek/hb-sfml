/*
 * SFML library: Font.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

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

// void sfFont_destroy(sfFont* font);
/* This function is in the file core.c */

// sfGlyph sfFont_getGlyph(const sfFont* font, sfUint32 codePoint, unsigned int characterSize, sfBool bold, float outlineThickness);

// float sfFont_getKerning(const sfFont* font, sfUint32 first, sfUint32 second, unsigned int characterSize);

// float sfFont_getLineSpacing(const sfFont* font, unsigned int characterSize);

// float sfFont_getUnderlinePosition(const sfFont* font, unsigned int characterSize);

// float sfFont_getUnderlineThickness(const sfFont* font, unsigned int characterSize);

// const sfTexture* sfFont_getTexture(sfFont* font, unsigned int characterSize);

// sfFontInfo sfFont_getInfo(const sfFont* font);
