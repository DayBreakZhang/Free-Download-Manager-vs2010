/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "FDMUploader.h"
#include "UploadsWnd.h"

STDMETHODIMP CFDMUploader::CreateUpload(IUploadPackage *pPkg, BOOL bDialogReq, long *pUplId)
{
	if (_pwndUploads == NULL || _pwndUploads->m_pwndUploads == NULL)
		return E_FAIL;

	USES_CONVERSION;
	vmsUploadsDll::vmsUploadPackage *p = NULL;

	if (pPkg != NULL)
	{
		_pwndUploads->m_pwndUploads->CreateNewPackage (&p);

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

	return _pwndUploads->m_pwndUploads->CreateUpload (p, bDialogReq, pUplId) ? S_OK : E_FAIL;
}

STDMETHODIMP CFDMUploader::GetUploadTargetUrl(long lId, BSTR *pbstrUrl)
{
	if (_pwndUploads == NULL || _pwndUploads->m_pwndUploads == NULL)
		return E_FAIL;

	USES_CONVERSION;
	char szUrl [10000]; DWORD dw = sizeof (szUrl);
	
	if (false == _pwndUploads->m_pwndUploads->GetUploadUrl (lId, szUrl, &dw))
		return E_FAIL;
	
	if (*szUrl == 0)
		return S_FALSE;

	*pbstrUrl = SysAllocString (A2W (szUrl));

	return S_OK;
}

STDMETHODIMP CFDMUploader::GetUploadPackageName(long lId, BSTR *pbstrName)
{
	if (_pwndUploads == NULL || _pwndUploads->m_pwndUploads == NULL)
		return E_FAIL;

	USES_CONVERSION;
	char szName [10000];
	if (false == _pwndUploads->m_pwndUploads->GetUploadPackageName (lId, szName, sizeof (szName)))
		return E_FAIL;
	
	*pbstrName = SysAllocString (A2W (szName));

	return S_OK;
}
