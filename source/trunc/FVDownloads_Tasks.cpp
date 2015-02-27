/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "FVDownloads_Tasks.h"
#include "Downloads_Tasks.h"
#include "MainFrm.h"
#include "FlashVideoDownloadsWnd.h"
#include "Dlg_CreateFVDownload.h"
#include "plugincmds.h"
#include "vmsDownloadsListHelper.h"
#include "Dlg_Download.h"
#include "vmsLogger.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CFVDownloads_Tasks::CFVDownloads_Tasks()
{
}

CFVDownloads_Tasks::~CFVDownloads_Tasks()
{
}

BEGIN_MESSAGE_MAP(CFVDownloads_Tasks, CListCtrlEx)
	//{{AFX_MSG_MAP(CFVDownloads_Tasks)
	ON_NOTIFY_REFLECT(LVN_GETDISPINFO, OnGetdispinfo)
	ON_WM_DRAWITEM()
	ON_WM_MEASUREITEM()
	ON_COMMAND(ID_FVDLD_CREATE, OnFvdldCreate)
	ON_COMMAND(ID_FVDLD_LAUNCH, OnFvdldLaunch)
	ON_COMMAND(ID_FVDLD_PASSTODLDS, OnFvdldPasstodlds)
	ON_COMMAND(ID_FVDLD_START, OnFvdldStart)
	ON_COMMAND(ID_FVDLD_STOP, OnFvdldStop)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_FVDLD_AUTOSTART, OnFvdldAutostart)
	ON_COMMAND(ID_FVDLD_DELETE, OnFvdldDelete)
	ON_COMMAND(ID_FVDLD_OPENFOLDER, OnFvdldOpenfolder)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_FVDLD_PROPERTIES, OnFvdldProperties)
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_FVDLD_CONVERT, OnFvdldConvert)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CFVDownloads_Tasks::Create(CWnd *pwndParent)
{
	CRect rc (0, 0, 50, 50);

	if (FALSE == CListCtrlEx::Create (HDS_DRAGDROP | LVS_REPORT | 
			LVS_OWNERDRAWFIXED | LVS_SHOWSELALWAYS | LVS_OWNERDATA | LVS_NOSORTHEADER,
			rc, pwndParent, 0x56783))
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
	
	ReadState ("FVDownloadsTasks");
	

	ShowWindow (SW_SHOW);

	return TRUE;
}

void CFVDownloads_Tasks::AddDownload(vmsDownloadSmartPtr dld, BOOL bPlaceToTop)
{
	if (bPlaceToTop)
		m_vDlds.insert (m_vDlds.begin (), dld);
	else
		m_vDlds.push_back (dld);
	
	VirtualView_ItemWillBeAdded (GetSysColor (COLOR_WINDOW), GetSysColor (COLOR_WINDOWTEXT), bPlaceToTop);
	SetItemCountEx (m_vDlds.size (), LVSICF_NOINVALIDATEALL | LVSICF_NOSCROLL);
}

void CFVDownloads_Tasks::OnGetdispinfo(NMHDR* pNMHDR, LRESULT* pResult) 
{
	LV_DISPINFO* pDispInfo = (LV_DISPINFO*)pNMHDR;
	LV_ITEM* pItem = &(pDispInfo)->item;

	try
	{
		vmsDownloadSmartPtr dld = m_vDlds [pItem->iItem];

		if (pItem->mask & LVIF_IMAGE)
		{
			pItem->iImage = CDownloads_Tasks::GetDownloadImage (dld);
			
		}

		if (pItem->mask & LVIF_TEXT)
		{
			int nSubItem = SubItemToSubItem (pItem->iSubItem);
			if (nSubItem != -1)
				lstrcpy (pItem->pszText, CDownloads_Tasks::GetDownloadText (dld, nSubItem));
		}

	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CFVDownloads_Tasks::OnGetdispinfo " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CFVDownloads_Tasks::OnGetdispinfo unknown exception");
	}
}

void CFVDownloads_Tasks::ApplyLanguage()
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

