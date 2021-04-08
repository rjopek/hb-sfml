#ifndef HB_SFML_H_
#define HB_SFML_H_

#include "hbapi.h"
#include "hbapierr.h"
#include "hbapiitm.h"
#include "hbstack.h"

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Network.h>
#include <SFML/System.h>
#include <SFML/Window.h>

HB_EXTERN_BEGIN

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/* Audio/sfMusic */
extern HB_EXPORT sfMusic *  hb_sfMusicItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM   hb_sfMusicItemPut( PHB_ITEM pItem, sfMusic * pSfMusic );
extern HB_EXPORT sfMusic *  hb_sfMusic_param( int iParam );
extern HB_EXPORT void       hb_sfMusic_ret( sfMusic * );

/* Audio/sfSound */
extern HB_EXPORT sfSound *  hb_sfSoundItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM   hb_sfSoundItemPut( PHB_ITEM pItem, sfSound * pSfSound );
extern HB_EXPORT sfSound *  hb_sfSound_param( int iParam );
extern HB_EXPORT void       hb_sfSound_ret( sfSound * );

/* Audio/sfSoundBuffer */
extern HB_EXPORT sfSoundBuffer *  hb_sfSoundBufferItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM         hb_sfSoundBufferItemPut( PHB_ITEM pItem, sfSoundBuffer * pSfSoundBuffer );
extern HB_EXPORT sfSoundBuffer *  hb_sfSoundBuffer_param( int iParam );
extern HB_EXPORT void             hb_sfSoundBuffer_ret( sfSoundBuffer * );

/* Audio/sfSoundBufferRecorder */
extern HB_EXPORT sfSoundBufferRecorder *  hb_sfSoundBufferRecorderItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM                 hb_sfSoundBufferRecorderItemPut( PHB_ITEM pItem, sfSoundBufferRecorder * pSfSoundBufferRecorder );
extern HB_EXPORT sfSoundBufferRecorder *  hb_sfSoundBufferRecorder_param( int iParam );
extern HB_EXPORT void                     hb_sfSoundBufferRecorder_ret( sfSoundBufferRecorder * );

/* Audio/sfSoundStream */
extern HB_EXPORT sfSoundStream *  hb_sfSoundStreamItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM         hb_sfSoundStreamItemPut( PHB_ITEM pItem, sfSoundStream * pSfSoundStream );
extern HB_EXPORT sfSoundStream *  hb_sfSoundStream_param( int iParam );
extern HB_EXPORT void             hb_sfSoundStream_ret( sfSoundStream * );

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/* Graphics/sfCircleShape */
extern HB_EXPORT sfCircleShape *  hb_sfCircleShapeItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM         hb_sfCircleShapeItemPut( PHB_ITEM pItem, sfCircleShape * pSfCircleShape );
extern HB_EXPORT sfCircleShape *  hb_sfCircleShape_param( int iParam );
extern HB_EXPORT void             hb_sfCircleShape_ret( sfCircleShape * );

/* Graphics/sfConvexShape */
extern HB_EXPORT sfConvexShape *  hb_sfConvexShapeItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM         hb_sfConvexShapeItemPut( PHB_ITEM pItem, sfConvexShape * pSfConvexShape );
extern HB_EXPORT sfConvexShape *  hb_sfConvexShape_param( int iParam );
extern HB_EXPORT void             hb_sfConvexShape_ret( sfConvexShape * );

/* Graphics/sfFont */
extern HB_EXPORT sfFont *  hb_sfFontItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM  hb_sfFontItemPut( PHB_ITEM pItem, sfFont * pSfFont );
extern HB_EXPORT sfFont *  hb_sfFont_param( int iParam );
extern HB_EXPORT void      hb_sfFont_ret( sfFont * );

/* Graphics/sfImage */
extern HB_EXPORT sfImage *  hb_sfImageItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM   hb_sfImageItemPut( PHB_ITEM pItem, sfImage * pSfImage );
extern HB_EXPORT sfImage *  hb_sfImage_param( int iParam );
extern HB_EXPORT void       hb_sfImage_ret( sfImage * );

