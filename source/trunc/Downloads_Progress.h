/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DOWNLOADS_PROGRESS_H__2F46F44F_3115_40E7_9305_BE4E4F04810D__INCLUDED_)
#define AFX_DOWNLOADS_PROGRESS_H__2F46F44F_3115_40E7_9305_BE4E4F04810D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "list.h"

class CDownloads_Progress : public CWnd
{

public:
	CDownloads_Progress();

public:

public:

	
	//{{AFX_VIRTUAL(CDownloads_Progress)
	//}}AFX_VIRTUAL

public:
	
	void set_FullRedraw ();
	
	void UpdateDownload ();
	
	void SetActiveDownload (vmsDownloadSmartPtr dld);
	vmsDownloadSmartPtr GetActiveDownload();
	BOOL Create (CWnd *pParent);
	virtual ~CDownloads_Progress();

	
protected:
	bool m_bRepaintBitmap;
	CBitmap m_bmpProgress;
	int m_iLastProgress;
	HANDLE m_hthDrawProgress, m_hevShutdown, m_hevDraw;
	static DWORD WINAPI _threadDrawProgress (LPVOID lp);
	CPen m_penQ;	
	
	CBrush m_brDone, m_brProgress;
	
	
	void DrawSectionProgress (CDC *dc, struct vmsSectionInfo* sect, int iSect, UINT64 uFileSize, bool bDontUseAlreadyDraw);
	CSize m_size;	
	vmsDownloadSmartPtr m_pActiveDownload;	
	
	void DrawProgress (CDC* dc, vmsDownloadSmartPtr dld);
	//{{AFX_MSG(CDownloads_Progress)
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
