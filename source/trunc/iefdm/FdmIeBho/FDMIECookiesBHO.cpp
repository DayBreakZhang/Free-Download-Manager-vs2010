/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "Iecooks.h"
#include "FDMIECookiesBHO.h"
#include <mshtml.h>
#include <oleacc.h>
#include "../../vmsVideoSiteHtmlCodeParser.h"
#include "vmsIeTabsHookFitter.h"
#include "HtmlEventSink.h"
#include "vmsFlashWindowsSubclasser.h"
#include "vmsComGIT.h"
#include <shlguid.h>
#include <vector>
using namespace std;
#include "vmsFlvSniffDllLoader.h"
#include "vmsDomHelper.h"
#include "vmsUrl.h"

#include "vmsFlashHelper.h"
_COM_SMARTPTR_TYPEDEF(IShockwaveFlash, __uuidof(IShockwaveFlash));

#include "oldsdksupport.h"

_COM_SMARTPTR_TYPEDEF(IHTMLRect, __uuidof(IHTMLRect));
_COM_SMARTPTR_TYPEDEF(IHTMLInputElement, __uuidof(IHTMLInputElement));
_COM_SMARTPTR_TYPEDEF(IHTMLElement2, __uuidof(IHTMLElement2));
_COM_SMARTPTR_TYPEDEF(IHTMLDocument3, __uuidof(IHTMLDocument3));
_COM_SMARTPTR_TYPEDEF(IHTMLWindow3, __uuidof(IHTMLWindow3));
_COM_SMARTPTR_TYPEDEF(IHTMLWindow4, __uuidof(IHTMLWindow4));
_COM_SMARTPTR_TYPEDEF(IHTMLDOMNode2, __uuidof(IHTMLDOMNode2));
_COM_SMARTPTR_TYPEDEF(IHTMLScreen2, __uuidof(IHTMLScreen2));
_COM_SMARTPTR_TYPEDEF(IHTMLScreen3, __uuidof(IHTMLScreen3));
_COM_SMARTPTR_TYPEDEF(IDisplayServices, __uuidof(IDisplayServices));

vector <CFDMIEBHO::Instance> CFDMIEBHO::_vInstances;
vmsCriticalSection CFDMIEBHO::_csInstances;

extern BOOL _bIsWin9x;

#pragma data_seg("shdata")

long CFDMIEBHO::_cIEDownloads = 0;
#pragma data_seg()

#pragma comment(linker, "/section:shdata,rws")

IHTMLDocument2Ptr doc_from_hwnd (HWND hwnd)
{
	HINSTANCE hInst = ::LoadLibrary( _T("OLEACC.DLL") );
	if (hInst == NULL)
		return NULL;

	LPFNOBJECTFROMLRESULT pfObjectFromLresult = (LPFNOBJECTFROMLRESULT)::GetProcAddress( hInst, _T("ObjectFromLresult") );
	if (pfObjectFromLresult == NULL)
		return NULL;

	UINT nMsg = RegisterWindowMessage ("WM_HTML_GETOBJECT");
	
	LRESULT lRes;
	::SendMessageTimeout (hwnd, nMsg, 0L, 0L, SMTO_ABORTIFHUNG, 1000, (DWORD*)&lRes );

	IHTMLDocument2Ptr spDoc;
	pfObjectFromLresult (lRes, IID_IHTMLDocument2, 0, (void**)&spDoc);

	FreeLibrary (hInst);

	return spDoc;
}

BOOL is_okpage (HWND hwnd)
{
	IHTMLDocument2Ptr spDoc = doc_from_hwnd (hwnd);
	if (spDoc == NULL)
		return TRUE;

	IHTMLLocationPtr spLoc;
	spDoc->get_location (&spLoc);
	if (spLoc == NULL)
		return FALSE;

	BSTR bstrHost = NULL;
	spLoc->get_hostname (&bstrHost);
	if (bstrHost == NULL)
		return FALSE;

	USES_CONVERSION;

	if (vmsVideoSiteHtmlCodeParser::GetSupportedSiteIndex (W2A (bstrHost)) != -1)
		return TRUE;

	return FALSE;
}

BOOL _bUseUnicode;
DWORD _dwIeMajorVersion;

BOOL GetIEVersion(DWORD *pMajor, DWORD *pMinor, DWORD *pBuild, DWORD *pSubBuild)
{
    CRegKey rk;
    LONG lRet = rk.Open(HKEY_LOCAL_MACHINE, _T("Software\\Microsoft\\Internet Explorer"), KEY_READ);
    if(lRet == 0)
    {
        TCHAR szBuff[256];
        DWORD dwCount = sizeof(szBuff);
        lRet = rk.QueryValue (szBuff, _T("Version"), &dwCount);
        if(lRet == 0)
        {
            sscanf(szBuff, "%u.%u.%u.%u", pMajor, pMinor, pBuild, pSubBuild);
            return TRUE;
        }
    }

    return FALSE;
}

LRESULT CALLBACK _IeServerWndProc (HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
	

	return 0;
}

HWND find_ie_server (HWND hwnd)
{
	HWND hwnd2 = NULL;
	
	for (;;)
	{
		hwnd2 = FindWindowEx (hwnd, hwnd2, NULL, NULL);
		if (hwnd2 == NULL)
			return NULL;

		char sz [1000];
		GetClassName (hwnd2, sz, sizeof (sz));

		if (lstrcmpi (sz, "Internet Explorer_Server") == 0)
			return hwnd2;

		HWND hwnd3 = find_ie_server (hwnd2);
		if (hwnd3 != NULL)
			return hwnd3;
	}
}

vmsFlvSniffDllLoader _SniffDllLoader (1);

