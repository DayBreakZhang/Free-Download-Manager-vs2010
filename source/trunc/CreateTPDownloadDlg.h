/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_CREATETPDOWNLOADDLG_H__03F2DDF0_42A2_447A_A6F5_59C47F718201__INCLUDED_)
#define AFX_CREATETPDOWNLOADDLG_H__03F2DDF0_42A2_447A_A6F5_59C47F718201__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "DownloadsGroupsComboBox.h"

#define ID_DLNOTADDED (IDCANCEL+100)

class CCreateTPDownloadDlg : public CDialog
{

public:
	static BOOL _CheckFolderName(CDialog *pdlg, UINT nIdCtrl);
	
	
	
	static BOOL _CheckFileName (CDialog* pdlg, UINT nIdCtrl);
	
	
	static BOOL _SetDownloadOutputFolderAsDefault (CWnd* pwndParent, LPCSTR pszFolder, vmsDownloadsGroupSmartPtr pGroup);
	
	bool m_bPlaceAtTop;
	
	vmsDownloadsGroupSmartPtr m_pGroup;
	
	static fsSiteInfo* _SavePassword(LPCSTR pszServer, fsNetworkProtocol np, LPCSTR pszUser, LPCSTR pszPwd);
	
	
	
	
	int _CheckDownloadAlrExists (vmsDownloadSmartPtr dld, BOOL bNeedTopMost = FALSE, BOOL bShowUI = TRUE);
	BOOL m_bReqTopMostDialog;	
	
	fsScheduleEx m_schScheduleParam;
	CString m_strUrl;			
	
	CString m_strOutFolder;
	CString m_strFileName;
	int m_nStreamingSpeed;

	CCreateTPDownloadDlg(vmsDownloadSmartPtr dld, CWnd* pParent = NULL);
	fsInternetResult Crack(LPCSTR pszUrl);

	//{{AFX_DATA(CCreateDownloadDlg)
	enum { IDD = IDD_CREATETPDOWNLOAD };
	CButton	m_btnOutFolderSetDefault;
	CComboBox	m_wndDldType;
	CButton	m_btnCreateGroup;
	CButton	m_btnChooseFolder;
	CSpinButtonCtrl	m_wndSpin;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CCreateDownloadDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	

	BOOL m_bUrlChanged;			
	void ApplyLanguage();
	void OnChangeGroups();
	BOOL m_bGroupChanged;
	BOOL m_bAuthChanged;
	void UrlChanged();
	void WrongURL();
	CDownloadsGroupsComboBox m_wndGroups;
	vmsDownloadSmartPtr m_dld;		

	void UpdateEnabled();
	BOOL m_bSetSaveAs;			

	volatile BOOL m_bNeedExit;	
	volatile BOOL m_bThread;	
	
	static DWORD WINAPI _threadQSize (LPVOID lp);
	
	//{{AFX_MSG(CCreateDownloadDlg)
	
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeGroups();
	afx_msg void OnCreategroup();
	afx_msg void OnChoosefolder();
	afx_msg void OnOutfolderSetdefault();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEditchangeUrl();
	afx_msg void OnSelchangeUrl();
	afx_msg void OnOk();
	afx_msg void OnSelchangeDldtype();
	afx_msg void OnCancel();
	afx_msg void OnChangeSaveas();
	afx_msg void OnFileauto();
	afx_msg void OnQsize();
};

//{{AFX_INSERT_LOCATION}}

#endif 
