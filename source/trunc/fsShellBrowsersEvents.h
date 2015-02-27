/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSSHELLBROWSERSEVENTS_H__7A084469_2A99_4025_A3F4_D7545A51F633__INCLUDED_)
#define AFX_FSSHELLBROWSERSEVENTS_H__7A084469_2A99_4025_A3F4_D7545A51F633__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

enum fsSHBrowserEvent
{
	SBE_BEFORENAVIGATE,		
	SBE_DLBEGIN,			
	SBE_DLCOMPLETE,			
	SBE_DOCUMENTCOMPLETE,
};

typedef BOOL (*fntSHBrowserEvent) (class fsShellBrowsersEvents* pBrowser, fsSHBrowserEvent ev, DWORD dwInfo, LPVOID lpParam);

class fsShellBrowsersEvents : public CCmdTarget
{
	DECLARE_DYNCREATE(fsShellBrowsersEvents)

public:
	fsShellBrowsersEvents();
	virtual ~fsShellBrowsersEvents();

public:
	IWebBrowser2* get_WB();
	BOOL is_Attached();
	
	HRESULT Attach(SHDocVw::IShellWindowsPtr& spSHWnds);
	
	void Detach();

	void SetEventFunc (fntSHBrowserEvent pfn, LPVOID lpParam);

	
	//{{AFX_VIRTUAL(fsShellBrowsersEvents)
	//}}AFX_VIRTUAL

protected:
	bool m_bDetaching;
	LPDISPATCH m_pWBRoot;
	void OnNavigateComplete2 (LPDISPATCH pDisp, VARIANT* URL);
	void OnDocumentComplete (LPDISPATCH pDisp, VARIANT* URL);
	void OnDownloadComplete();
	void OnDownloadBegin();
	void OnBeforeNavigate (LPDISPATCH, VARIANT*, VARIANT*, VARIANT*, VARIANT*, VARIANT*, BOOL*);

	BOOL Event (fsSHBrowserEvent ev, DWORD dwInfo = 0);
	fntSHBrowserEvent m_pfnEvents;
	LPVOID m_lpEventsParam;
	
	DECLARE_DISPATCH_MAP()

	HRESULT Attach (SHDocVw::IWebBrowser2Ptr& spBrowser);
	
	IWebBrowser2Ptr m_spWB;
	IConnectionPointPtr m_spConnPt;	
	DWORD m_dwCookie;					

	fs::list <fsShellBrowsersEvents*> m_vBrowsers;

	
	//{{AFX_MSG(fsShellBrowsersEvents)
		
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