void CFVDownloads_Tasks::OnRClick()
{
	CMenu menu;
	menu.LoadMenu (IDM_FVDOWNLOADS);
	ApplyLanguageToMenu (&menu);
	CMenu *pPopup = menu.GetSubMenu (0);

	
	UpdateActiveDownload (0);

	
	UpdateMenu (pPopup);

	ClientToScreen (&m_rbPt);

	m_odmenu.Attach (&menu, FALSE);
	
	m_odmenu.SetImageList (&((CMainFrame*)AfxGetApp ()->m_pMainWnd)->m_imgsMenu, &((CMainFrame*)AfxGetApp ()->m_pMainWnd)->m_dimgsMenu);
	fsSetImage *pImages;
	int cImages;
	CFlashVideoDownloadsWnd::Plugin_GetMenuImages (&pImages, &cImages);
	m_odmenu.SetImages (pImages, cImages);

	fsSetImage img (11, 0, 0);
	m_odmenu.SetImages (&img, 3, NULL, TRUE);

	
	pPopup->TrackPopupMenu (TPM_RIGHTBUTTON | TPM_TOPALIGN | TPM_LEFTALIGN,	
		m_rbPt.x, m_rbPt.y, this);
	m_odmenu.Detach ();

	menu.DestroyMenu ();
}

void CFVDownloads_Tasks::UpdateMenu(CMenu *pPopup)
{
	if (GetSelectedCount () == 0)
	{
		pPopup->EnableMenuItem (ID_FVDLD_START, MF_BYCOMMAND | MF_GRAYED);
		pPopup->EnableMenuItem (ID_FVDLD_STOP, MF_BYCOMMAND | MF_GRAYED);
		pPopup->EnableMenuItem (ID_FVDLD_AUTOSTART, MF_BYCOMMAND | MF_GRAYED);
		pPopup->EnableMenuItem (ID_FVDLD_DELETE, MF_BYCOMMAND | MF_GRAYED);
		pPopup->EnableMenuItem (ID_FVDLD_LAUNCH, MF_BYCOMMAND | MF_GRAYED);
		pPopup->EnableMenuItem (ID_FVDLD_CONVERT, MF_BYCOMMAND | MF_GRAYED);
		pPopup->EnableMenuItem (ID_FVDLD_OPENFOLDER, MF_BYCOMMAND | MF_GRAYED);
		pPopup->EnableMenuItem (ID_FVDLD_PASSTODLDS, MF_BYCOMMAND | MF_GRAYED);
		pPopup->EnableMenuItem (ID_FVDLD_PROPERTIES, MF_BYCOMMAND | MF_GRAYED);
	}
	else
	{
		DLDS_LIST v;
		GetSelectedDownloads (v);
	
		BOOL bRunning, bStopped, bCompleted, bAuto, bNotAuto;
		vmsDownloadsListHelper::GetStat (v, &bRunning, &bStopped, &bCompleted, &bAuto, &bNotAuto);

		if (bRunning == FALSE && bAuto == FALSE)
			pPopup->EnableMenuItem (ID_FVDLD_STOP, MF_BYCOMMAND | MF_GRAYED);

		if (bStopped == FALSE)
			pPopup->EnableMenuItem (ID_FVDLD_START, MF_BYCOMMAND | MF_GRAYED);

		if (v [0]->pMgr->IsDone () == FALSE)
		{
			pPopup->EnableMenuItem (ID_FVDLD_LAUNCH, MF_BYCOMMAND | MF_GRAYED);
			pPopup->EnableMenuItem (ID_FVDLD_CONVERT, MF_BYCOMMAND | MF_GRAYED);
		}

		if (bNotAuto == FALSE)
			pPopup->CheckMenuItem (ID_FVDLD_AUTOSTART, MF_CHECKED | MF_BYCOMMAND);
	}
}	

