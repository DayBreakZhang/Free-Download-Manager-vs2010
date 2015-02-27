/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __FDMTORRENTFILESRCVR_H_
#define __FDMTORRENTFILESRCVR_H_

#include "resource.h"       

class ATL_NO_VTABLE CFdmTorrentFilesRcvr : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CFdmTorrentFilesRcvr, &CLSID_FdmTorrentFilesRcvr>,
	public IDispatchImpl<IFdmTorrentFilesRcvr, &IID_IFdmTorrentFilesRcvr, &LIBID_FdmLib>
{
public:
	CFdmTorrentFilesRcvr()
	{
		m_bForceSilent = FALSE;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_FDMTORRENTFILESRCVR)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CFdmTorrentFilesRcvr)
	COM_INTERFACE_ENTRY(IFdmTorrentFilesRcvr)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

public:
	STDMETHOD(get_ForceSilent)( BOOL *pVal);
	STDMETHOD(put_ForceSilent)( BOOL newVal);
	STDMETHOD(CreateBtDownload)( BSTR bstrFile);
protected:
	struct _inc_CBRFF_ctx {
		CString strFileUrl;
		CString strFile;
		BOOL bForceSilent;
	};
	static DWORD WINAPI _threadCreateBtDownload(LPVOID lp);
	BOOL m_bForceSilent;
};

#endif 
