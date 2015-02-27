/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DOWNLOADS_BITTORRENT_H__1953213D_2F56_4D8E_A297_E8928ED6156D__INCLUDED_)
#define AFX_DOWNLOADS_BITTORRENT_H__1953213D_2F56_4D8E_A297_E8928ED6156D__INCLUDED_

#include "Downloads_Bittorrent_General.h"	
#include "Downloads_Bittorrent_Peers.h"	
#include "Downloads_Bittorrent_Files.h"	
#include "fsDownload.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

class CDownloads_Bittorrent : public CTabCtrl
{

public:
	CDownloads_Bittorrent();

public:

public:

	
	//{{AFX_VIRTUAL(CDownloads_Bittorrent)
	//}}AFX_VIRTUAL

public:
	void UpdateActiveDownload();
	vmsDownloadSmartPtr getActiveDownload();
	CDownloads_Bittorrent_Files m_files;
	void UpdatePeersStat();
	void set_ActiveTab(int nTab);
	CDownloads_Bittorrent_Peers m_peers;
	void UpdateStat();
	CDownloads_Bittorrent_General m_general;
	void ApplyLanguage();
	void Set_ActiveDownload(vmsDownloadSmartPtr dld);
	BOOL Create(CWnd *pParent);
	virtual ~CDownloads_Bittorrent();

	
protected:
	vmsDownloadSmartPtr m_dldActive;
	void ApplyCurTab();
	void ApplySize();
	std::vector <CWnd*> m_vTabs;
	CFont m_fontItems;
	//{{AFX_MSG(CDownloads_Bittorrent)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSelchange(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
