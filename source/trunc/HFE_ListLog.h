/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_HFE_LISTLOG_H__538CF177_2C1D_40A1_82B3_F1BE8A10266F__INCLUDED_)
#define AFX_HFE_LISTLOG_H__538CF177_2C1D_40A1_82B3_F1BE8A10266F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "HFE_FileList.h"	
#include "HFE_Log.h"	
#include "WndSplitter.h"	

class CHFE_ListLog : public CWnd
{
	friend class CHFEWnd;

public:
	CHFE_ListLog();

public:

public:

	
	//{{AFX_VIRTUAL(CHFE_ListLog)
	//}}AFX_VIRTUAL

public:
	
	void ApplyLanguage();
	
	void SaveState();
	BOOL m_bShowLog;	
	
	void ShowLog (BOOL bShow);
	BOOL Create (CWnd *pParent);
	virtual ~CHFE_ListLog();

	
protected:
	CHFE_Log m_wndLog;	
	CHFE_FileList m_wndFileList;	
	CWndSplitter m_wndSplitter;	
	//{{AFX_MSG(CHFE_ListLog)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
