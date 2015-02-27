/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Downloads_Tasks.h"
#include "DownloadsWnd.h"
#include "fsDownloadMgr.h"
#include "inetutil.h"
#include "misc.h"
#include "plugincmds.h"
#include "ShedulerWnd.h"
#include "list.h"
#include "ScheduleSheet.h"
#include "MainFrm.h"
#include "CreateBatchDownload.h"
#include "Dlg_UnpackSettings.h"
#include "Dlg_UnpackProgress.h"
#include "Dlg_CheckFileIntegrity.h"
#include "Dlg_CheckFileIntegrity_Progress.h"
#include "Dlg_CheckFileIntegrity_Result.h"
#include "FolderBrowser.h"
#include "Dlg_Download.h"
#include "vmsLogger.h"

#include <algorithm>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CShedulerWnd* _pwndScheduler;
extern CDownloadsWnd* _pwndDownloads;

CDownloads_Tasks::CDownloads_Tasks()
{
	m_pActiveDownload = NULL;
	m_sortModeSupport = LCSM_DESCENDING_NOTSUPPORTED;
	m_bAddingDownloads = false;
}

CDownloads_Tasks::~CDownloads_Tasks()
{
}

BEGIN_MESSAGE_MAP(CDownloads_Tasks, CListCtrlEx)
	//{{AFX_MSG_MAP(CDownloads_Tasks)
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_DLDCREATE, OnDldcreate)
	ON_COMMAND(ID_DLDDELETE, OnDlddelete)
	ON_COMMAND(ID_DLDPROPERTIES, OnDldproperties)
	ON_COMMAND(ID_DLDSTART, OnDldstart)
	ON_COMMAND(ID_DLDSTOP, OnDldstop)
	ON_COMMAND(ID_DLDLAUNCH, OnDldlaunch)
	ON_COMMAND(ID_DLDOPENFOLDER, OnDldopenfolder)
	ON_COMMAND(ID_DLDSCHEDULE, OnDldschedule)
	ON_COMMAND(ID_DLDAUTOSTART, OnDldautostart)
	ON_WM_DRAWITEM()
	ON_WM_MEASUREITEM()
	ON_COMMAND(ID_DLDADDSECTION, OnDldaddsection)
	ON_COMMAND(ID_DLDDELSECTION, OnDlddelsection)
	ON_COMMAND(ID_DLDRESTART, OnDldrestart)
	ON_WM_KEYDOWN()
	ON_WM_CHAR()
	ON_COMMAND(ID_DLDQSIZE, OnDldqsize)
	ON_COMMAND(ID_DLDCREATEBATCH, OnDldcreatebatch)
	ON_WM_CREATE()
	ON_COMMAND(ID_DLDCHECKVIR, OnDldcheckvir)
	ON_COMMAND(ID_DLDFIND, OnDldfind)
	ON_COMMAND(ID_DLDFINDNEXT, OnDldfindnext)
	ON_COMMAND(ID_DLDUNPACK, OnDldunpack)
	ON_COMMAND(ID_DLDMOVEDOWN, OnDldmovedown)
	ON_COMMAND(ID_DLDMOVEUP, OnDldmoveup)
	ON_COMMAND(ID_DLDCHECKINTEGRITY, OnDldcheckintegrity)
	ON_COMMAND(ID_DLDMOVETOFOLDER, OnDldmovetofolder)
	ON_COMMAND(ID_DLDMOVEBOTTOM, OnDldmovebottom)
	ON_COMMAND(ID_DLDMOVETOP, OnDldmovetop)
	ON_COMMAND(ID_DLDSCHEDULESTOP, OnDldschedulestop)
	ON_COMMAND(ID_DLDGRANTBANDWIDTHFORDLD, OnDldgrantbandwidthfordld)
	ON_COMMAND(ID_DLDSHOWPROGRESSDLG, OnDldshowprogressdlg)
	ON_COMMAND(ID_DLDCONVERT, OnDldconvert)
	ON_NOTIFY_REFLECT(LVN_GETDISPINFO, OnGetdispinfo)
	ON_COMMAND(ID_DLDENABLESEEDING, OnDldenableseeding)
	ON_COMMAND(ID_DLD_TP, OnDldcreateTP)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDownloads_Tasks::Create(CWnd *pParent)
{
	CRect rc (0, 0, 50, 50);

	
	if (FALSE == CListCtrlEx::Create (HDS_DRAGDROP | LVS_REPORT | 
			LVS_OWNERDRAWFIXED | LVS_SHOWSELALWAYS | LVS_OWNERDATA ,
			rc, pParent, 0x56789))
		return FALSE;

	SetExtendedStyle (LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|
		LVS_EX_INFOTIP|0x00004000);

	m_images.Create (16, 17, ILC_COLOR24 | ILC_MASK, 7, 1);
	CBitmap bmp;
	bmp.Attach (SBMP (IDB_DOWNLOADSTASKS));
  	
	m_images.Add (&bmp, RGB (255, 0, 255));
	SetImageList (&m_images, LVSIL_SMALL);

	m_selimages.Create (16, 17, ILC_COLOR24 | ILC_MASK, 7, 1);
	CBitmap bmp2;
	bmp2.Attach (SBMP (IDB_DOWNLOADSTASKS_SEL));
	m_selimages.Add (&bmp2, RGB (255, 0, 255));
	SetSelectedImages (&m_selimages);

	InsertColumn (0, "", LVCFMT_LEFT, 200, 0);
	InsertColumn (1, "", LVCFMT_LEFT, 50, 0);
	InsertColumn (2, "", LVCFMT_LEFT, 100, 0);
	InsertColumn (3, "", LVCFMT_LEFT, 60, 0);
	InsertColumn (4, "", LVCFMT_LEFT, 58, 0);
	InsertColumn (5, "", LVCFMT_LEFT, 70, 0);
	InsertColumn (6, "", LVCFMT_LEFT, 200, 0);
	InsertColumn (7, "", LVCFMT_LEFT, 120, 0);

	ReadState ("DownloadsList");
	InitSortImages ();	

	ShowWindow (SW_SHOW);

	return TRUE;
}

void CDownloads_Tasks::AddDownloadToList(vmsDownloadSmartPtr dld, BOOL bSelThisDld, bool bPlaceToTop)
{
	if (_PluginMgr.IsWasExit ())
		return;

	if (FindItem (dld) != -1)
		return;

	m_mxAddDel.Lock ();

	size_t nDldIndex;

	
	if (bPlaceToTop == false)
	{
		nDldIndex = m_vDownloads.size ();
		m_vDownloads.push_back (dld);
	}
	else
	{
		nDldIndex = 0;
		m_vDownloads.insert (m_vDownloads.begin (), dld);
	}
	VirtualView_ItemWillBeAdded (GetSysColor (COLOR_WINDOW), GetSysColor (COLOR_WINDOWTEXT), bPlaceToTop ? TRUE : FALSE);
	if (m_bAddingDownloads == false)
		SetItemCountEx (m_vDownloads.size (), LVSICF_NOINVALIDATEALL | LVSICF_NOSCROLL);

	m_mxAddDel.Unlock ();

	UpdateDownload (nDldIndex, FALSE);

	if (bSelThisDld)
		SelectDownload (dld);
}

void CDownloads_Tasks::UpdateDownload(vmsDownloadSmartPtr dld, BOOL bRedraw)
{
	int iItem = FindItem (dld);
	if (iItem != -1)
		UpdateDownload (iItem, bRedraw);
}

void CDownloads_Tasks::OnClick()
{
	UpdateActiveDownload (0);
}

void CDownloads_Tasks::OnRClick()
{
	CMenu menu;
	menu.LoadMenu (IDM_DOWNLOADS);
	ApplyLanguageToMenu (&menu);
	CMenu *pPopup = menu.GetSubMenu (0);

	
	UpdateActiveDownload (0);

	
	UpdateMenu (pPopup);

	ClientToScreen (&m_rbPt);

	m_odmenu.Attach (&menu, FALSE);
	
	m_odmenu.SetImageList (&((CMainFrame*)AfxGetApp ()->m_pMainWnd)->m_imgsMenu, &((CMainFrame*)AfxGetApp ()->m_pMainWnd)->m_dimgsMenu);
	fsSetImage *pImages;
	int cImages;
	CDownloadsWnd::Plugin_GetMenuImages (&pImages, &cImages);
	m_odmenu.SetImages (pImages, cImages);

	fsSetImage img (11, 0, 0);
	m_odmenu.SetImages (&img, 3, NULL, TRUE);

	
	pPopup->TrackPopupMenu (TPM_RIGHTBUTTON | TPM_TOPALIGN | TPM_LEFTALIGN,	m_rbPt.x, m_rbPt.y, this);
	m_odmenu.Detach ();

	menu.DestroyMenu ();

	_pwndDownloads->m_wndDownloads.m_info.m_progress.set_FullRedraw ();
}

vmsDownloadSmartPtr CDownloads_Tasks::GetActiveDownload()
{
	return m_pActiveDownload;
}

void CDownloads_Tasks::OnKeyDown(WORD wVK)
{
	switch (wVK)
	{
		case VK_DELETE:
			
			DeleteSelected (GetKeyState (VK_SHIFT) & 0x8000);
			break;

		case VK_RETURN:
			if (GetKeyState (VK_MENU) & 0x8000)
				OnDldproperties ();
			else
				CallSelectedDownload ();
			break;

		case VK_APPS:
			CalcCoordsForCurSel ();
			OnRClick ();
			break;

		case VK_TAB:
			
			_pwndDownloads->m_wndGroups.SetFocus ();
			break;			
	}
}

