/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "SpiderTasks.h"
#include "SpiderWnd.h"
#include "MainFrm.h"
#include "WPDS_Sheet.h"
#include "ShedulerWnd.h"
#include "ScheduleSheet.h"
#include "DownloadsWnd.h"
#include "plugincmds.h"
#include "vmsLogger.h"

extern CSpiderWnd *_pwndSpider;
extern CShedulerWnd *_pwndScheduler;
extern CDownloadsWnd* _pwndDownloads;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CSpiderTasks::CSpiderTasks()
{
}

CSpiderTasks::~CSpiderTasks()
{
}

BEGIN_MESSAGE_MAP(CSpiderTasks, CListCtrlEx)
	//{{AFX_MSG_MAP(CSpiderTasks)
	ON_COMMAND(ID_SPIDER_DL, OnSpiderDl)
	ON_WM_RBUTTONDOWN()
	ON_WM_MEASUREITEM()
	ON_WM_DRAWITEM()
	ON_COMMAND(ID_SPIDER_STOPDL, OnSpiderStopdl)
	ON_COMMAND(ID_SPIDER_STARTDL, OnSpiderStartdl)
	ON_COMMAND(ID_SPIDER_STARTAUTOMATICALLY, OnSpiderStartautomatically)
	ON_COMMAND(ID_SPIDER_SETTINGS, OnSpiderSettings)
	ON_COMMAND(ID_SPIDER_SCHEDULE, OnSpiderSchedule)
	ON_COMMAND(ID_SPIDER_OPENFOLDER, OnSpiderOpenfolder)
	ON_COMMAND(ID_SPIDER_DELETE, OnSpiderDelete)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_SPIDER_OPENPAGE, OnSpiderOpenpage)
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CSpiderTasks::Create(CWnd *pParent)
{
	CRect rc (0, 0, 50, 50);

	if (FALSE == CListCtrl::Create (LVS_REPORT|LVS_NOSORTHEADER|LVS_SHOWSELALWAYS|LVS_OWNERDRAWFIXED, rc, pParent, 0x7645329))
		return FALSE;

	SetExtendedStyle (LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_INFOTIP);

	

	m_images.Create (16, 17, ILC_COLOR24 | ILC_MASK, 6, 1);
	CBitmap bmp;
	bmp.Attach (SBMP (IDB_DOWNLOADSTASKS));
	m_images.Add (&bmp, RGB (255, 0, 255));
	SetImageList (&m_images, LVSIL_SMALL);

	m_selimages.Create (16, 17, ILC_COLOR24 | ILC_MASK, 7, 1);
	CBitmap bmp2;
	bmp2.Attach (SBMP (IDB_DOWNLOADSTASKS_SEL));
	m_selimages.Add (&bmp2, RGB (255, 0, 255));
	SetSelectedImages (&m_selimages);

	InsertColumn (0, LS (L_WEBPAGEURL), LVCFMT_LEFT, 250, 0);
	InsertColumn (1, LS (L_PROGRESS), LVCFMT_LEFT, 150, 0);
	InsertColumn (2, LS (L_FILES), LVCFMT_LEFT, 150, 0);

	ReadState ("SpiderTasks");

	ShowWindow (SW_SHOW);

	return TRUE;
}

