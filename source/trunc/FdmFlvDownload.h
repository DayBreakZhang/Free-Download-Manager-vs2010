/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __FDMFLVDOWNLOAD_H_
#define __FDMFLVDOWNLOAD_H_

#include "resource.h"       

_COM_SMARTPTR_TYPEDEF(IWGUrlReceiver, __uuidof(IWGUrlReceiver));

class ATL_NO_VTABLE CFdmFlvDownload : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CFdmFlvDownload, &CLSID_FdmFlvDownload>,
	public IDispatchImpl<IFdmFlvDownload, &IID_IFdmFlvDownload, &LIBID_FdmLib>
{
public:
	CFdmFlvDownload()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_FDMFLVDOWNLOAD)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CFdmFlvDownload)
	COM_INTERFACE_ENTRY(IFdmFlvDownload)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

public:
	STDMETHOD(get_Url)( IWGUrlReceiver* *pVal);
	STDMETHOD(put_Url)( IWGUrlReceiver* newVal);
protected:
	IWGUrlReceiverPtr m_spUrl;
};

#endif 
