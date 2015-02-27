/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FLOATINGWNDSTHREAD_H__5AFA0C0A_F6EB_4F13_A252_7A2B10C0A64F__INCLUDED_)
#define AFX_FLOATINGWNDSTHREAD_H__5AFA0C0A_F6EB_4F13_A252_7A2B10C0A64F__INCLUDED_

#include "FloatingWnd.h"	
#include "FloatingInfoWnd.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

class CFloatingWndsThread : public CWinThread
{
	DECLARE_DYNCREATE(CFloatingWndsThread)
protected:
	CFloatingWndsThread();           

public:

public:
	CFloatingInfoWnd m_wndFloatingInfo;
	CFloatingWnd m_wndFloating;

	
	//{{AFX_VIRTUAL(CFloatingWndsThread)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

protected:
	virtual ~CFloatingWndsThread();

	
	//{{AFX_MSG(CFloatingWndsThread)
		
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
