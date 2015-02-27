/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_CLIENTAREAWND_H__9802A8EE_E0EC_48CD_AB34_6BE9737F8E21__INCLUDED_)
#define AFX_CLIENTAREAWND_H__9802A8EE_E0EC_48CD_AB34_6BE9737F8E21__INCLUDED_

#include "WndSplitter.h"	
#include "PlugToolBarContainer.h"	
#include "PlugFrame.h"	
#include "PluginFrame2.h"

#if _MSC_VER > 1000
#pragma once
#endif 

class CClientAreaWnd : public CWnd
{
	friend class CChildView;
	friend class CMainFrame;

public:
	CClientAreaWnd();

public:

public:

	
	//{{AFX_VIRTUAL(CClientAreaWnd)
	//}}AFX_VIRTUAL

public:
	
	void SaveState();
	
	BOOL m_bShowSWBar;
	
	BOOL Create (CWnd *pParent);
	virtual ~CClientAreaWnd();

	
protected:
	CPluginFrame2 m_plugs2;	

	//{{AFX_MSG(CClientAreaWnd)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