void CDownloads_Tasks::UpdateActiveDownload(int adjSelected)
{
	try {
	
		POSITION pos = GetFirstSelectedItemPosition ();
		vmsDownloadSmartPtr dld;	

		
		if (pos && GetSelectedCount () == 1)
		{
			int iItem = GetNextSelectedItem (pos);

			iItem += adjSelected;	
			if (iItem < 0)
				iItem = 0;
			else if (iItem >= GetItemCount ())
				iItem = GetItemCount () - 1;

			dld = m_vDownloads [iItem];
		}
		else
		{
			int iItem = GetSelectionMark ();

			if (iItem == -1)
				dld = NULL;	
			else
			{
				iItem += adjSelected;	

				if (iItem < 0)
					iItem = 0;
				else if (iItem >= GetItemCount ())
					iItem = GetItemCount () - 1;

				dld = m_vDownloads [iItem];
			}
		}

		
		if (dld != m_pActiveDownload)
		{
			m_pActiveDownload = dld;
			m_pDownloadsWnd->SetActiveDownload (m_pActiveDownload);
		}

	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CDownloads_Tasks::UpdateActiveDownload " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CDownloads_Tasks::UpdateActiveDownload unknown exception");
	}
}

int CDownloads_Tasks::FindItem(vmsDownloadSmartPtr dld)
{
	for (size_t i = 0; i < m_vDownloads.size (); i++)
	{
		if (m_vDownloads [i] == dld)
			return i;
	}

	return -1;
}

void CDownloads_Tasks::DeleteSelected(BOOL bDontConfirmFileDeleting)
{
	POSITION pos = GetFirstSelectedItemPosition ();
	if (pos == NULL)
		return;

	if (bDontConfirmFileDeleting || _App.Deleted_ConfirmDeletion ())
		if (IDNO == MessageBox (bDontConfirmFileDeleting ? LS (L_DLDWBDELETEDFROMDISK) : LS (L_AREYOUSURE), LS (L_CONFIRMATION), MB_YESNO|MB_ICONQUESTION))
	{
		SetFocus ();
		return;
	}

	pos = GetFirstSelectedItemPosition ();
	if (pos == NULL)
		return;

	
	fs::list <_sRecordInfo> vDlds;
	
	
	while (pos)
	{
		_sRecordInfo s;

		s.iIndex = GetNextSelectedItem (pos);
		s.dld = m_vDownloads [s.iIndex];

		vDlds.add (s);
	}

	DLDS_LIST vpDlds;
	int i = 0;
	for (i = 0; i < vDlds.size (); i++)
		vpDlds.push_back (vDlds [i].dld);

	
	ShowWindow (SW_HIDE);

	try 
	{
		_DldsMgr.DeleteDownloads (vpDlds, TRUE, bDontConfirmFileDeleting);
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CDownloads_Tasks::DeleteSelected " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CDownloads_Tasks::DeleteSelected unknown exception");
	}

	ShowWindow (SW_SHOW);

	for (i = 0; i < vDlds.size (); i++)
	{
		if (vDlds [i].iIndex >= m_vDownloads.size ())
			break;
		SetItemState (vDlds [i].iIndex, 0, LVIS_SELECTED);
	}

	_pwndDownloads->UpdateTrayIconPlusOthers ();
	UpdateActiveDownload (0);
	SetFocus ();
}

void CDownloads_Tasks::OnRButtonDown(UINT nFlags, CPoint point) 
{
	m_rbPt = point;
	
	CListCtrlEx::OnRButtonDown(nFlags, point);
}

void CDownloads_Tasks::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	CListCtrlEx::OnLButtonDblClk(nFlags, point);
	CallSelectedDownload ();
}

void CDownloads_Tasks::OnDldcreate() 
{
	m_pDownloadsWnd->OnDownloadCreate ();
	SetFocus ();
}

void CDownloads_Tasks::OnDlddelete() 
{
	DeleteSelected ();
	SetFocus ();
}

void CDownloads_Tasks::OnDldproperties() 
{
	POSITION pos = GetFirstSelectedItemPosition ();
	DLDS_LIST vDlds;
	DLDS_LIST vBtDlds;
	DLDS_LIST vTpDlds;

	if (pos == NULL)
		return;

	while (pos)
	{
		int iItem = GetNextSelectedItem (pos);
		vmsDownloadSmartPtr dld = m_vDownloads [iItem];
		if (dld->pMgr->GetDownloadMgr () != NULL)
			vDlds.push_back (dld);
		else if (dld->pMgr->GetBtDownloadMgr () != NULL)
			vBtDlds.push_back (dld);
		else if (dld->pMgr->GetTpDownloadMgr () != NULL)
			vTpDlds.push_back (dld);
	}

	std::vector<std::pair<int, int>> vDldSizes;
	vDldSizes.push_back(std::pair<int, int>( vDlds.size (), 0 ));
	vDldSizes.push_back(std::pair<int, int>( vBtDlds.size (), 1 ));
	vDldSizes.push_back(std::pair<int, int>( vTpDlds.size (), 2 ));	
	std::sort(vDldSizes.begin(), vDldSizes.end());
	
	const int vDldsType = vDldSizes[vDldSizes.size()-1].second;
	if (0 == vDldsType)
		m_pDownloadsWnd->OnDownloadProperties (vDlds);
	else if (1 == vDldsType)
		m_pDownloadsWnd->OnBtDownloadProperties (vBtDlds);
	else if (2 == vDldsType)
		m_pDownloadsWnd->OnTpDownloadProperties (vTpDlds);
	 
	SetFocus ();
}

void CDownloads_Tasks::OnDldstart() 
{
	POSITION pos = GetFirstSelectedItemPosition ();
	DLDS_LIST vDlds;
	
	while (pos)
	{
		vmsDownloadSmartPtr dld = m_vDownloads [GetNextSelectedItem (pos)];
		if (dld->pMgr->IsRunning () == FALSE && dld->pMgr->IsDone () == FALSE)
			vDlds.push_back (dld);
	}

	_DldsMgr.StartDownloads (vDlds, TRUE);
}

void CDownloads_Tasks::OnDldstop() 
{
	POSITION pos = GetFirstSelectedItemPosition ();
	DLDS_LIST vDlds;

	if (pos == NULL)
		return;
	
	while (pos)
	{
		vmsDownloadSmartPtr dld = m_vDownloads [GetNextSelectedItem (pos)];
		if (dld->pMgr->IsRunning ())
			vDlds.push_back (dld);
		else if (dld->bAutoStart)
		{
			dld->bAutoStart = FALSE;
			dld->setDirty();
			UpdateDownload (dld);
		}
	}	

	if (vDlds.size ())
		_DldsMgr.StopDownloads (vDlds, TRUE);
}

void CDownloads_Tasks::OnDldlaunch() 
{
	POSITION pos = GetFirstSelectedItemPosition ();
	
	while (pos)
	{
		vmsDownloadSmartPtr dld = m_vDownloads [GetNextSelectedItem (pos)];
		if (dld->pMgr->IsDone ())
			_DldsMgr.LaunchDownload (dld);
	}	
}

void CDownloads_Tasks::WillBeDeleted(vmsDownloadSmartPtr dld)
{
	UnscheduleDownload (dld->nID);
	DeleteDownload (dld);
}

void CDownloads_Tasks::OnDldopenfolder() 
{
	fs::list <CString> vOpened;
	POSITION pos = GetFirstSelectedItemPosition ();

	while (pos)
	{
		vmsDownloadSmartPtr dld = m_vDownloads [GetNextSelectedItem (pos)];
		CString strFileName = dld->pMgr->get_OutputFilePathName ();
	
		int i;
		for (i = vOpened.size () - 1; i >= 0; i--)
		{
			if (vOpened [i] == strFileName)
				break;
		}
		if (i != -1)
			continue; 

		dld->pMgr->Do_OpenFolder ();
		vOpened.add (strFileName);
	}	
}

