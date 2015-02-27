/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSFINDFLVDOWNLOADSRESULTSCACHE_H__5A290C31_47AD_4078_A8B8_2248BC91C4F7__INCLUDED_)
#define AFX_VMSFINDFLVDOWNLOADSRESULTSCACHE_H__5A290C31_47AD_4078_A8B8_2248BC91C4F7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsObject.h"
#include "vmsHttpFlvTrafficAnalyzer.h"

class vmsFindFlvDownloadsResultsCache  
{
public:
	struct Result;
	typedef vmsObjectSmartPtr <Result> ResultPtr;
	struct Result : public vmsObject
	{
		string strWebPageUrl;
		string strFrameUrl;
		string strSwfUrl;
		string strFlashVars;
		vmsHttpFlvTrafficAnalyzer *pTa;

		Result () 
		{
			pTa = NULL;
		}

		~Result () 
		{
			if (pTa)
				delete pTa;
		}
	};
public:
	HRESULT FindFlvDownloads (LPCSTR pszUrl, LPCSTR pszFrameUrl, LPCSTR pszSwfUrl, LPCSTR pszFlashVars, LPCSTR pszOtherSwfUrls, LPCSTR pszOtherFlashVars, ResultPtr &result);
	vmsFindFlvDownloadsResultsCache(vmsHttpTrafficCollector *pHttpTraffic, vmsWinSockHttpDlgTree *pDlgTree);
	virtual ~vmsFindFlvDownloadsResultsCache();

protected:
	vmsCriticalSection m_csResults;
	int m_cFlvsInSession;
	void ExtractUrls (LPCSTR pszUrls, vector <string> &vResult);
	vmsHttpTrafficCollector* m_pHttpTraffic;
	vmsWinSockHttpDlgTree *m_pDlgTree;
	vector <ResultPtr> m_vResults;
public:
	void CheckNeedCacheReset(void);
	ResultPtr FindResult(LPCSTR pszUrl, LPCSTR pszFrameUrl, LPCSTR pszSwfUrl, LPCSTR pszFlashVars);
};

#endif 
