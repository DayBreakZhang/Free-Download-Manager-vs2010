/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __FDMUPLOADBTNFORIE_H_
#define __FDMUPLOADBTNFORIE_H_

#include "resource.h"       
#include <docobj.h>
#include <exdisp.h>
#include <mshtml.h>
#include <comdef.h>

class ATL_NO_VTABLE CFDMUploadBtnForIe : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CFDMUploadBtnForIe, &CLSID_FDMUploadBtnForIe>,
	public IDispatchImpl<IFDMUploadBtnForIe, &IID_IFDMUploadBtnForIe, &LIBID_FDMUPLOADBTNFORIELib>,
	public IObjectWithSiteImpl<CFDMUploadBtnForIe>,
	public IOleCommandTarget
{
public:
	CFDMUploadBtnForIe()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_FDMUPLOADBTNFORIE)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CFDMUploadBtnForIe)
	COM_INTERFACE_ENTRY(IFDMUploadBtnForIe)
	COM_INTERFACE_ENTRY(IOleCommandTarget)
	COM_INTERFACE_ENTRY(IObjectWithSite)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

public:
	STDMETHOD(GetSite )(REFIID riid, void **ppvSite);
	STDMETHOD(SetSite )(IUnknown *pUnkSite);
	STDMETHOD(Exec )(const GUID *pCmdGroup, DWORD nCmdID, DWORD nCmdExecOpt, VARIANTARG *pvaIn, VARIANTARG *pvaOut);
	STDMETHOD(QueryStatus  )(const GUID* pCmdGroup, ULONG cCmds, OLECMD prgCmds[], OLECMDTEXT* pCmdText);

protected:
	IWebBrowser2Ptr m_spWb;
};

#endif 
