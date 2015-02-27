/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Downloads_Groups.h"
#include "DownloadsWnd.h"
#include "GroupDlg.h"
#include "ShedulerWnd.h"
#include "system.h"
#include "DlgDeletedProperties.h"
#include "DlgDownloadsHistory.h"
#include "DlgT1ToT2.h"
#include "FolderBrowser.h"
#include "vmsLogger.h"

extern CShedulerWnd* _pwndScheduler;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CDownloadsWnd* _pwndDownloads;

CDownloads_Groups::CDownloads_Groups()
{
	m_filterLastWeek.SetPeriod (7);
	m_filterLastMonth.SetPeriod (31);
	FILETIME time;
	ZeroMemory (&time, sizeof (time));
	m_filterCustomHist.SetTimeRange (time, time);

	m_hContextMenuItem = NULL;
	m_cTotalDownloads = 0;
}

CDownloads_Groups::~CDownloads_Groups()
{
}

BEGIN_MESSAGE_MAP(CDownloads_Groups, CTreeCtrl)
	//{{AFX_MSG_MAP(CDownloads_Groups)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, OnSelchanged)
	ON_NOTIFY_REFLECT(NM_RCLICK, OnRclick)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_GRPDELETE, OnGrpdelete)
	ON_COMMAND(ID_GRPPROPERTIES, OnGrpproperties)
	ON_COMMAND(ID_GRPSTARTALL, OnGrpstartall)
	ON_COMMAND(ID_GRPSTOPALL, OnGrpstopall)
	ON_COMMAND(ID_GRPCREATE, OnGrpcreate)
	ON_COMMAND(ID_GRPDELETEALL, OnGrpdeleteall)
	ON_COMMAND(ID_GRPDELETEALLSUCCESSFUL, OnGrpdeleteallsuccessful)
	ON_COMMAND(ID_OPENGROUPFOLDER, OnOpengroupfolder)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_DRAWITEM()
	ON_WM_MEASUREITEM()
	ON_NOTIFY_REFLECT(TVN_KEYDOWN, OnKeydown)
	ON_COMMAND(ID_DELETED_CLEAR, OnDeletedClear)
	ON_COMMAND(ID_DELETED_PROPERTIES, OnDeletedProperties)
	ON_COMMAND(ID_HISTORY_CLEAR, OnHistoryClear)
	ON_COMMAND(ID_HISTORY_SETTINGS, OnHistorySettings)
	ON_NOTIFY_REFLECT(NM_CLICK, OnClick)
	ON_COMMAND(ID_GRPSETROOTFOLDER, OnSetGroupsRootFolder)
	ON_WM_TIMER()
	ON_COMMAND(ID_GRPDELETEALLDEADDLDS, OnGrpdeletealldeaddlds)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDownloads_Groups::Create(CWnd *pParent)
{
	CRect rc (0, 0, 150, 50);

	if (FALSE == CTreeCtrl::Create (TVS_HASLINES | TVS_HASBUTTONS | TVS_LINESATROOT | TVS_SHOWSELALWAYS, rc, pParent, 0x9876))
		return FALSE;

	CBitmap bmpg;
	bmpg.Attach (SBMP (IDB_GROUPS));
	m_images.Create (16, 15, ILC_COLOR24 | ILC_MASK, 8, 2);
	m_images.Add (&bmpg, RGB (255, 0, 255));
	SetImageList (&m_images, TVSIL_NORMAL);

	m_hAllGroups = InsertItem (TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_STATE | TVIF_TEXT, "", 0, 0,
		TVIS_BOLD | TVIS_EXPANDED, TVIS_BOLD | TVIS_EXPANDED, 0, TVI_ROOT, TVI_LAST);

	
	
	SetItemData (m_hAllGroups, (ULONG) &m_filterAll);

	InsertGroups ();
	InsertFilters ();
	InsertHistory ();
	InsertDeleted ();

	switch (_pwndDownloads->Get_DWWN ())
	{
		case DWWN_LISTOFDOWNLOADS:
			int nId; nId = _App.View_DownloadsGroups_SelectedFilterId ();
			switch (nId)
			{
			case -2:
				SelectItem (m_hTasks);
				break;

			case -1: 
				SelectItem (m_hAllGroups);
				break;

			default:
				vmsDownloadsGroupSmartPtr pGrp;
				pGrp = _DldsGrps.FindGroup (nId);
				if (pGrp != NULL)
					SetGroupFilter (pGrp);
				else
					SelectItem (m_hTasks);
				break;
			}
			break;

		case DWWN_HISTORY:
			SelectItem (m_hHistory);
			Expand (m_hHistory, TVE_EXPAND);
			break;

		case DWWN_DELETED:
			SelectItem (m_hDeleted);
			break;
	}

	m_odmenuImages.Create (16, 15, ILC_COLOR24 | ILC_MASK, 5, 2);
	CBitmap bmp;
	bmp.Attach (SBMP (IDB_GROUPSMENU));
	m_odmenuImages.Add (&bmp, RGB (255, 0, 255));

	CBitmap bmp1; bmp1.Attach (SBMP (IDB_GROUPSMENU_D));
	BITMAP bm; bmp1.GetBitmap (&bm);
	m_odmenuDImages.Create (16, bm.bmHeight, ILC_COLOR24|ILC_MASK, 3, 1);
	m_odmenuDImages.Add (&bmp1, RGB (255, 0, 255));
	m_odmenu.SetImageList (&m_odmenuImages, &m_odmenuDImages);

	ApplyLanguage ();
	
	ShowWindow (SW_SHOW);

	SetTimer (1, 1000, NULL);

	return TRUE;
}

