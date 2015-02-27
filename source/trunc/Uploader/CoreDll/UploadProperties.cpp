/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "uploadproperties.h"
#include "common.h"

void fsUP_GetDefaults_Free (fsUpload_Properties *p)
{
	SAFE_DELETE_ARRAY (p->pszPassword);
	SAFE_DELETE_ARRAY (p->pszProxyName);
	SAFE_DELETE_ARRAY (p->pszProxyPassword);
	SAFE_DELETE_ARRAY (p->pszProxyUserName);
	SAFE_DELETE_ARRAY (p->pszReferer);
	SAFE_DELETE_ARRAY (p->pszUserName);
	SAFE_DELETE_ARRAY (p->pszAgent);
}

void fsUP_GetByUrl_Free (fsUpload_Properties *p)
{
	fsUP_GetDefaults_Free (p);
	SAFE_DELETE_ARRAY (p->pszPathName);
	SAFE_DELETE_ARRAY (p->pszServerName);
}

void fsFillBuffer (LPSTR& psz, LPCSTR pszValue)
{
	SAFE_DELETE_ARRAY (psz);
	psz = new char [strlen (pszValue) + 1];
	strcpy (psz, pszValue);
}

void fsUP_GetDefaults (fsUpload_Properties *p)
{
	p->enAccType = (fsInternetAccessTypeEx)_pDllCaller->GetSettings ()->InternetAccessType ();
	p->dwFtpFlags = _pDllCaller->GetSettings ()->FtpFlags ();
	p->bUseHttp11 = _pDllCaller->GetSettings ()->UseHttp11 ();
	p->enFtpTransferType = (fsFtpTransferType)_pDllCaller->GetSettings ()->FtpTransferType ();
	p->bUseCookie = _pDllCaller->GetSettings ()->UseCookie ();

	fsFillBuffer (p->pszAgent, _pDllCaller->GetSettings ()->HttpAgent ());
	fsFillBuffer (p->pszPassword, "");
	fsFillBuffer (p->pszReferer, "");
	fsFillBuffer (p->pszUserName, "");
}

fsNetworkProtocol fsSchemeToNP (INTERNET_SCHEME scheme)
{
	switch (scheme)
	{
		case INTERNET_SCHEME_FTP:
			return NP_FTP;
			
		case INTERNET_SCHEME_HTTP: 
			return NP_HTTP;
			
		case INTERNET_SCHEME_HTTPS:
			return NP_HTTPS;

		case INTERNET_SCHEME_FILE:
			return NP_FILE;
	}

	ASSERT (FALSE);
	return (fsNetworkProtocol) -1;
}

fsInternetResult fsGetProxyByNP (fsUpload_Properties *p)
{
	switch (p->enProtocol)
	{
		case NP_FTP:
			fsFillBuffer (p->pszProxyName, _pDllCaller->GetSettings ()->FtpProxy_Name ());
			fsFillBuffer (p->pszProxyPassword, _pDllCaller->GetSettings ()->FtpProxy_Password ());
			fsFillBuffer (p->pszProxyUserName, _pDllCaller->GetSettings ()->FtpProxy_UserName ());
			break;
			
		case NP_HTTP: 
			fsFillBuffer (p->pszProxyName, _pDllCaller->GetSettings ()->HttpProxy_Name ());
			fsFillBuffer (p->pszProxyPassword, _pDllCaller->GetSettings ()->HttpProxy_Password ());
			fsFillBuffer (p->pszProxyUserName, _pDllCaller->GetSettings ()->HttpProxy_UserName ());
			break;

		case NP_HTTPS:
			fsFillBuffer (p->pszProxyName, _pDllCaller->GetSettings ()->HttpsProxy_Name ());
			fsFillBuffer (p->pszProxyPassword, _pDllCaller->GetSettings ()->HttpsProxy_Password ());
			fsFillBuffer (p->pszProxyUserName, _pDllCaller->GetSettings ()->HttpsProxy_UserName ());
			break;

		case NP_FILE:
			fsFillBuffer (p->pszProxyName, "");
			fsFillBuffer (p->pszProxyPassword, "");
			fsFillBuffer (p->pszProxyUserName, "");
			break;
	}

	return IR_SUCCESS;
}

fsInternetResult fsUP_GetByUrl (fsUpload_Properties *p, LPCSTR pszUrl)
{
	
	fsUP_GetDefaults (p);
	
	fsURL url;
	BOOL bOk = TRUE;

	fsInternetResult ir = url.Crack (pszUrl);	
	ASSERT (ir == IR_SUCCESS);
	if (ir != IR_SUCCESS)
	{
		fsUP_GetDefaults_Free (p);
		return ir;
	}

	p->enProtocol = fsSchemeToNP (url.GetInternetScheme ());

	
	fsGetProxyByNP (p);

	p->uServerPort = url.GetPort ();

	fsFillBuffer (p->pszServerName, url.GetHostName ());
	fsFillBuffer (p->pszPathName, url.GetPath ());

	LPCSTR pszUser = url.GetUserName ();
	LPCSTR pszPass = url.GetPassword ();

	if (*pszUser)
		fsFillBuffer (p->pszUserName, pszUser);

	if (*pszPass)
		fsFillBuffer (p->pszPassword, pszPass);

	return IR_SUCCESS;
}

fsInternetResult fsUP_ApplyUrl (fsUpload_Properties *p, LPCSTR pszUrl)
{
	fsURL url;
	fsInternetResult ir;

	ir = url.Crack (pszUrl);
	if (ir != IR_SUCCESS)
		return ir;
	
	fsNetworkProtocol np = fsSchemeToNP (url.GetInternetScheme ());

	if (p->enProtocol != np)  
	{
		SAFE_DELETE_ARRAY (p->pszProxyName);
		SAFE_DELETE_ARRAY (p->pszProxyUserName);
		SAFE_DELETE_ARRAY (p->pszProxyPassword);

		p->enProtocol = np;

		fsGetProxyByNP (p);
	}

	p->uServerPort = url.GetPort ();

	SAFE_DELETE_ARRAY (p->pszPathName);
	p->pszPathName = new char [strlen (url.GetPath ()) + 1];
	strcpy (p->pszPathName, url.GetPath ());

	SAFE_DELETE_ARRAY (p->pszServerName);
	p->pszServerName = new char [strlen (url.GetHostName ()) + 1];
	strcpy (p->pszServerName, url.GetHostName ());

	if (*url.GetUserName ())
	{
		SAFE_DELETE_ARRAY (p->pszUserName);
		p->pszUserName = new char [strlen (url.GetUserName ()) + 1];
		strcpy (p->pszUserName, url.GetUserName ());

		SAFE_DELETE_ARRAY (p->pszPassword);
		p->pszPassword = new char [strlen (url.GetPassword ()) + 1];
		strcpy (p->pszPassword, url.GetPassword ());
	}
	else
	{
		SAFE_DELETE_ARRAY (p->pszUserName);
		p->pszUserName = new char [1];
		*p->pszUserName = 0;

		SAFE_DELETE_ARRAY (p->pszPassword);
		p->pszPassword = new char [1];
		*p->pszPassword = 0;
	}

	return IR_SUCCESS;
}
