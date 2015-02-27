/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "FDMForFirefox.h"
#include <windows.h>
#include "vmsFirefoxExtensionInstaller.h"
#include "FDMUrlReceiver.h"
#include <assert.h>
#include <atlbase.h>
#include <fsString.h>
#include <nsmemory.h>
#include "vmsFdmTranslations.h"
#include "vmsFlvSniffDll.h"
#include "vmsWaitDlg.h"
#include "resource.h"
#include "xrfix.h"
#include "vmsHttpRedirectList.h"

#if defined (_UNICODE) || defined (UNICODE)
#define tstring std::wstring
#else 
#define tstring std::string
#endif

#ifdef _DEBUG
#define SCL_ENABLE
#endif

#include "vmsSourceCodeLogger.h"

SCL_INITOBJECT (_T ("vmsfdmff"), 0);

_COM_SMARTPTR_TYPEDEF(IFDMFlashVideoDownloads, __uuidof(IFDMFlashVideoDownloads));
_COM_SMARTPTR_TYPEDEF(IFdmUiWindow, __uuidof(IFdmUiWindow));

#define FLASHGOT_CID	"{19503e42-ca3c-4c27-b1e2-9cdb2170ee34}"

XRFIX_NS_IMPL_ISUPPORTS1 (CFDMForFirefox, IFDMForFirefox, IFDMFORFIREFOX_IID)

CFDMForFirefox::CFDMForFirefox()
{
	m_keyFDM.Open (HKEY_CURRENT_USER, 
		"Software\\FreeDownloadManager.ORG\\Free Download Manager");

	m_keyFDMMonitor.Open (m_keyFDM,	"Settings\\Monitor", KEY_READ);

	
	
	if (ERROR_SUCCESS != m_keyFDMFfStgs.Open (m_keyFDM, "FirefoxSettings\\Proxy"))
		m_keyFDMFfStgs.Create (m_keyFDM, "FirefoxSettings\\Proxy");

	CoInitialize (NULL);
}

CFDMForFirefox::~CFDMForFirefox()
{
  
	CoUninitialize ();
}

NS_IMETHODIMP CFDMForFirefox::GetLngString(const char *strIDString, PRUnicharIDL **_retval)
{
	*_retval = NULL;

	LPCSTR psz = NULL;
	
	if (lstrcmp (strIDString, "dllink") == 0)
	{
		psz = vmsFdmTranslations::o ().GetString (L_DLTHISIEMENU);
		if (psz == NULL || *psz == 0)
			psz = "Download with Free Download Manager";
	}

	else if (lstrcmp (strIDString, "dlall") == 0)
	{
		psz = vmsFdmTranslations::o ().GetString (L_DLALLIEMENU);
		if (psz == NULL || *psz == 0)
			psz = "Download all with Free Download Manager";
	}

	else if (lstrcmp (strIDString, "dlselected") == 0)
	{
		psz = vmsFdmTranslations::o ().GetString (L_DLSELECTEDIEMENU);
		if (psz == NULL || *psz == 0)
			psz = "Download selected with Free Download Manager";
	}

	else if (lstrcmp (strIDString, "dlvideo") == 0)
	{
		psz = vmsFdmTranslations::o ().GetString (L_DLFLASHVIDEOIEMENU);
		if (psz == NULL || *psz == 0)
			psz = "Download video with Free Download Manager";
	}

	else if (lstrcmp (strIDString, "dlbyfdm") == 0)
	{
		psz = vmsFdmTranslations::o ().GetString (L_DLBYFDM);
		if (psz == NULL || *psz == 0)
			psz = "Download by FDM";
	}

	else if (lstrcmp (strIDString, "showthisbtn") == 0)
	{
		psz = vmsFdmTranslations::o ().GetString (L_SHOW_THIS_BUTTON);
		if (psz == NULL || *psz == 0)
			psz = "Show This Button";
	}

	if (psz && *psz)
	{
		*_retval = (PRUnicharIDL*) nsMemory::Clone (CA2WEX <128> (psz), 
			(lstrlen (psz)+1) * sizeof (wchar_t));
	}

	return NS_OK;
}

