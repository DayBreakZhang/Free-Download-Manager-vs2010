/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __INETUTIL_H_
#define __INETUTIL_H_

#include "downloadproperties.h"

extern BOOL fsFileNameFromUrlPath (LPCSTR pszUrl, BOOL bUsingFTP, BOOL bDecode, LPSTR pszBuf, UINT uSize);

extern BOOL fsIRToStr (fsInternetResult ir, LPSTR pszStr, UINT uMaxSize);

extern BOOL fsFilePathFromUrlPath (LPCSTR pszUrl, BOOL bUsingFTP, BOOL bDecode, LPSTR pszBuf, UINT uSize);

extern BOOL fsPathFromUrlPath (LPCSTR pszUrl, BOOL bUsingFTP, BOOL bDecode, LPSTR pszBuf, UINT uSize);

extern BOOL fsIsAnchorInUrl (LPCSTR pszFullUrl, LPSTR* ppszWithoutAnchor, LPCSTR* ppszAnchor = NULL);

extern DWORD fsNPToSiteValidFor (fsNetworkProtocol np);

extern void vmsMakeWinInetProxy (LPCSTR pszProxy, fsNetworkProtocol npConnection, fsNetworkProtocol npProxy, LPSTR pszWProxy);

extern ULONG fsGetSiteIp (LPCSTR pszSite);

extern void fsDecodeHtmlUrl (fsString &str);
extern void fsDecodeHtmlText (fsString &str);

#endif