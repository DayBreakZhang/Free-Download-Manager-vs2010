/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "Uploads_Tasks.h"
#include "UploadsWnd.h"
#include "misc.h"
#include "cmds.h"
#include "resource.h"
#include "UploadPropertiesSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CUploads_Tasks::CUploads_Tasks()
{
}

CUploads_Tasks::~CUploads_Tasks()
{
}

BEGIN_MESSAGE_MAP(CUploads_Tasks, CListCtrlEx)
	//{{AFX_MSG_MAP(CUploads_Tasks)
	ON_WM_DRAWITEM()
	ON_WM_MEASUREITEM()
	ON_COMMAND(ID_UPL_CREATENEW, OnUplCreatenew)
	ON_COMMAND(ID_UPL_START, OnUplStart)
	ON_COMMAND(ID_UPL_STOP, OnUplStop)
	ON_COMMAND(ID_UPL_PROPERTIES, OnUplProperties)
	ON_COMMAND(ID_UPL_DELETE, OnUplDelete)
	ON_WM_KEYDOWN()
	ON_WM_CHAR()
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_UPL_COPYURL, OnUplCopyurl)
	ON_NOTIFY_REFLECT(LVN_GETDISPINFO, OnGetdispinfo)
	ON_COMMAND(ID_UPL_OPENINBROWSER, OnUplOpeninbrowser)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CUploads_Tasks::Create(CWnd *pParent)
{
	CRect rc (0, 0, 50, 50);

	if (FALSE == CListCtrl::Create (LVS_REPORT | LVS_NOSORTHEADER | LVS_SHOWSELALWAYS |
			LVS_OWNERDRAWFIXED | LVS_OWNERDATA, rc, pParent, 0x71a339))
		return FALSE;

	SetExtendedStyle (LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_INFOTIP);

	

	m_images.Create (16, 17, ILC_COLOR24 | ILC_MASK, 7, 1);
	CBitmap bmp;
	bmp.Attach (_pDllCaller->GetBitmap (BMP_FOR_TASKSLIST));
  	
	m_images.Add (&bmp, RGB (255, 0, 255));
	SetImageList (&m_images, LVSIL_SMALL);

	m_selimages.Create (16, 17, ILC_COLOR24 | ILC_MASK, 7, 1);
	CBitmap bmp2;
	bmp2.Attach (_pDllCaller->GetBitmap (BMP_FOR_TASKSLIST_SEL));
	m_selimages.Add (&bmp2, RGB (255, 0, 255));
	SetSelectedImages (&m_selimages);

	
	m_imgsMenu.Create (16, 15, ILC_COLOR24 | ILC_MASK, 6, 1);
	CBitmap bmp3;
	bmp3.Attach (_pDllCaller->GetBitmap (BMP_FOR_UPLOADSMENU));
	m_imgsMenu.Add (&bmp3, RGB (255, 0, 255));
	
	m_dimgsMenu.Create (16, 15, ILC_COLOR24 | ILC_MASK, 6, 1);
	CBitmap bmp4;
	bmp4.Attach (_pDllCaller->GetBitmap (BMP_FOR_UPLOADSMENU_D));
	m_dimgsMenu.Add (&bmp4, RGB (255, 0, 255));

	InsertColumn (0, "", LVCFMT_LEFT, 200, 0);
	InsertColumn (1, "", LVCFMT_LEFT, 100, 0);
	InsertColumn (2, "", LVCFMT_LEFT, 50, 0);
	InsertColumn (3, "", LVCFMT_LEFT, 100, 0);
	InsertColumn (4, "", LVCFMT_LEFT, 60, 0);
	InsertColumn (5, "", LVCFMT_LEFT, 70, 0);
	InsertColumn (6, "", LVCFMT_LEFT, 120, 0);
	
	ReadState ("UploadsTasks");
	ApplyLanguage ();

	ShowWindow (SW_SHOW);

	return TRUE;
}

void CUploads_Tasks::ApplyLanguage()
{
	SetColumnText (0, "URL");
	SetColumnText (1, LS (L_NAME));
	SetColumnText (2, LS (L_SIZE));
	SetColumnText (3, LS (L_UPLOADED));
	SetColumnText (4, LS (L_TIMELEFT));
	SetColumnText (5, LS (L_SPEED));
	SetColumnText (6, LS (L_ADDED));
}

#include "CoreDll.h"

