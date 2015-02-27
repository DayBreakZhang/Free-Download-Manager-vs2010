/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __UPLOADPROPERTIES_H_
#define __UPLOADPROPERTIES_H_

#include "../../inetfile/inetfile.h"

enum fsNetworkProtocol
{
	NP_HTTP,
	NP_HTTPS,
	NP_FTP,
	NP_FILE
};

#define FTP_USEPASSIVEMODE			1

#define FTP_DONTSENDLIST			2

enum fsInternetAccessTypeEx	
{
	IATE_NOPROXY		= IAT_NOPROXY,			
	IATE_PRECONFIGPROXY	= IAT_PRECONFIGPROXY,	
	IATE_MANUALPROXY	= IAT_MANUALPROXY,		
	IATE_FIREFOXPROXY,							
};

struct fsUpload_NetworkProperties
{
	
	fsInternetAccessTypeEx enAccType;	
	LPSTR pszProxyName;		
	LPSTR pszProxyUserName;	
	LPSTR pszProxyPassword;	

	
	fsNetworkProtocol enProtocol;	
	LPSTR pszServerName;	
	INTERNET_PORT  uServerPort;	
	LPSTR pszUserName;	
	LPSTR pszPassword;

	
	LPSTR pszPathName;	

	
	LPSTR pszAgent;		
	BOOL  bUseHttp11;	
	LPSTR pszReferer;	
	BOOL  bUseCookie;	

	
	DWORD dwFtpFlags;	
	fsFtpTransferType enFtpTransferType;	

	UINT uTimeout;
};

struct fsUpload_Properties : public fsUpload_NetworkProperties
{
	UINT uMaxErrRetries;
	UINT uPauseBetweenAttempts;	
	fsString strFileName;
};

extern void fsUP_GetByUrl_Free (fsUpload_Properties *p);
extern void fsUP_GetDefaults_Free (fsUpload_Properties *p);
extern fsInternetResult fsUP_GetByUrl (fsUpload_Properties *p, LPCSTR pszUrl);
extern fsInternetResult fsUP_ApplyUrl (fsUpload_Properties *p, LPCSTR pszUrl);

#endif 