/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fdm.h"
#include "TorrentsWnd.h"
#include "plugincmds.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CTorrentsWnd *_pwndTorrents = NULL;

CTorrentsWnd::CTorrentsWnd()
{
}

CTorrentsWnd::~CTorrentsWnd()
{
}

BEGIN_MESSAGE_MAP(CTorrentsWnd, CWnd)
	//{{AFX_MSG_MAP(CTorrentsWnd)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_COMMAND(ID_BTDLD_ADDFROMFILE, OnBtdldAddfromfile)
	ON_COMMAND(ID_BTDLD_ADDFROMURL, OnBtdldAddfromurl)
	ON_COMMAND(ID_BTDLD_AUTOSTART, OnBtdldAutostart)
	ON_COMMAND(ID_BTDLD_CREATENEWTORRENT, OnBtdldCreatenewtorrent)
	ON_COMMAND(ID_BTDLD_DELETE, OnBtdldDelete)
	ON_COMMAND(ID_BTDLD_LAUNCH, OnBtdldLaunch)
	ON_COMMAND(ID_BTDLD_OPENFOLDER, OnBtdldOpenfolder)
	ON_COMMAND(ID_BTDLD_PASSTODLDS, OnBtdldPasstodlds)
	ON_COMMAND(ID_BTDLD_PROPERTIES, OnBtdldProperties)
	ON_COMMAND(ID_BTDLD_START, OnBtdldStart)
	ON_COMMAND(ID_BTDLD_STOP, OnBtdldStop)
	//}}AFX_MSG_MAP

	
	ON_MESSAGE (WM_WGP_SHUTDOWN, OnAppExit)
	ON_MESSAGE (WM_WGP_READYTOSHUTDOWN, OnAppQueryExit)
	ON_MESSAGE (WM_WGP_UPDATE_MENUMAIN, OnUpdateMenu)
	ON_MESSAGE (WM_WGP_UPDATE_MENUVIEW, OnUpdateMenuView)
	ON_MESSAGE (WM_WGP_UPDATE_CMDITEM, OnUpdateToolBar)
	ON_MESSAGE (WM_WGP_INSERT, OnInsert)
	
	ON_COMMAND_RANGE(ID_DLLIST_1, ID_DLLIST_9, OnDLListShowCol)
	

	ON_WM_DESTROY()
END_MESSAGE_MAP()

HWND CTorrentsWnd::Plugin_CreateMainWindow(HWND hWndParent)
{
	if (FALSE == _AppMgr.IsBtInstalled ())
		return NULL; 

	fsnew1 (_pwndTorrents, CTorrentsWnd);
	
	_pwndTorrents->Create (CWnd::FromHandle (hWndParent));
	
	return _pwndTorrents->m_hWnd;
}

void CTorrentsWnd::Plugin_GetToolBarInfo(wgTButtonInfo **ppButtons, int *pcButtons)
{
	static wgTButtonInfo btns [] = 
	{
		wgTButtonInfo (ID_BTDLD_ADDFROMURL, TBSTYLE_BUTTON, ""),
		wgTButtonInfo (ID_BTDLD_ADDFROMFILE, TBSTYLE_BUTTON, ""),
		wgTButtonInfo (ID_BTDLD_CREATENEWTORRENT, TBSTYLE_BUTTON, ""),
		wgTButtonInfo (0, TBSTYLE_SEP, ""),
		wgTButtonInfo (ID_BTDLD_START, TBSTYLE_BUTTON, ""),
		wgTButtonInfo (ID_BTDLD_STOP, TBSTYLE_BUTTON, ""),
	};
	
	btns [0].pszToolTip = LS (L_BTDLD_ADDFROMURL);
	btns [1].pszToolTip = LS (L_BTDLD_ADDFROMFILE);
	btns [2].pszToolTip = LS (L_BTDLD_CREATENEWTORRENT);
	btns [4].pszToolTip = LS (L_STARTDLDS);
	btns [5].pszToolTip = LS (L_STOPDLDS);
	
	*ppButtons = btns;
	*pcButtons = sizeof (btns) / sizeof (wgTButtonInfo);
}

