/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSHTTPFLVTRAFFICANALYZER3_H__BF3DCF56_99FF_4D36_A370_74C7E5E9287A__INCLUDED_)
#define AFX_VMSHTTPFLVTRAFFICANALYZER3_H__BF3DCF56_99FF_4D36_A370_74C7E5E9287A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsHttpTrafficCollector.h"
#include "vmsHttpFlvTrafficAnalyzer.h"

class vmsHttpFlvTrafficAnalyzer3 : public vmsHttpFlvTrafficAnalyzer
{
public:
	HRESULT FindFlvDownloads (LPCSTR pszHtmlPageUrl, LPCSTR pszSwfUrl, LPCSTR pszFlashVars, const vmsHttpTrafficCollector *pTraffic);
	vmsHttpFlvTrafficAnalyzer3();
	virtual ~vmsHttpFlvTrafficAnalyzer3();
};

#endif 
