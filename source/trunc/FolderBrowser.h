/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FOLDERBROWSER_H__3A6754F8_1826_4E26_8EA0_247CEDD47BFB__INCLUDED_)
#define AFX_FOLDERBROWSER_H__3A6754F8_1826_4E26_8EA0_247CEDD47BFB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CFolderBrowser : public CWinThread
{
	DECLARE_DYNCREATE(CFolderBrowser)
protected:
	CFolderBrowser();           

public:

public:
	LPCSTR GetPath();
	static CFolderBrowser* Create (LPCSTR pszTitle, LPCSTR pszPath, LPCSTR pszRoot, CWnd* pWndParent);

	
	//{{AFX_VIRTUAL(CFolderBrowser)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

protected:
	CString m_strResPath;
	BOOL m_bResult;
	LPCSTR m_pszPath;
	LPCSTR m_pszTitle;
	LPCSTR m_pszRoot;
	HWND m_hWndParent;

	virtual ~CFolderBrowser();

	
	//{{AFX_MSG(CFolderBrowser)
		
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
