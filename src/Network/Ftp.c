/*
 * SFML library: Ftp.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

/* Network/sfFtpDirectoryResponse */
static HB_GARBAGE_FUNC( hb_sfFtpDirectoryResponse_destructor )
{
   sfFtpDirectoryResponse ** ppSfFtpDirectoryRespons = ( sfFtpDirectoryResponse ** ) Cargo;

   if( *ppSfFtpDirectoryRespons )
   {
      sfFtpDirectoryResponse_destroy( *ppSfFtpDirectoryRespons );
      *ppSfFtpDirectoryRespons = NULL;
   }
}

static const HB_GC_FUNCS s_gcSfFtpDirectoryResponseFuncs =
{
   hb_sfFtpDirectoryResponse_destructor,
   hb_gcDummyMark
};

sfFtpDirectoryResponse * hb_sfFtpDirectoryResponseItemGet( PHB_ITEM pItem )
{
   sfFtpDirectoryResponse ** ppSfFtpDirectoryRespons = ( sfFtpDirectoryResponse ** ) hb_itemGetPtrGC( pItem, &s_gcSfFtpDirectoryResponseFuncs );

   return ppSfFtpDirectoryRespons ? *ppSfFtpDirectoryRespons : NULL;
}

PHB_ITEM hb_sfFtpDirectoryResponseItemPut( PHB_ITEM pItem, sfFtpDirectoryResponse * pSfFtpDirectoryResponse )
{
   sfFtpDirectoryResponse ** ppSfFtpDirectoryRespons = ( sfFtpDirectoryResponse ** ) hb_gcAllocate( sizeof( sfFtpDirectoryResponse * ), &s_gcSfFtpDirectoryResponseFuncs );

   *ppSfFtpDirectoryRespons = pSfFtpDirectoryResponse;
   return hb_itemPutPtrGC( pItem, ppSfFtpDirectoryRespons );
}

sfFtpDirectoryResponse * hb_sfFtpDirectoryResponse_param( int iParam )
{
   sfFtpDirectoryResponse ** ppSfFtpDirectoryRespons = ( sfFtpDirectoryResponse ** ) hb_parptrGC( &s_gcSfFtpDirectoryResponseFuncs, iParam );

   if( ppSfFtpDirectoryRespons && *ppSfFtpDirectoryRespons )
   {
      return *ppSfFtpDirectoryRespons;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      return NULL;
   }
}

void hb_sfFtpDirectoryResponse_ret( sfFtpDirectoryResponse * pSfFtpDirectoryResponse )
{
   hb_sfFtpDirectoryResponseItemPut( hb_stackReturnItem(), pSfFtpDirectoryResponse );
}

// void sfFtpListingResponse_destroy(sfFtpListingResponse* ftpListingResponse);
HB_FUNC( SFFTPDIRECTORYRESPONSE_DESTROY )
{
   sfFtpDirectoryResponse ** ppSfFtpDirectoryRespons = ( sfFtpDirectoryResponse ** ) hb_parptrGC( &s_gcSfFtpDirectoryResponseFuncs, 1 );

   if( ppSfFtpDirectoryRespons && *ppSfFtpDirectoryRespons )
   {
      sfFtpDirectoryResponse_destroy( *ppSfFtpDirectoryRespons );
      *ppSfFtpDirectoryRespons = NULL;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// sfBool sfFtpListingResponse_isOk(const sfFtpListingResponse* ftpListingResponse);

// sfFtpStatus sfFtpListingResponse_getStatus(const sfFtpListingResponse* ftpListingResponse);

// const char* sfFtpListingResponse_getMessage(const sfFtpListingResponse* ftpListingResponse);

// size_t sfFtpListingResponse_getCount(const sfFtpListingResponse* ftpListingResponse);

// const char* sfFtpListingResponse_getName(const sfFtpListingResponse* ftpListingResponse, size_t index);

// void sfFtpDirectoryResponse_destroy(sfFtpDirectoryResponse* ftpDirectoryResponse);

// sfBool sfFtpDirectoryResponse_isOk(const sfFtpDirectoryResponse* ftpDirectoryResponse);

// sfFtpStatus sfFtpDirectoryResponse_getStatus(const sfFtpDirectoryResponse* ftpDirectoryResponse);

// const char* sfFtpDirectoryResponse_getMessage(const sfFtpDirectoryResponse* ftpDirectoryResponse);

// const char* sfFtpDirectoryResponse_getDirectory(const sfFtpDirectoryResponse* ftpDirectoryResponse);

// void sfFtpResponse_destroy(sfFtpResponse* ftpResponse);

// sfBool sfFtpResponse_isOk(const sfFtpResponse* ftpResponse);

// sfFtpStatus sfFtpResponse_getStatus(const sfFtpResponse* ftpResponse);

// const char* sfFtpResponse_getMessage(const sfFtpResponse* ftpResponse);

// sfFtp* sfFtp_create(void);

// void sfFtp_destroy(sfFtp* ftp);

// sfFtpResponse* sfFtp_connect(sfFtp* ftp, sfIpAddress server, unsigned short port, sfTime timeout);

// sfFtpResponse* sfFtp_loginAnonymous(sfFtp* ftp);

// sfFtpResponse* sfFtp_login(sfFtp* ftp, const char* name, const char* password);

// sfFtpResponse* sfFtp_disconnect(sfFtp* ftp);

// sfFtpResponse* sfFtp_keepAlive(sfFtp* ftp);

// sfFtpDirectoryResponse* sfFtp_getWorkingDirectory(sfFtp* ftp);

// sfFtpListingResponse* sfFtp_getDirectoryListing(sfFtp* ftp, const char* directory);

// sfFtpResponse* sfFtp_changeDirectory(sfFtp* ftp, const char* directory);

// sfFtpResponse* sfFtp_parentDirectory(sfFtp* ftp);

// sfFtpResponse* sfFtp_createDirectory(sfFtp* ftp, const char* name);

// sfFtpResponse* sfFtp_deleteDirectory(sfFtp* ftp, const char* name);

// sfFtpResponse* sfFtp_renameFile(sfFtp* ftp, const char* file, const char* newName);

// sfFtpResponse* sfFtp_deleteFile(sfFtp* ftp, const char* name);

// sfFtpResponse* sfFtp_download(sfFtp* ftp, const char* remoteFile, const char* localPath, sfFtpTransferMode mode);

// sfFtpResponse* sfFtp_upload(sfFtp* ftp, const char* localFile, const char* remotePath, sfFtpTransferMode mode, sfBool append);

// sfFtpResponse* sfFtp_sendCommand(sfFtp* ftp, const char* command, const char* parameter);
