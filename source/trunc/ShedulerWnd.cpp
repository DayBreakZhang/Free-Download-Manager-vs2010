/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "ShedulerWnd.h"
#include "plugins.h"
#include "ScheduleSheet.h"
#include "plugincmds.h"
#include "DownloadsWnd.h"
#include "mfchelp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CShedulerWnd* _pwndScheduler;

extern CDownloadsWnd* _pwndDownloads;

CShedulerWnd::CShedulerWnd()
{
	m_mgr.SetEventFunc (_ScheduleMgrEventFunc, this);
	m_mgr.SetEventDescFunc (_ScheduleMgrEventDesc, this);
	m_wndLog.SetEvMgr (&m_evMgr);

	getPersistObjectChildren ()->addPersistObject (&m_mgr);
	getPersistObjectChildren ()->addPersistObject (&m_evMgr);
	m_bIsSchedulerMgrLoadedSuccessfully = false;
	m_bIsEventsMgrLoadedSuccessfully = false;
}

CShedulerWnd::~CShedulerWnd()
{

}

BEGIN_MESSAGE_MAP(CShedulerWnd, CWnd)
	//{{AFX_MSG_MAP(CShedulerWnd)
	ON_WM_DESTROY()
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_COMMAND(ID_TASKS_DELETETASK, OnTasksDeletetask)
	ON_COMMAND(ID_TASKS_DISABLE, OnTasksDisable)
	ON_COMMAND(ID_TASKS_ENABLE, OnTasksEnable)
	ON_COMMAND(ID_TASKS_PROPERTIES, OnTasksProperties)
	ON_COMMAND(ID_CREATENEWTASK, OnCreatenewtask)
	ON_WM_SETFOCUS()
	//}}AFX_MSG_MAP

	
	ON_MESSAGE (WM_WGP_SHUTDOWN, OnAppExit)
	ON_MESSAGE (WM_WGP_READYTOSHUTDOWN, OnAppQueryExit)
	ON_MESSAGE (WM_WGP_UPDATE_MENUMAIN, OnUpdateMenu)
	ON_MESSAGE (WM_WGP_UPDATE_MENUVIEW, OnUpdateMenuView)
	ON_MESSAGE (WM_WGP_UPDATE_CMDITEM, OnUpdateToolBar)
	ON_MESSAGE (WM_WGP_INSERT, OnInsert)
	
	ON_COMMAND(WGP_MENU_VIEWSMPLITEM_CMDSTART+0, OnShowLog)

	ON_COMMAND_RANGE(ID_TASKS_1, ID_TASKS_4, OnTasksListShowCol)
	ON_COMMAND_RANGE(ID_LOG_1, ID_LOG_3, OnLogShowCol)
	
	

END_MESSAGE_MAP()

HWND CShedulerWnd::Plugin_CreateMainWindow(HWND hParent)
{
	fsnew1 (_pwndScheduler, CShedulerWnd);

	_pwndScheduler->Create (CWnd::FromHandle (hParent));

	return _pwndScheduler->m_hWnd;
}

BOOL CShedulerWnd::Create(CWnd *pParent)
{
	CRect rc (0, 0, 50, 50);

	if (FALSE == CWnd::Create (AfxRegisterWndClass (0, NULL,
		NULL, NULL), NULL, WS_CHILD | WS_VISIBLE, rc, pParent, 0x16721))
		return FALSE;

	return TRUE;
}

void CShedulerWnd::OnDestroy() 
{
	CWnd::OnDestroy();
	
	SAFE_DELETE (_pwndScheduler);	
}

LRESULT CShedulerWnd::OnAppExit(WPARAM, LPARAM)
{
	SaveAll (0xffffffff);
	m_mgr.Stop ();
	return 0;
}

LRESULT CShedulerWnd::OnAppQueryExit(WPARAM, LPARAM)
{
	return 0;
}

int CShedulerWnd::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_bShowLog = _App.View_SchedulerLog ();
	
	if (FALSE == m_wndTasks.Create (this))
		return -1;

	if (FALSE == m_wndLog.Create (this))
		return -1;

	if (FALSE == m_wndSplitter.Create (AfxGetInstanceHandle (), m_hWnd, WST_HORIZONTAL))
		return -1;

	m_wndSplitter.SetWnd1 (m_wndTasks);
	m_wndSplitter.SetWnd2 (m_wndLog);
	m_wndSplitter.SetRatio (_App.View_SplitterRatio ("Scheduler_T_L"));

	LoadTasks ();

	_pwndDownloads->UpdateAllDownloads (); 

	ShowLog (m_bShowLog);
	
	return 0;
}

