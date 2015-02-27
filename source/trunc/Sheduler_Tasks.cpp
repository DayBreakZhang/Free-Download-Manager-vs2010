/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Sheduler_Tasks.h"
#include "ShedulerWnd.h"
#include "plugincmds.h"
#include "DownloadsWnd.h"
#include "MainFrm.h"
#include "SpiderWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CShedulerWnd* _pwndScheduler;
extern CDownloadsWnd* _pwndDownloads;
extern CSpiderWnd* _pwndSpider;

CSheduler_Tasks::CSheduler_Tasks()
{
}

CSheduler_Tasks::~CSheduler_Tasks()
{
}

BEGIN_MESSAGE_MAP(CSheduler_Tasks, CListCtrlEx)
	//{{AFX_MSG_MAP(CSheduler_Tasks)
	ON_NOTIFY_REFLECT(NM_DBLCLK, OnDblclk)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_TASKS_DELETETASK, OnTasksDeletetask)
	ON_COMMAND(ID_CREATENEWTASK, OnCreatenewtask)
	ON_COMMAND(ID_TASKS_PROPERTIES, OnTasksProperties)
	ON_COMMAND(ID_TASKS_DISABLE, OnTasksDisable)
	ON_COMMAND(ID_TASKS_ENABLE, OnTasksEnable)
	ON_WM_DRAWITEM()
	ON_WM_MEASUREITEM()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CSheduler_Tasks::Create(CWnd *pParent)
{
	CRect rc (0, 0, 50, 50);

	if (FALSE == CListCtrl::Create (LVS_REPORT|LVS_NOSORTHEADER|LVS_SHOWSELALWAYS|LVS_OWNERDRAWFIXED, rc, pParent, 0x7645329))
		return FALSE;

	SetExtendedStyle (LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_INFOTIP);

	

	m_images.Create (16, 17, ILC_COLOR24 | ILC_MASK, 2, 1);
	CBitmap bmp;
	bmp.Attach (SBMP (IDB_SHEDULER));
	m_images.Add (&bmp, RGB (255, 0, 255));
	SetImageList (&m_images, LVSIL_SMALL);

	m_selImages.Create (16, 17, ILC_COLOR24 | ILC_MASK, 2, 1);
	CBitmap bmp1;
	bmp1.Attach (SBMP (IDB_SCHEDULER_SEL));
	m_selImages.Add (&bmp1, RGB (255, 0, 255));
	SetSelectedImages (&m_selImages);

	InsertColumn (0, LS (L_WTS), LVCFMT_LEFT, 250, 0);
	InsertColumn (1, LS (L_HTS), LVCFMT_LEFT, 150, 0);
	InsertColumn (2, LS (L_NEXTSTART), LVCFMT_LEFT, 100, 0);
	InsertColumn (3, LS (L_LASTSTART), LVCFMT_LEFT, 100, 0);

	ReadState ("SchedulerTasks");

	ShowWindow (SW_SHOW);

	return TRUE;
}

void CSheduler_Tasks::AddTask(fsSchedule *task)
{
	int iItem = AddItem (fsScheduleMgr::WTSToStr (task), GetSysColor (COLOR_WINDOW), 
		GetSysColor (COLOR_WINDOWTEXT), GetTaskImage (task));

	SetItemData (iItem, DWORD (task));

	UpdateTask (task);
}

void CSheduler_Tasks::UpdateTask(fsSchedule *task)
{
	int iItem = FindTask (task);

	if (iItem != -1)
		UpdateTask (iItem);
}

int CSheduler_Tasks::FindTask(fsSchedule *task)
{
	int cItems = GetItemCount ();

	for (int i = 0; i < cItems; i++)
		if (GetItemData (i) == (DWORD) task)
			return i;

	return -1;
}

void CSheduler_Tasks::OnDblclk(NMHDR* , LRESULT* pResult) 
{
	OnTasksProperties ();
	
	*pResult = 0;
}

void CSheduler_Tasks::OnRClick()
{
	CMenu menu;
	menu.LoadMenu (IDM_TASKS);
	ApplyLanguageToMenu (&menu);
	CMenu *pPopup = menu.GetSubMenu (0);

	UpdateMenu (pPopup);

	ClientToScreen (&m_rbPt);

	m_odmenu.Attach (&menu, FALSE);

	m_odmenu.SetImageList (&((CMainFrame*)AfxGetApp ()->m_pMainWnd)->m_imgsMenu, &((CMainFrame*)AfxGetApp ()->m_pMainWnd)->m_dimgsMenu);
	fsSetImage *pImages;
	int cImages;
	CShedulerWnd::Plugin_GetMenuImages (&pImages, &cImages);
	m_odmenu.SetImages (pImages, cImages);

	pPopup->TrackPopupMenu (TPM_RIGHTBUTTON | TPM_TOPALIGN | TPM_LEFTALIGN,	m_rbPt.x, m_rbPt.y, this);
	m_odmenu.Detach ();

	menu.DestroyMenu ();
}

