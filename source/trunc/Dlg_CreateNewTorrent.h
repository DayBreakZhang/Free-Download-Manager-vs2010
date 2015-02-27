/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLG_CREATENEWTORRENT_H__B39A174C_F956_4F95_9DA8_4EAA92CADBDE__INCLUDED_)
#define AFX_DLG_CREATENEWTORRENT_H__B39A174C_F956_4F95_9DA8_4EAA92CADBDE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "resource.h"

class CDlg_CreateNewTorrent : public CDialog
{

public:
	CDlg_CreateNewTorrent(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlg_CreateNewTorrent)
	enum { IDD = IDD_CREATENEWTORRENT };
	CProgressCtrl	m_wndProgress;
	CEdit		m_wndTracker;
	CListBox	m_wndTrackerList;
	CEdit		m_wndSource;
	CComboBox	m_wndPS;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlg_CreateNewTorrent)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void ApplyLanguage();
	BOOL m_bCreatingTorrent;
	BOOL m_bNeedCancel;
	int m_nProgress;
	static DWORD WINAPI _threadCreateNewTorrent (LPVOID);
	void getTrackerList (CStringList &sl);

	enum {WM_CLOSE_CREATE_TORRENT = WM_USER+1004};

	
	//{{AFX_MSG(CDlg_CreateNewTorrent)
	virtual BOOL OnInitDialog();
	afx_msg void OnFile();
	afx_msg void OnFolder();
	afx_msg void OnAddTracker();
	afx_msg void OnSelchangeTrackerList();
	afx_msg void OnRemoveTracker();
	afx_msg void OnSaveTrackers();
	afx_msg void OnRestoreTrackers();
	afx_msg void OnClearTrackers();
	virtual void OnOK();
	afx_msg void OnTimer(UINT nIDEvent);
	virtual void OnCancel();
	afx_msg LRESULT OnCloseCreateTorrent(WPARAM wparam, LPARAM lparam);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
