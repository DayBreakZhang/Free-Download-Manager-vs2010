/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __WGBHO_H_
#define __WGBHO_H_

#include "resource.h"       
#include <Exdisp.h>
#include <mshtml.h>
#include <fsString.h>

class ATL_NO_VTABLE CWgBHO : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CWgBHO, &CLSID_WgBHO>,
	public IObjectWithSiteImpl<CWgBHO>,
	public IDispatchImpl<IWgBHO, &IID_IWgBHO, &LIBID_IEFDMLib>
{
public:
	CWgBHO()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_WGBHO)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CWgBHO)
	COM_INTERFACE_ENTRY(IWgBHO)
	COM_INTERFACE_ENTRY(IObjectWithSite)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

public:
	STDMETHOD(BeforeNavigate2)(IDispatch*, VARIANT* url, VARIANT* flags, VARIANT* tfn, VARIANT* pd, VARIANT* headers, VARIANT_BOOL* bCancel);
protected:
	void WalkThroughForm(IHTMLElement *pElement, fsString& str);
	DWORD m_dwCookie;
	STDMETHOD(Connect)();
	CComQIPtr <IWebBrowser2, &IID_IWebBrowser2> m_spWebBrowser2;
	CComQIPtr <IConnectionPointContainer, &IID_IConnectionPointContainer> m_spCPC;
	STDMETHOD(SetSite )(IUnknown* pSite);
	STDMETHOD(GetSite )(REFIID riid, void** ppvSite);
};

#endif 
