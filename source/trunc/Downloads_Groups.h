/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DOWNLOADS_GROUPS_H__DC760A3A_7E05_41EE_8E48_95B376BE8EB1__INCLUDED_)
#define AFX_DOWNLOADS_GROUPS_H__DC760A3A_7E05_41EE_8E48_95B376BE8EB1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "fsODMenu.h"	
#include "fsDldFilter.h"
#include "vmsDownloadsGroupsMgr.h"

class CDownloads_Groups : public CTreeCtrl
{
	friend class CDownloadsWnd;

public:
	CDownloads_Groups();

public:

public:

	
	//{{AFX_VIRTUAL(CDownloads_Groups)
	//}}AFX_VIRTUAL

public:
	
	
	void UpdateNumbersOfDownloadsInGroups();
	
	void OnGroupNameChanged (vmsDownloadsGroupSmartPtr pGroup);
	
	void OnNewGroupCreated (vmsDownloadsGroupSmartPtr pGroup);
	
	void SetGroupFilter (vmsDownloadsGroupSmartPtr pGroup);
	
	void UpdateDeletedIcon();
	
	void SetFilter_DeletedDownloads();
	
	void SetFilter_AllHistory();
	
	void SetFilter_AllDownloads();
	
	
	fsDldHistRecFilter* GetHistoryCurrentFilter();
	
	
	fsDldFilter* GetCurrentFilter ();
	
	void ApplyLanguage();
	
	
	void ApplyNotGroupFilterForDownload (vmsDownloadSmartPtr dld);
	
	
	class CDownloadsWnd *m_pWndDownloads;
	BOOL Create (CWnd* pParent);
	virtual ~CDownloads_Groups();

	
protected:
	
	HTREEITEM m_hContextMenuItem;
	
	BOOL IsGroupItem (HTREEITEM hItem);
	
	HTREEITEM InsertGroup (vmsDownloadsGroupSmartPtr pGroup, HTREEITEM hRoot);
	
	int FindGroupIndex (vmsDownloadsGroupSmartPtr pGroup);
	
	void InsertGroups_tree (PDLDS_GROUPS_TREE pRoot, HTREEITEM hRoot);
	
	
	
	void CustomizeHistoryFilter();
	
	void ApplyLanguageToMenu_History (CMenu* menu);
	void ShowHistoryContextMenu();
	
	void ApplyLanguageToMenu_Deleted (CMenu* menu);
	void ShowDeletedContextMenu();
	
	void InsertDeleted();
	
	void InsertHistory();
	
	
	
	void ShowGrpContextMenu(HTREEITEM hItem = NULL, BOOL bAutoDetect = TRUE);
	
	void ApplyLanguageToMenu (CMenu *menu);
	CImageList m_odmenuDImages;	
	CImageList m_odmenuImages;	
	fsODMenu m_odmenu;
	
	HTREEITEM m_hCompleted, m_hInProgress, m_hStopped, m_hScheduled;
	
	HTREEITEM m_hTasks;
	HTREEITEM m_hFilters;	
	
	struct _inc_GroupItem {
		fsDldGroupFilter *pGroupFilter;
		HTREEITEM hGroup;
		
		
		
		size_t cDownloads;
	};
	
	std::vector <fsDldFilter*> m_vStateFilters;
	
	std::vector <_inc_GroupItem> m_vGroups;
	
	
	size_t m_cTotalDownloads;
	fsDldFilter m_filterAll;	
	
	void InsertFilters();
	HTREEITEM m_hOther;	
	
	HTREEITEM m_hHistory, m_hToday, m_hYesterday, m_hLastWeek, m_hLastMonth, m_hHistCustom;
	
	fsDldHistRecFilter m_filterAllHist;
	fsDldHistRecFilter_Custom m_filterCustomHist;
	fsDldHistRecFilter_Yesterday m_filterYesterday;
	fsDldHistRecFilter_Today m_filterToday;
	fsDldHistRecFilter_DuringPeriod m_filterLastWeek;
	fsDldHistRecFilter_DuringPeriod m_filterLastMonth;
	fsDldTasksFilter m_filterTasks;

	HTREEITEM m_hDeleted;	
	int m_rbY;		
	int m_rbX; 
	HTREEITEM m_hAllGroups;	
	
	void InsertGroups ();
	CImageList m_images;	
	//{{AFX_MSG(CDownloads_Groups)
	afx_msg void OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnRclick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnGrpdelete();
	afx_msg void OnGrpproperties();
	afx_msg void OnGrpstartall();
	afx_msg void OnGrpstopall();
	afx_msg void OnGrpcreate();
	afx_msg void OnGrpdeleteall();
	afx_msg void OnGrpdeleteallsuccessful();
	afx_msg void OnOpengroupfolder();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	afx_msg void OnKeydown(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeletedClear();
	afx_msg void OnDeletedProperties();
	afx_msg void OnHistoryClear();
	afx_msg void OnHistorySettings();
	afx_msg void OnClick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSetGroupsRootFolder();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnGrpdeletealldeaddlds();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
