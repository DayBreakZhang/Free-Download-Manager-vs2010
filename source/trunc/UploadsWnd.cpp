/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "UploadsWnd.h"
#include "plugincmds.h"
#include "uploader\coredll\cmds.h"
#include "mfchelp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CUploadsWnd *_pwndUploads = NULL;

HMODULE CUploadsWnd::m_hUploadsDll = NULL;

CUploadsWnd::CUploadsWnd()
{
	m_pwndUploads = NULL;
}

CUploadsWnd::~CUploadsWnd()
{
	
}

BEGIN_MESSAGE_MAP(CUploadsWnd, CWnd)
	//{{AFX_MSG_MAP(CUploadsWnd)
	ON_WM_CREATE()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP

	
	ON_MESSAGE (WM_WGP_SHUTDOWN, OnAppExit)
	ON_MESSAGE (WM_WGP_READYTOSHUTDOWN, OnAppQueryExit)
	ON_MESSAGE (WM_WGP_UPDATE_MENUMAIN, OnUpdateMenu)
	ON_MESSAGE (WM_WGP_UPDATE_MENUVIEW, OnUpdateMenuView)
	ON_MESSAGE (WM_WGP_UPDATE_CMDITEM, OnUpdateToolBar)
	ON_MESSAGE (WM_WGP_INSERT, OnInsert)

	
	ON_COMMAND_RANGE(ID_ULLIST_1, ID_ULLIST_7, OnListShowCol)
	ON_COMMAND_RANGE(ID_ULOG_1, ID_ULOG_3, OnLogShowCol)
	

	ON_COMMAND_RANGE (WGP_MENU_CMDFIRST, WGP_MENU_CMDLAST, OnUploadsCmd)

	

	ON_WM_DESTROY()
END_MESSAGE_MAP()

BOOL CUploadsWnd::Create(CWnd *pWndParent)
{
	CRect rc (0, 0, 50, 50);

	if (FALSE == CWnd::Create (AfxRegisterWndClass (0, NULL,
			NULL, NULL), NULL, WS_CHILD | WS_VISIBLE, rc, pWndParent, 0x16721))
		return FALSE;

	return TRUE;
}

HWND CUploadsWnd::Plugin_CreateMainWindow(HWND hWndParent)
{
	fsnew1 (_pwndUploads, CUploadsWnd);

	_pwndUploads->Create (CWnd::FromHandle (hWndParent));

	return _pwndUploads ? _pwndUploads->m_hWnd : NULL;
}

void CUploadsWnd::Plugin_GetToolBarInfo(wgTButtonInfo **ppButtons, int *pcButtons)
{
	static wgTButtonInfo btns [] = 
	{
		wgTButtonInfo (ID_UPL_CREATENEW, TBSTYLE_BUTTON, ""),
		wgTButtonInfo (ID_UPL_START, TBSTYLE_BUTTON, ""),
		wgTButtonInfo (ID_UPL_STOP, TBSTYLE_BUTTON, ""),
		
	};

	btns [0].pszToolTip = LS (L_UPLOADFILES);
	btns [1].pszToolTip = LS (L_START_UPLOAD);
	btns [2].pszToolTip = LS (L_STOP_UPLOAD);
	

	*ppButtons = btns;
	*pcButtons = sizeof (btns) / sizeof (wgTButtonInfo);
}

void CUploadsWnd::Plugin_GetMenuImages(fsSetImage **ppImages, int *pcImages)
{
	static fsSetImage images [] = 
	{
		fsSetImage (ID_UPL_CREATENEW, 0),
		fsSetImage (ID_UPL_START, 1),
		fsSetImage (ID_UPL_STOP, 2),
		
     	
		fsSetImage (ID_UPL_PROPERTIES, 6),
		fsSetImage (ID_UPL_DELETE, 7),
	};

	*ppImages = images;
	*pcImages = sizeof (images) / sizeof (fsSetImage);
}

void CUploadsWnd::Plugin_GetMenuViewItems(wgMenuViewItem **ppItems, int *)
{
	*ppItems = NULL;
}

void CUploadsWnd::Plugin_GetPluginNames(LPCSTR *ppszLong, LPCSTR *ppszShort)
{
	static CString strName;
	strName = LSNP (L_UPLOADS);
	*ppszLong = *ppszShort = strName;
}