STDMETHODIMP CFDMIEBHO::SetSite(IUnknown *pSite)
{
	if (pSite)
	{
		vmsCriticalSectionAutoLock csal (&_csInstances);
		int nIndex = findInstanceIndex (this);
		assert (nIndex != -1);
		if (nIndex != -1)
			_vInstances [nIndex].dwMainThreadId = GetCurrentThreadId ();

		

		if (GetModuleHandle ("fdmumsp.dll") == NULL)
		{
			TCHAR tsz [MAX_PATH] = _T ("");
			GetModuleFileName (_Module.GetModuleInstance (), tsz, MAX_PATH);
			LPTSTR ptsz = _tcsrchr (tsz, '\\');
			if (ptsz)
			{
				_tcscpy (ptsz + 1, _T ("fdmumsp.dll"));
				LoadLibrary (tsz);
			}
		}

		_SniffDllLoader.MakeSureDllLoaded ();
	}

	if (pSite == NULL)
	{
		ShowGetItButton (BST_HIDE, NULL);
		for (size_t i = 0; i < m_vHtmlEventHandlers.size (); i++)
		{
			AtlUnadvise (m_vHtmlEventHandlers [i]->getUnkParam (), __uuidof (HTMLDocumentEvents2), m_vHtmlEventHandlers [i]->m_dwCookie);
			m_vHtmlEventHandlers [i]->Release ();
		}
		m_vHtmlEventHandlers.clear ();
	}

	

	if (m_spWB != NULL)
	{
		Disconnect ();
		vmsComGIT::RevokeInterfaceFromGlobal (m_dwWbCookie);
		m_dwWbCookie = 0;
	}

	#ifndef DISABLE_OLD_MONITORING_HELPER
		if (pSite == NULL)
			DeleteFile ();
	#endif

	m_spWB = pSite;

	if (m_spWB == NULL)
		return pSite == NULL ? S_OK : E_INVALIDARG;

	vmsComGIT::RegisterInterfaceInGlobal (m_spWB, IID_IWebBrowser2, &m_dwWbCookie);

	_bUseUnicode = (GetVersion () & 0x80000000) == 0;
	DWORD dw;
	GetIEVersion (&_dwIeMajorVersion, &dw, &dw, &dw);

	

	m_spWB_CPC = m_spWB;
	if (m_spWB_CPC == NULL)
		return E_INVALIDARG;

	return Connect ();
}

STDMETHODIMP CFDMIEBHO::GetSite(REFIID riid, void **ppvSite)
{
	if (m_spWB == NULL || ppvSite == NULL)
		return E_INVALIDARG;
	
	*ppvSite = NULL;
	return m_spWB.QueryInterface (riid, (IWebBrowser2**)ppvSite);
}

STDMETHODIMP CFDMIEBHO::Connect()
{
	HRESULT hr;

	hr = Disconnect ();
	if (FAILED (hr))
		return hr;

	hr = m_spWB_CPC->FindConnectionPoint (DIID_DWebBrowserEvents2, &m_spWB_CPC_CP);
	if (FAILED (hr))
		return hr;

	IUnknown *pthis = (IUnknown*)(IFDMIEBHO*) this;

	hr = m_spWB_CPC_CP->Advise (pthis, &m_dwCookie);

	return hr;
}

STDMETHODIMP CFDMIEBHO::Disconnect()
{
	if (m_spWB_CPC_CP == NULL)
		return S_FALSE;

	HRESULT hr = m_spWB_CPC_CP->Unadvise (m_dwCookie);
	if (FAILED (hr))
		return hr;

	m_spWB_CPC_CP = NULL;
	m_spWB_CPC = NULL;

	return S_OK;
}

BOOL CALLBACK FindFlashWindows_EnumProc (HWND hwnd, LPARAM lp)
{
	TCHAR tszClass [1000] = _T ("");
	GetClassName (hwnd, tszClass, 1000);

	if (_tcsicmp (tszClass, _T ("MacromediaFlashPlayerActiveX")) == 0)
	{
		vector <HWND> *pv = (vector <HWND>*)lp;
		pv->push_back (hwnd);
	}
	
	return TRUE;
}

void FindFlashWindows (HWND hwnd, vector <HWND> &v)
{
	EnumChildWindows (hwnd, FindFlashWindows_EnumProc, (LPARAM)&v);
}

LRESULT CALLBACK CFDMIEBHO::_FlashWindowProc (HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
	int nWnd = vmsFlashWindowsSubclasser::o ().FindWindow (hwnd);
	if (nWnd == -1)
		return DefWindowProc (hwnd, msg, wp, lp);
	vmsFlashWindowsSubclasser::FlashWindow* wnd = vmsFlashWindowsSubclasser::o ().getWindow (nWnd);
	CFDMIEBHO *pthis = (CFDMIEBHO*)wnd->pvData;

	if (msg == WM_MOUSEMOVE)
	{
		RECT rc; GetWindowRect (hwnd, &rc);
		
	}

	return CallWindowProc (wnd->pfnOldProc, hwnd, msg, wp, lp);
}

STDMETHODIMP CFDMIEBHO::ProgressChange(long Progress, long ProgressMax)
{
#ifndef DISABLE_OLD_MONITORING_HELPER
	AnalyzePageAndWriteInfo ();
#endif

	QueryWindow ();
	SubclassFlashWindows ();	

	return S_OK;
}

