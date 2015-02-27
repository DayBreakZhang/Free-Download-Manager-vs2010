/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "Iefdmdm.h"
#include "IEWGDM.h"
#include <shlguid.h>
#include "vmsIETmpCookies.h"
#include "vmsBindStatusCallback.h"
#include "DlgDownloading.h"
#include "resource.h"
#include "vmsIeLock.h"
#include "vmsHttpHelper.h"
#include "..\..\FDM.h"
#include "vmsIeHKCU.h"

_COM_SMARTPTR_TYPEDEF(IFdmUiWindow, __uuidof(IFdmUiWindow));

BOOL fsIsMonitoringTurnedOn ()
{
	CRegKey key;
	if (ERROR_SUCCESS != key.Open (HKEY_CURRENT_USER, 
		_T ("Software\\FreeDownloadManager.ORG\\Free Download Manager\\Settings\\Monitor"), KEY_READ))
		return TRUE;
	
	DWORD dwMonitor;
	
	if (ERROR_SUCCESS != key.QueryValue (dwMonitor, _T ("IE2")))
		return TRUE;
	
	return dwMonitor;
}

BOOL fsOnNavigateUrl (LPCWSTR pwszUrl)
{
	BOOL bALT = GetKeyState (VK_MENU) & 0x8000;
	BOOL bCTRL = GetKeyState (VK_CONTROL) & 0x8000;
	
	
	if (bCTRL && bALT)
		return TRUE;
	
	CRegKey wgKey;
	
	DWORD bALTShouldPressed = FALSE;
	
	if (ERROR_SUCCESS == wgKey.Open (HKEY_CURRENT_USER, 
			_T ("Software\\FreeDownloadManager.ORG\\Free Download Manager\\Settings\\Monitor"),
			KEY_READ))
		wgKey.QueryValue (bALTShouldPressed, _T ("ALTShouldPressed"));
	
	
	if (bALT == FALSE && bALTShouldPressed)
		return FALSE; 
	
	return TRUE;
}

BOOL fsFileNameFromUrlPath (LPCSTR pszUrl, BOOL bUsingFTP, BOOL bDecode, LPSTR pszBuf, UINT uSize)
{
	*pszBuf = 0;
	
	int len = strlen (pszUrl);
	int pos;
	
	if (len == 0)
		return TRUE;
	
	int end = bUsingFTP ? strlen (pszUrl)-1 : strcspn (pszUrl, "?=#") - 1;
	
	if (end < 0)
		return FALSE;
	
	if (end >= len)
		end = len - 1;
	
	pos = end;
	
	while (pos && pszUrl [pos] != '/' && pszUrl [pos] != '\\')
		pos--;
	
	if (pszUrl [pos] != '/' && pszUrl [pos] != '\\')
		return FALSE;
	
	if (UINT(len - pos) > uSize)
		return FALSE;
	
	strcpy (pszBuf, pszUrl + pos + 1);
	
	pszBuf [end - pos] = 0;
	
	return TRUE;
}

LPCSTR strcmp_m (LPCSTR pszWhere, LPCSTR pszWhat)
{
	if (*pszWhere == 0)
		return *pszWhat == 0 ? pszWhere : NULL;
	
	if (*pszWhat == 0)
		return NULL;
	
	if (*pszWhat == '*')
	{
		if (pszWhat [1] == 0)
			return pszWhere;
		
		
		
		LPCSTR psz = strcmp_m (pszWhere, pszWhat+1);
		if (psz)
			return psz;
		
		
		return strcmp_m (pszWhere+1, pszWhat);
	}
	
	if (*pszWhat != '?')
	{
		if (*pszWhere != *pszWhat)
			return NULL;
	}
	
	return strcmp_m (pszWhere+1, pszWhat+1) ? pszWhere : NULL;
}

