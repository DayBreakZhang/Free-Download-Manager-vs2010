/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __FDMUPLOADER_H_
#define __FDMUPLOADER_H_

#include "resource.h"       
#include "./uploader/fum/fuminterfaces.h"

class ATL_NO_VTABLE CFDMUploader : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CFDMUploader, &CLSID_FDMUploader>,
	public IDispatchImpl<IUploader, &IID_IUploader, &LIBID_FdmLib>
{
public:
	CFDMUploader()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_FDMUPLOADER)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CFDMUploader)
	COM_INTERFACE_ENTRY(IUploader)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

public:
	STDMETHOD(GetUploadPackageName)( long lId,  BSTR* pbstrName);
	STDMETHOD(GetUploadTargetUrl)( long lId,  BSTR* pbstrUrl);
	STDMETHOD(CreateUpload)( IUploadPackage *pPkg,  BOOL bDialogReq,  long* pUplId);
};

#endif 
