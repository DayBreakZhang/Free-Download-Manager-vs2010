/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "fsPluginMgr.h"
#include "DownloadsWnd.h"

#include "ShedulerWnd.h"
#include "HFEWnd.h"
#include "SitesWnd.h"
#include "SpiderWnd.h"
#include "mfchelp.h"
#include "FlashVideoDownloadsWnd.h"
#include "TorrentsWnd.h"
#include "vmsPluginSupport.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

fsPluginMgr::fsPluginMgr()
{
	m_bWasExit = FALSE;
}

fsPluginMgr::~fsPluginMgr()
{
	for (int i = 0; i < m_vWndPlugs.size (); i++)
	{
		fsPluginInfo *plug = &m_vWndPlugs [i];
		SAFE_DELETE (plug->pbmpMenuImages);
		SAFE_DELETE (plug->pbmpMenuDImages);
		if (plug->hMenuMain) DestroyMenu (plug->hMenuMain);
		if (plug->hMenuView) DestroyMenu (plug->hMenuView);
	}
}

BOOL fsPluginMgr::LoadPlugins(CWnd *pPluginsFrame)
{
	m_pPluginsFrame = pPluginsFrame;

	if (FALSE == LoadBuiltIn ())
		return FALSE;

	for (int i = m_vWndPlugs.size () - 1; i; i--)
		ShowWindow (m_vWndPlugs [i].hWnd, SW_HIDE);

	
	vmsPluginSupport::o ().Initialize ();

	return TRUE;
}

