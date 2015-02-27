/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_SPIDERADDPAGEDLG_H__79BC625E_210D_4F12_B127_5C0A95C10E5B__INCLUDED_)
#define AFX_SPIDERADDPAGEDLG_H__79BC625E_210D_4F12_B127_5C0A95C10E5B__INCLUDED_

#include "fsScheduleMgr.h"	
#include "fsWebPageDownloader.h"
#include "DownloadsGroupsComboBox.h"
#if _MSC_VER > 1000
#pragma once
#endif 

class CSpiderAddPageDlg : public CDialog
{

public:
	
	
	
	static BOOL IsOkUrl (LPCSTR pszUrl, LPCSTR pszHTMLExts, BOOL *pbMustAddSlash = NULL);
	
	void ReadAutostart();
	fsWebPageDownloader* m_wpd;	
	CString m_strUrl;
	BOOL m_bScheduled;
	BOOL m_bAutoStart;
	BOOL m_bReqTopMost;
	CString m_strStartUrl;	
	
	fsScheduleEx m_schScheduleParam;
	class CFdmUiWindow *m_pUiWindow;
	CSpiderAddPageDlg(CWnd* pParent = NULL);   

	//{{AFX_DATA(CSpiderAddPageDlg)
	enum { IDD = IDD_SPIDER_ADD };
	CButton	m_btnOutFolderSetDefault;
	CSpinButtonCtrl	m_wndDepthSpin;
	CDownloadsGroupsComboBox	m_wndGroups;
	CButton	m_btnSetTime;
	CButton	m_btnCreateGroup;
	CButton	m_btnChooseFolder;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CSpiderAddPageDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	BOOL m_bAuthChanged;
	
	void BuildOutFolder();
	
	CString m_strBaseFolder;
	void PrepareCHMgr(CPoint point);
	BOOL WriteAuthorization();
	void UpdateEnabled();
	int m_iAutostart;
	void ApplyLanguage();
	void WrongURL();
	BOOL m_bGroupChanged, m_bOutFolderChanged;
	void OnUrlChanged();
	void OnChangeGroups();

	
	//{{AFX_MSG(CSpiderAddPageDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeGroups();
	afx_msg void OnAdvanced();
	afx_msg void OnCreategroup();
	afx_msg void OnChoosefolder();
	afx_msg void OnSettime();
	afx_msg void OnStartnow();
	afx_msg void OnStartmanual();
	afx_msg void OnStartschedule();
	afx_msg void OnEditchangeUrl();
	afx_msg void OnSelchangeUrl();
	virtual void OnOK();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnWhatisthis();
	afx_msg void OnUselogin();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnEditchangeOutfolder();
	afx_msg void OnSelchangeOutfolder();
	afx_msg void OnKeep();
	afx_msg void OnChangeUser();
	afx_msg void OnChangePassword();
	afx_msg void OnOutfolderSetdefault();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
