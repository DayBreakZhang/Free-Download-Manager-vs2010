/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VIDEOWINDOW_H__0B06D872_8B5B_4DDC_9D29_9EEB7F3DEC9B__INCLUDED_)
#define AFX_VIDEOWINDOW_H__0B06D872_8B5B_4DDC_9D29_9EEB7F3DEC9B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "PartMediaPreview/fsPartMediaPlayer.h"

class CVideoWindow : public CWnd
{
public:
	CVideoWindow();          
	virtual ~CVideoWindow();

protected:
	

public:

public:
	BOOL Create (CWnd* pWndParent);
	fsPartMediaPlayer m_player;

	
	//{{AFX_VIRTUAL(CVideoWindow)
	protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

protected:
	afx_msg LRESULT OnGraphMessage (WPARAM, LPARAM);
	
	
	//{{AFX_MSG(CVideoWindow)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
