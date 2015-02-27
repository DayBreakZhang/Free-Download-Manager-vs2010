/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "SpiderWnd.h"
#include "SpiderAddPageDlg.h"
#include "WPDS_Sheet.h"
#include "MainFrm.h"
#include "plugincmds.h"
#include "FdmUiWindow.h"
#include "vmsLogger.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define WM_SW_DOWNLOADER_EVENT			(WM_APP + 1000)

CSpiderWnd *_pwndSpider = NULL;

CSpiderWnd::CSpiderWnd()
{
	m_mgr.SetEventsFunc (_DownloaderEvents, this);
}

CSpiderWnd::~CSpiderWnd()
{
}

BEGIN_MESSAGE_MAP(CSpiderWnd, CWnd)
	//{{AFX_MSG_MAP(CSpiderWnd)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_TIMER()
	ON_COMMAND(ID_SPIDER_DELETE, OnSpiderDelete)
	ON_COMMAND(ID_SPIDER_OPENFOLDER, OnSpiderOpenfolder)
	ON_COMMAND(ID_SPIDER_OPENPAGE, OnSpiderOpenpage)
	ON_COMMAND(ID_SPIDER_SCHEDULE, OnSpiderSchedule)
	ON_COMMAND(ID_SPIDER_SETTINGS, OnSpiderSettings)
	ON_COMMAND(ID_SPIDER_STARTAUTOMATICALLY, OnSpiderStartautomatically)
	ON_COMMAND(ID_SPIDER_STARTDL, OnSpiderStartdl)
	ON_COMMAND(ID_SPIDER_STOPDL, OnSpiderStopdl)
	ON_COMMAND(ID_SPIDER_DL, OnSpiderDl)
	ON_WM_SETFOCUS()
	//}}AFX_MSG_MAP

	
	ON_MESSAGE (WM_WGP_SHUTDOWN, OnAppExit)
	ON_MESSAGE (WM_WGP_READYTOSHUTDOWN, OnAppQueryExit)
	ON_MESSAGE (WM_WGP_UPDATE_MENUMAIN, OnUpdateMenu)
	ON_MESSAGE (WM_WGP_UPDATE_MENUVIEW, OnUpdateMenuView)
	ON_MESSAGE (WM_WGP_UPDATE_CMDITEM, OnUpdateToolBar)
	ON_MESSAGE (WM_WGP_INSERT, OnInsert)
	
	ON_COMMAND(WGP_MENU_VIEWSMPLITEM_CMDSTART+0, OnShowTree)

	ON_COMMAND_RANGE(ID_LOW_1, ID_LOW_3, OnPagesListShowCol)
	
	
	ON_WM_DESTROY()
	ON_MESSAGE(WM_SW_DOWNLOADER_EVENT, OnWmSWDownloaderEvent)
END_MESSAGE_MAP()

HWND CSpiderWnd::Plugin_CreateMainWindow(HWND hParent)
{
	fsnew1 (_pwndSpider, CSpiderWnd);

	_pwndSpider->Create (CWnd::FromHandle (hParent));

	return _pwndSpider->m_hWnd;
}

BOOL CSpiderWnd::Create(CWnd *pParent)
{
	CRect rc (0, 0, 50, 50);

	if (FALSE == CWnd::Create (AfxRegisterWndClass (0, NULL,
		NULL, NULL), NULL, WS_CHILD | WS_VISIBLE, rc, pParent, 0x9a16))
		return FALSE;

	return TRUE;
}

