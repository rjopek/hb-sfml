/*
 * SFML library: Keyboard.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

// sfBool sfKeyboard_isKeyPressed(sfKeyCode key);
HB_FUNC( SFKEYBOARD_ISKEYPRESSED )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL )
   {
      hb_retl( sfKeyboard_isKeyPressed( hb_parni( 1 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfKeyboard_setVirtualKeyboardVisible(sfBool visible);
HB_FUNC( SFKEYBOARD_SETVIRTUALKEYBOARDVISIBLE )
{
   if( hb_param( 1, HB_IT_LOGICAL ) != NULL )
   {
      sfKeyboard_setVirtualKeyboardVisible( hb_parl( 1 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}
