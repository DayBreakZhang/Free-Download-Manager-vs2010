/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSDOWNLOADSLISTHELPER_H__21909151_951B_4C22_A893_A0F4507128DD__INCLUDED_)
#define AFX_VMSDOWNLOADSLISTHELPER_H__21909151_951B_4C22_A893_A0F4507128DD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsDownloadsListHelper  
{
public:
	static void GetStat (DLDS_LIST_REF v, BOOL *pbHasRunning, BOOL *pbHasStopped, BOOL *pbHasCompleted, BOOL *pbHasAutostart, BOOL *pbHasNotAutostart);
	vmsDownloadsListHelper();
	virtual ~vmsDownloadsListHelper();

};

#endif 