void CShedulerWnd::OnSize(UINT , int cx, int cy) 
{
	if (m_bShowLog)
		m_wndSplitter.ApplyRatio ();
	else
		m_wndTasks.MoveWindow (0, 0, cx, cy);
}

void CShedulerWnd::OnCreatenewtask() 
{
	CScheduleSheet sheet (LS (L_NEWTASK), this);
	
	
	fsScheduleEx schScheduleParam;
	fsSchedule& task = schScheduleParam.schTask;

	
	_App.Scheduler_LastTask_read (&task);

	sheet.Init  (&task);

    _DlgMgr.OnDoModal (&sheet);

	if (IDOK != sheet.DoModal ())
	{
		_DlgMgr.OnEndDialog (&sheet);
		return;
	}

    _DlgMgr.OnEndDialog (&sheet);

	_App.Scheduler_LastTask_save (&task);

	AddTask (&task);
}

void CShedulerWnd::_ScheduleMgrEventFunc(fsSchedule *task, fsScheduleMgrEvent ev, LPVOID lp)
{
	CShedulerWnd *pThis = (CShedulerWnd*) lp;

	switch (ev)
	{
		case SME_TASK_WILLBEDELETED:
			pThis->m_wndTasks.DeleteTaskFromList (task);
		break;

		default:
			pThis->m_wndTasks.UpdateTask (task);
	}
}

void CShedulerWnd::OnProperties(fsSchedule *task)
{
	CScheduleSheet sheet (LS (L_TASKPROP), this);
	
	sheet.Init  (task);

  	if (IDOK != _DlgMgr.DoModal (&sheet))
		return;

	if (sheet.IsNeedRecalculateStartTime ())
		m_mgr.CalculateStartTime (task);

	m_mgr.OnTaskUpdated (task);
}