NS_IMETHODIMP CFDMForFirefox::IsContextMenuItemShouldBeHidden(const char *strMenuItemID, XULSDK_PRBool *_retval)
{
	if (is_FlashGotInstalled ())
	{
		*_retval = TRUE;
		return NS_OK;
	}

	CRegKey key;

	

	key.Open (m_keyFDM, "Settings\\Monitor\\IEMenu", KEY_READ);

	DWORD dwShow = TRUE;

	HANDLE hmx = CreateMutex (NULL, FALSE, "mx::fdm: brmenu_disable");
	if (GetLastError () == ERROR_ALREADY_EXISTS)
		dwShow = FALSE;
	else
		key.QueryValue (dwShow, "Enable");
	CloseHandle (hmx);
	
	if (dwShow)
	{
		fsString strMxName, strValName;

		if (lstrcmp (strMenuItemID, "dllink") == 0)
		{
			strValName = "DLThis";
			strMxName = "mx::fdm: dllink_disable";
		}

		else if (lstrcmp (strMenuItemID, "dlall") == 0)
		{
			strValName = "DLAll";
			strMxName = "mx::fdm: dlall_disable";
		}

		else if (lstrcmp (strMenuItemID, "dlselected") == 0)
		{
			strValName = "DLSelected";
			strMxName = "mx::fdm: dlselected_disable";
		}

		else if (lstrcmp (strMenuItemID, "dlvideo") == 0)
		{
			strValName = "DLFlashVideo";
			strMxName = "mx::fdm: dlvideo_disable";
		}

		HANDLE hmx = CreateMutex (NULL, FALSE, strMxName);
		if (GetLastError () == ERROR_ALREADY_EXISTS)
			dwShow = FALSE;
		else
			key.QueryValue (dwShow, strValName);
		CloseHandle (hmx);
	}

	*_retval = !dwShow;

    return NS_OK;
}

bool CFDMForFirefox::is_FlashGotInstalled()
{
	static int _isInstalled = -1;
	if (_isInstalled == -1)
		_isInstalled = vmsFirefoxExtensionInstaller::IsInstalled (FLASHGOT_CID, true);
	return _isInstalled != 0;
}

NS_IMETHODIMP CFDMForFirefox::IsALTShouldBePressed(XULSDK_PRBool *_retval)
{
	if (is_FlashGotInstalled ())
	{
		*_retval = FALSE;
		return NS_OK;
	}

   	DWORD dw1 = TRUE, dw2 = FALSE;
	
	m_keyFDMMonitor.QueryValue (dw1, "Firefox");

	if (dw1)
		m_keyFDMMonitor.QueryValue (dw2, "ALTShouldPressed");

	*_retval = dw1 && dw2;

	return NS_OK;
}

NS_IMETHODIMP CFDMForFirefox::IsLinkShouldBeSkipped(IFDMUrl *url, const PRUnicharIDL *wstrSuggFileName, XULSDK_PRBool *_retval)
{
	*_retval = TRUE;

	if (is_FlashGotInstalled ())
		return NS_OK;

	DWORD dw = TRUE;

	m_keyFDMMonitor.QueryValue (dw, "Firefox");
	if (dw == FALSE)
		return NS_OK;

	dw = FALSE;
	m_keyFDMMonitor.QueryValue (dw, "ALTShouldPressed");
	if (dw)
		return NS_OK;

	*_retval = IsUrlShouldBeSkipped (url, wstrSuggFileName);

    return NS_OK;
}

NS_IMETHODIMP CFDMForFirefox::CatchLink(IFDMUrl *url, const PRUnicharIDL *wstrSuggFileName, XULSDK_PRBool *_retval)
{
	assert (url != NULL);
	if (!url || !_retval)
		return NS_ERROR_INVALID_ARG;

	IsLinkShouldBeSkipped (url, wstrSuggFileName, _retval);
	if (*_retval)
		return NS_OK;

	*_retval = TransferUrlToFDM (url);

    return NS_OK;
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
	char *psz1 = new char [lstrlen (pszWhere) + 1];
	char *psz2 = new char [lstrlen (pszWhat) + 1];

	lstrcpy (psz1, pszWhere);
	lstrcpy (psz2, pszWhat);

	CharLower (psz1);
	CharLower (psz2);

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

	int len = lstrlen (pszExts);
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

BOOL IsServerInServersStr (LPCSTR pszServers, LPCSTR pszServer)
{
	if (pszServer == NULL)
		return FALSE;

	int len = lstrlen (pszServers);
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

		fsString str;
		str = "*."; str += szServer;
		if (IsExtStrEq (str, pszServer))
			return TRUE;

	} while (i < len);

	return FALSE;
}

