/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsHttpFlvTrafficAnalyzer4.h"

vmsHttpFlvTrafficAnalyzer4::vmsHttpFlvTrafficAnalyzer4()
{

}

vmsHttpFlvTrafficAnalyzer4::~vmsHttpFlvTrafficAnalyzer4()
{

}

HRESULT vmsHttpFlvTrafficAnalyzer4::FindFlvDownloads(LPCSTR pszHtmlPageUrl, const vmsHttpTrafficCollector *pTraffic)
{
	LOGFN ("vmsHttpFlvTrafficAnalyzer4::FindFlvDownloads");

	m_vDownloads.clear ();

	const vmsHttpTrafficCollector::HttpDialog* pWebPage = 
		pTraffic->FindDialogByRequestUrl (pszHtmlPageUrl, vmsHttpTrafficCollector::HttpDialog::HTML);

	if (!pWebPage)
		return E_INVALIDARG;

	if (pWebPage->vbResponseBody.empty ())
		return S_FALSE;

	string strPageText;
	strPageText.assign ((LPSTR)&pWebPage->vbResponseBody [0], pWebPage->vbResponseBody.size ());

	int nStartIndex = pTraffic->getHttpDialogIndex (pWebPage) + 1;

	HTTPDLGLIST vFlvs; 
	pTraffic->GetHttpDialogs (nStartIndex, -1, 
		vmsHttpTrafficCollector::HttpDialog::FLV, vFlvs);

	HTTPDLGLIST vFlvs2;
	
	
	FindDialogsByUrlExactMatch (strPageText.c_str (), vFlvs, vFlvs2);
	if (vFlvs2.empty ())
		FindDialogsByFileUrlMatch (strPageText.c_str (), vFlvs, vFlvs2);

	if (!vFlvs2.empty ())
	{
		
		wstring wstrTitle;
		ExtractTitleFromHtml (pWebPage, wstrTitle);
		for (size_t i = 0; i < vFlvs2.size (); i++)
			AddFlvDownload (pWebPage, vFlvs2 [i], wstrTitle.c_str ());
		return S_OK;
	}

	

	string strBody;
	strBody.assign ((LPSTR)&pWebPage->vbResponseBody [0], pWebPage->vbResponseBody.size ());
	
	
	
	FindFlvDownloadInInBetweenDlgs (pTraffic, pWebPage, NULL, NULL, strBody.c_str (), vFlvs, FDT_EXACTURLMATCH);
	if (!m_vDownloads.empty ())
		return S_OK;
	
	
	
	FindFlvDownloadInInBetweenDlgs (pTraffic, pWebPage, NULL, NULL, strBody.c_str (), vFlvs, FDT_FILEURLMATCH);
	if (!m_vDownloads.empty ())
		return S_OK;	
	
	
	
	
	FindDialogsByUniqueUrlWordsMatch (strBody.c_str (), vFlvs, vFlvs2);
	if (vFlvs2.empty ())
		FindDialogsByUniqueUrlWordsMatch2 (pWebPage->strRequestUrl.c_str (), vFlvs, vFlvs2);
	if (!vFlvs2.empty ())
	{
		wstring wstrTitle;
		ExtractTitleFromHtml (pWebPage, wstrTitle);
		for (size_t i = 0; i < vFlvs2.size (); i++)
			AddFlvDownload (pWebPage, vFlvs2 [i], wstrTitle.c_str ());
		return S_OK;
	}
	
	
	FindFlvDownloadInInBetweenDlgs (pTraffic, pWebPage, NULL, NULL, strBody.c_str (), vFlvs, FDT_BYUNIQUEWORDS);
	if (!m_vDownloads.empty ())
		return S_OK;

	return m_vDownloads.empty () ? S_FALSE : S_OK;
}