void CSpiderTasks::UpdateMenu(CMenu* pMenu)
{
	pMenu->SetDefaultItem (ID_SPIDER_SETTINGS);

	if (GetSelectedCount () == 0)
	{
		pMenu->EnableMenuItem (ID_SPIDER_STARTDL, MF_BYCOMMAND | MF_GRAYED);
		pMenu->EnableMenuItem (ID_SPIDER_STOPDL, MF_BYCOMMAND | MF_GRAYED);
		pMenu->EnableMenuItem (ID_SPIDER_DELETE, MF_BYCOMMAND | MF_GRAYED);
		pMenu->EnableMenuItem (ID_SPIDER_OPENFOLDER, MF_BYCOMMAND | MF_GRAYED);
		pMenu->EnableMenuItem (ID_SPIDER_SETTINGS, MF_BYCOMMAND | MF_GRAYED);
		pMenu->EnableMenuItem (ID_SPIDER_STARTAUTOMATICALLY, MF_BYCOMMAND | MF_GRAYED);
		pMenu->EnableMenuItem (ID_SPIDER_SCHEDULE, MF_BYCOMMAND | MF_GRAYED);
		pMenu->EnableMenuItem (ID_SPIDER_OPENPAGE, MF_BYCOMMAND | MF_GRAYED);
	}
	else
	{
		POSITION pos = GetFirstSelectedItemPosition ();
		int iAutoStart = 3; 

		while (pos)
		{
			int iItem = GetNextSelectedItem (pos);
			fsWebPageDownloader *wpd = (fsWebPageDownloader*) GetItemData (iItem);

			BOOL bAutoStart = wpd->IsOnAutoStart ();
			BOOL bRunning = wpd->IsRunning ();
			BOOL bDone = wpd->IsDone ();

			if (iAutoStart == 3)
				iAutoStart = bAutoStart ? 1 : 0;
			else if (iAutoStart == 1 && bAutoStart == FALSE || iAutoStart == 0 && bAutoStart)
				iAutoStart = 2;	

			if (bRunning || bDone)
				pMenu->EnableMenuItem (ID_SPIDER_STARTDL, MF_BYCOMMAND | MF_GRAYED);
			
			if (bRunning == FALSE)
				pMenu->EnableMenuItem (ID_SPIDER_STOPDL, MF_BYCOMMAND | MF_GRAYED);

			if (bDone)
				pMenu->EnableMenuItem (ID_SPIDER_SCHEDULE, MF_BYCOMMAND | MF_GRAYED);
		}

		if (iAutoStart == 1)
			pMenu->CheckMenuItem (ID_SPIDER_STARTAUTOMATICALLY, MF_CHECKED | MF_BYCOMMAND);

		m_bAutoStart = iAutoStart != 1;

		if (GetSelectedCount () != 1)
			pMenu->EnableMenuItem (ID_SPIDER_OPENPAGE, MF_BYCOMMAND | MF_GRAYED);
		else
		{
			pos = GetFirstSelectedItemPosition ();
			fsWebPageDownloader *wpd = (fsWebPageDownloader*) GetItemData (GetNextSelectedItem (pos));
			fsDLWebPage *wp = wpd->GetRootPage ()->GetData ();
			if (wp->dld && wp->dld->pMgr->IsDone () == FALSE)
				pMenu->EnableMenuItem (ID_SPIDER_OPENPAGE, MF_BYCOMMAND | MF_GRAYED);
		}
	}
}

int CSpiderTasks::UpdateToolBar(UINT nID)
{
	BOOL bEnabled = TRUE;
	int cSelected = GetSelectedCount ();

	switch (nID)
	{
		case ID_SPIDER_DL:
			break;

		case ID_SPIDER_STARTDL:
			if (cSelected == 0)
				bEnabled = FALSE;
			else
			{
				POSITION pos = GetFirstSelectedItemPosition ();
				while (pos)
				{
					int iItem = GetNextSelectedItem (pos);
					fsWebPageDownloader *wpd = (fsWebPageDownloader*) GetItemData (iItem);

					BOOL bRunning = wpd->IsRunning ();
					BOOL bDone = wpd->IsDone ();

					if (bRunning || bDone)
						bEnabled = FALSE;
				}
			}
			break;

		case ID_SPIDER_STOPDL:
			if (cSelected == 0)
				bEnabled = FALSE;
			else
			{
				POSITION pos = GetFirstSelectedItemPosition ();
				while (pos)
				{
					int iItem = GetNextSelectedItem (pos);
					fsWebPageDownloader *wpd = (fsWebPageDownloader*) GetItemData (iItem);

					BOOL bRunning = wpd->IsRunning ();

					if (bRunning == FALSE)
						bEnabled = FALSE;
				}
			}
			break;

		case ID_SPIDER_SCHEDULE:
			if (cSelected == 0)
				bEnabled = FALSE;
			else
			{
				POSITION pos = GetFirstSelectedItemPosition ();
				while (pos)
				{
					int iItem = GetNextSelectedItem (pos);
					fsWebPageDownloader *wpd = (fsWebPageDownloader*) GetItemData (iItem);

					BOOL bDone = wpd->IsDone ();

					if (bDone)
						bEnabled = FALSE;
				}
			}
			break;
	}

	return bEnabled ? WGP_CMDITEMSTATE_ENABLED : WGP_CMDITEMSTATE_DISABLED;
}