STDMETHODIMP CFDMIEBHO::BeforeNavigate2(IDispatch *pdWB, VARIANT *url, VARIANT *flags, VARIANT *tfn, VARIANT *pd, VARIANT *headers, VARIANT_BOOL *bCancel)
{
#ifndef DISABLE_OLD_MONITORING_HELPER
	USES_CONVERSION;
	
	m_strPostData = "";
	m_strBeforeNavUrl = W2A (url->bstrVal);
	
	IWebBrowser2Ptr spWB (pdWB);
	if (spWB == NULL)
		return S_OK;
	
	IDispatchPtr spdDoc;
	spWB->get_Document (&spdDoc);
	if (spdDoc == NULL)
		return S_OK;
	
	IHTMLDocument2Ptr spDoc (spdDoc);
	if (spDoc == NULL)
		return S_OK;
	
	IHTMLElementCollectionPtr spForms;
	spDoc->get_forms (&spForms);
	
	long cForms = 0;
	if (spForms != NULL)
		spForms->get_length (&cForms);
	
	bool bFound = false;
	
	
	
	for (long i = 0; bFound == false && i < cForms; i++)
	{
		IDispatchPtr spd;
		spForms->item (CComVariant (i), CComVariant (i), &spd);
		if (spd == NULL)
			continue;
		
		IHTMLFormElementPtr spForm (spd);
		if (spForm == NULL)
			continue;
		
		BSTR bstr = NULL;
		spForm->get_action (&bstr);
		
		bFound = bstr != NULL && wcscmp (url->bstrVal, bstr) == 0;
		if (bstr)
		{
			SysFreeString (bstr);
			bstr = NULL;
		}
		
		if (bFound == false)
			continue;
		
		spForm->get_method (&bstr);
		
		if (bstr == NULL || wcsicmp (bstr, L"post"))
			break;
		if (bstr)
		{
			SysFreeString (bstr);
			bstr = NULL;
		}
		
		IHTMLElementPtr spFormElem (spForm);
		if (spFormElem == NULL)
		{
			bFound = false;
			continue;
		}
		
		
		WalkThroughForm (spFormElem, m_strPostData);
		
		
		if (m_strPostData != "" && 
			m_strPostData [m_strPostData.GetLength ()-1] == '&')
			m_strPostData [m_strPostData.GetLength ()-1] = 0;
	}
	
	m_strUrl = ""; 
	AnalyzePageAndWriteInfo ();
#endif
	
	return S_OK;
}

#ifndef DISABLE_OLD_MONITORING_HELPER

void CFDMIEBHO::SaveInfoToDisk()
{
	WaitForSingleObject (m_mxFile, INFINITE);

	if (m_hFile == INVALID_HANDLE_VALUE)
	{
		char szTmpPath [MAX_PATH], szFile [MAX_PATH];
		GetTempPath (MAX_PATH, szTmpPath);
		CreateDirectory (szTmpPath, NULL);
		lstrcat (szTmpPath, "Free Download Manager");
		CreateDirectory (szTmpPath, NULL);
		GetTempFileName (szTmpPath, "tic", 0, szFile);

		if (_bIsWin9x == FALSE)
		{
			m_hFile = CreateFile (szFile, GENERIC_WRITE, 
				FILE_SHARE_READ | FILE_SHARE_DELETE, NULL, CREATE_ALWAYS, 
				FILE_ATTRIBUTE_HIDDEN | FILE_FLAG_DELETE_ON_CLOSE, NULL);
		}
		else
		{
			m_strTmpFile = szFile;
			m_hFile = CreateFile (szFile, GENERIC_WRITE, 
				FILE_SHARE_READ, NULL, CREATE_ALWAYS, 
				FILE_ATTRIBUTE_HIDDEN, NULL);
		}

		if (m_hFile == INVALID_HANDLE_VALUE)
		{
			ReleaseMutex (m_mxFile);
			return;
		}
	}

	SetFilePointer (m_hFile, 0, NULL, FILE_BEGIN);

	DWORD dw;

	WriteFile (m_hFile, (LPCSTR)m_strUrl, m_strUrl.GetLength (), &dw, NULL);
	WriteFile (m_hFile, "\r\n", 2, &dw, NULL);
	WriteFile (m_hFile, (LPCSTR)m_strCookies, m_strCookies.GetLength (), &dw, NULL);
	WriteFile (m_hFile, "\r\n", 2, &dw, NULL);
	WriteFile (m_hFile, (LPCSTR)m_strPostData, m_strPostData.GetLength (), &dw, NULL);
	WriteFile (m_hFile, "\r\n", 2, &dw, NULL);
	WriteFile (m_hFile, (LPCSTR)m_strBeforeNavUrl, m_strBeforeNavUrl.GetLength (), &dw, NULL);

	SetEndOfFile (m_hFile);

	ReleaseMutex (m_mxFile);
}

void CFDMIEBHO::WalkThroughForm(IHTMLElement *pElement, fsString& str)
{
	USES_CONVERSION;

	IDispatchPtr spd;
	pElement->get_children (&spd);
	if (spd == NULL)
		return;
	IHTMLElementCollectionPtr spels (spd);
	if (spels == NULL)
		return;

	long cElements = 0;
	spels->get_length (&cElements);
	
	for (int j = 0; j < cElements; j++)
	{
		spd = NULL;
		spels->item (CComVariant (j), CComVariant (j), &spd);
		if (spd == NULL)
			continue;

		
		IHTMLInputElementPtr spInp (spd);
		if (spInp != NULL)
		{
			
			BSTR bstr = NULL, bstr2 = NULL;
			spInp->get_name (&bstr);				
			spInp->get_value (&bstr2);
			if (bstr)
			{
				str += W2A (bstr);
				str += "=";
				SysFreeString (bstr);
			}
			if (bstr2)
			{
				str += W2A (bstr2);
				SysFreeString (bstr2);
			}
			if (bstr || bstr2)
				str += "&";
		}
		
		IHTMLElementPtr spel (spd);
		if (spel != NULL)
			WalkThroughForm (spel, str);	
	}
}

