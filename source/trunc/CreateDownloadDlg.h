/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_CREATEDOWNLOADDLG_H__03F2DDF0_42A2_447A_A6F5_59C47F718201__INCLUDED_)
#define AFX_CREATEDOWNLOADDLG_H__03F2DDF0_42A2_447A_A6F5_59C47F718201__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "DownloadsWnd.h"
#include "fsScheduleMgr.h"
#include "DownloadsGroupsComboBox.h"

#define ID_DLNOTADDED (IDCANCEL+100)

class CCreateDownloadDlg : public CDialog
{

public:
	static BOOL _CheckFolderName(CDialog *pdlg, UINT nIdCtrl);
	
	
	
	static BOOL _CheckFileName (CDialog* pdlg, UINT nIdCtrl);
	
	
	static BOOL _SetDownloadOutputFolderAsDefault (CWnd* pwndParent, LPCSTR pszFolder, vmsDownloadsGroupSmartPtr pGroup);
	
	LPCSTR m_pszPostData;
	
	LPCSTR m_pszCookies;
	
	bool m_bPlaceAtTop;
	
	bool m_bSetFocusToOKBtn;
	
	vmsDownloadsGroupSmartPtr m_pGroup;
	
	static fsSiteInfo* _SavePassword (vmsDownloadSmartPtr dld);
	
	static fsSiteInfo* _SavePassword(LPCSTR pszServer, fsNetworkProtocol np, LPCSTR pszUser, LPCSTR pszPwd);
	
	
	
	
	static int _CheckDownloadAlrExists (
		vmsDownloadSmartPtr dld, BOOL bNeedTopMost = FALSE, BOOL bShowUI = TRUE, CCreateDownloadDlg* const cddlg = NULL);
	BOOL m_bReqTopMostDialog;	
	
	fsScheduleEx m_schScheduleParam;
	BOOL m_bScheduled;			
	BOOL m_bAuthorization;		
	CString m_strUrl;			
	class CFdmUiWindow *m_pUiWindow;

	CCreateDownloadDlg(vmsDownloadSmartPtr dld, CWnd* pParent = NULL);

	//{{AFX_DATA(CCreateDownloadDlg)
	enum { IDD = IDD_CREATEDOWNLOAD };
	CButton	m_btnOutFolderSetDefault;
	CComboBox	m_wndDldType;
	CButton	m_btnSetTime;
	CButton	m_btnCreateGroup;
	CButton	m_btnChooseFolder;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CCreateDownloadDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	

	BOOL m_bUrlChanged;			
	CString m_strComment;		
	volatile BOOL m_bNeedExit;	
	volatile BOOL m_bThread;	
	
	static DWORD WINAPI _threadQSize (LPVOID lp);
	void PrepareCHMgr(CPoint point);
	int m_iAutostart;			
	void ReadAutostart();
	void ApplyLanguage();
	void OnChangeGroups();
	BOOL m_bGroupChanged;
	BOOL m_bAuthChanged;
	void UrlChanged();
	void Update_User_Password();
	
	BOOL ReadDNP();
	void WrongUserName();
	void WrongURL();
	CDownloadsGroupsComboBox m_wndGroups;
	vmsDownloadSmartPtr m_dld;		

	void UpdateEnabled();
	

	
	//{{AFX_MSG(CCreateDownloadDlg)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnChangeSaveas();
	afx_msg void OnAuthorization();
	afx_msg void OnSelchangeGroups();
	afx_msg void OnStartnow();
	afx_msg void OnStartmanual();
	afx_msg void OnStartschedule();
	afx_msg void OnCreategroup();
	afx_msg void OnAdvanced();
	afx_msg void OnChoosefolder();
	afx_msg void OnSettime();
	afx_msg void OnEditchangeUrl();
	afx_msg void OnSelchangeUrl();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnWhatisthis();
	afx_msg void OnChangeUser();
	afx_msg void OnChangePassword();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnQsize();
	virtual void OnCancel();
	afx_msg void OnFileauto();
	afx_msg void OnMirrors();
	afx_msg void OnSelchangeDldtype();
	afx_msg void OnMalicious();
	afx_msg void OnOutfolderSetdefault();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