fsString DomainFromUrl(LPCSTR pszUrl)
{
	LPCSTR pszS = strstr (pszUrl, "://");
	if (pszS == NULL)
		pszS = strstr (pszUrl, ":\\\\");
	if (pszS == NULL)
		pszS = pszUrl;
	else
		pszS += 3;
	LPCSTR pszE = pszS;
	while (*pszE && *pszE != '\\' && *pszE != '/')
		pszE++;

	char sz [1000];
	if (pszE - pszS > sizeof (sz))
		return "";

	lstrcpyn (sz, pszS, pszE - pszS + 1);
	return sz;
}

bool CFDMForFirefox::IsServerToSkip (IFDMUrl *url)
{
	wchar_t_IDL *wsz;
	url->GetUrl (&wsz);
	fsString strDomain = DomainFromUrl (CW2AEX <128> (pwchar_t_IDL_to_pwchar_t (wsz)));
	nsMemory::Free (wsz);

	char szServers [10000] = ""; DWORD dw = sizeof (szServers);
	m_keyFDMMonitor.QueryValue (szServers, "SkipServers", &dw);

	return IsServerInServersStr (szServers, strDomain) != 0;
}

bool CFDMForFirefox::IsUrlShouldBeSkipped(IFDMUrl *url, const PRUnicharIDL *pwszSuggFileName)
{
	assert (url != NULL);
	if (!url)
		return false;
	if (!pwszSuggFileName)
		return false;

	char szExts [10000] = "pls m3u"; DWORD dw = sizeof (szExts);
	m_keyFDMMonitor.QueryValue (szExts, "SkipExtensions", &dw);

	char szFile [1000] = "";
	WideCharToMultiByte (CP_ACP, 0, pwchar_t_IDL_to_pwchar_t (pwszSuggFileName), -1, szFile, sizeof (szFile), 
		NULL, NULL);
	szFile [wcslen (pwchar_t_IDL_to_pwchar_t (pwszSuggFileName))] = 0;

	LPCSTR pszExt = strrchr (szFile, '.');
	if (pszExt++ == NULL) 
		return false;

	return IsExtInExtsStr (szExts, pszExt) != FALSE ||
		IsServerToSkip (url);
}

XULSDK_PRBool CFDMForFirefox::TransferUrlToFDM(IFDMUrl *url)
{
	assert (url != NULL);
	if (!url)
		return FALSE;

	IWGUrlReceiverPtr spUrlRcvr;
	spUrlRcvr.CreateInstance (__uuidof (WGUrlReceiver));

	assert (spUrlRcvr != NULL);
    if (spUrlRcvr == NULL)
		return FALSE;

	if (NS_OK != CFDMUrlReceiver::ApplyUrlToReceiver (spUrlRcvr, url))
		return FALSE;

	spUrlRcvr->put_IgnoreSize (FALSE);

	if (FAILED (spUrlRcvr->ShowAddDownloadDialog ()))
		return FALSE;

	IServiceProviderPtr spSP (spUrlRcvr);
	IFdmUiWindowPtr spUiWindow;
	if (spSP)
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

	DWORD dwAllow = TRUE;
	m_keyFDMMonitor.QueryValue (dwAllow, "AllowDownload");
	if (dwAllow == FALSE)
		return TRUE;	

	BSTR bstrState = NULL;
	do {
		if (bstrState)
		{
			SysFreeString (bstrState);
			bstrState = NULL;
		}
		Sleep (5);
		spUrlRcvr->get_UIState (&bstrState);
		assert (bstrState != NULL);
		if (!bstrState)
			return FALSE;
	} while (wcsicmp (bstrState, L"in_progress") == 0);

	BOOL bAdded = wcsicmp (bstrState, L"added") == 0;
	SysFreeString (bstrState);

	return bAdded;
}

