/*
 * SFML library: Window.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

// sfWindow* sfWindow_create(sfVideoMode mode, const char* title, sfUint32 style, const sfContextSettings* settings);
HB_FUNC( SFWINDOW_CREATE )
{
   PHB_ITEM pItem1, pItem2;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 3 &&
                  hb_param( 2, HB_IT_STRING )  != NULL &&
                  hb_param( 3, HB_IT_INTEGER ) != NULL &&
       ( pItem2 = hb_param( 4, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 7 )
   {
      sfVideoMode mode;

      mode.width        = ( unsigned int ) hb_arrayGetNI( pItem1, 1 );
      mode.height       = ( unsigned int ) hb_arrayGetNI( pItem1, 2 );
      mode.bitsPerPixel = ( unsigned int ) hb_arrayGetNI( pItem1, 3 );

      sfContextSettings settings;

      settings.depthBits         = ( unsigned int ) hb_arrayGetNI( pItem2, 1 );
      settings.stencilBits       = ( unsigned int ) hb_arrayGetNI( pItem2, 2 );
      settings.antialiasingLevel = ( unsigned int ) hb_arrayGetNI( pItem2, 3 );
      settings.majorVersion      = ( unsigned int ) hb_arrayGetNI( pItem2, 4 );
      settings.minorVersion      = ( unsigned int ) hb_arrayGetNI( pItem2, 5 );
      settings.attributeFlags    = ( unsigned int ) hb_arrayGetNI( pItem2, 6 );
      settings.sRgbCapable       =                  hb_arrayGetL( pItem2, 7 );

      hb_sfWindow_ret( sfWindow_create( mode, hb_parc( 2 ), ( unsigned int ) hb_parni( 3 ), &settings  ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfWindow* sfWindow_createUnicode(sfVideoMode mode, const sfUint32* title, sfUint32 style, const sfContextSettings* settings);

// sfWindow* sfWindow_createFromHandle(sfWindowHandle handle, const sfContextSettings* settings);

// void sfWindow_destroy(sfWindow* window);

// void sfWindow_close(sfWindow* window);

// sfBool sfWindow_isOpen(const sfWindow* window);

// sfContextSettings sfWindow_getSettings(const sfWindow* window);

// sfBool sfWindow_pollEvent(sfWindow* window, sfEvent* event);

// sfBool sfWindow_waitEvent(sfWindow* window, sfEvent* event);

// sfVector2i sfWindow_getPosition(const sfWindow* window);

// void sfWindow_setPosition(sfWindow* window, sfVector2i position);

// sfVector2u sfWindow_getSize(const sfWindow* window);

// void sfWindow_setSize(sfWindow* window, sfVector2u size);

// void sfWindow_setTitle(sfWindow* window, const char* title);

// void sfWindow_setUnicodeTitle(sfWindow* window, const sfUint32* title);

// void sfWindow_setIcon(sfWindow* window, unsigned int width, unsigned int height, const sfUint8* pixels);

// void sfWindow_setVisible(sfWindow* window, sfBool visible);

// void sfWindow_setVerticalSyncEnabled(sfWindow* window, sfBool enabled);

// void sfWindow_setMouseCursorVisible(sfWindow* window, sfBool visible);

// void sfWindow_setMouseCursorGrabbed(sfWindow* window, sfBool grabbed);

// void sfWindow_setMouseCursor(sfWindow* window, const sfCursor* cursor);

// void sfWindow_setKeyRepeatEnabled(sfWindow* window, sfBool enabled);

// void sfWindow_setFramerateLimit(sfWindow* window, unsigned int limit);

// void sfWindow_setJoystickThreshold(sfWindow* window, float threshold);

// sfBool sfWindow_setActive(sfWindow* window, sfBool active);
HB_FUNC( SFWINDOW_SETACTIVE )
{
   sfWindow* window = hb_sfWindow_param( 1 );

   if( window && hb_param( 2, HB_IT_LOGICAL )  != NULL )
   {
      hb_retl( sfWindow_setActive( window, hb_parl( 2 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfWindow_requestFocus(sfWindow* window);
HB_FUNC( SFWINDOW_REQUESTFOCUS )
{
   sfWindow* window = hb_sfWindow_param( 1 );

   if( window )
   {
      sfWindow_requestFocus( window );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfBool sfWindow_hasFocus(const sfWindow* window);

// void sfWindow_display(sfWindow* window);

// sfWindowHandle sfWindow_getSystemHandle(const sfWindow* window);
