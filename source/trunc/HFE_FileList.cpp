/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "HFE_FileList.h"
#include "HFEWnd.h"
#include "plugincmds.h"
#include "DownloadsWnd.h"
#include "WaitDlg.h"
#include "CreateDownloadsDlg.h"
#include "HFESheet.h"
#include "MainFrm.h"
#include "vmsLogger.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CHFEWnd *_pwndHFE;
extern CDownloadsWnd* _pwndDownloads;

CHFE_FileList::CHFE_FileList()
{
	m_bDontUpdateList = FALSE;
}

CHFE_FileList::~CHFE_FileList()
{
}

BEGIN_MESSAGE_MAP(CHFE_FileList, CListCtrlEx)
	//{{AFX_MSG_MAP(CHFE_FileList)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_HFE_DOWNLOAD, OnHfeDownload)
	ON_COMMAND(ID_HFE_GO, OnHfeGo)
	ON_COMMAND(ID_HFE_REFRESH, OnHfeRefresh)
	ON_COMMAND(ID_HFE_SETTINGS, OnHfeSettings)
	ON_COMMAND(ID_HFE_STOP, OnHfeStop)
	ON_COMMAND(ID_HFE_OPENFOLDER, OnHfeOpenfolder)
	ON_COMMAND(ID_HFE_PARENTFOLDER, OnHfeParentfolder)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_DRAWITEM()
	ON_WM_MEASUREITEM()
	ON_COMMAND(ID_HFE_DISCONNECT, OnHfeDisconnect)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CHFE_FileList::Create(CWnd *pParent)
{
	CRect rc (0, 0, 50, 50);

	if (FALSE == CListCtrlEx::Create (LVS_REPORT|LVS_OWNERDRAWFIXED|LVS_NOSORTHEADER|LVS_SHOWSELALWAYS,
									  rc, pParent, 0x56789))
		return FALSE;

	SetExtendedStyle (LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_INFOTIP);

	

	m_images.Create (16, 17, ILC_COLOR24 | ILC_MASK, 4, 1);
	CBitmap bmp;
	bmp.Attach (SBMP (IDB_FILELIST));
	m_images.Add (&bmp, RGB (255, 0, 255));
	SetImageList (&m_images, LVSIL_SMALL);

	m_selImages.Create (16, 17, ILC_COLOR24 | ILC_MASK, 4, 1);
	CBitmap bmp1;
	bmp1.Attach (SBMP (IDB_FILELIST_SEL));
	m_selImages.Add (&bmp1, RGB (255, 0, 255));
	SetSelectedImages (&m_selImages);

	InsertColumn (0, LS (L_FILENAME), LVCFMT_LEFT, 300, 0);
	InsertColumn (1, LS (L_SIZE), LVCFMT_LEFT, 80, 0);
	InsertColumn (2, LS (L_DATE), LVCFMT_LEFT, 170, 0);

	ReadState ("HFEFileList");

	ShowWindow (SW_SHOW);

	return TRUE;
}

void CHFE_FileList::UpdateList()
{
	if (m_bDontUpdateList)
		return;
	
	fsInternetFileListMgr *mgr = _pwndHFE->GetMgr ();

	DeleteAllItems ();

	
	if (mgr->IsConnected () == FALSE || mgr->GetLastError () != IR_SUCCESS)
		return;	

	UINT cFiles = mgr->GetFileCount ();

	
	if (mgr->IsCurrentPathRoot () == FALSE)
	{
		
		int iItem = AddItem ("..", GetSysColor (COLOR_WINDOW), GetSysColor (COLOR_WINDOWTEXT), 0);
		SetItemData (iItem, NULL);
	}

	for (UINT i = 0; i < cFiles; i++)
	{
		fsFileInfo *file = mgr->GetFileInfo (i);
		int iImage = GetFileImage (file);

		int iItem = AddItem (file->strName, GetSysColor (COLOR_WINDOW), GetSysColor (COLOR_WINDOWTEXT), iImage);
		SetItemData (iItem, (DWORD) file);

		
		if (file->uSize != _UI64_MAX)
		{
			CString str;

			if (_pwndDownloads->IsSizesInBytes () == FALSE)
			{
				CHAR szDim [10];
				float val;
				BytesToXBytes (file->uSize, &val, szDim);
				str.Format ("%.*g %s", val > 999 ? 4 : 3, val, szDim);
			}
			else
				str = fsBytesToStr (file->uSize);

			SetItemText (iItem, 1, str);
		}

		
		if (file->date.dwHighDateTime != UINT_MAX || file->date.dwLowDateTime != UINT_MAX)
		{
			SYSTEMTIME time;
			CHAR strTime [1000], strDate [1000];

			FileTimeToSystemTime (&file->date, &time);

			SystemTimeToStr (&time, strDate, strTime);

			strcat (strTime, " ");
			strcat (strTime, strDate);
			SetItemText (iItem, 2, strTime);
		}
	}

	SortItems (_SortFunc, (DWORD) this);
}

