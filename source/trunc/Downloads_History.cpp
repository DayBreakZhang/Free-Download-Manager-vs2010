/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Downloads_History.h"
#include "DownloadsWnd.h"
#include "WaitDlg.h"
#include "vmsLogger.h"

extern CDownloadsWnd* _pwndDownloads;

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

BEGIN_MESSAGE_MAP(CDownloads_History, CListCtrlEx)
	//{{AFX_MSG_MAP(CDownloads_History)
	ON_WM_DRAWITEM()
	ON_WM_MEASUREITEM()
	ON_COMMAND(ID_URLTOCLIPBOARD, OnUrltoclipboard)
	ON_COMMAND(ID_LAUNCH, OnLaunch)
	ON_COMMAND(ID_OPENFOLDER, OnOpenfolder)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_HSTITEM_DELETE, OnHstitemDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CDownloads_History::CDownloads_History()
{
	
}

CDownloads_History::~CDownloads_History()
{

}

BOOL CDownloads_History::Create(CWnd *pParent)
{
	CRect rc (0, 0, 0, 0);

	m_mgr = &_DldsMgr.m_histmgr;

	
	if (FALSE == CListCtrlEx::Create (LVS_REPORT|LVS_OWNERDRAWFIXED|LVS_SHOWSELALWAYS,
									  rc, pParent, 0x5d9))
		return FALSE;

	SetExtendedStyle (LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_INFOTIP);

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

	InsertColumn (0, "file", LVCFMT_LEFT, 100, 0);
	InsertColumn (1, "url", LVCFMT_LEFT, 100, 0);
	InsertColumn (2, "added", LVCFMT_LEFT, 80, 0);
	InsertColumn (3, "dlded", LVCFMT_LEFT, 80, 0);
	InsertColumn (4, "size", LVCFMT_LEFT, 80, 0);
	InsertColumn (5, "savedto", LVCFMT_LEFT, 100, 0);
	InsertColumn (6, "comment", LVCFMT_LEFT, 90, 0);

	ReadState ("DownloadsHistory");
	

	return TRUE;
}

void CDownloads_History::ApplyLanguage()
{
	SetColumnText (0, LS (L_FILE));
	SetColumnText (1, "URL");
	SetColumnText (2, LS (L_ADDED));
	SetColumnText (3, LS (L_DOWNLOADED));
	SetColumnText (4, LS (L_SIZE));
	SetColumnText (5, LS (L_SAVEDTO));
	SetColumnText (6, LS (L_COMMENT));
}

void CDownloads_History::AddRecord(fsDLHistoryRecord *rec)
{
	m_mxAddDel.Lock ();

	
	int iItem = AddItem ("", GetSysColor (COLOR_WINDOW), GetSysColor (COLOR_WINDOWTEXT), 0, TRUE);

	SetItemData (iItem, (DWORD) rec);

	
	UpdateRecord (iItem);

	m_mxAddDel.Unlock ();
}

void CDownloads_History::DeleteRecord(fsDLHistoryRecord *rec)
{
	m_mxAddDel.Lock ();
	int iItem = FindRecord (rec);
	if (iItem != -1)
		DeleteItem (iItem);
	m_mxAddDel.Unlock ();
}

void CDownloads_History::DeleteAllRecords()
{
	m_mxAddDel.Lock ();
	DeleteAllItems ();
	m_mxAddDel.Unlock ();
}

