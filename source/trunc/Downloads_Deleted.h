/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DOWNLOADS_DELETED_H__628BD07F_C1F5_411F_84BA_9F7E2CCB24D0__INCLUDED_)
#define AFX_DOWNLOADS_DELETED_H__628BD07F_C1F5_411F_84BA_9F7E2CCB24D0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "ListCtrlEx.h"
#include "fsODMenu.h"	

class CDownloads_Deleted : public CListCtrlEx  
{
public:
	
	void SelectDownload (vmsDownloadSmartPtr dld);
	
	static int GetDownloadImage (vmsDownloadSmartPtr dld);
	
	void RemoveAll();
	
	void RemoveDownload (vmsDownloadSmartPtr dld);
	
	void AddDownload (vmsDownloadSmartPtr dld);
	void ApplyLanguage();
	BOOL Create(CWnd *pParent);
	CDownloads_Deleted();
	virtual ~CDownloads_Deleted();

protected:
	static int CALLBACK _sortFunc(LPARAM item1, LPARAM item2, LPARAM lp);
	
	void Sort();
	void OnSortModeChanged();
	void OnForceUpdate();
	void OnKeyDown (WORD wVK);
	fsODMenu m_odmenu;
	void ApplyLanguageToMenu (CMenu* menu);
	void OnRClick();
	
	int FindDownload (vmsDownloadSmartPtr dld);
	
	void UpdateDownload (int iItem);
	CImageList m_images, m_selimages;

	//{{AFX_MSG(CDownloads_Deleted)
	afx_msg void OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnDeletedDelete();
	afx_msg void OnDeletedRestore();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

#endif 
