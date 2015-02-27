/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __FUMAPPLICATION_H_
#define __FUMAPPLICATION_H_

#include "resource.h"       

class ATL_NO_VTABLE CFUMApplication : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CFUMApplication, &CLSID_FUMApplication>,
	public IDispatchImpl<IFUMApplication, &IID_IFUMApplication, &LIBID_FUMLib>
{
public:
	CFUMApplication()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_FUMAPPLICATION)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CFUMApplication)
	COM_INTERFACE_ENTRY(IFUMApplication)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

public:
	STDMETHOD(Shutdown)( BOOL bAskUser);
};

#endif 
