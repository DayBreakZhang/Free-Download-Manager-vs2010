/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSWINSOCKHTTPTRAFFICANALYZER_H__59BFFED5_D21F_4D62_AF84_6655475CDBBF__INCLUDED_)
#define AFX_VMSWINSOCKHTTPTRAFFICANALYZER_H__59BFFED5_D21F_4D62_AF84_6655475CDBBF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsHttpTrafficCollector.h"

class vmsWinSockHttpTrafficAnalyzer  
{
public:
	
	struct DialogContainingWord
	{
		string strWord;
		vector <const vmsHttpTrafficCollector::HttpDialog*> vDlgs;
	};
	typedef vector <DialogContainingWord*> DialogPossibleSources;
public:
	static void FindUniqueUrlWords(const vector <const vmsHttpTrafficCollector::HttpDialog*> &vDlgs, vector < vector <string> > &vvUniqueWords);
	static void Free (DialogPossibleSources &v);
	
	
	
	
	
	
	
	static void FindOutgoingDialogs (const vmsHttpTrafficCollector *pTraffic, int nSrcDlgIndex, DWORD dwOutgoingContentTypes, bool bDontFindUnique, vector <const vmsHttpTrafficCollector::HttpDialog*> &vOutgoingDlgs);
	
	static void FindOutgoingDialogsByReferer (const vmsHttpTrafficCollector *pTraffic, int nSrcDlgIndex, DWORD dwOutgoingContentTypes, vector <const vmsHttpTrafficCollector::HttpDialog*> &vOutgoingDlgs);
	
	
	
	static int FindRedirectsRoot (const vmsHttpTrafficCollector *pTraffic, int nHttpDlgIndex);
	
	
	
	
	
	
	
	
	
	
	
	
	
	static void FindPossibleSourceDialogs (const vmsHttpTrafficCollector::HttpDialog* pDlg, const vmsHttpTrafficCollector *pTraffic, int nStartIndex, int nEndIndex, DWORD dwContentType, const vmsHttpTrafficCollector::HttpDialog* pSuspectSrcDlg, DialogPossibleSources &vResult);
	
	
	
	
	
	
	static float CalculatePossibleSourceDialogWeight (const vmsHttpTrafficCollector::HttpDialog* pDlg, bool bDontFindUnique, const DialogPossibleSources& vDPS);
	vmsWinSockHttpTrafficAnalyzer();
	virtual ~vmsWinSockHttpTrafficAnalyzer();

};

#endif 
