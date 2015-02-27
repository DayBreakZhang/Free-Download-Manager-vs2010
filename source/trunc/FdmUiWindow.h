/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once

#include "resource.h"
#include "fdm.h"

_COM_SMARTPTR_TYPEDEF(IFdmUiWindow, __uuidof(IFdmUiWindow));

class ATL_NO_VTABLE CFdmUiWindow : public 
	CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CFdmUiWindow, &CLSID_FdmUiWindow>,
	public IDispatchImpl<IFdmUiWindow, &IID_IFdmUiWindow, &LIBID_FdmLib>
{
public:

	CFdmUiWindow(void);

DECLARE_REGISTRY_RESOURCEID(IDR_FDMUIWINDOW)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CFdmUiWindow)
	COM_INTERFACE_ENTRY(IFdmUiWindow)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY_AGGREGATE(IID_IMarshal, m_pUnkMarshaler.p)
END_COM_MAP()

	virtual ~CFdmUiWindow(void);
	STDMETHOD(get_Handle)(ULONG* pVal);
	STDMETHOD(WaitForWindowCreation)(LONG uTimeoutMilliseconds);

	HRESULT FinalConstruct()
	{
		return CoCreateFreeThreadedMarshaler(
			GetUnknown (), &m_pUnkMarshaler.p);
	}

	void FinalRelease()
	{
		m_pUnkMarshaler.Release();
	}

	CComPtr<IUnknown> m_pUnkMarshaler;

protected:
	HWND m_hWnd;
	HANDLE m_hevWindowCreatedOrFailed;
	bool m_bWindowCreatedOrFailed;
public:
	void setWindow(HWND hwnd);
};