void CSpiderWnd::Plugin_GetToolBarInfo(wgTButtonInfo **ppButtons, int *pcButtons)
{
	static wgTButtonInfo btns [] = 
	{
		wgTButtonInfo (ID_SPIDER_DL, TBSTYLE_BUTTON, ""),
		wgTButtonInfo (ID_SPIDER_STARTDL, TBSTYLE_BUTTON, ""),
		wgTButtonInfo (ID_SPIDER_STOPDL, TBSTYLE_BUTTON, ""),
		wgTButtonInfo (ID_SPIDER_SCHEDULE, TBSTYLE_BUTTON, ""),
	};

	btns [0].pszToolTip = LS (L_DLWEBPAGE);
	btns [1].pszToolTip = LS (L_STARTDL);
	btns [2].pszToolTip = LS (L_STOPDL);
	btns [3].pszToolTip = LS (L_SCHEDULEDL);

	*ppButtons = btns;
	*pcButtons = sizeof (btns) / sizeof (wgTButtonInfo);
}

void CSpiderWnd::Plugin_GetMenuImages(fsSetImage **ppImages, int *pcImages)
{
	static fsSetImage images [] = 
	{
		fsSetImage (ID_SPIDER_DL, 0),
		fsSetImage (ID_SPIDER_STARTDL, 1),
		fsSetImage (ID_SPIDER_STOPDL, 2),
		fsSetImage (ID_SPIDER_SCHEDULE, 3),
		fsSetImage (ID_SPIDER_SETTINGS, 4),
		fsSetImage (ID_SPIDER_DELETE, 5),
	};

	*ppImages = images;
	*pcImages = sizeof (images) / sizeof (fsSetImage);
}

void CSpiderWnd::Plugin_GetMenuViewItems(wgMenuViewItem **ppItems, int *cItems)
{
	static wgMenuViewItem aItems [] = {
		wgMenuViewItem ("", &_pwndSpider->m_bShowTree),
	};

	aItems [0].pszName = LS (L_WEBPAGETREE);

	*ppItems = aItems;
	*cItems = sizeof (aItems) / sizeof (wgMenuViewItem);
}

void CSpiderWnd::Plugin_GetPluginNames(LPCSTR *ppszLong, LPCSTR *ppszShort)
{
	*ppszLong = *ppszShort = LS (L_HTMLSPIDER);
}

int CSpiderWnd::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (FALSE == m_wndTasks.Create (this))
		return -1;

	if (FALSE == m_wndTaskTree.Create (this))
		return -1;

	if (FALSE == m_wndSplitter.Create (AfxGetInstanceHandle (), m_hWnd, WST_HORIZONTAL))
		return -1;

	m_wndSplitter.SetWnd1 (m_wndTasks);
	m_wndSplitter.SetWnd2 (m_wndTaskTree);
	m_wndSplitter.SetRatio (_App.View_SplitterRatio ("Spider_T_TT"));

	m_bShowTree = _App.View_SpiderTree ();
	ShowTree (m_bShowTree);

	LoadPages ();

	SetTimer (1, 1000, NULL);
	
	return 0;
}

void CSpiderWnd::OnSize(UINT , int cx, int cy) 
{
	if (m_bShowTree)
		m_wndSplitter.ApplyRatio ();
	else
		m_wndTasks.MoveWindow (0, 0, cx, cy);
}

void CSpiderWnd::ShowTree(BOOL bShow)
{
	UINT nShow = bShow ? SW_SHOW : SW_HIDE;
	m_wndTaskTree.ShowWindow (nShow);
	::ShowWindow (m_wndSplitter.m_wndSplitter, nShow);

	m_bShowTree = bShow;
	_App.View_SpiderTree (bShow);

	RECT rc;
	GetClientRect (&rc);
	OnSize (0, rc.right, rc.bottom);
}

LRESULT CSpiderWnd::OnAppExit(WPARAM, LPARAM)
{
	m_mgr.SetEventsFunc (NULL, NULL);
	SaveAll (0xffffffff);
	return 0;
}

LRESULT CSpiderWnd::OnAppQueryExit(WPARAM, LPARAM)
{
	return 0;
}

LRESULT CSpiderWnd::OnUpdateMenu(WPARAM, LPARAM lp)
{
	m_wndTasks.UpdateMenu (CMenu::FromHandle (*((HMENU*)lp)));
	return 0;
}

