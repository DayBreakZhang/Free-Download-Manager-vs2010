/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __FUMUPLOADER_H_
#define __FUMUPLOADER_H_

#include "resource.h"       
#include "fuminterfaces.h"

class ATL_NO_VTABLE CFUMUploader : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CFUMUploader, &CLSID_FUMUploader>,
	public IDispatchImpl<IUploader, &IID_IUploader, &LIBID_FUMLib>
{
public:
	CFUMUploader()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_FUMUPLOADER)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CFUMUploader)
	COM_INTERFACE_ENTRY(IUploader)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

public:
	STDMETHOD(GetUploadPackageName)( long lId,  BSTR* pbstrName);
	STDMETHOD(GetUploadTargetUrl)( long lId,  BSTR* pbstrUrl);
	STDMETHOD(CreateUpload)( IUploadPackage *pPkg,  BOOL bDialogReq,  long* pUplId);
};

#endif 
