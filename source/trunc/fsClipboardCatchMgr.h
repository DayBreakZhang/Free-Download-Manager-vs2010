/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSCLIPBOARDCATCHMGR_H__C2ACEFED_8EC8_4866_AE8C_AD8A9159448E__INCLUDED_)
#define AFX_FSCLIPBOARDCATCHMGR_H__C2ACEFED_8EC8_4866_AE8C_AD8A9159448E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class fsClipboardCatchMgr : public CWnd
{

public:
	fsClipboardCatchMgr();

public:

public:

	
	//{{AFX_VIRTUAL(fsClipboardCatchMgr)
	//}}AFX_VIRTUAL

public:
	
	void Initialize (class fsIECatchMgr* iemgr);
	
	BOOL IsEnabled();
	
	void Enable (BOOL bEnable = TRUE);

	
	BOOL Create (CWnd* pParent);
	virtual ~fsClipboardCatchMgr();

	
protected:
	CString m_strLastUrl;		
	BOOL m_bEnabled;			
	fsIECatchMgr* m_pIEMgr;
	HWND m_hNextViewer;		
	//{{AFX_MSG(fsClipboardCatchMgr)
	afx_msg void OnDrawClipboard();
	afx_msg void OnChangeCbChain(HWND hWndRemove, HWND hWndAfter);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
