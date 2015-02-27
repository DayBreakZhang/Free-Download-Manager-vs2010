/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __WGURLLISTRECEIVER_H_
#define __WGURLLISTRECEIVER_H_

#include "resource.h"       
#include <objsafe.h>
#include "FdmUiWindow.h"

class ATL_NO_VTABLE CWgUrlListReceiver : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CWgUrlListReceiver, &CLSID_WGUrlListReceiver>,
	public IDispatchImpl<IWGUrlListReceiver, &IID_IWGUrlListReceiver, &LIBID_FdmLib>,
	public IServiceProvider
{
public:
	CWgUrlListReceiver()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_WGURLLISTRECEIVER)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CWgUrlListReceiver)
	COM_INTERFACE_ENTRY(IWGUrlListReceiver)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IServiceProvider)
END_COM_MAP()

BEGIN_CATEGORY_MAP(CWGUrlReceiver)
	IMPLEMENTED_CATEGORY(CATID_SafeForScripting)
	IMPLEMENTED_CATEGORY(CATID_SafeForInitializing)
END_CATEGORY_MAP()

public:
	STDMETHOD(get_Cookies)( BSTR *pVal);
	STDMETHOD(put_Cookies)( BSTR newVal);
	STDMETHOD(GetUrlListFromDocumentSelection)( IDispatch *pDispatch);
	STDMETHOD(AddUrlToList)();
	STDMETHOD(ShowAddUrlListDialog)();
	STDMETHOD(get_Referer)( BSTR *pVal);
	STDMETHOD(put_Referer)( BSTR newVal);
	STDMETHOD(get_Comment)( BSTR *pVal);
	STDMETHOD(put_Comment)( BSTR newVal);
	STDMETHOD(get_Url)( BSTR *pVal);
	STDMETHOD(put_Url)( BSTR newVal);

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
	struct threadAddUrlListDialogParam
	{
		CWgUrlListReceiver *pthis; 
		CFdmUiWindow *pUiWindow;
	};
	static DWORD WINAPI _threadAddUrlListDialog(LPVOID lp);
	fs::list <fsString> m_vUrls, m_vComments, m_vReferers, m_vCookies;
	CComBSTR m_bstrUrl, m_bstrComment, m_bstrReferer, m_bstrCookies;
	IFdmUiWindowPtr m_spLastUiWindow;
	vmsCriticalSection m_csLastUiWindow;
};

#endif 