LRESULT CSpiderWnd::OnUpdateToolBar(WPARAM wp, LPARAM)
{
	return m_wndTasks.UpdateToolBar (wp);
}

void CSpiderWnd::OnShowTree()
{
	ShowTree (m_bShowTree == FALSE);
}

void CSpiderWnd::SaveAll(DWORD dwWhat)
{
	if (dwWhat & 2)
	{
		_App.View_SplitterRatio ("Spider_T_TT", m_wndSplitter.GetRatio ());
		m_wndTasks.SaveState ("SpiderTasks");
	}
	if (dwWhat & 1)
	{
		SavePages ();
	}
}

void CSpiderWnd::OnSpiderDl() 
{
	m_wndTasks.OnSpiderDl ();
}

fsWebPageDownloader* CSpiderWnd::AddWebPage(LPCSTR pszStartUrl, BOOL bReqTopMost, CFdmUiWindow *pUiWindow)
{
	fsWebPageDownloaderPtr wpd;
	wpd.CreateInstance ();

	CSpiderAddPageDlg dlg;
	dlg.m_wpd = wpd;
	dlg.m_pUiWindow = pUiWindow;
	if (pszStartUrl)
		dlg.m_strStartUrl = pszStartUrl;
	else
		dlg.m_strStartUrl = "";

	dlg.m_bReqTopMost = bReqTopMost;

	if (_DlgMgr.DoModal (&dlg) == IDCANCEL)
		return NULL;

	m_mgr.Add (wpd);

	if (wpd->Create (dlg.m_strUrl, dlg.m_bAutoStart, dlg.m_bScheduled ? &dlg.m_schScheduleParam.schTask : NULL) == FALSE)
		m_mgr.Delete (wpd);
	else
		m_wndTasks.AddWebPage (wpd);

	return wpd;
}

void CSpiderWnd::_DownloaderEvents(fsWebPageDownloader *dldr, fsWPDEvent ev, fsDownload *dld, fsDLWebPage *wp, fsDLWebPageTree wptree, LPVOID lp)
{
	CSpiderWnd* pThis = (CSpiderWnd*)  lp;

	WmSWDownloaderEventParam *p = new WmSWDownloaderEventParam;
	p->dldr = dldr;
	p->ev = ev;
	p->dld = dld;
	p->wp = wp;
	p->wptree = wptree;

	if (ev == WPDE_FILEADDED)
		p->wptreeAdded = wptree ? wptree->GetLeaf (wptree->GetLeafCount () - 1) : NULL;

	pThis->PostMessage (WM_SW_DOWNLOADER_EVENT, 0, (LPARAM)p);
}

void CSpiderWnd::OnTimer(UINT nIDEvent) 
{
	
	
	for (int i = 0; i < m_mgr.GetWPDCount (); i++)
	{
		try
		{ 
			fsWebPageDownloader *wpd = m_mgr.GetWPD (i);
			if (wpd->IsDownloading ())
				m_wndTasks.UpdateWebPage (wpd);
		}
		catch (const std::exception& ex)
		{
			ASSERT (FALSE);
			vmsLogger::WriteLog("CSpiderWnd::OnTimer " + tstring(ex.what()));
		}
		catch (...)
		{
			ASSERT (FALSE);
			vmsLogger::WriteLog("CSpiderWnd::OnTimer unknown exception");
		}
	}
	
	CWnd::OnTimer(nIDEvent);
}

fsWebPageDownloadsMgr* CSpiderWnd::GetMgr()
{
	return &m_mgr;
}

void CSpiderWnd::LoadPages()
{
	do
	{
		if (FALSE == m_mgr.Load ())
		{
			
				break;
		}
		else
			break;
	}
	while (TRUE);

	for (int i = 0; i < m_mgr.GetWPDCount (); i++)
		m_wndTasks.AddWebPage (m_mgr.GetWPD (i));
}