NS_IMETHODIMP CFDMForFirefox::SetProxyType(PRInt32 nType)
{
	m_keyFDMFfStgs.SetValue (nType, "ProxyType");
    return NS_OK;
}

NS_IMETHODIMP CFDMForFirefox::SetProxy(const char *strProtocol, const char *strAddr, PRInt32 nPort)
{
	fsString str = strProtocol;
	fsString strAddrName = str; strAddrName += "_addr";
	fsString strPortName = str; strPortName += "_port";

	m_keyFDMFfStgs.SetValue (strAddr, strAddrName);
	m_keyFDMFfStgs.SetValue (nPort, strPortName);
	
    return NS_OK;
}

NS_IMETHODIMP CFDMForFirefox::IsDomainSupportedForVideoDownloads(const PRUnicharIDL *wstrDomain, XULSDK_PRBool *_retval)
{
	if (_wcsnicmp (pwchar_t_IDL_to_pwchar_t (wstrDomain), L"www.", 4) == 0)
		wstrDomain += 4;

	*_retval = wcsicmp (pwchar_t_IDL_to_pwchar_t (wstrDomain), L"youtube.com") == 0;

    return NS_OK;
}

NS_IMETHODIMP CFDMForFirefox::ProcessVideoDocument(const PRUnicharIDL *wstrDomain, const PRUnicharIDL *wstrReferer, const PRUnicharIDL *wstrHTML, XULSDK_PRBool *_retval)
{
	*_retval = FALSE;

	IFDMFlashVideoDownloadsPtr spFVDownloads;
	spFVDownloads.CreateInstance (__uuidof (FDMFlashVideoDownloads));

	assert (spFVDownloads != NULL);
	if (spFVDownloads == NULL)
		return NS_OK;
		          
	BSTR bstrDomain = SysAllocString (pwchar_t_IDL_to_pwchar_t (wstrDomain));
	BSTR bstrHtml = SysAllocString (pwchar_t_IDL_to_pwchar_t (wstrHTML));

	spFVDownloads->ProcessHtml (bstrDomain, bstrHtml);

	*_retval = TRUE;

    return NS_OK;
}

NS_IMETHODIMP CFDMForFirefox::CreateVideoDownloadFromUrl(const PRUnicharIDL *wstrUrl, XULSDK_PRBool *_retval)
{
	return CreateVideoDownloadFromUrl2 (wstrUrl, NULL, NULL, _retval);
}

NS_IMETHODIMP CFDMForFirefox::CreateVideoDownloadFromUrl2(const PRUnicharIDL *wstrUrl, const PRUnicharIDL *wstrSwfUrl, const PRUnicharIDL *wstrFlashVars, XULSDK_PRBool *_retval)
{
	return CreateVideoDownloadFromUrl3 (wstrUrl, NULL, wstrSwfUrl, wstrFlashVars, NULL, NULL, _retval);
}

NS_IMETHODIMP CFDMForFirefox::CreateVideoDownloadFromUrl3(const PRUnicharIDL *wstrUrl, const PRUnicharIDL *wstrFrameUrl, const PRUnicharIDL *wstrSwfUrl, const PRUnicharIDL *wstrFlashVars, const PRUnicharIDL *wstrOtherSwfUrls, const PRUnicharIDL *wstrOtherFlashVars, XULSDK_PRBool *_retval)
{
	*_retval = TRUE;

	_threadOnDownloadItBtnClicked_param *p = new _threadOnDownloadItBtnClicked_param;
	p->pthis = this;
	this->AddRef ();

	p->strUrl = CW2AEX<128> (pwchar_t_IDL_to_pwchar_t (wstrUrl));
	if (wstrFrameUrl)
		p->strFrameUrl = CW2AEX<128> (pwchar_t_IDL_to_pwchar_t (wstrFrameUrl));
	if (wstrSwfUrl)
		p->strSwfUrl = CW2AEX<128> (pwchar_t_IDL_to_pwchar_t (wstrSwfUrl));
	if (wstrFlashVars)
		p->strFlashVars = CW2AEX<128> (pwchar_t_IDL_to_pwchar_t (wstrFlashVars));
	if (wstrOtherSwfUrls)
		p->strOtherSwfUrls = CW2AEX<128> (pwchar_t_IDL_to_pwchar_t (wstrOtherSwfUrls));
	if (wstrOtherFlashVars)
		p->strOtherFlashVars = CW2AEX<128> (pwchar_t_IDL_to_pwchar_t (wstrOtherFlashVars));
	p->hwndParent = GetForegroundWindow ();

	DWORD dw;
	CloseHandle (
		CreateThread (NULL, 0, _threadOnDownloadItBtnClicked, p, 0, &dw));
	
	

    return NS_OK;
}

