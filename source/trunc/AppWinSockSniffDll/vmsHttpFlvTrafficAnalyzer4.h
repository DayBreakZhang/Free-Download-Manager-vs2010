/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSHTTPFLVTRAFFICANALYZER4_H__1D27DF83_1FAB_4844_A404_3BEDDB50AEDD__INCLUDED_)
#define AFX_VMSHTTPFLVTRAFFICANALYZER4_H__1D27DF83_1FAB_4844_A404_3BEDDB50AEDD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsHttpFlvTrafficAnalyzer.h"

class vmsHttpFlvTrafficAnalyzer4 : public vmsHttpFlvTrafficAnalyzer  
{
public:
	HRESULT FindFlvDownloads (LPCSTR pszHtmlPageUrl, const vmsHttpTrafficCollector *pTraffic);
	vmsHttpFlvTrafficAnalyzer4();
	virtual ~vmsHttpFlvTrafficAnalyzer4();

};

#endif 
