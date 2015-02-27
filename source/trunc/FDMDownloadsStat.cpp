/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "FDMDownloadsStat.h"

STDMETHODIMP CFDMDownloadsStat::get_DownloadCount(long *pVal)
{
	*pVal = m_vDownloads.size ();

	return S_OK;
}

void CFDMDownloadsStat::AddDownloadToList(vmsDownloadSmartPtr dld)
{
	CComObject <CFDMDownload>* pDld;
	HRESULT hr = CComObject <CFDMDownload>::CreateInstance (&pDld);
	if (FAILED (hr))
		return;

	

	pDld->ReadFromDownload (dld);

	m_vDownloads.add (pDld);
}

STDMETHODIMP CFDMDownloadsStat::get_Download(long nIndex, IFDMDownload **pVal)
{
	ASSERT (nIndex < m_vDownloads.size ());
	if (nIndex >= m_vDownloads.size ())
		return E_INVALIDARG;

	*pVal = m_vDownloads [nIndex];
	(*pVal)->AddRef ();

	return S_OK;
}

STDMETHODIMP CFDMDownloadsStat::BuildListOfDownloads(BOOL bIncludeCompleted, BOOL bIncludeRunning)
{
	m_vDownloads.clear ();

	_DldsMgr.LockList (true);

	size_t nCount = _DldsMgr.GetCount ();

	for (size_t i = 0; i < nCount; i++)
	{
		vmsDownloadSmartPtr dld = _DldsMgr.GetDownload (i);
		bool bAdd = bIncludeRunning && dld->pMgr->IsRunning ();
		if (bAdd == false)
			bAdd = bIncludeCompleted && dld->pMgr->IsDone ();
		if (bAdd)
			AddDownloadToList (dld);
	}

	_DldsMgr.UnlockList (true);
	
	return S_OK;
}