void CDownloads_Groups::InsertGroups()
{
	
	for (size_t i = 0; i < m_vGroups.size (); i++)
		delete m_vGroups [i].pGroupFilter;
	m_vGroups.clear ();

	InsertGroups_tree (_DldsGrps.GetGroupsTree (), m_hAllGroups);
}

void CDownloads_Groups::OnSelchanged(NMHDR*, LRESULT* pResult) 
{
	
	HTREEITEM hItem = GetSelectedItem ();
	HTREEITEM hParent = GetParentItem (hItem);

	if (hItem == m_hHistory || hParent == m_hHistory)
	{
		if (hItem == m_hHistCustom)
			CustomizeHistoryFilter (); 

		_pwndDownloads->Set_DWWN (DWWN_HISTORY);
		fsDldHistRecFilter* f = (fsDldHistRecFilter*) GetItemData (hItem);
		_pwndDownloads->m_wndHistory.ApplyFilter (f);
	}
	else if (hItem == m_hDeleted)
	{
		_pwndDownloads->Set_DWWN (DWWN_DELETED);
	}
	else
	{
		
		fsDldFilter* filter = (fsDldFilter*) GetItemData (hItem);
		_pwndDownloads->Set_DWWN (DWWN_LISTOFDOWNLOADS);
		
		if (filter->GetType () == DFT_GROUP)
			_App.View_DownloadsGroups_SelectedFilterId (((fsDldGroupFilter*)filter)->GetGroup ()->nId);
		else if (hItem == m_hTasks)
			_App.View_DownloadsGroups_SelectedFilterId (-2);
		else if (hItem == m_hAllGroups)
			_App.View_DownloadsGroups_SelectedFilterId (-1);
		
		_pwndDownloads->FilterDownloads (filter);	
	}

	*pResult = 0;
}

void CDownloads_Groups::OnRclick(NMHDR* , LRESULT* pResult) 
{
	HTREEITEM hItem;

	hItem = HitTest (CPoint (m_rbX, m_rbY)); 

	if (hItem)
		SelectItem (hItem);	
		
	ShowGrpContextMenu (hItem, FALSE);	

	*pResult = 0;
}

void CDownloads_Groups::OnRButtonDown(UINT nFlags, CPoint point) 
{
	m_rbX = point.x;
	m_rbY = point.y;
	
	CTreeCtrl::OnRButtonDown(nFlags, point);
}

void CDownloads_Groups::OnGrpdelete() 
{
	HTREEITEM hItem = GetSelectedItem ();

	
	if (hItem == NULL || hItem == m_hOther)
		return;	

	
	if (IsGroupItem (hItem) == FALSE)
		return;

	fsDldGroupFilter *filter = (fsDldGroupFilter*) GetItemData (hItem);

	
	if (m_pWndDownloads->DeleteGroup (filter->GetGroup ()) == FALSE)
	{
		SetFocus ();
		return;
	}

	SetFocus ();

	SelectItem (GetParentItem (hItem));
	
	
	DeleteItem (hItem);
}

void CDownloads_Groups::OnGrpproperties() 
{
	HTREEITEM hGroup = GetSelectedItem ();
	fsDldFilter *filter = (fsDldFilter*) GetItemData (hGroup);
	if (filter == NULL || filter->GetType () != DFT_GROUP)	
		return;

	fsDldGroupFilter *f = (fsDldGroupFilter*) filter;

	CGroupDlg dlg (f->GetGroup (), NULL, this);
	_DlgMgr.DoModal (&dlg);

	SetFocus ();
}

void CDownloads_Groups::OnGrpstartall() 
{
	m_pWndDownloads->StartDownloadsInList ();
}

void CDownloads_Groups::OnGrpstopall() 
{
	m_pWndDownloads->StopDownloadsInList ();
}

void CDownloads_Groups::OnGrpcreate() 
{
	HTREEITEM hGroup = m_hContextMenuItem;
	vmsDownloadsGroupSmartPtr pParentGroup;

	if (hGroup && IsGroupItem (hGroup))
	{
		fsDldFilter *filter = (fsDldFilter*) GetItemData (hGroup);
		if (filter == NULL || filter->GetType () != DFT_GROUP)	
			return; 

		fsDldGroupFilter *f = (fsDldGroupFilter*) filter;
		pParentGroup = f->GetGroup ();
	}

	CGroupDlg dlg (NULL, pParentGroup, this);

   	_DlgMgr.DoModal (&dlg);
}

void CDownloads_Groups::OnGrpdeleteall() 
{
	_pwndDownloads->DeleteDownloadsInList ();
}

void CDownloads_Groups::OnGrpdeleteallsuccessful() 
{
	_pwndDownloads->DeleteCompletedDownloadsInList ();
}

