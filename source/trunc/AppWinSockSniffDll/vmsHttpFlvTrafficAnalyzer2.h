/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSHTTPFLVTRAFFICANALYZER2_H__1243130A_66D6_4243_8FAA_A56845503142__INCLUDED_)
#define AFX_VMSHTTPFLVTRAFFICANALYZER2_H__1243130A_66D6_4243_8FAA_A56845503142__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsHttpTrafficCollector.h"
#include "vmsHttpFlvTrafficAnalyzer.h"

#define FTAFND_DONT_DOWNLOAD		1

#define FTAFND_DONT_FIND_UNIQUE		(1<<1)

class vmsHttpFlvTrafficAnalyzer2 : public vmsHttpFlvTrafficAnalyzer
{
public:
	
	HRESULT FindFlvDownloadsInHtmlPage (LPCSTR pszHtmlPageUrl, const vmsHttpTrafficCollector *pTraffic, DWORD dwFlags = 0);
	vmsHttpFlvTrafficAnalyzer2();
	virtual ~vmsHttpFlvTrafficAnalyzer2();

protected:
	
	HRESULT FindFlvDownloadsInHtmlPage_imp (LPCSTR pszHtmlPageUrl, const vmsHttpTrafficCollector *pTraffic, DWORD dwFlags, int nCallDepth);
};

#endif 
