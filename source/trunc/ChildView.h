/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_CHILDVIEW_H__41E3821A_FD14_4002_B95D_FB6E2383B71E__INCLUDED_)
#define AFX_CHILDVIEW_H__41E3821A_FD14_4002_B95D_FB6E2383B71E__INCLUDED_

#include "ClientAreaWnd.h"	
#include "SmallTipWnd.h"	

#if _MSC_VER > 1000
#pragma once
#endif 

class CChildView : public CWnd
{
	friend class CMainFrame;

public:
	CChildView();

public:

public:

	
	//{{AFX_VIRTUAL(CChildView)
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

public:
	void ApplyShowSmallTipsSetting();
	virtual ~CChildView();

	
protected:
	void ApplySize (int cx, int cy);
	bool m_bShowSmallTip;
	CSmallTipWnd m_wndSmallTip;
	
	afx_msg void OnUpdatePluginCommand (CCmdUI* pCmdUI);
	
	void OnPluginCommand (UINT);

	CClientAreaWnd m_wndClient;	
	DECLARE_DYNAMIC(CChildView)

	//{{AFX_MSG(CChildView)
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnSmallTipClose();
	afx_msg void OnSmallTipChanged();
	afx_msg void OnApplyShowSmallTipsSetting();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