void CSheduler_Tasks::OnRButtonDown(UINT nFlags, CPoint point) 
{
	m_rbPt = point;
	
	CListCtrlEx::OnRButtonDown(nFlags, point);
}

void CSheduler_Tasks::OnTasksDeletetask() 
{
	POSITION pos = GetFirstSelectedItemPosition ();

	if (pos == NULL)
		return;

	if (MessageBox (LS (L_AREYOUSURE), LS (L_CONFIRMATION), MB_YESNO | MB_ICONQUESTION) == IDNO)
	{
		SetFocus ();
		return;
	}

	SetFocus ();

	fs::list <int> vItems;

	while (pos)
		vItems.add (GetNextSelectedItem (pos));

	fsScheduleMgr *mgr = _pwndScheduler->GetMgr ();

	for (int i = vItems.size () - 1; i >= 0; i--)
	{
		int iItem = vItems [i];
		fsSchedule *task = (fsSchedule*) GetItemData (iItem);
		mgr->DeleteTask (task);
	}

	
	_pwndSpider->UpdateTasksIcons ();
}

void CSheduler_Tasks::OnCreatenewtask() 
{
	_pwndScheduler->OnCreatenewtask ();
	SetFocus ();
}

void CSheduler_Tasks::OnTasksProperties() 
{
	POSITION pos = GetFirstSelectedItemPosition ();

	if (pos == NULL)
		return;

	int iItem = GetNextSelectedItem (pos);

	if (pos)
		return;

	fsSchedule *task = (fsSchedule*) GetItemData (iItem);

	_pwndScheduler->OnProperties (task);

	_pwndScheduler->GetMgr ()->OnTaskUpdated (task);
	
	SetFocus ();
}

void CSheduler_Tasks::OnKeyDown(WORD wVK)
{
	switch (wVK)
	{
		case VK_DELETE:
			OnTasksDeletetask ();
		break;

		case VK_RETURN:
			OnTasksProperties ();
		break;

		case VK_APPS:
			CalcCoordsForCurSel ();
			OnRClick ();
		break;
	}
}

void CSheduler_Tasks::OnTasksDisable() 
{
	POSITION pos = GetFirstSelectedItemPosition ();

	while (pos)
	{
		int iItem = GetNextSelectedItem (pos);
		fsSchedule *task = (fsSchedule*) GetItemData (iItem);
		task->dwFlags &= ~ SCHEDULE_ENABLED;

		fsScheduleEx* pschScheduleParam = (fsScheduleEx*)task;
		if (pschScheduleParam && pschScheduleParam->m_ppoTaskWrapper)
			pschScheduleParam->m_ppoTaskWrapper->setDirty();

		_pwndScheduler->GetMgr ()->OnTaskUpdated (task);
	}
}

void CSheduler_Tasks::OnTasksEnable() 
{
	POSITION pos = GetFirstSelectedItemPosition ();

	while (pos)
	{
		int iItem = GetNextSelectedItem (pos);
		fsSchedule *task = (fsSchedule*) GetItemData (iItem);
		task->dwFlags |= SCHEDULE_ENABLED;

		fsScheduleEx* pschScheduleParam = (fsScheduleEx*)task;
		if (pschScheduleParam && pschScheduleParam->m_ppoTaskWrapper)
			pschScheduleParam->m_ppoTaskWrapper->setDirty();

		_pwndScheduler->GetMgr ()->RepairNextTime (task);
		_pwndScheduler->GetMgr ()->OnTaskUpdated (task);
	}	
}

int CSheduler_Tasks::GetTaskImage(fsSchedule *task)
{
	int iImage;

	if (task->dwFlags & SCHEDULE_ENABLED)
		iImage = 0;
	else
		iImage = 1;

	return iImage;
}

void CSheduler_Tasks::UpdateMenu(CMenu *pPopup)
{
	pPopup->SetDefaultItem (ID_TASKS_PROPERTIES);

	int cItems = GetSelectedCount ();

	if (cItems == 0)
	{
		pPopup->EnableMenuItem (ID_TASKS_ENABLE, MF_BYCOMMAND | MF_GRAYED);
		pPopup->EnableMenuItem (ID_TASKS_DISABLE, MF_BYCOMMAND | MF_GRAYED);
		pPopup->EnableMenuItem (ID_TASKS_DELETETASK, MF_BYCOMMAND | MF_GRAYED);
		pPopup->EnableMenuItem (ID_TASKS_PROPERTIES, MF_BYCOMMAND | MF_GRAYED);
	}
	else
	{
		POSITION pos = GetFirstSelectedItemPosition ();
		while (pos)
		{
			int iItem = GetNextSelectedItem (pos);
			fsSchedule *task = (fsSchedule*) GetItemData (iItem);
			if (task->dwFlags & SCHEDULE_ENABLED)
				pPopup->EnableMenuItem (ID_TASKS_ENABLE, MF_BYCOMMAND | MF_GRAYED);
			else
				pPopup->EnableMenuItem (ID_TASKS_DISABLE, MF_BYCOMMAND | MF_GRAYED);
		}
		
		if (cItems > 1)
			pPopup->EnableMenuItem (ID_TASKS_PROPERTIES, MF_BYCOMMAND | MF_GRAYED);
	}
}

