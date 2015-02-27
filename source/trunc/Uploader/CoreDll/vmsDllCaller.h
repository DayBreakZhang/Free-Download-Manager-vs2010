/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSDLLCALLER_H__4906328A_9106_4AEC_B3A4_C37928C3303E__INCLUDED_)
#define AFX_VMSDLLCALLER_H__4906328A_9106_4AEC_B3A4_C37928C3303E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

enum vmsWhichBitmap
{
	BMP_FOR_UPLOADSMENU,
	BMP_FOR_UPLOADSMENU_D,
	BMP_FOR_TASKSLIST,
	BMP_FOR_TASKSLIST_SEL,
	BMP_FOR_LOGLIST,
};

class vmsDllCallerSettings
{
public:
	virtual int    InternetAccessType () = NULL;
	virtual DWORD  FtpFlags () = NULL;
	virtual BOOL   UseHttp11 () = NULL;
	virtual int    FtpTransferType () = NULL;
	virtual BOOL   UseCookie () = NULL;
	virtual LPCSTR HttpAgent () = NULL;
	virtual LPCSTR FtpAsciiExts () = NULL;

	virtual LPCSTR FtpProxy_Name () = NULL;
	virtual LPCSTR FtpProxy_Password () = NULL;
	virtual LPCSTR FtpProxy_UserName () = NULL;

	virtual LPCSTR HttpProxy_Name () = NULL;
	virtual LPCSTR HttpProxy_Password () = NULL;
	virtual LPCSTR HttpProxy_UserName () = NULL;

	virtual LPCSTR HttpsProxy_Name () = NULL;
	virtual LPCSTR HttpsProxy_Password () = NULL;
	virtual LPCSTR HttpsProxy_UserName () = NULL;

	virtual BOOL   ShowSizesInBytes () = NULL;

	virtual int    FirefoxSettings_Proxy_Type () = NULL;
	virtual LPCSTR FirefoxSettings_Proxy_Addr (LPCSTR pszProtocol) = NULL;
	virtual int    FirefoxSettings_Proxy_Port (LPCSTR pszProtocol) = NULL;

	
	virtual BOOL   GetSettingsByName (LPCSTR pszName, LPVOID pData, DWORD dwDataSize) = NULL;
};

class vmsDllPersist
{
public:
	virtual BOOL GetProfileString (LPCSTR pszSecion, LPCSTR pszName, LPCSTR pszDefValue, LPSTR pszValue, DWORD *pdwValueSize) = NULL;
	virtual void WriteProfileString (LPCSTR pszSecion, LPCSTR pszName, LPCSTR pszValue) = NULL;
	virtual UINT GetProfileInt (LPCSTR pszSecion, LPCSTR pszName, UINT nDefValue) = NULL;
	virtual void WriteProfileInt (LPCSTR pszSecion, LPCSTR pszName, UINT nValue) = NULL;
	virtual BOOL GetProfileBinary (LPCSTR pszSecion, LPCSTR pszName, LPBYTE *ppData, UINT *pnDataSize) = NULL;
	virtual void WriteProfileBinary (LPCSTR pszSection, LPCSTR pszName, LPVOID pvData, UINT nDataSize) = NULL;

	virtual void FreeBuffer (LPBYTE pb) = NULL;
};

class vmsDllCallerEx
{
};

class vmsDllCaller  
{
public:
	virtual LPCSTR GetTranslatedString (int nId) = NULL;
	
	virtual vmsDllCallerSettings* GetSettings () = NULL;
	virtual vmsDllPersist* GetPersist () = NULL;
	
	
	virtual void IRToStr (int ir, char *sz, UINT cch) = NULL;
	
	virtual HBITMAP GetBitmap (vmsWhichBitmap) = NULL;

	
	
	
	
	
	
	
	
	virtual BOOL OnBeforeUpload (LPSTR pszStopReason, bool* pbNeedStop) = NULL;

	
	
	virtual void GetDataFilePath (LPCSTR pszName, LPSTR pszResult) = NULL;

	
	virtual void GetCommonFilesFolder (LPSTR pszResult) = NULL;

	virtual vmsDllCallerEx* GetExtendedFeatures () = NULL;
};

#endif 
