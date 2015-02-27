/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSSHELLWINDOWSEVENTS_H__34F1B5DF_A780_4973_9E8F_F84179E08554__INCLUDED_)
#define AFX_FSSHELLWINDOWSEVENTS_H__34F1B5DF_A780_4973_9E8F_F84179E08554__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

enum fsSHWindowsEvent
{
	SWE_WINDOWOPENED,		
	SWE_WINDOWCLOSED		
};

typedef void (*fntSHWindowsEvents) (fsSHWindowsEvent ev, LPVOID lpParam);

class fsShellWindowsEvents : public CCmdTarget
{
	DECLARE_DYNCREATE(fsShellWindowsEvents)

public:
	fsShellWindowsEvents();
	virtual ~fsShellWindowsEvents();

public:
	
	HRESULT Attach (SHDocVw::IShellWindowsPtr& spSHWnds);
	
	void Detach ();

	
	void SetEventFunc (fntSHWindowsEvents pfn, LPVOID lpParam);

	
	//{{AFX_VIRTUAL(fsShellWindowsEvents)
	//}}AFX_VIRTUAL

protected:
	fntSHWindowsEvents m_pfnEvents;	
	LPVOID m_lpEventsParam;

	DECLARE_DISPATCH_MAP()

	
	void OnWindowRevoked (long lCookie);
	void OnWindowRegistered(long lCookie);

	LPCONNECTIONPOINT m_pConnPt;	
	DWORD m_dwCookie;				

	
	//{{AFX_MSG(fsShellWindowsEvents)
		
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