int CHFE_FileList::GetFileImage(fsFileInfo *file)
{
	int iImage;

	if (file->bFolder)
		iImage = 0;
	else
		iImage = 2;

	if (file->bAvailable == FALSE)
		iImage++;

	return iImage;
}

void CHFE_FileList::OnRButtonDown(UINT nFlags, CPoint point) 
{
	m_rbPt = point;
	
	CListCtrlEx::OnRButtonDown(nFlags, point);
}

void CHFE_FileList::OnRClick()
{
	CMenu menu;
	menu.LoadMenu (IDM_HFE);
	ApplyLanguageToMenu (&menu);
	CMenu *pPopup = menu.GetSubMenu (0);

	UpdateMenu (pPopup);

	ClientToScreen (&m_rbPt);

	m_odmenu.Attach (&menu, FALSE);

	m_odmenu.SetImageList (&((CMainFrame*)AfxGetApp ()->m_pMainWnd)->m_imgsMenu, &((CMainFrame*)AfxGetApp ()->m_pMainWnd)->m_dimgsMenu);
	fsSetImage *pImages;
	int cImages;
	CHFEWnd::Plugin_GetMenuImages (&pImages, &cImages);
	m_odmenu.SetImages (pImages, cImages);

	pPopup->TrackPopupMenu (TPM_RIGHTBUTTON | TPM_TOPALIGN | TPM_LEFTALIGN,	m_rbPt.x, m_rbPt.y, this);
	m_odmenu.Detach ();

	menu.DestroyMenu ();
}

void CHFE_FileList::OnHfeDownload() 
{
	POSITION pos = GetFirstSelectedItemPosition ();

	if (pos == NULL)
		return;

	if (GetSelectedCount () == 1)
	{
		int iItem = GetNextSelectedItem (pos);
		
		if (((fsFileInfo*) GetItemData (iItem))->bFolder)
			DownloadSelected ();	
		else
		{
			

			CString strUrl = GetItemText (iItem, 0);
			fsString strFullUrl;

			
			if (IR_SUCCESS != _pwndHFE->GetMgr ()->GetFullUrl (strUrl, strFullUrl))
			{
				MessageBox (LS (L_BADURL), LS (L_ERR), MB_ICONERROR);
				SetFocus ();
				return;
			}

			
			_pwndDownloads->CreateDownload (strFullUrl);
		}
	}
	else
	{
		DownloadSelected ();	
	}

	SetFocus ();
}

void CHFE_FileList::OnHfeGo() 
{
	_pwndHFE->OnGo ();	
}

void CHFE_FileList::OnHfeRefresh() 
{
	DeleteAllItems ();
	_pwndHFE->GetMgr ()->Refresh ();	
}

void CHFE_FileList::OnHfeSettings() 
{
	CHFESheet sheet (LS (L_EXPLORERSETTINGS), this);
	_DlgMgr.OnDoModal (&sheet);
	sheet.DoModal ();
	_DlgMgr.OnEndDialog (&sheet);
	SetFocus ();
}

void CHFE_FileList::OnHfeStop() 
{
	_pwndHFE->GetMgr ()->Stop (FALSE);	
}