LPCSTR strcmpi_m (LPCSTR pszWhere, LPCSTR pszWhat)
{
	char *psz1 = new char [strlen (pszWhere) + 1];
	char *psz2 = new char [strlen (pszWhat) + 1];
	
	strcpy (psz1, pszWhere);
	strcpy (psz2, pszWhat);
	
	CharLowerA (psz1);
	CharLowerA (psz2);
	
	LPCSTR psz = strcmp_m (psz1, psz2);
	LPCSTR pszRet = NULL;
	if (psz)
		pszRet = pszWhere + (psz - psz1);
	
	delete [] psz1;
	delete [] psz2;
	
	return pszRet;
}

BOOL IsExtStrEq (LPCSTR pszMasked, LPCSTR psz2)
{
	return strcmpi_m (psz2, pszMasked) != NULL;
	
	
}

BOOL IsExtInExtsStr (LPCSTR pszExts, LPCSTR pszExt)
{
	if (pszExt == NULL)
		return FALSE;
	
	int len = strlen (pszExts);
	int i = 0;
	CHAR szExt [10000];
	
	do
	{
		int j = 0;
		
		while (i < len && pszExts [i] != ' ')
			szExt [j++] = pszExts [i++];
		
		szExt [j] = 0;
		i++;
		
		if (IsExtStrEq (szExt, pszExt))
			return TRUE;
		
	} while (i < len);
	
	return FALSE;
}

LPCSTR Monitor_OnlyExts ()
{
static char* pszExts = "\
EXE ZIP ARJ RAR LZH Z GZ TGZ GZIP TAR BIN MP3 M4A WAV RA RAM AAC AIF AVI MPG\
MPEG QT PLJ ASF MOV RM MP4 WMA WMV MPE MPA R0* R1* A0* A1* TIF TIFF PDF MSI\
ACE ISO OGG 7Z SEA SIT SITX PPT PPS";

return pszExts;
}

LPCSTR Monitor_SkipExts ()
{
	static char szExts [10000];
	strcpy (szExts, "pls m3u");
	CRegKey wgKey;
	if (ERROR_SUCCESS == wgKey.Open (HKEY_CURRENT_USER, 
			_T ("Software\\FreeDownloadManager.ORG\\Free Download Manager\\Settings\\Monitor"),
			KEY_READ))
	{
		TCHAR tsz [sizeof (szExts)] = _T ("");
		DWORD dw = sizeof (szExts);
		if (ERROR_SUCCESS == wgKey.QueryValue (tsz, _T ("SkipExtensions"), &dw))
		{
			USES_CONVERSION;
			strcpy (szExts, T2CA (tsz));
		}
	}
	return szExts;
}

BOOL is_ExtToSkip (LPCSTR pszURL, BOOL bUseSkipExtsList)
{
	string strPath = vmsHttpHelper::ExtractPath (pszURL);
	
	if (strPath.empty () || stricmp (pszURL, "about:blank") == 0)
		return bUseSkipExtsList == FALSE;
	
	char szFile [10000];
	fsFileNameFromUrlPath (strPath.c_str (), strnicmp (pszURL, "ftp://", 6) == 0,
		TRUE, szFile, sizeof (szFile));
	
	if (*szFile == 0)
		return bUseSkipExtsList == FALSE;
	
	LPCSTR pszExt = strrchr (szFile, '.');
	if (pszExt++ == NULL) 
		return bUseSkipExtsList == FALSE;
	
	if (bUseSkipExtsList == FALSE && IsExtInExtsStr (Monitor_OnlyExts (), pszExt) == FALSE)
		return TRUE;
	
	return IsExtInExtsStr (Monitor_SkipExts (), pszExt);
}

BOOL IsServerInServersStr (LPCSTR pszServers, LPCSTR pszServer)
{
	if (pszServer == NULL)
		return FALSE;
	
	int len = strlen (pszServers);
	int i = 0;
	CHAR szServer [10000];
	
	do
	{
		int j = 0;
		
		while (i < len && pszServers [i] != ' ')
			szServer [j++] = pszServers [i++];
		
		szServer [j] = 0;
		i++;
		
		if (IsExtStrEq (szServer, pszServer))
			return TRUE;
		
		string str;
		str = "*."; str += szServer;
		if (IsExtStrEq (str.c_str (), pszServer))
			return TRUE;
		
	} while (i < len);
	
	return FALSE;
}