void CFVDownloads_Tasks::ApplyLanguageToMenu(CMenu *menu)
{
	CString str; 

	menu->ModifyMenu (0, MF_BYPOSITION|MF_STRING, 0, LS (L_FVDOWNLOADS));
	
	str = LS (L_CREATEFVDLD); str += "\tIns";
	menu->ModifyMenu (ID_FVDLD_CREATE, MF_BYCOMMAND|MF_STRING, ID_FVDLD_CREATE, str);

	str = LS (L_STARTDLDS); str += "\tShift+S";
	menu->ModifyMenu (ID_FVDLD_START, MF_BYCOMMAND|MF_STRING, ID_FVDLD_START, str);
	str = LS (L_STOPDLDS); str += "\tShift+O";
	menu->ModifyMenu (ID_FVDLD_STOP, MF_BYCOMMAND|MF_STRING, ID_FVDLD_STOP, str);
	str = LS (L_DELETEDLD); str += "\tDel (Shift+Del)";
	menu->ModifyMenu (ID_FVDLD_DELETE, MF_BYCOMMAND|MF_STRING, ID_FVDLD_DELETE, str);
	menu->ModifyMenu (ID_FVDLD_LAUNCH, MF_BYCOMMAND|MF_STRING, ID_FVDLD_LAUNCH, LS (L_LAUNCHFILE));
	menu->ModifyMenu (ID_FVDLD_CONVERT, MF_BYCOMMAND|MF_STRING, ID_FVDLD_CONVERT, LS (L_CONVERT_MEDIA_FILE));	
	menu->ModifyMenu (ID_FVDLD_OPENFOLDER, MF_BYCOMMAND|MF_STRING, ID_FVDLD_OPENFOLDER, LS (L_OPENFOLDER));
	menu->ModifyMenu (ID_FVDLD_PASSTODLDS, MF_BYCOMMAND|MF_STRING, ID_FVDLD_PASSTODLDS, LS (L_PASSTODLDS));

	str = LS (L_AUTOSTARTDLD); str += '\t';
	menu->ModifyMenu (ID_FVDLD_AUTOSTART, MF_BYCOMMAND|MF_STRING, ID_FVDLD_AUTOSTART, str);

	str = LS (L_DLDPROP); str += "\tAlt+Enter";
	menu->ModifyMenu (ID_FVDLD_PROPERTIES, MF_BYCOMMAND|MF_STRING, ID_FVDLD_PROPERTIES, str);
}

void CFVDownloads_Tasks::OnDrawItem(int , LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	m_odmenu.OnDrawItem (lpDrawItemStruct);
}

void CFVDownloads_Tasks::OnMeasureItem(int , LPMEASUREITEMSTRUCT lpMeasureItemStruct)
{
	m_odmenu.OnMeasureItem (lpMeasureItemStruct);
}

void CFVDownloads_Tasks::OnFvdldCreate() 
{
	_pwndFVDownloads->CreateDownload ();
	SetFocus ();
}

void CFVDownloads_Tasks::OnFvdldLaunch() 
{
	POSITION pos = GetFirstSelectedItemPosition ();
	
	while (pos)
	{
		vmsDownloadSmartPtr dld = m_vDlds [GetNextSelectedItem (pos)];
		if (dld->pMgr->IsDone ())
			_DldsMgr.LaunchDownload (dld);
	}	
}

void CFVDownloads_Tasks::OnFvdldPasstodlds() 
{
	DLDS_LIST v;
	GetSelectedDownloads (v);
	if (v.size ())
	{
		_pwndDownloads->ShowDownloads (v);
		((CMainFrame*)AfxGetApp ()->m_pMainWnd)->SetActivePlugin (0);
	}
}

void CFVDownloads_Tasks::OnFvdldStart() 
{
	DLDS_LIST v;
	POSITION pos = GetFirstSelectedItemPosition ();
	while (pos)
	{
		int nItem = GetNextSelectedItem (pos);
		v.push_back (m_vDlds [nItem]);
	}
	_DldsMgr.StartDownloads (v, TRUE);	
}

void CFVDownloads_Tasks::OnFvdldStop() 
{
	DLDS_LIST v;
	POSITION pos = GetFirstSelectedItemPosition ();
	while (pos)
	{
		int nItem = GetNextSelectedItem (pos);
		vmsDownloadSmartPtr dld = m_vDlds [nItem];
		if (dld->pMgr->IsRunning ())
			v.push_back (dld);
		else if (dld->bAutoStart)
		{
			dld->bAutoStart = FALSE;
			dld->setDirty();
			_pwndDownloads->UpdateDownload (dld);
		}
	}
	if (v.size ())
		_DldsMgr.StopDownloads (v, TRUE);	
}

void CFVDownloads_Tasks::GetSelectedDownloads(DLDS_LIST_REF v)
{
	POSITION pos = GetFirstSelectedItemPosition ();
	while (pos)
	{
		int nItem = GetNextSelectedItem (pos);
		v.push_back (m_vDlds [nItem]);
	}
}

void CFVDownloads_Tasks::UpdateDownload(vmsDownloadSmartPtr dld)
{
	int nIndex = FindIndex (dld);
	if (nIndex != -1)
		RedrawItems (nIndex, nIndex);
}

