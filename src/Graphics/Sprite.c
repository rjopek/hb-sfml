/*
 * SFML library: Sprite.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

/* Graphics/sfSprite */
static HB_GARBAGE_FUNC( hb_sfSprite_destructor )
{
   sfSprite ** ppSfSprite = ( sfSprite ** ) Cargo;

   if( *ppSfSprite )
   {
      sfSprite_destroy( *ppSfSprite );
      *ppSfSprite = NULL;
   }
}

static const HB_GC_FUNCS s_gcSfSpriteFuncs =
{
   hb_sfSprite_destructor,
   hb_gcDummyMark
};

PHB_ITEM hb_sfSpriteItemPut( PHB_ITEM pItem, sfSprite * pSfSprite )
{
   sfSprite ** ppSfSprite = ( sfSprite ** ) hb_gcAllocate( sizeof( sfSprite * ), &s_gcSfSpriteFuncs );

   *ppSfSprite = pSfSprite;
   return hb_itemPutPtrGC( pItem, ppSfSprite );
}

sfSprite * hb_sfSprite_param( int iParam )
{
   sfSprite ** ppSfSprite = ( sfSprite ** ) hb_parptrGC( &s_gcSfSpriteFuncs, iParam );

   if( ppSfSprite && *ppSfSprite )
   {
      return *ppSfSprite;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      return NULL;
   }
}

void hb_sfSprite_ret( sfSprite * pSfSprite )
{
   hb_sfSpriteItemPut( hb_stackReturnItem(), pSfSprite );
}

// sfSprite* sfSprite_create(void);
HB_FUNC( SFSPRITE_CREATE )
{
   hb_sfSprite_ret( sfSprite_create() );
}

// sfSprite* sfSprite_copy(const sfSprite* sprite);
HB_FUNC( SFSPRITE_COPY )
{
   sfSprite* sprite = hb_sfSprite_param( 1 );

   if( sprite )
   {
      hb_sfSprite_ret( sfSprite_copy( sprite ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfSprite_destroy(sfSprite* sprite);
HB_FUNC( SFSPRITE_DESTROY )
{
   sfSprite ** ppSfSprite = ( sfSprite ** ) hb_parptrGC( &s_gcSfSpriteFuncs, 1 );

   if( ppSfSprite && *ppSfSprite )
   {
      sfSprite_destroy( *ppSfSprite );
      *ppSfSprite = NULL;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfSprite_setPosition(sfSprite* sprite, sfVector2f position);

// void sfSprite_setRotation(sfSprite* sprite, float angle);

// void sfSprite_setScale(sfSprite* sprite, sfVector2f scale);

// void sfSprite_setOrigin(sfSprite* sprite, sfVector2f origin);

// sfVector2f sfSprite_getPosition(const sfSprite* sprite);

// float sfSprite_getRotation(const sfSprite* sprite);

// sfVector2f sfSprite_getScale(const sfSprite* sprite);

// sfVector2f sfSprite_getOrigin(const sfSprite* sprite);

// void sfSprite_move(sfSprite* sprite, sfVector2f offset);

// void sfSprite_rotate(sfSprite* sprite, float angle);

// void sfSprite_scale(sfSprite* sprite, sfVector2f factors);

// sfTransform sfSprite_getTransform(const sfSprite* sprite);

// sfTransform sfSprite_getInverseTransform(const sfSprite* sprite);

// void sfSprite_setTexture(sfSprite* sprite, const sfTexture* texture, sfBool resetRect);
HB_FUNC( SFSPRITE_SETTEXTURE )
{
   sfSprite* sprite = hb_sfSprite_param( 1 );
   sfTexture* texture = hb_sfTexture_param( 2 );

   if( sprite && texture && hb_param( 3, HB_IT_LOGICAL ) != NULL )
   {
      sfSprite_setTexture( sprite, texture, hb_parl( 3 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}


// void sfSprite_setTextureRect(sfSprite* sprite, sfIntRect rectangle);

// void sfSprite_setColor(sfSprite* sprite, sfColor color);

// const sfTexture* sfSprite_getTexture(const sfSprite* sprite);

// sfIntRect sfSprite_getTextureRect(const sfSprite* sprite);

// sfColor sfSprite_getColor(const sfSprite* sprite);

// sfFloatRect sfSprite_getLocalBounds(const sfSprite* sprite);

// sfFloatRect sfSprite_getGlobalBounds(const sfSprite* sprite);