/* Graphics/sfRectangleShape */
extern HB_EXPORT sfRectangleShape *  hb_sfRectangleShapeItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM            hb_sfRectangleShapeItemPut( PHB_ITEM pItem, sfRectangleShape * pSfRectangleShape );
extern HB_EXPORT sfRectangleShape *  hb_sfRectangleShape_param( int iParam );
extern HB_EXPORT void                hb_sfRectangleShape_ret( sfRectangleShape * );

/* Graphics/sfRenderTexture */
extern HB_EXPORT sfRenderTexture *  hb_sfRenderTextureItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM           hb_sfRenderTextureItemPut( PHB_ITEM pItem, sfRenderTexture * pSfRenderTexture );
extern HB_EXPORT sfRenderTexture *  hb_sfRenderTexture_param( int iParam );
extern HB_EXPORT void               hb_sfRenderTexture_ret( sfRenderTexture * );

/* Graphics/sfRenderWindow */
extern HB_EXPORT sfRenderWindow *  hb_sfRenderWindowItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM          hb_sfRenderWindowItemPut( PHB_ITEM pItem, sfRenderWindow * pSfRenderWindow );
extern HB_EXPORT sfRenderWindow *  hb_sfRenderWindow_param( int iParam );
extern HB_EXPORT void              hb_sfRenderWindow_ret( sfRenderWindow * );

/* Graphics/sfShader */
extern HB_EXPORT sfShader *  hb_sfShaderItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM    hb_sfShaderItemPut( PHB_ITEM pItem, sfShader * pSfShader );
extern HB_EXPORT sfShader *  hb_sfShader_param( int iParam );
extern HB_EXPORT void        hb_sfShader_ret( sfShader * );

/* Graphics/sfShape */
extern HB_EXPORT sfShape *  hb_sfShapeItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM   hb_sfShapeItemPut( PHB_ITEM pItem, sfShape * pSfShape );
extern HB_EXPORT sfShape *  hb_sfShape_param( int iParam );
extern HB_EXPORT void       hb_sfShape_ret( sfShape * );

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

/* Graphics/sfTransformable */
extern HB_EXPORT sfTransformable *  hb_sfTransformableItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM           hb_sfTransformableItemPut( PHB_ITEM pItem, sfTransformable * pSfTransformable );
extern HB_EXPORT sfTransformable *  hb_sfTransformable_param( int iParam );
extern HB_EXPORT void               hb_sfTransformable_ret( sfTransformable * );

/* Graphics/sfVertexArray */
extern HB_EXPORT sfVertexArray *  hb_sfVertexArrayItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM         hb_sfVertexArrayItemPut( PHB_ITEM pItem, sfVertexArray * pSfVertexArray );
extern HB_EXPORT sfVertexArray *  hb_sfVertexArray_param( int iParam );
extern HB_EXPORT void             hb_sfVertexArray_ret( sfVertexArray * );

/* Graphics/sfVertexBuffer */
extern HB_EXPORT sfVertexBuffer *  hb_sfVertexBufferItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM          hb_sfVertexBufferItemPut( PHB_ITEM pItem, sfVertexBuffer * pSfVertexBuffer );
extern HB_EXPORT sfVertexBuffer *  hb_sfVertexBuffer_param( int iParam );
extern HB_EXPORT void              hb_sfVertexBuffer_ret( sfVertexBuffer * );

/* Graphics/sfView */
extern HB_EXPORT sfView *  hb_sfViewItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM  hb_sfViewItemPut( PHB_ITEM pItem, sfView * pSfView );
extern HB_EXPORT sfView *  hb_sfView_param( int iParam );
extern HB_EXPORT void      hb_sfView_ret( sfView * );

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/* Network/sfFtpDirectoryResponse */
extern HB_EXPORT sfFtpDirectoryResponse *  hb_sfFtpDirectoryResponseItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM                  hb_sfFtpDirectoryResponseItemPut( PHB_ITEM pItem, sfFtpDirectoryResponse * pSfFtpDirectoryResponse );
extern HB_EXPORT sfFtpDirectoryResponse *  hb_sfFtpDirectoryResponse_param( int iParam );
extern HB_EXPORT void                      hb_sfFtpDirectoryResponse_ret( sfFtpDirectoryResponse * );

