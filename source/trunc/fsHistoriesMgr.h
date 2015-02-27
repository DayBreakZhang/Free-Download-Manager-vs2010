/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSHISTORIESMGR_H__BE0B3802_68B1_4D05_B995_B68D4D12717D__INCLUDED_)
#define AFX_FSHISTORIESMGR_H__BE0B3802_68B1_4D05_B995_B68D4D12717D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class fsHistoriesMgr  
{
public:
	
	void ClearAll();
	
	void ReadSettings();

	fsHistoriesMgr();
	virtual ~fsHistoriesMgr();

};

#endif 