NS_IMETHODIMP CFDMForFirefox::IsVideoFlash(const PRUnicharIDL *wstrUrl, const PRUnicharIDL *wstrFrameUrl, const PRUnicharIDL *wstrSwfUrl, const PRUnicharIDL *wstrFlashVars, const PRUnicharIDL *wstrOtherSwfUrls, const PRUnicharIDL *wstrOtherFlashVars, XULSDK_PRBool *_retval)
{
	if (!wstrFrameUrl)
		wstrFrameUrl = pwchar_t_to_pwchar_t_IDL (L"");
	if (!wstrSwfUrl)
		wstrSwfUrl = pwchar_t_to_pwchar_t_IDL (L"");
	if (!wstrFlashVars)
		wstrFlashVars = pwchar_t_to_pwchar_t_IDL (L"");
	if (!wstrOtherSwfUrls)
		wstrOtherSwfUrls = pwchar_t_to_pwchar_t_IDL (L"");
	if (!wstrOtherFlashVars)
		wstrOtherFlashVars = pwchar_t_to_pwchar_t_IDL (L"");

	vmsFlvSniffDll dll;

	*_retval = dll.IsVideoFlash (CW2AEX<128> (pwchar_t_IDL_to_pwchar_t (wstrUrl)), CW2AEX<128> (pwchar_t_IDL_to_pwchar_t (wstrFrameUrl)),
		CW2AEX<128> (pwchar_t_IDL_to_pwchar_t (wstrSwfUrl)), CW2AEX<128> (pwchar_t_IDL_to_pwchar_t (wstrFlashVars)), 
		CW2AEX<128> (pwchar_t_IDL_to_pwchar_t (wstrOtherSwfUrls)), CW2AEX<128> (pwchar_t_IDL_to_pwchar_t (wstrOtherFlashVars)));

	return NS_OK;
}

DWORD WINAPI CFDMForFirefox::_threadOnDownloadItBtnClicked(LPVOID lp)
{
	_threadOnDownloadItBtnClicked_param *p = (_threadOnDownloadItBtnClicked_param*)lp;
	vmsFlvSniffDll dll;
	threadOnDownloadItBtnClicked_a_params th_a_params;
	th_a_params.pSniffDll = &dll;
	th_a_params.pszUrl = p->strUrl.c_str ();
	th_a_params.pszFrameUrl = p->strFrameUrl.c_str ();
	th_a_params.pszSwfUrl = p->strSwfUrl.c_str ();
	th_a_params.pszFlashVars = p->strFlashVars.c_str ();
	th_a_params.pszOtherSwfUrls = p->strOtherSwfUrls.c_str ();
	th_a_params.pszOtherFlashVars = p->strOtherFlashVars.c_str ();
	th_a_params.hevCloseDlg = CreateEvent (NULL, TRUE, FALSE, NULL);
	DWORD dw;
	CloseHandle (
		CreateThread (NULL, 0, _threadOnDownloadItBtnClicked_a, &th_a_params, 0, &dw));	
	vmsWaitDlg dlg;
	dlg.m_hevCloseDlg = th_a_params.hevCloseDlg;
	dlg.m_strMsg = vmsFdmTranslations::o ().GetString (L_SEARCHING_FLVS);
	if (dlg.m_strMsg.empty ())
		dlg.m_strMsg = _T ("Searching flash videos...");
	dlg.m_hIcon = (HICON)LoadImage (GetModuleHandle ("vmsfdmff.dll"), MAKEINTRESOURCE (IDI_FDM),
		IMAGE_ICON, 16, 16, 0);
	if (dlg.Create (GetModuleHandle ("vmsfdmff.dll"), MAKEINTRESOURCE (IDD_WAIT), p->hwndParent))
	{
		ShowWindow (dlg.m_hwnd, SW_SHOW);
		BringWindowToTop (dlg.m_hwnd);
		MSG msg;
		while (GetMessage (&msg, NULL, 0, 0))
			DispatchMessage (&msg);
	}
	else
	{
		WaitForSingleObject (th_a_params.hevCloseDlg, INFINITE);
	}
	DestroyIcon (dlg.m_hIcon);
	if (!IsWindow (p->hwndParent))
		p->hwndParent = NULL;
	dll.OnDownloadItBtnClicked_ShowMsgIfReq (p->hwndParent);
	CloseHandle (th_a_params.hevCloseDlg);
	p->pthis->Release ();
	delete p;
	return 0;
}

