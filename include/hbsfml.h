
#ifndef HB_SFML_H_
#define HB_SFML_H_

#include "hbapi.h"
#include "hbapierr.h"
#include "hbapiitm.h"
#include "hbstack.h"

#include <SFML/Graphics.h>
#include <SFML/Window.h>

HB_EXTERN_BEGIN

extern HB_EXPORT sfRenderWindow *  hb_sfRenderWindowItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM          hb_sfRenderWindowItemPut( PHB_ITEM pItem, sfRenderWindow * pSfRenderWindow );
extern HB_EXPORT sfRenderWindow *  hb_sfRenderWindow_param( int iParam );
extern HB_EXPORT void              hb_sfRenderWindow_ret( sfRenderWindow * );

extern HB_EXPORT sfWindow *  hb_sfWindowItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM    hb_sfWindowItemPut( PHB_ITEM pItem, sfWindow * pSfWindow );
extern HB_EXPORT sfWindow *  hb_sfWindow_param( int iParam );
extern HB_EXPORT void        hb_sfWindow_ret( sfWindow * );

extern HB_EXPORT sfContext *  hb_sfContextItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM     hb_sfContextItemPut( PHB_ITEM pItem, sfContext * pSfContext );
extern HB_EXPORT sfContext *  hb_sfContext_param( int iParam );
extern HB_EXPORT void         hb_sfContext_ret( sfContext * );

HB_EXTERN_END

#endif /* HB_SFML_H_ */