void CFDMIEBHO::DeleteFile()
{
	if (m_hFile != INVALID_HANDLE_VALUE)
	{
		CloseHandle (m_hFile);
		m_hFile = INVALID_HANDLE_VALUE;
		if (_bIsWin9x)
			::DeleteFile (m_strTmpFile);
	}

	WaitForSingleObject (m_mxFile, INFINITE);
	char szTmpPath [MAX_PATH];
	GetTempPath (MAX_PATH, szTmpPath);
	lstrcat (szTmpPath, "Free Download Manager");
	RemoveDirectory (szTmpPath);
	ReleaseMutex (m_mxFile);
}

void CFDMIEBHO::AnalyzePageAndWriteInfo()
{
	USES_CONVERSION;
	
	IDispatchPtr spdDoc;
	m_spWB->get_Document (&spdDoc);
	if (spdDoc == NULL)
		return;
	
	IHTMLDocument2Ptr spDoc (spdDoc);
	if (spDoc == NULL)
		return;
	
	BSTR bstr = NULL;
	spDoc->get_cookie (&bstr);
	
	fsString strCookies, strUrl;
	
	if (bstr)
	{
		strCookies = W2A (bstr);
		SysFreeString (bstr);
		bstr = NULL;
	}
	
	spDoc->get_URL (&bstr);
	
	if (bstr)
	{
		strUrl = W2A (bstr);
		SysFreeString (bstr);
		bstr = NULL;
	}
	
	if (m_strUrl != strUrl || m_strCookies != strCookies || 
		m_strPostData != "")
	{
		m_strUrl = strUrl;
		m_strCookies = strCookies;
		SaveInfoToDisk ();
	}
}

#endif

STDMETHODIMP CFDMIEBHO::DownloadBegin()
{
	InterlockedIncrement (&_cIEDownloads);
	return S_OK;
}

STDMETHODIMP CFDMIEBHO::DownloadComplete()
{
	InterlockedDecrement (&_cIEDownloads);
	return S_OK;
}

long CFDMIEBHO::get_IEDownloadsCount()
{
	return _cIEDownloads;
}

STDMETHODIMP CFDMIEBHO::DocumentComplete(IDispatch *pDisp, VARIANT *URL)
{
	QueryWindow ();
	SubclassFlashWindows ();
	return S_OK;
}

STDMETHODIMP CFDMIEBHO::WindowStateChanged(DWORD dwFlags, DWORD dwValidFlagsMask)
{
	

	return S_OK;
}

STDMETHODIMP CFDMIEBHO::NavigateComplete2(IDispatch *pDisp, VARIANT *URL)
{
	IUnknownPtr spUnk1 (m_spWB);
	IUnknownPtr spUnk2 (pDisp);
	if (spUnk1 == spUnk2)
	{
		
		bool bOK = false;
		IDispatchPtr spDisp;
		m_spWB->get_Document (&spDisp);
		if (spDisp)
		{	
			IHTMLDocument2Ptr spDoc (spDisp);
			if (spDoc)
			{
				CComBSTR bstr;
				spDoc->get_URL (&bstr);
				if (bstr.Length ())
				{
					vmsCriticalSectionAutoLock csal (&m_cswstrPageUrl);
					m_wstrPageUrl = bstr;
					bOK = true;
				}
			}
		}
		if (!bOK)
		{
			vmsCriticalSectionAutoLock csal (&m_cswstrPageUrl);
			m_wstrPageUrl = L"about:blank";
		}
	}

	QueryWindow ();

	IWebBrowser2Ptr spWb (pDisp);
	IDispatchPtr spdDoc;
	spWb->get_Document (&spdDoc);
	IUnknownPtr spDocUnk (spdDoc);
	bool bHaveHandler = false;
	for (size_t i = 0; i < m_vHtmlEventHandlers.size (); i++)
	{
		if (spDocUnk == m_vHtmlEventHandlers [i]->getUnkParam ())
		{
			bHaveHandler = true;
			break;
		}
	}
	if (!bHaveHandler)
	{
		CHtmlEventSink <CFDMIEBHO> *pHandler = CHtmlEventSink <CFDMIEBHO>::CreateHandler (this, &CFDMIEBHO::OnHtmlEvent, spDocUnk);
		AtlAdvise (spDocUnk, pHandler, __uuidof (HTMLDocumentEvents2), &pHandler->m_dwCookie);
		m_vHtmlEventHandlers.push_back (pHandler);
	}
	
	return S_OK;
}

void extractRect (IHTMLRect *pRect, RECT *prc)
{
	ZeroMemory (prc, sizeof (RECT));
	ATLASSERT (pRect != NULL);
	if (!pRect)
		return;
	long l = 0;
	pRect->get_left (&l); prc->left = l;
	pRect->get_right (&l); prc->right = l;
	pRect->get_top (&l); prc->top = l;
	pRect->get_bottom (&l); prc->bottom = l;
}

float getIE8zoom (IHTMLDocument2 *pDoc)
{
	assert (pDoc != NULL);
	if (!pDoc)
		return 1.0f;

	IHTMLWindow2Ptr spWnd;
	pDoc->get_parentWindow (&spWnd);
	ATLASSERT (spWnd != NULL);
	if (spWnd == NULL)
		return 1.0f;

	IHTMLScreenPtr spScreen;
	spWnd->get_screen (&spScreen);
	IHTMLScreen2Ptr spScreen2 (spScreen);
	IHTMLScreen3Ptr spScreen3 (spScreen);
	if (spScreen2 && spScreen3)
	{
		
		

		long lDeviceDPI = 0;
		spScreen2->get_deviceXDPI (&lDeviceDPI);
		long lLogicalDPI = 0; 
		spScreen2->get_logicalXDPI (&lLogicalDPI);
		assert (lLogicalDPI == 96);
		
		if (lLogicalDPI)
			return (float)lDeviceDPI / (float)lLogicalDPI;
	}

	return 1.0f;
}

