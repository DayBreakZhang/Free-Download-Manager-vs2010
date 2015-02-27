/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSHTTPFLVTRAFFICANALYZER_H__208C8F65_B847_4DFF_9921_F56BF5510E99__INCLUDED_)
#define AFX_VMSHTTPFLVTRAFFICANALYZER_H__208C8F65_B847_4DFF_9921_F56BF5510E99__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsHttpTrafficCollector.h"

class vmsHttpFlvTrafficAnalyzer  
{
public:
	struct FlvDownload
	{
		string strUrl;
		wstring wstrTitle;
		string strContentType;
		string strContentLength;
		string strReferer;
		string strCookies;
		vector <BYTE> vbPostData;
	};
public:
	void AddFlvDownloads (const vmsHttpFlvTrafficAnalyzer &taFrom);
	static void ExtractFlashVarsFromSwfUrl (LPCSTR pszUrl, const vmsHttpTrafficCollector *pTraffic, const vmsWinSockHttpDlgTree *pTree, string &strResult);
	const vector <FlvDownload>& getFlvDownloads () const;
	const FlvDownload* getFlvDownload (int nIndex) const;
	int get_FlvDownloadCount () const;
	vmsHttpFlvTrafficAnalyzer();
	virtual ~vmsHttpFlvTrafficAnalyzer();

protected:
	enum FindFlvDownloadInInBetweenDlgs_Type {
		FDT_EXACTURLMATCH,
		FDT_FILEURLMATCH,
		FDT_BYUNIQUEWORDS,
	};
	void FindFlvDownloadInInBetweenDlgs (const vmsHttpTrafficCollector *pTraffic, HTTPDLG pWebPage, HTTPDLGLIST vFlvs, FindFlvDownloadInInBetweenDlgs_Type enFindType);
	void FindFlvDownloadInInBetweenDlgs (const vmsHttpTrafficCollector *pTraffic, HTTPDLG pWebPage, LPCSTR pszSwfUrl, LPCSTR pszFlashVars, LPCSTR pszSwfContext, HTTPDLGLIST vFlvs, FindFlvDownloadInInBetweenDlgs_Type enFindType);
	void FindDialogsByUrlExactMatch(LPCSTR pszSrcText, const HTTPDLGLIST &vDlgs, HTTPDLGLIST &vResult);
	void FindDialogsByFileUrlMatch(LPCSTR pszSrcText, const HTTPDLGLIST &vDlgs, HTTPDLGLIST &vResult);
	
	static void ExtractTitleFromFlashVars (HTTPDLG pWebPage, LPCSTR pszFlashVars, wstring &wstrTitle);
	
	static void FindDialogsByUniqueUrlWordsMatch(LPCSTR pszSwfContext, const HTTPDLGLIST &vDlgs, HTTPDLGLIST &vResult);
	static void FindDialogsByUniqueUrlWordsMatch2(LPCSTR pszSomeUrl, const HTTPDLGLIST &vDlgs, HTTPDLGLIST &vResult);
	static void DecodeWebPageString (const vmsHttpTrafficCollector::HttpDialog* pWebPage, LPCSTR pszString, wstring &wstrResult);
	static void ExtractTitleFromXml (const vmsHttpTrafficCollector::HttpDialog *pDlg, wstring &wstrTitle, const vmsHttpTrafficCollector::HttpDialog* pFlvDlg);
	static void ExtractTitleFromXWwwFormUrlEncoded (const vmsHttpTrafficCollector::HttpDialog *pDlg, wstring &wstrTitle);
	static void ExtractTitleFromHtml (const vmsHttpTrafficCollector::HttpDialog *pHtmlDlg, wstring &wstrTitle);
	void AddFlvDownload (const vmsHttpTrafficCollector::HttpDialog *pSrcHtmlDlg, const vmsHttpTrafficCollector::HttpDialog *pDlg, LPCWSTR pwszTitle);
	vector <FlvDownload> m_vDownloads;

};

#endif 