void CTorrentsWnd::Plugin_GetMenuImages(fsSetImage **ppImages, int *pcImages)
{
	static fsSetImage images [] = 
	{
		fsSetImage (ID_BTDLD_ADDFROMURL, 0),
		fsSetImage (ID_BTDLD_ADDFROMFILE, 1),
		fsSetImage (ID_BTDLD_CREATENEWTORRENT, 2),
		fsSetImage (ID_BTDLD_START, 3),
		fsSetImage (ID_BTDLD_STOP, 4),
		fsSetImage (ID_BTDLD_PROPERTIES, 8),
		fsSetImage (ID_BTDLD_DELETE, 9),
	};
	
	*ppImages = images;
	*pcImages = sizeof (images) / sizeof (fsSetImage);
}

void CTorrentsWnd::Plugin_GetMenuViewItems(wgMenuViewItem **ppItems, int* )
{
	*ppItems = NULL;
}

void CTorrentsWnd::Plugin_GetPluginNames(LPCSTR *ppszLong, LPCSTR *ppszShort)
{
	static CString strName;
	strName = LSNP (L_TORRENTS);
	*ppszLong = *ppszShort = strName;
}

void CTorrentsWnd::Plugin_SetLanguage(wgLanguage, HMENU hMenuMain, HMENU hMenuView)
{
	CMenu *menu = CMenu::FromHandle (hMenuMain);
	_pwndTorrents->m_wndTasks.ApplyLanguage ();
	_pwndTorrents->m_wndBtTab.ApplyLanguage ();
	_pwndTorrents->ApplyLanguageToMenuView (CMenu::FromHandle (hMenuView));
	_pwndTorrents->m_wndTasks.ApplyLanguageToMenu (menu);
}

HMENU CTorrentsWnd::Plugin_GetMainMenu()
{
	return LoadMenu (AfxGetInstanceHandle (), MAKEINTRESOURCE (IDM_TORRENTS));
}

HMENU CTorrentsWnd::Plugin_GetViewMenu()
{
	return LoadMenu (AfxGetInstanceHandle (), MAKEINTRESOURCE (IDM_TORRENTS_VIEW));
}

BOOL CTorrentsWnd::Create(CWnd *pwndParent)
{
	CRect rc (0, 0, 50, 50);
	
	if (FALSE == CWnd::Create (AfxRegisterWndClass (0, NULL,
			NULL, NULL), NULL, WS_CHILD | WS_VISIBLE, rc, pwndParent, 0))
		return FALSE;
	
	return TRUE;
}

int CTorrentsWnd::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_wndTasks.Create (this);	
	m_wndBtTab.Create (this);
	m_wndBtTab.ShowWindow (SW_SHOW);

	m_wndSplitter.Create (AfxGetInstanceHandle (), m_hWnd, WST_HORIZONTAL);

	m_wndSplitter.SetWnd1 (m_wndTasks);
	m_wndSplitter.SetWnd2 (m_wndBtTab);

	m_wndSplitter.SetRatio (_App.View_SplitterRatio ("Torrents_DL_BTINFO"));

	DLDS_LIST v;

	_DldsMgr.LockList (true);
	size_t nCount = _DldsMgr.GetCount ();
	for (size_t i = 0; i < nCount; i++)
	{
		if (_DldsMgr.GetDownload (i)->pMgr->IsBittorrent ())
			v.push_back (_DldsMgr.GetDownload (i));
	}
	_DldsMgr.UnlockList (true);

	for (size_t i = 0; i < v.size (); i++)
		m_wndTasks.AddDownload (v [i], FALSE);
	
	return 0;
}

void CTorrentsWnd::OnSize(UINT nType, int cx, int cy) 
{
	CWnd::OnSize(nType, cx, cy);
	
	m_wndSplitter.ApplyRatio ();	
}

LRESULT CTorrentsWnd::OnInsert(WPARAM, LPARAM)
{
	m_wndTasks.OnBtdldAddfromurl ();
	return 0;
}

LRESULT CTorrentsWnd::OnAppExit(WPARAM, LPARAM)
{
	SaveAll (0xffffffff);
	m_wndTasks.DeleteAllItems ();
	SetActiveDownload (NULL);
	return 0;
}

LRESULT CTorrentsWnd::OnAppQueryExit(WPARAM, LPARAM)
{
	return 0;
}

LRESULT CTorrentsWnd::OnUpdateMenu(WPARAM, LPARAM lp)
{
	m_wndTasks.UpdateMenu (CMenu::FromHandle (*((HMENU*)lp)));
	return 0;
}