void getHtmlElementScreenRect (IHTMLElement *pElement, RECT &rc)
{
	ZeroMemory (&rc, sizeof (rc));
	IHTMLElement2Ptr spElement2 (pElement);
	ATLASSERT (spElement2 != NULL);
	if (spElement2 == NULL)
		return;
	IHTMLRectPtr spRect;
	spElement2->getBoundingClientRect (&spRect);
	ATLASSERT (spRect != NULL);
	if (spRect == NULL)
		return;
	extractRect (spRect, &rc);

	IDispatchPtr spdDoc;
	pElement->get_document (&spdDoc);
	ATLASSERT (spdDoc != NULL);
	if (spdDoc == NULL)
		return;
	IHTMLDocument2Ptr spDoc (spdDoc);
	ATLASSERT (spDoc != NULL);
	if (spDoc == NULL)
		return;

	IHTMLWindow2Ptr spWnd;
	spDoc->get_parentWindow (&spWnd);
	ATLASSERT (spWnd != NULL);
	if (spWnd == NULL)
		return;

	IHTMLWindow3Ptr spWnd3 (spWnd);
	ATLASSERT (spWnd3 != NULL);
	long x, y;
	spWnd3->get_screenLeft (&x);
	spWnd3->get_screenTop (&y);
	
	rc.left += x; rc.right += x;
	rc.top += y; rc.bottom += y;
}

void getScrollsPos (IHTMLDocument2 *pDocument, SIZE &sz)
{
	sz.cx = sz.cy = 0;

	IHTMLElementPtr spBody;
	pDocument->get_body (&spBody);
	if (spBody != NULL)
	{
		IHTMLElement2Ptr spElem2 (spBody);
		if (spElem2 != NULL)
		{
			long x = 0, y = 0;
			spElem2->get_scrollLeft (&x);
			spElem2->get_scrollTop (&y);
			
			if (x == 0 && y == 0)
			{
				IHTMLElementPtr spBodyParent;
				spBody->get_parentElement (&spBodyParent);
				if (spBodyParent != NULL)
				{
					spElem2 = spBodyParent;
					if (spElem2 != NULL)
					{
						spElem2->get_scrollLeft (&x);
						spElem2->get_scrollTop (&y);
					}									
				}
			}
			
			sz.cx = x; sz.cy = y;
		}
	}
}

void CFDMIEBHO::OnHtmlEvent(IUnknown *pDocUnk, DISPID idEvent, VARIANT *pVarResult)
{
	ATLASSERT (pDocUnk != NULL);
	IHTMLDocument2Ptr spDoc (pDocUnk);
	if (spDoc == NULL)
		return;
	
	IHTMLWindow2Ptr spWin;
	IHTMLEventObjPtr spEvent;
	spDoc->get_parentWindow (&spWin);
	spWin->get_event (&spEvent);
	
	if (spEvent != NULL)
	{
		IHTMLElementPtr spElem;
		spEvent->get_srcElement (&spElem);
		if (spElem)
		{
			IShockwaveFlashPtr spFlash (spElem);

			if (spFlash == NULL)
			{
				CComBSTR bsType;
				spEvent->get_type (&bsType);
				if (_wcsicmp (bsType, L"mouseover") == 0 || _wcsicmp (bsType, L"mousemove") == 0)
					ShowGetItButton (BST_HIDE_ONLYIFMOUSEISNOTOVERBUTTON, NULL);
			}
			else 
			{
				CComBSTR bsType;
				spEvent->get_type (&bsType);

				if (bsType != NULL && (_wcsicmp (bsType, L"mouseover") == 0 || _wcsicmp (bsType, L"mousemove") == 0))
				{
					RECT rc; getHtmlElementScreenRect (spElem, rc);
					SIZE sScrolls = {0};
					IHTMLDocument2Ptr spCurDoc (spDoc), spParentDoc;
					CComBSTR bstrLastUrl;
					spDoc->get_URL (&bstrLastUrl);
					do 
					{
						vmsDomHelper::GetParentDocument (spCurDoc, &spParentDoc);
						if (spParentDoc != NULL)
						{
							CComBSTR bstrURL;
							spParentDoc->get_URL (&bstrURL);
							if (wcscmp (bstrLastUrl, bstrURL))
							{
								bstrLastUrl = bstrURL;
								SIZE s = {0}; getScrollsPos (spParentDoc, s);
								sScrolls.cx += s.cx; sScrolls.cy += s.cy;
							}
						}
						spCurDoc = spParentDoc;
						spParentDoc = NULL;
					}
					while (spCurDoc != NULL);
					
					rc.left -= sScrolls.cx; rc.right -= sScrolls.cx;
					rc.top -= sScrolls.cy; rc.bottom -= sScrolls.cy;

					
					
					
					
					float fZoom = getIE8zoom (spDoc);
					rc.top *= fZoom; rc.bottom *= fZoom; 
					rc.left *= fZoom; rc.right *= fZoom;

					

					IDispatchPtr spdRootDoc;
					m_spWB->get_Document (&spdRootDoc);
					IHTMLDocument2Ptr spRootDoc (spdRootDoc);
					ATLASSERT (spRootDoc != NULL);
					if (spRootDoc != NULL)
					{
						CComBSTR bstr;
						spRootDoc->get_URL (&bstr);
						vmsCriticalSectionAutoLock csal (&m_cswstrPageUrl);
						m_wstrPageUrl = bstr;
					}

					IDispatchPtr spdOwnerDoc;
					spElem->get_document (&spdOwnerDoc);
					m_wstrFrameUrl = L"";
					IHTMLDocument2Ptr spOwnerDoc (spdOwnerDoc);
					if (spOwnerDoc != NULL)
					{
						CComBSTR bstr;
						spOwnerDoc->get_URL (&bstr);
						m_wstrFrameUrl = bstr;
					}

					if (m_wstrFrameUrl == m_wstrPageUrl)
						m_wstrFrameUrl = L"";

					GetFlashMovie (spDoc, spFlash, m_wstrSwfUrl);

					CComBSTR bstrFuncName = getJSFunc_fdm_fmb_getElementParam (JSFunc_Name);

					if (!vmsDomHelper::IsJSFunctionKnown (spDoc, bstrFuncName))
						vmsDomHelper::InjectJSCode (spDoc, getJSFunc_fdm_fmb_getElementParam (JSFunc_SrcText));
									
					vector <CComVariant> vArgs; CComVariant vaResult;
					IDispatchPtr spElemDisp (spElem);
					vArgs.push_back (CComVariant ((LPDISPATCH)spElemDisp));
					vArgs.push_back (CComVariant (L"flashvars"));
 					vmsDomHelper::ExecJScript (spDoc, bstrFuncName, vArgs, vaResult);

					if (vaResult.vt == VT_BSTR && vaResult.bstrVal)
						m_wstrFlashVars = vaResult.bstrVal;
					else
						m_wstrFlashVars = L"";

					GatherAllSwfUrlsAndFlashVars (spRootDoc, m_wstrOtherSwfUrls, m_wstrOtherFlashVars, spFlash);

					USES_CONVERSION;
					BOOL bVideo = vmsFlvSniffDll::IsVideoFlash (W2CA (m_wstrPageUrl.c_str ()),
						W2CA (m_wstrFrameUrl.c_str ()), W2CA (m_wstrSwfUrl.c_str ()), W2CA (m_wstrFlashVars.c_str ()), 
						W2CA (m_wstrOtherSwfUrls.c_str ()), W2CA (m_wstrOtherFlashVars.c_str ()));
					
					if (bVideo)
						ShowGetItButton (BST_SHOW, &rc);
				}

				else if (_wcsicmp (bsType, L"mouseout") == 0)
				{
					if (m_pGetItBtn == NULL || !m_pGetItBtn->isShowingMenu ())
						ShowGetItButton (BST_HIDE_ONLYIFMOUSEISNOTOVERBUTTON, NULL);
				}
			}
		}
	}
}

