/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __IEWGET_COMMON_H_
#define __IEWGET_COMMON_H_

extern BOOL fsOnNavigateUrl (LPCSTR pszUrl);

extern BOOL fsUrlToFdm (LPCSTR pszUrl, LPCSTR pszReferer, LPCSTR pszCookies, LPCSTR pszPostData, BOOL bUseSkipExtsList);

extern BOOL fsIsMonitoringTurnedOn ();

extern BOOL fsIsOKUrl (LPCSTR pszURL);

#endif