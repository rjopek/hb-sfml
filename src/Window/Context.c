/*
 * SFML library: Context.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

/* Window/sfContext */
static HB_GARBAGE_FUNC( hb_sfContext_destructor )
{
   sfContext ** ppSfContext = ( sfContext ** ) Cargo;

   if( *ppSfContext )
   {
      sfContext_destroy( *ppSfContext );
      *ppSfContext = NULL;
   }
}

static const HB_GC_FUNCS s_gcSfContextFuncs =
{
   hb_sfContext_destructor,
   hb_gcDummyMark
};

PHB_ITEM hb_sfContextItemPut( PHB_ITEM pItem, sfContext * pSfContext )
{
   sfContext ** ppSfContext = ( sfContext ** ) hb_gcAllocate( sizeof( sfContext * ), &s_gcSfContextFuncs );

   *ppSfContext = pSfContext;
   return hb_itemPutPtrGC( pItem, ppSfContext );
}

sfContext * hb_sfContext_param( int iParam )
{
   sfContext ** ppSfContext = ( sfContext ** ) hb_parptrGC( &s_gcSfContextFuncs, iParam );

   if( ppSfContext && *ppSfContext )
   {
      return *ppSfContext;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      return NULL;
   }
}

void hb_sfContext_ret( sfContext * pSfContext )
{
   hb_sfContextItemPut( hb_stackReturnItem(), pSfContext );
}

// sfContext* sfContext_create(void);
HB_FUNC( SFCONTEXT_CREATE )
{
   hb_sfContext_ret( sfContext_create() );
}

// void sfContext_destroy(sfContext* context);
HB_FUNC( SFCONTEXT_DESTROY )
{
   sfContext ** ppSfContext = ( sfContext ** ) hb_parptrGC( &s_gcSfContextFuncs, 1 );

   if( ppSfContext && *ppSfContext )
   {
      sfContext_destroy( *ppSfContext );
      *ppSfContext = NULL;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

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

// sfUint64 sfContext_getActiveContextId();
HB_FUNC( SFCONTEXT_GETACTIVECONTEXTID )
{
   hb_retnll( sfContext_getActiveContextId() );
}