DWORD WINAPI CFDMIEBHO::_threadFlash_GetItButton(LPVOID lp)
{
	CFDMIEBHO *pthis = (CFDMIEBHO*) lp;

	HRESULT hrCoInit = CoInitialize (NULL);
	
	HWND hwndIE = pthis->m_hWnd;

	USES_CONVERSION;
	pthis->m_pGetItBtn->m_strHtmlPageUrl = W2CA (pthis->m_wstrPageUrl.c_str ());
	pthis->m_pGetItBtn->m_strFrameUrl = W2CA (pthis->m_wstrFrameUrl.c_str ());
	pthis->m_pGetItBtn->m_strSwfUrl = W2CA (pthis->m_wstrSwfUrl.c_str ());
	pthis->m_pGetItBtn->m_strFlashVars = W2CA (pthis->m_wstrFlashVars.c_str ());
	pthis->m_pGetItBtn->m_strOtherSwfUrls = W2CA (pthis->m_wstrOtherSwfUrls.c_str ());
	pthis->m_pGetItBtn->m_strOtherFlashVars = W2CA (pthis->m_wstrOtherFlashVars.c_str ());
	pthis->m_pGetItBtn->Create (pthis->m_hWndIeServer, &pthis->m_rcFlash);

	HWND hwndDlIt = pthis->m_pGetItBtn->getHWND ();

	MSG msg; int nRes;
	while (IsWindow (hwndDlIt))
	{
		nRes = GetMessage (&msg, NULL, 0, 0);
		if (nRes == 0 || nRes == -1)
			break;
		TranslateMessage (&msg);
		DispatchMessage (&msg);
	}

	EnterCriticalSection (&pthis->m_csGetItBtn);
	vmsGetItButton* p = pthis->m_pGetItBtn;
	pthis->m_pGetItBtn = NULL;
	LeaveCriticalSection (&pthis->m_csGetItBtn);

	if (SUCCEEDED (hrCoInit))
		CoUninitialize ();

	if (p->Clicked ())
		p->getSniffDll ()->OnDownloadItBtnClicked_ShowMsgIfReq (hwndIE);
	delete p;

	return 0;
}

BOOL CALLBACK FindIeServerWindow_EnumProc (HWND hwnd, LPARAM lp)
{
	TCHAR tszClass [1000] = _T ("");
	GetClassName (hwnd, tszClass, 1000);

	if (_tcsicmp (tszClass, _T ("Internet Explorer_Server")) == 0)
	{
		HWND *phwndIeServer = (HWND*)lp;
		*phwndIeServer = hwnd;
		return FALSE;
	}
	
	return TRUE;
}

void FindIeServerWindow (HWND hwnd, HWND *phwndIeServer)
{
	EnumChildWindows (hwnd, FindIeServerWindow_EnumProc, (LPARAM)phwndIeServer);
}

