/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FUM.h"
#include "MainFrm.h"
#include "mfchelp.h"
#include "optsheet.h"
#include "system.h"
#include "fsUpdateMgr.h"
#include "DlgUpdate.h"
#include "../coredll/dll.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define ID_UPDATE 40000
#define WM_TRAYMSG				(WM_APP + 100)

IMPLEMENT_DYNAMIC(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_WM_SETFOCUS()
	ON_WM_MEASUREITEM()
	ON_WM_DRAWITEM()
	ON_COMMAND(ID_TOOLS_GENERALSETTINGS, OnToolsGeneralsettings)
	ON_COMMAND(ID_HOMEPAGE, OnHomepage)
	ON_COMMAND(ID_SUPPORT, OnSupport)
	ON_COMMAND(ID_RECOMMEND, OnRecommend)
	ON_WM_CLOSE()
	ON_COMMAND(ID_SHOWMAINWINDOW, OnShowmainwindow)
	ON_COMMAND(ID_CREATENEWUPLOAD, OnCreatenewupload)
	ON_WM_SIZE()
	ON_WM_SYSCOMMAND()
	ON_MESSAGE(WM_TRAYMSG, OnTrayMsg)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP

	ON_COMMAND(ID_NEED_EXIT, OnNeedExit)
	ON_COMMAND(ID_UPDATE, OnUpdate)

	ON_COMMAND_RANGE (ID_LNGMENU_START, ID_LNGMENU_START+500, OnLanguage)
	ON_UPDATE_COMMAND_UI_RANGE (ID_LNGMENU_START, ID_LNGMENU_START+500, OnUpdateLanguage)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

CMainFrame::CMainFrame() : 
	m_um ("http://freedownloadmanager.org/update/fum/index.txt")
{
	m_dlgUpdate = NULL;
	m_bTrayMenuShowing = FALSE;

	m_nShutdownMsg = RegisterWindowMessage ("FUM - shutdown");

	m_nUploadsMsg1 = RegisterWindowMessage (vmsUploadsDll::MSG_NAME_1);
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndView.Create(NULL, NULL, AFX_WS_DEFAULT_VIEW,
		CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, NULL))
	{
		TRACE0("Failed to create view window\n");
		return -1;
	}

	HMENU hmUploads = m_wndView.m_pwndUploads->GetUploadsMenu ();
	CMenu *menu = GetMenu ();
	ModifyMenu (menu->m_hMenu, 2, MF_BYPOSITION|MF_POPUP, (UINT)GetSubMenu (hmUploads, 0), "-");

	CBitmap bmp, bmp_d; 
	bmp.Attach (LoadImage (AfxGetResourceHandle (), MAKEINTRESOURCE (IDB_TOOLBAR),
		IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION));
	bmp_d.Attach (LoadImage (AfxGetResourceHandle (), MAKEINTRESOURCE (IDB_TOOLBAR_D),
		IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION));
	ConvertBmp32WithAlphaToBmp32WithoutAlpha (bmp, GetSysColor (COLOR_3DFACE));
	ConvertBmp32WithAlphaToBmp32WithoutAlpha (bmp_d, GetSysColor (COLOR_3DFACE));
	m_imgsTb.Create (32, 32, ILC_COLOR32 | ILC_MASK, 10, 1);
	m_imgsTb_d.Create (32, 32, ILC_COLOR32 | ILC_MASK, 10, 1);
	m_imgsTb.Add (&bmp, GetSysColor (COLOR_3DFACE));
	m_imgsTb_d.Add (&bmp_d, GetSysColor (COLOR_3DFACE));
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_TOOLTIPS))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      
	}

	m_wndToolBar.GetToolBarCtrl ().SetButtonSize (CSize (32 + 7, 32 + 7));
	m_wndToolBar.GetToolBarCtrl ().SetImageList (&m_imgsTb);
	m_wndToolBar.GetToolBarCtrl ().SetDisabledImageList (&m_imgsTb_d);

	UINT aIDs [] = { ID_UPL_CREATENEW, ID_UPL_START, ID_UPL_STOP,
		ID_TOOLS_UPLOADERSETTINGS, ID_HELP, ID_APP_ABOUT};
	m_wndToolBar.SetButtons (aIDs, sizeof (aIDs)/sizeof (UINT));

	if (!m_wndStatusBar.Create(this) || !m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      
	}

	
	
	
	
	

	m_odmenuMain.Attach (GetMenu (), TRUE);
	BuildLngMenu ();

	ApplyLanguage ();

	UINT pnIcons [] = {IDR_MAINFRAME};
	_Tray.Create (m_hWnd, pnIcons, sizeof (pnIcons) / sizeof (UINT), PRG_NAME, WM_TRAYMSG);

	
	SetTimer (1, 3 * 60 * 1000, NULL);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	
	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;

	WNDCLASS wc;
	ZeroMemory (&wc, sizeof (wc));
	wc.hbrBackground = (HBRUSH) (COLOR_WINDOW+1);
	wc.hCursor = LoadCursor (NULL, IDC_ARROW);
	wc.hIcon = LoadIcon (AfxGetInstanceHandle (), MAKEINTRESOURCE (IDR_MAINFRAME));
	wc.hInstance = AfxGetInstanceHandle ();
	wc.lpfnWndProc = ::DefWindowProc;
	wc.lpszClassName = "Free Upload Manager Main Window";
	cs.lpszClass = wc.lpszClassName;
	
	return AfxRegisterClass (&wc);
}

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif 