void CDownloads_History::UpdateRecord(int iItem)
{
	fsDLHistoryRecord *rec = (fsDLHistoryRecord*) GetItemData (iItem);
	SetItemText (iItem, 0, rec->strFileName);

	SetItemText (iItem, 1, rec->strURL);

	char sz [1000];
	
	FileTimeToStr (&rec->dateAdded, sz, NULL);
	SetItemText (iItem, 2, sz);

	if (rec->dateDownloaded.dwHighDateTime != 0)
	{
		FileTimeToStr (&rec->dateDownloaded, sz, NULL);
		SetItemText (iItem, 3, sz);
	}
	else
	{
		CString str = LS (L_WASDELETED_);
		FileTimeToStr (&rec->dateRecordAdded, sz, NULL);
		str += " (";
		str += sz;
		str += ')';
		SetItemText (iItem, 3, str);
	}

	CString str;
	if (rec->uFileSize != _UI64_MAX)
	{
		if (FALSE == _pwndDownloads->IsSizesInBytes ())
		{
			float val;
			char szDim [10];
			BytesToXBytes (rec->uFileSize, &val, szDim);
			str.Format ("%.*g %s", val > 999 ? 4 : 3, val, szDim);
		}
		else
			str = fsBytesToStr (rec->uFileSize);
	}
	else
		str = LS (L_UNKNOWN);

	SetItemText (iItem, 4, str);

	SetItemText (iItem, 5, rec->strSavedTo);
	
	str = rec->strComment;
	str.Replace ("\r", " ");
	str.Replace ("\n", " ");
	SetItemText (iItem, 6, str);

	SetItemImage (iItem, GetRecordImage (rec));
}

int CDownloads_History::FindRecord(fsDLHistoryRecord *rec)
{
	LVFINDINFO fi;

	fi.flags = LVFI_PARAM;
	fi.lParam = (LPARAM) rec;

	return CListCtrl::FindItem (&fi, -1);
}

void CDownloads_History::OnForceUpdate()
{
	for (int i = 0; i < GetItemCount (); i++)
	{
		UpdateRecord (i);
	}
}

void CDownloads_History::ApplyFilter(fsDldHistRecFilter* filter)
{
	if (filter == NULL)
	{
		DeleteAllRecords ();
		return;
	}

	if (m_mgr->GetRecordCount () < 600)	
		ApplyFilter_imp (filter);	
	else
	{
		
		CWaitDlg dlg;
		dlg.StartWaiting (LS (L_BUILDINGLISTOFHISTORY), _threadApplyFilter, FALSE, this, filter);
	}
}

void CDownloads_History::ApplyFilter_imp(fsDldHistRecFilter *f, int *piProgress)
{
	DeleteAllRecords ();
	ShowWindow (SW_HIDE);
	std::vector <fsDLHistoryRecordPtr> v;
	m_mgr->Lock ();

	try 
	{
		int cRecs = m_mgr->GetRecordCount ();
		for (int i = cRecs-1; i >= 0; i--)
		{
			fsDLHistoryRecord* rec = m_mgr->GetRecord (i);
			if (f->IsSatisfies (rec))
				v.push_back (rec);

			if (piProgress)
				*piProgress = int (float (cRecs-i) / cRecs * 100);

		}
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CDownloads_History::ApplyFilter_imp " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CDownloads_History::ApplyFilter_imp unknown exception");
	}

	m_mgr->Unlock ();

	for (size_t i = 0; i < v.size (); i++)
		AddRecord (v [i]);

	ShowWindow (SW_SHOW);
}

DWORD WINAPI CDownloads_History::_threadApplyFilter(LPVOID lp)
{
	ProcWaitInfo *info = (ProcWaitInfo*) lp;
	CDownloads_History* pThis = (CDownloads_History*) info->lpParam1;
	fsDldHistRecFilter *f = (fsDldHistRecFilter*) info->lpParam2;
	pThis->ApplyFilter_imp (f, &info->iProgress);
	info->bWaitDone = TRUE;
	return 0;
}

int CDownloads_History::GetRecordImage(fsDLHistoryRecord *rec)
{
	if (rec->dateDownloaded.dwHighDateTime != 0)
		return 1;
	else
		return 6;

}