void CDownloads_Groups::OnOpengroupfolder() 
{
	fsDldGroupFilter *filter = (fsDldGroupFilter*) GetItemData (GetSelectedItem ());

	CString str = filter->GetGroup ()->strOutFolder;
	str.Replace ("%sdrive%", CString (vmsGetExeDriveLetter ()) + ":");

	char sz [MY_MAX_PATH];
	lstrcpy (sz, str);

	
	
	
	
	
	
	
	while (sz [2] != 0 && GetFileAttributes (sz) == DWORD (-1))
	{
		LPSTR psz = strrchr (sz, '\\');
		if (psz)
			*psz = 0;
		else
			return;
	}

	if (sz [2] != 0)
		ShellExecute (::GetDesktopWindow (), "explore", sz, NULL, NULL, SW_SHOW);
}

void CDownloads_Groups::InsertFilters()
{
	for (size_t i = 0; i < m_vStateFilters.size (); i++)
		delete m_vStateFilters [i];
	m_vStateFilters.clear ();

	
	m_hFilters = InsertItem (TVIF_IMAGE  | TVIF_SELECTEDIMAGE | TVIF_STATE | TVIF_TEXT, LS (L_FILTERS), 0, 0,
		TVIS_BOLD | TVIS_EXPANDED, TVIS_BOLD | TVIS_EXPANDED, 0, TVI_ROOT, TVI_LAST);

	SetItemData (m_hFilters, (ULONG) &m_filterAll);

	
	m_hTasks = InsertItem (LS (L_TASKS), 1, 1, TVI_ROOT, TVI_FIRST);
	SetItemData (m_hTasks, (ULONG) &m_filterTasks);

	
	m_hCompleted = InsertItem (LS (L_COMPLETED), 2, 2, m_hFilters, TVI_LAST);
	fsDldDoneFilter* f1 = new fsDldDoneFilter;
	m_vStateFilters.push_back (f1);
	SetItemData (m_hCompleted, (ULONG) m_vStateFilters [m_vStateFilters.size ()-1]);

	
	m_hInProgress = InsertItem (LS (L_INPROGRESS), 3, 3, m_hFilters, TVI_LAST);
	fsDldRunningFilter* f2 = new fsDldRunningFilter;
	m_vStateFilters.push_back (f2);
	SetItemData (m_hInProgress, (ULONG) m_vStateFilters [m_vStateFilters.size ()-1]);

	
	m_hStopped = InsertItem (LS (L_STOPPED), 4, 4, m_hFilters, TVI_LAST);
	fsDldStoppedFilter *f3 = new fsDldStoppedFilter;
	m_vStateFilters.push_back (f3);
	SetItemData (m_hStopped, (ULONG) m_vStateFilters [m_vStateFilters.size ()-1]);

	
	m_hScheduled = InsertItem (LS (L_SCHEDULED), 5, 5, m_hFilters, TVI_LAST);
	fsDldScheduledFilter *f4 = new fsDldScheduledFilter;
	m_vStateFilters.push_back (f4);
	SetItemData (m_hScheduled, (ULONG) m_vStateFilters [m_vStateFilters.size ()-1]);
}

void CDownloads_Groups::ApplyNotGroupFilterForDownload(vmsDownloadSmartPtr dld)
{
	HTREEITEM hItem = GetSelectedItem ();
	if (hItem == NULL)
		return;

	if (hItem == m_hTasks || GetParentItem (hItem) == m_hFilters)
	{
		CDownloads_Tasks* tasks = &_pwndDownloads->m_wndDownloads.m_tasks;
		fsDldFilter *filter = (fsDldFilter*) GetItemData (hItem);
		if (filter->IsSatisfies (dld))
			tasks->AddDownload (dld);
		else
			tasks->DeleteDownload (dld);
	}
}

void CDownloads_Groups::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	HTREEITEM hItem;

	hItem = HitTest (point); 

	if (hItem)
	{
		if (IsGroupItem (hItem))
		{
			SelectItem (hItem);
			OnGrpproperties ();
			return;
		}
		else if (hItem == m_hDeleted)
		{
			SelectItem (hItem);
			OnDeletedProperties ();
			return;
		}
	}
	
	CTreeCtrl::OnLButtonDblClk(nFlags, point);
}

void CDownloads_Groups::OnDrawItem(int , LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	m_odmenu.OnDrawItem (lpDrawItemStruct);
}

void CDownloads_Groups::OnMeasureItem(int , LPMEASUREITEMSTRUCT lpMeasureItemStruct) 
{
	m_odmenu.OnMeasureItem (lpMeasureItemStruct);
}

void CDownloads_Groups::ApplyLanguage()
{
	CString str;
	if (m_cTotalDownloads)
		str.Format ("%s (%d)", LS (L_ALLDLDS), m_cTotalDownloads);
	else
		str = LS (L_ALLDLDS);
	SetItemText (m_hAllGroups, str);

	vmsDownloadsGroupSmartPtr pGroup = _DldsGrps.FindGroup (GRP_OTHER_ID);
	if (pGroup->cDownloads)
		str.Format ("%s (%d)", LS (L_OTHER), pGroup->cDownloads);
	else
		str = LS (L_OTHER);
	SetItemText (m_hOther, str);

	SetItemText (m_hFilters, LS (L_FILTERS));
	SetItemText (m_hCompleted, LS (L_COMPLETED));
	SetItemText (m_hTasks, LS (L_TASKS));
	SetItemText (m_hInProgress, LS (L_INPROGRESS));
	SetItemText (m_hScheduled, LS (L_SCHEDULED));
	SetItemText (m_hStopped, LS (L_STOPPED));

	SetItemText (m_hHistory, LS (L_HISTORY));
	SetItemText (m_hToday, LS (L_TODAY));
	SetItemText (m_hYesterday, LS (L_YESTERDAY));
	SetItemText (m_hLastWeek, LS (L_LASTWEEK));
	SetItemText (m_hLastMonth, LS (L_LASTMONTH));
	SetItemText (m_hHistCustom, LS (L_CUSTOMttt));

	SetItemText (m_hDeleted, LS (L_DELETED));
}

