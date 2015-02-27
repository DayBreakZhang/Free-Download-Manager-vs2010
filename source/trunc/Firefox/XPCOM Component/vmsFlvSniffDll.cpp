/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include <windows.h>
#include "vmsFlvSniffDll.h"
#include <string>
#include "vmsFdmTranslations.h"

vmsFlvSniffDll::vmsFlvSniffDll()
{
	m_enBR = ButtonResult::NONE;
	m_hrLast = S_OK;
}

vmsFlvSniffDll::~vmsFlvSniffDll()
{

}

void vmsFlvSniffDll::OnDownloadItBtnClicked (const char* pszWebPageUrl)
{
	HMODULE hDll = GetModuleHandle ("flvsniff.dll");
	if (!hDll)
	{
		m_enBR = ButtonResult::E_SNIFF_MODULE_NOT_FOUND;
		return;
	}
	typedef HRESULT (WINAPI *FNBTNCLCKD)(LPCSTR);
	FNBTNCLCKD pfn = (FNBTNCLCKD) GetProcAddress (hDll, "onGetItBtnClicked");
	if (pfn != NULL)
	{
		HRESULT hr = pfn (pszWebPageUrl);
		if (FAILED (hr))
		{
			if (hr == E_INVALIDARG)
				m_enBR = ButtonResult::E_URL_NOT_FOUND;
			else
				m_enBR = ButtonResult::E_FAILED;
			m_hrLast = hr;
		}
		else if (hr == S_FALSE)
		{
			m_enBR = ButtonResult::E_NO_FLV_FOUND;
		}
	}
}

void vmsFlvSniffDll::OnDownloadItBtnClicked2 (const char* pszWebPageUrl, const char* pszSwfUrl, const char* pszFlashVars)
{
	HMODULE hDll = GetModuleHandle ("flvsniff.dll");
	if (!hDll)
	{
		m_enBR = ButtonResult::E_SNIFF_MODULE_NOT_FOUND;
		return;
	}
	typedef HRESULT (WINAPI *FNBTNCLCKD)(LPCSTR, LPCSTR, LPCSTR);
	FNBTNCLCKD pfn = (FNBTNCLCKD) GetProcAddress (hDll, "onGetItBtnClicked2");
	if (pfn != NULL)
	{
		HRESULT hr = pfn (pszWebPageUrl, pszSwfUrl, pszFlashVars);
		if (FAILED (hr))
		{
			if (hr == E_INVALIDARG)
				m_enBR = ButtonResult::E_URL_NOT_FOUND;
			else
				m_enBR = ButtonResult::E_FAILED;
			m_hrLast = hr;
		}
		else if (hr == S_FALSE)
		{
			m_enBR = ButtonResult::E_NO_FLV_FOUND;
		}
	}
}

void vmsFlvSniffDll::OnDownloadItBtnClicked3 (const char* pszWebPageUrl, const char* pszFrameUrl, const char* pszSwfUrl, const char* pszFlashVars, const char* pszOtherSwfUrls, const char* pszOtherFlashVars)
{
	HMODULE hDll = GetModuleHandle ("flvsniff.dll");
	if (!hDll)
	{
		m_enBR = ButtonResult::E_SNIFF_MODULE_NOT_FOUND;
		return;
	}
	typedef HRESULT (WINAPI *FNBTNCLCKD)(LPCSTR, LPCSTR, LPCSTR, LPCSTR, LPCSTR, LPCSTR);
	FNBTNCLCKD pfn = (FNBTNCLCKD) GetProcAddress (hDll, "onGetItBtnClicked3");
	if (pfn != NULL)
	{
		HRESULT hr = pfn (pszWebPageUrl, pszFrameUrl, pszSwfUrl, pszFlashVars, pszOtherSwfUrls, pszOtherFlashVars);
		if (FAILED (hr))
		{
			if (hr == E_INVALIDARG)
				m_enBR = ButtonResult::E_URL_NOT_FOUND;
			else
				m_enBR = ButtonResult::E_FAILED;
			m_hrLast = hr;
		}
		else if (hr == S_FALSE)
		{
			m_enBR = ButtonResult::E_NO_FLV_FOUND;
		}
	}
}

