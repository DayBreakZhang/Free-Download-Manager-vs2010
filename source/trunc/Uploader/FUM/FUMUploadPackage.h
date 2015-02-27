/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __FUMUPLOADPACKAGE_H_
#define __FUMUPLOADPACKAGE_H_

#include "resource.h"       
#include <vector>
#include "fuminterfaces.h"

class ATL_NO_VTABLE CFUMUploadPackage : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CFUMUploadPackage, &CLSID_FUMUploadPackage>,
	public IDispatchImpl<IUploadPackage, &IID_IUploadPackage, &LIBID_FUMLib>
{
public:
	CFUMUploadPackage()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_FUMUPLOADPACKAGE)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CFUMUploadPackage)
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