void CDownloads_Groups::ApplyLanguageToMenu(CMenu *menu)
{
	menu->ModifyMenu (ID_GRPCREATE, MF_BYCOMMAND|MF_STRING, ID_GRPCREATE, LS (L_CREATEGRP));
	
	CString str = LS (L_DELGRP); str += "\tDel";
	menu->ModifyMenu (ID_GRPDELETE, MF_BYCOMMAND|MF_STRING, ID_GRPDELETE, str);

	menu->ModifyMenu (ID_GRPSTARTALL, MF_BYCOMMAND|MF_STRING, ID_GRPSTARTALL, LS (L_STARTALLDLDS));
	menu->ModifyMenu (ID_GRPSTOPALL, MF_BYCOMMAND|MF_STRING, ID_GRPSTOPALL, LS (L_STOPALLDLDS));
	menu->ModifyMenu (ID_GRPDELETEALL, MF_BYCOMMAND|MF_STRING, ID_GRPDELETEALL, LS (L_DELETEALLDLDS));
	menu->ModifyMenu (ID_GRPDELETEALLSUCCESSFUL, MF_BYCOMMAND|MF_STRING, ID_GRPDELETEALLSUCCESSFUL, LS (L_DELSUCCDLDS));
	menu->ModifyMenu (ID_GRPDELETEALLDEADDLDS, MF_BYCOMMAND|MF_STRING, ID_GRPDELETEALLDEADDLDS, LS (L_DELDEADDLDS));
	menu->ModifyMenu (ID_OPENGROUPFOLDER, MF_BYCOMMAND|MF_STRING, ID_OPENGROUPFOLDER, LS (L_OPENGRPFOLDER));

	str = LS (L_GRPPROP); str += "\tEnter";
	menu->ModifyMenu (ID_GRPPROPERTIES, MF_BYCOMMAND|MF_STRING, ID_GRPPROPERTIES, str);
}

void CDownloads_Groups::OnKeydown(NMHDR* pNMHDR, LRESULT* pResult) 
{
	TV_KEYDOWN* pTVKeyDown = (TV_KEYDOWN*)pNMHDR;

	HTREEITEM hItem = GetSelectedItem ();
	
	switch (pTVKeyDown->wVKey)
	{
		case VK_DELETE:
			if (hItem)
			{
				if (hItem == m_hDeleted)
					OnDeletedClear ();
				else if (hItem == m_hHistory || GetParentItem (hItem) == m_hHistory)
					OnHistoryClear ();
				else if (IsGroupItem (hItem))
					OnGrpdelete ();
			}
			break;

		case VK_RETURN:
			if (hItem)
			{
				if (hItem == m_hHistory)
					OnHistorySettings ();
				else if (hItem == m_hDeleted)
					OnDeletedProperties ();
				else if (IsGroupItem (hItem))
					OnGrpproperties ();
			}
			
			break;

		case VK_APPS:
			ShowGrpContextMenu ();
			break;

		case VK_TAB:
			switch (_pwndDownloads->Get_DWWN ())
			{
				case DWWN_LISTOFDOWNLOADS:
					_pwndDownloads->m_wndDownloads.m_tasks.SetFocus ();
					break;

				case DWWN_HISTORY:
					_pwndDownloads->m_wndHistory.SetFocus ();
					break;

				case DWWN_DELETED:
					_pwndDownloads->m_wndDeleted.SetFocus ();
					break;
			}
			break;
	}
	
	*pResult = 0;
}

