/*
 * SFML library: VideoMode.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

// sfVideoMode sfVideoMode_getDesktopMode(void);
HB_FUNC( SFVIDEOMODE_GETDESKTOPMODE )
{
   sfVideoMode sfvideomode = sfVideoMode_getDesktopMode();

   PHB_ITEM info = hb_itemArrayNew( 5 );

   hb_arraySetNI( info, 1, ( unsigned int ) sfvideomode.width );
   hb_arraySetNI( info, 2, ( unsigned int ) sfvideomode.height );
   hb_arraySetNI( info, 3, ( unsigned int ) sfvideomode.bitsPerPixel );

   hb_itemReturnRelease( info );
}

// const sfVideoMode* sfVideoMode_getFullscreenModes(size_t* count);

// sfBool sfVideoMode_isValid(sfVideoMode mode);
HB_FUNC( sfVideoMode_isValid )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 3 )
   {
      sfVideoMode mode;

      mode.width        = ( unsigned int ) hb_arrayGetNI( pItem, 1 );
      mode.height       = ( unsigned int ) hb_arrayGetNI( pItem, 2 );
      mode.bitsPerPixel = ( unsigned int ) hb_arrayGetNI( pItem, 3 );

      hb_retl( sfVideoMode_isValid( mode ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}