void CUploadsWnd::Plugin_SetLanguage(wgLanguage, HMENU hMenuMain, HMENU hMenuView)
{
	if (!_pwndUploads)
		return;
	_pwndUploads->ApplyLanguageToMenu (CMenu::FromHandle (hMenuMain));
	_pwndUploads->ApplyLanguageToMenuView (CMenu::FromHandle (hMenuView));
	if (_pwndUploads->m_pwndUploads != NULL)
		_pwndUploads->m_pwndUploads->ApplyLanguage ();
}

LRESULT CUploadsWnd::OnAppExit(WPARAM, LPARAM)
{
	if (m_pwndUploads)
		m_pwndUploads->StopAllUploads (FALSE);

	while (m_pwndUploads->get_UploadsStat ()->IsUploadsRunning ())
	{
		Sleep (10);
		MSG msg;
		while (PeekMessage (&msg, NULL, 0, 0, PM_REMOVE))
			DispatchMessage (&msg);
	}

	SaveAll ();

	return 0;
}

LRESULT CUploadsWnd::OnAppQueryExit(WPARAM, LPARAM)
{
	return 0;
}

LRESULT CUploadsWnd::OnUpdateMenu(WPARAM, LPARAM lp)
{
	UpdateMenu (CMenu::FromHandle (*((HMENU*)lp)));
	return 0;
}

void CUploadsWnd::UpdateMenu(CMenu *pMenu)
{
	if (m_pwndUploads)
		m_pwndUploads->UpdateMenu (pMenu);
}

LRESULT CUploadsWnd::OnUpdateToolBar(WPARAM wp, LPARAM)
{
	return UpdateToolBar (wp);
}

int CUploadsWnd::UpdateToolBar(UINT nID)
{
	if (m_pwndUploads == NULL)
		return 0;

	BOOL bEnabled, bChecked;

	m_pwndUploads->GetMenuCommandState (nID, bEnabled, bChecked);

	int iState = bEnabled ? WGP_CMDITEMSTATE_ENABLED : WGP_CMDITEMSTATE_DISABLED;
	if (bChecked) iState |= WGP_CMDITEMSTATE_CHECKED;

	return iState;
}

LRESULT CUploadsWnd::OnInsert(WPARAM, LPARAM)
{
	OnUploadsCmd (ID_UPL_CREATENEW);
	return 0;
}

LRESULT CUploadsWnd::OnUpdateMenuView(WPARAM, LPARAM lp)
{
	HMENU* pMenus = (HMENU*) lp;
	UpdateListColMenu (CMenu::FromHandle (pMenus [0]));
	UpdateLogColMenu (CMenu::FromHandle (pMenus [1]));
	return 0;
}

void CUploadsWnd::ApplyLanguageToMenu(CMenu *menu)
{
	menu->ModifyMenu (0, MF_BYPOSITION | MF_STRING, 0, LS (L_UPLOADS));

	if (m_pwndUploads)
		m_pwndUploads->ApplyLanguageToMenu (menu);
}

int CUploadsWnd::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (FALSE == LoadFumCoreDll (true))
		return -1;

	vmsUploadsDll::FNSDC pfnSetCaller = (vmsUploadsDll::FNSDC) GetProcAddress (m_hUploadsDll, 
		"_SetDllCaller");
	ASSERT (pfnSetCaller != NULL);
	pfnSetCaller (&m_udc);

	vmsUploadsDll::FNCUW pfnCreate = (vmsUploadsDll::FNCUW) GetProcAddress (m_hUploadsDll, 
		"_CreateUploadsWindow");
	ASSERT (pfnCreate != NULL);

	m_pwndUploads = pfnCreate (this);

	return 0;
}

void CUploadsWnd::OnSize(UINT nType, int cx, int cy) 
{
	if (m_pwndUploads)
		m_pwndUploads->get_Wnd ()->MoveWindow (0, 0, cx, cy);	
}

void CUploadsWnd::SaveAll()
{
	if (m_pwndUploads)
		m_pwndUploads->SaveAll ();
}

void CUploadsWnd::UpdateLogColMenu(CMenu *menu)
{
	ASSERT (m_pwndUploads);

	
	BOOL bEn = m_pwndUploads->GetListViewColumnCount (vmsUploadsDll::LV_TASK_LOG) > 1;
	for (int i = 0; i < 3; i++)
	{
		if (m_pwndUploads->IsListViewColumnShown (vmsUploadsDll::LV_TASK_LOG, i))
		{
			menu->CheckMenuItem (ID_ULOG_1+i, MF_CHECKED);
			if (bEn == FALSE)
				
				menu->EnableMenuItem (ID_ULOG_1+i, MF_GRAYED);
		}
	}
}