void CDownloads_Groups::ShowGrpContextMenu(HTREEITEM hItem, BOOL bAutoDetect)
{
	if (bAutoDetect)	
	{
		hItem = GetSelectedItem ();
		if (hItem)
		{
			RECT rc;
			GetItemRect (hItem, &rc, TRUE);
			m_rbX = rc.left;
			m_rbY = rc.top;
		}
	}

	m_hContextMenuItem = hItem;

	if (hItem)
	{
		if (hItem == m_hDeleted)
		{
			ShowDeletedContextMenu ();
			return;
		}

		if (hItem == m_hHistory || GetParentItem (hItem) == m_hHistory)
		{
			ShowHistoryContextMenu ();
			return;
		}
	}

	CMenu menu;
	menu.LoadMenu (IDM_GROUP);
	CMenu *pPopup = menu.GetSubMenu (0);

	ApplyLanguageToMenu (pPopup);

	pPopup->SetDefaultItem (ID_GRPPROPERTIES);

	if (hItem)	
	{
		
		
		if (hItem == m_hAllGroups || IsGroupItem (hItem))
		{
			if (hItem == m_hAllGroups)
			{
				pPopup->EnableMenuItem (ID_GRPDELETE, MF_BYCOMMAND | MF_GRAYED);
				pPopup->EnableMenuItem (ID_OPENGROUPFOLDER, MF_BYCOMMAND | MF_GRAYED);
				pPopup->ModifyMenu (ID_GRPPROPERTIES, MF_BYCOMMAND, ID_GRPSETROOTFOLDER, LS (L_SETGRPROOTFOLDER));
			}

			if (hItem == m_hOther)
			{
				pPopup->EnableMenuItem (ID_GRPDELETE, MF_BYCOMMAND | MF_GRAYED);
			}
		}
		else
		{
			pPopup->EnableMenuItem (ID_GRPPROPERTIES, MF_BYCOMMAND | MF_GRAYED);
			pPopup->EnableMenuItem (ID_GRPDELETE, MF_BYCOMMAND | MF_GRAYED);
			pPopup->EnableMenuItem (ID_OPENGROUPFOLDER, MF_BYCOMMAND | MF_GRAYED);
		
			if (hItem != m_hFilters && hItem != m_hCompleted && hItem != m_hAllGroups)
			{
				pPopup->EnableMenuItem (ID_GRPDELETEALLSUCCESSFUL, MF_BYCOMMAND | MF_GRAYED);
				pPopup->EnableMenuItem (ID_GRPDELETEALLDEADDLDS, MF_BYCOMMAND | MF_GRAYED);
			}
			else if (hItem == m_hCompleted)
			{
				pPopup->EnableMenuItem (ID_GRPSTARTALL, MF_BYCOMMAND | MF_GRAYED);
				pPopup->EnableMenuItem (ID_GRPSTOPALL, MF_BYCOMMAND | MF_GRAYED);
				pPopup->EnableMenuItem (ID_GRPDELETEALL, MF_BYCOMMAND | MF_GRAYED);
			}	
		}
	}
	else  
	{
		

		pPopup->EnableMenuItem (ID_GRPPROPERTIES, MF_BYCOMMAND | MF_GRAYED);
		pPopup->EnableMenuItem (ID_GRPDELETE, MF_BYCOMMAND | MF_GRAYED);
		pPopup->EnableMenuItem (ID_OPENGROUPFOLDER, MF_BYCOMMAND | MF_GRAYED);
		pPopup->EnableMenuItem (ID_GRPSTARTALL, MF_BYCOMMAND | MF_GRAYED);
		pPopup->EnableMenuItem (ID_GRPSTOPALL, MF_BYCOMMAND | MF_GRAYED);
		pPopup->EnableMenuItem (ID_GRPDELETEALL, MF_BYCOMMAND | MF_GRAYED);
		pPopup->EnableMenuItem (ID_GRPDELETEALLSUCCESSFUL, MF_BYCOMMAND | MF_GRAYED);
		pPopup->EnableMenuItem (ID_GRPDELETEALLDEADDLDS, MF_BYCOMMAND | MF_GRAYED);
	}

	CPoint pt (m_rbX, m_rbY);
	ClientToScreen (&pt);

	m_odmenu.Attach (&menu, FALSE);

	fsSetImage images [] =
	{
		fsSetImage (ID_GRPCREATE, 0),
		fsSetImage (ID_GRPDELETE, 1),
		fsSetImage (ID_GRPDELETEALL, 2),
		fsSetImage (ID_GRPPROPERTIES, 3),
	};

	m_odmenu.SetImages (images, sizeof (images) / sizeof (fsSetImage));

	pPopup->TrackPopupMenu (TPM_RIGHTBUTTON | TPM_TOPALIGN | TPM_LEFTALIGN,	pt.x, pt.y, this);
	m_odmenu.Detach ();

	menu.DestroyMenu ();
}

fsDldFilter* CDownloads_Groups::GetCurrentFilter()
{
	HTREEITEM hItem = GetSelectedItem ();

	if (hItem == m_hTasks)
		return &m_filterTasks;

	if (hItem == m_hAllGroups || hItem == m_hFilters)
		return &m_filterAll;

	if (hItem == m_hHistory || hItem == m_hDeleted)
		return NULL;

	if (GetParentItem (hItem) == m_hFilters || IsGroupItem (hItem))
		return (fsDldFilter*) GetItemData (hItem);

	return NULL;
}

void CDownloads_Groups::InsertHistory()
{
	m_hHistory = InsertItem (TVIF_IMAGE  | TVIF_SELECTEDIMAGE | TVIF_STATE | TVIF_TEXT, LS (L_HISTORY), 0, 0,
		TVIS_BOLD, TVIS_BOLD, 0, TVI_ROOT, TVI_LAST);
	SetItemData (m_hHistory, ULONG (&m_filterAllHist));

	m_hToday = InsertItem (LS (L_TODAY), 1, 1, m_hHistory, TVI_LAST);
	SetItemData (m_hToday, ULONG (&m_filterToday));

	m_hYesterday = InsertItem (LS (L_YESTERDAY), 1, 1, m_hHistory, TVI_LAST);
	SetItemData (m_hYesterday, ULONG (&m_filterYesterday));

	m_hLastWeek = InsertItem (LS (L_LASTWEEK), 1, 1, m_hHistory, TVI_LAST);
	SetItemData (m_hLastWeek, ULONG (&m_filterLastWeek));

	m_hLastMonth = InsertItem (LS (L_LASTMONTH), 1, 1, m_hHistory, TVI_LAST);
	SetItemData (m_hLastMonth, ULONG (&m_filterLastMonth));

	m_hHistCustom = InsertItem (LS (L_CUSTOMttt), 1, 1, m_hHistory, TVI_LAST);
	SetItemData (m_hHistCustom, ULONG (&m_filterCustomHist));
}

