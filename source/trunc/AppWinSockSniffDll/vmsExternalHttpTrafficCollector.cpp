/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsExternalHttpTrafficCollector.h"

vmsExternalHttpTrafficCollector::vmsExternalHttpTrafficCollector(vmsHttpTrafficCollector *pHttpTraffic)
{
	assert (pHttpTraffic != NULL);
	m_pHttpTraffic = pHttpTraffic;
}

vmsExternalHttpTrafficCollector::~vmsExternalHttpTrafficCollector()
{

}

UINT vmsExternalHttpTrafficCollector::OnNewHttpDialog(LPCSTR pszUrl, LPCSTR pszRequestHdrs, LPCSTR pszRespHdrs)
{
	vmsHttpTrafficCollector::HttpDialogPtr spDlg;
	spDlg = m_pHttpTraffic->CreateHttpDialogStore ();
#ifdef _DEBUG
	spDlg->enProvider = vmsHttpTrafficCollector::HttpDialog::Provider::PROV_EXTERNAL;
#endif
	spDlg->dwFlags |= vmsHttpTrafficCollector::HttpDialog::BODY_DECOMPRESSED;

	spDlg->strRequestUrl = pszUrl;
	LOG ("New URL: %s", spDlg->strRequestUrl.c_str ());
	char szHost [1000] = "";
	URL_COMPONENTS urlc; ZeroMemory (&urlc, sizeof (urlc));
	urlc.dwStructSize = sizeof (urlc);
	urlc.lpszHostName = szHost;
	urlc.dwHostNameLength = sizeof (szHost);
	InternetCrackUrl (pszUrl, 0, 0, &urlc);
	spDlg->strRequestHost = szHost;

	spDlg->strRequestHeaders = pszRequestHdrs;
	m_pHttpTraffic->onHttpRequestHdrsAvailable (spDlg);
	spDlg->strResponseHeaders = pszRespHdrs;
	m_pHttpTraffic->onHttpResponseHdrsAvailable (spDlg);
	spDlg->enState = vmsHttpTrafficCollector::HttpDialog::RESPONSE_HEADERS_RCVD;
	m_pHttpTraffic->LockDialogsLists (true);
	m_pHttpTraffic->m_vDialogsInProgress.push_back (spDlg);
	m_pHttpTraffic->LockDialogsLists (false);

	if (!m_pHttpTraffic->isNeedBody (spDlg))
	{
		m_pHttpTraffic->MoveDialogToCompleted (spDlg);
	}
	else
	{
		spDlg->enState = vmsHttpTrafficCollector::HttpDialog::RECEIVING_RESPONSE_BODY;
	}

	return (UINT)spDlg->nID;
}

void vmsExternalHttpTrafficCollector::OnHttpDialogDataReceived(UINT nUID, LPBYTE pbData, UINT nSize)
{
	m_pHttpTraffic->LockDialogsLists (true);
	int nIndex = m_pHttpTraffic->FindDialogIndexById (nUID);
	if (nIndex == -1)
	{
		m_pHttpTraffic->LockDialogsLists (false);
		return;
	}
	vmsHttpTrafficCollector::HttpDialogPtr spDlg = m_pHttpTraffic->m_vDialogsInProgress [nIndex];
	m_pHttpTraffic->LockDialogsLists (false);

	if (pbData && nSize)
	{
		assert (m_pHttpTraffic->isNeedBody (spDlg));
		int l; l = spDlg->vbResponseBody.size ();
		if (l + nSize <= vmsHttpTrafficCollector::RequestBodyMaxSize)
		{
			spDlg->vbResponseBody.resize (l + nSize);
			CopyMemory (&spDlg->vbResponseBody [l], pbData, nSize);
			m_pHttpTraffic->onDataReceived (spDlg);
		}
		else
		{
			m_pHttpTraffic->DeleteDialogFromListByID (spDlg->nID);
		}
	}
}

void vmsExternalHttpTrafficCollector::OnHttpDialogClosed(UINT nUID)
{
	m_pHttpTraffic->LockDialogsLists (true);
	
	int nIndex = m_pHttpTraffic->FindDialogIndexById (nUID);
	if (nIndex != -1)
	{
		vmsHttpTrafficCollector::HttpDialogPtr spDlg = m_pHttpTraffic->m_vDialogsInProgress [nIndex];
		assert (spDlg != NULL);
		m_pHttpTraffic->CloseDialog (spDlg);
	}
	
	m_pHttpTraffic->LockDialogsLists (false);
}
