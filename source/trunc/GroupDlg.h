/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_GROUPDLG_H__83ECF421_B610_4EE0_A638_E6EE45DD232B__INCLUDED_)
#define AFX_GROUPDLG_H__83ECF421_B610_4EE0_A638_E6EE45DD232B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsDownloadsGroupsMgr.h"
#include "DownloadsGroupsComboBox.h"

class CGroupDlg : public CDialog
{

public:
	CGroupDlg(vmsDownloadsGroupSmartPtr pGroup, vmsDownloadsGroupSmartPtr pParentGroup, CWnd* pParent);   

	vmsDownloadsGroupSmartPtr m_pGroup;	
	vmsDownloadsGroupSmartPtr m_pParentGroup;

	//{{AFX_DATA(CGroupDlg)
	enum { IDD = IDD_DLDGROUP };
	CDownloadsGroupsComboBox	m_wndGroups;
	CButton	m_btnChooseFolder;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CGroupDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	afx_msg void OnInsertMacros (UINT nIDMacrosCmd);
	void PrepareCHMgr(CPoint point);
	void ApplyLanguage();
	
	
	CString m_strBaseFolder; 
	
	
	
	BOOL m_bPathChanged;
	
	
	//{{AFX_MSG(CGroupDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnChoosefolder();
	afx_msg void OnChangeGrpname();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnWhatisthis();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnMacroses();
	afx_msg void OnSelchangeGroups();
	afx_msg void OnSelchangeGrpfolder();
	afx_msg void OnEditchangeGrpfolder();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
