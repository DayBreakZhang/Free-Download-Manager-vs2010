/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __FDMDOWNLOADSSTAT_H_
#define __FDMDOWNLOADSSTAT_H_

#include "resource.h"       
#include "FDMDownload.h"

_COM_SMARTPTR_TYPEDEF (IFDMDownload, __uuidof (IFDMDownload));

class ATL_NO_VTABLE CFDMDownloadsStat : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CFDMDownloadsStat, &CLSID_FDMDownloadsStat>,
	public IDispatchImpl<IFDMDownloadsStat, &IID_IFDMDownloadsStat, &LIBID_FdmLib>
{
public:
	CFDMDownloadsStat()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_FDMDOWNLOADSSTAT)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CFDMDownloadsStat)
	COM_INTERFACE_ENTRY(IFDMDownloadsStat)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

public:
	STDMETHOD(BuildListOfDownloads)( BOOL bIncludeCompleted,  BOOL bIncludeRunning);
	STDMETHOD(get_Download)( long nIndex,  IFDMDownload* *pVal);
	STDMETHOD(get_DownloadCount)( long *pVal);
protected:
	
	void AddDownloadToList (vmsDownloadSmartPtr dld);
	
	
	fs::list <IFDMDownloadPtr> m_vDownloads;
};

#endif 