LPCSTR Monitor_SkipServers ()
{
	static char szServers [10000] = "";
	CRegKey wgKey;
	if (ERROR_SUCCESS == wgKey.Open (HKEY_CURRENT_USER, _T ("Software\\FreeDownloadManager.ORG\\Free Download Manager\\Settings\\Monitor"),
			KEY_READ))
	{
		TCHAR tsz [sizeof (szServers)] = _T ("");
		DWORD dw = sizeof (szServers);
		if (ERROR_SUCCESS == wgKey.QueryValue (tsz, _T ("SkipServers"), &dw))
		{
			USES_CONVERSION;
			strcpy (szServers, T2CA (tsz));
		}
	}
	return szServers;
}

BOOL is_ServerToSkip (LPCSTR psz)
{
	if (psz == NULL || *psz == 0)
		return FALSE;

	if (stricmp (psz, "about:blank") == 0)
		return FALSE;

	string strHostName;
	vmsHttpHelper::ExtractHostName (psz, strHostName);

	return IsServerInServersStr (Monitor_SkipServers (), strHostName.c_str ());
}

BOOL fsUrlToFdm (LPCSTR pszUrl, LPCSTR pszReferer, LPCSTR pszCookies, LPCSTR pszPostData, BOOL bUseSkipExtsList, LPCSTR pszOriginalURL, LPCSTR pszUserAgent)
{
	if (is_ServerToSkip (pszUrl))
		return FALSE;
	
	if (pszReferer && is_ServerToSkip (pszReferer))
		return FALSE;
	
	if (is_ExtToSkip (pszUrl, bUseSkipExtsList))
		return FALSE;
	
	string strHost;
	vmsHttpHelper::ExtractHostName (pszUrl, strHost);
	if (strHost.empty ())
		return FALSE;
	if (stricmp (strHost.c_str (), "megashares.com") == 0 ||
		(strHost.length () > sizeof ("megashares.com") && stricmp (strHost.c_str ()+strHost.length ()-sizeof("megashares.com"), ".megashares.com") == 0))
	{
		pszReferer = "";
	}
	
	
	IWGUrlReceiver* wg;
	HRESULT hr;
	if (FAILED (hr = CoCreateInstance (CLSID_WGUrlReceiver, NULL, CLSCTX_ALL, IID_IWGUrlReceiver, (void**) &wg)))
	{
		TCHAR tszMsg [1000];
		_tcscpy (tszMsg, _T ("Free Download Manager is not properly installed! Please reinstall Free Download Manager or try to reboot your PC.\n\nError code: 0x"));
		TCHAR tsz [100];
		_itot ((UINT)hr, tsz, 16);
		_tcscat (tszMsg, tsz);
		MessageBox (NULL, tszMsg, _T ("Error"), MB_ICONERROR);
		return FALSE;
	}
	
	wg->put_IgnoreSize (FALSE);
	
	_bstr_t url = pszUrl;
	wg->put_Url (url);
	if (pszOriginalURL && *pszOriginalURL)
		wg->put_OriginalURL (_bstr_t (pszOriginalURL));
	if (pszUserAgent && *pszUserAgent)
		wg->put_UserAgent (_bstr_t (pszUserAgent));
	if (pszCookies)
	{
		_bstr_t cookies = pszCookies;
		wg->put_Cookies (cookies);
	}
	if (pszReferer)
	{
		_bstr_t referer = pszReferer;
		wg->put_Referer (referer);
	}
	if (pszPostData)
	{
		_bstr_t ah = pszPostData;
		wg->put_PostData (ah);
	}
	wg->put_CheckExtension (FALSE);
	hr = wg->AddDownload ();
	
	if (FAILED (hr))
	{
		wg->Release ();
		return FALSE;
	}

	IServiceProviderPtr spSP (wg);
	if (spSP != NULL)
	{
		IFdmUiWindowPtr spUiWindow;
		spSP->QueryService (__uuidof (IFdmUiWindow), __uuidof (IFdmUiWindow), (void**)&spUiWindow);
		if (spUiWindow != NULL)
		{
			spUiWindow->WaitForWindowCreation (5000);
			ULONG u = 0;
			spUiWindow->get_Handle (&u);
			if (u)
			{
				SetForegroundWindow ((HWND)u);
				BringWindowToTop ((HWND)u);
			}
		}
	}
	
	CRegKey wgKey;
	if (ERROR_SUCCESS == wgKey.Open (HKEY_CURRENT_USER, _T ("Software\\FreeDownloadManager.ORG\\Free Download Manager\\Settings\\Monitor"), KEY_READ))
	{
		DWORD b = FALSE;
		if (ERROR_SUCCESS != wgKey.QueryValue (b, _T ("AllowDownload")))
			b = TRUE;
		if (b == FALSE)	
		{
			wg->Release ();
			return TRUE;
		}
	}
	
	CComBSTR bstrState;
	do {
		Sleep (10);
		wg->get_UIState (&bstrState);
	} while (bstrState == L"in_progress");
	
	wg->Release ();
	
	return bstrState == L"added";
}

