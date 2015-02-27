/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __FS_INET_H_
#define __FS_INET_H_

#include <windows.h>
#include <wininet.h>

enum fsInternetResult
{
	IR_SUCCESS,				
	IR_S_FALSE,				
	IR_ALREADYCONNECTED,	
	IR_WININETUNKERROR,		
	IR_NOTINITIALIZED,		
	IR_LOGINFAILURE,		
	IR_FILENOTOPENED,		
	IR_BADURL,				
	IR_INVALIDPARAM,		
	IR_ERROR,				
	IR_TIMEOUT,				
	IR_CANTCONNECT,			
	IR_FILENOTFOUND,		
	IR_LOSTCONNECTION,		
	IR_NAMENOTRESOLVED,		
	IR_RANGESNOTAVAIL,		
	IR_PROXYAUTHREQ,		
	IR_WINERROR,			
	IR_NEEDREDIRECT,		
	IR_EXTERROR,			
	IR_SERVERBADREQUEST,	
	IR_SERVERUNKERROR,		
	IR_CONNECTIONABORTED,	
	IR_OUTOFMEMORY,			
	IR_S_REDIRECTED,		
	IR_INVALIDPASSWORD,		
	IR_INVALIDUSERNAME,		
	IR_NODIRECTACCESS,		
	IR_NOINTERNETCONNECTION,	
	IR_HTTPVERNOTSUP,		
	IR_BADFILESIZE,
	
	
	IR_DOUBTFUL_RANGESRESPONSE,	
	
	IR_E_NOTIMPL,
	
	IR_E_WININET_UNSUPP_RESOURCE,
};

extern fsInternetResult fsWinInetErrorToIR ();
extern fsInternetResult fsWinInetErrorToIR (DWORD dwErr);
extern fsInternetResult fsHttpStatusCodeToIR (DWORD dwStatusCode);

extern fsInternetResult fsHttpOpenPath (LPCSTR pszPath, class fsHttpConnection *pServer, class fsHttpFile *pFile, LPSTR* ppRedirectedUrl, BOOL *pbRedirInner);

extern fsInternetResult fsHttpOpenUrl (LPCSTR pszUrl, LPCSTR pszUser, LPCSTR pszPassword, class fsHttpConnection *pServer, class fsHttpFile *pFile, LPSTR* ppRedirectedUrl, BOOL *pbRedirInner);

extern BOOL fsUrlToFullUrl (LPCSTR pszUrlParent, LPCSTR pszUrlCurrent, LPSTR *ppszFullUrl);
extern fsInternetResult fsWSAErrorToIR ();

extern BOOL fsIsUrlRelative (LPCSTR pszUrl);
extern fsInternetResult fsWinErrorToIR (DWORD dwErr);
extern fsInternetResult fsWinErrorToIR ();

extern void fsRemoveWWW (LPCSTR pszUrl);

extern BOOL fsIsServersEqual (LPCSTR pszServ1, LPCSTR pszServ2, BOOL bExcludeSubDomainNameFrom2Site = FALSE);

extern fsInternetResult fsDownloadFile (class fsInternetURLFile* file, LPBYTE* ppBuf, UINT* puSize, BOOL* pbAbort);

#endif