void CUploads_Tasks::OnRClick()
{
	AFX_MANAGE_STATE (AfxGetStaticModuleState ());

	CMenu menu;
	menu.LoadMenu (IDM_UPLOADS);
	CMenu *pPopup = menu.GetSubMenu (0);
	ApplyLanguageToMenu (pPopup);

	
	UpdateMenu (pPopup);

	CPoint pt;
	GetCursorPos (&pt);

	m_odmenu.Attach (&menu, FALSE);
	
	m_odmenu.SetImageList (&m_imgsMenu, &m_dimgsMenu);
	
	fsSetImage images [] = 
	{
		fsSetImage (ID_UPL_CREATENEW, 0),
		fsSetImage (ID_UPL_START, 1),
		fsSetImage (ID_UPL_STOP, 2),
		
     	
		fsSetImage (ID_UPL_PROPERTIES, 6),
		fsSetImage (ID_UPL_DELETE, 7),
	};

	m_odmenu.SetImages (images, sizeof (images) / sizeof (fsSetImage));

	fsSetImage img (11, 0, 0);
	m_odmenu.SetImages (&img, 3, NULL, TRUE);

	
	pPopup->TrackPopupMenu (TPM_RIGHTBUTTON | TPM_TOPALIGN | TPM_LEFTALIGN,	pt.x, pt.y, this);
	m_odmenu.Detach ();

	menu.DestroyMenu ();
}

void CUploads_Tasks::UpdateMenu(CMenu *pPopup)
{
	try{
	if (GetSelectedCount () == 0)
	{
		pPopup->EnableMenuItem (ID_UPL_START, MF_BYCOMMAND | MF_GRAYED);
		pPopup->EnableMenuItem (ID_UPL_STOP, MF_BYCOMMAND | MF_GRAYED);
		pPopup->EnableMenuItem (ID_UPL_DELETE, MF_BYCOMMAND | MF_GRAYED);
		pPopup->EnableMenuItem (ID_UPL_PROPERTIES, MF_BYCOMMAND | MF_GRAYED);
		pPopup->EnableMenuItem (ID_UPL_COPYURL, MF_BYCOMMAND | MF_GRAYED);
		pPopup->EnableMenuItem (ID_UPL_OPENINBROWSER, MF_BYCOMMAND | MF_GRAYED);
	}
	else
	{
		BOOL bHasRunning, bHasStopped, bHasDone;
		GetSelectedListState (bHasRunning, bHasStopped, bHasDone);

		if (bHasStopped == FALSE)
			pPopup->EnableMenuItem (ID_UPL_START, MF_BYCOMMAND | MF_GRAYED);

		if (bHasRunning == FALSE)
			pPopup->EnableMenuItem (ID_UPL_STOP, MF_BYCOMMAND | MF_GRAYED);
	}
	} catch (...) {
		UpdateMenu (pPopup);
	}
}

void CUploads_Tasks::OnDrawItem(int , LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	m_odmenu.OnDrawItem (lpDrawItemStruct);
}

void CUploads_Tasks::OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct) 
{
	m_odmenu.OnMeasureItem (lpMeasureItemStruct);
}

void CUploads_Tasks::OnUplCreatenew() 
{
	_pwndUploads->CreateNewUpload ();
}

int CUploads_Tasks::OnUpdateToolBar(UINT nID)
{
	BOOL bEnabled = TRUE;	
	BOOL bChecked = FALSE;	

	if (GetSelectedCount () == 0)
	{
		switch (nID)
		{
			case ID_UPL_START:
			case ID_UPL_STOP:
			case ID_UPL_DELETE:
			case ID_UPL_PROPERTIES:
				bEnabled = FALSE;
			break;
		}
	}
	else
	{
		BOOL bHasRunning, bHasStopped, bHasDone;
		GetSelectedListState(bHasRunning, bHasStopped, bHasDone);

		switch (nID)
		{
		case ID_UPL_START:
			bEnabled = bHasStopped;
			break;

		case ID_UPL_STOP:
			bEnabled = bHasRunning;
			break;
		}
	}

	int iState = bEnabled ? WGP_CMDITEMSTATE_ENABLED : WGP_CMDITEMSTATE_DISABLED;
	if (bChecked) iState |= WGP_CMDITEMSTATE_CHECKED;

	return iState;
}

