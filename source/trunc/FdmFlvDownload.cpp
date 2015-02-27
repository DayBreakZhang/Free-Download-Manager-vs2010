/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FDM.h"
#include "FdmFlvDownload.h"

STDMETHODIMP CFdmFlvDownload::get_Url(IWGUrlReceiver **pVal)
{
	*pVal = m_spUrl;
	m_spUrl->AddRef ();
	return S_OK;
}

STDMETHODIMP CFdmFlvDownload::put_Url(IWGUrlReceiver *newVal)
{
	m_spUrl = newVal;
	return S_OK;
}