void CDownloads_Tasks::UpdateMenu(CMenu *pPopup)
{
	try
	{
		if (_pwndDownloads->Get_DWWN () != DWWN_LISTOFDOWNLOADS || GetSelectedCount () == 0)
		{
			pPopup->EnableMenuItem (ID_DLDSTART, MF_BYCOMMAND | MF_GRAYED);
			pPopup->EnableMenuItem (ID_DLDSTOP, MF_BYCOMMAND | MF_GRAYED);
			pPopup->EnableMenuItem (ID_DLDRESTART, MF_BYCOMMAND | MF_GRAYED);
			pPopup->EnableMenuItem (ID_DLDADDSECTION, MF_BYCOMMAND | MF_GRAYED);
			pPopup->EnableMenuItem (ID_DLDDELSECTION, MF_BYCOMMAND | MF_GRAYED);
			pPopup->EnableMenuItem (ID_DLDDELETE, MF_BYCOMMAND | MF_GRAYED);
			pPopup->EnableMenuItem (ID_DLDOPENFOLDER, MF_BYCOMMAND | MF_GRAYED);
			pPopup->EnableMenuItem (ID_DLDPROPERTIES, MF_BYCOMMAND | MF_GRAYED);
			pPopup->EnableMenuItem (ID_DLDLAUNCH, MF_BYCOMMAND | MF_GRAYED);
			pPopup->EnableMenuItem (ID_DLDAUTOSTART, MF_BYCOMMAND | MF_GRAYED);
			pPopup->EnableMenuItem (ID_DLDSCHEDULE, MF_BYCOMMAND | MF_GRAYED);
			pPopup->EnableMenuItem (ID_DLDQSIZE, MF_BYCOMMAND | MF_GRAYED);
			pPopup->EnableMenuItem (ID_DLDCHECKVIR, MF_BYCOMMAND | MF_GRAYED);
			pPopup->EnableMenuItem (ID_DLDUNPACK, MF_BYCOMMAND | MF_GRAYED);
			pPopup->EnableMenuItem (ID_DLDCONVERT, MF_BYCOMMAND | MF_GRAYED);
			pPopup->EnableMenuItem (ID_DLDMOVEUP, MF_BYCOMMAND | MF_GRAYED);
			pPopup->EnableMenuItem (ID_DLDMOVEDOWN, MF_BYCOMMAND | MF_GRAYED);
			pPopup->EnableMenuItem (ID_DLDMOVETOP, MF_BYCOMMAND | MF_GRAYED);
			pPopup->EnableMenuItem (ID_DLDMOVEBOTTOM, MF_BYCOMMAND | MF_GRAYED);
			pPopup->EnableMenuItem (ID_DLDCHECKINTEGRITY, MF_BYCOMMAND | MF_GRAYED);
			pPopup->EnableMenuItem (ID_DLDMOVETOFOLDER, MF_BYCOMMAND | MF_GRAYED);
			pPopup->EnableMenuItem (ID_DLDSCHEDULESTOP, MF_BYCOMMAND | MF_GRAYED);
			pPopup->EnableMenuItem (ID_DLDGRANTBANDWIDTHFORDLD, MF_BYCOMMAND | MF_GRAYED);
			pPopup->EnableMenuItem (ID_DLDSHOWPROGRESSDLG, MF_BYCOMMAND | MF_GRAYED);
			pPopup->EnableMenuItem (ID_DLDENABLESEEDING, MF_BYCOMMAND | MF_GRAYED);
		}
		else
		{
			POSITION pos = GetFirstSelectedItemPosition ();
			
			
			
			int iAutoStart = 3; 
			
			BOOL bRunning = FALSE;
			
			BOOL bStopped = FALSE; 
			
			BOOL bCanQuery = FALSE;
			
			BOOL bDone = FALSE;
			BOOL b1stDone = FALSE;
			bool b1st = true;
			bool b1stGranted = false;
			bool bHasEnableSeedingDlds = false;
			bool bHasBtDlds = false;

			
			while (pos)
			{
				int iItem = GetNextSelectedItem (pos);
				vmsDownloadSmartPtr dld = m_vDownloads [iItem];

				if (b1st) {
					b1stDone = dld->pMgr->IsDone ();
					b1st = false;
					b1stGranted = dld == _DldsMgr.get_HighestPriorityDownload ();
				}

				if (bHasEnableSeedingDlds == false && dld->pMgr->IsBittorrent ())
				{
					bHasBtDlds = true;

					if ((dld->pMgr->GetBtDownloadMgr ()->get_Flags () & BTDF_DISABLE_SEEDING) == 0 ||
							dld->pMgr->GetBtDownloadMgr ()->isSeeding ())
						bHasEnableSeedingDlds = true;
				}

				if (iAutoStart == 3)
					iAutoStart = dld->bAutoStart ? 1 : 0;
				else if (iAutoStart == 1 && dld->bAutoStart == FALSE || iAutoStart == 0 && dld->bAutoStart)
					iAutoStart = 2;	

				if (bRunning == FALSE && dld->pMgr->IsRunning ())
					bRunning = TRUE;

				if (bStopped == FALSE && dld->pMgr->IsRunning () == FALSE && dld->pMgr->IsDone () == FALSE)
					bStopped = TRUE;

				if (bDone == FALSE && dld->pMgr->IsDone ())
					bDone = TRUE;
	
				if (bCanQuery == FALSE && dld->pMgr->GetNumberOfSections () == 0)
					bCanQuery = TRUE;
			}

			
			if (bRunning == FALSE)
			{
				if (iAutoStart == 0)
					pPopup->EnableMenuItem (ID_DLDSTOP, MF_BYCOMMAND | MF_GRAYED);
				pPopup->EnableMenuItem (ID_DLDADDSECTION, MF_BYCOMMAND | MF_GRAYED);
				pPopup->EnableMenuItem (ID_DLDDELSECTION, MF_BYCOMMAND | MF_GRAYED);
				pPopup->EnableMenuItem (ID_DLDGRANTBANDWIDTHFORDLD, MF_BYCOMMAND | MF_GRAYED);
				pPopup->EnableMenuItem (ID_DLDSHOWPROGRESSDLG, MF_BYCOMMAND | MF_GRAYED);
			}
			else if (GetSelectedCount () != 1)
			{
				pPopup->EnableMenuItem (ID_DLDGRANTBANDWIDTHFORDLD, MF_BYCOMMAND | MF_GRAYED);
			}

			
			if (bStopped == FALSE)
			{
				pPopup->EnableMenuItem (ID_DLDSTART, MF_BYCOMMAND | MF_GRAYED);
				if (bDone == FALSE)
					pPopup->EnableMenuItem (ID_DLDRESTART, MF_BYCOMMAND | MF_GRAYED);
				pPopup->EnableMenuItem (ID_DLDQSIZE, MF_BYCOMMAND | MF_GRAYED);
			}

			
			if (bRunning == FALSE && bStopped == FALSE)
			{
				pPopup->EnableMenuItem (ID_DLDSCHEDULE, MF_BYCOMMAND | MF_GRAYED);
				pPopup->EnableMenuItem (ID_DLDSCHEDULESTOP, MF_BYCOMMAND | MF_GRAYED);
			}

			
			if (bDone == FALSE)
			{
				pPopup->EnableMenuItem (ID_DLDLAUNCH, MF_BYCOMMAND | MF_GRAYED);
				pPopup->EnableMenuItem (ID_DLDCHECKVIR, MF_BYCOMMAND | MF_GRAYED);
			}

			
			if (bCanQuery == FALSE)
				pPopup->EnableMenuItem (ID_DLDQSIZE, MF_BYCOMMAND | MF_GRAYED);

			
			if (iAutoStart == 1)
				pPopup->CheckMenuItem (ID_DLDAUTOSTART, MF_CHECKED | MF_BYCOMMAND);

			m_bAutoStart = iAutoStart != 1;

			if (GetSelectedCount () != 1 || b1stDone == FALSE) {
				pPopup->EnableMenuItem (ID_DLDUNPACK, MF_BYCOMMAND | MF_GRAYED);
				pPopup->EnableMenuItem (ID_DLDCONVERT, MF_BYCOMMAND | MF_GRAYED);
				pPopup->EnableMenuItem (ID_DLDCHECKINTEGRITY, MF_BYCOMMAND | MF_GRAYED);
			}

			if (GetSelectedCount () == 1 && b1stGranted)
				pPopup->CheckMenuItem (ID_DLDGRANTBANDWIDTHFORDLD, MF_CHECKED | MF_BYCOMMAND);

			m_bHasEnableSeedingDlds = bHasEnableSeedingDlds;
			if (bHasBtDlds == false)
				pPopup->EnableMenuItem (ID_DLDENABLESEEDING, MF_BYCOMMAND | MF_GRAYED);
			else if (bHasEnableSeedingDlds)
				pPopup->CheckMenuItem (ID_DLDENABLESEEDING, MF_CHECKED | MF_BYCOMMAND);
		}
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CDownloads_Tasks::UpdateMenu " + tstring(ex.what()));
		UpdateMenu (pPopup);
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CDownloads_Tasks::UpdateMenu unknown exception");
		UpdateMenu (pPopup);
	}
}

void CDownloads_Tasks::AddDownload(vmsDownloadSmartPtr dld, BOOL bSelThisDld)
{
	AddDownloadToList (dld, bSelThisDld);
}

void CDownloads_Tasks::DeleteDownload(vmsDownloadSmartPtr dld)
{
	m_mxAddDel.Lock ();

	int iIndex = FindItem (dld);

	if (iIndex != -1)
	{
		VirtualView_ItemWillBeDeleted (iIndex);
		m_vDownloads.erase (m_vDownloads.begin () + iIndex);
		SetItemCount (m_vDownloads.size ());
		if (m_pActiveDownload == dld)
		{
			m_pActiveDownload = NULL;
			m_pDownloadsWnd->SetActiveDownload (NULL);
		}
	}

	m_mxAddDel.Unlock ();
}

void CDownloads_Tasks::OnDldschedule() 
{
	ScheduleSelectedDlds (TRUE);
}

int CDownloads_Tasks::GetDownloadImage(vmsDownloadSmartPtr dld)
{
	if (dld->pMgr->IsRunning ())
	{
		if (dld->pMgr->GetDownloadingSectionCount () || dld->pMgr->GetSpeed ())
			return 3;	
		else
			return 4;	
	}

	if (dld->pMgr->IsDone ())
	{
		if (dld->pMgr->IsBittorrent () && dld->pMgr->GetBtDownloadMgr ()->isSeeding ())
			return 7;	
		return 1;	
	}

	if (_pwndScheduler && _pwndScheduler->GetMgr ()->IsDownloadScheduled (dld))
		return 2;	

	return dld->bAutoStart ? 5 : 0;	
}

void CDownloads_Tasks::UpdateAllDownloads()
{
	RedrawItems (0, GetItemCount ()-1);
	UpdateWindow ();
}

void CDownloads_Tasks::UnscheduleDownload(UINT nID)
{
	fsScheduleMgr *mgr = _pwndScheduler->GetMgr ();

	
	for (int i = mgr->GetTaskCount () - 1; i >= 0; i--)
	{
		fsSchedule *task = mgr->GetTask (i);
		if (task->wts.enType == WTS_STARTDOWNLOAD || task->wts.enType == WTS_STOPDOWNLOAD)
		{
			for (int j = task->wts.dlds.pvIDs->size () - 1; j >= 0; j--)
			{
				
				if (task->wts.dlds.pvIDs->at (j) == nID)
				{
					
					task->wts.dlds.pvIDs->del (j);
					if (task->wts.dlds.pvIDs->size () == 0)
						mgr->DeleteTask (task);	
					break;
				}
			}
		}
	}
}

void CDownloads_Tasks::OnForceUpdate()
{
	RedrawItems (0, GetItemCount ()-1);
}

void CDownloads_Tasks::OnDldautostart() 
{
	POSITION pos = GetFirstSelectedItemPosition	();

	while (pos)
	{
		vmsDownloadSmartPtr dld = m_vDownloads [GetNextSelectedItem (pos)];
		dld->bAutoStart = m_bAutoStart;
		dld->setDirty();
		UpdateDownload (dld);
	}

	_DldsMgr.setNeedProcessDownloads ();
}

