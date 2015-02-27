/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __FDMCUSTBUTTON_H_
#define __FDMCUSTBUTTON_H_

#include "resource.h"       
#include <docobj.h>
#include <exdisp.h>

class ATL_NO_VTABLE CFDMCustButton : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CFDMCustButton, &CLSID_FDMCustButton>,
	public IFDMCustButton,
	public IOleCommandTarget,
	public IObjectWithSite
{
public:
	CFDMCustButton()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_FDMCUSTBUTTON)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CFDMCustButton)
	COM_INTERFACE_ENTRY(IFDMCustButton)
	COM_INTERFACE_ENTRY(IOleCommandTarget)
	COM_INTERFACE_ENTRY(IObjectWithSite)
END_COM_MAP()

public:
protected:
	CComPtr <IWebBrowser2> m_spBrowser;

	STDMETHOD(GetSite )(REFIID riid, void **ppvSite);
	STDMETHOD(SetSite )(IUnknown *pUnkSite);
	STDMETHOD(Exec )(const GUID *pCmdGroup, DWORD nCmdID, DWORD nCmdExecOpt, VARIANTARG *pvaIn, VARIANTARG *pvaOut);
	STDMETHOD(QueryStatus) (const GUID* pCmdGroup, ULONG cCmds, OLECMD prgCmds[], OLECMDTEXT* pCmdText);
};

#endif 