void CFDMIEBHO::QueryWindow()
{
	if (m_hWnd == NULL)
	{
		IServiceProviderPtr spService (m_spWB);
		IOleWindowPtr spWindow;
		spService->QueryService (SID_SShellBrowser, IID_IOleWindow, (void**)&spWindow);
		if (spWindow != NULL)
			spWindow->GetWindow (&m_hWnd);
	}

	if (m_hWndIeServer == NULL && m_hWnd != NULL)
		FindIeServerWindow (m_hWnd, &m_hWndIeServer);
}

void CFDMIEBHO::ShowGetItButton(GetItBtnShowType enST, const RECT *prcFlash)
{
	EnterCriticalSection (&m_csGetItBtn);

	if (enST == BST_SHOW)
	{
		if (m_pGetItBtn == NULL)
		{
			if (prcFlash)
				m_rcFlash = *prcFlash;
			else
				ZeroMemory (&m_rcFlash, sizeof (RECT));

			if (!vmsGetItButton::Settings_ShowButton ())
			{
				LeaveCriticalSection (&m_csGetItBtn);
				return;
			}

			RetrieveFlashInfo ();
			DWORD dw;
			if (m_htGetIt)
				CloseHandle (m_htGetIt);

			m_pGetItBtn = new vmsGetItButton;
			m_htGetIt = CreateThread (NULL, 0, _threadFlash_GetItButton, this, 0, &dw);
		}
	}
	else
	{
		if (m_pGetItBtn && IsWindow (m_pGetItBtn->getHWND ()))
		{
			if (enST == BST_HIDE_ONLYIFMOUSEISNOTOVERBUTTON)
			{
				RECT rc;
				GetWindowRect (m_pGetItBtn->getHWND (), &rc);
				InflateRect (&rc, 2, 2);
				POINT pt; GetCursorPos (&pt);
				if (PtInRect (&rc, pt))
				{
					LeaveCriticalSection (&m_csGetItBtn);
					return;
				}
			}
			m_pGetItBtn->Close ();
		}
	}

	LeaveCriticalSection (&m_csGetItBtn);
}

void CFDMIEBHO::RetrieveFlashInfo()
{
	POINT pt; GetCursorPos (&pt);
	ScreenToClient (m_hWndIeServer, &pt);
	
	IWebBrowserPtr spWB;
	vmsComGIT::GetInterfaceFromGlobal (m_dwWbCookie, IID_IWebBrowser2, (void**)&spWB);
	if (spWB == NULL)
		return;
	
	IDispatchPtr spDocDisp;
	spWB->get_Document (&spDocDisp);

	IHTMLDocument2Ptr spDoc (spDocDisp);
	
	IHTMLElementPtr spElement;
	spDoc->elementFromPoint (pt.x, pt.y, &spElement);
	
	if (spElement == NULL)
		return;
	
	IShockwaveFlashPtr spFlash (spElement);
	
	if (spFlash == NULL)
		return;

	GetFlashMovie (spDoc, spFlash, m_wstrSwfUrl);
}

void CFDMIEBHO::SubclassFlashWindows()
{
	if (m_hWnd != NULL)
	{
		vector <HWND> vFlashWnds;
		FindFlashWindows (m_hWnd, vFlashWnds);
		for (size_t i = 0; i < vFlashWnds.size (); i++)
			vmsFlashWindowsSubclasser::o ().Subclass (vFlashWnds [i], _FlashWindowProc, this);
	}
}

STDMETHODIMP CFDMIEBHO::StatusTextChange(BSTR bstrText)
{
	QueryWindow ();
	SubclassFlashWindows ();
	return S_OK;
}

CComBSTR CFDMIEBHO::getJSFunc_fdm_fmb_getElementParam(JSFuncWhat enWhat)
{
	if (enWhat == JSFunc_Name)
		return L"fdm_fmb_getElementParam";

	CComBSTR bstr = L"function fdm_fmb_getElementParam (elem, paramName)\
{\
var vars;\
try {\
vars = elem.getAttribute (paramName);\
} catch (e) {}\
if ((vars == null || vars == \"\") && elem.hasChildNodes ())\
{\
try {\
for (var i = 0; i < elem.childNodes.length; i++)\
{\
try{\
if (elem.childNodes[i].getAttribute(\"name\").toLowerCase() == paramName)\
{\
vars = elem.childNodes[i].getAttribute(\"value\");\
break;\
}\
}catch(e){}\
}\
}catch(e){}\
}\
if ((vars == null || vars == \"\") && elem.parentNode && elem.parentNode.hasChildNodes ())\
{\
try {\
for (var i = 0; i < elem.parentNode.childNodes.length; i++) \
{\
try{\
if (elem.parentNode.childNodes[i].getAttribute(\"name\").toLowerCase() == paramName)\
{\
vars = elem.parentNode.childNodes[i].getAttribute(\"value\");\
break;\
}\
}catch(e){}\
}\
}catch(e){}\
}\
return vars;\
}";

	return bstr;
}

CComBSTR CFDMIEBHO::getJSFunc_fdm_fmb_getFlashElementSwfUrl(JSFuncWhat enWhat)
{
	if (enWhat == JSFunc_Name)
		return L"fdm_fmb_getFlashElementSwfUrl";

	

	CComBSTR bstr = L"function fdm_fmb_getFlashElementSwfUrl (elem)\
{\
  var swfSrc;\
  try {swfSrc = elem.data;}catch (e){}\
  if (swfSrc == null || swfSrc == \"\")\
  {\
    try {swfSrc = elem.src;}catch (e){}\
  }\
  if (swfSrc == null || swfSrc == \"\")\
    swfSrc = fdm_fmb_getElementParam (elem, \"src\");\
  if (swfSrc == null || swfSrc == \"\")\
    swfSrc = fdm_fmb_getElementParam (elem, \"movie\");\
  return swfSrc;\
}";

	return bstr;
}