LRESULT CTorrentsWnd::OnUpdateMenuView(WPARAM, LPARAM lp)
{
	HMENU* pMenus = (HMENU*) lp;
	CMenu* menu = CMenu::FromHandle (pMenus [0]);
	
	BOOL bEn = m_wndTasks.GetHeaderCtrl ()->GetItemCount () > 1;
	for (int i = 0; i < 9; i++)
	{
		if (m_wndTasks.IsColumnShown (i))
		{
			menu->CheckMenuItem (ID_DLLIST_1+i, MF_CHECKED);
			if (bEn == FALSE)
				menu->EnableMenuItem (ID_DLLIST_1+i, MF_GRAYED);
		}
	}
	
	return 0;
}

LRESULT CTorrentsWnd::OnUpdateToolBar(WPARAM wp, LPARAM)
{
	return m_wndTasks.OnUpdateToolBar (wp);
}

void CTorrentsWnd::SaveAll(DWORD dwWhat)
{
	if (dwWhat & 2)
	{
		m_wndTasks.SaveState ();
		_App.View_SplitterRatio ("Torrents_DL_BTINFO", m_wndSplitter.GetRatio ());
	}
}

void CTorrentsWnd::AddDownload(vmsDownloadSmartPtr dld, BOOL bPlaceToTop)
{
	ASSERT (dld->pMgr->IsBittorrent ());
	m_wndTasks.AddDownload (dld, bPlaceToTop);
}

void CTorrentsWnd::ApplyLanguageToMenuView(CMenu *menu)
{
	menu->ModifyMenu (0, MF_BYPOSITION | MF_STRING, 0, LS (L_LISTOFTORRENTS));
	
	UINT aCmds [] = {ID_DLLIST_1, ID_DLLIST_2, ID_DLLIST_3, ID_DLLIST_4, ID_DLLIST_5, 
		ID_DLLIST_6, ID_DLLIST_7, ID_DLLIST_8, ID_DLLIST_9 };
	LPCSTR apszCmds [] = {LS (L_FILENAME), LS (L_SIZE), LS (L_DOWNLOADED),
		LS (L_TIMELEFT), LS (L_RATIO), LS (L_SECTIONS), LS (L_SPEED), LS (L_COMMENT), LS (L_ADDED) };
	
	for (int i = 0; i < sizeof (aCmds) / sizeof (UINT); i++)
		menu->ModifyMenu (aCmds [i], MF_BYCOMMAND|MF_STRING, aCmds [i], apszCmds [i]);
}

void CTorrentsWnd::OnDLListShowCol(UINT nCmd)
{
	int iCol = nCmd - ID_DLLIST_1;
	m_wndTasks.ChangeColumnVisibility (iCol);
}

void CTorrentsWnd::SetActiveDownload(vmsDownloadSmartPtr dld)
{
	m_wndBtTab.Set_ActiveDownload (dld);
}

void CTorrentsWnd::OnBtdldAddfromfile() 
{
	m_wndTasks.OnBtdldAddfromfile ();
}

void CTorrentsWnd::OnBtdldAddfromurl() 
{
	m_wndTasks.OnBtdldAddfromurl ();	
}

void CTorrentsWnd::OnBtdldAutostart() 
{
	m_wndTasks.OnBtdldAutostart ();	
}

void CTorrentsWnd::OnBtdldCreatenewtorrent() 
{
	m_wndTasks.OnBtdldCreatenewtorrent ();	
}

void CTorrentsWnd::OnBtdldDelete() 
{
	m_wndTasks.OnBtdldDelete ();	
}

void CTorrentsWnd::OnBtdldLaunch() 
{
	m_wndTasks.OnBtdldLaunch ();	
}

void CTorrentsWnd::OnBtdldOpenfolder() 
{
	m_wndTasks.OnBtdldOpenfolder ();	
}

void CTorrentsWnd::OnBtdldPasstodlds() 
{
	m_wndTasks.OnBtdldPasstodlds ();	
}

void CTorrentsWnd::OnBtdldProperties() 
{
	m_wndTasks.OnBtdldProperties ();	
}

void CTorrentsWnd::OnBtdldStart() 
{
	m_wndTasks.OnBtdldStart ();	
}

void CTorrentsWnd::OnBtdldStop() 
{
	m_wndTasks.OnBtdldStop ();	
}

void CTorrentsWnd::OnDestroy()
{
	CWnd::OnDestroy();

	SAFE_DELETE (_pwndTorrents);
}
