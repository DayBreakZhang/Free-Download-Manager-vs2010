/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_SHEDULERWND_H__6C83160D_AC85_4A7F_A1A4_78EF69C3E03D__INCLUDED_)
#define AFX_SHEDULERWND_H__6C83160D_AC85_4A7F_A1A4_78EF69C3E03D__INCLUDED_

#include "Sheduler_Tasks.h"	
#include "Scheduler_Log.h"	
#include "WndSplitter.h"	
#include "fsScheduleMgr.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

#include "fsEventsMgr.h"
#include "plugins.h"
#include "vmsPersistObject.h"

class CShedulerWnd : public CWnd, public vmsPersistObject
{
	friend class CScheduler_Log; 

public:
	CShedulerWnd();

public:

public:

	
	//{{AFX_VIRTUAL(CShedulerWnd)
	//}}AFX_VIRTUAL

public:
	static HMENU Plugin_GetViewMenu();
	static HMENU Plugin_GetMainMenu();
	
	static void Plugin_SetLanguage (wgLanguage, HMENU hMenuMain, HMENU);
	static void Plugin_GetPluginNames(LPCSTR *ppszLong, LPCSTR *ppszShort);
	static void Plugin_GetMenuViewItems(wgMenuViewItem **ppItems, int *cItems);
	static void Plugin_GetMenuImages(fsSetImage **ppImages, int *pcImages);
	static void Plugin_GetToolBarInfo(wgTButtonInfo **ppButtons, int *pcButtons);
	static HWND Plugin_CreateMainWindow (HWND hParent);
	
	
	BOOL SaveSchedules();
	
	void TurnoffWhenDone (fsShutdownType enST, BOOL bUse);
	
	
	
	
	
	BOOL TurnoffWhenDone(fsShutdownType enST, int* ppos = NULL);
	
	void HangupWhenDone (BOOL bUse);
	BOOL HangupWhenDone(int* ppos = NULL);
	
	void ExitWhenDone (BOOL bUse);
	BOOL ExitWhenDone(int* ppos = NULL);
	
	void SaveAll(DWORD dwWhat);
	
	void UpdateTask (fsSchedule* task);
	
	void AddTask (fsSchedule *task);
	
	afx_msg void OnCreatenewtask();
	fsScheduleMgr* GetMgr();
	
	void OnProperties (fsSchedule *task);
	
	static void _ScheduleMgrEventFunc (fsSchedule *task, fsScheduleMgrEvent ev, LPVOID lp);
	CSheduler_Tasks m_wndTasks;
	BOOL Create (CWnd *pParent);
	void getObjectItselfStateBuffer(LPBYTE pb, LPDWORD pdwSize, bool bSaveToStorage);
	bool loadObjectItselfFromStateBuffer(LPBYTE pb, LPDWORD pdwSize, DWORD dwVer);
	virtual ~CShedulerWnd();

protected:
	virtual void onChildObjectLoadFinished (vmsPersistObject *pObject, bool bResult);

	
protected:
	
	afx_msg LRESULT OnInsert(WPARAM, LPARAM);
	afx_msg void OnLogShowCol (UINT uCmd);
	afx_msg void OnTasksListShowCol (UINT uCmd);
	void UpdateLogColMenu (CMenu* menu);
	void UpdateTasksListColMenu (CMenu* menu);
	afx_msg LRESULT OnUpdateMenuView (WPARAM, LPARAM lp);
	void ShowLog (BOOL bShow);
	void ApplyLanguageToMenuView (CMenu *menu);
	afx_msg void OnShowLog();
	LRESULT afx_msg OnUpdateToolBar (WPARAM wp, LPARAM);
	afx_msg LRESULT OnUpdateMenu (WPARAM, LPARAM lp);
	
	BOOL m_bShowLog;			
	fsEventsMgr m_evMgr;
	
	static void _ScheduleMgrEventDesc (LPCSTR pszEvent, fsScheduleMgrEventType enType, LPVOID lp);
	
	void LoadTasks();

	fsScheduleMgr m_mgr;
	CWndSplitter m_wndSplitter;
	CScheduler_Log m_wndLog;
	afx_msg LRESULT OnAppQueryExit (WPARAM, LPARAM);
	afx_msg LRESULT OnAppExit (WPARAM, LPARAM);
	//{{AFX_MSG(CShedulerWnd)
	afx_msg void OnDestroy();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnTasksDeletetask();
	afx_msg void OnTasksDisable();
	afx_msg void OnTasksEnable();
	afx_msg void OnTasksProperties();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	bool m_bIsSchedulerMgrLoadedSuccessfully;
	bool m_bIsEventsMgrLoadedSuccessfully;
};

//{{AFX_INSERT_LOCATION}}

#endif 
