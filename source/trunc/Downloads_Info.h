/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DOWNLOADS_INFO_H__607680D5_1B90_421B_AF4E_1C523B15CCB3__INCLUDED_)
#define AFX_DOWNLOADS_INFO_H__607680D5_1B90_421B_AF4E_1C523B15CCB3__INCLUDED_

#include "Downloads_InfoFrame.h"	
#include "Downloads_Log.h"	
#include "Downloads_Progress.h"	
#include "Downloads_VideoPreview.h"	
#include "Downloads_Opinions.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

#include "fsDownload.h"
#include "Downloads_Bittorrent.h"	

enum CDownloads_Info_Tab
{
	DIT_LOG				= 0,
	DIT_BT				= 1,
	DIT_PROGRESS		= 2,
	DIT_MEDIAPREVIEW	= 3,
	DIT_OPINIONS		= 4,
};

class CDownloads_Info : public CTabCtrl
{
	
	
	friend class CMainFrame;

public:
	CDownloads_Info();

public:

public:

	
	//{{AFX_VIRTUAL(CDownloads_Info)
	//}}AFX_VIRTUAL

public:
	void UpdateBtStat();
	CDownloads_Bittorrent m_bt;
	int get_CurTab();
	void set_CurTab (int nIndex);
	CDownloads_Progress* Get_ProgressWindow();
	CDownloads_Log* Get_LogWindow();
	
	
	void AddDownloadEvent (fsDownloadEvents *event);
	
	void UpdateActiveDownload();
	
	void Set_ActiveDownload (vmsDownloadSmartPtr dld);
	vmsDownloadSmartPtr Get_ActiveDownload();
	
	void SaveState();
	
	void ApplyLanguage();
	BOOL Create (CWnd *pParent);
	virtual ~CDownloads_Info();

	CDownloads_Opinions m_opinions;	
	CDownloads_VideoPreview m_video; 
	CDownloads_Progress m_progress;	

	
protected:
	void ApplyBtTab();
	bool m_bBtTabShowing;
	bool m_bBtTabWasActive;
	BOOL IsBtDownloadActive();
	vmsDownloadSmartPtr m_activeDld;
	int m_cy;
	
	void ApplyCurTab();
	CDownloads_Log m_log;			
	CImageList m_images;			
	CDownloads_InfoFrame m_frame;	
	CFont m_itemsFont;				
	//{{AFX_MSG(CDownloads_Info)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
	afx_msg void OnSelchange(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
