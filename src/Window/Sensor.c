/*
 * SFML library: Sensor.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

// sfBool sfSensor_isAvailable(sfSensorType sensor);
HB_FUNC( sfSensor_isAvailable )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL )
   {
      hb_retl( sfSensor_isAvailable( ( unsigned int ) hb_parni( 1 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfSensor_setEnabled(sfSensorType sensor, sfBool enabled);
HB_FUNC( SFSENSOR_SETENABLED )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL && hb_param( 2, HB_IT_LOGICAL ) != NULL )
   {
      sfSensor_setEnabled( ( unsigned int ) hb_parni( 1 ), hb_parl( 2 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfVector3f sfSensor_getValue(sfSensorType sensor);
HB_FUNC( sfSensor_getValue )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL )
   {
      sfVector3f sfvector3f = sfSensor_getValue( ( unsigned int ) hb_parni( 1 ) );

      PHB_ITEM pVector3fArray = hb_itemArrayNew( 3 );

      hb_arraySetND( pVector3fArray, 1, ( float ) sfvector3f.x );
      hb_arraySetND( pVector3fArray, 2, ( float ) sfvector3f.y );
      hb_arraySetND( pVector3fArray, 3, ( float ) sfvector3f.z );

      hb_itemReturnRelease( pVector3fArray );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}
