/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_AERDLG_H__E965C146_EC84_4EC8_89ED_2736E7E67231__INCLUDED_)
#define AFX_AERDLG_H__E965C146_EC84_4EC8_89ED_2736E7E67231__INCLUDED_

#include "DownloadProperties.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

class CAERDlg : public CDialog
{

public:
	BOOL m_bDontAskAgain;	
	fsAlreadyExistReaction m_enAER;	
	LPCSTR m_pszFile;		
	void DisableStopAndResume();	
	CAERDlg(CWnd* pParent = NULL);   

	//{{AFX_DATA(CAERDlg)
	enum { IDD = IDD_AER };
		
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CAERDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	
	void PrepareCHMgr(CPoint point);
	
	void ApplyLanguage();
	BOOL m_bDSR;	

	
	//{{AFX_MSG(CAERDlg)
	afx_msg void OnRewrite();
	afx_msg void OnRename();
	afx_msg void OnStop();
	afx_msg void OnResume();
	virtual BOOL OnInitDialog();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnWhatisthis();
	afx_msg void OnClose();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