#include "../UrlMonSpy/vmsUrlMonRequest.h"
#include "../../AppWinSockSniffDll/vmsHttpRequestParser.h"
#include "../../AppWinSockSniffDll/vmsHttpRequestParser.cpp"
#include "../../AppWinSockSniffDll/vmsHttpParser.cpp"

STDMETHODIMP CIEWGDM::Download(IMoniker *pmk, IBindCtx *pbc, 
	DWORD dwBindVerb, LONG grfBINDF, BINDINFO *pBindInfo, 
	LPCOLESTR pszHeaders, LPCOLESTR pszRedir, UINT uiCP)
{
	ATLASSERT (dwBindVerb == BINDVERB_GET || dwBindVerb == BINDVERB_POST);
	if (dwBindVerb != BINDVERB_GET && dwBindVerb != BINDVERB_POST)
		return E_FAIL;

	if (fsIsMonitoringTurnedOn () == FALSE)
		return E_FAIL;

	HRESULT hr;
	USES_CONVERSION;

	wstring wstrUrl;

	LPOLESTR pwsz = NULL;
	if (FAILED (hr = pmk->GetDisplayName (pbc, NULL, &pwsz)))
		return hr;
	if (!pwsz)
		return E_FAIL;
	wstrUrl = pwsz;

	IMallocPtr spMalloc;
	CoGetMalloc (1, &spMalloc);
	if (spMalloc != NULL)
		spMalloc->Free (pwsz);

	if (!fsOnNavigateUrl (wstrUrl.c_str ()))
		return E_FAIL;

	vector <BYTE> vbPostData;
	if (pBindInfo != NULL && pBindInfo->dwBindVerb == BINDVERB_POST && pBindInfo->cbstgmedData != 0)
	{
		assert (pBindInfo->stgmedData.tymed == TYMED_HGLOBAL);
		if (pBindInfo->stgmedData.tymed == TYMED_HGLOBAL)
		{
			LPVOID pData = GlobalLock (pBindInfo->stgmedData.hGlobal);
			if (pData)
			{
				vbPostData.resize (pBindInfo->cbstgmedData);
				CopyMemory (&vbPostData [0], pData, pBindInfo->cbstgmedData);
				GlobalUnlock (pBindInfo->stgmedData.hGlobal);
			}
		}
	}

	typedef vmsUrlMonRequest* (WINAPI *FNfdmumspy_findRequest) (LPCWSTR pwszUrl, LPBYTE pbPostData, DWORD dwPostDataSize, bool bInProgressOnly);
	HMODULE hDll = GetModuleHandle (_T ("fdmumsp.dll"));
	if (!hDll)
	{
		TCHAR tsz [MAX_PATH] = _T ("");
		GetModuleFileName (_Module.GetModuleInstance (), tsz, MAX_PATH);
		LPTSTR ptsz = _tcsrchr (tsz, '\\');
		if (ptsz)
		{
			_tcscpy (ptsz + 1, _T ("fdmumsp.dll"));
			hDll = LoadLibrary (tsz);
		}
	}

	FNfdmumspy_findRequest pfn = NULL;
	if (hDll)
		pfn = (FNfdmumspy_findRequest) GetProcAddress (hDll, "fdmumspy_findRequest");

	vmsUrlMonRequestPtr spRequest;
	if (pfn)
		spRequest = pfn (wstrUrl.c_str (), vbPostData.empty () ? NULL : &vbPostData[0], vbPostData.size (), true);

	string strUserAgent, strReferer, strCookies, strOriginalURL;

	if (spRequest != NULL)
	{
		spRequest->Release (); 
		vmsHttpRequestParser reqHdrs;
		reqHdrs.ParseHeader (spRequest->getRequestHeaders ());
		const vmsHttpRequestParser::HdrField *pHdr = reqHdrs.FieldByName ("Referer");
		if (pHdr)
			strReferer = pHdr->strValue;
		pHdr = reqHdrs.FieldByName ("Cookie");
		if (pHdr)
			strCookies = pHdr->strValue;
		assert (spRequest->getUrl () != NULL);
		if (wcscmp (spRequest->getUrl (), wstrUrl.c_str ()))
			strOriginalURL = W2CA (spRequest->getUrl ());
		pHdr = reqHdrs.FieldByName ("User-Agent");
		if (pHdr)
			strUserAgent = pHdr->strValue;
	}

	if (!vbPostData.empty ())
		vbPostData.push_back (0);
	
	return fsUrlToFdm (W2CA (wstrUrl.c_str ()), strReferer.c_str (),  strCookies.c_str (), 
		vbPostData.empty () ? "" : (LPCSTR)&vbPostData[0], TRUE, strOriginalURL.c_str (), strUserAgent.c_str ()) ? S_OK : E_FAIL;
		
	
	

	
}

