/*
 * SFML library: RenderWindow.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

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

// sfRenderWindow* sfRenderWindow_create(sfVideoMode mode, const char* title, sfUint32 style, const sfContextSettings* settings);
HB_FUNC( SFRENDERWINDOW_CREATE )
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

      hb_sfRenderWindow_ret( sfRenderWindow_create( mode, hb_parc( 2 ), ( unsigned int ) hb_parni( 3 ), &settings  ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfRenderWindow* sfRenderWindow_createUnicode(sfVideoMode mode, const sfUint32* title, sfUint32 style, const sfContextSettings* settings);

// sfRenderWindow* sfRenderWindow_createFromHandle(sfWindowHandle handle, const sfContextSettings* settings);

// void sfRenderWindow_destroy(sfRenderWindow* renderWindow);
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

// void sfRenderWindow_close(sfRenderWindow* renderWindow);

// sfBool sfRenderWindow_isOpen(const sfRenderWindow* renderWindow);
HB_FUNC( SFRENDERWINDOW_ISOPEN )
{
   sfRenderWindow* renderWindow = hb_sfRenderWindow_param( 1 );

   if( renderWindow )
   {
      hb_retl( sfRenderWindow_isOpen( renderWindow ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfContextSettings sfRenderWindow_getSettings(const sfRenderWindow* renderWindow);

// sfBool sfRenderWindow_pollEvent(sfRenderWindow* renderWindow, sfEvent* event);

// sfBool sfRenderWindow_waitEvent(sfRenderWindow* renderWindow, sfEvent* event);

// sfVector2i sfRenderWindow_getPosition(const sfRenderWindow* renderWindow);

// void sfRenderWindow_setPosition(sfRenderWindow* renderWindow, sfVector2i position);

// sfVector2u sfRenderWindow_getSize(const sfRenderWindow* renderWindow);

// void sfRenderWindow_setSize(sfRenderWindow* renderWindow, sfVector2u size);

// void sfRenderWindow_setTitle(sfRenderWindow* renderWindow, const char* title);

// void sfRenderWindow_setUnicodeTitle(sfRenderWindow* renderWindow, const sfUint32* title);

// void sfRenderWindow_setIcon(sfRenderWindow* renderWindow, unsigned int width, unsigned int height, const sfUint8* pixels);

// void sfRenderWindow_setVisible(sfRenderWindow* renderWindow, sfBool visible);

// void sfRenderWindow_setVerticalSyncEnabled(sfRenderWindow* renderWindow, sfBool enabled);

// void sfRenderWindow_setMouseCursorVisible(sfRenderWindow* renderWindow, sfBool show);

// void sfRenderWindow_setMouseCursorGrabbed(sfRenderWindow* renderWindow, sfBool grabbed);

// void sfRenderWindow_setMouseCursor(sfRenderWindow* window, const sfCursor* cursor);

// void sfRenderWindow_setKeyRepeatEnabled(sfRenderWindow* renderWindow, sfBool enabled);

// void sfRenderWindow_setFramerateLimit(sfRenderWindow* renderWindow, unsigned int limit);

// void sfRenderWindow_setJoystickThreshold(sfRenderWindow* renderWindow, float threshold);

// sfBool sfRenderWindow_setActive(sfRenderWindow* renderWindow, sfBool active);

// void sfRenderWindow_requestFocus(sfRenderWindow* renderWindow);

// sfBool sfRenderWindow_hasFocus(const sfRenderWindow* renderWindow);

// void sfRenderWindow_display(sfRenderWindow* renderWindow);

// sfWindowHandle sfRenderWindow_getSystemHandle(const sfRenderWindow* renderWindow);

// void sfRenderWindow_clear(sfRenderWindow* renderWindow, sfColor color);

// void sfRenderWindow_setView(sfRenderWindow* renderWindow, const sfView* view);

// const sfView* sfRenderWindow_getView(const sfRenderWindow* renderWindow);

// const sfView* sfRenderWindow_getDefaultView(const sfRenderWindow* renderWindow);

// sfIntRect sfRenderWindow_getViewport(const sfRenderWindow* renderWindow, const sfView* view);

// sfVector2f sfRenderWindow_mapPixelToCoords(const sfRenderWindow* renderWindow, sfVector2i point, const sfView* view);

// sfVector2i sfRenderWindow_mapCoordsToPixel(const sfRenderWindow* renderWindow, sfVector2f point, const sfView* view);

// void sfRenderWindow_drawSprite(sfRenderWindow* renderWindow, const sfSprite* object, const sfRenderStates* states);

// void sfRenderWindow_drawText(sfRenderWindow* renderWindow, const sfText* object, const sfRenderStates* states);

// void sfRenderWindow_drawShape(sfRenderWindow* renderWindow, const sfShape* object, const sfRenderStates* states);

// void sfRenderWindow_drawCircleShape(sfRenderWindow* renderWindow, const sfCircleShape* object, const sfRenderStates* states);

// void sfRenderWindow_drawConvexShape(sfRenderWindow* renderWindow, const sfConvexShape* object, const sfRenderStates* states);

// void sfRenderWindow_drawRectangleShape(sfRenderWindow* renderWindow, const sfRectangleShape* object, const sfRenderStates* states);

// void sfRenderWindow_drawVertexArray(sfRenderWindow* renderWindow, const sfVertexArray* object, const sfRenderStates* states);

// void sfRenderWindow_drawVertexBuffer(sfRenderWindow* renderWindow, const sfVertexBuffer* object, const sfRenderStates* states);

// void sfRenderWindow_drawPrimitives(sfRenderWindow* renderWindow, const sfVertex* vertices, size_t vertexCount, sfPrimitiveType type, const sfRenderStates* states);

// void sfRenderWindow_pushGLStates(sfRenderWindow* renderWindow);

// void sfRenderWindow_popGLStates(sfRenderWindow* renderWindow);

// void sfRenderWindow_resetGLStates(sfRenderWindow* renderWindow);

// CSFML_DEPRECATED sfImage* sfRenderWindow_capture(const sfRenderWindow* renderWindow);

// sfVector2i sfMouse_getPositionRenderWindow(const sfRenderWindow* relativeTo);

// void sfMouse_setPositionRenderWindow(sfVector2i position, const sfRenderWindow* relativeTo);

// sfVector2i sfTouch_getPositionRenderWindow(unsigned int finger, const sfRenderWindow* relativeTo);