void CFDMIEBHO::GatherAllSwfUrlsAndFlashVars(IHTMLDocument2 *pDoc, wstring &wstrSwfUrls, wstring &wstrFlashVars, IShockwaveFlash *pExceptElement)
{
	wstrSwfUrls = wstrFlashVars = L"";
	GatherAllSwfUrlsAndFlashVars_imp (pDoc, wstrSwfUrls, wstrFlashVars, pExceptElement);
}

void CFDMIEBHO::GatherAllSwfUrlsAndFlashVars_imp(IHTMLDocument2 *pDoc, wstring &wstrSwfUrls, wstring &wstrFlashVars, IShockwaveFlash *pExceptElement)
{
	ATLASSERT (pDoc != NULL);
	if (!pDoc)
		return;

	IHTMLDocument3Ptr spDoc3 (pDoc); 
	
	IHTMLElementCollectionPtr spColl;

	pDoc->get_embeds (&spColl);
	if (spColl != NULL)
	{
		GatherCollectionSwfUrlsAndFlashVars (pDoc, spColl, wstrSwfUrls, wstrFlashVars, pExceptElement);
		spColl = NULL;
	}

	spDoc3->getElementsByTagName (CComBSTR (L"object"), &spColl);
	if (spColl != NULL)
	{
		GatherCollectionSwfUrlsAndFlashVars (pDoc, spColl, wstrSwfUrls, wstrFlashVars, pExceptElement);
		spColl = NULL;
	}

	IHTMLFramesCollection2Ptr spFrames;
	pDoc->get_frames (&spFrames);
	if (spFrames)
	{
		long cFrames = 0;
		spFrames->get_length (&cFrames);
		for (long i = 0; i < cFrames; i++)
		{
			CComVariant vtFrame;
			spFrames->item (&CComVariant (i), &vtFrame);
			ATLASSERT (vtFrame.vt == VT_DISPATCH);
			if (vtFrame.vt == VT_DISPATCH)
			{
				IHTMLWindow2Ptr spFrameWnd (vtFrame.pdispVal);
				if (spFrameWnd)
				{
					IHTMLLocationPtr spLoc;
					spFrameWnd->get_location (&spLoc);
					CComBSTR bstrFrameUrl;
					if (spLoc)
						spLoc->get_href (&bstrFrameUrl);

					IHTMLDocument2Ptr spFrameDoc;
					vmsDomHelper::GetWindowDocument (spFrameWnd, &spFrameDoc);
					if (spFrameDoc)
						GatherAllSwfUrlsAndFlashVars_imp (spFrameDoc, wstrSwfUrls, wstrFlashVars, pExceptElement);
				}
			}
		}
	}
}

void CFDMIEBHO::GatherCollectionSwfUrlsAndFlashVars(IHTMLDocument2 *pDoc, IHTMLElementCollection *pColl, wstring &wstrSwfUrls, wstring &wstrFlashVars, IShockwaveFlash *pExceptElement)
{
	long cItems = 0;
	pColl->get_length (&cItems);

	for (long i = 0; i < cItems; i++)
	{
		IDispatchPtr spdElem;
		pColl->item (CComVariant (i), CComVariant (i), &spdElem);
		ATLASSERT (spdElem != NULL);
		IShockwaveFlashPtr spFlash (spdElem);
		if (spFlash == NULL)
			continue;
		if (spFlash == pExceptElement)
			continue;

		wstring wstr;
		GetFlashMovie (pDoc, spFlash, wstr);
		wstrSwfUrls += wstr;
		wstrSwfUrls += L"\n";
		
		CComBSTR bstrFuncName = getJSFunc_fdm_fmb_getElementParam (JSFunc_Name);
		if (!vmsDomHelper::IsJSFunctionKnown (pDoc, bstrFuncName))
			vmsDomHelper::InjectJSCode (pDoc, getJSFunc_fdm_fmb_getElementParam (JSFunc_SrcText));
		
		vector <CComVariant> vArgs; CComVariant vaResult;
		vArgs.push_back (CComVariant ((LPDISPATCH)spdElem));
		vArgs.push_back (CComVariant (L"flashvars"));
		vmsDomHelper::ExecJScript (pDoc, bstrFuncName, vArgs, vaResult);
		
		if (vaResult.vt == VT_BSTR && vaResult.bstrVal)
			wstrFlashVars += vaResult.bstrVal;
		
		wstrFlashVars += L"\n";
	}
}

void CFDMIEBHO::GetFlashMovie(IHTMLDocument2* pDoc, IShockwaveFlash* pFlash, wstring& wstrResult)
{
	wstrResult = L"";

	assert (pDoc != NULL && pFlash != NULL);
	if (!pDoc)
		return;
	if (!pFlash)
		return;

	CComBSTR bstr;
	pFlash->get_Movie (&bstr);

	if (!bstr.Length ())
		return;

	USES_CONVERSION;
	string strUrl = W2CA (bstr);

	if (vmsUrl::isAbsolute (strUrl.c_str ()))
	{
		wstrResult = bstr;
		return;
	}

	CComBSTR bstrDocUrl;
	pDoc->get_URL (&bstrDocUrl);

	if (bstrDocUrl.Length () == 0)
	{
		wstrResult = bstr;
		return;
	}

	string strUrlAbs;
	vmsUrl::GetAbsoluteUrlFromRelative2 (W2CA (bstrDocUrl), strUrl.c_str (), strUrlAbs);

	wstrResult = A2CW (strUrlAbs.c_str ());
}
