#include "hbsfml.ch"

PROCEDURE Main()

   LOCAL aMode = { 800, 600, 32 }
   LOCAL pWindow
   LOCAL pTexture
   LOCAL pSprite
   LOCAL pFont
   LOCAL pText
   LOCAL pMusic
   LOCAL aEvent

   /* Create the main window */
   pWindow := sfRenderWindow_create( aMode, "SFML window", sfResize + sfClose, NIL )
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
      DO WHILE( sfRenderWindow_pollEvent( window, &event ) )

         /* Close window : exit */
         IF event.type == sfEvtClosed
            sfRenderWindow_close( window )
         ENDIF

      ENDDO

      /* Clear the screen */
      sfRenderWindow_clear( window, sfBlack )

      /* Draw the sprite */
      sfRenderWindow_drawSprite( window, sprite, NULL )

      /* Draw the text */
      sfRenderWindow_drawText( window, text, NULL )

      /* Update the window */
      sfRenderWindow_display( window )
   ENDDO

   /* Cleanup resources */
   sfMusic_destroy( music )
   sfText_destroy( text )
   sfFont_destroy( font )
   sfSprite_destroy( sprite )
   sfTexture_destroy( texture )
   sfRenderWindow_destroy( window )

   RETURN