/* Network/sfHttpRequest */
extern HB_EXPORT sfHttpRequest *  hb_sfHttpRequestItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM         hb_sfHttpRequestItemPut( PHB_ITEM pItem, sfHttpRequest * pSfHttpRequest );
extern HB_EXPORT sfHttpRequest *  hb_sfHttpRequest_param( int iParam );
extern HB_EXPORT void             hb_sfHttpRequest_ret( sfHttpRequest * );

/* Network/sfPacket */
extern HB_EXPORT sfPacket *  hb_sfPacketItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM    hb_sfPacketItemPut( PHB_ITEM pItem, sfPacket * pSfPacket );
extern HB_EXPORT sfPacket *  hb_sfPacket_param( int iParam );
extern HB_EXPORT void        hb_sfPacket_ret( sfPacket * );

/* Network/sfSocketSelector */
extern HB_EXPORT sfSocketSelector *  hb_sfSocketSelectorItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM            hb_sfSocketSelectorItemPut( PHB_ITEM pItem, sfSocketSelector * pSfSocketSelector );
extern HB_EXPORT sfSocketSelector *  hb_sfSocketSelector_param( int iParam );
extern HB_EXPORT void                hb_sfSocketSelector_ret( sfSocketSelector * );

/* Network/sfTcpListener */
extern HB_EXPORT sfTcpListener *  hb_sfTcpListenerItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM         hb_sfTcpListenerItemPut( PHB_ITEM pItem, sfTcpListener * pSfTcpListener );
extern HB_EXPORT sfTcpListener *  hb_sfTcpListener_param( int iParam );
extern HB_EXPORT void             hb_sfTcpListener_ret( sfTcpListener * );

/* Network/sfTcpSocket */
extern HB_EXPORT sfTcpSocket *  hb_sfTcpSocketItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM       hb_sfTcpSocketItemPut( PHB_ITEM pItem, sfTcpSocket * pSfTcpSocket );
extern HB_EXPORT sfTcpSocket *  hb_sfTcpSocket_param( int iParam );
extern HB_EXPORT void           hb_sfTcpSocket_ret( sfTcpSocket * );

/* Network/sfUdpSocket */
extern HB_EXPORT sfUdpSocket *  hb_sfUdpSocketItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM       hb_sfUdpSocketItemPut( PHB_ITEM pItem, sfUdpSocket * pSfUdpSocket );
extern HB_EXPORT sfUdpSocket *  hb_sfUdpSocket_param( int iParam );
extern HB_EXPORT void           hb_sfUdpSocket_ret( sfUdpSocket * );

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/* System/sfClock */
extern HB_EXPORT sfClock *  hb_sfClockItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM   hb_sfClockItemPut( PHB_ITEM pItem, sfClock * pSfClock );
extern HB_EXPORT sfClock *  hb_sfClock_param( int iParam );
extern HB_EXPORT void       hb_sfClock_ret( sfClock * );

/* System/sfMutex */
extern HB_EXPORT sfMutex *  hb_sfMutexItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM   hb_sfMutexItemPut( PHB_ITEM pItem, sfMutex * pSfMutex );
extern HB_EXPORT sfMutex *  hb_sfMutex_param( int iParam );
extern HB_EXPORT void       hb_sfMutex_ret( sfMutex * );

/* System/sfThread */
extern HB_EXPORT sfThread *  hb_sfThreadItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM    hb_sfThreadItemPut( PHB_ITEM pItem, sfThread * pSfThread );
extern HB_EXPORT sfThread *  hb_sfThread_param( int iParam );
extern HB_EXPORT void        hb_sfThread_ret( sfThread * );

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
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

/* Window/sfEvent */
extern HB_EXPORT sfEvent *  hb_sfEventItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM   hb_sfEventItemPut( PHB_ITEM pItem, sfEvent * pSfEvent );
extern HB_EXPORT sfEvent *  hb_sfEvent_param( int iParam );
extern HB_EXPORT void       hb_sfEvent_ret( sfEvent * );

/* Window/sfWindow */
extern HB_EXPORT sfWindow *  hb_sfWindowItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM    hb_sfWindowItemPut( PHB_ITEM pItem, sfWindow * pSfWindow );
extern HB_EXPORT sfWindow *  hb_sfWindow_param( int iParam );
extern HB_EXPORT void        hb_sfWindow_ret( sfWindow * );

HB_EXTERN_END

#endif /* HB_SFML_H_ */
