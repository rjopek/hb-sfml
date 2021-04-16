/*
 * SFML library: Transformable.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

/* Graphics/sfTransformable */
static HB_GARBAGE_FUNC( hb_sfTransformable_destructor )
{
   sfTransformable ** ppSfTransformable = ( sfTransformable ** ) Cargo;

   if( *ppSfTransformable )
   {
      sfTransformable_destroy( *ppSfTransformable );
      *ppSfTransformable = NULL;
   }
}

static const HB_GC_FUNCS s_gcSfTransformableFuncs =
{
   hb_sfTransformable_destructor,
   hb_gcDummyMark
};

PHB_ITEM hb_sfTransformableItemPut( PHB_ITEM pItem, sfTransformable * pSfTransformable )
{
   sfTransformable ** ppSfTransformable = ( sfTransformable ** ) hb_gcAllocate( sizeof( sfTransformable * ), &s_gcSfTransformableFuncs );

   *ppSfTransformable = pSfTransformable;
   return hb_itemPutPtrGC( pItem, ppSfTransformable );
}

sfTransformable * hb_sfTransformable_param( int iParam )
{
   sfTransformable ** ppSfTransformable = ( sfTransformable ** ) hb_parptrGC( &s_gcSfTransformableFuncs, iParam );

   if( ppSfTransformable && *ppSfTransformable )
   {
      return *ppSfTransformable;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      return NULL;
   }
}

void hb_sfTransformable_ret( sfTransformable * pSfTransformable )
{
   hb_sfTransformableItemPut( hb_stackReturnItem(), pSfTransformable );
}

// sfTransformable* sfTransformable_create(void);

// sfTransformable* sfTransformable_copy(const sfTransformable* transformable);

// void sfTransformable_destroy(sfTransformable* transformable);
HB_FUNC( SFTRANSFORMABLE_DESTROY )
{
   sfTransformable ** ppSfTransformable = ( sfTransformable ** ) hb_parptrGC( &s_gcSfTransformableFuncs, 1 );

   if( ppSfTransformable && *ppSfTransformable )
   {
      sfTransformable_destroy( *ppSfTransformable );
      *ppSfTransformable = NULL;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfTransformable_setPosition(sfTransformable* transformable, sfVector2f position);

// void sfTransformable_setRotation(sfTransformable* transformable, float angle);

// void sfTransformable_setScale(sfTransformable* transformable, sfVector2f scale);

// void sfTransformable_setOrigin(sfTransformable* transformable, sfVector2f origin);

// sfVector2f sfTransformable_getPosition(const sfTransformable* transformable);

// float sfTransformable_getRotation(const sfTransformable* transformable);

// sfVector2f sfTransformable_getScale(const sfTransformable* transformable);

// sfVector2f sfTransformable_getOrigin(const sfTransformable* transformable);

// void sfTransformable_move(sfTransformable* transformable, sfVector2f offset);

// void sfTransformable_rotate(sfTransformable* transformable, float angle);

// void sfTransformable_scale(sfTransformable* transformable, sfVector2f factors);

// sfTransform sfTransformable_getTransform(const sfTransformable* transformable);

// sfTransform sfTransformable_getInverseTransform(const sfTransformable* transformable);