void CUploadsWnd::ApplyLanguageToMenuView(CMenu *menu)
{
	menu->ModifyMenu (0, MF_BYPOSITION | MF_STRING, 0, LS (L_LISTOFUPLS));
	menu->ModifyMenu (1, MF_BYPOSITION | MF_STRING, 0, LS (L_LOG));

	UINT aCmds [] = {ID_ULLIST_1, ID_ULLIST_2, ID_ULLIST_3, ID_ULLIST_4, ID_ULLIST_5, 
		ID_ULLIST_6, ID_ULLIST_7, ID_ULOG_1, ID_ULOG_2, ID_ULOG_3 };
	LPCSTR apszCmds [] = {"URL", LS (L_NAME), LS (L_SIZE), LS (L_UPLOADED),
		LS (L_TIMELEFT), LS (L_SPEED), LS (L_ADDED),
		LS (L_TIME), LS (L_DATE), LS (L_INFORMATION)};
	
	for (int i = 0; i < sizeof (aCmds) / sizeof (UINT); i++)
		menu->ModifyMenu (aCmds [i], MF_BYCOMMAND|MF_STRING, aCmds [i], apszCmds [i]);
}

void CUploadsWnd::UpdateListColMenu(CMenu *menu)
{
	ASSERT (m_pwndUploads);

	BOOL bEn = m_pwndUploads->GetListViewColumnCount (vmsUploadsDll::LV_UPLOADS_TASKS) > 1;
	for (int i = 0; i < 7; i++)
	{
		if (m_pwndUploads->IsListViewColumnShown (vmsUploadsDll::LV_UPLOADS_TASKS, i))
		{
			menu->CheckMenuItem (ID_ULLIST_1+i, MF_CHECKED);
			if (bEn == FALSE)
				menu->EnableMenuItem (ID_ULLIST_1+i, MF_GRAYED);
		}
	}
}

void CUploadsWnd::OnListShowCol(UINT nID)
{
	int iCol = nID - ID_ULLIST_1;
	m_pwndUploads->ChangeListViewColumnVisibility (vmsUploadsDll::LV_UPLOADS_TASKS, iCol);
}

void CUploadsWnd::OnLogShowCol(UINT nID)
{
	int iCol = nID - ID_ULOG_1;
	m_pwndUploads->ChangeListViewColumnVisibility (vmsUploadsDll::LV_TASK_LOG, iCol);
}

HMENU CUploadsWnd::Plugin_GetMainMenu()
{
	return _pwndUploads && _pwndUploads->m_pwndUploads ? 
		_pwndUploads->m_pwndUploads->GetUploadsMenu () : NULL;
}

HMENU CUploadsWnd::Plugin_GetViewMenu()
{
	return LoadMenu (AfxGetInstanceHandle (), MAKEINTRESOURCE (IDM_UPLOADS_VIEW));
}

void CUploadsWnd::OnUploadsCmd(UINT nCmd)
{
	m_pwndUploads->get_Wnd ()->SendMessage (WM_COMMAND, nCmd);
}

BOOL CUploadsWnd::LoadFumCoreDll(bool bShowUI)
{
	if (m_hUploadsDll == NULL)
	{
		#ifndef _DEBUG
			CString strFP = fsGetFumProgramFilesFolder ();
			m_hUploadsDll = LoadLibrary (strFP + "fumcore.dll");
		#else
			CString strFP = vmsGetAppFolder ();
			m_hUploadsDll = LoadLibrary (strFP + "Fum\\fumcore.dll");

		#endif
	
			if (m_hUploadsDll == NULL)
				return FALSE;
	}

    vmsUploadsDll::FNGV pfnGetVersion = (vmsUploadsDll::FNGV) GetProcAddress (m_hUploadsDll,
     	"_GetVersion");
	DWORD dwMajorVer;
    pfnGetVersion (&dwMajorVer, NULL);
	if (dwMajorVer != vmsUploadsDll::DLL_INTERFACE_VERSION)
	{
		FreeLibrary (m_hUploadsDll);
		m_hUploadsDll = NULL;

		if (bShowUI)
		{
			::MessageBox (AfxGetApp ()->m_pMainWnd->m_hWnd, 
				LS (L_FDM_FUMCOREDLL_REQTOUPDATE), LS (L_WARNING), MB_ICONERROR);
		}

		return FALSE;
	}

	return TRUE;
}

void CUploadsWnd::OnDestroy()
{
	CWnd::OnDestroy();

	SAFE_DELETE (_pwndUploads);
}
