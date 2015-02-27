/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_CHILDVIEW_H__7AF47CEC_A050_40CA_A214_27474B40D8D0__INCLUDED_)
#define AFX_CHILDVIEW_H__7AF47CEC_A050_40CA_A214_27474B40D8D0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "..\CoreDll\dll.h"
#include "vmsUploadsDllCaller.h"	

extern vmsUploadsDll::vmsUploadsWnd *_pwndUploads;

class CChildView : public CWnd
{

public:
	CChildView();

public:

public:

	
	//{{AFX_VIRTUAL(CChildView)
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

public:
	
	
	vmsUploadsDll::vmsUploadsWnd *m_pwndUploads;

	virtual ~CChildView();

	
protected:
	afx_msg void OnUpdateViewUploadsLogColumn (CCmdUI *pCmdUI);
	afx_msg void OnViewUploadsLogColumn (UINT nId);
	afx_msg void OnUpdateViewUploadsColumn (CCmdUI *pCmdUI);
	afx_msg void OnViewUploadsColumn (UINT nId);
	afx_msg void OnPluginCommand (UINT nCmd);
	afx_msg void OnUpdatePluginCommand (CCmdUI *pCmdUI);
	
	
	HMODULE m_hUploadsDll;
	
	vmsUploadsDllCaller m_udc;

	//{{AFX_MSG(CChildView)
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnToolsUploadersettings();
	afx_msg void OnInitMenuPopup(CMenu* pPopupMenu, UINT nIndex, BOOL bSysMenu);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
