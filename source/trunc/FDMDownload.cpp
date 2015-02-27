/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "FDMDownload.h"

STDMETHODIMP CFDMDownload::get_Url(BSTR *pVal)
{
	USES_CONVERSION;
	*pVal = SysAllocString (A2W (m_strUrl));
	return S_OK;
}

STDMETHODIMP CFDMDownload::put_Url(BSTR newVal)
{
	USES_CONVERSION;
	m_strUrl = W2A (newVal);
	return S_OK;
}

void CFDMDownload::ReadFromDownload(vmsDownloadSmartPtr dld)
{
	m_strUrl = dld->pMgr->get_URL ();
	
	for (int i = 0; i < 6; i++)
		m_astrDldTexts [i] = CDownloads_Tasks::GetDownloadText (dld, i);
}

STDMETHODIMP CFDMDownload::get_DownloadText(long nTextIndex, BSTR *pVal)
{
	if (nTextIndex < 0 || nTextIndex > 5)
		return E_INVALIDARG;

	USES_CONVERSION;
	*pVal = SysAllocString (A2W (m_astrDldTexts [nTextIndex]));

	return S_OK;
}
