/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsInternetSession.h"

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

extern void vmsMakeWinInetProxy (LPCSTR pszProxy, fsNetworkProtocol npConnection, fsNetworkProtocol npProxy, LPSTR pszWProxy);

fsInternetResult vmsInternetSession::Create(LPCSTR pszAgent, fsInternetAccessTypeEx enAT, LPCSTR pszProxyName, fsNetworkProtocol enProtocol)
{
	if (enAT != IATE_FIREFOXPROXY)
	{
		return fsInternetSession::Create (pszAgent, (fsInternetAccessType)enAT, pszProxyName);
	}
	else
	{
		if (1 != _pDllCaller->GetSettings ()->FirefoxSettings_Proxy_Type ())
			return fsInternetSession::Create (pszAgent, IAT_NOPROXY, "");

		LPCSTR ppszProts [] = {
			"http", "ssl", "ftp"
		};
		if (enProtocol > 2)
			enProtocol = NP_HTTP;

		CString strProxy;
		strProxy.Format ("%s:%d", 
			_pDllCaller->GetSettings ()->FirefoxSettings_Proxy_Addr (ppszProts [enProtocol]),
			_pDllCaller->GetSettings ()->FirefoxSettings_Proxy_Port (ppszProts [enProtocol]));

		char szProxy [10000];
		vmsMakeWinInetProxy (strProxy, enProtocol, enProtocol, szProxy);

		return fsInternetSession::Create (pszAgent, IAT_MANUALPROXY, szProxy);
	}
}
