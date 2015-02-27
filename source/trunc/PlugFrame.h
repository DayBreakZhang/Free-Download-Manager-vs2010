/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_PLUGFRAME_H__2F18C148_2AB2_4A87_B684_E36868D557F3__INCLUDED_)
#define AFX_PLUGFRAME_H__2F18C148_2AB2_4A87_B684_E36868D557F3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CPlugFrame : public CWnd
{

public:
	CPlugFrame();

public:

public:

	
	//{{AFX_VIRTUAL(CPlugFrame)
	//}}AFX_VIRTUAL

public:
	
	void SetPluginWindow (HWND hWnd);
	
	void SetFrameName (LPCTSTR pszName);
	BOOL Create (CWnd* pParent);
	virtual ~CPlugFrame();

	
protected:
	CFont m_font;	
	COLORREF m_clrBkCaption, m_clrCaptionText;	
	void SetupPluginRect();
	int m_dyCaption;	
	HWND m_wndPlugin;
	CString m_strFrameName;
	//{{AFX_MSG(CPlugFrame)
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