void CDownloads_History::SelectRecord(fsDLHistoryRecord *rec)
{
	int iItem = FindRecord (rec);

	if (iItem == -1)
		return;

	POSITION pos = GetFirstSelectedItemPosition ();
	
	while (pos)
		SetItemState (GetNextSelectedItem (pos), 0, LVIS_SELECTED | LVIS_FOCUSED);

	
	SetItemState (iItem, LVIS_FOCUSED | LVIS_SELECTED, LVIS_FOCUSED | LVIS_SELECTED);
	SetSelectionMark (iItem);
	EnsureVisible (iItem, FALSE);
}

void CDownloads_History::OnRClick()
{
	CMenu menu;
	menu.LoadMenu (IDM_HISTORYITEMS);
	ApplyLanguageToMenu (&menu);
	CMenu *pPopup = menu.GetSubMenu (0);

	if (GetSelectedCount () != 1)
	{
		pPopup->EnableMenuItem (ID_LAUNCH, MF_BYCOMMAND | MF_GRAYED);
		pPopup->EnableMenuItem (ID_OPENFOLDER, MF_BYCOMMAND | MF_GRAYED);
		pPopup->EnableMenuItem (ID_URLTOCLIPBOARD, MF_BYCOMMAND | MF_GRAYED);
	}

	if (GetSelectedCount () == 0)
		pPopup->EnableMenuItem (ID_HSTITEM_DELETE, MF_BYCOMMAND | MF_GRAYED);

	m_odmenu.Attach (&menu, FALSE);
	
	CPoint pt (0,0);
	GetCursorPos (&pt);
	pPopup->TrackPopupMenu (TPM_RIGHTBUTTON | TPM_TOPALIGN | TPM_LEFTALIGN,	pt.x, pt.y, this);
	m_odmenu.Detach ();

	menu.DestroyMenu ();
}

void CDownloads_History::ApplyLanguageToMenu(CMenu *menu)
{
	menu->ModifyMenu (ID_LAUNCH, MF_BYCOMMAND|MF_STRING, ID_LAUNCH, LS (L_LAUNCHFILE));
	menu->ModifyMenu (ID_OPENFOLDER, MF_BYCOMMAND|MF_STRING, ID_OPENFOLDER, LS (L_OPENFOLDER));
	menu->ModifyMenu (ID_URLTOCLIPBOARD, MF_BYCOMMAND|MF_STRING, ID_URLTOCLIPBOARD, LS (L_URLTOCLIPBOARD));

	CString str = LS (L_DELETERECORD); str += "\tDel";
	menu->ModifyMenu (ID_HSTITEM_DELETE, MF_BYCOMMAND|MF_STRING, ID_HSTITEM_DELETE, str);
}

void CDownloads_History::OnDrawItem(int , LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	m_odmenu.OnDrawItem (lpDrawItemStruct);
}

void CDownloads_History::OnMeasureItem(int , LPMEASUREITEMSTRUCT lpMeasureItemStruct) 
{
	m_odmenu.OnMeasureItem (lpMeasureItemStruct);
}

void CDownloads_History::OnUrltoclipboard() 
{
	fsDLHistoryRecord* rec = get_SelectedRecord ();
	_ClipbrdMgr.Text (rec->strURL);
}

void CDownloads_History::OnSortModeChanged()
{
	if (m_sortMode != LCSM_ASCENDING)
		m_sortMode = LCSM_ASCENDING;
	
	Sort ();
}

void CDownloads_History::Sort()
{
	if (m_sortMode != LCSM_NONE)
		SortItems (_sortFunc, DWORD (this));
	else
	{
		_pwndDownloads->ApplyHistoryCurrentFilter ();
	}
}

