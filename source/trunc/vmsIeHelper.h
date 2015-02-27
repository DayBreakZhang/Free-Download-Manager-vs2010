/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSIEHELPER_H__1B3C3002_6D3B_4680_8803_5622396BBD0E__INCLUDED_)
#define AFX_VMSIEHELPER_H__1B3C3002_6D3B_4680_8803_5622396BBD0E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsIeHelper  
{
public:
	static bool RegisterExeAsSafeToDragDrop (LPCTSTR ptszAppGuid);
	static bool RegisterExeAsSafeToRun (LPCTSTR ptszAppGuid);
	vmsIeHelper();
	virtual ~vmsIeHelper();

};

#endif 
