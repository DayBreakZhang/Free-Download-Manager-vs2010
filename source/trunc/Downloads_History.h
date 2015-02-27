/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DOWNLOADS_HISTORY_H__DED743BB_CC73_479A_937C_C8D60FCFEF03__INCLUDED_)
#define AFX_DOWNLOADS_HISTORY_H__DED743BB_CC73_479A_937C_C8D60FCFEF03__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "ListCtrlEx.h"
#include "fsMutex.h"	
#include "fsODMenu.h"	

class CDownloads_History : public CListCtrlEx  
{
public:
	fsDLHistoryRecord* get_SelectedRecord();
	
	void SelectRecord (fsDLHistoryRecord* rec);
	
	static int GetRecordImage (fsDLHistoryRecord* rec);
	
	void ApplyFilter(class fsDldHistRecFilter*);
	
	void DeleteAllRecords();
	
	void DeleteRecord (fsDLHistoryRecord* rec);
	
	void AddRecord (fsDLHistoryRecord* rec);

	void ApplyLanguage();
	BOOL Create(CWnd *pParent);
	CDownloads_History();
	virtual ~CDownloads_History();

protected:
	void OnKeyDown (WORD wVK);
	static int CALLBACK _sortFunc(LPARAM item1, LPARAM item2, LPARAM lp);
	void Sort();
	void OnSortModeChanged();
	fsODMenu m_odmenu;
	void ApplyLanguageToMenu (CMenu* menu);
	void OnRClick();
	
	static DWORD WINAPI _threadApplyFilter (LPVOID lp);
	void ApplyFilter_imp (fsDldHistRecFilter* f, int *piProgress = NULL);
	fsDownloadsHistoryMgr* m_mgr;
	fsMutex m_mxAddDel;	
	void OnForceUpdate();
	int FindRecord (fsDLHistoryRecord* rec);
	
	void UpdateRecord (int iItem);
	CImageList m_images, m_selimages;

	//{{AFX_MSG(CDownloads_History)
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	afx_msg void OnUrltoclipboard();
	afx_msg void OnLaunch();
	afx_msg void OnOpenfolder();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnHstitemDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif 
