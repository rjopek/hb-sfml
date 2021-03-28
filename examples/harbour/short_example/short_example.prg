#include "hbsfml.ch"

#define EventType 1
#define type      1

PROCEDURE Main()

   LOCAL pWindow
   LOCAL aMode = { 800, 600, 32 }
   LOCAL aContextSettings := { 0, 0, 0, 4, 5, 0, .F. }
   LOCAL pTexture
   LOCAL pSprite
   LOCAL pFont
   LOCAL pText
   LOCAL pMusic
   LOCAL aEvent := {}

   /* Create the main window */
   pWindow := sfRenderWindow_create( aMode, "SFML window", sfResize + sfClose, aContextSettings )
   IF ! pWindow
      RETURN
   ENDIF

   /* Load a sprite to display */
   pTexture := sfTexture_createFromFile( "cute_image.jpg", NIL )
   IF ! pTexture
      RETURN
   ENDIF

   pSprite := sfSprite_create()
   sfSprite_setTexture( pSprite, pTexture, .T. )

   /* Create a graphical text to display */
   pFont := sfFont_createFromFile( "arial.ttf" )
   IF ! pFont
      RETURN
   ENDIF

   pText := sfText_create()
   sfText_setString( pText, "Hello SFML" )
   sfText_setFont( pText, pFont )
   sfText_setCharacterSize( pText, 50 )

   /* Load a music to play */
   pMusic := sfMusic_createFromFile( "nice_music.ogg" )
   IF ! pMusic
      RETURN
   ENDIF

   /* Play the music */
   sfMusic_play( pMusic )

   /* Start the game loop */
   DO WHILE sfRenderWindow_isOpen( pWindow )

      /* Process events */
      DO WHILE sfRenderWindow_pollEvent( pWindow, aEvent )

         /* Close window : exit */
         IF aEvent[ EventType ][ type ] == sfEvtClosed
            sfRenderWindow_close( pWindow )
         ENDIF

      ENDDO

      /* Clear the screen */
      sfRenderWindow_clear( pWindow, sfBlack )

      /* Draw the sprite */
      sfRenderWindow_drawSprite( pWindow, pSprite, NIL )

      /* Draw the text */
      sfRenderWindow_drawText( pWindow, pText, NIL )

      /* Update the window */
      sfRenderWindow_display( pWindow )

   ENDDO

   /* Cleanup resources */
   sfMusic_destroy( pMusic )
   sfText_destroy( pText )
   sfFont_destroy( pFont )
   sfSprite_destroy( pSprite )
   sfTexture_destroy( pTexture )
   sfRenderWindow_destroy( pWindow )

   RETURN
