#include "hbsfml.h"

int main()
{
   sfVideoMode mode = { 800, 600, 32 };
   sfWindow* window;
   sfEvent event;

   window = sfWindow_create( mode, "SFML window", sfResize | sfClose, NULL );

   // run the program as long as the window is open
   while( sfRenderWindow_isOpen( window ) )
   {
      // check all the window's events that were triggered since the last iteration of the loop
      while( sfRenderWindow_pollEvent( window, &event ) )
      {
         // "close requested" event: we close the window
         if( event.type == sfEvtClosed )
         {
            sfRenderWindow_close( window );
         }
      }
   }
   sfWindow_destroy( window );

   return 0;
}