int CDownloads_Tasks::OnUpdateToolBar(UINT nID)
{
	BOOL bEnabled = TRUE;	
	BOOL bChecked = FALSE;	

	
	if (nID == ID_DLD_VID_PLAY || nID == ID_DLD_VID_PAUSE ||
		nID == ID_DLD_VID_STOP || nID == ID_DLD_VID_MUTE     )
	{
		_pwndDownloads->m_wndDownloads.m_info.m_video.UpdateCommand (nID,
			&bEnabled, &bChecked);

		int iState = bEnabled ? WGP_CMDITEMSTATE_ENABLED : WGP_CMDITEMSTATE_DISABLED;
		if (bChecked) iState |= WGP_CMDITEMSTATE_CHECKED;
		return iState;
	}

	if (GetSelectedCount () == 0)
	{
		switch (nID)
		{
			case ID_DLDSTART:
			case ID_DLDSTOP:
			case ID_DLDDELETE:
			case ID_DLDOPENFOLDER:
			case ID_DLDPROPERTIES:
			case ID_DLDLAUNCH:
			case ID_DLDCHECKVIR:
			case ID_DLDAUTOSTART:
			case ID_DLDSCHEDULE:
			case ID_DLDMOVEUP:
			case ID_DLDMOVEDOWN:
			case ID_DLDMOVETOP:
			case ID_DLDMOVEBOTTOM:
			case ID_DLDSCHEDULESTOP:
			case ID_DLDSHOWPROGRESSDLG:
				bEnabled = FALSE;
			break;
		}
	}
	else
	{
		

		POSITION pos = GetFirstSelectedItemPosition ();
		int iAutoStart = 3; 
		BOOL bRunning = FALSE;
		BOOL bStopped = FALSE;

		while (pos)
		{
			try 
			{
				int iItem = GetNextSelectedItem (pos);
				vmsDownloadSmartPtr dld = m_vDownloads [iItem];
				if (dld->pMgr->IsRunning ())
					bRunning = TRUE;
				else if (dld->pMgr->IsDone () == FALSE)
					bStopped = TRUE;

				if (iAutoStart == 3)
					iAutoStart = dld->bAutoStart ? 1 : 0;
				else if (iAutoStart == 1 && dld->bAutoStart == FALSE || iAutoStart == 0 && dld->bAutoStart)
					iAutoStart = 2;	
			}
			catch (const std::exception& ex)
			{
				ASSERT (FALSE);
				vmsLogger::WriteLog("CDownloads_Tasks::OnUpdateToolBar " + tstring(ex.what()));
			}
			catch (...)
			{
				ASSERT (FALSE);
				vmsLogger::WriteLog("CDownloads_Tasks::OnUpdateToolBar unknown exception");
			}
		}

		switch (nID)
		{
			case ID_DLDSTART:
				if (bStopped == FALSE)
						bEnabled = FALSE;
				break;

			case ID_DLDSTOP:
				if (bRunning == FALSE && iAutoStart == 0)
					bEnabled = FALSE;
				break;

			case ID_DLDSCHEDULE:
			case ID_DLDSCHEDULESTOP:
				if (bRunning == FALSE && bStopped == FALSE)
					bEnabled = FALSE;
				break;
		}

		if (nID == ID_DLDAUTOSTART && iAutoStart == 1)
			bChecked = TRUE;
	}

	int iState = bEnabled ? WGP_CMDITEMSTATE_ENABLED : WGP_CMDITEMSTATE_DISABLED;
	if (bChecked) 
	{
		iState |= WGP_CMDITEMSTATE_CHECKED;
	}
	return iState;
}

void CDownloads_Tasks::OnDrawItem(int , LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	m_odmenu.OnDrawItem (lpDrawItemStruct);
}

void CDownloads_Tasks::OnMeasureItem(int , LPMEASUREITEMSTRUCT lpMeasureItemStruct) 
{
	m_odmenu.OnMeasureItem (lpMeasureItemStruct);
}

void CDownloads_Tasks::ApplyLanguageToMenu(CMenu *menu)
{
	menu->ModifyMenu (0, MF_BYPOSITION|MF_STRING, 0, LS (L_DOWNLOADS));
	
	CString str = LS (L_NEWDL); str += "\tCtrl+N";
	menu->ModifyMenu (ID_DLDCREATE, MF_BYCOMMAND|MF_STRING, ID_DLDCREATE, str);

	menu->ModifyMenu (ID_DLDCREATEBATCH, MF_BYCOMMAND|MF_STRING, ID_DLDCREATEBATCH, LS (L_CREATEBATCHDLD));

	menu->ModifyMenu (ID_DLD_TP, MF_BYCOMMAND|MF_STRING, ID_DLD_TP, LS (L_CREATETPDLD));
	
	str = LS (L_STARTDLDS); str += "\tShift+S";
	menu->ModifyMenu (ID_DLDSTART, MF_BYCOMMAND|MF_STRING, ID_DLDSTART, str);
	str = LS (L_STOPDLDS); str += "\tShift+O";
	menu->ModifyMenu (ID_DLDSTOP, MF_BYCOMMAND|MF_STRING, ID_DLDSTOP, str);

	str = LS (L_QUERYSIZE); str += "\tShift+Q";
	menu->ModifyMenu (ID_DLDQSIZE, MF_BYCOMMAND|MF_STRING, ID_DLDQSIZE, str);

	menu->GetSubMenu (0)->ModifyMenu (10, MF_BYPOSITION|MF_STRING, 0, LS (L_ADVANCED));
	str = LS (L_RESTARTDL); str += "\tShift+R";
	menu->ModifyMenu (ID_DLDRESTART, MF_BYCOMMAND|MF_STRING, ID_DLDRESTART, str);
	str = LS (L_ADDONEMORESECT); str += "\t+";
	menu->ModifyMenu (ID_DLDADDSECTION, MF_BYCOMMAND|MF_STRING, ID_DLDADDSECTION, str);
	str = LS (L_DELSECTION); str += "\t-";
	menu->ModifyMenu (ID_DLDDELSECTION, MF_BYCOMMAND|MF_STRING, ID_DLDDELSECTION, str);
	
	menu->GetSubMenu (0)->ModifyMenu (12, MF_BYPOSITION|MF_STRING, 0, LS (L_SCHEDULE));
	menu->ModifyMenu (ID_DLDSCHEDULE, MF_BYCOMMAND|MF_STRING, ID_DLDSCHEDULE, LS (L_SCHEDULE_START));
	menu->ModifyMenu (ID_DLDSCHEDULESTOP, MF_BYCOMMAND|MF_STRING, ID_DLDSCHEDULESTOP, LS (L_SCHEDULE_STOP));
	
	str = LS (L_DELETEDLD); str += "\tDel (Shift+Del)";
	menu->ModifyMenu (ID_DLDDELETE, MF_BYCOMMAND|MF_STRING, ID_DLDDELETE, str);

	menu->ModifyMenu (ID_DLDLAUNCH, MF_BYCOMMAND|MF_STRING, ID_DLDLAUNCH, LS (L_LAUNCHFILE));
	menu->ModifyMenu (ID_DLDOPENFOLDER, MF_BYCOMMAND|MF_STRING, ID_DLDOPENFOLDER, LS (L_OPENFOLDER));
	
	str = LS (L_AUTOSTARTDLD); str += '\t';
	menu->ModifyMenu (ID_DLDAUTOSTART, MF_BYCOMMAND|MF_STRING, ID_DLDAUTOSTART, str);

	menu->ModifyMenu (ID_DLDCHECKVIR, MF_BYCOMMAND|MF_STRING, ID_DLDCHECKVIR, LS (L_PERFVIRCHECK));

	str = LS (L_DLDPROP); str += "\tAlt+Enter";
	menu->ModifyMenu (ID_DLDPROPERTIES, MF_BYCOMMAND|MF_STRING, ID_DLDPROPERTIES, str);

	str = LS (L_FIND); str += "\tCtrl+F";
	menu->ModifyMenu (ID_DLDFIND, MF_BYCOMMAND|MF_STRING, ID_DLDFIND, str);
	
	str = LS (L_FINDNEXT); str += "\tF3";
	menu->ModifyMenu (ID_DLDFINDNEXT, MF_BYCOMMAND|MF_STRING, ID_DLDFINDNEXT, str);

	menu->ModifyMenu (ID_DLDUNPACK, MF_BYCOMMAND|MF_STRING, ID_DLDUNPACK, LS (L_EXTRACTARCHIVE));
	menu->ModifyMenu (ID_DLDCONVERT, MF_BYCOMMAND|MF_STRING, ID_DLDCONVERT, LS (L_CONVERT_MEDIA_FILE));

	str = LS (L_MOVEUP); str += "\tShift+U";
	menu->ModifyMenu (ID_DLDMOVEUP, MF_BYCOMMAND|MF_STRING, ID_DLDMOVEUP, str);

	str = LS (L_MOVEDOWN); str += "\tShift+D";
	menu->ModifyMenu (ID_DLDMOVEDOWN, MF_BYCOMMAND|MF_STRING, ID_DLDMOVEDOWN, str);

	str = LS (L_CHECKFILEINTEGRITY); str += "\tShift+I";
	menu->ModifyMenu (ID_DLDCHECKINTEGRITY, MF_BYCOMMAND|MF_STRING, ID_DLDCHECKINTEGRITY, str);

	str = LS (L_MOVEDLDFILETOFOLDER); str += "\tShift+M";
	menu->ModifyMenu (ID_DLDMOVETOFOLDER, MF_BYCOMMAND|MF_STRING, ID_DLDMOVETOFOLDER, str);

	str = LS (L_MOVETOP); str += "\tShift+T";
	menu->ModifyMenu (ID_DLDMOVETOP, MF_BYCOMMAND|MF_STRING, ID_DLDMOVETOP, str);

	str = LS (L_MOVEBOTTOM); str += "\tShift+B";
	menu->ModifyMenu (ID_DLDMOVEBOTTOM, MF_BYCOMMAND|MF_STRING, ID_DLDMOVEBOTTOM, str);

	menu->ModifyMenu (ID_DLDGRANTBANDWIDTHFORDLD, MF_BYCOMMAND|MF_STRING, ID_DLDGRANTBANDWIDTHFORDLD, LS (L_GRANTBANDWIDTHFORDLD));

	menu->ModifyMenu (ID_DLDSHOWPROGRESSDLG, MF_BYCOMMAND|MF_STRING, ID_DLDSHOWPROGRESSDLG, LS (L_DLDSHOWPROGRESSDLG));

	menu->ModifyMenu (ID_DLDENABLESEEDING, MF_BYCOMMAND|MF_STRING, ID_DLDENABLESEEDING, LS (L_ENABLE_SEEDING));
}

