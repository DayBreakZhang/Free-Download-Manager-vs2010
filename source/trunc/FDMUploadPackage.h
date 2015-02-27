/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __FDMUPLOADPACKAGE_H_
#define __FDMUPLOADPACKAGE_H_

#include "resource.h"       
#include "./uploader/fum/fuminterfaces.h"

class ATL_NO_VTABLE CFDMUploadPackage : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CFDMUploadPackage, &CLSID_FDMUploadPackage>,
	public IDispatchImpl<IUploadPackage, &IID_IUploadPackage, &LIBID_FdmLib>
{
public:
	CFDMUploadPackage()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_FDMUPLOADPACKAGE)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CFDMUploadPackage)
	COM_INTERFACE_ENTRY(IUploadPackage)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

public:
	STDMETHOD(GetFilePath)( long nIndex,  BSTR* pbstrPathName);
	STDMETHOD(GetFileCount)( long* pCount);
	STDMETHOD(get_Name)( BSTR *pVal);
	STDMETHOD(put_Name)( BSTR newVal);
	STDMETHOD(Add)( BSTR bstrPathName);

protected:
	std::vector <fsString> m_vFiles;
	fsString m_strName;
};

#endif 