void CDownloads_Groups::InsertDeleted()
{
	m_hDeleted = InsertItem (TVIF_IMAGE  | TVIF_SELECTEDIMAGE | TVIF_STATE | TVIF_TEXT, LS (L_DELETED), 6, 6,
		0, 0, 0, TVI_ROOT, TVI_LAST);

	SetItemData (m_hDeleted, NULL);
}

void CDownloads_Groups::ShowDeletedContextMenu()
{
	CMenu menu;
	menu.LoadMenu (IDM_GROUP);
	CMenu *pPopup = menu.GetSubMenu (1);

	ApplyLanguageToMenu_Deleted (pPopup);

	pPopup->SetDefaultItem (ID_DELETED_PROPERTIES);

	if (_DldsMgr.Get_DeletedDownloadCount () == 0)
		pPopup->EnableMenuItem (ID_DELETED_CLEAR, MF_BYCOMMAND | MF_GRAYED);

	CPoint pt (m_rbX, m_rbY);
	ClientToScreen (&pt);

	m_odmenu.Attach (&menu, FALSE);

	fsSetImage images [] =
	{
		fsSetImage (ID_DELETED_CLEAR, 2),
		fsSetImage (ID_DELETED_PROPERTIES, 3),
	};

	m_odmenu.SetImages (images, sizeof (images) / sizeof (fsSetImage));

	pPopup->TrackPopupMenu (TPM_RIGHTBUTTON | TPM_TOPALIGN | TPM_LEFTALIGN,	pt.x, pt.y, this);
	m_odmenu.Detach ();

	menu.DestroyMenu ();
}

void CDownloads_Groups::OnDeletedClear() 
{
	if (0 == _DldsMgr.Get_DeletedDownloadCount ())
		return;
	
	if (IDYES == MessageBox (LS (L_AREYOUSURE), LS (L_CONFIRMATION), MB_YESNO | MB_ICONQUESTION))
	{
		if (_pwndDownloads->Get_DWWN () == DWWN_DELETED)
			_pwndDownloads->m_wndDeleted.ShowWindow (SW_HIDE);
		try 
		{
			_DldsMgr.ClearDeleted ();	
		}
		catch (const std::exception& ex)
		{
			ASSERT (FALSE);
			vmsLogger::WriteLog("CDownloads_Groups::OnDeletedClear " + tstring(ex.what()));
		}
		catch (...)
		{
			ASSERT (FALSE);
			vmsLogger::WriteLog("CDownloads_Groups::OnDeletedClear unknown exception");
		}

		if (_pwndDownloads->Get_DWWN () == DWWN_DELETED)
			_pwndDownloads->m_wndDeleted.ShowWindow (SW_SHOW);
	}

	SetFocus ();
}

void CDownloads_Groups::OnDeletedProperties() 
{
	CDlgDeletedProperties dlg;
	_DlgMgr.DoModal (&dlg);
	SetFocus ();
}

void CDownloads_Groups::ApplyLanguageToMenu_Deleted(CMenu *menu)
{
	menu->ModifyMenu (ID_DELETED_PROPERTIES, MF_BYCOMMAND|MF_STRING, ID_DELETED_PROPERTIES, LS (L_PROPERTIES));
	
	CString str = LS (L_CLEARDELETED); str += "\tDel";
	menu->ModifyMenu (ID_DELETED_CLEAR, MF_BYCOMMAND|MF_STRING, ID_DELETED_CLEAR, str);
}

void CDownloads_Groups::ShowHistoryContextMenu()
{
	CMenu menu;
	menu.LoadMenu (IDM_GROUP);
	CMenu *pPopup = menu.GetSubMenu (2);

	ApplyLanguageToMenu_History (pPopup);

	pPopup->SetDefaultItem (ID_HISTORY_SETTINGS);

	if (_DldsMgr.m_histmgr.GetRecordCount () == 0)
		pPopup->EnableMenuItem (ID_HISTORY_CLEAR, MF_BYCOMMAND | MF_GRAYED);

	CPoint pt (m_rbX, m_rbY);
	ClientToScreen (&pt);

	m_odmenu.Attach (&menu, FALSE);

	fsSetImage images [] =
	{
		fsSetImage (ID_HISTORY_CLEAR, 2),
		fsSetImage (ID_HISTORY_SETTINGS, 3),
	};

	m_odmenu.SetImages (images, sizeof (images) / sizeof (fsSetImage));

	pPopup->TrackPopupMenu (TPM_RIGHTBUTTON | TPM_TOPALIGN | TPM_LEFTALIGN,	pt.x, pt.y, this);
	m_odmenu.Detach ();

	menu.DestroyMenu ();
}

