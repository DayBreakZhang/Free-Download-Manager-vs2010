/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __FDM_H_
#define __FDM_H_

#include "resource.h"       

class ATL_NO_VTABLE CFDM : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CFDM, &CLSID_FDM>,
	public IDispatchImpl<IFDM, &IID_IFDM, &LIBID_FdmLib>
{
public:
	CFDM()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_FDM)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CFDM)
	COM_INTERFACE_ENTRY(IFDM)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

public:
	
	
	STDMETHOD(Shutdown)( BOOL bAskUser);
};

#endif 
