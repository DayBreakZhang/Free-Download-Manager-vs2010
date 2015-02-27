/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Downloads_Deleted.h"
#include "DownloadsWnd.h"
#include "vmsLogger.h"

extern CDownloadsWnd* _pwndDownloads;

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

BEGIN_MESSAGE_MAP(CDownloads_Deleted, CListCtrlEx)
	//{{AFX_MSG_MAP(CDownloads_Deleted)
	ON_WM_MEASUREITEM()
	ON_WM_DRAWITEM()
	ON_COMMAND(ID_DELETED_DELETE, OnDeletedDelete)
	ON_COMMAND(ID_DELETED_RESTORE, OnDeletedRestore)
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CDownloads_Deleted::CDownloads_Deleted()
{

}

CDownloads_Deleted::~CDownloads_Deleted()
{

}

BOOL CDownloads_Deleted::Create(CWnd *pParent)
{
	CRect rc (0, 0, 0, 0);

	
	if (FALSE == CListCtrlEx::Create (LVS_REPORT|LVS_OWNERDRAWFIXED|LVS_SHOWSELALWAYS,
									  rc, pParent, 0x5A9))
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

	InsertColumn (0, "", LVCFMT_LEFT, 200, 0);
	InsertColumn (1, "", LVCFMT_LEFT, 50, 0);
	InsertColumn (2, "", LVCFMT_LEFT, 100, 0);
	InsertColumn (3, "", LVCFMT_LEFT, 58, 0);
	InsertColumn (4, "", LVCFMT_LEFT, 200, 0);

	ReadState ("DownloadsDeleted");

	

	return TRUE;
}

void CDownloads_Deleted::ApplyLanguage()
{
	SetColumnText (0, LS (L_FILENAME));
	SetColumnText (1, LS (L_SIZE));
	SetColumnText (2, LS (L_DOWNLOADED));
	SetColumnText (3, LS (L_SECTIONS));
	SetColumnText (4, LS (L_COMMENT));
}

void CDownloads_Deleted::AddDownload(vmsDownloadSmartPtr dld)
{
	
	int iItem = AddItem ("", GetSysColor (COLOR_WINDOW), GetSysColor (COLOR_WINDOWTEXT), 0, TRUE);

	SetItemData (iItem, (DWORD) (fsDownload*) dld);

	
	UpdateDownload (iItem);

}

void CDownloads_Deleted::RemoveDownload(vmsDownloadSmartPtr dld)
{
	int iItem = FindDownload (dld);
	if (iItem != -1)
		DeleteItem (iItem);
}

