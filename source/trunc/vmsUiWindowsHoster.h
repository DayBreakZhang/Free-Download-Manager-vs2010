/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSUIWINDOWSHOSTER_H__439F50DE_4587_4D09_8058_B5BDECCE3758__INCLUDED_)
#define AFX_VMSUIWINDOWSHOSTER_H__439F50DE_4587_4D09_8058_B5BDECCE3758__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsUiWindow.h"

class vmsUiWindowsHoster : public CWnd
{

public:
	vmsUiWindowsHoster();

public:

public:

	
	//{{AFX_VIRTUAL(vmsUiWindowsHoster)
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

public:
	void AttachUiWindow (vmsUiWindow *pUiWindow);
	virtual ~vmsUiWindowsHoster();

	
protected:
	vmsUiWindow* m_pUiWindow;
	//{{AFX_MSG(vmsUiWindowsHoster)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnEnterIdle(UINT nWhy, CWnd* pWho);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
