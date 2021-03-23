/*
 * SFML library: Window.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

// sfWindow* sfWindow_create(sfVideoMode mode, const char* title, sfUint32 style, const sfContextSettings* settings);
HB_FUNC( CREATE )
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
HB_FUNC( CREATEUNICODE )
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

      const sfUint32 title;
      hb_sfWindow_ret( sfWindow_createUnicode( mode, &title, ( unsigned int ) hb_parni( 3 ), &settings  ) );
      hb_storni( title, 2 );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

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
HB_FUNC( getSize )
{
   const sfWindow* window = hb_sfWindow_param( 1 );

   if( window )
   {
      sfVector2u sfvector2u = sfWindow_getSize( window );

      PHB_ITEM info = hb_itemArrayNew( 2 );

      hb_arraySetNI( info, 1, ( unsigned int) sfvector2u.x );
      hb_arraySetNI( info, 2, ( unsigned int ) sfvector2u.y );

      hb_itemReturnRelease( info );

   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfWindow_setSize(sfWindow* window, sfVector2u size);
HB_FUNC( SETSIZE )
{
   PHB_ITEM pItem;

   sfWindow* window = hb_sfWindow_param( 1 );

   if( window && ( pItem = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 2 )
   {
      sfVector2u size;

      size.x = ( unsigned int ) hb_arrayGetNI( pItem, 1 );
      size.y = ( unsigned int ) hb_arrayGetNI( pItem, 2 );

      sfWindow_setSize( window, size );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfWindow_setTitle(sfWindow* window, const char* title);
HB_FUNC( SETTITLE )
{
   sfWindow* window = hb_sfWindow_param( 1 );

   if( window && hb_param( 2, HB_IT_STRING ) != NULL )
   {
      sfWindow_setTitle( window, hb_parc( 2 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfWindow_setUnicodeTitle(sfWindow* window, const sfUint32* title);
HB_FUNC( SETUNICODETITLE )
{
   sfWindow* window = hb_sfWindow_param( 1 );

   if( window && hb_param( 2, HB_IT_INTEGER ) != NULL )
   {
      const sfUint32 title;
      sfWindow_setUnicodeTitle( window, &title );
      hb_storni( title, 2 );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfWindow_setIcon(sfWindow* window, unsigned int width, unsigned int height, const sfUint8* pixels);
HB_FUNC( SETICON )
{
   sfWindow* window = hb_sfWindow_param( 1 );

   if( window &&
      hb_param( 2, HB_IT_INTEGER ) != NULL &&
      hb_param( 3, HB_IT_INTEGER ) != NULL &&
      hb_param( 4, HB_IT_INTEGER ) != NULL )
   {
      const sfUint8 pixels;
      sfWindow_setIcon( window, ( unsigned int ) hb_parni( 2 ), ( unsigned int ) hb_parni( 3 ), &pixels );
      hb_storni( pixels, 4 );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfWindow_setVisible(sfWindow* window, sfBool visible);
HB_FUNC( SETVISIBLE )
{
   sfWindow* window = hb_sfWindow_param( 1 );

   if( window && hb_param( 2, HB_IT_LOGICAL ) != NULL )
   {
      sfWindow_setVisible( window, hb_parl( 2 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfWindow_setVerticalSyncEnabled(sfWindow* window, sfBool enabled);
HB_FUNC( SETVERTICALSYNCENABLED )
{
   sfWindow* window = hb_sfWindow_param( 1 );

   if( window && hb_param( 2, HB_IT_LOGICAL ) != NULL )
   {
      sfWindow_setVerticalSyncEnabled( window, hb_parl( 2 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfWindow_setMouseCursorVisible(sfWindow* window, sfBool visible);
HB_FUNC( SETMOUSECURSORVISIBLE )
{
   sfWindow* window = hb_sfWindow_param( 1 );

   if( window && hb_param( 2, HB_IT_LOGICAL ) != NULL )
   {
      sfWindow_setMouseCursorVisible( window, hb_parl( 2 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfWindow_setMouseCursorGrabbed(sfWindow* window, sfBool grabbed);
HB_FUNC( SETMOUSECURSORGRABBED )
{
   sfWindow* window = hb_sfWindow_param( 1 );

   if( window && hb_param( 2, HB_IT_LOGICAL ) != NULL )
   {
      sfWindow_setMouseCursorGrabbed( window, hb_parl( 2 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfWindow_setMouseCursor(sfWindow* window, const sfCursor* cursor);

// void sfWindow_setKeyRepeatEnabled(sfWindow* window, sfBool enabled);
HB_FUNC( SETKEYREPEATENABLED )
{
   sfWindow* window = hb_sfWindow_param( 1 );

   if( window && hb_param( 2, HB_IT_LOGICAL ) != NULL )
   {
      sfWindow_setKeyRepeatEnabled( window, hb_parl( 2 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfWindow_setFramerateLimit(sfWindow* window, unsigned int limit);
HB_FUNC( SETFRAMERATELIMIT )
{
   sfWindow* window = hb_sfWindow_param( 1 );

   if( window && hb_param( 2, HB_IT_INTEGER ) != NULL )
   {
      sfWindow_setFramerateLimit( window, ( unsigned int ) hb_parni( 2 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfWindow_setJoystickThreshold(sfWindow* window, float threshold);
HB_FUNC( SETJOYSTICKTHRESHOLD )
{
   sfWindow* window = hb_sfWindow_param( 1 );

   if( window && hb_param( 2, HB_IT_NUMERIC ) != NULL )
   {
      sfWindow_setJoystickThreshold( window, ( float ) hb_parnd( 2 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfBool sfWindow_setActive(sfWindow* window, sfBool active);
HB_FUNC( SETACTIVE )
{
   sfWindow* window = hb_sfWindow_param( 1 );

   if( window && hb_param( 2, HB_IT_LOGICAL ) != NULL )
   {
      hb_retl( sfWindow_setActive( window, hb_parl( 2 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfWindow_requestFocus(sfWindow* window);
HB_FUNC( REQUESTFOCUS )
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
HB_FUNC( HASFOCUS )
{
   const sfWindow* window = hb_sfWindow_param( 1 );

   if( window )
   {
      hb_retl( sfWindow_hasFocus( window ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfWindow_display(sfWindow* window);
HB_FUNC( DISPLAY )
{
   sfWindow* window = hb_sfWindow_param( 1 );

   if( window )
   {
      sfWindow_display( window );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfWindowHandle sfWindow_getSystemHandle(const sfWindow* window);