void CDownloads_Tasks::ApplyLanguage()
{
	SetColumnText (0, LS (L_FILENAME));
	SetColumnText (1, LS (L_SIZE));
	SetColumnText (2, LS (L_DOWNLOADED));
	SetColumnText (3, LS (L_TIMELEFT));
	SetColumnText (4, LS (L_SECTIONS));
	SetColumnText (5, LS (L_SPEED));
	SetColumnText (6, LS (L_COMMENT));
	SetColumnText (7, LS (L_ADDED));
}

void CDownloads_Tasks::CalcCoordsForCurSel()
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

void CDownloads_Tasks::OnDldaddsection() 
{
	POSITION pos = GetFirstSelectedItemPosition ();
	while (pos)
	{
		vmsDownloadSmartPtr dld = m_vDownloads [GetNextSelectedItem (pos)];
		if (dld->pMgr->IsRunning ())
			dld->pMgr->CreateOneMoreSection ();
	}
}

void CDownloads_Tasks::OnDlddelsection() 
{
	POSITION pos = GetFirstSelectedItemPosition ();
	while (pos)
	{
		vmsDownloadSmartPtr dld = m_vDownloads [GetNextSelectedItem (pos)];
		if (dld->pMgr->IsRunning ())
			dld->pMgr->StopSection ();
	}	
}

void CDownloads_Tasks::OnDldrestart() 
{
	POSITION pos = GetFirstSelectedItemPosition ();

	if (pos)
	{
		if (MessageBox (LS (L_AREYOUSURE_WILLSTARTFROM0), LS (L_CONFIRMATION), MB_ICONQUESTION | MB_YESNO) == IDNO)
			return;
	}

	DLDS_LIST vpDlds;

	while (pos)
		vpDlds.push_back (m_vDownloads [GetNextSelectedItem (pos)]);

	for (size_t i = 0; i < vpDlds.size (); i++)
		_pwndDownloads->RestartDownload (vpDlds [i], i == vpDlds.size () - 1);
}

void CDownloads_Tasks::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	BOOL bShift = GetKeyState (VK_SHIFT) & 0x8000;
	BOOL bCtrl = GetKeyState (VK_CONTROL) & 0x8000;

	switch (nChar)
	{
		case 'S':
			if (bShift)
			{
				OnDldstart ();
				return;
			}
			break;

		case 'O':
			if (bShift)
			{
				OnDldstop ();
				return;
			}
			break;

		case 'Q':
			if (bShift)
			{
				OnDldqsize ();
				return;
			}
			break;

		case VK_ADD:
			OnDldaddsection ();
			return;

		case VK_SUBTRACT:
			OnDlddelsection ();
			return;

		case 'R':
			if (bShift)
			{
				OnDldrestart ();
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

		case 'U':
			if (bShift)
			{
				OnDldmoveup ();
				return;
			}
			break;

		case 'D':
			if (bShift)
			{
				OnDldmovedown ();
				return;
			}
			break;

		case 'T':
			if (bShift)
			{
				OnDldmovetop ();
				return;
			}
			break;

		case 'B':
			if (bShift)
			{
				OnDldmovebottom ();
				return;
			}
			break;

		case 'I':
			if (bShift)
			{
				OnDldcheckintegrity ();
				return;
			}
			break;

		case 'M':
			if (bShift)
			{
				OnDldmovetofolder ();
				return;
			}
			break;
	}
	
	CListCtrl::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CDownloads_Tasks::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	switch (nChar)
	{
		case 'S':
		case 'O':
		case 'R':
		case 'Q':
		case 'U':
		case 'D':
		case 'I':
		case 'M':
		case 'T':
		case 'B':
			if (GetKeyState (VK_SHIFT) & 0x8000)
				return;
	
		case '+':
		case '-':
			return;
	}
	
	CListCtrlEx::OnChar(nChar, nRepCnt, nFlags);
}

void CDownloads_Tasks::OnDldqsize() 
{
	POSITION pos = GetFirstSelectedItemPosition ();
	while (pos)
	{
		int iItem = GetNextSelectedItem (pos);
		vmsDownloadSmartPtr dld = m_vDownloads [iItem];
		if (dld->pMgr->GetDownloadMgr () != NULL)
		{
			if (dld->pMgr->IsRunning () == FALSE && dld->pMgr->IsDone () == FALSE && 
					dld->pMgr->GetDownloadMgr ()->IsQueringSize () == FALSE &&
					dld->pMgr->GetNumberOfSections () == 0)
				dld->pMgr->GetDownloadMgr ()->QuerySize2 ();
		}
	}
}

void CDownloads_Tasks::OnDldcreatebatch() 
{
	CCreateBatchDownload dlg;
	_DlgMgr.OnDoModal (&dlg);
	dlg.DoModal ();
	_DlgMgr.OnEndDialog (&dlg);
}

void CDownloads_Tasks::OnSortModeChanged()
{
	Sort ();
}

void CDownloads_Tasks::Sort()
{
	if (m_sortMode != LCSM_NONE)
	{
		SortDownloads ();
		m_sortMode = LCSM_NONE;
	}
}

void CDownloads_Tasks::GetFileName(vmsDownloadSmartPtr dld, LPSTR pszFileName)
{
	strcpy (pszFileName, GetFileName (dld).c_str ());
}

std::string CDownloads_Tasks::GetFileName(vmsDownloadSmartPtr dld)
{
	std::string strResult;

	if (dld->pMgr->GetTpDownloadMgr ())
	{
		return dld->pMgr->get_OutputFilePathName ();
	}

	if (dld->pMgr->GetBtDownloadMgr ())
	{
		CString str = dld->pMgr->get_OutputFilePathName ();
		
		
		if (str.IsEmpty ())
			return "";

		if (str [str.GetLength () - 1] != '\\')
		{
			LPCSTR psz = strrchr (str, '\\');
			if (psz)
				str	= psz + 1;
		}
		else
		{
			str = dld->pMgr->GetBtDownloadMgr ()->get_TorrentName ();
		}

		return str;
	}

	if (dld->pMgr->GetDownloadMgr ())
	{
		fsDownloadMgr *pMgr = dld->pMgr->GetDownloadMgr ();

		CString strFile = dld->pMgr->get_OutputFilePathName ();

		int fl = strFile.GetLength ();

		ASSERT (fl > 0);

		if (!fl)
			return "index.html";

		
		if (strFile [fl-1] == '\\' || strFile [fl-1] == '/')
		{
			LPCSTR psz = pMgr->GetDownloader ()->Get_FileName ();

			if (psz && *psz)
				strResult = psz;
			else
			{
				char sz [10000] = "";
				
				fsFileNameFromUrlPath (pMgr->GetDNP ()->pszPathName, 
					pMgr->GetDNP ()->enProtocol == NP_FTP, TRUE, sz, 10000);
				strResult = sz;
			}
		}
		else
		{
			char sz [10000] = "";
			
			
			fsGetFileName (strFile, sz);
			if (pMgr->GetDP ()->pszAdditionalExt && *pMgr->GetDP ()->pszAdditionalExt)
			{
				char* pszAddExt = sz;
				while (TRUE)
				{
					pszAddExt = strstr (pszAddExt, pMgr->GetDP ()->pszAdditionalExt);
					if (pszAddExt == NULL)
						break;

					if (*(pszAddExt-1) == '.' && *(pszAddExt + strlen (pMgr->GetDP ()->pszAdditionalExt)) == 0)
						break;

					pszAddExt++;
				}

				if (pszAddExt)
					*(pszAddExt-1) = 0;
			}
			strResult = sz;
		}

		if (strResult.empty ())	
			strResult = "index.html";	
	}

	return strResult;
}

int CDownloads_Tasks::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CListCtrlEx::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	m_drop.Register (this);
	
	return 0;
}

void CDownloads_Tasks::CallSelectedDownload()
{
	POSITION pos = GetFirstSelectedItemPosition ();
	if (pos == NULL)
		return;

	vmsDownloadSmartPtr dld = m_vDownloads [GetNextSelectedItem (pos)];

	if (pos == NULL && dld->pMgr->IsDone ())
	{
		OnDldlaunch ();
	}
	else if (pos == NULL && dld->pMgr->IsRunning () && _App.DownloadDialog_Use ())
	{
		if (dld->pdlg)
		{
			dld->pdlg->BringWindowToTop ();
			dld->pdlg->SetFocus ();
		}
		else
		{
			dld->AddRef ();
			_pwndDownloads->PostMessage (WM_DW_CREATEDLDDIALOG, 1, (LPARAM)(fsDownload*)dld);
		}
	}
	else
	{
		OnDldproperties ();
	}
}

void CDownloads_Tasks::SelectDownload(vmsDownloadSmartPtr dld)
{
	int iItem = FindItem (dld);

	if (iItem == -1)
		return;

	POSITION pos = GetFirstSelectedItemPosition ();
	
	while (pos)
		SetItemState (GetNextSelectedItem (pos), 0, LVIS_SELECTED | LVIS_FOCUSED);

	
	SetItemState (iItem, LVIS_FOCUSED | LVIS_SELECTED, LVIS_FOCUSED | LVIS_SELECTED);
	SetSelectionMark (iItem);
	EnsureVisible (iItem, FALSE);
	UpdateActiveDownload (0);
}

void CDownloads_Tasks::OnDldcheckvir() 
{
	POSITION pos = GetFirstSelectedItemPosition ();
	
	while (pos)
	{
		vmsDownloadSmartPtr dld = m_vDownloads [GetNextSelectedItem (pos)];
		if (dld->pMgr->IsDone ())
			_DldsMgr.PerformVirusCheck (dld, FALSE, FALSE);
	}	
}

void CDownloads_Tasks::OnDldfind() 
{
	AfxGetApp ()->m_pMainWnd->PostMessage (WM_COMMAND, ID_FIND);
}

void CDownloads_Tasks::OnDldfindnext() 
{
	AfxGetApp ()->m_pMainWnd->PostMessage (WM_COMMAND, ID_FINDNEXT);
}

void CDownloads_Tasks::LockList()
{
	m_mxAddDel.Lock ();
}

