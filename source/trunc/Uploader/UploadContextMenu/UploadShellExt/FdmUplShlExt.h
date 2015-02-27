/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __FDMUPLSHLEXT_H_
#define __FDMUPLSHLEXT_H_

#include "resource.h"       
#include <shlobj.h>
#include <comdef.h>
#include <vector>
#include <fsString.h>

class ATL_NO_VTABLE CFdmUplShlExt : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CFdmUplShlExt, &CLSID_FdmUplShlExt>,
	public IDispatchImpl<IFdmUplShlExt, &IID_IFdmUplShlExt, &LIBID_UPLOADSHELLEXTLib>,
	public IShellExtInit,
	public IContextMenu
{
public:
	CFdmUplShlExt()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_FDMUPLSHLEXT)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CFdmUplShlExt)
	COM_INTERFACE_ENTRY(IFdmUplShlExt)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IShellExtInit)
	COM_INTERFACE_ENTRY(IContextMenu)
END_COM_MAP()

public:
	STDMETHOD(QueryContextMenu )(HMENU hmenu, UINT indexMenu, UINT idCmdFirst, UINT idCmdLast, UINT uFlags);
	STDMETHOD(InvokeCommand )(LPCMINVOKECOMMANDINFO pici);
	STDMETHOD(GetCommandString )(UINT_PTR idCmd, UINT uFlags, UINT *pwReserved, LPSTR pszName, UINT cchMax);
	STDMETHOD(Initialize )(LPCITEMIDLIST pidlFolder, IDataObject *pdtobj, HKEY hkeyProgID);
protected:
	std::vector <fsString> m_vFiles;
};

#endif 
