/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSTRANSFERFLVDOWNLOADSTOFDM_H__85413C4B_14C0_4275_8482_E6E35DD4D21E__INCLUDED_)
#define AFX_VMSTRANSFERFLVDOWNLOADSTOFDM_H__85413C4B_14C0_4275_8482_E6E35DD4D21E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsHttpFlvTrafficAnalyzer.h"

class vmsTransferFlvDownloadsToFdm  
{
public:
	static HRESULT Do (LPCSTR pszSrcWebPageUrl, const vector <vmsHttpFlvTrafficAnalyzer::FlvDownload> &v);
	vmsTransferFlvDownloadsToFdm();
	virtual ~vmsTransferFlvDownloadsToFdm();

protected:
	static string ExtensionFromContentType (LPCSTR pszCT);
	static void SetupWgUrlRcvr (struct IWGUrlReceiver *pRcvr, const vmsHttpFlvTrafficAnalyzer::FlvDownload &flv);
};

#endif 
