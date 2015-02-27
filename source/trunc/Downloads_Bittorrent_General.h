/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DOWNLOADS_BITTORRENT_GENERAL_H__58AC4EA6_ABD4_4A93_85A9_3DCE594805F1__INCLUDED_)
#define AFX_DOWNLOADS_BITTORRENT_GENERAL_H__58AC4EA6_ABD4_4A93_85A9_3DCE594805F1__INCLUDED_

#include "fsDownload.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

class CDownloads_Bittorrent_General : public CListCtrl
{

public:
	CDownloads_Bittorrent_General();

public:

public:

	
	//{{AFX_VIRTUAL(CDownloads_Bittorrent_General)
	//}}AFX_VIRTUAL

public:
	void UpdateWastedStat();
	void UpdatePeersStat();
	void UpdateUploadStat();
	void ApplyLanguage();
	void UpdateStat();
	void set_ActiveDownload (vmsDownloadSmartPtr dld);
	BOOL Create(CWnd *pParent);
	virtual ~CDownloads_Bittorrent_General();

	
protected:
	BOOL m_bVisible;
	vmsDownloadSmartPtr m_dld;
	//{{AFX_MSG(CDownloads_Bittorrent_General)
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnCmdUpdate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
