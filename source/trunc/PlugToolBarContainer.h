/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_PLUGTOOLBARCONTAINER_H__3CC12D5A_80C7_49BA_8DA4_100B42B367B3__INCLUDED_)
#define AFX_PLUGTOOLBARCONTAINER_H__3CC12D5A_80C7_49BA_8DA4_100B42B367B3__INCLUDED_

#include "PlugToolBar.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

class CPlugToolBarContainer : public CWnd
{
	friend class CChildView;
	friend class CMainFrame;

public:
	CPlugToolBarContainer();

public:

public:

	
	//{{AFX_VIRTUAL(CPlugToolBarContainer)
	//}}AFX_VIRTUAL

public:
	void SetPlugsFrame (CPlugFrame* pFrame);
	BOOL Create (CWnd *pParent);
	virtual ~CPlugToolBarContainer();

	
protected:
	CPlugToolBar m_plugToolBar;	
	//{{AFX_MSG(CPlugToolBarContainer)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
