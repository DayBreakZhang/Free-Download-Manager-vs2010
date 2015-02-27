/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __FDMUPLSENDTOSHLEXT_H_
#define __FDMUPLSENDTOSHLEXT_H_

#include "resource.h"       

#include <comdef.h>
#include <shlobj.h>
#include <vector>
#include <fsString.h>

class ATL_NO_VTABLE CFdmUplSendToShlExt : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CFdmUplSendToShlExt, &CLSID_FdmUplSendToShlExt>,
	public IDispatchImpl<IFdmUplSendToShlExt, &IID_IFdmUplSendToShlExt, &LIBID_UPLOADSHELLEXTLib>,
	public IPersistFile,
	public IDropTarget
{
public:
	CFdmUplSendToShlExt()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_FDMUPLSENDTOSHLEXT)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CFdmUplSendToShlExt)
	COM_INTERFACE_ENTRY(IFdmUplSendToShlExt)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IPersistFile)
	COM_INTERFACE_ENTRY(IDropTarget)
END_COM_MAP()

public:
	
    STDMETHOD(GetClassID)(LPCLSID)      { return E_NOTIMPL; }
    STDMETHOD(IsDirty)()                { return E_NOTIMPL; }
    STDMETHOD(Load)(LPCOLESTR, DWORD)   { return S_OK;      }
    STDMETHOD(Save)(LPCOLESTR, BOOL)    { return E_NOTIMPL; }
    STDMETHOD(SaveCompleted)(LPCOLESTR) { return E_NOTIMPL; }
    STDMETHOD(GetCurFile)(LPOLESTR*)    { return E_NOTIMPL; }

	
    STDMETHOD(DragEnter)(IDataObject* pDataObj, DWORD grfKeyState,
                         POINTL pt, DWORD* pdwEffect);

    STDMETHOD(DragOver)(DWORD grfKeyState, POINTL pt, DWORD* pdwEffect)
        { return E_NOTIMPL; }

    STDMETHOD(DragLeave)();

    STDMETHOD(Drop)(IDataObject* pDataObj, DWORD grfKeyState,
                    POINTL pt, DWORD* pdwEffect);

protected:
	std::vector <fsString> m_vFiles;
};

#endif 
