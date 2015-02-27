/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSAUTORUNMGR_H__6D0999BD_CA3F_481B_8D67_C4798D2E0967__INCLUDED_)
#define AFX_FSAUTORUNMGR_H__6D0999BD_CA3F_481B_8D67_C4798D2E0967__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class fsAutorunMgr  
{
public:
	
	BOOL IsAutoStart();
	
	BOOL SetAutoStart (BOOL bSet = TRUE);

	fsAutorunMgr();
	virtual ~fsAutorunMgr();

protected:
	
	void CloseAutoStartKey();
	BOOL OpenAutoStartKey ();
	HKEY m_hAutoStart;	
};

#endif 
