/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_CREATEDOWNLOADFROMTORRENTFILEDLG_H__1959D54F_6F49_4254_A209_0F75D0BAC356__INCLUDED_)
#define AFX_CREATEDOWNLOADFROMTORRENTFILEDLG_H__1959D54F_6F49_4254_A209_0F75D0BAC356__INCLUDED_

#include "fsScheduleMgr.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

#include "DownloadsGroupsComboBox.h"
#include "fsDownload.h"	

class CCreateDownloadFromTorrentFileDlg : public CDialog
{

public:
	
	BOOL m_bPlaceToTop;
	
	BOOL m_bScheduled;
	vmsDownloadSmartPtr m_dld;
	
	fsScheduleEx m_schScheduleParam;
	CCreateDownloadFromTorrentFileDlg(CWnd* pParent = NULL);   

	//{{AFX_DATA(CCreateDownloadFromTorrentFileDlg)
	enum { IDD = IDD_CREATETORRENTDOWNLOAD };
	CDownloadsGroupsComboBox	m_wndGroups;
	CButton	m_btnSetTime;
	CButton	m_btnSetDefaultFolder;
	CButton	m_btnCreateGroup;
	CButton	m_btnChooseFolder;
	LPCTSTR m_ptszTorrentFile;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CCreateDownloadFromTorrentFileDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void UpdateEnabled();
	void ApplyLanguage();

	
	//{{AFX_MSG(CCreateDownloadFromTorrentFileDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnUselogin();
	afx_msg void OnCreategroup();
	afx_msg void OnChoosefolder();
	afx_msg void OnOutfolderSetdefault();
	afx_msg void OnSettime();
	afx_msg void OnAdvanced();
	virtual void OnOK();
	afx_msg void OnSelchangeGroups();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
