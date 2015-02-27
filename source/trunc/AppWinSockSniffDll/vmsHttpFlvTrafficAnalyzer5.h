/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSHTTPFLVTRAFFICANALYZER5_H__A5F4C7D2_03D6_4515_BBEC_8D0C4114AAF5__INCLUDED_)
#define AFX_VMSHTTPFLVTRAFFICANALYZER5_H__A5F4C7D2_03D6_4515_BBEC_8D0C4114AAF5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsHttpFlvTrafficAnalyzer.h"

class vmsHttpFlvTrafficAnalyzer5 : public vmsHttpFlvTrafficAnalyzer  
{
public:
	static void GetFlvTitle (HTTPDLG pWebPage, LPCSTR pszFlashVars, HTTPDLGTREEITEMLIST& vFlvTree, wstring &wstrTitle);
	HRESULT FindFlvDownloads (LPCSTR pszHtmlPageUrl, LPCSTR pszFrameUrl, LPCSTR pszSwfUrl, LPCSTR pszFlashVars, vector <string> &vOtherSwfUrls, vector <string> &vOtherFlashVars, vmsWinSockHttpDlgTree *pDlgTree);
	vmsHttpFlvTrafficAnalyzer5();
	virtual ~vmsHttpFlvTrafficAnalyzer5();

protected:
#ifdef LOG_WEBFILES_TREE
	void LogMainCall (int iCall, LPCSTR pszHtmlPageUrl, LPCSTR pszFrameUrl, LPCSTR pszSwfUrl, LPCSTR pszFlashVars, vector <string> &vOtherSwfUrls, vector <string> &vOtherFlashVars, const vmsWinSockHttpDlgTree *pDlgTree, HTTPDLGTREEITEM pWebPage, HTTPDLGTREEITEM pFrame);
#endif
};

#endif 
