/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSPLUGINMGR_H__EC8A6B33_6965_4A53_A4E5_94455A78EAD6__INCLUDED_)
#define AFX_FSPLUGINMGR_H__EC8A6B33_6965_4A53_A4E5_94455A78EAD6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "list.h"
#include "plugins.h"
#include "fsODMenu.h"

typedef HWND (*fntCreateMainWindow)(HWND);
typedef HMENU (*fntGetMainMenu)();
typedef HMENU (*fntGetViewMenu)();
typedef void (*fntGetMenuImages)(wgMenuItemImage**, int *);
typedef void (*fntGetTBInfo)(wgTButtonInfo**, int*);
typedef void (*fntGetMenuViewItems)(wgMenuViewItem** ppItems, int* cItems);
typedef void (*fntGetPluginNames)(LPCSTR* ppszLongName, LPCSTR* ppszShortName);
typedef void (*fntSetLanguage)(wgLanguage, HMENU, HMENU);
typedef BOOL (*fntReadyToShutdown)();
typedef void (*fntShutdown)();

struct fsPluginInfo
{
	HMODULE		hLib;	
	HWND		hWnd;		
	CString     strName;		
	CString		strLongName;	
	HMENU hMenuMain;	
	HMENU hMenuView;	
	
	CBitmap* pbmpMenuImages, *pbmpMenuDImages;	

	wgMenuItemImage *pMenuMainImages;	
	int	cMenuMainImages;
	wgMenuItemImage *pMenuViewImages;	
	int cMenuViewImages;
	
	wgMenuViewItem *pMenuViewItems;	
	int cMenuViewItems;
	
	
	fntGetPluginNames pfnGPN;
	fntGetTBInfo pfnGTBI;
	fntGetMenuViewItems pfnGMVI;
	fntSetLanguage pfnSetLanguage;
	fntReadyToShutdown pfnRTS;
	fntShutdown pfnShutdown;
};

class fsPluginMgr  
{
public:
	
	
	BOOL LoadPlugins(CWnd *pPluginsFrame);
	
	int GetPluginCount();
	
	fsPluginInfo& Plugin (int iPlugin);
	
	CImageList* GetImages ();
	
	
	BOOL QueryExit();
	
	void OnNewLng (LPCSTR pszLng);
	
	int OnUpdateToolBar (UINT nID);
	
	void OnSetActivePlugin (int iActive);
	
	void UpdateMenuMain (HMENU* phMenus);
	
	void UpdateMenuView (HMENU* phMenus);
	
	BOOL IsWasExit();
	
	
	
	BOOL OnAppExit(BOOL bQueryForExit = TRUE);

	fsPluginMgr();
	virtual ~fsPluginMgr();

protected:
	int m_iActivePlugin;		
	BOOL m_bWasExit;			
	vmsCriticalSection m_csExit;
	CWnd* m_pPluginsFrame;		
	
	BOOL LoadBuiltIn();
	
	fs::list <fsPluginInfo> m_vWndPlugs, m_vWndLessPlugs;
	CImageList m_images;	
};

#endif 
