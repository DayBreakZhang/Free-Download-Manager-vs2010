/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLGFINDADVANCED_H__3A52FC0C_4FBB_4082_A09A_40CFBC3B386E__INCLUDED_)
#define AFX_DLGFINDADVANCED_H__3A52FC0C_4FBB_4082_A09A_40CFBC3B386E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "DownloadsGroupsComboBox.h"

class CDlgFindAdvanced : public CDialog
{

public:
	CDlgFindAdvanced(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlgFindAdvanced)
	enum { IDD = IDD_FIND_ADVANCED };
	CComboBox	m_wndDim2;
	CComboBox	m_wndDim1;
	CDownloadsGroupsComboBox	m_wndGroups;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlgFindAdvanced)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	BOOL SetTime();
	BOOL m_bTimeSet;	
	FILETIME m_t2;		
	FILETIME m_t1;		
	void PrepareCHMgr(CPoint point);
	void ApplyLanguage();
	void UpdateEnabled();

	
	//{{AFX_MSG(CDlgFindAdvanced)
	virtual BOOL OnInitDialog();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnWhatisthis();
	virtual void OnOK();
	afx_msg void OnSelchangeGroups();
	afx_msg void OnListofdlds();
	afx_msg void OnDeleted();
	afx_msg void OnHistofdlds();
	afx_msg void OnUsetime();
	afx_msg void OnUsesize();
	afx_msg void OnSettime();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