void CFVDownloads_Tasks::WillBeDeleted(vmsDownloadSmartPtr dld)
{
	int nIndex = FindIndex (dld);
	if (nIndex != -1)
	{
		VirtualView_ItemWillBeDeleted (nIndex);
		m_vDlds.erase (m_vDlds.begin () + nIndex);
		SetItemCount (m_vDlds.size ());
		if (m_pActiveDownload == dld)
		{
			m_pActiveDownload = NULL;
			_pwndFVDownloads->SetActiveDownload (NULL);
		}
	}
}

int CFVDownloads_Tasks::FindIndex(vmsDownloadSmartPtr dld)
{
	for (size_t i = 0; i < m_vDlds.size (); i++)
	{
		if (m_vDlds [i] == dld)
			return i;
	}

	return -1;
}

void CFVDownloads_Tasks::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	CListCtrlEx::OnLButtonDblClk(nFlags, point);
	CallSelectedDownload (TRUE);
}

void CFVDownloads_Tasks::OnFvdldAutostart() 
{
	DLDS_LIST v;
	GetSelectedDownloads (v);
	if (v.size () == 0)
		return;

	BOOL b = TRUE;
	vmsDownloadsListHelper::GetStat (v, NULL, NULL, NULL, NULL, &b);

	for (size_t i = 0; i < v.size (); i++) {
		v [i]->bAutoStart = b;
		v [i]->setDirty();
	}

	_pwndDownloads->UpdateAllDownloads ();
	_DldsMgr.setNeedProcessDownloads ();
}

void CFVDownloads_Tasks::OnFvdldDelete() 
{
	DeleteSelected (FALSE);
}

