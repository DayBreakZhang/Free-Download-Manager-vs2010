/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsInternetSession.h"
#include "inetutil.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsInternetSession::vmsInternetSession()
{

}

vmsInternetSession::~vmsInternetSession()
{

}

fsInternetResult vmsInternetSession::Create(LPCSTR pszAgent, fsInternetAccessTypeEx enAT, LPCSTR pszProxyName, fsNetworkProtocol enProtocol)
{
#ifndef FDM_DLDR__RAWCODEONLY
	if (enAT != IATE_FIREFOXPROXY)
	{
		return fsInternetSession::Create (pszAgent, (fsInternetAccessType)enAT, pszProxyName);
	}
	else
	{
		
		if (1 != _App.FirefoxSettings_Proxy_Type ())
			return fsInternetSession::Create (pszAgent, IAT_NOPROXY, "");

		LPCSTR ppszProts [] = {
			"http", "ssl", "ftp"
		};
		if (enProtocol > 2)
			enProtocol = NP_HTTP;

		CString strProxy;
		strProxy.Format ("%s:%d", 
			_App.FirefoxSettings_Proxy_Addr (ppszProts [enProtocol]),
			_App.FirefoxSettings_Proxy_Port (ppszProts [enProtocol]));

		char szProxy [10000];
		vmsMakeWinInetProxy (strProxy, enProtocol, enProtocol, szProxy);

		return fsInternetSession::Create (pszAgent, IAT_MANUALPROXY, szProxy);
	}
#else
	return fsInternetSession::Create (pszAgent, (fsInternetAccessType)enAT, pszProxyName);
#endif
}