void CDownloads_Tasks::UnlockList()
{
	m_mxAddDel.Unlock ();
}

void CDownloads_Tasks::OnGetdispinfo(NMHDR *pNMHDR, LRESULT *pResult)
{
	LV_DISPINFO* pDispInfo = (LV_DISPINFO*)pNMHDR;
	LV_ITEM* pItem = &(pDispInfo)->item;

	try
	{
		vmsDownloadSmartPtr dld = m_vDownloads [pItem->iItem];

		if (pItem->mask & LVIF_IMAGE)
		{
			pItem->iImage = GetDownloadImage (dld);
			UpdateDownload (dld, FALSE);
		}

		if (pItem->mask & LVIF_TEXT)
		{
			int nSubItem = SubItemToSubItem (pItem->iSubItem);
			if (nSubItem != -1)
				lstrcpy (pItem->pszText, GetDownloadText (dld, nSubItem));		
		}

	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CDownloads_Tasks::OnGetdispinfo " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CDownloads_Tasks::OnGetdispinfo unknown exception");
	}
}

CString CDownloads_Tasks::GetDownloadText(vmsDownloadSmartPtr dld, int nSubItem)
{
	
	if (nSubItem == 0)
	{
		CHAR szFile [10000];	
		GetFileName (dld, szFile);
		if (lstrlen (szFile) > 233)
		{
			szFile [233] = 0;
			lstrcat (szFile, "...");
		}
		return szFile;
	}

	
	if (nSubItem == 1)
	{
		if (dld->pMgr->IsBittorrent () == FALSE && dld->pMgr->GetNumberOfSections () == 0)
			return "";

		UINT64 uSize = dld->pMgr->GetLDFileSize ();

		if (uSize != _UI64_MAX)
		{
			if (dld->pMgr->IsBittorrent ())
			{
				UINT64 nToDownload, nDownloaded;
				dld->pMgr->GetBtDownloadMgr ()->getPartialDownloadProgress (&nToDownload, &nDownloaded);
				if (nToDownload != uSize)
				{
					CString str;
					str.Format ("%s (%s)", (LPCSTR)BytesToString (nToDownload), (LPCSTR)BytesToString (uSize));
					return str;
				}
			}

			return BytesToString (uSize);
		}
		else
			return "?";	
	}

	
	if (nSubItem == 2)
	{
		if (dld->pMgr->IsBittorrent () == FALSE && dld->pMgr->GetNumberOfSections () == 0)
			return "";

		if (dld->pMgr->IsBittorrent () && dld->pMgr->IsReservingDiskSpace ())
		{
			CString str;
			if (dld->pMgr->get_ReservingDiskSpaceProgress () == -1)
				return "RD";
			str.Format ("RD: %d%%", dld->pMgr->get_ReservingDiskSpaceProgress ());
			return str;
		}

		CString str;
		UINT64 uSize = dld->pMgr->GetLDFileSize ();
		UINT64 uDone = dld->pMgr->GetDownloadedBytesCount ();

		if (dld->pMgr->IsBittorrent ())
		{
			UINT64 nToDownload, nDownloaded;
			dld->pMgr->GetBtDownloadMgr ()->getPartialDownloadProgress (&nToDownload, &nDownloaded);
			if (nToDownload != uSize)
			{
				int iPercents = nToDownload ? (int)((double)(INT64)nDownloaded / (INT64)nToDownload * 100) : 100;
				if (iPercents > 100)
					iPercents = 100;
				
				if (_pwndDownloads->IsSizesInBytes () == FALSE)
				{
					float val, val0;
					char szDim [10], szDim0 [10];
					BytesToXBytes (uDone, &val, szDim);
					BytesToXBytes (nDownloaded, &val0, szDim0);
					str.Format ("%d%% [%.*g %s] (%d%% [%.*g %s])", iPercents, val0 > 999 ? 4 : 3, (double)val0, szDim0,
						(int)((double)(INT64)uDone / (INT64)uSize * 100), val > 999 ? 4 : 3, (double)val, szDim);
				}
				else
				{
					CString s = fsBytesToStr (uDone);
					CString s0 = fsBytesToStr (nDownloaded);
					str.Format ("%d%% [%s] (%d%% [%s])", iPercents, (LPCSTR)s0,
						(int)((double)(INT64)uDone / (INT64)uSize * 100), (LPCSTR)s);
				}
				return str;
			}
		}

		if (_pwndDownloads->IsSizesInBytes () == FALSE)
		{
			float val;
			char szDim [10];
			BytesToXBytes (uDone, &val, szDim);
			if (dld->pMgr->IsTp() && dld->pMgr->GetPercentDone () == -1)
				str.Format ("%.*g %s [%s]", val > 999 ? 4 : 3, val, szDim, LS (L_LIVESTREAMING));
			else if (uSize != _UI64_MAX && uSize != 0)
				str.Format ("%d%% [%.*g %s]", (int)((double)(INT64)uDone / (INT64)uSize * 100), val > 999 ? 4 : 3, val, szDim);
			else
				str.Format ("%.*g %s", val > 999 ? 4 : 3, val, szDim);
		}
		else
		{
			CString s = fsBytesToStr (uDone);
			if (uSize != _UI64_MAX)
				str.Format ("%d%% [%s]", (int)((double)(INT64)uDone / (INT64)uSize * 100), s);
			else
				str = s;
		}

		return str;
	}

	
	if (nSubItem == 3)
	{
		if (dld->pMgr->IsRunning () == FALSE)
			return "";
		
		UINT64 uSpeed = dld->pMgr->GetSpeed ();
		if (uSpeed == 0)
			return "";		

		UINT64 uLeft = dld->pMgr->GetBytesLeft ();
		if (uLeft == _UI64_MAX)
			return "";

		if (dld->pMgr->IsBittorrent ())
		{
			UINT64 nToDownload, nDownloaded;
			dld->pMgr->GetBtDownloadMgr ()->getPartialDownloadProgress (&nToDownload, &nDownloaded);
			uLeft = nToDownload - nDownloaded;
		}
		else if (dld->pMgr->IsTp() && dld->pMgr->GetPercentDone () == -1)
			return "";

		return fsTimeInSecondsToStr (UINT (uLeft / uSpeed));
	}

	
	if (nSubItem == 4)
	{
		CString str;
		str.Format ("%d/%d", dld->pMgr->GetDownloadingSectionCount (), 
			dld->pMgr->GetNumberOfSections ());
		return str;
	}

	
	if (nSubItem == 5)
	{
		if (dld->pMgr->IsRunning () == FALSE)
		{
			if (dld->pMgr->IsBittorrent () && dld->pMgr->GetBtDownloadMgr ()->isSeeding ())
			{
				CString str;
				str.Format ("%s/%s; %s/%s", BytesToString (0), LS (L_S),
					BytesToString (dld->pMgr->GetBtDownloadMgr ()->GetUploadSpeed ()), LS (L_S));
				return str;
			}

			return "";
		}

		CString str;

		if (dld->pMgr->IsBittorrent () && dld->pMgr->GetBtDownloadMgr ()->GetUploadSpeed () != 0)
		{
			str.Format ("%s/%s; %s/%s", BytesToString (dld->pMgr->GetSpeed ()), LS (L_S),
				BytesToString (dld->pMgr->GetBtDownloadMgr ()->GetUploadSpeed ()), LS (L_S));
		}
		else
		{
			str.Format ("%s/%s", BytesToString (dld->pMgr->GetSpeed ()), LS (L_S));
		}
		return str;
	}

	
	if (nSubItem == 6)
	{
		CString str = dld->strComment;
		str.Replace ("\r", " ");
		str.Replace ("\n", " ");
		return str;
	}

	
	if (nSubItem == 7)
	{
		char szDate [100], szTime [100];
		FileTimeToStr (&dld->dateAdded, szDate, szTime, TRUE);
		CString str = szDate; str += ", "; str += szTime;
		return str;
	}

	return "";
}

void CDownloads_Tasks::DeleteAllItems()
{
	VirtualView_AllItemsWillBeDeleted ();
	SetItemCount (0);
	m_vDownloads.clear ();
	UpdateActiveDownload (0);
}

void CDownloads_Tasks::SortDownloads()
{
	int N = m_vDownloads.size ();

	if (N < 2)
		return;

	vmsDownloadSmartPtr *pDlds = new vmsDownloadSmartPtr [N];

	int i = 0;
	for (i = 0; i < N; i++)
		pDlds [i] = m_vDownloads [i];

	switch (m_iSortCol)
	{
	case 0:
		qsort (pDlds, N, sizeof (vmsDownloadSmartPtr), _compareDownloadsByFileName);
		break;

	case 1:
		qsort (pDlds, N, sizeof (vmsDownloadSmartPtr), _compareDownloadsByLDFileSize);
		break;

	case 2:
		qsort (pDlds, N, sizeof (vmsDownloadSmartPtr), _compareDownloadsByDownloadedByteCount);
		break;

	case 3:
		qsort (pDlds, N, sizeof (vmsDownloadSmartPtr), _compareDownloadsByTimeRamaining);
		break;

	case 4:
		qsort (pDlds, N, sizeof (vmsDownloadSmartPtr), _compareDownloadsByNumberOfSections);
		break;

	case 5:
		qsort (pDlds, N, sizeof (vmsDownloadSmartPtr), _compareDownloadsBySpeed);
		break;

	case 6:
		qsort (pDlds, N, sizeof (vmsDownloadSmartPtr), _compareDownloadsByComment);
		break;

	case 7:
		qsort (pDlds, N, sizeof (vmsDownloadSmartPtr), _compareDownloadsByDateAdded);
		break;

	default:
		ASSERT (FALSE);
		delete [] pDlds;
		return;
	}

	DLDS_LIST vOld = m_vDownloads;

	m_vDownloads.clear ();

	for (i = 0; i < N; i++)
		m_vDownloads.push_back (pDlds [i]);

	delete [] pDlds;

	_DldsMgr.ReorderDownloads (vOld, m_vDownloads, true);

	RedrawItems (0, GetItemCount ()-1);
}

vmsDownloadSmartPtr CDownloads_Tasks::GetItemData(int nItem)
{
	return m_vDownloads [nItem];
}