void CUploads_Tasks::OnUploadCountChanged()
{
	BOOL bErase = GetItemCount () > _UplsMgr.GetCount ();

	VirtualView_AllItemsWillBeDeleted ();

	for (int i = 0; i < _UplsMgr.GetCount (); i++)
		VirtualView_ItemWillBeAdded (GetSysColor (COLOR_WINDOW), GetSysColor (COLOR_WINDOWTEXT), FALSE);

	SetItemCountEx (_UplsMgr.GetCount (), LVSICF_NOINVALIDATEALL | LVSICF_NOSCROLL);

	if (bErase)
		Invalidate (TRUE);
}

void CUploads_Tasks::OnGetdispinfo(NMHDR *pNMHDR, LRESULT *pResult)
{
	LV_DISPINFO* pDispInfo = (LV_DISPINFO*)pNMHDR;
	LV_ITEM* pItem= &(pDispInfo)->item;

	try{

	vmsUploadSmartPtr upl = _UplsMgr.GetUpload (pItem->iItem);

	if (pItem->mask & LVIF_IMAGE)
        pItem->iImage = GetUploadImage (upl);

	if (pItem->mask & LVIF_TEXT)
	{
		int nSubItem = SubItemToSubItem (pItem->iSubItem);
		if (nSubItem != -1)
			lstrcpy (pItem->pszText, GetUploadText (upl, nSubItem));
	}

	}catch (...) {}
}

int CUploads_Tasks::GetUploadImage(vmsUploadSmartPtr upl)
{
	if (upl->pMgr->IsDone ())
		return 1;	

	if (upl->pMgr->IsRunning ())
	{
		return 3;	
		
	}

	return upl->bAutostart ? 5 : 0;	
}

CString CUploads_Tasks::GetUploadText(vmsUploadSmartPtr upl, int nSubItem)
{
	switch (nSubItem)
	{
	case 0: 
		return upl->pMgr->get_PackageUrl ();

	case 1:	
		return upl->pMgr->get_PackageName ();

	case 2:	
		if (upl->pMgr->GetTotalSize () == _UI64_MAX)
			return "";
		return BytesToString (upl->pMgr->GetTotalSize ());

	case 3:	
	{
		if (upl->pMgr->GetTotalSize () == _UI64_MAX)
			return "";
		CString str;
		float val;
		char szDim [100];
		if (_pDllCaller->GetSettings ()->ShowSizesInBytes () == FALSE)
		{
			BytesToXBytes (upl->pMgr->GetUploadedByteCount (), &val, szDim);
			str.Format ("%d%% [%.*g %s]", (int)((double)(INT64)upl->pMgr->GetUploadedByteCount () / 
				(INT64)upl->pMgr->GetTotalSize () * 100), val > 999 ? 4 : 3, val, szDim);
		}
		else
		{
			CString s = fsBytesToStr (upl->pMgr->GetUploadedByteCount (), TRUE);
			str.Format ("%d%% [%s]", (int)((double)(INT64)upl->pMgr->GetUploadedByteCount () / 
				(INT64)upl->pMgr->GetTotalSize () * 100), s);
		}
		return str;
	}

	case 4: 
		if (upl->pMgr->IsRunning () == FALSE || 
				upl->pMgr->GetSpeed () == 0)
			return "";
		return fsTimeInSecondsToStr (UINT ((upl->pMgr->GetTotalSize () - upl->pMgr->GetUploadedByteCount ()) / 
			upl->pMgr->GetSpeed ()));

	case 5: 
		return BytesToString (upl->pMgr->GetSpeed ()) + "/" + LS (L_S);

	case 6: 
		CString str;
		char szDate [100], szTime [100];
		FileTimeToStr (&upl->dateAdded, szDate, szTime, TRUE);
		str = szDate; str += ", "; str += szTime;
		return str;		
	}

	ASSERT (FALSE);
	return "";
}

void CUploads_Tasks::UpdateUpload(vmsUploadSmartPtr upl, BOOL bRedraw)
{
	for (int i = 0; i < _UplsMgr.GetCount (); i++)
	{
		if (_UplsMgr.GetUpload (i) == upl)
		{
			UpdateUpload (i, bRedraw);
			return;
		}
	}
}

void CUploads_Tasks::UpdateUpload(int nIndex, BOOL bRedraw)
{
	if (bRedraw)
		RedrawItems (nIndex, nIndex);
}

