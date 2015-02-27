/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_CREATEBATCHDOWNLOAD_H__FB47F1B8_CAF4_49A0_AA5C_265C287F6373__INCLUDED_)
#define AFX_CREATEBATCHDOWNLOAD_H__FB47F1B8_CAF4_49A0_AA5C_265C287F6373__INCLUDED_

#include "fsScheduleMgr.h"	
#include "fsDownloadsMgr.h"	
#include "DownloadsGroupsComboBox.h"
#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsBatchList.h"	

class CCreateBatchDownload : public CDialog
{

public:
	
	fsScheduleEx m_schScheduleParam;
	CCreateBatchDownload(CWnd* pParent = NULL);  

	//{{AFX_DATA(CCreateBatchDownload)
	enum { IDD = IDD_CREATEBATCHDOWNLOAD };
	CButton	m_btnOutFolderSetDefault;
	CComboBox	m_wndZ;
	CComboBox	m_wndA;
	CDownloadsGroupsComboBox m_wndGroups;
	CButton	m_btnSetTime;
	CButton	m_btnCreateGroup;
	CButton	m_btnChooseFolder;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CCreateBatchDownload)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	
	vmsBatchList m_bl, m_blSaveAs;
	
	bool m_bBLParametersChanged;
	
	
	void FillZ();
	
	void FreeDownloads();
	
	static DWORD WINAPI _threadCalculateSize (LPVOID lp);
	static DWORD WINAPI _threadCalcSize (LPVOID lp);
	
	
	DLDS_LIST* GenerateDownloads();
	
	void GenerateAndAddDownloads();
	
	BOOL ReadAuth();
	
	BOOL CheckUrl();
	
	void WrongUrl();
	
	BOOL BuildBatchList();
	int m_iAlphaFrom, m_iAlphaTo;	
	void PrepareCHMgr (CPoint point);
	BOOL m_bScheduled;	
	BOOL m_bAuthorization;	
	vmsDownloadSmartPtr m_dld;	
	int m_iAutostart;	
	void ApplyLanguage();
	
	void ReadAutostart();
	
	void UrlChanged();
	
	void Update_User_Password();
	
	void UpdateEnabled();
	BOOL m_bGroupChanged, m_bAuthChanged;

	
	void OnChangeGroups();
	CString m_strUrl;			
	DLDS_LIST* m_pvDownloads;

	
	//{{AFX_MSG(CCreateBatchDownload)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeGroups();
	afx_msg void OnEditchangeUrl();
	afx_msg void OnSelchangeUrl();
	afx_msg void OnUselogin();
	afx_msg void OnChangeUser();
	afx_msg void OnChangePassword();
	afx_msg void OnStartnow();
	afx_msg void OnStartmanual();
	afx_msg void OnStartschedule();
	afx_msg void OnCreategroup();
	afx_msg void OnChoosefolder();
	afx_msg void OnSettime();
	afx_msg void OnAdvanced();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnWhatisthis();
	afx_msg void OnResults();
	virtual void OnOK();
	afx_msg void OnQuerysize();
	virtual void OnCancel();
	afx_msg void OnSelchangeA();
	afx_msg void OnSelchangeZ();
	afx_msg void OnChangeNumbers();
	afx_msg void OnSetnumbers();
	afx_msg void OnFileauto();
	afx_msg void OnOutfolderSetdefault();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