int CSheduler_Tasks::OnUpdateToolBar(UINT nID)
{
	int cItems = GetSelectedCount ();
	BOOL bEnabled = TRUE;

	if (cItems == 0)
	{
		switch (nID)
		{
			case ID_TASKS_ENABLE:
			case ID_TASKS_DISABLE:
			case ID_TASKS_DELETETASK:
			case ID_TASKS_PROPERTIES:
				bEnabled = FALSE;
			break;
		}
	}
	else
	{
		POSITION pos = GetFirstSelectedItemPosition ();
		while (pos)
		{
			int iItem = GetNextSelectedItem (pos);
			fsSchedule *task = (fsSchedule*) GetItemData (iItem);

			switch (nID)
			{
				case ID_TASKS_ENABLE:
					if (task->dwFlags & SCHEDULE_ENABLED)
						bEnabled = FALSE;
				break;
			
				case ID_TASKS_DISABLE:
					if ((task->dwFlags & SCHEDULE_ENABLED) == 0)
						bEnabled = FALSE;
				break;
			}
		}
		
		if (cItems > 1 && nID == ID_TASKS_PROPERTIES)
			bEnabled = FALSE;
	}

	return bEnabled ? WGP_CMDITEMSTATE_ENABLED : WGP_CMDITEMSTATE_DISABLED;
}

void CSheduler_Tasks::OnDrawItem(int , LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	m_odmenu.OnDrawItem (lpDrawItemStruct);
}

void CSheduler_Tasks::OnMeasureItem(int , LPMEASUREITEMSTRUCT lpMeasureItemStruct) 
{
	m_odmenu.OnMeasureItem (lpMeasureItemStruct);
}

void CSheduler_Tasks::ApplyLanguageToMenu(CMenu *menu)
{
	menu->ModifyMenu (0, MF_BYPOSITION|MF_STRING, 0, LS (L_SCHEDULER));
	
	CString str = LS (L_NEWTASK); str += "\tCtrl+T";
	menu->ModifyMenu (ID_CREATENEWTASK, MF_BYCOMMAND|MF_STRING, ID_CREATENEWTASK, str);
	
	menu->ModifyMenu (ID_TASKS_ENABLE, MF_BYCOMMAND|MF_STRING, ID_TASKS_ENABLE, LS (L_ENABLETASK));
	menu->ModifyMenu (ID_TASKS_DISABLE, MF_BYCOMMAND|MF_STRING, ID_TASKS_DISABLE, LS (L_DISABLETASK));
	
	str = LS (L_DELETETASK); str += "\tDel";
	menu->ModifyMenu (ID_TASKS_DELETETASK, MF_BYCOMMAND|MF_STRING, ID_TASKS_DELETETASK, str);
	
	str = LS (L_TASKPROP); str += "\tEnter";
	menu->ModifyMenu (ID_TASKS_PROPERTIES, MF_BYCOMMAND|MF_STRING, ID_TASKS_PROPERTIES, str);
}

void CSheduler_Tasks::ApplyLanguage()
{
	SetColumnText (0, LS (L_WTS));
	SetColumnText (1, LS (L_HTS));
	SetColumnText (2, LS (L_NEXTSTART));
	SetColumnText (3, LS (L_LASTSTART));

	UpdateAllTasks ();
}

void CSheduler_Tasks::UpdateTask(int iItem)
{
	fsSchedule *task = (fsSchedule*) GetItemData (iItem);
	SetItemText (iItem, 0, fsScheduleMgr::WTSToStr (task));
	SetItemText (iItem, 1, fsScheduleMgr::HTSToStr (task));
	SetItemText (iItem, 2, fsScheduleMgr::NextTimeToStr (task));
	SetItemText (iItem, 3, fsScheduleMgr::LastTimeToStr (task));
	SetItemImage (FindTask (task), GetTaskImage (task));
}

void CSheduler_Tasks::UpdateAllTasks()
{
	int cItems = GetItemCount ();
	while (cItems--)
		UpdateTask (cItems);
}

void CSheduler_Tasks::CalcCoordsForCurSel()
{
	int iCurSel = GetSelectionMark ();
	if (iCurSel == -1)
	{
		POSITION pos = GetFirstSelectedItemPosition ();
		if (pos)
			iCurSel = GetNextSelectedItem (pos);
	}

	if (iCurSel != -1)
	{
		RECT rc;
		GetItemRect (iCurSel, &rc, LVIR_BOUNDS);
		m_rbPt.x = rc.left + 30;
		m_rbPt.y = rc.top;
	}
	else
		m_rbPt.x = m_rbPt.y = 30;
}

void CSheduler_Tasks::OnForceUpdate()
{
	UpdateAllTasks ();
}

void CSheduler_Tasks::DeleteTaskFromList(fsSchedule *task)
{
	int iTask = FindTask (task);
	if (iTask != -1)
		DeleteItem (iTask);
}
