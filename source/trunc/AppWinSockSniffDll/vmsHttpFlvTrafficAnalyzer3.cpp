/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsHttpFlvTrafficAnalyzer3.h"
#include "vmsHttpHelper.h"
#include "vmsCharsets.h"
#include "vmsWinSockHttpTrafficAnalyzer.h"
#include "vmsUrlWords.h"

vmsHttpFlvTrafficAnalyzer3::vmsHttpFlvTrafficAnalyzer3()
{

}

vmsHttpFlvTrafficAnalyzer3::~vmsHttpFlvTrafficAnalyzer3()
{

}

HRESULT vmsHttpFlvTrafficAnalyzer3::FindFlvDownloads(LPCSTR pszHtmlPageUrl, LPCSTR pszSwfUrl, LPCSTR pszFlashVars, const vmsHttpTrafficCollector *pTraffic)
{
	LOGFN ("vmsHttpFlvTrafficAnalyzer3::FindFlvDownloads");

	LOG ("Html page url = %s", pszHtmlPageUrl);
	LOG ("Swf url = %s", pszSwfUrl ? pszSwfUrl : "");
	LOG ("FlashVars = %s", pszFlashVars ? pszFlashVars : "");

	m_vDownloads.clear ();
	
	string strFlashVars;

	if (pszFlashVars)
		strFlashVars = pszFlashVars;

	string strFlashVars2;
	ExtractFlashVarsFromSwfUrl (pszSwfUrl, pTraffic, NULL, strFlashVars2);
	if (!strFlashVars2.empty ())
	{
		if (!strFlashVars.empty () && strFlashVars [strFlashVars.length ()-1] != '&')
			strFlashVars += '&';
		strFlashVars += strFlashVars2;
		LOG ("Found more flashvars. Now = %s", strFlashVars.c_str ());
	}

	if (strFlashVars.empty ())
		return S_FALSE;

	const vmsHttpTrafficCollector::HttpDialog* pWebPage = 
		pTraffic->FindDialogByRequestUrl (pszHtmlPageUrl, vmsHttpTrafficCollector::HttpDialog::HTML);

	string strFV; vmsHttpHelper::DecodeUrl (strFlashVars.c_str (), strFV);

	
	
	LPCSTR pszFV = strFV.c_str ();
	while (pszFV)
	{
		pszFV = strstr (pszFV, "\\/");
		if (pszFV)
		{
			strFV.erase (strFV.begin () + (pszFV-strFV.c_str ()));
			pszFV = strFV.c_str ();
		}
	}
	

	LOG ("Decoded flashvars = %s", strFV.c_str ());
	
	int nStartIndex = pWebPage ? pTraffic->getHttpDialogIndex (pWebPage) + 1 : 0;

	HTTPDLGLIST vFlvs; 
	pTraffic->GetHttpDialogs (nStartIndex, -1, 
		vmsHttpTrafficCollector::HttpDialog::FLV, vFlvs);

	LOGHTTPDLGLIST ("List of known FLVs", vFlvs);

	HTTPDLGLIST vFlvs2;

	
	FindDialogsByUrlExactMatch (strFV.c_str (), vFlvs, vFlvs2);
	LOGHTTPDLGLIST ("List of FLVs which URLs are exactly specified in FlashVars", vFlvs2);
	if (vFlvs2.empty ())
	{
		FindDialogsByFileUrlMatch (strFV.c_str (), vFlvs, vFlvs2);
		LOGHTTPDLGLIST ("List of FLVs which FILE URLs are exactly specified in FlashVars", vFlvs2);
	}

	if (!vFlvs2.empty ())
	{
		LOGsnl ("Found FLV(s). Adding downloads.");
		
		wstring wstrTitle;
		ExtractTitleFromFlashVars (pWebPage, strFlashVars.c_str (), wstrTitle);
		if (wstrTitle.empty ())
			ExtractTitleFromHtml (pWebPage, wstrTitle);
		for (size_t i = 0; i < vFlvs2.size (); i++)
			AddFlvDownload (pWebPage, vFlvs2 [i], wstrTitle.c_str ());
		return S_OK;
	}

	

	
	
	FindFlvDownloadInInBetweenDlgs (pTraffic, pWebPage, pszSwfUrl, strFlashVars.c_str (),
		strFV.c_str (), vFlvs, FDT_EXACTURLMATCH);
	if (!m_vDownloads.empty ())
		return S_OK;

	
	
	FindFlvDownloadInInBetweenDlgs (pTraffic, pWebPage, pszSwfUrl, strFlashVars.c_str (),
		strFV.c_str (), vFlvs, FDT_FILEURLMATCH);
	if (!m_vDownloads.empty ())
		return S_OK;	

	
	

	FindDialogsByUniqueUrlWordsMatch (strFV.c_str (), vFlvs, vFlvs2);
	if (vFlvs2.empty ())
		FindDialogsByUniqueUrlWordsMatch2 (pszSwfUrl, vFlvs, vFlvs2);
	if (!vFlvs2.empty ())
	{
		wstring wstrTitle;
		ExtractTitleFromFlashVars (pWebPage, strFlashVars.c_str (), wstrTitle);
		if (wstrTitle.empty ())
			ExtractTitleFromHtml (pWebPage, wstrTitle);
		for (size_t i = 0; i < vFlvs2.size (); i++)
			AddFlvDownload (pWebPage, vFlvs2 [i], wstrTitle.c_str ());
		return S_OK;
	}

	
	FindFlvDownloadInInBetweenDlgs (pTraffic, pWebPage, pszSwfUrl, strFlashVars.c_str (),
		strFV.c_str (), vFlvs, FDT_BYUNIQUEWORDS);
	if (!m_vDownloads.empty ())
		return S_OK;	

	return m_vDownloads.empty () ? S_FALSE : S_OK;
}

