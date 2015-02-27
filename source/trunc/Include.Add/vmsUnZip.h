/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSUNZIP_H__63E87C1E_BBA1_4F5B_A059_D0C8CC711DB6__INCLUDED_)
#define AFX_VMSUNZIP_H__63E87C1E_BBA1_4F5B_A059_D0C8CC711DB6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsUnZip  
{
public:
	static BOOL Unpack (LPCTSTR ptszFileName, LPCTSTR ptszDstFolder);
	vmsUnZip();
	virtual ~vmsUnZip();

};

#endif 