void CSpiderWnd::SavePages()
{
	m_mgr.Save ();
}

void CSpiderWnd::SetupDefSettings()
{
	fsWPDSettings wpds;
	fsWebPageDownloader::ReadDefaultWPDS (&wpds);
	CWPDS_Sheet sheet (LS (L_SPIDERDEFSETTINGS), this);
	sheet.Init (&wpds, FALSE, NULL, true);

	_DlgMgr.OnDoModal (&sheet);
	sheet.DoModal ();
	_DlgMgr.OnEndDialog (&sheet);
	
	_App.Spider_Depth (wpds.iDepth);
	_App.Spider_DownloadFiles (wpds.bDownloadFiles);
	_App.Spider_DownloadImages (wpds.bDownloadImages);
	_App.Spider_DownloadStyles (wpds.bDownloadStyles);
	_App.Spider_Exts (wpds.strExts);
	_App.Spider_ExtsType (wpds.enExtsType);
	_App.Spider_HTMLExts (wpds.strHTMLExts);
	_App.Spider_NotAllFiles (wpds.bNotAllFiles);
	_App.Spider_NotAllImages (wpds.bNotAllImages);
	_App.Spider_NotAllPages (wpds.bNotAllPages);
	_App.Spider_ImgExts (wpds.strImgsExts);
	_App.Spider_ImgExtsType (wpds.enImgsExtsType);
	_App.Spider_SavePagesUnderHTM (wpds.bSavePagesUnderHTM);
}

void CSpiderWnd::ApplyLanguage()
{
	m_wndTasks.ApplyLanguage ();
}

void CSpiderWnd::OnSpiderDelete() 
{
	m_wndTasks.OnSpiderDelete ();	
}

void CSpiderWnd::OnSpiderOpenfolder() 
{
	m_wndTasks.OnSpiderOpenfolder ();	
}

void CSpiderWnd::OnSpiderOpenpage() 
{
	m_wndTasks.OnSpiderOpenpage ();	
}

void CSpiderWnd::OnSpiderSchedule() 
{
	m_wndTasks.OnSpiderSchedule ();	
}

void CSpiderWnd::OnSpiderSettings() 
{
	m_wndTasks.OnSpiderSettings ();	
}

void CSpiderWnd::OnSpiderStartautomatically() 
{
	m_wndTasks.OnSpiderStartautomatically ();	
}

void CSpiderWnd::OnSpiderStartdl() 
{
	m_wndTasks.OnSpiderStartdl ();	
}

void CSpiderWnd::OnSpiderStopdl() 
{
	m_wndTasks.OnSpiderStopdl ();
}

void CSpiderWnd::OnSetFocus(CWnd* pOldWnd) 
{
	CWnd::OnSetFocus(pOldWnd);
	m_wndTasks.SetFocus ();
}

void CSpiderWnd::UpdateTasksIcons()
{
	m_wndTasks.UpdateIcons ();
	m_wndTaskTree.UpdateAll ();
}

void CSpiderWnd::Plugin_SetLanguage(wgLanguage, HMENU hMenuMain, HMENU hMenuView)
{
	CMenu *menu = CMenu::FromHandle (hMenuMain);
	_pwndSpider->m_wndTasks.ApplyLanguageToMenu (menu);
	_pwndSpider->ApplyLanguage ();
	_pwndSpider->ApplyLanguageToMenuView (CMenu::FromHandle (hMenuView));
}

void CSpiderWnd::ApplyLanguageToMenuView(CMenu *menu)
{
	menu->ModifyMenu (0, MF_BYPOSITION | MF_STRING, 0, LS (L_LISTOFPAGES));

	UINT aCmds [] = {ID_LOW_1, ID_LOW_2, ID_LOW_3};
	LPCSTR apszCmds [] = {LS (L_WEBPAGEURL), LS (L_PROGRESS), LS (L_FILES)};
	
	for (int i = 0; i < sizeof (aCmds) / sizeof (UINT); i++)
		menu->ModifyMenu (aCmds [i], MF_BYCOMMAND|MF_STRING, aCmds [i], apszCmds [i]);
}

