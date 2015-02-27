/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __FDMUPLSHELLEXTS_H_
#define __FDMUPLSHELLEXTS_H_

#include "resource.h"       

class ATL_NO_VTABLE CFdmUplShellExts : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CFdmUplShellExts, &CLSID_FdmUplShellExts>,
	public IDispatchImpl<IFdmUplShellExts, &IID_IFdmUplShellExts, &LIBID_UPLOADSHELLEXTLib>
{
public:
	CFdmUplShellExts()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_FDMUPLSHELLEXTS)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CFdmUplShellExts)
	COM_INTERFACE_ENTRY(IFdmUplShellExts)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

public:
	STDMETHOD(get_ShowInSendToContextMenu)( BOOL *pVal);
	STDMETHOD(put_ShowInSendToContextMenu)( BOOL newVal);
	STDMETHOD(get_ShowInExplorerContextMenu)( BOOL *pVal);
	STDMETHOD(put_ShowInExplorerContextMenu)( BOOL newVal);
};

#endif 
