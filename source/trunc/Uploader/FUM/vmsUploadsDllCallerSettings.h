/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSUPLOADSDLLCALLERSETTINGS_H__45BF1D8A_6AF4_4958_80D8_EAEA14634588__INCLUDED_)
#define AFX_VMSUPLOADSDLLCALLERSETTINGS_H__45BF1D8A_6AF4_4958_80D8_EAEA14634588__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "..\CoreDll\dll.h"

class vmsUploadsDllCallerSettings : public vmsUploadsDll::vmsDllCallerSettings
{
public:
	BOOL GetSettingsByName (LPCSTR pszName, LPVOID pData, DWORD dwDataSize);
	int FirefoxSettings_Proxy_Port (LPCSTR pszProtocol);
	LPCSTR FirefoxSettings_Proxy_Addr (LPCSTR pszProtocol);
	int FirefoxSettings_Proxy_Type();
	BOOL ShowSizesInBytes();
	LPCSTR HttpProxy_UserName();
	LPCSTR HttpProxy_Password();
	LPCSTR HttpProxy_Name();
	LPCSTR HttpsProxy_UserName();
	LPCSTR HttpsProxy_Password();
	LPCSTR HttpsProxy_Name();
	LPCSTR FtpProxy_UserName();
	LPCSTR FtpProxy_Password();
	LPCSTR FtpProxy_Name();
	LPCSTR FtpAsciiExts();
	LPCSTR HttpAgent();
	BOOL UseCookie();
	int FtpTransferType();
	BOOL UseHttp11();
	DWORD FtpFlags();
	virtual int InternetAccessType();
	vmsUploadsDllCallerSettings();
	virtual ~vmsUploadsDllCallerSettings();

};

#endif 
