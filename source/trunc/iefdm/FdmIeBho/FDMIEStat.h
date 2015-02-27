/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __FDMIESTAT_H_
#define __FDMIESTAT_H_

#include "resource.h"       

class ATL_NO_VTABLE CFDMIEStat : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CFDMIEStat, &CLSID_FDMIEStat>,
	public IDispatchImpl<IFDMIEStat, &IID_IFDMIEStat, &LIBID_IEFDMBHOLib>
{
public:
	CFDMIEStat()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_FDMIESTAT)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CFDMIEStat)
	COM_INTERFACE_ENTRY(IFDMIEStat)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

public:
	STDMETHOD(get_DownloadCount)( long *pVal);
};

#endif 