DWORD WINAPI CIEWGDM::_threadDlgDownloading(LPVOID lp)
{
	HRESULT hrCI = CoInitialize (NULL);

	_threadDlgDownloading_param *pParam = (_threadDlgDownloading_param*)lp;
	
	CDlgDownloading *pdlg = new CDlgDownloading;
	pdlg->m_pBSC = pParam->pBSC;
		
	pdlg->Create (NULL);
	pdlg->ShowWindow (SW_SHOW);
	pdlg->BringWindowToTop ();
	SetForegroundWindow (*pdlg);

	MSG msg;
	while (GetMessage (&msg, NULL, 0, 0))
		DispatchMessage (&msg);

	delete pdlg;

	pParam->pBSC->Release ();

	vmsIeLock::Unlock ();

	if (pParam->pUnkDMstream)
	{
		IUnknown *pUnkDM = NULL;
		CoGetInterfaceAndReleaseStream (pParam->pUnkDMstream, IID_IUnknown, (void**)&pUnkDM);
		if (pUnkDM)
			pUnkDM->Release ();
	}

	delete pParam;

	if (SUCCEEDED (hrCI))
		CoUninitialize ();

	return 0;
}

bool CIEWGDM::isUseNativeIeDownloader()
{
	vmsIeHKCU key;
	if (ERROR_SUCCESS != key.Open (_T ("Software\\FreeDownloadManager.ORG\\Free Download Manager\\Settings\\Monitor"), 
			KEY_READ))
		return false;
	DWORD dw = 0;
	key.getKey ().QueryValue (dw, _T ("UseIeNativeDownloader"));
	return dw != 0;
}
