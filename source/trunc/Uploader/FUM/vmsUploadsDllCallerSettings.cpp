/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsUploadsDllCallerSettings.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsUploadsDllCallerSettings::vmsUploadsDllCallerSettings()
{

}

vmsUploadsDllCallerSettings::~vmsUploadsDllCallerSettings()
{

}

int vmsUploadsDllCallerSettings::InternetAccessType()
{
	return _App.InternetAccessType ();
}

DWORD vmsUploadsDllCallerSettings::FtpFlags()
{
	return _App.FtpFlags ();
}

BOOL vmsUploadsDllCallerSettings::UseHttp11()
{
	return _App.UseHttp11 ();
}

int vmsUploadsDllCallerSettings::FtpTransferType()
{
	return _App.FtpTransferType ();
}

BOOL vmsUploadsDllCallerSettings::UseCookie()
{
	return _App.UseCookie ();
}

LPCSTR vmsUploadsDllCallerSettings::HttpAgent()
{
	static CString str;
	str = _App.Agent ();
	return str;
}

LPCSTR vmsUploadsDllCallerSettings::FtpAsciiExts()
{
	static CString str;
	str = _App.ASCIIExts ();
	return str;
}

LPCSTR vmsUploadsDllCallerSettings::FtpProxy_Name()
{
	static CString str;
	str = _App.FtpProxy_Name ();
	return str;
}

LPCSTR vmsUploadsDllCallerSettings::FtpProxy_Password()
{
	static CString str;
	str = _App.FtpProxy_Password ();
	return str;
}

LPCSTR vmsUploadsDllCallerSettings::FtpProxy_UserName()
{
	static CString str;
	str = _App.FtpProxy_UserName ();
	return str;
}

LPCSTR vmsUploadsDllCallerSettings::HttpProxy_Name()
{
	static CString str;
	str = _App.HttpProxy_Name ();
	return str;
}

LPCSTR vmsUploadsDllCallerSettings::HttpProxy_Password()
{
	static CString str;
	str = _App.HttpProxy_Password ();
	return str;
}

LPCSTR vmsUploadsDllCallerSettings::HttpProxy_UserName()
{
	static CString str;
	str = _App.HttpProxy_UserName ();
	return str;
}

LPCSTR vmsUploadsDllCallerSettings::HttpsProxy_Name()
{
	static CString str;
	str = _App.HttpsProxy_Name ();
	return str;
}

LPCSTR vmsUploadsDllCallerSettings::HttpsProxy_Password()
{
	static CString str;
	str = _App.HttpsProxy_Password ();
	return str;
}

LPCSTR vmsUploadsDllCallerSettings::HttpsProxy_UserName()
{
	static CString str;
	str = _App.HttpsProxy_UserName ();
	return str;
}

int vmsUploadsDllCallerSettings::FirefoxSettings_Proxy_Type()
{
	return _App.FirefoxSettings_Proxy_Type ();
}

LPCSTR vmsUploadsDllCallerSettings::FirefoxSettings_Proxy_Addr(LPCSTR pszProtocol)
{
	static CString str;
	str = _App.FirefoxSettings_Proxy_Addr (pszProtocol);
	return str;
}

int vmsUploadsDllCallerSettings::FirefoxSettings_Proxy_Port(LPCSTR pszProtocol)
{
	return _App.FirefoxSettings_Proxy_Port (pszProtocol);
}

BOOL vmsUploadsDllCallerSettings::ShowSizesInBytes()
{
	return FALSE;
}

BOOL vmsUploadsDllCallerSettings::GetSettingsByName(LPCSTR pszName, LPVOID pData, DWORD dwDataSize)
{
	return FALSE;
}