DWORD WINAPI CFDMForFirefox::_threadOnDownloadItBtnClicked_a(LPVOID lp)
{
	threadOnDownloadItBtnClicked_a_params *p = (threadOnDownloadItBtnClicked_a_params*)lp;
	CoInitialize (NULL);
	p->pSniffDll->OnDownloadItBtnClicked3 (p->pszUrl, p->pszFrameUrl, p->pszSwfUrl, p->pszFlashVars,
		p->pszOtherSwfUrls, p->pszOtherFlashVars);
	SetEvent (p->hevCloseDlg);
	CoUninitialize ();
	return 0;
}

NS_IMETHODIMP CFDMForFirefox::OnNewHttpRequest (const PRUnicharIDL *wstrUrl, const PRUnicharIDL *wstrSourceTabUrl)
{
	assert (wstrUrl != NULL && wstrSourceTabUrl != NULL);
	if (!wstrUrl || !wstrSourceTabUrl)
		return NS_ERROR_INVALID_POINTER;
	vmsFlvSniffDll::OnNewHttpRequest (CW2AEX<128> (pwchar_t_IDL_to_pwchar_t (wstrUrl)), CW2AEX<128> (pwchar_t_IDL_to_pwchar_t (wstrSourceTabUrl)));
	return NS_OK;
}

NS_IMETHODIMP CFDMForFirefox::OnHttpRedirect (const PRUnicharIDL *wstrUrl, const PRUnicharIDL *wstrOriginalUrl)
{
	assert (wstrUrl != NULL && wstrOriginalUrl != NULL);
	if (!wstrUrl || !wstrOriginalUrl)
		return NS_ERROR_INVALID_POINTER;
	LOGsnl ("Redirect:");
	LOG (" source: %s", CW2AEX<128> (wstrOriginalUrl));
	LOG (" new: %s", CW2AEX<128> (wstrUrl));
	vmsHttpRedirectList::Redirect r;
	r.dwTicksRegistered = GetTickCount ();
	r.wstrUrl = pwchar_t_IDL_to_pwchar_t (wstrUrl);
	r.wstrOriginalUrl = pwchar_t_IDL_to_pwchar_t (wstrOriginalUrl);
	vmsHttpRedirectList::o ().addRedirect (r);
	return NS_OK;
}

NS_IMETHODIMP CFDMForFirefox::DownloadBegin(const PRUnicharIDL *wstrUrl)
{
	vmsBrowserActivityMonitor::o ().onDownloadBegin (pwchar_t_IDL_to_pwchar_t (wstrUrl));
	return NS_OK;
}

NS_IMETHODIMP CFDMForFirefox::DownloadComplete(const PRUnicharIDL *wstrUrl)
{
	vmsBrowserActivityMonitor::o ().onDownloadEnd (pwchar_t_IDL_to_pwchar_t (wstrUrl));
	return NS_OK;
}

NS_IMETHODIMP CFDMForFirefox::OnHttpActivity(const PRUnicharIDL *wstrUrl)
{
	vmsBrowserActivityMonitor::o ().onActivity (pwchar_t_IDL_to_pwchar_t (wstrUrl));
	return NS_OK;
}