/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FVDOWNLOADS_TASKS_H__74369AAA_3E4B_4BEE_8F38_D72D0C9EF779__INCLUDED_)
#define AFX_FVDOWNLOADS_TASKS_H__74369AAA_3E4B_4BEE_8F38_D72D0C9EF779__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "ListCtrlEx.h"
#include "fsDownload.h"	
#include "fsODMenu.h"	

class CFVDownloads_Tasks : public CListCtrlEx
{
	friend class CFlashVideoDownloadsWnd;

public:
	CFVDownloads_Tasks();

public:

public:

	
	//{{AFX_VIRTUAL(CFVDownloads_Tasks)
	//}}AFX_VIRTUAL

public:
	void SaveState();
	int OnUpdateToolBar(UINT nID);
	void ShowSelectedDldsProperties();
	int FindIndex (vmsDownloadSmartPtr dld);
	void WillBeDeleted (vmsDownloadSmartPtr dld);
	void UpdateDownload (vmsDownloadSmartPtr dld);
	void GetSelectedDownloads (DLDS_LIST_REF v);
	void ApplyLanguageToMenu (CMenu* menu);
	void UpdateMenu(CMenu *pPopup);
	void ApplyLanguage();
	void AddDownload (vmsDownloadSmartPtr dld, BOOL bPlaceToTop);
	BOOL Create (CWnd* pwndParent);
	virtual ~CFVDownloads_Tasks();

	
protected:
	void OnItemChanged(NM_LISTVIEW *pLV);
	void OnClick();
	void UpdateActiveDownload(int adjSelected);
	vmsDownloadSmartPtr m_pActiveDownload;
	CPoint m_rbPt;
	void CalcCoordsForCurSel();
	void CallSelectedDownload(BOOL bPropertiesInsteadOfPass);
	void OnKeyDown(WORD wVK);
	void DeleteSelected(BOOL bDontConfirmFileDeleting);
	fsODMenu m_odmenu;
	void OnRClick();
	DLDS_LIST m_vDlds;
	CImageList m_images, m_selimages;
	//{{AFX_MSG(CFVDownloads_Tasks)
	afx_msg void OnGetdispinfo(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	afx_msg void OnFvdldCreate();
	afx_msg void OnFvdldLaunch();
	afx_msg void OnFvdldPasstodlds();
	afx_msg void OnFvdldStart();
	afx_msg void OnFvdldStop();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnFvdldAutostart();
	afx_msg void OnFvdldDelete();
	afx_msg void OnFvdldOpenfolder();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnFvdldProperties();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnFvdldConvert();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