void CHFE_FileList::UpdateMenu(CMenu *pPopup)
{
	pPopup->SetDefaultItem (ID_HFE_DOWNLOAD);

	if (_pwndHFE->GetMgr ()->IsRunning  () == FALSE)
		pPopup->EnableMenuItem (ID_HFE_STOP, MF_BYCOMMAND | MF_GRAYED);

	if (_pwndHFE->GetMgr ()->IsConnected () == FALSE)
		pPopup->EnableMenuItem (ID_HFE_DISCONNECT, MF_BYCOMMAND | MF_GRAYED);

	if (_pwndHFE->GetMgr ()->GetCurrentPath () == NULL || _pwndHFE->GetMgr ()->IsRunning ())
	{
		pPopup->EnableMenuItem (ID_HFE_REFRESH, MF_BYCOMMAND | MF_GRAYED);
		pPopup->EnableMenuItem (ID_HFE_PARENTFOLDER, MF_BYCOMMAND | MF_GRAYED);
	}

	if (_pwndHFE->GetMgr ()->IsCurrentPathRoot ())
		pPopup->EnableMenuItem (ID_HFE_PARENTFOLDER, MF_BYCOMMAND | MF_GRAYED);

	int cItems = GetSelectedCount ();

	if (cItems == 0)
	{
		pPopup->EnableMenuItem (ID_HFE_DOWNLOAD, MF_BYCOMMAND | MF_GRAYED);
		pPopup->EnableMenuItem (ID_HFE_OPENFOLDER, MF_BYCOMMAND | MF_GRAYED);
	}
	else
	{
		POSITION pos = GetFirstSelectedItemPosition ();
		while (pos)
		{
			int iItem = GetNextSelectedItem (pos);
			fsFileInfo *file = (fsFileInfo*) GetItemData (iItem);
			if (iItem == 0 && _pwndHFE->GetMgr ()->IsCurrentPathRoot () == FALSE)
			{
				pPopup->EnableMenuItem (ID_HFE_DOWNLOAD, MF_BYCOMMAND | MF_GRAYED);
			} 
			else
			{
				if (file->bFolder == FALSE)
					pPopup->EnableMenuItem (ID_HFE_OPENFOLDER, MF_BYCOMMAND | MF_GRAYED);
			}
		}

		if (cItems != 1)
			pPopup->EnableMenuItem (ID_HFE_OPENFOLDER, MF_BYCOMMAND | MF_GRAYED);
	}
}

int CALLBACK CHFE_FileList::_SortFunc(LPARAM item1, LPARAM item2, LPARAM )
{
	fsFileInfo *file1 = (fsFileInfo*) item1;
	fsFileInfo *file2 = (fsFileInfo*) item2;

	if (file1 == NULL)
		return -1;
	else if (file2 == NULL)
		return -1;

	
	if (file1->bFolder && file2->bFolder == FALSE)
		return -1;
	else if (file2->bFolder && file1->bFolder == FALSE)
		return 1;

	return stricmp (file1->strName, file2->strName);
}

void CHFE_FileList::OnHfeOpenfolder() 
{
	POSITION pos = GetFirstSelectedItemPosition ();
	int iItem = GetNextSelectedItem (pos);

	fsString strUrl;

	
	if (iItem == 0 && _pwndHFE->GetMgr ()->IsCurrentPathRoot () == FALSE)
	{
		
		_pwndHFE->GetMgr ()->GetParentFolderUrl (strUrl);
		_pwndHFE->GetMgr ()->GoParentFolder ();
	}
	else
	{
		
		CString strFolder = GetItemText (iItem, 0);
		_pwndHFE->GetMgr ()->FolderToUrl (strFolder, strUrl);
		_pwndHFE->GetMgr ()->GoFolder (strFolder);
	}

	
	_pwndHFE->m_wndUrl.PushUrl (strUrl);
}

void CHFE_FileList::OnHfeParentfolder() 
{
	fsInternetFileListMgr* mgr = _pwndHFE->GetMgr ();

	if (mgr->IsCurrentPathRoot ())
		return;

	mgr->GoParentFolder ();
}

void CHFE_FileList::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	Open1SelectedItem ();

	CListCtrlEx::OnLButtonDblClk(nFlags, point);
}

BOOL CHFE_FileList::Open1SelectedItem()
{
	POSITION pos = GetFirstSelectedItemPosition ();
	if (pos && GetSelectedCount () == 1)
	{
		fsFileInfo *file = (fsFileInfo*) GetItemData (GetNextSelectedItem (pos));

		
		if (file == NULL || file->bFolder)
			OnHfeOpenfolder (); 
		else
			OnHfeDownload ();	

		return TRUE;
	}

	return FALSE;	
}

