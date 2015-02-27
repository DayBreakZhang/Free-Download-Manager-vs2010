/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_UITHREAD_H__65820914_E17B_4A41_B078_32E557D55422__INCLUDED_)
#define AFX_UITHREAD_H__65820914_E17B_4A41_B078_32E557D55422__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#define ID_UITHR_DOWORK				30000

class UIThread : public CWinThread
{
	DECLARE_DYNCREATE(UIThread)
protected:
	UIThread();           

public:

public:
	
	void StartDoWork();
	
	void set_Thread (LPTHREAD_START_ROUTINE pfn, LPVOID lpParam);

	
	//{{AFX_VIRTUAL(UIThread)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

protected:
	LPVOID m_lpParam;
	LPTHREAD_START_ROUTINE m_pfnThread;
	virtual ~UIThread();

	
	//{{AFX_MSG(UIThread)
	afx_msg void OnDoWork();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
