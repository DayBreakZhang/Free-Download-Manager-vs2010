/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __FDMDOWNLOAD_H_
#define __FDMDOWNLOAD_H_

#include "resource.h"       

class ATL_NO_VTABLE CFDMDownload : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CFDMDownload, &CLSID_FDMDownload>,
	public IDispatchImpl<IFDMDownload, &IID_IFDMDownload, &LIBID_FdmLib>
{
public:
	CFDMDownload()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_FDMDOWNLOAD)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CFDMDownload)
	COM_INTERFACE_ENTRY(IFDMDownload)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

public:
	STDMETHOD(get_DownloadText)( long nTextIndex,  BSTR *pVal);
	void ReadFromDownload (vmsDownloadSmartPtr dld);
	STDMETHOD(get_Url)( BSTR *pVal);
	STDMETHOD(put_Url)( BSTR newVal);

protected:
	fsString m_strUrl;
	fsString m_astrDldTexts [6];

};

#endif 