void CDownloads_Tasks::OnItemChanged(NM_LISTVIEW *pLV)
{
	if (pLV->uNewState != pLV->uOldState) 
		UpdateActiveDownload (0);
}

void CDownloads_Tasks::OnDldunpack() 
{
	POSITION pos = GetFirstSelectedItemPosition ();
	if (pos == NULL)
		return;

	vmsDownloadSmartPtr dld = m_vDownloads [GetNextSelectedItem (pos)];

	if (dld->pMgr->IsDone () == FALSE)
		return;

	if (dld->pMgr->GetBtDownloadMgr () != NULL &&
			dld->pMgr->GetBtDownloadMgr ()->get_FileCount () > 1)
		return;
        
	CString strArchive = dld->pMgr->get_OutputFilePathName ();

	if (GetFileAttributes (strArchive) == DWORD (-1))
		return;

	CDlg_UnpackSettings dlgS;

	dlgS.m_strDstFolder = strArchive;
	dlgS.m_strDstFolder.Replace ('/', '\\');

	LPCSTR pszE = strrchr (dlgS.m_strDstFolder, '\\');
	if (pszE)
		dlgS.m_strDstFolder.Insert (pszE - dlgS.m_strDstFolder + 1, "_extracted\\");
	dlgS.m_strDstFolder += ".extracted\\";

	if (IDCANCEL == _DlgMgr.DoModal (&dlgS))
		return;

	CDlg_UnpackProgress dlgP;

	dlgP.m_strArchive = strArchive;
	dlgP.m_strDstFolder = dlgS.m_strDstFolder;

	_DlgMgr.DoModal (&dlgP);
}

void CDownloads_Tasks::OnDldmovedown() 
{
	MoveSelectedDownloads (MT_DOWN);
	_DldsMgr.setNeedProcessDownloads ();
}

void CDownloads_Tasks::OnDldmoveup() 
{
	MoveSelectedDownloads (MT_UP);
	_DldsMgr.setNeedProcessDownloads ();
}

void CDownloads_Tasks::MoveSelectedDownloads(vmsMoveType enMT)
{
	if (m_sortMode != LCSM_NONE)
		return;

	DLDS_LIST vDlds;
	fs::list <int> vIndxs;
	
	int nIndxDldPos = -1;
	POSITION pos = GetFirstSelectedItemPosition ();
	while (pos)
	{
		int nItem = GetNextSelectedItem (pos);

		vmsDownloadSmartPtr dld = GetItemData (nItem);
		if (enMT == MT_UP && nItem == 0)
			nIndxDldPos = 0;
		else if (enMT == MT_DOWN && nItem == GetItemCount () - 1)
			nIndxDldPos = nItem;
		else {
			vDlds.push_back (dld);
			vIndxs.add (nItem);
		}
		
		if (nIndxDldPos == -1)
		{
			if (enMT == MT_TOP)
				nIndxDldPos = 0;
			else if (enMT == MT_BOTTOM)
				nIndxDldPos = GetItemCount () - 1;
			else if (enMT == MT_UP)
				nIndxDldPos = nItem - 1;	
			else if (enMT == MT_DOWN && pos == NULL)
				nIndxDldPos = nItem + 1;	
		}
	}

	if (vDlds.size () == 0)
		return;

	vmsDownloadSmartPtr dld;
	if (enMT == MT_TOP)
		dld = _DldsMgr.GetDownload (0);
	else if (enMT == MT_BOTTOM)
		dld = _DldsMgr.GetDownload (_DldsMgr.GetCount () - 1);
	else
		dld = GetItemData (nIndxDldPos);

	_DldsMgr.MoveDownloads (vDlds, dld, enMT == MT_UP || enMT == MT_TOP);

	

	int i;
	for (i = vIndxs.size () - 1; i >= 0; i--)
		m_vDownloads.erase (m_vDownloads.begin () + vIndxs [i]);
	if (enMT == MT_DOWN || enMT == MT_BOTTOM)
		nIndxDldPos -= vDlds.size () - 1;

	for (i = 0; i < (int)vDlds.size (); i++)
		m_vDownloads.insert (m_vDownloads.begin () + nIndxDldPos + i, vDlds [i]);

	
	RedrawItems (0, GetItemCount () - 1);

	pos = GetFirstSelectedItemPosition ();
	
	while (pos)
		SetItemState (GetNextSelectedItem (pos), 0, LVIS_SELECTED | LVIS_FOCUSED);
	EnsureVisible (enMT == MT_UP || enMT == MT_TOP ? nIndxDldPos : nIndxDldPos+vDlds.size ()-1, FALSE);
	for (i = 0; i < (int)vDlds.size (); i++)	
		SetItemState (nIndxDldPos+i, LVIS_FOCUSED | LVIS_SELECTED, LVIS_FOCUSED | LVIS_SELECTED);
}

void CDownloads_Tasks::OnDldcheckintegrity() 
{
	POSITION pos = GetFirstSelectedItemPosition ();
	if (pos == NULL)
		return;

	vmsDownloadSmartPtr dld = m_vDownloads [GetNextSelectedItem (pos)];

	if (dld->pMgr->IsDone () == FALSE)
		return;

	ASSERT (dld->pMgr->GetDownloadMgr () != NULL);
	if (dld->pMgr->GetDownloadMgr () == NULL)
		return;

	LPCSTR pszFile = dld->pMgr->GetDownloadMgr ()->GetDP ()->pszFileName;

	if (GetFileAttributes (pszFile) == DWORD (-1))
		return;

	CDlg_CheckFileIntegrity dlg;
	if (*dld->pMgr->GetDownloadMgr ()->GetDP ()->pszCheckSum)
	{
		dlg.m_strChecksum = dld->pMgr->GetDownloadMgr ()->GetDP ()->pszCheckSum;
		dlg.m_nAlgorithm = LOWORD (dld->pMgr->GetDownloadMgr ()->GetDP ()->dwIntegrityCheckAlgorithm);
		dlg.m_nSHA2Strength = HIWORD (dld->pMgr->GetDownloadMgr ()->GetDP ()->dwIntegrityCheckAlgorithm);
	}
	if (IDCANCEL == _DlgMgr.DoModal (&dlg))
		return;

	SAFE_DELETE_ARRAY (dld->pMgr->GetDownloadMgr ()->GetDP ()->pszCheckSum);
	dld->pMgr->GetDownloadMgr ()->GetDP ()->pszCheckSum = new char [dlg.m_strChecksum.GetLength () + 1];
	lstrcpy (dld->pMgr->GetDownloadMgr ()->GetDP ()->pszCheckSum, dlg.m_strChecksum);
	dld->pMgr->GetDownloadMgr ()->GetDP ()->dwIntegrityCheckAlgorithm = MAKELONG (dlg.m_nAlgorithm, dlg.m_nSHA2Strength);
	dld->pMgr->GetDownloadMgr ()->setDirty();

	CDlg_CheckFileIntegrity_Progress dlg2;
	dlg2.m_enHashAlgorithm = (vmsHashAlgorithm) dlg.m_nAlgorithm;
	dlg2.m_enSHA2Strength = (vmsHash_SHA2Strength) dlg.m_nSHA2Strength;
	dlg2.m_strFile = pszFile;
	dlg2.m_strValidHashResult = dlg.m_strChecksum;
	if (IDCANCEL == _DlgMgr.DoModal (&dlg2))
		return;

	if (dlg2.is_CheckingSucceeded () == false || 
			_App.View_DontShowHashCheckResultIfOK () == FALSE)
	{
		CDlg_CheckFileIntegrity_Result dlg3;
		dlg3.m_bResultOK = dlg2.is_CheckingSucceeded ();
		char sz [MY_MAX_PATH];
		fsGetFileName (dld->pMgr->GetDownloadMgr ()->GetDP ()->pszFileName, sz);
		dlg3.m_strFileName = sz;
		dlg3.m_strUrl = dld->pMgr->GetDownloadMgr ()->GetDownloader ()->get_URL ();
		dlg3.m_strValidHash = dlg.m_strChecksum;
		dlg3.m_strResultHash = dlg2.m_strHashResult;
		if (IDC_RESTARTDOWNLOAD == _DlgMgr.DoModal (&dlg3))
			_pwndDownloads->RestartDownload (dld, TRUE);
	}
}

void CDownloads_Tasks::OnDldmovetofolder() 
{
	DLDS_LIST vDlds;
	POSITION pos = GetFirstSelectedItemPosition ();
	while (pos)
	{
		int iItem = GetNextSelectedItem (pos);
		vmsDownloadSmartPtr dld = m_vDownloads [iItem];
		vDlds.push_back (dld);
	}

	if (vDlds.size () == 0)
		return;

	CFolderBrowser *fb = CFolderBrowser::Create (LS (L_CHOOSEOUTFOLDER), 
		_App.View_LastDldMoveToFolder (), NULL, this);
	if (fb == NULL)
		return;

	_App.View_LastDldMoveToFolder (fb->GetPath ());

	for (size_t i = 0; i < vDlds.size (); i++)
		vDlds [i]->pMgr->MoveToFolder (fb->GetPath ());
}

void CDownloads_Tasks::OnDldmovebottom() 
{
	MoveSelectedDownloads (MT_BOTTOM);
	_DldsMgr.setNeedProcessDownloads ();
}

void CDownloads_Tasks::OnDldmovetop() 
{
	MoveSelectedDownloads (MT_TOP);	
	_DldsMgr.setNeedProcessDownloads ();
}

void CDownloads_Tasks::OnDldschedulestop() 
{
	ScheduleSelectedDlds (FALSE);
}

