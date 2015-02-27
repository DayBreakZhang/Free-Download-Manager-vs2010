/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "PluginFrame2.h"
#include "PlugToolBar.h"
#include "MainFrm.h"
#include "DownloadsWnd.h"

extern CDownloadsWnd* _pwndDownloads;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern fsPluginMgr _PluginMgr;

CPluginFrame2::CPluginFrame2()
{
	m_iActivePlugin = -1;
}

CPluginFrame2::~CPluginFrame2()
{
	_App.ActivePlugin (m_iActivePlugin);
}

BEGIN_MESSAGE_MAP(CPluginFrame2, CWnd)
	//{{AFX_MSG_MAP(CPluginFrame2)
	ON_WM_SIZE()
	ON_WM_SETFOCUS()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CPluginFrame2::SendPluginCommand(UINT uCmd)
{
	::SendMessage (_PluginMgr.Plugin (m_iActivePlugin).hWnd, WM_COMMAND, uCmd, 0);
}

BOOL CPluginFrame2::Create(CWnd *pParent)
{
	CRect rc (50, 50, 275, 70);

	if (FALSE == CWnd::Create (AfxRegisterWndClass (0, NULL,
		(HBRUSH) (COLOR_BTNFACE+1), NULL), NULL, WS_CHILD | WS_VISIBLE, rc, pParent, 0x111))
		return FALSE;

	if (FALSE == m_wndTabs.Create (this))
		return FALSE;

	if (FALSE == Initialize ())
		return FALSE;

	ShowWindow (SW_SHOW);

	return TRUE;
}

void CPluginFrame2::SetActivePlugin(int iPlugin)
{
	if (m_iActivePlugin == iPlugin)
		return;

	if (iPlugin == _PluginMgr.GetPluginCount ())
	{
		_App.View_MoreTabs (m_bMoreTabs = FALSE);
		int cur = m_iActivePlugin;
		if (cur > 2)
			cur = 0;
		m_wndTabs.DeleteAllItems ();
		int i = 0;
		for (i = 0; i < 3; i++)
			m_wndTabs.InsertItem (i, _PluginMgr.Plugin (i).strName);
		m_wndTabs.InsertItem (i, ">>");
		m_wndTabs.SetCurSel (cur);
		SetActivePlugin (cur);
		return;
	}

	if (m_bMoreTabs == FALSE && iPlugin >= 3)
	{
		_App.View_MoreTabs (m_bMoreTabs = TRUE);
		m_wndTabs.DeleteItem (3);
		int i;
		for (i = 3; i < _PluginMgr.GetPluginCount (); i++)
			m_wndTabs.InsertItem (i, _PluginMgr.Plugin (i).strName);
		m_wndTabs.InsertItem (i, "<<");
		m_wndTabs.SetCurSel (m_iActivePlugin);
		return;
	}

	if (m_iActivePlugin != -1)
	{
		
		

		::ShowWindow (_PluginMgr.Plugin (m_iActivePlugin).hWnd, SW_HIDE);
		m_pMainFrame->RemovePluginMenu ();
		m_pMainFrame->RemovePluginMenuView ();
		_TBMgr.HideGroup (m_iActivePlugin + 1);
	}

	m_iActivePlugin = iPlugin;
	
	fsPluginInfo &plug = _PluginMgr.Plugin (iPlugin);
	m_pMainFrame->AddPluginMenu (plug.hMenuMain, plug.pMenuMainImages, plug.cMenuMainImages);
	m_pMainFrame->AddPluginMenuView (plug.hMenuView, plug.pMenuViewImages, plug.cMenuViewImages, plug.pMenuViewItems, plug.cMenuViewItems);
	::ShowWindow (plug.hWnd, SW_SHOW);
	::SetFocus (plug.hWnd);
	_TBMgr.ShowGroup (m_iActivePlugin + 1, 0);

	_PluginMgr.OnSetActivePlugin (iPlugin);
	
	m_wndTabs.SetCurSel (m_iActivePlugin);
}

int CPluginFrame2::GetActivePlugin()
{
	return m_iActivePlugin;
}