void CSpiderTasks::AddWebPage(fsWebPageDownloader *wpd)
{
	int iItem = AddItem (wpd->GetStartURL ());
	SetItemData (iItem, (DWORD)wpd);
	UpdateWebPage (iItem);
}

void CSpiderTasks::UpdateWebPage(int iItem)
{
	fsWebPageDownloader *wpd = (fsWebPageDownloader*) GetItemData (iItem);

	SetItemText (iItem, 0, wpd->GetStartURL ());
	
	CString str;
	str.Format ("%d%%", (int) wpd->GetPercentDone ());
	SetItemText (iItem, 1, str);
	
	str.Format ("%d/%d", wpd->GetDoneFileCount (), wpd->GetFileCount ());
	SetItemText (iItem, 2, str);

	SetItemImage (iItem, GetWebPageImage (wpd));
}

void CSpiderTasks::UpdateWebPage(fsWebPageDownloader *wpd)
{
	int iItem = FindWebPage (wpd);
	if (iItem != -1)
		UpdateWebPage (iItem);
}

int CSpiderTasks::FindWebPage(fsWebPageDownloader *wpd)
{
	LVFINDINFO fi;
	fi.flags = LVFI_PARAM;
	fi.lParam = (LONG)wpd;
	return FindItem (&fi);
}

int CSpiderTasks::GetWebPageImage(fsWebPageDownloader *wpd)
{
	if (wpd->IsDone ())
		return 1;

	if (wpd->IsRunning ())
	{
		if (wpd->IsDownloading ())
			return 3;
		else
			return 4;
	}

	if (wpd->IsScheduled ())
		return 2;

	return wpd->IsOnAutoStart () ? 5 : 0;	
}

void CSpiderTasks::OnSpiderDl() 
{
	_pwndSpider->AddWebPage ();	
	SetFocus ();
}

void CSpiderTasks::OnRClick()
{
	CMenu menu;
	menu.LoadMenu (IDM_SPIDER);
	ApplyLanguageToMenu (&menu);
	CMenu *pPopup = menu.GetSubMenu (0);

	UpdateActiveWPD ();

	UpdateMenu (pPopup);

	ClientToScreen (&m_rbPt);

	m_odmenu.Attach (&menu, FALSE);

	m_odmenu.SetImageList (&((CMainFrame*)AfxGetApp ()->m_pMainWnd)->m_imgsMenu, &((CMainFrame*)AfxGetApp ()->m_pMainWnd)->m_dimgsMenu);
	fsSetImage *pImages;
	int cImages;
	CSpiderWnd::Plugin_GetMenuImages (&pImages, &cImages);
	m_odmenu.SetImages (pImages, cImages);

	pPopup->TrackPopupMenu (TPM_RIGHTBUTTON | TPM_TOPALIGN | TPM_LEFTALIGN,	m_rbPt.x, m_rbPt.y, this);
	m_odmenu.Detach ();

	menu.DestroyMenu ();
}

void CSpiderTasks::OnRButtonDown(UINT nFlags, CPoint point) 
{
	m_rbPt = point;
	CListCtrlEx::OnRButtonDown(nFlags, point);
}

void CSpiderTasks::OnMeasureItem(int , LPMEASUREITEMSTRUCT lpMeasureItemStruct) 
{
	m_odmenu.OnMeasureItem (lpMeasureItemStruct);
}

void CSpiderTasks::OnDrawItem(int , LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	m_odmenu.OnDrawItem (lpDrawItemStruct);
}

void CSpiderTasks::OnSpiderStopdl() 
{
	POSITION pos = GetFirstSelectedItemPosition ();	
	while (pos)
	{
		fsWebPageDownloader *wpd = (fsWebPageDownloader*) GetItemData (GetNextSelectedItem (pos));
		wpd->StopDownloading ();
	}
	SetFocus ();
}

void CSpiderTasks::OnSpiderStartdl() 
{
	POSITION pos = GetFirstSelectedItemPosition ();	
	while (pos)
	{
		fsWebPageDownloader *wpd = (fsWebPageDownloader*) GetItemData (GetNextSelectedItem (pos));
		wpd->StartDownloading ();
	}
	SetFocus ();
}

