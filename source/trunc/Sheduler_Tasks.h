/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_SHEDULER_TASKS_H__EBC2CAED_B113_4EEA_A9EB_B83BBC4B0645__INCLUDED_)
#define AFX_SHEDULER_TASKS_H__EBC2CAED_B113_4EEA_A9EB_B83BBC4B0645__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "fsScheduleMgr.h"
#include "listctrlex.h"
#include "fsODMenu.h"	

class CSheduler_Tasks : public CListCtrlEx
{
	friend class CShedulerWnd; 

public:
	CSheduler_Tasks();

public:

public:

	
	//{{AFX_VIRTUAL(CSheduler_Tasks)
	//}}AFX_VIRTUAL

public:
	
	void DeleteTaskFromList (fsSchedule* task);
	
	void UpdateAllTasks ();
	
	void ApplyLanguage();
	void ApplyLanguageToMenu (CMenu *menu);
	int OnUpdateToolBar (UINT nID);
	
	void UpdateTask (fsSchedule *task);
	
	void AddTask (fsSchedule* task);
	BOOL Create (CWnd *pParent);
	virtual ~CSheduler_Tasks();

	
protected:
	
	void OnForceUpdate();
	CImageList m_images;	
	CImageList m_selImages;	
	
	void CalcCoordsForCurSel();
	
	void UpdateTask (int iItem);
	fsODMenu m_odmenu;
	void UpdateMenu (CMenu* pMenu);
	
	int GetTaskImage(fsSchedule *task);
	void OnKeyDown(WORD wVK);
	CPoint m_rbPt;		
	void OnRClick ();
	
	
	int FindTask (fsSchedule *task);
	//{{AFX_MSG(CSheduler_Tasks)
	afx_msg void OnDblclk(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTasksDeletetask();
	afx_msg void OnCreatenewtask();
	afx_msg void OnTasksProperties();
	afx_msg void OnTasksDisable();
	afx_msg void OnTasksEnable();
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
