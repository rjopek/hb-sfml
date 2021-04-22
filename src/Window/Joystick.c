/*
 * SFML library: Joystick.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

// sfBool sfJoystick_isConnected(unsigned int joystick);
HB_FUNC( SFJOYSTICK_ISCONNECTED )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL )
   {
      hb_retl( sfJoystick_isConnected( ( unsigned int ) hb_parni( 1 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// unsigned int sfJoystick_getButtonCount(unsigned int joystick);
HB_FUNC( SFJOYSTICK_GETBUTTONCOUNT )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL )
   {
      hb_retni( ( unsigned int ) sfJoystick_getButtonCount( ( unsigned int ) hb_parni( 1 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfBool sfJoystick_hasAxis(unsigned int joystick, sfJoystickAxis axis);
HB_FUNC( SFJOYSTICK_HASAXIS )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL && hb_param( 2, HB_IT_INTEGER ) != NULL )
   {
      hb_retl( sfJoystick_hasAxis( ( unsigned int ) hb_parni( 1 ), ( unsigned int ) hb_parni( 2 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfBool sfJoystick_isButtonPressed(unsigned int joystick, unsigned int button);
HB_FUNC( SFJOYSTICK_ISBUTTONPRESSED )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL && hb_param( 2, HB_IT_INTEGER ) != NULL )
   {
      hb_retl( sfJoystick_isButtonPressed( ( unsigned int ) hb_parni( 1 ), ( unsigned int ) hb_parni( 2 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// float sfJoystick_getAxisPosition(unsigned int joystick, sfJoystickAxis axis);
HB_FUNC( SFJOYSTICK_GETAXISPOSITION )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL && hb_param( 2, HB_IT_INTEGER ) != NULL )
   {
      hb_retnl( ( float ) sfJoystick_getAxisPosition( ( unsigned int ) hb_parni( 1 ), ( unsigned int ) hb_parni( 2 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfJoystickIdentification sfJoystick_getIdentification(unsigned int joystick);
HB_FUNC( SFJOYSTICK_GETIDENTIFICATION )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL )
   {
      sfJoystickIdentification sfjoystickidentification = sfJoystick_getIdentification( ( unsigned int ) hb_parni( 1 ) );

      PHB_ITEM pJoystickIdentificationArray = hb_itemArrayNew( 3 );

      hb_arraySetC(  pJoystickIdentificationArray, 1,                  sfjoystickidentification.name );
      hb_arraySetNI( pJoystickIdentificationArray, 2, ( unsigned int ) sfjoystickidentification.vendorId );
      hb_arraySetNI( pJoystickIdentificationArray, 3, ( unsigned int ) sfjoystickidentification.productId );

      hb_itemReturnRelease( pJoystickIdentificationArray );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfJoystick_update(void);
HB_FUNC( SFJOYSTICK_UPDATE )
{
   sfJoystick_update();
}