BOOL fsPluginMgr::LoadBuiltIn()
{
	fsPluginInfo plug;

	plug.hLib = NULL;

	m_images.Create (_TB_SIZE_X, _TB_SIZE_Y, ILC_COLOR32 | ILC_MASK, 5, 1);
	
	

	
	fntGetMainMenu afnGMM [] = {
		CDownloadsWnd::Plugin_GetMainMenu,
		CFlashVideoDownloadsWnd::Plugin_GetMainMenu,
		CTorrentsWnd::Plugin_GetMainMenu,
		
		CShedulerWnd::Plugin_GetMainMenu,
		CHFEWnd::Plugin_GetMainMenu,
		CSitesWnd::Plugin_GetMainMenu,
		CSpiderWnd::Plugin_GetMainMenu,
	};
	fntGetViewMenu afnGVM [] = {
		CDownloadsWnd::Plugin_GetViewMenu,
		CFlashVideoDownloadsWnd::Plugin_GetViewMenu,
		CTorrentsWnd::Plugin_GetViewMenu,
		
		CShedulerWnd::Plugin_GetViewMenu,
		CHFEWnd::Plugin_GetViewMenu,
		CSitesWnd::Plugin_GetViewMenu,
		CSpiderWnd::Plugin_GetViewMenu,
	};
	
	
	const int cPlugins = sizeof (afnGMM) / sizeof (fntGetMainMenu);

	
	fntCreateMainWindow afnCMW [] = {
		CDownloadsWnd::Plugin_CreateMainWindow,
		CFlashVideoDownloadsWnd::Plugin_CreateMainWindow,
		CTorrentsWnd::Plugin_CreateMainWindow,
		
		CShedulerWnd::Plugin_CreateMainWindow, 
		CHFEWnd::Plugin_CreateMainWindow,
		CSitesWnd::Plugin_CreateMainWindow, 
		CSpiderWnd::Plugin_CreateMainWindow
	};

	fntGetPluginNames afnGPN [] = {
		CDownloadsWnd::Plugin_GetPluginNames, 
		CFlashVideoDownloadsWnd::Plugin_GetPluginNames, 
		CTorrentsWnd::Plugin_GetPluginNames,
		
		CShedulerWnd::Plugin_GetPluginNames,
		CHFEWnd::Plugin_GetPluginNames, 
		CSitesWnd::Plugin_GetPluginNames, 
		CSpiderWnd::Plugin_GetPluginNames
	};

	fntSetLanguage afnSL [] = {
		CDownloadsWnd::Plugin_SetLanguage, 
		CFlashVideoDownloadsWnd::Plugin_SetLanguage,
		CTorrentsWnd::Plugin_SetLanguage,
		
		CShedulerWnd::Plugin_SetLanguage,
		CHFEWnd::Plugin_SetLanguage, 
		CSitesWnd::Plugin_SetLanguage, 
		CSpiderWnd::Plugin_SetLanguage
	};

	UINT aIDBmps [] = {
		IDB_TOOL_DLDS, IDB_TOOL_DLDS, IDB_TOOL_BT, 
		IDB_TOOL_SCHEDULE, IDB_TOOL_HFE, 
		IDB_TOOL_SITES, IDB_TOOL_SPIDER
	};
	UINT aIDBmpsD [] = {
		IDB_TOOL_DLDS_D, IDB_TOOL_DLDS_D, IDB_TOOL_BT_D, 
		IDB_TOOL_SCHEDULE_D, IDB_TOOL_HFE_D, 
		IDB_TOOL_SITES_D, IDB_TOOL_SPIDER_D
	};

	fntGetMenuImages afnGMI [] = {
		CDownloadsWnd::Plugin_GetMenuImages, 
		CFlashVideoDownloadsWnd::Plugin_GetMenuImages,
		CTorrentsWnd::Plugin_GetMenuImages,
		
		CShedulerWnd::Plugin_GetMenuImages, 
		CHFEWnd::Plugin_GetMenuImages, 
		CSitesWnd::Plugin_GetMenuImages, 
		CSpiderWnd::Plugin_GetMenuImages
	};

	fntGetTBInfo afnGTBI [] = {
		CDownloadsWnd::Plugin_GetToolBarInfo, 
		CFlashVideoDownloadsWnd::Plugin_GetToolBarInfo, 
		CTorrentsWnd::Plugin_GetToolBarInfo,
		
		CShedulerWnd::Plugin_GetToolBarInfo, 
		CHFEWnd::Plugin_GetToolBarInfo, 
		CSitesWnd::Plugin_GetToolBarInfo, 
		CSpiderWnd::Plugin_GetToolBarInfo
	};

	fntGetMenuViewItems afnGMVI [] = {
		CDownloadsWnd::Plugin_GetMenuViewItems, 
		CFlashVideoDownloadsWnd::Plugin_GetMenuViewItems, 
		CTorrentsWnd::Plugin_GetMenuViewItems,
		
		CShedulerWnd::Plugin_GetMenuViewItems, 
		CHFEWnd::Plugin_GetMenuViewItems,
		CSitesWnd::Plugin_GetMenuViewItems, 
		CSpiderWnd::Plugin_GetMenuViewItems
	};
	

	for (int i = 0; i < cPlugins; i++)
	{
		LPCSTR pszPlug, psz;
		afnGPN [i] (&psz, &pszPlug);
	
		
				
		plug.hWnd = afnCMW [i] (m_pPluginsFrame->m_hWnd);
		if (plug.hWnd == NULL)
		{
			if (i == 0)
				return FALSE;
			continue;
		}
		
		
		plug.hMenuMain = afnGMM [i] ();
		plug.hMenuView = afnGVM [i] ();
		
		
				
		fsnew1 (plug.pbmpMenuImages, CBitmap);
		plug.pbmpMenuImages->Attach (SBMP (aIDBmps [i]));
		fsnew1 (plug.pbmpMenuDImages, CBitmap);
		plug.pbmpMenuDImages->Attach (SBMP (aIDBmpsD [i]));

		
		afnGMI [i] (&plug.pMenuMainImages, &plug.cMenuMainImages);
		plug.pMenuViewImages = NULL; plug.cMenuViewImages = 0;
			
		
		plug.pfnGPN = afnGPN [i];
		plug.pfnGTBI = afnGTBI [i];
		plug.pfnGMVI = afnGMVI [i];
		plug.pfnSetLanguage = afnSL [i];
		plug.pfnRTS = NULL;
		plug.pfnShutdown = NULL;
		
		
		afnGMVI [i] (&plug.pMenuViewItems, &plug.cMenuViewItems);

		m_vWndPlugs.add (plug);

		
		wgTButtonInfo* pButtons;
		int cButtons;
		afnGTBI [i] (&pButtons, &cButtons);
		CBitmap bmp1, bmp2;

		bmp1.Attach (SBMP (aIDBmps [i]));
		bmp2.Attach (SBMP (aIDBmpsD [i]));

		if (_TB_USE_ALPHA)
		{
			ConvertBmp32WithAlphaToBmp32WithoutAlpha (bmp1, GetSysColor (COLOR_3DFACE));
			ConvertBmp32WithAlphaToBmp32WithoutAlpha (bmp2, GetSysColor (COLOR_3DFACE));
		}

		_TBMgr.InsertGroup (pButtons, &bmp1, &bmp2, cButtons);
	}

	return TRUE;
}

