/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_TORRENTS_TASKS_H__3E8AF1A7_ED59_4D0F_8AE0_83351D479065__INCLUDED_)
#define AFX_TORRENTS_TASKS_H__3E8AF1A7_ED59_4D0F_8AE0_83351D479065__INCLUDED_

#include "fsDownload.h"	
#include "fsODMenu.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

class CTorrents_Tasks : public CListCtrlEx
{
	friend class CTorrentsWnd;

public:
	CTorrents_Tasks();

public:

public:

	
	//{{AFX_VIRTUAL(CTorrents_Tasks)
	//}}AFX_VIRTUAL

public:
	vmsDownloadSmartPtr getActiveDownload();
	int OnUpdateToolBar(UINT nID);
	void SaveState();
	void CallSelectedDownload(BOOL bPropertiesInsteadOfPass);
	void WillBeDeleted(vmsDownloadSmartPtr dld);
	void UpdateDownload(vmsDownloadSmartPtr dld);
	void ApplyLanguage();
	void UpdateMenu(CMenu *pPopup);
	void AddDownload(vmsDownloadSmartPtr dld, BOOL bPlaceToTop);
	void DeleteAllItems ();
	BOOL Create (CWnd *pwndParent);
	void ApplyLanguageToMenu(CMenu *menu);
	virtual ~CTorrents_Tasks();

	
protected:
	fsODMenu m_odmenu;
	void OnRClick();
	CPoint m_rbPt;
	void ShowSelectedDldsProperties();
	void CalcCoordsForCurSel();
	void GetSelectedDownloads(DLDS_LIST_REF v);
	void DeleteSelected(BOOL bDontConfirmFileDeleting);
	void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	void OnKeyDown(WORD wVK);
	void OnClick();
	vmsDownloadSmartPtr m_pActiveDownload;
	void UpdateActiveDownload(int adjSelected);
	void OnItemChanged(NM_LISTVIEW *pLV);
	int FindIndex(vmsDownloadSmartPtr dld);
	int SubItemToDlSubItem (int nIndex);
	DLDS_LIST m_vDlds;
	CImageList m_images, m_selimages;
	//{{AFX_MSG(CTorrents_Tasks)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnGetdispinfo (NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBtdldAddfromfile();
	afx_msg void OnBtdldAddfromurl();
	afx_msg void OnBtdldAutostart();
	afx_msg void OnBtdldCreatenewtorrent();
	afx_msg void OnBtdldDelete();
	afx_msg void OnBtdldLaunch();
	afx_msg void OnBtdldOpenfolder();
	afx_msg void OnBtdldPasstodlds();
	afx_msg void OnBtdldProperties();
	afx_msg void OnBtdldStart();
	afx_msg void OnBtdldStop();
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