void CSpiderTasks::OnSpiderStartautomatically() 
{
	POSITION pos = GetFirstSelectedItemPosition ();	
	while (pos)
	{
		fsWebPageDownloader *wpd = (fsWebPageDownloader*) GetItemData (GetNextSelectedItem (pos));
		wpd->SetAutoStartDownloading (m_bAutoStart);
	}
	SetFocus ();
}

void CSpiderTasks::OnSpiderSettings() 
{
	CWPDS_Sheet sheet (LS (L_PROPOFDL), this);

	POSITION pos = GetFirstSelectedItemPosition ();
	if (pos == NULL)
		return;
	fsWebPageDownloader* wpd = (fsWebPageDownloader*) GetItemData (GetNextSelectedItem (pos));

	sheet.Init (wpd->GetWDPS (), TRUE, wpd);

	_DlgMgr.DoModal (&sheet);

	SetFocus ();
}

void CSpiderTasks::OnSpiderSchedule() 
{
	POSITION pos = GetFirstSelectedItemPosition ();
	DLDS_LIST vDlds; 
	fsScheduleMgr *mgr = _pwndScheduler->GetMgr ();

	while (pos)
	{
		int iItem = GetNextSelectedItem (pos);
		fsWebPageDownloader *wpd = (fsWebPageDownloader*) GetItemData (iItem);
		for (int i = 0; i < wpd->GetDownloadCount (); i++)
		{
			vmsDownloadSmartPtr dld = wpd->GetDownload (i);
			if (dld != NULL && dld->pMgr->IsDone () == FALSE)
				vDlds.push_back (dld);
		}
	}

	if (vDlds.size () == 0)
		return;

	
	fsScheduleEx schSheduleParam;
	fsSchedule& task = schSheduleParam.schTask;
	fsSchedule* pTask = mgr->GetScheduleDLTask (vDlds, TRUE);
	BOOL bCreate = pTask == NULL;

	if (pTask == NULL)
	{
		task.hts.enType = HTS_ONCE;
		task.hts.last.dwHighDateTime = task.hts.last.dwLowDateTime = UINT_MAX;
		task.dwFlags = SCHEDULE_ENABLED;
		SYSTEMTIME time;
		GetLocalTime (&time);
		if (++time.wHour > 23)
			time.wHour = 0;
		time.wMinute = 0;
		SystemTimeToFileTime (&time, &task.hts.next);
		task.uWaitForConfirmation = 0;
		pTask = &task;
	}

	CScheduleSheet sheet (LS (L_SCHEDULEDLDS), this);
	sheet.Init (pTask, FALSE);
	_DlgMgr.OnDoModal (&sheet);
	UINT uIDRet = sheet.DoModal ();
    _DlgMgr.OnEndDialog (&sheet);

	 if (uIDRet == IDOK)
	 {
		 if (bCreate)
		 {
			pTask->wts.enType = WTS_STARTDOWNLOAD;
			pTask->wts.dlds.dwFlags = 0;
			fsnew1 (pTask->wts.dlds.pvIDs, fs::list <UINT>);
			for (size_t i = 0; i < vDlds.size (); i++)
				pTask->wts.dlds.pvIDs->add (vDlds [i]->nID);

			_pwndScheduler->AddTask (pTask);
		}
		else
		{
			if (sheet.IsNeedRecalculateStartTime ())
				mgr->CalculateStartTime (pTask);
			_pwndScheduler->GetMgr ()->OnTaskUpdated (pTask);
		}
	}
         
	pos = GetFirstSelectedItemPosition ();
	 while (pos)
		UpdateWebPage (GetNextSelectedItem (pos));
}

void CSpiderTasks::OnSpiderOpenfolder() 
{
	POSITION pos = GetFirstSelectedItemPosition ();
	if (pos)
	{
		fsWebPageDownloader *wpd = (fsWebPageDownloader*) GetItemData (GetNextSelectedItem (pos));
		ShellExecute (m_hWnd, "explore", wpd->GetWDPS ()->strFolderSaveTo, NULL, NULL, SW_SHOW);
	}
}

