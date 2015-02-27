/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DOWNLOADS_BITTORRENT_FILES_H__2815A0B6_6537_42CE_84E1_6E60764728E0__INCLUDED_)
#define AFX_DOWNLOADS_BITTORRENT_FILES_H__2815A0B6_6537_42CE_84E1_6E60764728E0__INCLUDED_

#include "fsDownload.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

#include "ColumnTreeCtrl.h"

class CDownloads_Bittorrent_Files : public CColumnTreeCtrl
{

public:
	CDownloads_Bittorrent_Files();

public:

public:

	
	//{{AFX_VIRTUAL(CDownloads_Bittorrent_Files)
	//}}AFX_VIRTUAL

public:
	void UpdateProgress();
	void set_ActiveDownload(vmsDownloadSmartPtr dld);
	void ApplyLanguage();
	BOOL Create(CWnd *pwndParent);
	virtual ~CDownloads_Bittorrent_Files();

	
protected:
	void ApplyLanguageToMenuBtFiles (CMenu* pmenu);
	void ShowContextMenu(HTREEITEM hItem);
	afx_msg void OnRclick (NMHDR* , LRESULT* pResult);
	void AddFiles (fs::ListTree <vmsBtDownloadManager::vmsFile>* pTree, CColumnTreeCtrl *pTreeCtrl, HTREEITEM hRoot);
	int m_nFileNameOffset;
	vmsDownloadSmartPtr m_dld;
	//{{AFX_MSG(CDownloads_Bittorrent_Files)
	afx_msg void OnBtfilesDontdownload();
	afx_msg void OnBtfilesHighpiority();
	afx_msg void OnBtfilesNormalpriority();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
