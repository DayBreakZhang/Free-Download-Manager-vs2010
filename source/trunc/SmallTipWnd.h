/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_SMALLTIPWND_H__F3CC2362_EE6C_453F_A4FC_DD909ECDB959__INCLUDED_)
#define AFX_SMALLTIPWND_H__F3CC2362_EE6C_453F_A4FC_DD909ECDB959__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsUiWindowsHoster.h"
#include "vmsSingleLineTooltip.h"	

#define ID_SMALLTIP_CLOSE		100
#define ID_SMALLTIP_CHANGED		101

class CSmallTipWnd : public vmsUiWindowsHoster, public vmsUiWindow
{

public:
	CSmallTipWnd();

public:

public:

	
	//{{AFX_VIRTUAL(CSmallTipWnd)
	//}}AFX_VIRTUAL

public:
	void Draw(CDC *pdc);
	void setPos (int x, int y, int cx, int cy);
	CSize getRequiredSize () const;
	void Create (CWnd* pwndParent);
	virtual ~CSmallTipWnd();

	
protected:
	tstring m_tstrCurrentTip;
	CRect m_rcClose;
	CBitmap m_bmpClose; BITMAP m_bmClose;
	CBitmap m_bmpTip; BITMAP m_bmTip;
	vmsSingleLineTooltip m_tip;
	//{{AFX_MSG(CSmallTipWnd)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnSetToDownloadOneByOne();
	afx_msg void OnEnableSilentMonitoring();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