BOOL vmsFlvSniffDll::IsVideoFlash (const char* pszWebPageUrl, const char* pszFrameUrl, const char* pszSwfUrl, const char* pszFlashVars, const char* pszOtherSwfUrls, const char* pszOtherFlashVars)
{
	HMODULE hDll = GetModuleHandle ("flvsniff.dll");
	if (!hDll)
		return FALSE;
	typedef BOOL (WINAPI *FNIVF)(LPCSTR, LPCSTR, LPCSTR, LPCSTR, LPCSTR, LPCSTR);
	FNIVF pfn = (FNIVF) GetProcAddress (hDll, "isVideoFlash");
	if (pfn != NULL)
		return pfn (pszWebPageUrl, pszFrameUrl, pszSwfUrl, pszFlashVars, pszOtherSwfUrls, pszOtherFlashVars);
	return FALSE;
}

void vmsFlvSniffDll::OnDownloadItBtnClicked_ShowMsgIfReq(HWND hwndParent) const
{
	std::string strMsg;
	
	switch (m_enBR)
	{
	case E_SNIFF_MODULE_NOT_FOUND:
		strMsg = vmsFdmTranslations::o ().GetString (L_FLVSNIFFMODULE_NOTFOUND);
		if (strMsg.empty ())
			strMsg = "Flash video monitoring module is not loaded. Make sure FDM is running and you've enabled this option in FDM (see Options | Downloads | Flash Video).";
		break;
		
	case E_FAILED:
		strMsg = vmsFdmTranslations::o ().GetString (L_FAILEDTRANSFERDLDSTOFDM);
		if (strMsg.empty ())
			strMsg = "An error occurred while trying to transfer downloads to FDM.\nError: 0x%x.";
		char sz [300]; *sz = 0;
		sprintf (sz, strMsg.c_str (), m_hrLast);
		strMsg = sz;
		break;
		
	case E_NO_FLV_FOUND:
		strMsg = vmsFdmTranslations::o ().GetString (L_NOFLVSFOUND);
		if (strMsg.empty ())
			strMsg = "There were no flash videos found on this page. Make sure the videos on this page are playing or try to reload it (refresh page or clear browser's cache).";
		break;
		
	case E_URL_NOT_FOUND:
		strMsg = vmsFdmTranslations::o ().GetString (L_FLVWEBPAGENOTFOUND);
		if (strMsg.empty ())
			strMsg = "Failed to found information about this web page. Please force your browser to reload it.";
		break;		
	}
	
	if (!strMsg.empty ())
		MessageBox (hwndParent, strMsg.c_str (), NULL, MB_ICONERROR);
}

UINT vmsFlvSniffDll::onNewHttpDialog(LPCSTR pszUrl, LPCSTR pszRequestHdrs, LPCSTR pszRespHdrs)
{
	HMODULE hDll = GetModuleHandle ("flvsniff.dll");
	if (!hDll)
		return UINT_MAX;
	typedef UINT (WINAPI *FNNHD)(LPCSTR, LPCSTR, LPCSTR);
	FNNHD pfn = (FNNHD) GetProcAddress (hDll, "onNewHttpDialog");
	if (pfn != NULL)
		return pfn (pszUrl, pszRequestHdrs, pszRespHdrs);
	return UINT_MAX;
}

void vmsFlvSniffDll::onHttpDialogDataReceived(UINT nUID, LPBYTE pbData, UINT nSize)
{
	HMODULE hDll = GetModuleHandle ("flvsniff.dll");
	if (!hDll)
		return;
	typedef UINT (WINAPI *FNHDDR)(UINT, LPBYTE, UINT);
	FNHDDR pfn = (FNHDDR) GetProcAddress (hDll, "onHttpDialogDataReceived");
	if (pfn != NULL)
		pfn (nUID, pbData, nSize);
}

void vmsFlvSniffDll::onHttpDialogClosed(UINT nUID)
{
	HMODULE hDll = GetModuleHandle ("flvsniff.dll");
	if (!hDll)
		return;
	typedef UINT (WINAPI *FNHDC)(UINT);
	FNHDC pfn = (FNHDC) GetProcAddress (hDll, "onHttpDialogClosed");
	if (pfn != NULL)
		pfn (nUID);
}

void vmsFlvSniffDll::OnNewHttpRequest(LPCSTR pszUrl, LPCSTR pszSrcTabUrl)
{
	HMODULE hDll = GetModuleHandle ("flvsniff.dll");
	if (!hDll)
		return;
	typedef void (WINAPI *FNONHR)(LPCSTR, LPCSTR);
	FNONHR pfn = (FNONHR) GetProcAddress (hDll, "onNewHttpRequest");
	if (pfn)
		pfn (pszUrl, pszSrcTabUrl);
}
