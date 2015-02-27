/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_SCRDLG_H__3B8B9873_0250_499B_9D01_DA434EEA6DCD__INCLUDED_)
#define AFX_SCRDLG_H__3B8B9873_0250_499B_9D01_DA434EEA6DCD__INCLUDED_

#include "DownloadProperties.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

class CSCRDlg : public CDialog
{

public:
	BOOL m_bDontAskAgain;	
	fsSizeChangeReaction m_enSCR;	
	const fsDownload_NetworkProperties* m_dnp;	
	CSCRDlg(CWnd* pParent = NULL);   

	//{{AFX_DATA(CSCRDlg)
	enum { IDD = IDD_SCR };
		
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CSCRDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void PrepareCHMgr(CPoint point);
	void ApplyLanguage();

	
	//{{AFX_MSG(CSCRDlg)
	afx_msg void OnRestart();
	afx_msg void OnAdjust();
	afx_msg void OnStop();
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