int CALLBACK CDownloads_History::_sortFunc(LPARAM item1, LPARAM item2, LPARAM lp)
{
	CDownloads_History* pThis = (CDownloads_History*) lp;
	fsDLHistoryRecord* rec1 = (fsDLHistoryRecord*) item1;
	fsDLHistoryRecord* rec2 = (fsDLHistoryRecord*) item2;

	switch (pThis->m_iSortCol)
	{
		case 0:	
			return stricmp (rec1->strFileName, rec2->strFileName);
		
		case 1:	
			return stricmp (rec1->strURL, rec2->strURL);

		case 2:	
			return CompareFileTime (&rec2->dateAdded, &rec1->dateAdded);

		case 3:	
			if (rec1->dateDownloaded.dwHighDateTime == 0 && rec2->dateDownloaded.dwHighDateTime == 0)
				return 0;
			
			if (rec2->dateDownloaded.dwHighDateTime == 0)
				return -1;

			if (rec1->dateDownloaded.dwHighDateTime == 0)
				return 1;

			return CompareFileTime (&rec2->dateDownloaded, &rec1->dateDownloaded);

		case 4:	
			UINT64 size1;
			UINT64 size2;
			size1 = rec1->uFileSize;
			size2 = rec2->uFileSize;
			
			if (size1 == _UI64_MAX)
				return size2 == _UI64_MAX ? 0 : 1;

			if (size2 == _UI64_MAX)
				return size1 == _UI64_MAX ? 0 : -1;

			if (size1 == size2)
				return 0;

			return size1 > size2 ? -1 : 1;

		case 5:	
			return stricmp (rec1->strSavedTo, rec2->strSavedTo);
	}

	return 0;
}

void CDownloads_History::OnLaunch() 
{
	fsDLHistoryRecord* rec = get_SelectedRecord ();
	if (rec)
		ShellExecute (::GetDesktopWindow (), "open", rec->strSavedTo, NULL, NULL, SW_SHOW);
}

void CDownloads_History::OnOpenfolder() 
{
	fsDLHistoryRecord* rec = get_SelectedRecord ();

	if (GetFileAttributes (rec->strSavedTo) == DWORD (-1))
	{
		char szPath [MY_MAX_PATH];
		fsGetPath (rec->strSavedTo, szPath);
		ShellExecute (m_hWnd, "explore", szPath, NULL, NULL, SW_SHOW);
	}
	else
	{
		CString strCmd;
		strCmd.Format ("/select,\"%s\"", rec->strSavedTo);
		ShellExecute (m_hWnd, "open", "explorer.exe", strCmd, NULL, SW_SHOW);
	}
}

fsDLHistoryRecord* CDownloads_History::get_SelectedRecord()
{
	POSITION pos = GetFirstSelectedItemPosition ();
	if (pos == NULL)
		return NULL;

	int iItem = GetNextSelectedItem (pos);

	return (fsDLHistoryRecord*) GetItemData (iItem);
}

void CDownloads_History::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	OnLaunch ();	
	CListCtrlEx::OnLButtonDblClk(nFlags, point);
}

void CDownloads_History::OnHstitemDelete() 
{
	POSITION pos = GetFirstSelectedItemPosition ();
	fs::list <fsDLHistoryRecord*> v;

	while (pos)
	{
		int i = GetNextSelectedItem (pos);
		v.add ((fsDLHistoryRecord*) GetItemData (i));
	}

	if (IDCANCEL == MessageBox (LS (L_ISOKTODELETE), LS (L_CONFIRMATION), 
			MB_ICONQUESTION | MB_OKCANCEL)) 
	{
		SetFocus ();
		return;
	}

	ShowWindow (SW_HIDE);

	try 
	{
		for (int i = 0; i < v.size (); i++)
			_DldsMgr.m_histmgr.DeleteRecord (v [i]);
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CDownloads_History::OnHstitemDelete " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CDownloads_History::OnHstitemDelete unknown exception");
	}

	ShowWindow (SW_SHOW);
	SetFocus ();
}

void CDownloads_History::OnKeyDown(WORD wVK)
{
	switch (wVK)
	{
	case VK_DELETE:
		OnHstitemDelete ();
		break;
	}
}