void CHFE_FileList::OnKeyDown(WORD wVK)
{
	switch (wVK)
	{
		case VK_RETURN:
			if (Open1SelectedItem () == FALSE)
				OnHfeDownload ();
		break;

		case VK_APPS:
			CalcCoordsForCurSel ();
			OnRClick ();
		break;
	}
}

void CHFE_FileList::DownloadSelected()
{
	m_bDontUpdateList = TRUE;

	CWaitDlg dlg;

	fsInternetFileListMgr *mgr = _pwndHFE->GetMgr ();

	BOOL bRI = mgr->RetreiveInfoWhileGettingList ();
	
	mgr->RetreiveInfoWhileGettingList (FALSE); 
	
	fsString strUrl;
	mgr->GetCurrentUrl (strUrl);

	CString strOrigUrl; 
	_pwndHFE->m_wndUrl.m_wndUrl.GetWindowText (strOrigUrl);

	
	bool bWasError = false;
	if (IDOK == dlg.StartWaiting (LS (L_BUILDINGLIST), _threadBuildList, TRUE, this, &bWasError) &&
			m_pList != NULL)
	{
		

		CCreateDownloadsDlg dlg;

		dlg.m_pFileList = m_pList;
		dlg.m_strRootUrl = strUrl;
		
		_DlgMgr.DoModal (&dlg);

		cleanFiles();
		SAFE_DELETE (m_pList);
	}

	m_bDontUpdateList = FALSE;

	if (mgr->IsRunning ())
	{
		mgr->Stop (FALSE);
		while (mgr->IsRunning ()) {
			MSG msg;
			while (PeekMessage (&msg, NULL, 0, 0, PM_REMOVE))
				DispatchMessage (&msg);
			Sleep (10);
		}
	}

	if (mgr->IsConnected ())
		mgr->GetList (strUrl, NULL, NULL);	
	else
		DeleteAllItems ();

	mgr->RetreiveInfoWhileGettingList (bRI);

	_pwndHFE->m_wndUrl.m_wndUrl.SetWindowText (strOrigUrl);
	if (bWasError)
		_pwndHFE->LogFailedMessage (LS (L_FAILED));
}

fs::tree <fsFileInfo*>* CHFE_FileList::BuildList(LPCSTR pszFolder, BOOL *pbNeedStop, int* piProgress, int iProgressDone)
{
	fsInternetFileListMgr *mgr = _pwndHFE->GetMgr ();
	fs::tree <fsFileInfo*> *pRoot = NULL;
	fs::tree <fsFileInfo*> *pCur;

	if (*pbNeedStop)
		return NULL;

	if (pszFolder)
	{
		
		mgr->GoFolder (pszFolder);
		MSG msg;
		
		while (mgr->IsRunning ())
		{
			if (*pbNeedStop)
				mgr->Stop ();

			while (PeekMessage (&msg, 0, 0, 0, PM_REMOVE))
				DispatchMessage (&msg);

			Sleep (20);
		}

		while (PeekMessage (&msg, 0, 0, 0, PM_REMOVE))
				DispatchMessage (&msg);
	}

	if (*pbNeedStop)
		return NULL;

	
	if (mgr->IsConnected () == FALSE)
		return NULL;

	UINT cFiles = mgr->GetFileCount ();

	if (cFiles == 0)
		goto _lExit;

	fsnew1 (pCur, fs::tree <fsFileInfo*>);
	pRoot = pCur;

	UINT i;
	int iProgress; iProgress = *piProgress;
	
	for (i = 0; i < cFiles && *pbNeedStop == FALSE; i++)
	{
		fsFileInfo *file = mgr->GetFileInfo (i);

		std::auto_ptr<fsFileInfo> apfiFileInfoGuard( new fsFileInfo(*file) );
		fsFileInfo* pfiFileInfo = apfiFileInfoGuard.get();
		if (pfiFileInfo == 0)
			return 0;

		
		pCur->Data (apfiFileInfoGuard.release());

		if (file->bFolder)	
		{
			fsString str = file->strName;

			
			str [str.Length ()-1] = 0;
			if (strchr (str, '\\') || strchr (str, '/'))
				continue;

			
			try {
			fs::tree <fsFileInfo*>* pChildren = BuildList (file->strName, pbNeedStop, 
				piProgress, iProgressDone/cFiles);
			pCur->Right (pChildren);
			if (mgr->GetFileCount () != cFiles) 
				throw 1;
			}
			catch (const std::exception& ex)
			{
				ASSERT (FALSE);
				vmsLogger::WriteLog(" " + tstring(ex.what()));
				SAFE_DELETE (pRoot);
				throw 1;
			}
			catch (...)
			{
				ASSERT (FALSE);
				vmsLogger::WriteLog(" unknown exception");
				SAFE_DELETE (pRoot);
				throw 1;
			}
		}

		
		if (i < cFiles - 1)
		{
			fs::tree <fsFileInfo*> *p;
			
			fsnew1 (p, fs::tree <fsFileInfo*>);
			pCur->Left (p);
			pCur->Left ()->Root (pCur);
			pCur = pCur->Left ();
		}

		*piProgress = iProgress + MulDiv (i, iProgressDone, cFiles);
	}

_lExit:
	
	if (pszFolder)
	{
		
		mgr->GoParentFolder ();
		MSG msg;
		while (PeekMessage (&msg, 0, 0, 0, PM_REMOVE))
				DispatchMessage (&msg);
	}
		
	return pRoot;	
}

