
#ifndef HB_SFML_H_
#define HB_SFML_H_

#include "hbapi.h"
#include "hbapierr.h"
#include "hbapiitm.h"
#include "hbstack.h"

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>

HB_EXTERN_BEGIN

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/* Audio/sfMusic */
extern HB_EXPORT sfMusic *  hb_sfMusicItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM   hb_sfMusicItemPut( PHB_ITEM pItem, sfMusic * pSfMusic );
extern HB_EXPORT sfMusic *  hb_sfMusic_param( int iParam );
extern HB_EXPORT void       hb_sfMusic_ret( sfMusic * );

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/* Graphics/sfCircleShape */
extern HB_EXPORT sfCircleShape *  hb_sfCircleShapeItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM         hb_sfCircleShapeItemPut( PHB_ITEM pItem, sfCircleShape * pSfCircleShape );
extern HB_EXPORT sfCircleShape *  hb_sfCircleShape_param( int iParam );
extern HB_EXPORT void             hb_sfCircleShape_ret( sfCircleShape * );

/* Graphics/sfFont */
extern HB_EXPORT sfFont *  hb_sfFontItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM  hb_sfFontItemPut( PHB_ITEM pItem, sfFont * pSfFont );
extern HB_EXPORT sfFont *  hb_sfFont_param( int iParam );
extern HB_EXPORT void      hb_sfFont_ret( sfFont * );

/* Graphics/sfRenderWindow */
extern HB_EXPORT sfRenderWindow *  hb_sfRenderWindowItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM          hb_sfRenderWindowItemPut( PHB_ITEM pItem, sfRenderWindow * pSfRenderWindow );
extern HB_EXPORT sfRenderWindow *  hb_sfRenderWindow_param( int iParam );
extern HB_EXPORT void              hb_sfRenderWindow_ret( sfRenderWindow * );

/* Graphics/sfSprite */
extern HB_EXPORT sfSprite *  hb_sfSpriteItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM    hb_sfSpriteItemPut( PHB_ITEM pItem, sfSprite * pSfSprite );
extern HB_EXPORT sfSprite *  hb_sfSprite_param( int iParam );
extern HB_EXPORT void        hb_sfSprite_ret( sfSprite * );

/* Graphics/sfText */
extern HB_EXPORT sfText *  hb_sfTextItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM  hb_sfTextItemPut( PHB_ITEM pItem, sfText * pSfText );
extern HB_EXPORT sfText *  hb_sfText_param( int iParam );
extern HB_EXPORT void      hb_sfText_ret( sfText * );

/* Graphics/sfTexture */
extern HB_EXPORT sfTexture *  hb_sfTextureItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM     hb_sfTextureItemPut( PHB_ITEM pItem, sfTexture * pSfTexture );
extern HB_EXPORT sfTexture *  hb_sfTexture_param( int iParam );
extern HB_EXPORT void         hb_sfTexture_ret( sfTexture * );

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/* Window/sfWindow */
extern HB_EXPORT sfWindow *  hb_sfWindowItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM    hb_sfWindowItemPut( PHB_ITEM pItem, sfWindow * pSfWindow );
extern HB_EXPORT sfWindow *  hb_sfWindow_param( int iParam );
extern HB_EXPORT void        hb_sfWindow_ret( sfWindow * );

/* Window/sfContext */
extern HB_EXPORT sfContext *  hb_sfContextItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM     hb_sfContextItemPut( PHB_ITEM pItem, sfContext * pSfContext );
extern HB_EXPORT sfContext *  hb_sfContext_param( int iParam );
extern HB_EXPORT void         hb_sfContext_ret( sfContext * );

/* Window/sfCursor */
extern HB_EXPORT sfCursor *  hb_sfCursorItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM    hb_sfCursorItemPut( PHB_ITEM pItem, sfCursor * pSfCursor );
extern HB_EXPORT sfCursor *  hb_sfCursor_param( int iParam );
extern HB_EXPORT void        hb_sfCursor_ret( sfCursor * );

HB_EXTERN_END

#endif /* HB_SFML_H_ */
