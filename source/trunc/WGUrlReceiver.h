/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __WGURLRECEIVER_H_
#define __WGURLRECEIVER_H_

#include "resource.h"       
#include <objsafe.h>
#include "FdmUiWindow.h"

class ATL_NO_VTABLE CWGUrlReceiver : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CWGUrlReceiver, &CLSID_WGUrlReceiver>,
	public IDispatchImpl<IWGUrlReceiver, &IID_IWGUrlReceiver, &LIBID_FdmLib>,
	public IServiceProvider
{
public:
	CWGUrlReceiver()
	{
		m_bCheckExt = FALSE;
		m_bIgnoreSize = TRUE;
		m_hJobt = NULL;
		m_dlInfo.bForceSilent = FALSE;
		m_dlInfo.bForceAutoStart = FALSE;
		m_dlInfo.bDisableMaliciousChecking = FALSE;
		m_dlInfo.bDisableURLExistsChecking = FALSE;
		m_dlInfo.bFlashVideoDownload = FALSE;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_WGURLRECEIVER)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CWGUrlReceiver)
	COM_INTERFACE_ENTRY(IWGUrlReceiver)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IServiceProvider)
END_COM_MAP()

BEGIN_CATEGORY_MAP(CWGUrlReceiver)
	IMPLEMENTED_CATEGORY(CATID_SafeForScripting)
	IMPLEMENTED_CATEGORY(CATID_SafeForInitializing)
END_CATEGORY_MAP()

public:
	STDMETHOD(get_FileSize)( BSTR *pVal);
	STDMETHOD(put_FileSize)( BSTR newVal);
	STDMETHOD(get_FlashVideoDownload)( BOOL *pVal);
	STDMETHOD(put_FlashVideoDownload)( BOOL newVal);
	STDMETHOD(get_FileName)( BSTR *pVal);
	STDMETHOD(put_FileName)( BSTR newVal);
	STDMETHOD(get_DisableURLExistsCheck)( BOOL *pVal);
	STDMETHOD(put_DisableURLExistsCheck)( BOOL newVal);
	STDMETHOD(get_DisableMaliciousChecking)( BOOL *pVal);
	STDMETHOD(put_DisableMaliciousChecking)( BOOL newVal);
	STDMETHOD(get_ForceDownloadAutoStart)( BOOL *pVal);
	STDMETHOD(put_ForceDownloadAutoStart)( BOOL newVal);
	STDMETHOD(get_ForceSilentEx)( BOOL *pVal);
	STDMETHOD(put_ForceSilentEx)( BOOL newVal);
	STDMETHOD(get_PostData)( BSTR *pVal);
	STDMETHOD(put_PostData)( BSTR newVal);
	STDMETHOD(get_Cookies)( BSTR *pVal);
	STDMETHOD(put_Cookies)( BSTR newVal);
	STDMETHOD(get_ForceSilent)( BOOL *pVal);
	STDMETHOD(put_ForceSilent)( BOOL newVal);
	STDMETHOD(get_UIState)( BSTR *pVal);
	STDMETHOD(get_UseSkipExtsList)( BOOL *pVal);
	STDMETHOD(put_UseSkipExtsList)( BOOL newVal);
	void FinalRelease();
	STDMETHOD(get_IgnoreSize)( BOOL *pVal);
	STDMETHOD(put_IgnoreSize)( BOOL newVal);
	STDMETHOD(get_CheckExtension)( BOOL *pVal);
	STDMETHOD(put_CheckExtension)( BOOL newVal);
	STDMETHOD(AddDownload)();
	
	STDMETHOD(get_Referer)( BSTR *pVal);
	STDMETHOD(put_Referer)( BSTR newVal);
	
	STDMETHOD(get_Comment)( BSTR *pVal);
	STDMETHOD(put_Comment)( BSTR newVal);
	
	STDMETHOD(get_Url)( BSTR *pVal);
	STDMETHOD(put_Url)( BSTR newVal);
	
	STDMETHOD(ShowAddPageDownloadDialog)();
	
	STDMETHOD(ShowAddDownloadDialog)();
protected:
	void CheckRapidshare();
	void StartJobThread (LPTHREAD_START_ROUTINE pfn);
	static DWORD WINAPI _threadAddPage (LPVOID lp);
	HANDLE m_hJobt;
	struct _ic_DownloadInfo	{
		CComBSTR bstrUrl, bstrOriginalUrl, bstrComment, bstrReferer, 
			bstrCookies, bstrPostData, bstrFileName,
			bstrFileSize;
		BOOL bForceSilent;
		BOOL bNoUIInForceSilentMode;
		BOOL bForceAutoStart;
		BOOL bDisableMaliciousChecking;
		BOOL bDisableURLExistsChecking;
		BOOL bFlashVideoDownload;
		CComBSTR bstrUserAgent;
		class CFdmUiWindow *pUiWindow;
	};

	BOOL is_ExtToSkip ();
	static DWORD WINAPI _threadAddDownload (LPVOID lp);
	static HRESULT AddDownload_imp(_ic_DownloadInfo* dlinfo);
	_ic_DownloadInfo m_dlInfo;
	BOOL m_bCheckExt;
	BOOL m_bIgnoreSize;
public:
	STDMETHOD(get_OriginalURL)(BSTR* pVal);
	STDMETHOD(put_OriginalURL)(BSTR newVal);
	STDMETHOD(get_UserAgent)(BSTR* pVal);
	STDMETHOD(put_UserAgent)(BSTR newVal);

	STDMETHODIMP QueryService (REFGUID guidService, REFIID riid, void** ppvObject)
	{
		if (IsEqualIID (guidService, IID_IFdmUiWindow))
		{
			vmsAUTOLOCKSECTION (m_csLastUiWindow);
			if (m_spLastUiWindow)
				return m_spLastUiWindow->QueryInterface (riid, ppvObject);
		}
		return E_NOINTERFACE;
	}

	protected:
		IFdmUiWindowPtr m_spLastUiWindow;
		vmsCriticalSection m_csLastUiWindow;
};

#endif 
