/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __FDMIEBHO_H_
#define __FDMIEBHO_H_

#include "resource.h"       
#include <exdisp.h>
#include <comdef.h>
#include <fsString.h>
#include "vmsGetItButton.h"
#include <string>
#include <mflash.h>
#include "HTMLEventSink.h"

#define DISABLE_OLD_MONITORING_HELPER

class ATL_NO_VTABLE CFDMIEBHO : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CFDMIEBHO, &CLSID_FDMIEBHO>,
	public IObjectWithSiteImpl<CFDMIEBHO>,
	public IDispatchImpl<IFDMIEBHO, &IID_IFDMIEBHO, &LIBID_IEFDMBHOLib>
{
public:
	CFDMIEBHO()
	{
		Instance inst;
		inst.pBHO = this;
		EnterCriticalSection (&_csInstances);
		_vInstances.push_back (inst);
		LeaveCriticalSection (&_csInstances);

		#ifndef DISABLE_OLD_MONITORING_HELPER
			m_hFile = INVALID_HANDLE_VALUE;		
			m_mxFile = CreateMutex (NULL, FALSE, "vmsMX::fdmietmpcookiesfileops");
		#endif
		m_hWnd = NULL; m_hWndIeServer = NULL;
		m_pGetItBtn = NULL;
		m_dwWbCookie = 0;
		InitializeCriticalSection (&m_csGetItBtn);
		m_htGetIt = NULL;
	}

	~CFDMIEBHO () 
	{
		WaitForSingleObject (m_htGetIt, 10*1000);
		DeleteCriticalSection (&m_csGetItBtn);

		EnterCriticalSection (&_csInstances);
		int nIndex = findInstanceIndex (this);
		assert (nIndex != -1);
		if (nIndex != -1)
			_vInstances.erase (_vInstances.begin () + nIndex);
		LeaveCriticalSection (&_csInstances);
	}

DECLARE_REGISTRY_RESOURCEID(IDR_FDMIEBHO)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CFDMIEBHO)
	COM_INTERFACE_ENTRY(IFDMIEBHO)
	COM_INTERFACE_ENTRY(IObjectWithSite)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

public:
	STDMETHOD(StatusTextChange)( BSTR bstrText);
	STDMETHOD(NavigateComplete2)( IDispatch *pDisp,  VARIANT *URL);
	STDMETHOD(WindowStateChanged)(DWORD dwFlags, DWORD dwValidFlagsMask);
	STDMETHOD(DocumentComplete)( IDispatch *pDisp,  VARIANT *URL);
	static long get_IEDownloadsCount();
	STDMETHOD(DownloadComplete)();
	STDMETHOD(DownloadBegin)();
	STDMETHOD(BeforeNavigate2)(IDispatch*, VARIANT* url, VARIANT* flags, VARIANT* tfn, VARIANT* pd, VARIANT* headers, VARIANT_BOOL* bCancel);
	STDMETHOD(ProgressChange)(long Progress, long ProgressMax);
	STDMETHOD(GetSite)(REFIID riid, void **ppvSite);
	STDMETHOD(SetSite )(IUnknown *pSite);

public:
	std::wstring m_wstrPageUrl;
	vmsCriticalSection m_cswstrPageUrl;

protected:
	void GatherAllSwfUrlsAndFlashVars (IHTMLDocument2 *pDoc, wstring &wstrSwfUrls, wstring &wstrFlashVars, IShockwaveFlash *pExceptElement);
	void GatherAllSwfUrlsAndFlashVars_imp (IHTMLDocument2 *pDoc, wstring &wstrSwfUrls, wstring &wstrFlashVars, IShockwaveFlash *pExceptElement);
	void GatherCollectionSwfUrlsAndFlashVars(IHTMLDocument2 *pDoc, IHTMLElementCollection *pColl, wstring &wstrSwfUrls, wstring &wstrFlashVars, IShockwaveFlash *pExceptElement);
	enum JSFuncWhat
	{
		JSFunc_Name			= 0,
		JSFunc_SrcText		= 1,
	};
	static CComBSTR getJSFunc_fdm_fmb_getElementParam (JSFuncWhat enWhat);
	static CComBSTR getJSFunc_fdm_fmb_getFlashElementSwfUrl (JSFuncWhat enWhat);
	CRITICAL_SECTION m_csGetItBtn;
	HANDLE m_htGetIt;
	RECT m_rcFlash;
	void SubclassFlashWindows ();
	std::wstring m_wstrFrameUrl, m_wstrSwfUrl, m_wstrFlashVars, 
		m_wstrOtherSwfUrls, m_wstrOtherFlashVars;
	void RetrieveFlashInfo();
	DWORD m_dwWbCookie;
	enum GetItBtnShowType
	{
		BST_SHOW,
		BST_HIDE,
		BST_HIDE_ONLYIFMOUSEISNOTOVERBUTTON,
	};
	void ShowGetItButton (GetItBtnShowType enST, const RECT *prcFlash);
	vmsGetItButton* m_pGetItBtn;
	void QueryWindow();
	HWND m_hWnd, m_hWndIeServer; 
	static DWORD WINAPI _threadFlash_GetItButton (LPVOID lp);
	static LRESULT CALLBACK _FlashWindowProc (HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);
	DWORD m_dwCookieHtmlEvents;
	void OnHtmlEvent (IUnknown *pDocUnk, DISPID idEvent, VARIANT *pVarResult);
	vector <CHtmlEventSink <CFDMIEBHO>*> m_vHtmlEventHandlers;
#ifndef DISABLE_OLD_MONITORING_HELPER
	void AnalyzePageAndWriteInfo();
	void DeleteFile();
	void WalkThroughForm (IHTMLElement* pElement, fsString& str);
	HANDLE m_mxFile;
	void SaveInfoToDisk();
	fsString m_strCookies;
	fsString m_strUrl;
	fsString m_strPostData;
	fsString m_strBeforeNavUrl;
	fsString m_strTmpFile;	
	HANDLE m_hFile;
#endif
	static long _cIEDownloads;
	STDMETHOD(Disconnect)();
	STDMETHOD(Connect)();

	IConnectionPointContainerPtr m_spWB_CPC;
	IWebBrowser2Ptr m_spWB;
	DWORD m_dwCookie;
	IConnectionPointPtr m_spWB_CPC_CP;

public:
	struct Instance
	{
		CFDMIEBHO *pBHO;
		DWORD dwMainThreadId;

		Instance () {
			pBHO = NULL;
			dwMainThreadId = 0;
		}
	};
	static vector <Instance> _vInstances;
	static vmsCriticalSection _csInstances;
	static int findInstanceIndex (CFDMIEBHO *pInstance)
	{
		for (size_t i = 0; i < _vInstances.size (); i++)
		{
			if (_vInstances [i].pBHO == pInstance)
				return (int)i;
		}
		return -1;
	}
	static int findInstanceIndexByThreadId (DWORD dwId)
	{
		for (size_t i = 0; i < _vInstances.size (); i++)
		{
			if (_vInstances [i].dwMainThreadId == dwId)
				return (int)i;
		}
		return -1;
	}
	void GetFlashMovie(IHTMLDocument2* pDoc, IShockwaveFlash* pFlash, wstring& wstrResult);
};

#endif 