void CDownloads_Tasks::ScheduleSelectedDlds(BOOL bStart)
{
	POSITION pos = GetFirstSelectedItemPosition ();
	DLDS_LIST vDlds;
	fsScheduleMgr *mgr = _pwndScheduler->GetMgr ();

	
	while (pos)
	{
		int iItem = GetNextSelectedItem (pos);
		vmsDownloadSmartPtr dld = m_vDownloads [iItem];
		if (dld->pMgr->IsDone () == FALSE)
			vDlds.push_back (dld);
	}

	if (vDlds.size () == 0)
		return;

	
	fsScheduleEx schScheduleParam;
	fsSchedule& task = schScheduleParam.schTask;
	
	fsSchedule* pTask = mgr->GetScheduleDLTask (vDlds, bStart);
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

	CScheduleSheet sheet (LS (bStart ? L_SCHEDULE_DLDSTART : L_SCHEDULE_DLDSTOP), this);
	sheet.Init (pTask, FALSE);
	_DlgMgr.OnDoModal (&sheet);	
	UINT uIDRet = sheet.DoModal ();
	_DlgMgr.OnEndDialog (&sheet);

	if (uIDRet == IDOK)
	{
		if (bCreate)	
		{
			 
			pTask->wts.enType = bStart ? WTS_STARTDOWNLOAD : WTS_STOPDOWNLOAD;
			fsnew1 (pTask->wts.dlds.pvIDs, fs::list <UINT>);
			pTask->wts.dlds.dwFlags = 0;
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
         
    SetFocus ();
}

void CDownloads_Tasks::BeginAddDownloads()
{
	LockList ();
	m_bAddingDownloads = true;
}

void CDownloads_Tasks::EndAddDownloads()
{
	m_bAddingDownloads = false;
	UnlockList ();
	SetItemCountEx (m_vDownloads.size (), LVSICF_NOINVALIDATEALL);
}

void CDownloads_Tasks::UpdateDownload(size_t nIndex, BOOL bRedraw)
{
	COLORREF clr;

	if (m_vDownloads [nIndex]->pMgr->GetBtDownloadMgr ())
	{
		clr = RGB (0, 100, 100); 
	}
	else if (m_vDownloads [nIndex]->pMgr->GetDownloadMgr () && 
		m_vDownloads [nIndex]->pMgr->GetDownloadMgr ()->GetDownloader ()->is_WasAccessedAtLeastOnce ())
	{
		switch (m_vDownloads [nIndex]->pMgr->IsResumeSupported ())
		{
		case RST_NONE:
			clr = RGB (160, 0, 0);
			break;

		case RST_PRESENT:
			clr = RGB (0, 100, 0);
			break;

		case RST_UNKNOWN:
			clr = RGB (150, 150, 0);
			break;

		default:
			clr = RGB (0, 0, 0);
			break;
		}
	}
	else
	{
		ASSERT (m_vDownloads [nIndex]->pMgr->GetDownloadMgr () != NULL ||
			m_vDownloads [nIndex]->pMgr->GetBtDownloadMgr () != NULL ||
			m_vDownloads [nIndex]->pMgr->GetTpDownloadMgr () != NULL);
		clr = RGB (0, 0, 0);
	}

	SetItemColor (nIndex, clr, FALSE);

	if (bRedraw)
		RedrawItems (nIndex, nIndex);
}

void CDownloads_Tasks::OnDldgrantbandwidthfordld() 
{
	POSITION pos = GetFirstSelectedItemPosition ();
	if (pos == NULL)
		return;

	vmsDownloadSmartPtr dld = m_vDownloads [GetNextSelectedItem (pos)];
	if (dld == _DldsMgr.get_HighestPriorityDownload ())
		dld = NULL;

	_DldsMgr.set_HighestPriorityDownload (dld);
}

void CDownloads_Tasks::OnDldshowprogressdlg() 
{
	POSITION pos = GetFirstSelectedItemPosition ();

	while (pos)
	{
		vmsDownloadSmartPtr dld = m_vDownloads [GetNextSelectedItem (pos)];

		if (dld->pMgr->IsRunning ())
		{
			if (dld->pdlg == NULL)
			{
				dld->pdlg = new CDlg_Download;
				dld->pdlg->Create (dld);
			}
			dld->pdlg->ShowWindow (SW_SHOW);
			dld->pdlg->BringWindowToTop ();
			dld->pdlg->SetFocus ();
		}
	}
}

void CDownloads_Tasks::OnDldconvert() 
{
	_pwndDownloads->m_wndDownloads.m_info.m_video.Convert ();	
}

void CDownloads_Tasks::OnDldenableseeding() 
{
	POSITION pos = GetFirstSelectedItemPosition ();
	while (pos)
	{
		vmsDownloadSmartPtr dld = m_vDownloads [GetNextSelectedItem (pos)];
		if (dld->pMgr->IsBittorrent ())
		{
			dld->pMgr->GetBtDownloadMgr ()->EnableSeeding (!m_bHasEnableSeedingDlds);
			UpdateDownload (dld, TRUE);
		}
	}
}

int CDownloads_Tasks::_compareDownloadsByFileName(LPCVOID p1, LPCVOID p2)
{
	vmsDownloadSmartPtr *a1 = (vmsDownloadSmartPtr*)p1;
	vmsDownloadSmartPtr *a2 = (vmsDownloadSmartPtr*)p2;
	char szFile1 [10000];  char szFile2 [10000];
	GetFileName (*a1, szFile1);
	GetFileName (*a2, szFile2);
	return lstrcmpi (szFile1, szFile2);
}

int CDownloads_Tasks::_compareDownloadsByLDFileSize(LPCVOID p1, LPCVOID p2)
{
	vmsDownloadSmartPtr *a1 = (vmsDownloadSmartPtr*)p1;
	vmsDownloadSmartPtr *a2 = (vmsDownloadSmartPtr*)p2;

	UINT64 size1;
	UINT64 size2;
	size1 = (*a1)->pMgr->GetLDFileSize ();
	size2 = (*a2)->pMgr->GetLDFileSize ();
	
	if (size1 == _UI64_MAX)
		return size2 == _UI64_MAX ? 0 : 1;
	
	if (size2 == _UI64_MAX)
		return size1 == _UI64_MAX ? 0 : -1;
	
	if (size1 == size2)
		return 0;
	
	return size1 > size2 ? -1 : 1;
}

int CDownloads_Tasks::_compareDownloadsByDownloadedByteCount(LPCVOID p1, LPCVOID p2)
{
	vmsDownloadSmartPtr *a1 = (vmsDownloadSmartPtr*)p1;
	vmsDownloadSmartPtr *a2 = (vmsDownloadSmartPtr*)p2;

	UINT64 done1;
	UINT64 done2;
	done1 = (*a1)->pMgr->GetDownloadedBytesCount ();
	done2 = (*a2)->pMgr->GetDownloadedBytesCount ();
	
	if (done1 == done2)
		return 0;
	
	return done1 > done2 ? -1 : 1;
}

int CDownloads_Tasks::_compareDownloadsByTimeRamaining(LPCVOID p1, LPCVOID p2)
{
	vmsDownloadSmartPtr *a1 = (vmsDownloadSmartPtr*)p1;
	vmsDownloadSmartPtr *a2 = (vmsDownloadSmartPtr*)p2;

	UINT64 size1;
	UINT64 size2;
	size1 = (*a1)->pMgr->GetLDFileSize ();
	size2 = (*a2)->pMgr->GetLDFileSize ();
	
	UINT speed1, speed2;
	speed1 = (*a1)->pMgr->GetSpeed ();
	speed2 = (*a2)->pMgr->GetSpeed ();
	
	if (speed1 == 0 || size1 == _UI64_MAX)
		return speed2 == 0 || size2 == _UI64_MAX ? 0 : 1;
	
	if (speed2 == 0 || size2 == _UI64_MAX)
		return speed1 == 0 || size1 == _UI64_MAX ? 0 : -1;
	
	UINT64 pr1, pr2;
	pr1 = (*a1)->pMgr->GetBytesLeft () / speed1;
	pr2 = (*a2)->pMgr->GetBytesLeft () / speed2;
	
	if (pr1 == pr2)
		return 0;
	
	return pr1 < pr2 ? 1 : -1;
}

int CDownloads_Tasks::_compareDownloadsByNumberOfSections(LPCVOID p1, LPCVOID p2)
{
	vmsDownloadSmartPtr *a1 = (vmsDownloadSmartPtr*)p1;
	vmsDownloadSmartPtr *a2 = (vmsDownloadSmartPtr*)p2;

	UINT sects1, sects2;
	
	sects1 = (*a1)->pMgr->GetNumberOfSections ();
	sects2 = (*a2)->pMgr->GetNumberOfSections ();
	
	if (sects1 == sects2)
	{
		sects1 = (*a1)->pMgr->GetDownloadingSectionCount ();
		sects2 = (*a2)->pMgr->GetDownloadingSectionCount ();
		
		if (sects1 == sects2)
			return 0;
		
		return sects1 > sects2 ? -1 : 1;
	}
	
	return sects1 > sects2 ? -1 : 1;
}

int CDownloads_Tasks::_compareDownloadsBySpeed(LPCVOID p1, LPCVOID p2)
{
	vmsDownloadSmartPtr *a1 = (vmsDownloadSmartPtr*)p1;
	vmsDownloadSmartPtr *a2 = (vmsDownloadSmartPtr*)p2;

	UINT speed1, speed2;
	
	speed1 = (*a1)->pMgr->GetSpeed ();
	speed2 = (*a2)->pMgr->GetSpeed ();
	
	if (speed1 == speed2)
		return 0;
	
	return speed1 > speed2 ? -1 : 1;
}

int CDownloads_Tasks::_compareDownloadsByComment(LPCVOID p1, LPCVOID p2)
{
	vmsDownloadSmartPtr *a1 = (vmsDownloadSmartPtr*)p1;
	vmsDownloadSmartPtr *a2 = (vmsDownloadSmartPtr*)p2;

	return lstrcmpi ((*a1)->strComment, (*a2)->strComment);
}

int CDownloads_Tasks::_compareDownloadsByDateAdded(LPCVOID p1, LPCVOID p2)
{
	vmsDownloadSmartPtr *a1 = (vmsDownloadSmartPtr*)p1;
	vmsDownloadSmartPtr *a2 = (vmsDownloadSmartPtr*)p2;

	return CompareFileTime (&(*a1)->dateAdded, &(*a2)->dateAdded);
}

void CDownloads_Tasks::OnDldcreateTP() 
{
	m_pDownloadsWnd->OnTpDownloadCreate ();
	SetFocus ();
}