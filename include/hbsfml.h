
#ifndef HB_SFML_H_
#define HB_SFML_H_

#include "hbapi.h"
#include "hbapierr.h"
#include "hbapiitm.h"
#include "hbstack.h"

#include <SFML/Window.h>

HB_EXTERN_BEGIN

extern HB_EXPORT sfWindow *  hb_sfWindowItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM    hb_sfWindowItemPut( PHB_ITEM pItem, sfWindow * pSfWindow );
extern HB_EXPORT sfWindow *  hb_sfWindow_param( int iParam );
extern HB_EXPORT void        hb_sfWindow_ret( sfWindow * );

HB_EXTERN_END

#endif /* HB_SFML_H_ */
