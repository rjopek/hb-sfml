#include "hbsfml.ch"

#define EVENT_TYPE   1

PROCEDURE Main()

   LOCAL pWindow
   LOCAL aContextSettings := { 0, 0, 0, 4, 5, 0, .F. }
   LOCAL aMode := { 800, 600, 24 }
   LOCAL aEvent

   pWindow := sfWindow_create( aMode, "My window", sfResize + sfClose, aContextSettings )

   // run the program as long as the window is open
   DO WHILE sfWindow_isOpen( pWindow )

      // check all the window's events that were triggered since the last iteration of the loop
      DO WHILE sfWindow_pollEvent( pWindow, aEvent )

         // "close requested" event: we close the window
         IF aEvent[ EVENT_TYPE ] == sfEvtClosed
            sfWindow_close( pWindow )
         ENDIF

      ENDDO

   ENDDO

   RETURN