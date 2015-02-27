/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DOWNLOADS_LOG_H__B5D1F47C_CB4B_4A86_9A49_10AEB5348072__INCLUDED_)
#define AFX_DOWNLOADS_LOG_H__B5D1F47C_CB4B_4A86_9A49_10AEB5348072__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "ListCtrlEx.h"
#include "fsODMenu.h"	

class CDownloads_Log : public CListCtrlEx
{

public:
	CDownloads_Log();

public:

public:

	
	//{{AFX_VIRTUAL(CDownloads_Log)
	//}}AFX_VIRTUAL

public:
	
	void ApplyLanguage();
	
	void SetActiveDownload (vmsDownloadSmartPtr dld);
	
	void AddRecord (struct fsDownloadEvents *event);
	BOOL Create (CWnd *pParent);
	virtual ~CDownloads_Log();

	
protected:
	
	void OnForceUpdate();
	
	
	void CalcCoordsForCurSel();
	void OnKeyDown (WORD wVK);
	void ApplyLanguageToMenu (CMenu* menu);
	fsODMenu m_odmenu;
	BOOL m_bAutoScroll;	
	CPoint m_rbPt;		
	vmsDownloadSmartPtr m_pActiveDownload;	
	void OnRClick();
	CImageList m_images;
	//{{AFX_MSG(CDownloads_Log)
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnAutoscroll();
	afx_msg void OnClear();
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	afx_msg void OnCopyToCb();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
