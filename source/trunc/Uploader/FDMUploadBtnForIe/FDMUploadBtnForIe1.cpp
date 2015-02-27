/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FDMUploadBtnForIe.h"
#include "FDMUploadBtnForIe1.h"
#include <shlguid.h>

#include "../FUM/FUM_i.h"
#include "../../Fdm.h"

_COM_SMARTPTR_TYPEDEF (IUploader, __uuidof (IUploader));
_COM_SMARTPTR_TYPEDEF (IUploadPackage, __uuidof (IUploadPackage));

STDMETHODIMP CFDMUploadBtnForIe::QueryStatus(const GUID *pCmdGroup, ULONG cCmds, OLECMD prgCmds[], OLECMDTEXT *pCmdText)
{
	prgCmds [0].cmdf = OLECMDF_ENABLED;
	return S_OK;
}

STDMETHODIMP CFDMUploadBtnForIe::Exec(const GUID *pCmdGroup, DWORD nCmdID, DWORD nCmdExecOpt, VARIANTARG *pvaIn, VARIANTARG *pvaOut)
{
	IUploaderPtr spUpldr;
	if (FAILED (spUpldr.CreateInstance (__uuidof (FUMUploader))))
		spUpldr.CreateInstance (__uuidof (FDMUploader));

	long lId;
	if (FAILED (spUpldr->CreateUpload (NULL, TRUE, &lId)))
		return S_FALSE; 

	return S_OK;
}

STDMETHODIMP CFDMUploadBtnForIe::SetSite(IUnknown *pUnkSite)
{
	if (pUnkSite == NULL)
	{
		m_spWb = NULL;
		return S_OK;
	}

	IServiceProviderPtr spServProv (pUnkSite);

	return spServProv->QueryService (SID_SWebBrowserApp, IID_IWebBrowser2,
			(void**)&m_spWb);
}

STDMETHODIMP CFDMUploadBtnForIe::GetSite(REFIID riid, void **ppvSite)
{
	return m_spWb->QueryInterface (riid, ppvSite);
}
