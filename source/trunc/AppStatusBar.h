/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_APPSTATUSBAR_H__7600D4AD_0967_4536_AEBB_667CC84F3D9C__INCLUDED_)
#define AFX_APPSTATUSBAR_H__7600D4AD_0967_4536_AEBB_667CC84F3D9C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CAppStatusBar : public CStatusBar
{

public:
	CAppStatusBar();

public:

public:

	
	//{{AFX_VIRTUAL(CAppStatusBar)
	//}}AFX_VIRTUAL

public:
	void SetToolTipText (UINT nIDTip, LPCSTR pszText);
	virtual ~CAppStatusBar();

	
protected:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CToolTipCtrl m_ttip;
	//{{AFX_MSG(CAppStatusBar)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