void CFVDownloads_Tasks::OnFvdldOpenfolder() 
{
	fs::list <CString> vOpened;
	POSITION pos = GetFirstSelectedItemPosition ();

	while (pos)
	{
		vmsDownloadSmartPtr dld = m_vDlds [GetNextSelectedItem (pos)];
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

void CFVDownloads_Tasks::DeleteSelected(BOOL bDontConfirmFileDeleting)
{
	if (bDontConfirmFileDeleting || _App.Deleted_ConfirmDeletion ())
	if (IDNO == MessageBox (bDontConfirmFileDeleting ? LS (L_DLDWBDELETEDFROMDISK) : LS (L_AREYOUSURE), LS (L_CONFIRMATION), MB_YESNO|MB_ICONQUESTION))
	{
		SetFocus ();
		return;
	}

	DLDS_LIST v;
	GetSelectedDownloads (v);
	if (v.size () == 0)
		return;

	_pwndDownloads->DeleteDownloads (v, TRUE, bDontConfirmFileDeleting);
	UpdateActiveDownload (0);
}

void CFVDownloads_Tasks::OnKeyDown(WORD wVK)
{
	switch (wVK)
	{
		case VK_DELETE:
			
			DeleteSelected (GetKeyState (VK_SHIFT) & 0x8000);
			break;

		case VK_RETURN:
			if (GetKeyState (VK_MENU) & 0x8000)
				ShowSelectedDldsProperties ();
			else
				CallSelectedDownload (TRUE);
			break;

		case VK_APPS:
			CalcCoordsForCurSel ();
			OnRClick ();
			break;
	}
}

void CFVDownloads_Tasks::CallSelectedDownload(BOOL bPropertiesInsteadOfPass)
{
	POSITION pos = GetFirstSelectedItemPosition ();
	if (pos == NULL)
		return;

	vmsDownloadSmartPtr dld = m_vDlds [GetNextSelectedItem (pos)];

	if (pos == NULL && dld->pMgr->IsDone ())
	{
		OnFvdldLaunch ();
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
		if (bPropertiesInsteadOfPass)
			ShowSelectedDldsProperties ();
		else
			OnFvdldPasstodlds ();
	}
}

void CFVDownloads_Tasks::CalcCoordsForCurSel()
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

void CFVDownloads_Tasks::OnRButtonDown(UINT nFlags, CPoint point) 
{
	m_rbPt = point;	
	CListCtrlEx::OnRButtonDown(nFlags, point);
}

void CFVDownloads_Tasks::ShowSelectedDldsProperties()
{
	POSITION pos = GetFirstSelectedItemPosition ();
	DLDS_LIST vDlds;
	DLDS_LIST vBtDlds;

	if (pos == NULL)
		return;

	while (pos)
	{
		int iItem = GetNextSelectedItem (pos);
		vmsDownloadSmartPtr dld = m_vDlds [iItem];
		if (dld->pMgr->GetDownloadMgr () != NULL)
			vDlds.push_back (dld);
		else if (dld->pMgr->GetBtDownloadMgr () != NULL)
			vBtDlds.push_back (dld);
	}

	if (vDlds.size () >= vBtDlds.size ())
		_pwndDownloads->OnDownloadProperties (vDlds);
	else
		_pwndDownloads->OnBtDownloadProperties (vBtDlds);

	SetFocus ();
}

void CFVDownloads_Tasks::OnFvdldProperties() 
{
	ShowSelectedDldsProperties ();
}

void CFVDownloads_Tasks::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	BOOL bShift = GetKeyState (VK_SHIFT) & 0x8000;
	BOOL bCtrl = GetKeyState (VK_CONTROL) & 0x8000;

	switch (nChar)
	{
		case 'S':
			if (bShift)
			{
				OnFvdldStart ();
				return;
			}
			break;

		case 'O':
			if (bShift)
			{
				OnFvdldStop ();
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

int CFVDownloads_Tasks::OnUpdateToolBar(UINT nID)
{
	BOOL bEnabled = TRUE;	
	BOOL bChecked = FALSE;	

	
	if (nID == ID_DLD_VID_PLAY || nID == ID_DLD_VID_PAUSE ||
			nID == ID_DLD_VID_STOP || nID == ID_DLD_VID_MUTE)
	{
		_pwndFVDownloads->m_wndPreview.UpdateCommand (nID, &bEnabled, &bChecked);

		int iState = bEnabled ? WGP_CMDITEMSTATE_ENABLED : WGP_CMDITEMSTATE_DISABLED;
		if (bChecked) iState |= WGP_CMDITEMSTATE_CHECKED;
		return iState;
	}

	if (GetSelectedCount () == 0)
	{
		switch (nID)
		{
			case ID_FVDLD_START:
			case ID_FVDLD_STOP:
			case ID_FVDLD_DELETE:
			case ID_FVDLD_OPENFOLDER:
			case ID_FVDLD_PROPERTIES:
			case ID_FVDLD_LAUNCH:
			case ID_FVDLD_CONVERT:
			case ID_FVDLD_AUTOSTART:
			case ID_FVDLD_PASSTODLDS:
				bEnabled = FALSE;
			break;
		}
	}
	else
	{
		DLDS_LIST v;
		GetSelectedDownloads (v);
	
		BOOL bRunning, bStopped, bCompleted, bAuto, bNotAuto;
		vmsDownloadsListHelper::GetStat (v, &bRunning, &bStopped, &bCompleted, &bAuto, &bNotAuto);

		switch (nID)
		{
		case ID_FVDLD_STOP:
			if (bRunning == FALSE && bAuto == FALSE)
				bEnabled = FALSE;
			break;

		case ID_FVDLD_START:
			if (bStopped == FALSE)
				bEnabled = FALSE;
			break;

		case ID_FVDLD_LAUNCH:
		case ID_FVDLD_CONVERT:
			if (v [0]->pMgr->IsDone () == FALSE)
				bEnabled = FALSE;
			break;

		case ID_FVDLD_AUTOSTART:
			if (bNotAuto == FALSE)
				bEnabled = FALSE;
			break;
		}
	}

	int iState = bEnabled ? WGP_CMDITEMSTATE_ENABLED : WGP_CMDITEMSTATE_DISABLED;
	if (bChecked) iState |= WGP_CMDITEMSTATE_CHECKED;

	return iState;
}

void CFVDownloads_Tasks::SaveState()
{
	CListCtrlEx::SaveState ("FVDownloadsTasks");
}

void CFVDownloads_Tasks::UpdateActiveDownload(int adjSelected)
{
	try 
	{
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

			dld = m_vDlds [iItem];
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

				dld = m_vDlds [iItem];
			}
		}

		
		if (dld != m_pActiveDownload)
		{
			m_pActiveDownload = dld;
			_pwndFVDownloads->SetActiveDownload (m_pActiveDownload);
		}

	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CFVDownloads_Tasks::UpdateActiveDownload " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CFVDownloads_Tasks::UpdateActiveDownload unknown exception");
	}
}

void CFVDownloads_Tasks::OnClick()
{
	UpdateActiveDownload (0);
}

void CFVDownloads_Tasks::OnItemChanged(NM_LISTVIEW *pLV)
{
	if (pLV->uNewState != pLV->uOldState) 
		UpdateActiveDownload (0);
}

void CFVDownloads_Tasks::OnFvdldConvert() 
{
	_pwndFVDownloads->m_wndPreview.Convert ();	
}
