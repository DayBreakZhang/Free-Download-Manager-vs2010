/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsWinSockHttpTrafficAnalyzer.h"
#include "vmsHttpFlvTrafficAnalyzer2.h"
#include "vmsHtmlParser.h"
#include "vmsHtmlTagParser.h"
#include "vmsDownloadForTrafficCollector.h"

vmsHttpFlvTrafficAnalyzer2::vmsHttpFlvTrafficAnalyzer2()
{

}

vmsHttpFlvTrafficAnalyzer2::~vmsHttpFlvTrafficAnalyzer2()
{

}

HRESULT vmsHttpFlvTrafficAnalyzer2::FindFlvDownloadsInHtmlPage(LPCSTR pszHtmlPageUrl, const vmsHttpTrafficCollector *pTraffic, DWORD dwFlags)
{
	LOGFN ("vmsHttpFlvTrafficAnalyzer2::FindFlvDownloadsInHtmlPage");
	m_vDownloads.clear ();
	return FindFlvDownloadsInHtmlPage_imp (pszHtmlPageUrl, pTraffic, dwFlags, 0);
}

HRESULT vmsHttpFlvTrafficAnalyzer2::FindFlvDownloadsInHtmlPage_imp(LPCSTR pszHtmlPageUrl, const vmsHttpTrafficCollector *pTraffic, DWORD dwFlags, int nCallDepth)
{
	const vmsHttpTrafficCollector::HttpDialog *pDlg = pTraffic->FindDialogByRequestUrl (pszHtmlPageUrl, 
		vmsHttpTrafficCollector::HttpDialog::HTML);
	if (!pDlg && (dwFlags & FTAFND_DONT_DOWNLOAD) == 0)
	{
		if (vmsDownloadForTrafficCollector::MakeDownload (pszHtmlPageUrl))
		{
			pDlg = pTraffic->FindDialogByRequestUrl (pszHtmlPageUrl, 
				vmsHttpTrafficCollector::HttpDialog::HTML);
		}
	}
	if (!pDlg)
		return E_INVALIDARG; 
	
	vector <const vmsHttpTrafficCollector::HttpDialog*> vFlvs;
	vmsWinSockHttpTrafficAnalyzer::FindOutgoingDialogs (pTraffic, 
		pTraffic->getHttpDialogIndex (pDlg), 
		vmsHttpTrafficCollector::HttpDialog::FLV, (dwFlags & FTAFND_DONT_FIND_UNIQUE) != 0, vFlvs);
	
	wstring wstrTitle;
	ExtractTitleFromHtml (pDlg, wstrTitle);
	
	for (int i = 0; i < vFlvs.size (); i++)
		AddFlvDownload (pDlg, vFlvs [i], wstrTitle.c_str ());
	
	if (vFlvs.empty ())
	{
		vector <const vmsHttpTrafficCollector::HttpDialog*> vDlgs;
		vmsWinSockHttpTrafficAnalyzer::FindOutgoingDialogs (pTraffic, 
			pTraffic->getHttpDialogIndex (pDlg), 
			vmsHttpTrafficCollector::HttpDialog::X_WWW_FORM_URL_ENCODED | vmsHttpTrafficCollector::HttpDialog::XML, 
			(dwFlags & FTAFND_DONT_FIND_UNIQUE) != 0, vDlgs);
		for (int i = 0; i < vDlgs.size (); i++)
		{
			const vmsHttpTrafficCollector::HttpDialog* pDlg2 = vDlgs [i];
			vFlvs.clear ();
			vmsWinSockHttpTrafficAnalyzer::FindOutgoingDialogs (pTraffic, 
				pTraffic->getHttpDialogIndex (pDlg2), 
				vmsHttpTrafficCollector::HttpDialog::FLV, 
				(dwFlags & FTAFND_DONT_FIND_UNIQUE) != 0, vFlvs);
			if (!vFlvs.empty ())
			{
				for (int j = 0; j < vFlvs.size (); j++)
				{
					wstring wstrTitle2;
					if (pDlg2->enCT == vmsHttpTrafficCollector::HttpDialog::X_WWW_FORM_URL_ENCODED)
						ExtractTitleFromXWwwFormUrlEncoded (pDlg2, wstrTitle2);
					else 
						ExtractTitleFromXml (pDlg2, wstrTitle2, vFlvs [j]);
					if (wstrTitle2.empty ())
						wstrTitle2 = wstrTitle;
					AddFlvDownload (pDlg, vFlvs [j], wstrTitle2.c_str ());
				}
			}
		}
	}

	

	
	
	
	
	if (nCallDepth == 0)
	if (vFlvs.empty ()) 
	{
		
		LPCSTR pszHtml = (LPCSTR)pDlg->getBodyText ();
		vector <string> v1, v2;
		vmsHtmlParser::findAllTagsHeads (pszHtml, "iframe", v1);
		vmsHtmlParser::findAllTagsHeads (pszHtml, "frame", v2);
		
		for (int iVector = 0; iVector < 2; iVector++)
		{
			vector <string> &v = iVector ? v2 : v1;
			
			for (size_t i = 0; i < v.size (); i++)
			{
				vmsHtmlTagParser tag (v [i].c_str ());
				const vmsHtmlTagParser::TagAttribute *src = tag.findAttribute ("src");
				if (!src || src->strValue.empty ())
					continue;
				string strHtmlUrl;
				vmsHtmlParser::DecodeHtmlSpecEntites (src->strValue.c_str (), strHtmlUrl);
				if (strHtmlUrl.empty ())
					continue;
				FindFlvDownloadsInHtmlPage_imp (strHtmlUrl.c_str (), pTraffic, dwFlags, nCallDepth+1);
			}
		}
	}

	
	
	

	return m_vDownloads.empty () ? S_FALSE : S_OK;
}