void CShedulerWnd::LoadTasks()
{
	CString strFile = fsGetDataFilePath ("schedules.sav");

	if (GetFileAttributes (strFile) == DWORD (-1))
		return;

	HANDLE hFile = CreateFile (strFile, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
		return;

	DWORD dw = 0;
	DWORD dwRequiredSize = ::GetFileSize(hFile, NULL);
	if (dwRequiredSize <= 0) {
		CloseHandle (hFile);
		return;
	}

	std::auto_ptr<BYTE> pbtBufferGuard( new BYTE[dwRequiredSize] );
	LPBYTE pbtBuffer = pbtBufferGuard.get();
	if (pbtBuffer == 0) {
		CloseHandle (hFile);
		return;
	}
	memset(pbtBuffer, 0, dwRequiredSize);

	if (!ReadFile (hFile, pbtBuffer, dwRequiredSize, &dw, NULL) || dw != dwRequiredSize) {
		CloseHandle (hFile);
		return;
	}

	if (!loadFromStateBuffer(pbtBuffer, &dwRequiredSize, 0)) {
		CloseHandle (hFile);

		if (m_bIsSchedulerMgrLoadedSuccessfully && !m_bIsEventsMgrLoadedSuccessfully) {
			m_evMgr.clear();
			MessageBox (LS (L_CANTLOADSCHEDULERLOG), LS (L_ERR), MB_ICONERROR);
		}

		return;
	}

	CloseHandle (hFile);
	resetDirty();

	int cEvents = m_evMgr.GetEventCount ();
	for (int i = 0; i < cEvents; i++)
		m_wndLog.AddRecord (m_evMgr.GetEvent (i));

	
	
	

		

	
	

	
	
	
	

	
	

	

	
	
	
}

bool CShedulerWnd::loadObjectItselfFromStateBuffer(LPBYTE pb, LPDWORD pdwSize, DWORD dwVer)
{
	if (pdwSize)
		*pdwSize = 0;
	return true;
}

fsScheduleMgr* CShedulerWnd::GetMgr()
{
	return &m_mgr;
}

void CShedulerWnd::_ScheduleMgrEventDesc(LPCSTR pszEvent, fsScheduleMgrEventType enType, LPVOID lp)
{
	CShedulerWnd *pThis = (CShedulerWnd*) lp;

	fsDescEvent ev;
	
	switch (enType)
	{
		case SMET_S:
			ev.clrBg = CLR_RESPONSE_S;
			ev.clrText = RGB (0, 0, 0);
			ev.iImage = 2;
		break;

		case SMET_E:
			ev.clrBg = CLR_RESPONSE_E;
			ev.clrText = RGB (0, 0, 0);
			ev.iImage = 3;
		break;

		case SMET_INPROGRESS:
			ev.clrBg = CLR_INQUIRY;
			ev.clrText = RGB (0, 0, 0);
			ev.iImage = 0;
		break;
	}

	fsnew (ev.pszEvent, char, strlen (pszEvent) + 1);
	strcpy (ev.pszEvent, pszEvent);

	pThis->m_evMgr.add (&ev);
	pThis->m_wndLog.AddRecord (&ev);
}

void CShedulerWnd::AddTask(fsSchedule *task)
{
	m_mgr.CalculateStartTime (task);

	task->dwFlags |= SCHEDULE_ENABLED;

	int iTask = m_mgr.AddTask (task);

	m_wndTasks.AddTask (m_mgr.GetTask (iTask));
}

LRESULT CShedulerWnd::OnUpdateMenu(WPARAM, LPARAM lp)
{
	m_wndTasks.UpdateMenu (CMenu::FromHandle (*((HMENU*)lp)));
	return 0;
}

void CShedulerWnd::OnTasksDeletetask() 
{
	m_wndTasks.OnTasksDeletetask ();
}

void CShedulerWnd::OnTasksDisable() 
{
	m_wndTasks.OnTasksDisable ();	
}

void CShedulerWnd::OnTasksEnable() 
{
	m_wndTasks.OnTasksEnable ();	
}

void CShedulerWnd::OnTasksProperties() 
{
	m_wndTasks.OnTasksProperties ();	
}

void CShedulerWnd::UpdateTask(fsSchedule *task)
{
	m_wndTasks.UpdateTask (task);
}

void CShedulerWnd::SaveAll(DWORD dwWhat)
{
	if (dwWhat & 1)
	{
		SaveSchedules ();
	}

	if (dwWhat & 2)
	{
		_App.View_SplitterRatio ("Scheduler_T_L", m_wndSplitter.GetRatio ());
		m_wndTasks.SaveState ("SchedulerTasks");
		m_wndLog.SaveState ("SchedulerLog");
	}
}

void CShedulerWnd::Plugin_GetToolBarInfo(wgTButtonInfo **ppButtons, int *pcButtons)
{
	static wgTButtonInfo btns [] = 
	{
		wgTButtonInfo (ID_CREATENEWTASK, TBSTYLE_BUTTON, ""),
		wgTButtonInfo (ID_TASKS_PROPERTIES, TBSTYLE_BUTTON, ""),
	};

	btns [0].pszToolTip = LS (L_NEWTASK);
	btns [1].pszToolTip = LS (L_TASKPROP);

	*ppButtons = btns;
	*pcButtons = sizeof (btns) / sizeof (wgTButtonInfo);
}

LRESULT  CShedulerWnd::OnUpdateToolBar(WPARAM wp, LPARAM)
{
	return m_wndTasks.OnUpdateToolBar (wp);
}

void CShedulerWnd::Plugin_GetMenuImages(fsSetImage **ppImages, int *pcImages)
{
	static fsSetImage images [] = 
	{
		fsSetImage (ID_CREATENEWTASK, 0),
		fsSetImage (ID_TASKS_PROPERTIES, 1),
		fsSetImage (ID_TASKS_DELETETASK, 2)
	};

	*ppImages = images;
	*pcImages = sizeof (images) / sizeof (fsSetImage);
}

BOOL CShedulerWnd::HangupWhenDone(int* ppos)
{
	int pos = -1;
	bool bEn = false;

	do {
		pos = m_mgr.FindTask (WTS_HANGUP, pos);
		if (pos != -1 && m_mgr.GetTask (pos)->hts.enType == HTS_WHENDONE)
			break;
	}
	while (pos != -1);

	if (pos != -1)
		bEn = (m_mgr.GetTask (pos)->dwFlags & SCHEDULE_ENABLED) != 0;

	if (ppos)
		*ppos = pos;

	return pos != -1 && bEn;
}

void CShedulerWnd::HangupWhenDone(BOOL bUse)
{
	int pos;
	if (!bUse == !HangupWhenDone (&pos))	
		return;

	if (bUse)
	{
		if (pos != -1) {
			m_mgr.GetTask (pos)->dwFlags |= SCHEDULE_ENABLED;
			m_mgr.setDirtyFlagForTask(pos);
			m_wndTasks.UpdateTask (pos);
			return;
		}

		
		fsScheduleEx schScheduleParam;
		fsSchedule& task = schScheduleParam.schTask;
		task.dwFlags = SCHEDULE_ENABLED;
		if (_App.WD_DisableAfterExec ())
			task.dwFlags |= SCHEDULE_AUTODIS;
		task.uWaitForConfirmation = _App.ConfTimeout_Hangup ();
		task.wts.enType = WTS_HANGUP;
		task.wts.pszHangupConnection = NULL;
		task.hts.uTimeNothingReceived = 30;
		task.hts.enType = HTS_WHENDONE;
		m_mgr.AddTask (&task);
		m_wndTasks.AddTask (m_mgr.GetTask (m_mgr.GetTaskCount () - 1));
	}
	else
	{
		
		m_mgr.GetTask (pos)->dwFlags &= ~SCHEDULE_ENABLED;
		m_mgr.setDirtyFlagForTask(pos);
		m_wndTasks.UpdateTask (pos);
	}
}

BOOL CShedulerWnd::ExitWhenDone(int* ppos)
{
	int pos = -1;
	bool bEn = false;

	do {
		pos = m_mgr.FindTask (WTS_EXIT, pos);
		if (pos != -1 && m_mgr.GetTask (pos)->hts.enType == HTS_WHENDONE)
			break;
	}
	while (pos != -1);

	if (pos != -1)
		bEn = (m_mgr.GetTask (pos)->dwFlags & SCHEDULE_ENABLED) != 0;

	if (ppos)
		*ppos = pos;

	return pos != -1 && bEn;
}

void CShedulerWnd::ExitWhenDone(BOOL bUse)
{
	int pos;
	if (!bUse == !ExitWhenDone (&pos))	
		return;

	if (bUse)
	{
		if (pos != -1) {
			m_mgr.GetTask (pos)->dwFlags |= SCHEDULE_ENABLED;
			m_mgr.setDirtyFlagForTask(pos);
			m_wndTasks.UpdateTask (pos);
			return;
		}

		
		fsScheduleEx schScheduleParam;
		fsSchedule& task = schScheduleParam.schTask;
		task.dwFlags = SCHEDULE_ENABLED;
		if (_App.WD_DisableAfterExec ())
			task.dwFlags |= SCHEDULE_AUTODIS;
		task.uWaitForConfirmation = _App.ConfTimeout_Exit ();
		task.wts.enType = WTS_EXIT;
		task.hts.uTimeNothingReceived = 30;
		task.hts.enType = HTS_WHENDONE;
		m_mgr.AddTask (&task);
		m_wndTasks.AddTask (m_mgr.GetTask (m_mgr.GetTaskCount () - 1));
	}
	else
	{
		
		m_mgr.GetTask (pos)->dwFlags &= ~SCHEDULE_ENABLED;
		m_mgr.setDirtyFlagForTask(pos);
		m_wndTasks.UpdateTask (pos);
	}
}

BOOL CShedulerWnd::TurnoffWhenDone(fsShutdownType , int* ppos)
{
	

	int pos = -1;
	bool bEn = false;

	do {
		pos = m_mgr.FindTask (WTS_SHUTDOWN, pos);
		if (pos != -1 && m_mgr.GetTask (pos)->hts.enType == HTS_WHENDONE)
			break;
	}
	while (pos != -1);

	if (pos != -1)
		bEn = (m_mgr.GetTask (pos)->dwFlags & SCHEDULE_ENABLED) != 0;

	if (ppos)
		*ppos = pos;

	return pos != -1 && bEn;
}

void CShedulerWnd::TurnoffWhenDone(fsShutdownType enST, BOOL bUse)
{
	

	int pos;
	if (!bUse == !TurnoffWhenDone (enST, &pos))
		return;

	if (bUse)
	{
		if (pos != -1) {
			fsSchedule* task = m_mgr.GetTask (pos);
			task->wts.shutdown.enShutdown = enST;
			task->dwFlags |= SCHEDULE_ENABLED;
			m_mgr.setDirtyFlagForTask(pos);
			m_wndTasks.UpdateTask (pos);
			return;
		}

		
		fsScheduleEx schScheduleParam;
		fsSchedule& task = schScheduleParam.schTask;
		task.dwFlags = SCHEDULE_ENABLED;
		if (_App.WD_DisableAfterExec ())
			task.dwFlags |= SCHEDULE_AUTODIS;
		task.uWaitForConfirmation = _App.ConfTimeout_Shutdown ();
		task.wts.enType = WTS_SHUTDOWN;
		task.wts.shutdown.enShutdown = enST;
		task.wts.shutdown.bForce = FALSE;
		task.hts.uTimeNothingReceived = 30;

		task.hts.enType = HTS_WHENDONE;
		m_mgr.AddTask (&task);
		m_wndTasks.AddTask (m_mgr.GetTask (m_mgr.GetTaskCount () - 1));
	}
	else
	{
		
		m_mgr.GetTask (pos)->dwFlags &= ~SCHEDULE_ENABLED;
		m_mgr.setDirtyFlagForTask(pos);
		m_wndTasks.UpdateTask (pos);
	}
}

void CShedulerWnd::Plugin_GetMenuViewItems(wgMenuViewItem **ppItems, int * cItems)
{
	static wgMenuViewItem aItems [] = {
		wgMenuViewItem ("", &_pwndScheduler->m_bShowLog),
	};

	aItems [0].pszName = LS (L_SCHEDULERLOG);

	*ppItems = aItems;
	*cItems = sizeof (aItems) / sizeof (wgMenuViewItem);
}

void CShedulerWnd::OnShowLog()
{
	ShowLog (m_bShowLog == FALSE);
}

void CShedulerWnd::ShowLog(BOOL bShow)
{
	UINT nShow = bShow ? SW_SHOW : SW_HIDE;
	m_wndLog.ShowWindow (nShow);
	::ShowWindow (m_wndSplitter.m_wndSplitter, nShow);

	m_bShowLog = bShow;
	_App.View_SchedulerLog (bShow);

	RECT rc;
	GetClientRect (&rc);
	OnSize (0, rc.right, rc.bottom);
}

void CShedulerWnd::Plugin_GetPluginNames(LPCSTR *ppszLong, LPCSTR *ppszShort)
{
	static CString strName;
	strName = LSNP (L_SCHEDULER);
	*ppszLong = *ppszShort = strName;
}

BOOL CShedulerWnd::SaveSchedules()
{
	if (!isDirty())
		return TRUE;

	DWORD dwRequiredSize = 0;
	DWORD dw = 0;

	CString strFile = fsGetDataFilePath ("schedules.sav");

	HANDLE hFile = CreateFile (strFile, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS,
		FILE_ATTRIBUTE_HIDDEN, NULL);

	getStateBuffer(0, &dwRequiredSize, false);

	if (dwRequiredSize == 0) {
		CloseHandle (hFile);
		return FALSE;
	}

	std::auto_ptr<BYTE> apbtBufferGuard( new BYTE[dwRequiredSize] );
	LPBYTE pbtBuffer = apbtBufferGuard.get();
	if (pbtBuffer == 0) {
		CloseHandle (hFile);
		return FALSE;
	}
	memset(pbtBuffer, 0, dwRequiredSize);

	getStateBuffer(pbtBuffer, &dwRequiredSize, true);

	if (FALSE == WriteFile (hFile, pbtBuffer, dwRequiredSize, &dw, NULL) || dw != dwRequiredSize) {
		CloseHandle (hFile);
		return FALSE;
	}
	CloseHandle (hFile);
	onStateSavedSuccessfully();

	return TRUE;

	
}

void CShedulerWnd::getObjectItselfStateBuffer(LPBYTE pb, LPDWORD pdwSize, bool bSaveToStorage)
{
	if (pdwSize)
		*pdwSize = 0;
}

void CShedulerWnd::OnSetFocus(CWnd* pOldWnd) 
{
	CWnd::OnSetFocus(pOldWnd);
	m_wndTasks.SetFocus ();	
}

void CShedulerWnd::Plugin_SetLanguage(wgLanguage, HMENU hMenuMain, HMENU hMenuView)
{
	CMenu *menu = CMenu::FromHandle (hMenuMain);
	_pwndScheduler->m_wndTasks.ApplyLanguageToMenu (menu);
	_pwndScheduler->m_wndTasks.ApplyLanguage ();
	_pwndScheduler->m_wndLog.ApplyLanguage ();
	_pwndScheduler->ApplyLanguageToMenuView (CMenu::FromHandle (hMenuView));
}

void CShedulerWnd::ApplyLanguageToMenuView(CMenu *menu)
{
	menu->ModifyMenu (0, MF_BYPOSITION | MF_STRING, 0, LS (L_LISTOFTASKS));
	menu->ModifyMenu (1, MF_BYPOSITION | MF_STRING, 0, LS (L_SCHEDULERLOG));

	UINT aCmds [] = {ID_TASKS_1, ID_TASKS_2, ID_TASKS_3, ID_TASKS_4, ID_LOG_1, ID_LOG_2, ID_LOG_3 };
	LPCSTR apszCmds [] = {LS (L_WTS), LS (L_HTS), LS (L_NEXTSTART), LS (L_LASTSTART), LS (L_TIME),
		LS (L_DATE), LS (L_INFORMATION)};
	
	for (int i = 0; i < sizeof (aCmds) / sizeof (UINT); i++)
		menu->ModifyMenu (aCmds [i], MF_BYCOMMAND|MF_STRING, aCmds [i], apszCmds [i]);
}

LRESULT CShedulerWnd::OnUpdateMenuView(WPARAM, LPARAM lp)
{
	HMENU* pMenus = (HMENU*) lp;
	UpdateTasksListColMenu (CMenu::FromHandle (pMenus [0]));
	UpdateLogColMenu (CMenu::FromHandle (pMenus [1]));
	return 0;
}

void CShedulerWnd::UpdateTasksListColMenu(CMenu *menu)
{
	BOOL bEn = m_wndTasks.GetHeaderCtrl ()->GetItemCount () > 1;
	for (int i = 0; i < 4; i++)
	{
		if (m_wndTasks.IsColumnShown (i))
		{
			menu->CheckMenuItem (ID_TASKS_1+i, MF_CHECKED);
			if (bEn == FALSE)
				menu->EnableMenuItem (ID_TASKS_1+i, MF_GRAYED);
		}
	}
}

void CShedulerWnd::UpdateLogColMenu(CMenu *menu)
{
	BOOL bEn = m_wndLog.GetHeaderCtrl ()->GetItemCount () > 1;
	for (int i = 0; i < 3; i++)
	{
		if (m_wndLog.IsColumnShown (i))
		{
			menu->CheckMenuItem (ID_LOG_1+i, MF_CHECKED);
			if (bEn == FALSE)
				menu->EnableMenuItem (ID_LOG_1+i, MF_GRAYED);
		}
	}
}

void CShedulerWnd::OnTasksListShowCol(UINT uCmd)
{
	int iCol = uCmd - ID_TASKS_1;
	m_wndTasks.ChangeColumnVisibility (iCol);
}

void CShedulerWnd::OnLogShowCol(UINT uCmd)
{
	int iCol = uCmd - ID_LOG_1;
	m_wndLog.ChangeColumnVisibility (iCol);
}

LRESULT CShedulerWnd::OnInsert(WPARAM, LPARAM)
{
	m_wndTasks.OnCreatenewtask ();
	return 0;
}

HMENU CShedulerWnd::Plugin_GetMainMenu()
{
	return LoadMenu (AfxGetInstanceHandle (), MAKEINTRESOURCE (IDM_TASKS));
}

HMENU CShedulerWnd::Plugin_GetViewMenu()
{
	return LoadMenu (AfxGetInstanceHandle (), MAKEINTRESOURCE (IDM_TASKS_VIEW));
}

void CShedulerWnd::onChildObjectLoadFinished (vmsPersistObject *pObject, bool bResult) 
{
	if (!bResult)
		return;

	if (pObject == &m_mgr)
	{
		
		if (_App.App_2_0_SchedulerFixPerformed () == FALSE)
		{
			_App.App_2_0_SchedulerFixPerformed (TRUE);

			int pos;

			while (-1 != (pos = m_mgr.FindTask (WTS_SHUTDOWN)))
				m_mgr.DeleteTask (m_mgr.GetTask (pos));

			while (-1 != (pos = m_mgr.FindTask (WTS_EXIT)))
				m_mgr.DeleteTask (m_mgr.GetTask (pos));

			while (-1 != (pos = m_mgr.FindTask (WTS_HANGUP)))
				m_mgr.DeleteTask (m_mgr.GetTask (pos));
		}
		

		int cTasks = m_mgr.GetTaskCount ();
		for (int i = 0; i < cTasks; i++)
			m_wndTasks.AddTask (m_mgr.GetTask (i));

		m_bIsSchedulerMgrLoadedSuccessfully = true;
	}

	else if (pObject == &m_evMgr)
	{
		m_bIsEventsMgrLoadedSuccessfully = true;
	}
}