/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __IEWGMONITOR_H_
#define __IEWGMONITOR_H_

#include "resource.h"       
#include <urlmon.h>

class ATL_NO_VTABLE CIEWGMonitor : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CIEWGMonitor, &CLSID_IEWGMonitor>,
	public IInternetProtocol
{
public:
	CIEWGMonitor()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_IEWGMONITOR)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CIEWGMonitor)
	COM_INTERFACE_ENTRY(IInternetProtocol)
	COM_INTERFACE_ENTRY(IInternetProtocolRoot)
END_COM_MAP()

public:
protected:
	STDMETHOD(UnlockRequest)();
	STDMETHOD(Seek )(LARGE_INTEGER, DWORD, ULARGE_INTEGER*);
	STDMETHOD(Read )(LPVOID, ULONG, ULONG*);
	STDMETHOD(LockRequest )(DWORD);
	STDMETHOD(Terminate )(DWORD);
	STDMETHOD(Suspend)();
	STDMETHOD(Start )(LPCWSTR pszwUrl, IInternetProtocolSink*, IInternetBindInfo*, DWORD, DWORD);
	STDMETHOD(Resume)();
	STDMETHOD(Continue )(PROTOCOLDATA*);
	STDMETHODIMP Abort (HRESULT, DWORD);
};

#endif 
