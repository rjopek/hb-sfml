/*
 * SFML library: Window.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

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
      settings.sRgbCapable       =                  hb_arrayGetL(  pItem2, 7 );

      hb_sfWindow_ret( sfWindow_create( mode, hb_parc( 2 ), ( unsigned int ) hb_parni( 3 ), &settings ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfWindow* sfWindow_createUnicode(sfVideoMode mode, const sfUint32* title, sfUint32 style, const sfContextSettings* settings);
HB_FUNC( SFWINDOW_CREATEUNICODE )
{
   PHB_ITEM pItem1, pItem2;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 3 &&
                  hb_param( 2, HB_IT_STRING  ) != NULL &&
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
      hb_sfWindow_ret( sfWindow_createUnicode( mode, &title, ( unsigned int ) hb_parni( 3 ), &settings ) );
      hb_storni( title, 2 );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfWindow* sfWindow_createFromHandle(sfWindowHandle handle, const sfContextSettings* settings);

// void sfWindow_destroy(sfWindow* window);
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

// void sfWindow_close(sfWindow* window);
HB_FUNC( SFWINDOW_CLOSE )
{
   sfWindow* window = hb_sfWindow_param( 1 );

   if( window )
   {
      sfWindow_close( window );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfBool sfWindow_isOpen(const sfWindow* window);
HB_FUNC( SFWINDOW_ISOPEN )
{
   const sfWindow* window = hb_sfWindow_param( 1 );

   if( window )
   {
      hb_retl( sfWindow_isOpen( window ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfContextSettings sfWindow_getSettings(const sfWindow* window);
HB_FUNC( SFWINDOW_GETSETTINGS )
{
   const sfWindow* window = hb_sfWindow_param( 1 );

   if( window )
   {
      sfContextSettings sfcontextsettings = sfWindow_getSettings( window );

      PHB_ITEM pContextSettingsArray = hb_itemArrayNew( 7 );

      hb_arraySetNI( pContextSettingsArray, 1, ( unsigned int ) sfcontextsettings.depthBits );
      hb_arraySetNI( pContextSettingsArray, 2, ( unsigned int ) sfcontextsettings.stencilBits );
      hb_arraySetNI( pContextSettingsArray, 3, ( unsigned int ) sfcontextsettings.antialiasingLevel );
      hb_arraySetNI( pContextSettingsArray, 4, ( unsigned int ) sfcontextsettings.majorVersion );
      hb_arraySetNI( pContextSettingsArray, 5, ( unsigned int ) sfcontextsettings.minorVersion );
      hb_arraySetNI( pContextSettingsArray, 6, ( unsigned int ) sfcontextsettings.attributeFlags );
      hb_arraySetL( pContextSettingsArray, 7,                   sfcontextsettings.sRgbCapable );

      hb_itemReturnRelease( pContextSettingsArray );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfBool sfWindow_pollEvent(sfWindow* window, sfEvent* event);
HB_FUNC( SFWINDOW_POLLEVENT )
{
   PHB_ITEM pItem;

   sfWindow* window = hb_sfWindow_param( 1 );

   if( window && ( pItem = hb_param( 2, HB_IT_ARRAY ) ) != NULL /* && hb_arrayLen( pItem ) == 13 */ )
   {
      sfEvent event;

      event.type ;// = hb_arrayGetNI( pItem, sfEvtClosed );
      //
      //event.type = pEventTypeArray //hb_arrayGetNI( pItem, 1 );
/*
      // sfSizeEvent size
      PHB_ITEM pSubarraySizeEvent = hb_arrayGetItemPtr( pItem, 2 );

      event->size.type   =                  hb_arrayGetNI( pSubarraySizeEvent, 1 );
      event->size.width  = ( unsigned int ) hb_arrayGetNI( pSubarraySizeEvent, 2 );
      event->size.height = ( unsigned int ) hb_arrayGetNI( pSubarraySizeEvent, 3 );

      // sfKeyEvent key
      PHB_ITEM pSubarrayKeyEvent = hb_arrayGetItemPtr( pItem, 3 );

      event->key.type    = hb_arrayGetNI( pSubarrayKeyEvent, 1 );
      event->key.code    = hb_arrayGetNI( pSubarrayKeyEvent, 2 );
      event->key.alt     = hb_arrayGetL( pSubarrayKeyEvent, 3 );
      event->key.control = hb_arrayGetL( pSubarrayKeyEvent, 4 );
      event->key.shift   = hb_arrayGetL( pSubarrayKeyEvent, 5 );
      event->key.system  = hb_arrayGetL( pSubarrayKeyEvent, 6 );

      // sfTextEvent text
      PHB_ITEM pSubarrayTextEvent = hb_arrayGetItemPtr( pItem, 4 );

      event->text.type    =                  hb_arrayGetNI( pSubarrayTextEvent, 1 );
      event->text.unicode = ( unsigned int ) hb_arrayGetNI( pSubarrayTextEvent, 2 );

      // sfMouseMoveEvent mouseMove
      PHB_ITEM pSubarrayMouseMoveEvent = hb_arrayGetItemPtr( pItem, 5 );

      event->mouseMove.type = hb_arrayGetNI( pSubarrayMouseMoveEvent, 1 );
      event->mouseMove.x    = hb_arrayGetNI( pSubarrayMouseMoveEvent, 2 );
      event->mouseMove.y    = hb_arrayGetNI( pSubarrayMouseMoveEvent, 3 );

      // sfMouseButtonEvent mouseButton
      PHB_ITEM pSubarrayMouseButtonEvent = hb_arrayGetItemPtr( pItem, 6 );

      event->mouseButton.type   = hb_arrayGetNI( pSubarrayMouseButtonEvent, 1 );
      event->mouseButton.button = hb_arrayGetNI( pSubarrayMouseButtonEvent, 2 );
      event->mouseButton.x      = hb_arrayGetNI( pSubarrayMouseButtonEvent, 3 );
      event->mouseButton.y      = hb_arrayGetNI( pSubarrayMouseButtonEvent, 4 );

      // sfMouseWheelEvent mouseWheel
      PHB_ITEM pSubarrayMouseWheelEvent = hb_arrayGetItemPtr( pItem, 7 );

      event->mouseWheel.type  = hb_arrayGetNI( pSubarrayMouseWheelEvent, 1 );
      event->mouseWheel.delta = hb_arrayGetNI( pSubarrayMouseWheelEvent, 2 );
      event->mouseWheel.x     = hb_arrayGetNI( pSubarrayMouseWheelEvent, 3 );
      event->mouseWheel.y     = hb_arrayGetNI( pSubarrayMouseWheelEvent, 4 );

      // sfMouseWheelScrollEvent mouseWheelScroll
      PHB_ITEM pSubarrayMouseWheelScrollEvent = hb_arrayGetItemPtr( pItem, 8 );

      event->mouseWheelScroll.type  =           hb_arrayGetNI( pSubarrayMouseWheelScrollEvent, 1 );
      event->mouseWheelScroll.wheel =           hb_arrayGetNI( pSubarrayMouseWheelScrollEvent, 2 );
      event->mouseWheelScroll.delta = ( float ) hb_arrayGetND( pSubarrayMouseWheelScrollEvent, 3 );
      event->mouseWheelScroll.x     =           hb_arrayGetNI( pSubarrayMouseWheelScrollEvent, 4 );
      event->mouseWheelScroll.y     =           hb_arrayGetNI( pSubarrayMouseWheelScrollEvent, 5 );

      // sfJoystickMoveEvent joystickMove
      PHB_ITEM pSubarrayJoystickMoveEvent = hb_arrayGetItemPtr( pItem, 9 );

      event->joystickMove.type       =                  hb_arrayGetNI( pSubarrayJoystickMoveEvent, 1 );
      event->joystickMove.joystickId = ( unsigned int ) hb_arrayGetNI( pSubarrayJoystickMoveEvent, 2 );
      event->joystickMove.axis       =                  hb_arrayGetNI( pSubarrayJoystickMoveEvent, 3 );
      event->joystickMove.position   = ( float )        hb_arrayGetND( pSubarrayJoystickMoveEvent, 4 );

      // sfJoystickButtonEvent joystickButton
      PHB_ITEM pSubarrayJoystickButtonEvent = hb_arrayGetItemPtr( pItem, 10 );

      event->joystickButton.type       =                  hb_arrayGetNI( pSubarrayJoystickButtonEvent, 1 );
      event->joystickButton.joystickId = ( unsigned int ) hb_arrayGetNI( pSubarrayJoystickButtonEvent, 2 );
      event->joystickButton.button     = ( unsigned int ) hb_arrayGetNI( pSubarrayJoystickButtonEvent, 3 );

      // sfJoystickConnectEvent joystickConnect
      PHB_ITEM pSubarrayJoystickConnectEvent = hb_arrayGetItemPtr( pItem, 11 );

      event->joystickConnect.type       =                  hb_arrayGetNI( pSubarrayJoystickConnectEvent, 1 );
      event->joystickConnect.joystickId = ( unsigned int ) hb_arrayGetNI( pSubarrayJoystickConnectEvent, 2 );

      // sfTouchEvent touch
      PHB_ITEM pSubarrayTouchEvent = hb_arrayGetItemPtr( pItem, 12 );

      event->touch.type   =                  hb_arrayGetNI( pSubarrayTouchEvent, 1 );
      event->touch.finger = ( unsigned int ) hb_arrayGetNI( pSubarrayTouchEvent, 2 );
      event->touch.x      =                  hb_arrayGetNI( pSubarrayTouchEvent, 3 );
      event->touch.y      =                  hb_arrayGetNI( pSubarrayTouchEvent, 4 );

      // sfSensorEvent sensor
      PHB_ITEM pSubarraySensorEvent = hb_arrayGetItemPtr( pItem, 13 );

      event->sensor.type       =           hb_arrayGetNI( pSubarraySensorEvent, 1 );
      event->sensor.sensorType =           hb_arrayGetNI( pSubarraySensorEvent, 2 );
      event->sensor.x          = ( float ) hb_arrayGetND( pSubarraySensorEvent, 3 );
      event->sensor.y          = ( float ) hb_arrayGetND( pSubarraySensorEvent, 4 );
      event->sensor.z          = ( float ) hb_arrayGetND( pSubarraySensorEvent, 5 );
*/
      hb_retl( sfWindow_pollEvent( window, &event ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfBool sfWindow_waitEvent(sfWindow* window, sfEvent* event);

// sfVector2i sfWindow_getPosition(const sfWindow* window);
HB_FUNC( SFWINDOW_GETPOSITION )
{
   const sfWindow* window = hb_sfWindow_param( 1 );

   if( window )
   {
      sfVector2i sfvector2i = sfWindow_getPosition( window );

      PHB_ITEM pVector2iArray = hb_itemArrayNew( 2 );

      hb_arraySetNI( pVector2iArray, 1, sfvector2i.x );
      hb_arraySetNI( pVector2iArray, 2, sfvector2i.y );

      hb_itemReturnRelease( pVector2iArray );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfWindow_setPosition(sfWindow* window, sfVector2i position);
HB_FUNC( SFWINDOW_SETPOSITION )
{
   PHB_ITEM pItem;

   sfWindow* window = hb_sfWindow_param( 1 );

   if( window && ( pItem = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 2 )
   {
      sfVector2i position;

      position.x = hb_arrayGetNI( pItem, 1 );
      position.y = hb_arrayGetNI( pItem, 2 );

      sfWindow_setPosition( window, position );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfVector2u sfWindow_getSize(const sfWindow* window);
HB_FUNC( SFWINDOW_GETSIZE )
{
   const sfWindow* window = hb_sfWindow_param( 1 );

   if( window )
   {
      sfVector2u sfvector2u = sfWindow_getSize( window );

      PHB_ITEM pVector2uArray = hb_itemArrayNew( 2 );

      hb_arraySetNI( pVector2uArray, 1, ( unsigned int ) sfvector2u.x );
      hb_arraySetNI( pVector2uArray, 2, ( unsigned int ) sfvector2u.y );

      hb_itemReturnRelease( pVector2uArray );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfWindow_setSize(sfWindow* window, sfVector2u size);
HB_FUNC( SFWINDOW_SETSIZE )
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
HB_FUNC( SFWINDOW_SETTITLE )
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
HB_FUNC( SFWINDOW_SETUNICODETITLE )
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
HB_FUNC( SFWINDOW_SETICON )
{
   sfWindow* window = hb_sfWindow_param( 1 );

   if( window &&
      hb_param( 2, HB_IT_INTEGER ) != NULL &&
      hb_param( 3, HB_IT_INTEGER ) != NULL &&
      hb_param( 4, HB_IT_POINTER ) != NULL )
   {
      sfWindow_setIcon( window, ( unsigned int ) hb_parni( 2 ), ( unsigned int ) hb_parni( 3 ), ( const unsigned char* ) hb_parptr( 4 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfWindow_setVisible(sfWindow* window, sfBool visible);
HB_FUNC( SFWINDOW_SETVISIBLE )
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
HB_FUNC( SFWINDOW_SETVERTICALSYNCENABLED )
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
HB_FUNC( SFWINDOW_SETMOUSECURSORVISIBLE )
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
HB_FUNC( SFWINDOW_SETMOUSECURSORGRABBED )
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
HB_FUNC( SFWINDOW_SETMOUSECURSOR )
{
   sfWindow* window = hb_sfWindow_param( 1 );
   const sfCursor* cursor = hb_sfCursor_param( 2 );

   if( window && cursor )
   {
      sfWindow_setMouseCursor( window, cursor );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfWindow_setKeyRepeatEnabled(sfWindow* window, sfBool enabled);
HB_FUNC( SFWINDOW_SETKEYREPEATENABLED )
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
HB_FUNC( SFWINDOW_SETFRAMERATELIMIT )
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
HB_FUNC( SFWINDOW_SETJOYSTICKTHRESHOLD )
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
HB_FUNC( SFWINDOW_SETACTIVE )
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
HB_FUNC( SFWINDOW_HASFOCUS )
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
HB_FUNC( SFWINDOW_DISPLAY )
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
