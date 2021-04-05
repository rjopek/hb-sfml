/*
 * SFML library: Http.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

/* Network/sfHttpRequest */
static HB_GARBAGE_FUNC( hb_sfHttpRequest_destructor )
{
   sfHttpRequest ** ppSfHttpRequest = ( sfHttpRequest ** ) Cargo;

   if( *ppSfHttpRequest )
   {
      sfHttpRequest_destroy( *ppSfHttpRequest );
      *ppSfHttpRequest = NULL;
   }
}

static const HB_GC_FUNCS s_gcSfHttpRequestFuncs =
{
   hb_sfHttpRequest_destructor,
   hb_gcDummyMark
};

sfHttpRequest * hb_sfHttpRequestItemGet( PHB_ITEM pItem )
{
   sfHttpRequest ** ppSfHttpRequest = ( sfHttpRequest ** ) hb_itemGetPtrGC( pItem, &s_gcSfHttpRequestFuncs );

   return ppSfHttpRequest ? *ppSfHttpRequest : NULL;
}

PHB_ITEM hb_sfHttpRequestItemPut( PHB_ITEM pItem, sfHttpRequest * pSfHttpRequest )
{
   sfHttpRequest ** ppSfHttpRequest = ( sfHttpRequest ** ) hb_gcAllocate( sizeof( sfHttpRequest * ), &s_gcSfHttpRequestFuncs );

   *ppSfHttpRequest = pSfHttpRequest;
   return hb_itemPutPtrGC( pItem, ppSfHttpRequest );
}

sfHttpRequest * hb_sfHttpRequest_param( int iParam )
{
   sfHttpRequest ** ppSfHttpRequest = ( sfHttpRequest ** ) hb_parptrGC( &s_gcSfHttpRequestFuncs, iParam );

   if( ppSfHttpRequest && *ppSfHttpRequest )
   {
      return *ppSfHttpRequest;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      return NULL;
   }
}

void hb_sfHttpRequest_ret( sfHttpRequest * pSfHttpRequest )
{
   hb_sfHttpRequestItemPut( hb_stackReturnItem(), pSfHttpRequest );
}

// sfHttpRequest* sfHttpRequest_create(void);

// void sfHttpRequest_destroy(sfHttpRequest* httpRequest);
HB_FUNC( SFHTTPREQUEST_DESTROY )
{
   sfHttpRequest ** ppSfHttpRequest = ( sfHttpRequest ** ) hb_parptrGC( &s_gcSfHttpRequestFuncs, 1 );

   if( ppSfHttpRequest && *ppSfHttpRequest )
   {
      sfHttpRequest_destroy( *ppSfHttpRequest );
      *ppSfHttpRequest = NULL;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfHttpRequest_setField(sfHttpRequest* httpRequest, const char* field, const char* value);

// void sfHttpRequest_setMethod(sfHttpRequest* httpRequest, sfHttpMethod method);

// void sfHttpRequest_setUri(sfHttpRequest* httpRequest, const char* uri);

// void sfHttpRequest_setHttpVersion(sfHttpRequest* httpRequest, unsigned int major, unsigned int minor);

// void sfHttpRequest_setBody(sfHttpRequest* httpRequest, const char* body);

// void sfHttpResponse_destroy(sfHttpResponse* httpResponse);

// const char* sfHttpResponse_getField(const sfHttpResponse* httpResponse, const char* field);

// sfHttpStatus sfHttpResponse_getStatus(const sfHttpResponse* httpResponse);

// unsigned int sfHttpResponse_getMajorVersion(const sfHttpResponse* httpResponse);

// unsigned int sfHttpResponse_getMinorVersion(const sfHttpResponse* httpResponse);

// const char* sfHttpResponse_getBody(const sfHttpResponse* httpResponse);

// sfHttp* sfHttp_create(void);

// void sfHttp_destroy(sfHttp* http);

// void sfHttp_setHost(sfHttp* http, const char* host, unsigned short port);

// sfHttpResponse* sfHttp_sendRequest(sfHttp* http, const sfHttpRequest* request, sfTime timeout);