void CHFE_FileList::cleanFilesSubtree(fs::tree <fsFileInfo*>* pCur)
{
	if (pCur->Left())
		cleanFilesSubtree(pCur->Left());
	if (pCur->Right())
		cleanFilesSubtree(pCur->Right());
	delete pCur->Data();
}

void CHFE_FileList::cleanFiles()
{
	if (m_pList)
		cleanFilesSubtree(m_pList);
}

DWORD WINAPI CHFE_FileList::_threadBuildList(LPVOID lp)
{
	

	ProcWaitInfo *info = (ProcWaitInfo*) lp;
	CHFE_FileList *pThis = (CHFE_FileList*) info->lpParam1;
	bool *pbWasError = (bool*) info->lpParam2;
	*pbWasError = false;

	
	POSITION pos = pThis->GetFirstSelectedItemPosition ();

	pThis->m_pList = NULL;

	if (pos == NULL)
		return 0;

	
	
	
	fsnew1 (pThis->m_pList, fs::tree <fsFileInfo*>);
	fs::tree <fsFileInfo*>* pCur = pThis->m_pList;

	fs::list <int> vItems;	
	while (pos)
		vItems.add (pThis->GetNextSelectedItem (pos));

	

	int cItems = vItems.size ();
	bool bFatalError = false;
	for (int i = 0; i < cItems && info->bNeedStop == FALSE; i++)
	{
		fsFileInfo *file = (fsFileInfo*) pThis->GetItemData (vItems [i]);

		std::auto_ptr<fsFileInfo> apfiFileInfoGuard( new fsFileInfo(*file) );
		fsFileInfo* pfiFileInfo = apfiFileInfoGuard.get();
		if (pfiFileInfo == 0)
			return 0;

		pCur->Data (apfiFileInfoGuard.release());
		if (file->bFolder)
		{
			try 
			{
				fs::tree <fsFileInfo*>* pChildren = BuildList (file->strName, &info->bNeedStop,
					&info->iProgress, 100/cItems); 
				pCur->Right (pChildren);
			}
			catch (const std::exception& ex)
			{
				ASSERT (FALSE);
				vmsLogger::WriteLog(" " + tstring(ex.what()));
				bFatalError = true;
				break;
			}
			catch (...)
			{
				ASSERT (FALSE);
				vmsLogger::WriteLog(" unknown exception");
				bFatalError = true;
				break;
			}
		}		

		if (i < cItems - 1)
		{
			fs::tree <fsFileInfo*> *p;
			fsnew1 (p, fs::tree <fsFileInfo*>);
			pCur->Left (p);
			pCur->Left ()->Root (pCur);
			pCur = pCur->Left ();
		}

		info->iProgress = MulDiv (i, 100, cItems);
	}

	if (info->bNeedStop == FALSE && bFatalError)
	{
		*pbWasError = true;
		info->bNeedStop = TRUE;
	}
	
	if (info->bNeedStop)
	{
		pThis->cleanFiles();
		SAFE_DELETE (pThis->m_pList);
		info->bNeedStop = FALSE;
	}

	info->bWaitDone = TRUE;

	return 0;
}