void CDownloads_Groups::ApplyLanguageToMenu_History(CMenu *menu)
{
	menu->ModifyMenu (ID_HISTORY_SETTINGS, MF_BYCOMMAND|MF_STRING, ID_HISTORY_SETTINGS, LS (L_SETTINGS));
	
	CString str = LS (L_CLEARHISTORY2); str += "\tDel";
	menu->ModifyMenu (ID_HISTORY_CLEAR, MF_BYCOMMAND|MF_STRING, ID_HISTORY_CLEAR, str);
}

void CDownloads_Groups::OnHistoryClear() 
{
	if (IDYES == MessageBox (LS (L_AREYOUSURE), LS (L_CONFIRMATION), MB_YESNO | MB_ICONQUESTION))
		_DldsMgr.m_histmgr.ClearHistory ();
	SetFocus ();
}

void CDownloads_Groups::OnHistorySettings() 
{
	CDlgDownloadsHistory dlg;
	_DlgMgr.DoModal (&dlg);
	SetFocus ();
}

fsDldHistRecFilter* CDownloads_Groups::GetHistoryCurrentFilter()
{
	HTREEITEM hItem = GetSelectedItem ();

	if (hItem == m_hHistory)
		return &m_filterAllHist;

	if (GetParentItem (hItem) == m_hHistory)
		return (fsDldHistRecFilter*) GetItemData (hItem);

	return NULL;
}

void CDownloads_Groups::OnClick(NMHDR* , LRESULT* pResult) 
{
	*pResult = 0;

	CPoint pt;
	if (FALSE == GetCursorPos (&pt))
		return;

	ScreenToClient (&pt);

	if (HitTest (pt) == m_hHistCustom)
	{
		if (GetSelectedItem () == m_hHistCustom)
		{
			CustomizeHistoryFilter ();
			_pwndDownloads->m_wndHistory.ApplyFilter (&m_filterCustomHist);
		}
	}
}

void CDownloads_Groups::CustomizeHistoryFilter()
{
	CDlgT1ToT2 dlg;
			
	dlg.m_t1 = *m_filterCustomHist.Get_TFrom ();
	dlg.m_t2 = *m_filterCustomHist.Get_TTo ();

	if (IDOK == _DlgMgr.DoModal (&dlg))
		m_filterCustomHist.SetTimeRange (dlg.m_t1, dlg.m_t2);
}

void CDownloads_Groups::SetFilter_AllDownloads()
{
	if (GetSelectedItem () != m_hAllGroups)
		SelectItem (m_hAllGroups);
}

void CDownloads_Groups::SetFilter_AllHistory()
{
	if (GetSelectedItem () != m_hHistory)
		SelectItem (m_hHistory);
}

void CDownloads_Groups::SetFilter_DeletedDownloads()
{
	if (GetSelectedItem () != m_hDeleted)
		SelectItem (m_hDeleted);
}

void CDownloads_Groups::UpdateDeletedIcon()
{
	int img = _DldsMgr.Get_DeletedDownloadCount () ? 7 : 6;
	int imgold;
	GetItemImage (m_hDeleted, imgold, imgold);
	if (img != imgold)
		SetItemImage (m_hDeleted, img, img);
}

void CDownloads_Groups::SetGroupFilter(vmsDownloadsGroupSmartPtr pGroup)
{
	HTREEITEM hGrp = NULL;

	for (size_t i = 0; i < m_vGroups.size (); i++)
	{
		if (pGroup == m_vGroups [i].pGroupFilter->GetGroup ())
		{
			hGrp = m_vGroups [i].hGroup;
			break;
		}
	}

	if (hGrp != NULL && hGrp != GetSelectedItem ())
		SelectItem (hGrp);
}

void CDownloads_Groups::OnSetGroupsRootFolder() 
{
	CFolderBrowser *fb = CFolderBrowser::Create (LS (L_SELECTGRPSROOTFLDR), 
		_DldsGrps.GetGroupsRootOutFolder (), NULL, this);
	if (fb == NULL)
		return;
	_DldsGrps.SetGroupsRootOutFolder (fb->GetPath ());
}

void CDownloads_Groups::InsertGroups_tree(PDLDS_GROUPS_TREE pRoot, HTREEITEM hRoot)
{
	for (int i = 0; i < pRoot->GetLeafCount (); i++)
	{
		PDLDS_GROUPS_TREE pGroup = pRoot->GetLeaf (i);

		HTREEITEM hGroup = InsertGroup (pGroup->GetData (), hRoot);

		if (pGroup->GetLeafCount ())
			InsertGroups_tree (pGroup, hGroup);
	}
}

void CDownloads_Groups::OnNewGroupCreated(vmsDownloadsGroupSmartPtr pGroup)
{
	ASSERT (FindGroupIndex (pGroup) == -1);
	if (FindGroupIndex (pGroup) != -1)
		return;

	PDLDS_GROUPS_TREE pGrpInTree = _DldsGrps.FindGroupInTree (pGroup);
	ASSERT (pGrpInTree != NULL);
	PDLDS_GROUPS_TREE pRoot = pGrpInTree->GetRoot ();
	
	
	HTREEITEM hRoot;
	
	if (pRoot == _DldsGrps.GetGroupsTree ())
	{
		hRoot = m_hAllGroups;
	}
	else
	{
		int nIndex = FindGroupIndex (pRoot->GetData ());
		if (nIndex == -1)
			return;
		hRoot = m_vGroups [nIndex].hGroup;
	}

	InsertGroup (pGroup, hRoot);

	
	Expand (hRoot, TVE_EXPAND);
}

