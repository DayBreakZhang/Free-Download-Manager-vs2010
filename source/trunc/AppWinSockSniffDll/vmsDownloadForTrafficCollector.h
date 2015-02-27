/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSDOWNLOADFORTRAFFICCOLLECTOR_H__F898CE13_628B_4D0D_912A_D7B6A5D4112B__INCLUDED_)
#define AFX_VMSDOWNLOADFORTRAFFICCOLLECTOR_H__F898CE13_628B_4D0D_912A_D7B6A5D4112B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsWinSockHttpTrafficCollector.h"
#include "vmsWinSockHttpDlgTree.h"

extern vmsHttpTrafficCollector _HttpTraffic;

class vmsDownloadForTrafficCollector  
{
public:
	static BOOL MakeDownload (LPCSTR pszUrl, vmsHttpTrafficCollector::HttpDialog::ResourceContentType enCT = vmsHttpTrafficCollector::HttpDialog::HTML, vmsHttpTrafficCollector *pTraffic = &_HttpTraffic, vmsWinSockHttpDlgTree *pDlgTree = &vmsWinSockHttpDlgTree::o ());
	vmsDownloadForTrafficCollector();
	virtual ~vmsDownloadForTrafficCollector();

protected:
	static BOOL MakeWasteDownload (LPCSTR pszUrl);
};

#endif 