void CUploads_Tasks::OnItemChanged(NM_LISTVIEW *pLV)
{
	if (pLV->uNewState != pLV->uOldState)
	{
		if (pLV->iItem != -1)
		{
			_pwndUploads->m_wndLog.set_CurrentUpload (
				_UplsMgr.GetUpload (pLV->iItem));
		}
	}
}

void CUploads_Tasks::OnUplStart() 
{
	UPLS_LIST v;

	POSITION pos = GetFirstSelectedItemPosition ();
	while (pos)
		v.push_back (_UplsMgr.GetUpload (GetNextSelectedItem (pos)));

	_UplsMgr.StartUploads (v);	
}

void CUploads_Tasks::OnUplStop() 
{
	UPLS_LIST v;

	POSITION pos = GetFirstSelectedItemPosition ();
	while (pos)
		v.push_back (_UplsMgr.GetUpload (GetNextSelectedItem (pos)));

	_UplsMgr.StopUploads (v, TRUE);
}

void CUploads_Tasks::OnUplProperties() 
{
	AFX_MANAGE_STATE (AfxGetStaticModuleState ());

	POSITION pos = GetFirstSelectedItemPosition ();
	if (pos == NULL)
		return;

	CUploadPropertiesSheet sheet (LS (L_UPLOAD_PROPERTIES), this);
	sheet.set_Upload (_UplsMgr.GetUpload (GetNextSelectedItem (pos)));
	_DlgMgr.DoModal (&sheet);
}

void CUploads_Tasks::OnUplDelete() 
{
	UPLS_LIST v;

	POSITION pos = GetFirstSelectedItemPosition ();
	while (pos)
		v.push_back (_UplsMgr.GetUpload (GetNextSelectedItem (pos)));

	if (v.size ())
	{
		if (IDYES == MessageBox (LS (L_AREYOUSURE), LS (L_CONFIRMATION), MB_ICONQUESTION | MB_YESNO))
			_UplsMgr.DeleteUploads (v);
		_pwndUploads->m_wndLog.set_CurrentUpload (NULL);
		SetFocus ();
	}
}

void CUploads_Tasks::GetSelectedListState(BOOL &bHasRunning, BOOL &bHasStopped, BOOL &bHasDone)
{
	
	
	
	bHasRunning = FALSE;
	
	bHasStopped = FALSE; 
	
	bHasDone = FALSE;
	
	
	POSITION pos = GetFirstSelectedItemPosition ();
	while (pos && 
		(bHasRunning == FALSE || bHasStopped == FALSE || bHasDone == FALSE))
	{
		int iItem = GetNextSelectedItem (pos);
		vmsUploadSmartPtr upl = _UplsMgr.GetUpload (iItem);

		if (bHasRunning == FALSE && upl->pMgr->IsRunning ())
			bHasRunning = TRUE;

		if (bHasRunning == FALSE && upl->bAutostart && upl->pMgr->IsDone () == FALSE)
			bHasRunning = TRUE;

		if (bHasStopped == FALSE && upl->pMgr->IsRunning () == FALSE && 
				upl->pMgr->IsDone () == FALSE)
			bHasStopped = TRUE;

		if (bHasDone == FALSE && upl->pMgr->IsDone ())
			bHasDone = TRUE;
	}
}

void CUploads_Tasks::OnKeyDown(WORD wVK)
{
	switch (wVK)
	{
		case VK_DELETE:
			OnUplDelete ();
		break;

		case VK_RETURN:
			OnUplProperties ();
		break;

		case VK_APPS:
			OnRClick ();
		break;
	}
}