void CDownloads_Groups::OnGroupNameChanged(vmsDownloadsGroupSmartPtr pGroup)
{
	int nIndex = FindGroupIndex (pGroup);
	if (nIndex == -1)
		return;
	HTREEITEM hGroup = m_vGroups [nIndex].hGroup;
	CString str;
	if (pGroup->cDownloads)
		str.Format ("%s (%d)", pGroup->strName, pGroup->cDownloads);
	else
		str = pGroup->strName;
	SetItemText (hGroup, str);
}

int CDownloads_Groups::FindGroupIndex(vmsDownloadsGroupSmartPtr pGroup)
{
	for (size_t i = 0; i < m_vGroups.size (); i++)
	{
		if (m_vGroups [i].pGroupFilter->GetGroup ()->nId == pGroup->nId)
			return i;
	}

	return -1; 
}

HTREEITEM CDownloads_Groups::InsertGroup(vmsDownloadsGroupSmartPtr pGroup, HTREEITEM hRoot)
{
	_inc_GroupItem grpItem;

	if (pGroup->nId == GRP_OTHER_ID)
	{
		CString str;
		if (pGroup->cDownloads)
			str.Format ("%s (%d)", LS (L_OTHER), pGroup->cDownloads);
		else
			str = LS (L_OTHER);
		
		grpItem.hGroup = m_hOther = InsertItem (TVIF_IMAGE | TVIF_SELECTEDIMAGE | 
			TVIF_STATE | TVIF_TEXT, 
			str, 1, 1, 0, 0, 0, hRoot, TVI_LAST);
	}
	else
	{
		CString str;
		if (pGroup->cDownloads)
			str.Format ("%s (%d)", pGroup->strName, pGroup->cDownloads);
		else
			str = pGroup->strName;
		
		grpItem.hGroup = InsertItem (str, 1, 1, hRoot, TVI_SORT);
	}

	
	grpItem.pGroupFilter = new fsDldGroupFilter;
	grpItem.pGroupFilter->SetGroup (pGroup);
	grpItem.cDownloads = pGroup->cDownloads;
	m_vGroups.push_back (grpItem);
	SetItemData (grpItem.hGroup, (ULONG) grpItem.pGroupFilter);

	return grpItem.hGroup;
}

BOOL CDownloads_Groups::IsGroupItem(HTREEITEM hItem)
{
	if (hItem == m_hTasks)
		return FALSE;

	if (hItem == m_hAllGroups || hItem == m_hFilters)
		return FALSE;

	if (hItem == m_hHistory || hItem == m_hDeleted || 
			GetParentItem (hItem) == m_hHistory || 
			GetParentItem (hItem) == m_hDeleted)
		return FALSE;

	fsDldFilter *filter = (fsDldFilter*) GetItemData (hItem);
	ASSERT (filter != NULL);
	if (filter == NULL)
		return FALSE;
	return filter->GetType () == DFT_GROUP;
}

void CDownloads_Groups::OnTimer(UINT nIDEvent) 
{
	UpdateNumbersOfDownloadsInGroups ();
	
	CTreeCtrl::OnTimer(nIDEvent);
}

void CDownloads_Groups::UpdateNumbersOfDownloadsInGroups()
{
	try {

	size_t cTotalDownloads = 0;

	for (size_t i = 0; i < m_vGroups.size (); i++)
	{
		cTotalDownloads += m_vGroups [i].pGroupFilter->GetGroup ()->cDownloads;
		if (m_vGroups [i].cDownloads != m_vGroups [i].pGroupFilter->GetGroup ()->cDownloads)
		{
			LPCSTR pszName = m_vGroups [i].pGroupFilter->GetGroup ()->nId == GRP_OTHER_ID ?
				LS (L_OTHER) : m_vGroups [i].pGroupFilter->GetGroup ()->strName;

			m_vGroups [i].cDownloads = m_vGroups [i].pGroupFilter->GetGroup ()->cDownloads;

			CString str;
			if (m_vGroups [i].cDownloads)
				str.Format ("%s (%d)", pszName, m_vGroups [i].cDownloads);
			else
				str = pszName;

			SetItemText (m_vGroups [i].hGroup, str);
		}
	}

	if (cTotalDownloads != m_cTotalDownloads)
	{
		m_cTotalDownloads = cTotalDownloads;
		CString str;
		if (m_cTotalDownloads)
			str.Format ("%s (%d)", LS (L_ALLDLDS), m_cTotalDownloads);
		else
			str = LS (L_ALLDLDS);
		SetItemText (m_hAllGroups, str);
	}

	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CDownloads_Groups::UpdateNumbersOfDownloadsInGroups " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CDownloads_Groups::UpdateNumbersOfDownloadsInGroups unknown exception");
	}
}

void CDownloads_Groups::OnGrpdeletealldeaddlds() 
{
	_pwndDownloads->DeleteDeadDownloadsInList ();	
}
