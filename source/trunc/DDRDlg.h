/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DDRDLG_H__3821C1CB_5B95_4166_BC5C_6AFC0137BDE4__INCLUDED_)
#define AFX_DDRDLG_H__3821C1CB_5B95_4166_BC5C_6AFC0137BDE4__INCLUDED_

#include "fsDownloadsMgr.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

class CDDRDlg : public CDialog
{

public:
	BOOL m_bNoCancel;	
	BOOL m_bForAll;		
	BOOL m_bDontAskAgain;	
	CString m_strUrl;	
	fsDeleteDownloadReaction m_enDDR;	
	CDDRDlg(CWnd* pParent = NULL);

	//{{AFX_DATA(CDDRDlg)
	enum { IDD = IDD_DDR };
		
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDDRDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void PrepareCHMgr(CPoint point);
	void ApplyLanguage();

	
	//{{AFX_MSG(CDDRDlg)
	afx_msg void OnYes();
	afx_msg void OnNo();
	virtual BOOL OnInitDialog();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnWhatisthis();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnYestoall();
	afx_msg void OnNotoall();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