LRESULT CSpiderWnd::OnUpdateMenuView(WPARAM, LPARAM lp)
{
	HMENU* pMenus = (HMENU*) lp;
	UpdatePagesListColMenu (CMenu::FromHandle (pMenus [0]));
	return 0;
}

void CSpiderWnd::UpdatePagesListColMenu(CMenu *menu)
{
	BOOL bEn = m_wndTasks.GetHeaderCtrl ()->GetItemCount () > 1;
	for (int i = 0; i < 3; i++)
	{
		if (m_wndTasks.IsColumnShown (i))
		{
			menu->CheckMenuItem (ID_LOW_1+i, MF_CHECKED);
			if (bEn == FALSE)
				menu->EnableMenuItem (ID_LOW_1+i, MF_GRAYED);
		}
	}
}

void CSpiderWnd::OnPagesListShowCol(UINT uCmd)
{
	int iCol = uCmd - ID_LOW_1;
	m_wndTasks.ChangeColumnVisibility (iCol);
}

LRESULT CSpiderWnd::OnInsert(WPARAM, LPARAM)
{
	m_wndTasks.OnSpiderDl ();
	return 0;
}

HMENU CSpiderWnd::Plugin_GetMainMenu()
{
	return LoadMenu (AfxGetInstanceHandle (), MAKEINTRESOURCE (IDM_SPIDER));
}

HMENU CSpiderWnd::Plugin_GetViewMenu()
{
	return LoadMenu (AfxGetInstanceHandle (), MAKEINTRESOURCE (IDM_SPIDER_VIEW));
}

void CSpiderWnd::OnDestroy()
{
	CWnd::OnDestroy();

	SAFE_DELETE (_pwndSpider);
}

void CSpiderWnd::onDownloaderEvents(fsWebPageDownloader *dldr, fsWPDEvent ev, fsDownload *dld, fsDLWebPage *wp, fsDLWebPageTree wptree, fsDLWebPageTree wptreeAdded)
{
	switch (ev)
	{
	case WPDE_DLDEVENTRECEIVED:
		m_wndTaskTree.UpdateDownload (dld);
		break;

	case WPDE_FILEADDED:
		m_wndTaskTree.OnFileAdded (wptree, wptreeAdded);
		break;

	case WPDE_DLDWILLBEDELETED:
		m_wndTaskTree.OnDldWillBeDeleted (dld);
		break;

	case WPDE_DLDRESTORED:
		m_wndTaskTree.UpdateDownload (dld);
		break;

	case WPDE_WEBPAGEWILLBEDELETED:
		m_wndTaskTree.OnWebPageWillBeDeleted (wp);
		m_wndTasks.UpdateWebPage (dldr);
		break;

	case WPDE_STOPPED:
		break;

	case WPDE_DONE:
		CString strtmp;
		char szUrl [10000];
		dldr->GetDownloadingSiteName (szUrl);
		strtmp.Format ("%s - %s", szUrl, LS (L_DONE));
		CMainFrame::ShowTimeoutBalloon (strtmp, vmsFdmAppMgr::getAppName ());
		break;
	}

	m_wndTasks.UpdateWebPage (dldr);
}

afx_msg LRESULT CSpiderWnd::OnWmSWDownloaderEvent(WPARAM wp, LPARAM lp)
{
	WmSWDownloaderEventParam *param = (WmSWDownloaderEventParam*)lp;
	ASSERT (param != NULL);
	if (!param)
		return 0;
	onDownloaderEvents (param->dldr, param->ev, param->dld, param->wp, param->wptree, param->wptreeAdded);
	delete param;
	return 0;
}
