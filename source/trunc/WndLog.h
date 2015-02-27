/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_WND_LOG_H__E6B6D3C4_EFED_41F6_8C91_0CB7C3FAFB19__INCLUDED_)
#define AFX_WND_LOG_H__E6B6D3C4_EFED_41F6_8C91_0CB7C3FAFB19__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "ListCtrlEx.h"
#include "fsODMenu.h"	
#include "fsEventsMgr.h"

class CWndLog : public CListCtrlEx
{

public:
	CWndLog();

public:

public:

	
	//{{AFX_VIRTUAL(CWndLog)
	//}}AFX_VIRTUAL

public:
	
	void SetEvMgr (fsEventsMgr* mgr);
	
	void ApplyLanguageToMenu (CMenu *menu);
	void ApplyLanguage();
	
	void AddRecord (struct fsDescEvent *ev);

	BOOL Create (CWnd *pParent);
	virtual ~CWndLog();

	
protected:
	fsEventsMgr* m_pEvMgr;
	
	void OnForceUpdate();
	
	void CalcCoordsForCurSel();
	void OnKeyDown (WORD wVK);
	fsODMenu m_odmenu;
	CPoint m_rbPt;
	void OnRClick();
	BOOL m_bAutoScroll;
	CImageList m_images;	
	//{{AFX_MSG(CWndLog)
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnAutoscroll();
	afx_msg void OnClear();
	afx_msg void OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnCopyToCb();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