void CDownloads_Deleted::UpdateDownload(int iItem)
{
	vmsDownloadSmartPtr dld = (fsDownload*)GetItemData (iItem);

	std::stringstream ssFile;	
	ssFile << CDownloads_Tasks::GetFileName (dld) << " (" << 
		dld->pMgr->get_URL () << ")";
	SetItemText (iItem, 0, ssFile.str ().c_str ());

	int cSects = dld->pMgr->GetNumberOfSections ();
	UINT64 uSize = dld->pMgr->GetLDFileSize ();
	UINT64 uDone = 0;

	
	SetItemImage (iItem, GetDownloadImage (dld));

	
	
	
	
	uDone = dld->pMgr->GetDownloadedBytesCount ();

	CString str;
	CHAR szDim [10];
	float val;

	

	if (cSects)
	{
		

		if (uSize != _UI64_MAX)
		{
			if (_pwndDownloads->IsSizesInBytes () == FALSE)
			{
				
				BytesToXBytes (uSize, &val, szDim);
				str.Format ("%.*g %s", val > 999 ? 4 : 3, val, szDim);
			}
			else
			{
				
				
				str = fsBytesToStr (uSize);
			}
			SetItemText (iItem, 1, str);
		}
		else
			SetItemText (iItem, 1, "?");	

		

		if (_pwndDownloads->IsSizesInBytes () == FALSE)
		{
			BytesToXBytes (uDone, &val, szDim);
			if (uSize != _UI64_MAX)
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
		SetItemText (iItem, 2, str);
	}
	else
	{
		SetItemText (iItem, 1, "");
		SetItemText (iItem, 2, "");
	}

	

	str.Format ("%d", cSects);
	SetItemText (iItem, 3, str);

	
	str = dld->strComment;
	str.Replace ("\r", " ");
	str.Replace ("\n", " ");
	SetItemText (iItem, 4, str);
}

int CDownloads_Deleted::FindDownload(vmsDownloadSmartPtr dld)
{
	LVFINDINFO fi;

	fi.flags = LVFI_PARAM;
	fi.lParam = (LPARAM)(fsDownload*) dld;

	return CListCtrl::FindItem (&fi, -1);
}

void CDownloads_Deleted::RemoveAll()
{
	DeleteAllItems ();
}

void CDownloads_Deleted::OnRClick()
{
	CMenu menu;
	menu.LoadMenu (IDM_DELETEDITEMS);
	ApplyLanguageToMenu (&menu);
	CMenu *pPopup = menu.GetSubMenu (0);

	if (GetSelectedCount () == 0)
	{
		pPopup->EnableMenuItem (ID_DELETED_RESTORE, MF_BYCOMMAND | MF_GRAYED);
		pPopup->EnableMenuItem (ID_DELETED_DELETE, MF_BYCOMMAND | MF_GRAYED);
	}

	m_odmenu.Attach (&menu, FALSE);
	
	CPoint pt (0,0);
	GetCursorPos (&pt);
	pPopup->TrackPopupMenu (TPM_RIGHTBUTTON | TPM_TOPALIGN | TPM_LEFTALIGN,	pt.x, pt.y, this);
	m_odmenu.Detach ();

	menu.DestroyMenu ();
}

void CDownloads_Deleted::ApplyLanguageToMenu(CMenu *menu)
{
	menu->ModifyMenu (ID_DELETED_RESTORE, MF_BYCOMMAND|MF_STRING, ID_DELETED_RESTORE, LS (L_RESTORE));
	menu->ModifyMenu (ID_DELETED_DELETE, MF_BYCOMMAND|MF_STRING, ID_DELETED_DELETE, LS (L_DELETE));
}

void CDownloads_Deleted::OnMeasureItem(int , LPMEASUREITEMSTRUCT lpMeasureItemStruct) 
{
	m_odmenu.OnMeasureItem (lpMeasureItemStruct);
}

void CDownloads_Deleted::OnDrawItem(int , LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	m_odmenu.OnDrawItem (lpDrawItemStruct);
}

void CDownloads_Deleted::OnDeletedDelete() 
{
	DLDS_LIST v;
	POSITION pos = GetFirstSelectedItemPosition ();
	while (pos)
	{
		int iItem = GetNextSelectedItem (pos);
		vmsDownloadSmartPtr dld = (fsDownload*) GetItemData (iItem);
		v.push_back (dld);
	}

	if (v.size ())
	{
		if (IDYES == MessageBox (LS (L_AREYOUSURE), LS (L_CONFIRMATION), MB_ICONQUESTION | MB_YESNO))
		{
			if (_pwndDownloads->Get_DWWN () == DWWN_DELETED)
				_pwndDownloads->m_wndDeleted.ShowWindow (SW_HIDE);
			try 
			{
				_DldsMgr.DeleteDeletedDownloads (v);
			}
			catch (const std::exception& ex)
			{
				ASSERT (FALSE);
				vmsLogger::WriteLog("CDownloads_Deleted::OnDeletedDelete " + tstring(ex.what()));
			}
			catch (...)
			{
				ASSERT (FALSE);
				vmsLogger::WriteLog("CDownloads_Deleted::OnDeletedDelete unknown exception");
			}

			if (_pwndDownloads->Get_DWWN () == DWWN_DELETED)
				_pwndDownloads->m_wndDeleted.ShowWindow (SW_SHOW);
		}
	}
}

void CDownloads_Deleted::OnDeletedRestore() 
{
	DLDS_LIST v;
	POSITION pos = GetFirstSelectedItemPosition ();
	while (pos)
	{
		int iItem = GetNextSelectedItem (pos);
		vmsDownloadSmartPtr dld = (fsDownload*) GetItemData (iItem);
		v.push_back (dld);
	}

	if (v.size ())
	{
		if (_pwndDownloads->Get_DWWN () == DWWN_DELETED)
			_pwndDownloads->m_wndDeleted.ShowWindow (SW_HIDE);
		try 
		{
			_DldsMgr.RestoreDownloads (v);
		}
		catch (const std::exception& ex)
		{
			ASSERT (FALSE);
			vmsLogger::WriteLog("CDownloads_Deleted::OnDeletedRestore " + tstring(ex.what()));
		}
		catch (...)
		{
			ASSERT (FALSE);
			vmsLogger::WriteLog("CDownloads_Deleted::OnDeletedRestore unknown exception");
		}

		if (_pwndDownloads->Get_DWWN () == DWWN_DELETED)
			_pwndDownloads->m_wndDeleted.ShowWindow (SW_SHOW);
	}	
}

void CDownloads_Deleted::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	
	BOOL bCtrl = GetKeyState (VK_CONTROL) & 0x8000;

	switch (nChar)
	{
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

void CDownloads_Deleted::OnKeyDown(WORD wVK)
{
	switch (wVK)
	{
		case VK_DELETE:
			OnDeletedDelete ();
			break;

		case VK_TAB:
			_pwndDownloads->m_wndGroups.SetFocus ();
			break;
	}
}

void CDownloads_Deleted::OnForceUpdate()
{
	for (int i = 0; i < GetItemCount (); i++)
	{
		UpdateDownload (i);
	}
}

int CDownloads_Deleted::GetDownloadImage(vmsDownloadSmartPtr dld)
{
	if (dld->pMgr->IsDone ())
		return 1;	
	else
		return 0;
}

void CDownloads_Deleted::OnSortModeChanged()
{
	if (m_sortMode != LCSM_ASCENDING)
		m_sortMode = LCSM_ASCENDING;
	
	Sort ();
}

void CDownloads_Deleted::Sort()
{
	if (m_sortMode != LCSM_NONE)
		SortItems (_sortFunc, DWORD (this));
	else
	{
		DeleteAllItems ();
		for (int i = _DldsMgr.Get_DeletedDownloadCount () - 1; i >= 0; i--)
			AddDownload (_DldsMgr.Get_DeletedDownload (i));
	}
}

int CALLBACK CDownloads_Deleted::_sortFunc(LPARAM item1, LPARAM item2, LPARAM lp)
{
	CDownloads_Deleted* pThis = (CDownloads_Deleted*) lp;
	vmsDownloadSmartPtr dld1 = (fsDownload*) item1;
	vmsDownloadSmartPtr dld2 = (fsDownload*) item2;

	switch (pThis->m_iSortCol)
	{
		case 0:
			char szFile1 [10000];  char szFile2 [10000];
			CDownloads_Tasks::GetFileName (dld1, szFile1);
			CDownloads_Tasks::GetFileName (dld2, szFile2);
			return stricmp (szFile1, szFile2);
		
		case 1:
			UINT64 size1;
			UINT64 size2;
			size1 = dld1->pMgr->GetLDFileSize ();
			size2 = dld2->pMgr->GetLDFileSize ();
			
			if (size1 == _UI64_MAX)
				return size2 == _UI64_MAX ? 0 : 1;

			if (size2 == _UI64_MAX)
				return size1 == _UI64_MAX ? 0 : -1;

			if (size1 == size2)
				return 0;

			return size1 > size2 ? -1 : 1;

		case 2:
			UINT64 done1;
			UINT64 done2;
			done1 = dld1->pMgr->GetDownloadedBytesCount ();
			done2 = dld2->pMgr->GetDownloadedBytesCount ();

			if (done1 == done2)
				return 0;

			return done1 > done2 ? -1 : 1;

		case 3:
			UINT sects1, sects2;

			sects1 = dld1->pMgr->GetNumberOfSections ();
			sects2 = dld2->pMgr->GetNumberOfSections ();

			if (sects1 == sects2)
				return 0;

			return sects1 > sects2 ? -1 : 1;
	}

	return 0;
}

void CDownloads_Deleted::SelectDownload(vmsDownloadSmartPtr dld)
{
	int iItem = FindDownload (dld);

	if (iItem == -1)
		return;

	POSITION pos = GetFirstSelectedItemPosition ();
	
	while (pos)
		SetItemState (GetNextSelectedItem (pos), 0, LVIS_SELECTED | LVIS_FOCUSED);

	
	SetItemState (iItem, LVIS_FOCUSED | LVIS_SELECTED, LVIS_FOCUSED | LVIS_SELECTED);
	SetSelectionMark (iItem);
	EnsureVisible (iItem, FALSE);
}