void CPluginFrame2::OnNewLng()
{
	m_wndTabs.DeleteAllItems ();

	int i = 0;
	for (i = 0; i < _PluginMgr.GetPluginCount (); i++)
	{
		fsPluginInfo *plug = &_PluginMgr.Plugin (i);
		if (i < 3 || m_bMoreTabs)
			m_wndTabs.InsertItem (i, plug->strName);
		else if (i == 3)
			m_wndTabs.InsertItem (i,  ">>");

		if (i == m_iActivePlugin)
		{
			m_pMainFrame->AddPluginMenu (plug->hMenuMain, plug->pMenuMainImages, plug->cMenuMainImages);
			m_pMainFrame->AddPluginMenuView (plug->hMenuView, plug->pMenuViewImages, plug->cMenuViewImages, plug->pMenuViewItems, plug->cMenuViewItems);
		}
	}

	if (m_bMoreTabs)
		m_wndTabs.InsertItem (i, "<<");

	m_wndTabs.SetCurSel (m_iActivePlugin);
}

BOOL CPluginFrame2::Initialize()
{
	m_pMainFrame = (CMainFrame*) AfxGetApp ()->m_pMainWnd;
	m_bMoreTabs = _App.View_MoreTabs ();

	
	if (FALSE == _PluginMgr.LoadPlugins (this))
		return FALSE;

	int cMenuImages;

	for (int i = 0; i < _PluginMgr.GetPluginCount (); i++)
	{
		fsPluginInfo &plug = _PluginMgr.Plugin (i);
		if (i < 3 || m_bMoreTabs)
			m_wndTabs.InsertItem (i, plug.strName);
		else if (i == 3)
			m_wndTabs.InsertItem (i, ">>");

		::ShowWindow (plug.hWnd, SW_HIDE);
		
		if (plug.pbmpMenuImages)
		{
			
			cMenuImages = m_pMainFrame->m_imgsTool.GetImageCount ();
			m_pMainFrame->m_imgsTool.Add (plug.pbmpMenuImages, RGB (255, 0, 255));
			m_pMainFrame->m_dimgsTool.Add (plug.pbmpMenuDImages, RGB (255, 0, 255));
			delete plug.pbmpMenuImages;
			delete plug.pbmpMenuDImages;
			plug.pbmpMenuImages = plug.pbmpMenuDImages = NULL;
			
			

			int j = 0;
			for (j = 0; j < plug.cMenuMainImages; j++)
			{
				plug.pMenuMainImages [j].iCheckImage += cMenuImages;
				plug.pMenuMainImages [j].iImage += cMenuImages;
			}

			for (j = 0; j < plug.cMenuViewImages; j++)
			{
				plug.pMenuViewImages [j].iCheckImage += cMenuImages;
				plug.pMenuViewImages [j].iImage += cMenuImages;
			}
		}
	}

	int iPlug = _App.ActivePlugin ();
	if (iPlug >= _PluginMgr.GetPluginCount () || iPlug < 0)
		iPlug = 0;
	if (m_bMoreTabs == FALSE && iPlug > 2)
		iPlug = 0;

	SetActivePlugin (iPlug);

	return TRUE;
}

void CPluginFrame2::OnSize(UINT nType, int cx, int cy) 
{
	CWnd::OnSize(nType, cx, cy);

	if (cx && cy)
	{
		int tabcy = 23; 
		if (IsWindow (m_wndTabs.m_hWnd))
		{
			CRect rc;
			m_wndTabs.GetItemRect (0, &rc);
			tabcy = rc.bottom - rc.top;
			tabcy += 3;
			m_wndTabs.MoveWindow (0, 0, cx+10, tabcy);	
		}

		for (int i = 0; i < _PluginMgr.GetPluginCount (); i++)
			::MoveWindow (_PluginMgr.Plugin (i).hWnd, 0, tabcy, cx, cy - tabcy, TRUE);
	}
}

void CPluginFrame2::OnSetFocus(CWnd* pOldWnd) 
{
	CWnd::OnSetFocus(pOldWnd);
	
	if (m_iActivePlugin != -1)
	{
		fsPluginInfo &plug = _PluginMgr.Plugin (m_iActivePlugin);
		::SetFocus (plug.hWnd);
	}
}

BOOL CPluginFrame2::OnEraseBkgnd(CDC* pDC) 
{
	
	
	
	
	if (_pwndDownloads->m_wndDownloads.m_info.m_video.m_wndVideo.m_player.Get_State () != VFPS_CLOSED)
	{
    		CRect rc;

		
		_pwndDownloads->m_wndDownloads.m_info.m_video.GetWindowRect(&rc);
		ScreenToClient(&rc);

		
		pDC->ExcludeClipRect(&rc);
	}

	return CWnd::OnEraseBkgnd(pDC);
}