void CSpiderTasks::OnSpiderDelete() 
{
	POSITION pos = GetFirstSelectedItemPosition ();
	if (pos == NULL)
		return;
	
	 int iRet = MessageBox (LS (L_DELETEDLSALSO), LS (L_CONFIRMATION), MB_ICONQUESTION|MB_YESNOCANCEL);
	
	 SetFocus ();

	 if (iRet == IDCANCEL)
		 return;

	fs::list <int> vPages;

	pos = GetFirstSelectedItemPosition ();
	while (pos)
		vPages.add (GetNextSelectedItem (pos));

	for (int i = vPages.size () - 1; i >= 0; i--)
	{
		fsWebPageDownloader *wpd = (fsWebPageDownloader*) GetItemData (vPages [i]);
		if (iRet == IDYES)
		{
			ShowWindow (SW_HIDE);
			try 
			{
				wpd->DeleteAllDownloads (TRUE);
			}
			catch (const std::exception& ex)
			{
				ASSERT (FALSE);
				vmsLogger::WriteLog("CSpiderTasks::OnSpiderDelete " + tstring(ex.what()));
			}
			catch (...)
			{
				ASSERT (FALSE);
				vmsLogger::WriteLog("CSpiderTasks::OnSpiderDelete unknown exception");
			}
			ShowWindow (SW_SHOW);
		}
		else
			wpd->DetachFromDownloads ();
		DeleteItem (vPages [i]);
		_pwndSpider->GetMgr ()->Delete (wpd);
	}
}

void CSpiderTasks::DeleteWebPage(fsWebPageDownloader *wp)
{
	int iIndex = FindWebPage (wp);
	if (iIndex != -1)
		DeleteItem (iIndex);
}

void CSpiderTasks::UpdateActiveWPD(int adj)
{
	POSITION pos = GetFirstSelectedItemPosition ();
	fsWebPageDownloader* wpd;

	if (pos && GetSelectedCount () == 1)
	{
		int iItem = GetNextSelectedItem (pos);

		iItem += adj;
		if (iItem < 0)
			iItem = 0;
		else if (iItem >= GetItemCount ())
			iItem = GetItemCount () - 1;

		wpd = (fsWebPageDownloader*) GetItemData (iItem);
	}
	else
	{
		int iItem = GetSelectionMark ();

		if (iItem == -1)
			wpd = NULL;
		else
		{
			iItem += adj;

			if (iItem < 0)
				iItem = 0;
			else if (iItem >= GetItemCount ())
				iItem = GetItemCount () - 1;

			wpd = (fsWebPageDownloader*) GetItemData (iItem);
		}
	}

	if (wpd != _pwndSpider->m_wndTaskTree.m_wpd)
	{
		_pwndSpider->m_wndTaskTree.m_wpd = wpd;
		_pwndSpider->m_wndTaskTree.UpdateAll ();
	}
}

void CSpiderTasks::OnClick()
{
	UpdateActiveWPD ();
}

void CSpiderTasks::OnDeleteItem(NM_LISTVIEW *pNM)
{
	if (pNM->lParam == (LONG) _pwndSpider->m_wndTaskTree.m_wpd)
	{
		_pwndSpider->m_wndTaskTree.m_wpd = NULL;
		_pwndSpider->m_wndTaskTree.UpdateAll ();
	}
}

void CSpiderTasks::OnDeleteAllItems()
{
	_pwndSpider->m_wndTaskTree.m_wpd = NULL;
	_pwndSpider->m_wndTaskTree.UpdateAll ();
}

void CSpiderTasks::OnKeyDown(WORD wVK)
{
	switch (wVK)
	{
		case VK_DELETE:
			OnSpiderDelete ();
			break;

		case VK_UP:
			UpdateActiveWPD (-1);
			break;

		case VK_DOWN:
			UpdateActiveWPD (1);
			break;

		case VK_RETURN:
			CallSelectedPage ();
			break;

		case VK_APPS:
			CalcCoordsForCurSel ();
			OnRClick ();
		break;
	}
}

void CSpiderTasks::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	CListCtrlEx::OnLButtonDblClk(nFlags, point);
	CallSelectedPage ();
}

