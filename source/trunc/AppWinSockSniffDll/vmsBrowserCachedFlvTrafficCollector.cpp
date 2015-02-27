/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsBrowserCachedFlvTrafficCollector.h"
#include "vmsIeFlvHistory.h"

vmsBrowserCachedFlvTrafficCollector::vmsBrowserCachedFlvTrafficCollector()
{

}

vmsBrowserCachedFlvTrafficCollector::~vmsBrowserCachedFlvTrafficCollector()
{

}

vmsBrowserCachedFlvTrafficCollector& vmsBrowserCachedFlvTrafficCollector::o()
{
	static vmsBrowserCachedFlvTrafficCollector o;
	return o;
}

void vmsBrowserCachedFlvTrafficCollector::Initialize()
{
	if (!m_vCompletedDialogs.empty ())
		return;

	vmsBrowserFlvHistory *phist;
	vmsIeFlvHistory iehist;

	if (GetModuleHandle ("iexplore.exe"))
		phist = &iehist;
	else
		return;

	phist->Gather ();

	for (int i = 0; i < phist->getItemCount (); i++)
	{
		const vmsBrowserFlvHistory::Item *item = phist->getItem (i);

		HttpDialogPtr spDlg;
		spDlg.CreateInstance ();
		spDlg->nID = InterlockedIncrement (&m_nNextDlgID);
		
		spDlg->enState = HttpDialog::DONE;

		spDlg->strRequestUrl = item->strUrl;

		LPCSTR psz1 = strstr (item->strUrl.c_str (), "://");
		if (psz1)
		{
			psz1 += 3;
			LPCSTR psz2 = strchr (psz1, '/');
			if (psz2)
				spDlg->strRequestHost.assign (psz1, psz2-psz1);
		}

		spDlg->pHttpResponse = new vmsHttpResponseParser;
		spDlg->pHttpResponse->ParseHeader (item->strHttpResponse.c_str ());

		spDlg->strResponseHeaders = item->strHttpResponse;

		spDlg->enCT = HttpDialog::FLV;

		const vmsHttpParser::HdrField *pCL = spDlg->pHttpResponse->FieldByName ("Content-Length");
		if (pCL != NULL)
			spDlg->nContentLength = (UINT64)_atoi64 (pCL->strValue.c_str ());

		EnterCriticalSection (&m_csModifyDialogsVector);
		m_vCompletedDialogs.push_back (spDlg);
		LeaveCriticalSection (&m_csModifyDialogsVector);
	}
}

void vmsBrowserCachedFlvTrafficCollector::AddSourceDialog(const HttpDialog* pDlg)
{
	if (m_vCompletedDialogs.empty ())
		Initialize ();

	HttpDialogPtr spDlg;
	spDlg.CreateInstance ();

	spDlg->nID = !m_vCompletedDialogs.empty () ? m_vCompletedDialogs [0]->nID-1 : 
		InterlockedIncrement (&m_nNextDlgID);

	spDlg->enState = HttpDialog::DONE;

	spDlg->strRequestUrl = pDlg->strRequestUrl;

	spDlg->strRequestHost = pDlg->strRequestHost;

	if (pDlg->pHttpRequest)
	{
		spDlg->pHttpRequest = new vmsHttpRequestParser;
		*spDlg->pHttpRequest = *pDlg->pHttpRequest;
	}

	spDlg->strRequestHeaders = pDlg->strRequestHeaders;
		
	if (pDlg->pHttpResponse)
	{
		spDlg->pHttpResponse = new vmsHttpResponseParser;
		*spDlg->pHttpResponse = *pDlg->pHttpResponse;
	}

	spDlg->strResponseHeaders = pDlg->strResponseHeaders;

	spDlg->vbResponseBody = pDlg->vbResponseBody;

	spDlg->enCT = pDlg->enCT;

	spDlg->nContentLength = pDlg->nContentLength;
			
	EnterCriticalSection (&m_csModifyDialogsVector);
	m_vCompletedDialogs.insert (m_vCompletedDialogs.begin (), spDlg);
	LeaveCriticalSection (&m_csModifyDialogsVector);
}

bool vmsBrowserCachedFlvTrafficCollector::DoesCurrentProcessHaveCache()
{
	return false;
	
}
