/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_CREATEDOWNLOADLISTDLG_H__35ED3550_E981_4ED4_BF94_94F8132856EB__INCLUDED_)
#define AFX_CREATEDOWNLOADLISTDLG_H__35ED3550_E981_4ED4_BF94_94F8132856EB__INCLUDED_

#include "fsScheduleMgr.h"	
#include "DownloadsGroupsComboBox.h"
#if _MSC_VER > 1000
#pragma once
#endif 

class CCreateDownloadListDlg : public CDialog
{

public:
	fs::list <fsString>* m_pvUrls;	
	fs::list <fsString>* m_pvReferers;	
	fs::list <fsString>* m_pvComments;	
	fs::list <fsString>* m_pvCookies;	
	class CFdmUiWindow* m_pUiWindow;

	CCreateDownloadListDlg(CWnd* pParent = NULL);   

	//{{AFX_DATA(CCreateDownloadListDlg)
	enum { IDD = IDD_CREATEURLLIST };
	CListCtrl	m_wndUrlList;
	CDownloadsGroupsComboBox m_wndGroups;
	CButton	m_btnSetTime;
	CButton	m_btnCreateGroup;
	CButton	m_btnChooseFolder;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CCreateDownloadListDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	
	DLDS_LIST* GenerateDownloads(BOOL bCheckDldExistance = TRUE);
	
	static DWORD WINAPI _threadCalculateSize(LPVOID lp);
	static DWORD WINAPI _threadCalcSize(LPVOID lp);
	void UpdateEnabled ();
	
	void DeleteSelectedUrls();
	
	void WriteUrlsToDialog();
	
	BOOL AddDownloads();
	BOOL ReadAuth();
	void OnChangeGroups();
	BOOL m_bScheduled;
	void ReadAutostart();
	int m_iAutostart;
	BOOL m_bAuthChanged;
	BOOL m_bGroupChanged;
	BOOL m_bAutoStart;
	
	fsScheduleEx m_schScheduleParam;
	
	vmsDownloadSmartPtr m_dld;
	void PrepareCHMgr(CPoint point);
	void ApplyLanguage();

	
	//{{AFX_MSG(CCreateDownloadListDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnWhatisthis();
	virtual void OnOK();
	afx_msg void OnKeydownUrllist(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDelselected();
	afx_msg void OnItemchangedUrllist(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelchangeGroups();
	afx_msg void OnCreategroup();
	afx_msg void OnChoosefolder();
	afx_msg void OnSettime();
	afx_msg void OnAdvanced();
	afx_msg void OnQuerysize();
	afx_msg void OnStartnow();
	afx_msg void OnStartmanual();
	afx_msg void OnStartschedule();
	afx_msg void OnUselogin();
	afx_msg void OnFilter();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

protected:
	bool m_bIsFirstHit;
	bool m_bUsernameChanged;
	bool m_bPasswordChanged;
public:
	afx_msg void OnEnChangeUser();
	afx_msg void OnEnChangePassword();
};

//{{AFX_INSERT_LOCATION}}

#endif 