void CSpiderTasks::ApplyLanguageToMenu(CMenu *menu)
{
	menu->ModifyMenu (0, MF_BYPOSITION|MF_STRING, 0, LS (L_HTMLSPIDER));
	
	CString str = LS (L_DLWEBPAGE); str += "\tCtrl+L";
	menu->ModifyMenu (ID_SPIDER_DL, MF_BYCOMMAND|MF_STRING, ID_SPIDER_DL, str);

	str = LS (L_PROPOFDL); str += "\tEnter";
	menu->ModifyMenu (ID_SPIDER_SETTINGS, MF_BYCOMMAND|MF_STRING, ID_SPIDER_SETTINGS, str);

	menu->ModifyMenu (ID_SPIDER_STARTDL, MF_BYCOMMAND|MF_STRING, ID_SPIDER_STARTDL, LS (L_STARTDL));

	menu->ModifyMenu (ID_SPIDER_STOPDL, MF_BYCOMMAND|MF_STRING, ID_SPIDER_STOPDL, LS (L_STOPDL));

	menu->ModifyMenu (ID_SPIDER_SCHEDULE, MF_BYCOMMAND|MF_STRING, ID_SPIDER_SCHEDULE, LS (L_SCHEDULEDL));

	str = LS (L_DELETE); str += "\tDel";
	menu->ModifyMenu (ID_SPIDER_DELETE, MF_BYCOMMAND|MF_STRING, ID_SPIDER_DELETE, str);

	menu->ModifyMenu (ID_SPIDER_OPENFOLDER, MF_BYCOMMAND|MF_STRING, ID_SPIDER_OPENFOLDER, LS (L_OPENFOLDER));

	menu->ModifyMenu (ID_SPIDER_STARTAUTOMATICALLY, MF_BYCOMMAND|MF_STRING, ID_SPIDER_STARTAUTOMATICALLY, LS (L_STARTDLAUTO));

	menu->ModifyMenu (ID_SPIDER_OPENPAGE, MF_BYCOMMAND|MF_STRING, ID_SPIDER_OPENPAGE, LS (L_OPENWEBPAGE));
}

void CSpiderTasks::OnSpiderOpenpage() 
{
	POSITION pos = GetFirstSelectedItemPosition ();
	if (pos)
	{
		fsWebPageDownloader *wpd = (fsWebPageDownloader*) GetItemData (GetNextSelectedItem (pos));
		
		fsDLWebPage* wp = wpd->GetRootPage ()->GetData ();
		LPCSTR pszFile = wp->dld ? wp->dld->pMgr->GetDownloadMgr ()->GetDP ()->pszFileName : wp->strFile;
		ShellExecute (m_hWnd, "open", pszFile, NULL, NULL, SW_SHOW);
	}
}

void CSpiderTasks::ApplyLanguage()
{
	SetColumnText (0, LS (L_WEBPAGEURL));
	SetColumnText (1, LS (L_PROGRESS));
	SetColumnText (2, LS (L_FILES));
}

void CSpiderTasks::CalcCoordsForCurSel()
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

void CSpiderTasks::UpdateIcons()
{
	int cItems = GetItemCount ();
	for (int i = cItems-1; i >= 0; i--)
	{
		fsWebPageDownloader *wpd = (fsWebPageDownloader*) GetItemData (i);
		SetItemImage (i, GetWebPageImage (wpd));
	}
}

void CSpiderTasks::OnForceUpdate()
{
	DeleteAllItems ();
	fsWebPageDownloadsMgr *mgr = _pwndSpider->GetMgr ();
	for (int i = 0; i < mgr->GetWPDCount (); i++)
		AddWebPage (mgr->GetWPD (i));
}

void CSpiderTasks::CallSelectedPage()
{
	POSITION pos = GetFirstSelectedItemPosition ();
	if (pos == NULL)
		return;

	fsWebPageDownloader *wpd = (fsWebPageDownloader*) GetItemData (GetNextSelectedItem (pos));

	if (pos == NULL && wpd->IsDone ())
		OnSpiderOpenpage ();
	else
		OnSpiderSettings ();
}

void CSpiderTasks::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	BOOL bShift = GetKeyState (VK_SHIFT) & 0x8000;
	BOOL bCtrl = GetKeyState (VK_CONTROL) & 0x8000;

	switch (nChar)
	{
		case 'S':
			if (bShift)
			{
				OnSpiderStartdl ();
				return;
			}
			break;

		case 'O':
			if (bShift)
			{
				OnSpiderStopdl ();
				return;
			}
			break;

		case 'A':
			if (bCtrl)
			{
				int cItems = GetItemCount ();
				for (int i = cItems-1; i >= 0; i--)
					SetItemState (i, LVIS_SELECTED, LVIS_SELECTED);
				return;
			}
			break;
	}
	
	CListCtrl::OnKeyDown(nChar, nRepCnt, nFlags);
}
