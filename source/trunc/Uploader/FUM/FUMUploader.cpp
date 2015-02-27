/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FUM.h"
#include "FUMUploader.h"
#include "ChildView.h"

STDMETHODIMP CFUMUploader::CreateUpload(IUploadPackage *pPkg, BOOL bDialogReq, long *pUplId)
{
	USES_CONVERSION;
	vmsUploadsDll::vmsUploadPackage *p = NULL;

	while (_pwndUploads == NULL)
		Sleep (100);

	if (pPkg != NULL)
	{
		_pwndUploads->CreateNewPackage (&p);

		long lCount = 0;
		pPkg->GetFileCount (&lCount);

		for (long i = 0; i < lCount; i++)
		{
			BSTR bstr; 
			pPkg->GetFilePath (i, &bstr);
			p->add (W2A (bstr));
			SysFreeString (bstr);
		}
	
		BSTR bstr = NULL;
		pPkg->get_Name (&bstr);
		if (bstr != NULL)
		{
			p->set_name (W2A (bstr));
			SysFreeString (bstr);
		}
	}

	return _pwndUploads->CreateUpload (p, bDialogReq, pUplId) ? S_OK : E_FAIL;
}

STDMETHODIMP CFUMUploader::GetUploadTargetUrl(long lId, BSTR *pbstrUrl)
{
	USES_CONVERSION;
	char szUrl [10000]; DWORD dw = sizeof (szUrl);
	
	if (false == _pwndUploads->GetUploadUrl (lId, szUrl, &dw))
		return E_FAIL;
	
	if (*szUrl == 0)
		return S_FALSE;

	*pbstrUrl = SysAllocString (A2W (szUrl));

	return S_OK;
}

STDMETHODIMP CFUMUploader::GetUploadPackageName(long lId, BSTR *pbstrName)
{
	USES_CONVERSION;
	char szName [10000];
	if (false == _pwndUploads->GetUploadPackageName (lId, szName, sizeof (szName)))
		return E_FAIL;
	
	*pbstrName = SysAllocString (A2W (szName));

	return S_OK;
}

