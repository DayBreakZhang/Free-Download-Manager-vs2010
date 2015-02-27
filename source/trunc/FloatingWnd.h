/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FLOATINGWND_H__3135B822_307F_40AB_A070_F7906C9BCCB1__INCLUDED_)
#define AFX_FLOATINGWND_H__3135B822_307F_40AB_A070_F7906C9BCCB1__INCLUDED_

#include "FloatingWndDropTarget.h"	
#include "XInfoTip.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

class CFloatingWnd : public CFrameWnd
{
	
protected:

public:
	CFloatingWnd(); 

public:
	void HideAlways();
	void SetBlend (BYTE val);
	
	void UpdateTimer();
	
	
	void Show(BOOL bShow, BOOL bByUser = TRUE);
	
	void SaveState();
	BOOL Create();
	virtual ~CFloatingWnd();

	
	//{{AFX_VIRTUAL(CFloatingWnd)
	//}}AFX_VIRTUAL

protected:
	BOOL m_bHideAlways;
	
	void ShowTip();
	CXInfoTip m_wndTip;
	BOOL m_bShown; 
	BOOL m_bTimerSet; 
	CFloatingWndDropTarget m_drop;	
	BYTE m_blend;		
	HICON m_hLogoIcon;	
	class CMainFrame* m_pMainFrame;

	
	//{{AFX_MSG(CFloatingWnd)
	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnNcRButtonUp(UINT nHitTest, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnNcLButtonDblClk(UINT nHitTest, CPoint point);
	afx_msg void OnClose();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnMoving(UINT fwSide, LPRECT pRect);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