CImageList* fsPluginMgr::GetImages()
{
	return &m_images;
}

fsPluginInfo& fsPluginMgr::Plugin(int iPlugin)
{
	return m_vWndPlugs [iPlugin];
}

int fsPluginMgr::GetPluginCount()
{
	return m_vWndPlugs.size ();
}

BOOL fsPluginMgr::OnAppExit(BOOL bQueryForExit)
{
	vmsAUTOLOCKSECTION (m_csExit);

	if (m_bWasExit)
		return TRUE;

	if (bQueryForExit)
	{
		if (FALSE == QueryExit ())
			return FALSE;
	}
		
	m_bWasExit = TRUE;

	vmsAUTOLOCKSECTION_UNLOCK (m_csExit);

	_TumMgr.Shutdown ();

	vmsPluginSupport::o ().Shutdown ();

	for (int i = 0; i < m_vWndPlugs.size (); i++)
	{
		if (m_vWndPlugs [i].pfnShutdown)
			m_vWndPlugs [i].pfnShutdown ();
		else
			SendMessage (m_vWndPlugs [i].hWnd, WM_WGP_SHUTDOWN, 0, 0);
	}

	_DldsMgr.Shutdown ();

	vmsBtDownloadManager::Shutdown ();

	if (_BT.is_Initialized ())
		_BT.Shutdown ();

	return TRUE;
}

BOOL fsPluginMgr::IsWasExit()
{
	return m_bWasExit;
}

void fsPluginMgr::UpdateMenuMain(HMENU* phMenus)
{
	SendMessage (m_vWndPlugs [m_iActivePlugin].hWnd, WM_WGP_UPDATE_MENUMAIN, 0, (LPARAM) phMenus);
}

void fsPluginMgr::UpdateMenuView(HMENU* phMenus)
{
	SendMessage (m_vWndPlugs [m_iActivePlugin].hWnd, WM_WGP_UPDATE_MENUVIEW, 0, (LPARAM) phMenus);
}

void fsPluginMgr::OnSetActivePlugin(int iActive)
{
	m_iActivePlugin = iActive;
}

int fsPluginMgr::OnUpdateToolBar(UINT nID)
{
	return SendMessage (m_vWndPlugs [m_iActivePlugin].hWnd, WM_WGP_UPDATE_CMDITEM, nID, (LPARAM)_TBMgr.m_hWnd);
}

void fsPluginMgr::OnNewLng(LPCSTR )
{
	for (int i = 0; i < m_vWndPlugs.size (); i++)
	{
		fsPluginInfo *plug = &m_vWndPlugs [i];
		LPCSTR pszLongName, pszShortName;

		if (plug->pfnSetLanguage)
			plug->pfnSetLanguage (WGL_UNKNOWN, plug->hMenuMain, plug->hMenuView);

		

		plug->pfnGPN (&pszLongName, &pszShortName);
		plug->pfnGMVI (&plug->pMenuViewItems, &plug->cMenuViewItems);

		plug->strLongName = pszLongName;
		plug->strName = pszShortName;

		wgTButtonInfo* pButtons;
		int cButtons;
		plug->pfnGTBI (&pButtons, &cButtons);

		LPCSTR *ppszToolTips;
		fsnew (ppszToolTips, LPCSTR, cButtons);
		for (int j = 0; j < cButtons; j++)
			ppszToolTips [j] = pButtons [j].pszToolTip;

		_TBMgr.UpdateGroupToolTips (i+1, ppszToolTips, cButtons);

		delete [] ppszToolTips;
	}
}

BOOL fsPluginMgr::QueryExit()
{
	for (int i = 0; i < m_vWndPlugs.size (); i++)
	{
		if (m_vWndPlugs [i].pfnRTS)
		{
			if (m_vWndPlugs [i].pfnRTS () == FALSE)
				return FALSE;
		}
		else
		{
			if (0 != SendMessage (m_vWndPlugs [i].hWnd, WM_WGP_READYTOSHUTDOWN, 0, 0))
				return FALSE;
		}
	}

	return TRUE;
}
