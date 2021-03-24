/*
 * SFML library: Clipboard.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

// const char* sfClipboard_getString();
HB_FUNC( GETSTRING )
{
   hb_retc( sfClipboard_getString() );
}

// const sfUint32* sfClipboard_getUnicodeString();

// void sfClipboard_setString(const char* text);
HB_FUNC( SETSTRING )
{
   if( hb_param( 1, HB_IT_STRING ) != NULL )
   {
      sfClipboard_setString( hb_parc( 1 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfClipboard_setUnicodeString(const sfUint32* text);