void CMainFrame::OnSetFocus(CWnd* pOldWnd)
{
	
	m_wndView.SetFocus();
}

BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	
	if (m_wndView.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		return TRUE;

	
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

void CMainFrame::OnMeasureItem(int , LPMEASUREITEMSTRUCT lpMeasureItemStruct) 
{
	m_odmenuMain.OnMeasureItem (lpMeasureItemStruct);
}

void CMainFrame::OnDrawItem(int , LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	m_odmenuMain.OnDrawItem (lpDrawItemStruct);
}

void CMainFrame::BuildLngMenu()
{
	CMenu *menu = GetMenu ()->GetSubMenu (1);
	menu = menu->GetSubMenu (menu->GetMenuItemCount () - 1);

	m_odmenuMain.RemoveMenuItem (menu, 0, TRUE);

	if (_LngMgr.GetLngCount ())
	{
		for (int i = 0; i < _LngMgr.GetLngCount (); i++)
			m_odmenuMain.InsertMenuItem (menu, _LngMgr.GetLngName (i), ID_LNGMENU_START+i, i, TRUE);
	}
	else 
	{
		m_odmenuMain.InsertMenuItem (menu, LS (L_EMPTY), ID_LNGMENU_START, 0, TRUE);
	}
}

void CMainFrame::OnLanguage(UINT nId)
{
	int iCurLng = _LngMgr.GetCurLng ();
	if (FALSE == _LngMgr.LoadLng (nId - ID_LNGMENU_START))
	{
		_LngMgr.LoadLng (iCurLng);
		MessageBox ("Sorry, can't load this language", "Error", MB_ICONERROR);
		return;
	}
	_App.View_Language (_LngMgr.GetLngName (nId - ID_LNGMENU_START));

	ApplyLanguage ();
}

void CMainFrame::OnUpdateLanguage(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck (_LngMgr.GetCurLng () == (int)(pCmdUI->m_nID - ID_LNGMENU_START));
}

void CMainFrame::ApplyLanguage()
{
	m_odmenuMain.Detach ();
	m_wndView.m_pwndUploads->ApplyLanguageToMenu (GetMenu ()->GetSubMenu (2));
	
	m_odmenuMain.Attach (GetMenu (), TRUE);

	fsSetText aMenuBarTexts [] = {
		fsSetText (0, LS (L_FILE)),
		fsSetText (1, LS (L_VIEW)),
		fsSetText (2, LS (L_UPLOADS)),
		fsSetText (3, LS (L_OPTIONS)),
		fsSetText (4, LS (L_HELP)),
	};
	m_odmenuMain.SetMenuItemsText (GetMenu (), aMenuBarTexts, sizeof (aMenuBarTexts) / sizeof (fsSetText), TRUE);

	CString strCut = LS (L_CUT), strCopy = LS (L_COPY), strPaste = LS (L_PASTE), 
		strDldOpt = LS (L_DLDR_OPTIONS), strDldDef = LS (L_DLDDEFOPT),
		strPrgGen = LS (L_PRGGENSET), strLight = LS (L_LIGHT), strMedium = LS (L_MEDIUM),
		strHeavy = LS (L_HEAVY), strDial = LS (L_DIAL), strDoc = LS (L_DOCUMENTATION),
		strSpiderDefs = LS (L_SPIDERDEFSETTINGS), strExit = LS (L_EXIT),
		strExport = LS (L_EXPORTSETTINGS), strSaveAll = LS (L_SAVEALL),
		strImpFromClip = LS (L_IMPORTURLSFROMCLIPBOARD);

	strCut += "\tCtrl+X"; strCopy += "\tCtrl+C"; strPaste += "\tCtrl+V";
	strDldOpt += "\tCtrl+O"; strDldDef += "\tCtrl+E";
	strPrgGen += "\tCtrl+P"; strLight += "\tCtrl+1"; strMedium += "\tCtrl+2"; strHeavy += "\tCtrl+3";
	strDial += "\tCtrl+D"; strDoc += "\tF1";
	strSpiderDefs += "\tCtrl+Q"; strExit += "\tAlt+X";
	strExport += '\t'; strSaveAll += "\tCtrl+S";
	strImpFromClip += "\tCtrl+Shift+V";

	fsSetText aTexts [] = {
		fsSetText (ID_APP_EXIT, strExit),
		fsSetText (ID_VIEW_TOOLBAR, LS (L_TOOLBAR)),
		fsSetText (ID_VIEW_STATUS_BAR, LS (L_STATUSBAR)),

		
		fsSetText (ID_TOOLS_GENERALSETTINGS, LS (L_PRGGENSET)),
		
		fsSetText (ID_HELP, strDoc),
		fsSetText (ID_HOMEPAGE, LS (L_HOMEPAGE)),
		fsSetText (ID_RECOMMEND, LS (L_RECOMMEND)),
		fsSetText (ID_SUPPORT, LS (L_TOSUPPORT)),
		fsSetText (ID_APP_ABOUT, LS (L_ABOUT)),
	};
	m_odmenuMain.SetMenuItemsText (GetMenu (), aTexts, sizeof (aTexts) / sizeof (fsSetText), FALSE);

	m_odmenuMain.SetMenuItemText (GetMenu ()->GetSubMenu (1), LS (L_LISTOFUPLS), 3, TRUE);
	m_odmenuMain.SetMenuItemText (GetMenu ()->GetSubMenu (1), LS (L_LOG), 4, TRUE);

	UINT aCmds [] = {ID_VIEW_LU_1, ID_VIEW_LU_2, ID_VIEW_LU_3, ID_VIEW_LU_4, ID_VIEW_LU_5, 
		ID_VIEW_LU_6, ID_VIEW_LU_7, ID_VIEW_LUL_1, ID_VIEW_LUL_2, ID_VIEW_LUL_3 };
	LPCSTR apszCmds [] = {"URL", LS (L_NAME), LS (L_SIZE), LS (L_UPLOADED),
		LS (L_TIMELEFT), LS (L_SPEED), LS (L_ADDED),
		LS (L_TIME), LS (L_DATE), LS (L_INFORMATION)};
	for (int i = 0; i < sizeof (aCmds) / sizeof (UINT); i++)
		m_odmenuMain.SetMenuItemText (GetMenu ()->GetSubMenu (1), apszCmds [i], aCmds [i], FALSE);

	DrawMenuBar ();

	m_wndView.m_pwndUploads->ApplyLanguage ();
}

void CMainFrame::OnToolsGeneralsettings() 
{
	COptSheet sheet (LS (L_PRGGENSET), this);
	_DlgMgr.DoModal (&sheet);
}

BOOL CMainFrame::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
{
	LPNMHDR nm = (LPNMHDR) lParam;

	if (nm->hwndFrom == m_wndToolBar.m_hWnd)
	{
		int nID = ((LPNMTBGETINFOTIPA) nm)->iItem;

		switch (nm->code)
		{
			case TBN_GETINFOTIPA:
				LPNMTBGETINFOTIPA inf; inf = (LPNMTBGETINFOTIPA) nm;
				lstrcpy (inf->pszText, GetToolbarButtonText (nID));
				*pResult = TRUE;
				return TRUE;

			default:
				return DefWindowProc (WM_NOTIFY, wParam, lParam);
		}
	}

	*pResult = FALSE;
	return FALSE;
}

CString CMainFrame::GetToolbarButtonText(UINT nID)
{
	switch (nID)
	{
	case ID_UPL_CREATENEW:
		return LS (L_UPLOADFILES);

	case ID_UPL_START:
		return LS (L_START_UPLOAD);

	case ID_UPL_STOP:
		return LS (L_STOP_UPLOAD);

	case ID_TOOLS_UPLOADERSETTINGS:
		return LS (L_INTEGRATION_SETTINGS);

	case ID_HELP:
		return LS (L_DOCUMENTATION);

	case ID_APP_ABOUT:
		return LS (L_ABOUT);

	default:
		return "";
	}
}

void CMainFrame::OnHomepage() 
{
	fsOpenUrlInBrowser ("http://www.freedownloadmanager.org/");	
}

void CMainFrame::OnSupport() 
{
	fsOpenUrlInBrowser ("http://www.freedownloadmanager.org/support.htm");	
}

void CMainFrame::OnRecommend() 
{
	ShellExecute (NULL, "open", "mailto:@?subject=Free%20Download%20Manager%20[http://www.freedownloadmanager.org]",	NULL, NULL, SW_SHOW);	
}

void CMainFrame::OnClose() 
{
	SaveState ();

	m_wndView.m_pwndUploads->SaveAll ();
	_Tray.Remove ();

	_DlgMgr.EndAllDialogs ();
	
	CFrameWnd::OnClose();
}

void CMainFrame::OnUpdate() 
{
	static bool _bInFunc = false;
	
	if (_bInFunc)
		return;

	_bInFunc = true;

	if (m_dlgUpdate)
	{
		if (m_dlgUpdate->IsWindowVisible ())
			return;
		delete m_dlgUpdate;
		m_dlgUpdate = NULL;
	}

	if (IDNO == MessageBox (LS (L_NEWVER_AVAIL_UPDATE_REQ), NULL, MB_ICONQUESTION | MB_YESNO))
	{
		_bInFunc = false;
		return;
	}

	m_dlgUpdate = new CDlgUpdate;
	m_dlgUpdate->Create (IDD_UPDATE, this);
	m_dlgUpdate->SetForegroundWindow ();

	_bInFunc = false;
}

BOOL CMainFrame::OnBeforeUpload(LPSTR pszStopReason, bool* pbNeedStop)
{
	static bool _bInFunc = false;
	static DWORD _timeLastOkCheck = 0;

_lBegin:

	if (m_iOnBeforeUpload_LastCallResult == LCR_RESTART_REQ)
	{
		lstrcpy (pszStopReason, LS (L_RESTART_REQ));
		return FALSE;
	}

	if (GetTickCount () - _timeLastOkCheck < 3600 * 1000)
	{
		switch (m_iOnBeforeUpload_LastCallResult)
		{
		case LCR_NO_NEW_VER:
			return TRUE;

		case LCR_NEW_VER_DETECTED:
			lstrcpy (pszStopReason, LS (L_UPDATE_REQ));
			PostMessage (WM_COMMAND, ID_UPDATE);
			return FALSE;
		}
	}
	
	if (_bInFunc)
	{
		while (_bInFunc && *pbNeedStop)
			Sleep (50);
		if (*pbNeedStop)
			return FALSE;
		goto _lBegin;
	}
	
	_bInFunc = true;

	DWORD dw;
	HANDLE htCheck = CreateThread (NULL, 0, _threadCheckNewVer, &m_um, 0, &dw);
	while (WaitForSingleObject (htCheck, 100) == WAIT_TIMEOUT)
	{
		if (*pbNeedStop)
		{
			m_um.Abort ();
			TerminateThread (htCheck, 0);
			CloseHandle (htCheck);
			return FALSE;
		}
	}
	dw = UR_CONNECTION_ERROR;
	GetExitCodeThread (htCheck, &dw);
	CloseHandle (htCheck);

	switch (dw)
	{
	case UR_CONNECTION_ERROR:
		m_iOnBeforeUpload_LastCallResult = LCR_CHECK_FAILED;
		lstrcpy (pszStopReason, LS (L_FAILED_CHECK_FOR_UPDATES));
		break;

	case UR_NO_FRESH_VERSION:
		m_iOnBeforeUpload_LastCallResult = LCR_NO_NEW_VER;
		_timeLastOkCheck = GetTickCount ();
		break;

	case UR_UPDATE_AVAILABLE:
		m_iOnBeforeUpload_LastCallResult = LCR_NEW_VER_DETECTED;
		_timeLastOkCheck = GetTickCount ();
		lstrcpy (pszStopReason, LS (L_UPDATE_REQ));
		PostMessage (WM_COMMAND, ID_UPDATE);
		break;
	}

	_bInFunc = false;

	return m_iOnBeforeUpload_LastCallResult == LCR_NO_NEW_VER;
}

DWORD WINAPI CMainFrame::_threadCheckNewVer(LPVOID lp)
{
	fsUpdateMgr *um = (fsUpdateMgr*)lp;
	return um->CheckForUpdates ();
}

void CMainFrame::OnNeedExit() 
{
	SendMessage (WM_CLOSE);	
}

LRESULT CMainFrame::OnTrayMsg(WPARAM, LPARAM lp)
{
	switch (lp)
	{
		case WM_LBUTTONDOWN:
			if (IsIconic ())
				OnShowmainwindow ();
			else
				ShowWindow (SW_MINIMIZE);
			break;

		case WM_RBUTTONUP:
			ShowTrayMenu ();
			break;
	}
	
	return 0;
}

void CMainFrame::OnShowmainwindow() 
{
	if (IsIconic ())
		ShowWindow (SW_RESTORE);
	else
		ShowWindow (SW_SHOW);

	SetForegroundWindow ();
}

void CMainFrame::ShowTrayMenu()
{
	if (m_bTrayMenuShowing)
		return;

	m_bTrayMenuShowing = TRUE;
	
	CMenu menu;
	menu.LoadMenu (IDM_TRAY);
	CMenu *pPopup = menu.GetSubMenu (0);

	pPopup->SetDefaultItem (ID_SHOWMAINWINDOW);

	CPoint pt;
	GetCursorPos (&pt);

	SetForegroundWindow ();
	
	m_odTrayMenu.Attach (&menu, FALSE);

	

	CString strSMW = LS (L_SHOWMAINWND); strSMW += '\t';
	CString strExit = LS (L_EXIT); strExit += "\tAlt+X";

	fsSetText texts [] = {
		fsSetText (ID_SHOWMAINWINDOW, strSMW),
		fsSetText (ID_CREATENEWUPLOAD, LS (L_UPLOADFILES)),
		fsSetText (ID_APP_ABOUT, LS (L_ABOUT)),
		fsSetText (ID_APP_EXIT, strExit),
	};
	m_odTrayMenu.SetMenuItemsText (&menu, texts, sizeof (texts) / sizeof (fsSetText), FALSE);

	
		
	UINT uFlags = TPM_RIGHTBUTTON;
	uFlags |=  TPM_BOTTOMALIGN | TPM_RIGHTALIGN;

	pPopup->TrackPopupMenu (uFlags,	pt.x, pt.y, this);
	m_odTrayMenu.Detach ();

	menu.DestroyMenu ();

	m_bTrayMenuShowing = FALSE;
}

void CMainFrame::OnCreatenewupload() 
{
	PostMessage (WM_COMMAND, ID_UPL_CREATENEW);	
}

void CMainFrame::OnSize(UINT nType, int cx, int cy) 
{
	if (nType == SIZE_MINIMIZED)
	{
		if (_App.Prg_MinToTray ()) 
			ShowWindow (SW_HIDE);
	}

	CFrameWnd::OnSize(nType, cx, cy);	
}

void CMainFrame::OnSysCommand(UINT nID, LPARAM lParam) 
{
	if (nID == SC_CLOSE && _App.Prg_CloseAsMinimize ())
	{
		ShowWindow (SW_MINIMIZE);
		return;
	}
	
	CFrameWnd::OnSysCommand(nID, lParam);
}

void CMainFrame::SaveState()
{
	_App.View_SaveWndPlacement (this, "MainFrm");
}

void CMainFrame::OnTimer(UINT nIDEvent) 
{
	if (nIDEvent == 1)
	{
		m_wndView.m_pwndUploads->SaveAll ();
	}
	
	CFrameWnd::OnTimer(nIDEvent);
}

LRESULT CMainFrame::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	if (message == m_nShutdownMsg)
		PostMessage (WM_COMMAND, ID_NEED_EXIT);

	else if (message == m_nUploadsMsg1)
		m_wndView.m_pwndUploads->get_Wnd ()->SendMessage (message, wParam, lParam);
	
	return CFrameWnd::WindowProc(message, wParam, lParam);
}
