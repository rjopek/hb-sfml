/*
 * SFML library: Context.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

// sfContext* sfContext_create(void);
HB_FUNC( SFCONTEXT_CREATE )
{
   hb_sfContext_ret( sfContext_create() );
}

// void sfContext_destroy(sfContext* context);
/* This function is in the file core.c */

// sfBool sfContext_setActive(sfContext* context, sfBool active);
HB_FUNC( SFCONTEXT_SETACTIVE )
{
   sfContext* context = hb_sfContext_param( 1 );

   if( context && hb_param( 2, HB_IT_LOGICAL ) != NULL )
   {
      hb_retl( sfContext_setActive( context, hb_parl( 2 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfContextSettings sfContext_getSettings(const sfContext* context);
HB_FUNC( SFCONTEXT_GETSETTINGS )
{
   const sfContext* context = hb_sfContext_param( 1 );

   if( context )
   {
      sfContextSettings sfcontextsettings = sfContext_getSettings( context );

      PHB_ITEM info = hb_itemArrayNew( 7 );

      hb_arraySetNI( info, 1, ( unsigned int ) sfcontextsettings.depthBits );
      hb_arraySetNI( info, 2, ( unsigned int ) sfcontextsettings.stencilBits );
      hb_arraySetNI( info, 3, ( unsigned int ) sfcontextsettings.antialiasingLevel );
      hb_arraySetNI( info, 4, ( unsigned int ) sfcontextsettings.majorVersion );
      hb_arraySetNI( info, 5, ( unsigned int ) sfcontextsettings.minorVersion );
      hb_arraySetNI( info, 6, ( unsigned int ) sfcontextsettings.attributeFlags );
      hb_arraySetL( info, 7,                   sfcontextsettings.sRgbCapable );

      hb_itemReturnRelease( info );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfUint64 sfContext_getActiveContextId();
HB_FUNC( SFCONTEXT_GETACTIVECONTEXTID )
{
   hb_retnll( sfContext_getActiveContextId() );
}