void CUploads_Tasks::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	BOOL bShift = GetKeyState (VK_SHIFT) & 0x8000;
	BOOL bCtrl = GetKeyState (VK_CONTROL) & 0x8000;

	switch (nChar)
	{
		case 'S':
			if (bShift)
			{
				OnUplStart ();
				return;
			}
			break;

		case 'O':
			if (bShift)
			{
				OnUplStop ();
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

void CUploads_Tasks::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	switch (nChar)
	{
		case 'S':
		case 'O':
			if (GetKeyState (VK_SHIFT) & 0x8000)
				return;
	}
	
	CListCtrlEx::OnChar(nChar, nRepCnt, nFlags);
}

void CUploads_Tasks::ApplyLanguageToMenu(CMenu *menu)
{
	CString str = LS (L_UPLOADFILES); str += "\tIns";
	menu->ModifyMenu (ID_UPL_CREATENEW, MF_BYCOMMAND|MF_STRING, ID_UPL_CREATENEW, str);

	str = LS (L_START_UPLOAD); str += "\tShift+S";
	menu->ModifyMenu (ID_UPL_START, MF_BYCOMMAND|MF_STRING, ID_UPL_START, str);
	str = LS (L_STOP_UPLOAD); str += "\tShift+O";
	menu->ModifyMenu (ID_UPL_STOP, MF_BYCOMMAND|MF_STRING, ID_UPL_STOP, str);

	str = LS (L_DELETE); str += "\tDel";
	menu->ModifyMenu (ID_UPL_DELETE, MF_BYCOMMAND|MF_STRING, ID_UPL_DELETE, str);

	str = LS (L_PROPERTIES); str += "\tEnter";
	menu->ModifyMenu (ID_UPL_PROPERTIES, MF_BYCOMMAND|MF_STRING, ID_UPL_PROPERTIES, str);

	menu->ModifyMenu (ID_UPL_COPYURL, MF_BYCOMMAND|MF_STRING, ID_UPL_COPYURL, LS (L_URLTOCLIPBOARD));

	menu->ModifyMenu (ID_UPL_OPENINBROWSER, MF_BYCOMMAND|MF_STRING, ID_UPL_OPENINBROWSER, LS (L_OPEN_IN_BROWSER));
}

void CUploads_Tasks::GetMenuCommandState(UINT nCmd, BOOL &bEnabled, BOOL &bChecked)
{
	bEnabled = TRUE;
	bChecked = FALSE;

	if (GetSelectedCount () == 0)
	{
		switch (nCmd)
		{
			case ID_UPL_START:
			case ID_UPL_STOP:
			case ID_UPL_DELETE:
			case ID_UPL_PROPERTIES:
			case ID_UPL_COPYURL:
			case ID_UPL_OPENINBROWSER:
				bEnabled = FALSE;
			break;
		}
	}
	else
	{
		BOOL bHasRunning, bHasStopped, bHasDone;
		GetSelectedListState (bHasRunning, bHasStopped, bHasDone);

		switch (nCmd)
		{
		case ID_UPL_START:
			bEnabled = bHasStopped;
			break;

		case ID_UPL_STOP:
			bEnabled = bHasRunning;
			break;
		}
	}
}

void CUploads_Tasks::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	CListCtrlEx::OnLButtonDblClk(nFlags, point);
	
	CallSelectedUpload ();
}

void CUploads_Tasks::OnUplCopyurl() 
{
	POSITION pos = GetFirstSelectedItemPosition ();
	if (pos == NULL)
		return;

	vmsUploadSmartPtr upl = _UplsMgr.GetUpload (GetNextSelectedItem (pos));

	LPCSTR psz = upl->pMgr->get_PackageUrl ();

	vmsSetClipboardText (psz);	
}

void CUploads_Tasks::SelectLastUpload()
{
	POSITION pos = GetFirstSelectedItemPosition ();
	
	while (pos)
		SetItemState (GetNextSelectedItem (pos), 0, LVIS_SELECTED | LVIS_FOCUSED);

	int iItem = GetItemCount () - 1;

	SetItemState (iItem, LVIS_FOCUSED | LVIS_SELECTED, LVIS_FOCUSED | LVIS_SELECTED);
	SetSelectionMark (iItem);
	EnsureVisible (iItem, FALSE);
}

extern void fsOpenUrlInBrowser (LPCSTR pszUrl);

void CUploads_Tasks::OnUplOpeninbrowser() 
{
	POSITION pos = GetFirstSelectedItemPosition ();
	if (pos == NULL)
		return;

	vmsUploadSmartPtr upl = _UplsMgr.GetUpload (GetNextSelectedItem (pos));

	LPCSTR psz = upl->pMgr->get_PackageUrl ();
	if (psz && *psz)
		fsOpenUrlInBrowser (psz);
}

void CUploads_Tasks::CallSelectedUpload()
{
	POSITION pos = GetFirstSelectedItemPosition ();
	if (pos == NULL)
		return;

	vmsUploadSmartPtr upl = _UplsMgr.GetUpload (GetNextSelectedItem (pos));

	if (upl->pMgr->IsDone ())
		OnUplOpeninbrowser ();
	else
		OnUplProperties ();
}