int CHFE_FileList::OnUpdateToolBar(UINT nID)
{
	BOOL bEnabled = TRUE;

	switch (nID)
	{
		case ID_HFE_STOP:
			if (_pwndHFE->GetMgr ()->IsRunning  () == FALSE)
				bEnabled = FALSE;
		break;

		case ID_HFE_REFRESH:
		case ID_HFE_PARENTFOLDER:
			if (_pwndHFE->GetMgr ()->GetCurrentPath () == NULL || _pwndHFE->GetMgr ()->IsRunning ())
				bEnabled = FALSE;

			if (nID == ID_HFE_PARENTFOLDER && _pwndHFE->GetMgr ()->IsCurrentPathRoot ())
				bEnabled = FALSE;
		break;

		case ID_HFE_BACK:
			bEnabled = _pwndHFE->m_wndUrl.m_vAddrs.size () > 1;
		break;
	}

	int cItems = GetSelectedCount ();

	if (cItems == 0)
	{
		if (nID == ID_HFE_DOWNLOAD || nID == ID_HFE_OPENFOLDER)
			bEnabled = FALSE;
	}
	else
	{
		POSITION pos = GetFirstSelectedItemPosition ();
		while (pos)
		{
			int iItem = GetNextSelectedItem (pos);
			fsFileInfo *file = (fsFileInfo*) GetItemData (iItem);
			
			switch (nID)
			{
				case ID_HFE_DOWNLOAD:
					if (iItem == 0 && _pwndHFE->GetMgr ()->IsCurrentPathRoot () == FALSE)
						bEnabled = FALSE;
				break;

				case ID_HFE_OPENFOLDER:
					if (iItem == 0 && _pwndHFE->GetMgr ()->IsCurrentPathRoot () && file->bFolder == FALSE)
						bEnabled = FALSE;
				break;
			}
		}

		if (cItems != 1 && nID == ID_HFE_OPENFOLDER)
			bEnabled = FALSE;
	}

	return bEnabled ? WGP_CMDITEMSTATE_ENABLED : WGP_CMDITEMSTATE_DISABLED;
}

void CHFE_FileList::OnDrawItem(int , LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	m_odmenu.OnDrawItem (lpDrawItemStruct);
}

void CHFE_FileList::OnMeasureItem(int , LPMEASUREITEMSTRUCT lpMeasureItemStruct) 
{
	m_odmenu.OnMeasureItem (lpMeasureItemStruct);
}

void CHFE_FileList::OnHfeDisconnect() 
{
	_pwndHFE->GetMgr ()->Disconnect ();
	DeleteAllItems ();
}

void CHFE_FileList::ApplyLanguageToMenu(CMenu * menu)
{
	menu->ModifyMenu (0, MF_BYPOSITION|MF_STRING, 0, LS (L_EXPLORER));
	
	menu->ModifyMenu (ID_HFE_OPENFOLDER, MF_BYCOMMAND|MF_STRING, ID_HFE_OPENFOLDER, LS (L_OPENFOLDER));
	menu->ModifyMenu (ID_HFE_PARENTFOLDER, MF_BYCOMMAND|MF_STRING, ID_HFE_PARENTFOLDER, LS (L_OPENPARENTFOLDER));
	menu->ModifyMenu (ID_HFE_STOP, MF_BYCOMMAND|MF_STRING, ID_HFE_STOP, LS (L_STOP));
	menu->ModifyMenu (ID_HFE_REFRESH, MF_BYCOMMAND|MF_STRING, ID_HFE_REFRESH, LS (L_REFRESH));
	menu->ModifyMenu (ID_HFE_DISCONNECT, MF_BYCOMMAND|MF_STRING, ID_HFE_DISCONNECT, LS (L_DISCONNECT));
	menu->ModifyMenu (ID_HFE_DOWNLOAD, MF_BYCOMMAND|MF_STRING, ID_HFE_DOWNLOAD, LS (L_DOWNLOAD));
	menu->ModifyMenu (ID_HFE_SETTINGS, MF_BYCOMMAND|MF_STRING, ID_HFE_SETTINGS, LS (L_EXPLORERSETTINGS));
}

void CHFE_FileList::ApplyLanguage()
{
	SetColumnText (0, LS (L_FILENAME));
	SetColumnText (1, LS (L_SIZE));
	SetColumnText (2, LS (L_DATE));
}

void CHFE_FileList::CalcCoordsForCurSel()
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

void CHFE_FileList::OnForceUpdate()
{
	UpdateList ();
}
