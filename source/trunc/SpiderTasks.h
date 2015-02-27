/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_SPIDERTASKS_H__0BDBE4EE_5A5A_4AC0_9FD6_A3CFA87DA53A__INCLUDED_)
#define AFX_SPIDERTASKS_H__0BDBE4EE_5A5A_4AC0_9FD6_A3CFA87DA53A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "ListCtrlEx.h"

#include "fsWebPageDownloader.h"
#include "fsODMenu.h"	

class CSpiderTasks : public CListCtrlEx
{
	friend class CSpiderWnd;

public:
	CSpiderTasks();

public:

public:

	
	//{{AFX_VIRTUAL(CSpiderTasks)
	//}}AFX_VIRTUAL

public:
	
	
	void CallSelectedPage();
	
	void UpdateIcons();
	
	
	void ApplyLanguage();
	void ApplyLanguageToMenu (CMenu* pMenu);

	
	void DeleteWebPage (fsWebPageDownloader *wp);
	
	int GetWebPageImage (fsWebPageDownloader *wpd);
	
	
	int FindWebPage (fsWebPageDownloader* wpd);
	
	void UpdateWebPage (fsWebPageDownloader* wpd);
	void UpdateWebPage (int iItem);
	
	void AddWebPage (fsWebPageDownloader *wpd);

	int UpdateToolBar (UINT nID);
	void UpdateMenu (CMenu *pMenu);

	BOOL Create (CWnd* pParent);
	virtual ~CSpiderTasks();

	
protected:
	
	void OnForceUpdate();
	
	void CalcCoordsForCurSel();
	void OnKeyDown (WORD wVK);
	void OnDeleteAllItems();
	void OnDeleteItem (NM_LISTVIEW *pNM);
	void OnClick();
	
	
	void UpdateActiveWPD (int adj = 0);

	
	CImageList m_images;	
	CImageList m_selimages;

	fsODMenu m_odmenu;
	POINT m_rbPt;
	void OnRClick();
	
	//{{AFX_MSG(CSpiderTasks)
	afx_msg void OnSpiderDl();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnSpiderStopdl();
	afx_msg void OnSpiderStartdl();
	afx_msg void OnSpiderStartautomatically();
	afx_msg void OnSpiderSettings();
	afx_msg void OnSpiderSchedule();
	afx_msg void OnSpiderOpenfolder();
	afx_msg void OnSpiderDelete();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnSpiderOpenpage();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
private:
	
	BOOL m_bAutoStart;
};

//{{AFX_INSERT_LOCATION}}

#endif 
