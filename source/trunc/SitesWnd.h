/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_SITESWND_H__C6B78BA9_6992_4DB1_A24D_67536F3B5647__INCLUDED_)
#define AFX_SITESWND_H__C6B78BA9_6992_4DB1_A24D_67536F3B5647__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "plugins.h"
#include "fsODMenu.h"
#include "ListCtrlEx.h"
#include "fsSitesMgr.h"

class CSitesWnd : public CListCtrlEx
{

public:
	CSitesWnd();

public:

public:

	
	//{{AFX_VIRTUAL(CSitesWnd)
	//}}AFX_VIRTUAL

public:
	static HMENU Plugin_GetViewMenu();
	static HMENU Plugin_GetMainMenu();
	
	static void Plugin_SetLanguage (wgLanguage, HMENU hMenuMain, HMENU);
	static void Plugin_GetPluginNames(LPCSTR *ppszLong, LPCSTR *ppszShort);
	static void Plugin_GetMenuViewItems(wgMenuViewItem **ppItems, int *cItems);
	static void Plugin_GetMenuImages(fsSetImage **ppImages, int *pcImages);
	static void Plugin_GetToolBarInfo (wgTButtonInfo **ppButtons, int *pcButtons);
	static HWND Plugin_CreateMainWindow (HWND hWndParent);
	

	
	void ApplyLanguage();
	void ApplyLanguageToMenu (CMenu *menu);
	
	
	void SaveAll(DWORD dwWhat);
	
	
	afx_msg void OnSitesAdd();

	
	void SaveSites();
	void LoadSites();
	
	BOOL Create (CWnd* pWndParent);
	virtual ~CSitesWnd();

	
protected:
	
	afx_msg LRESULT OnInsert(WPARAM, LPARAM);
	afx_msg void OnSitesListShowCol (UINT uCmd);
	void UpdateSitesListColMenu (CMenu* menu);
	afx_msg LRESULT OnUpdateMenuView (WPARAM, LPARAM lp);
	void ApplyLanguageToMenuView(CMenu *menu);
	afx_msg LRESULT OnUpdateToolBar(WPARAM wp, LPARAM);
	afx_msg LRESULT OnUpdateMenu(WPARAM, LPARAM lp);
	afx_msg LRESULT OnAppQueryExit(WPARAM, LPARAM);
	afx_msg LRESULT OnAppExit (WPARAM, LPARAM);
	int UpdateToolBar (UINT nID);
	

	struct SwSitesMgrEventParam
	{
		fsSitesMgrEvent ev;
		fsSiteInfoPtr site;
	};
	afx_msg LRESULT OnSwSitesMgrEvent (WPARAM, LPARAM);

	void onEvents (fsSitesMgrEvent ev, fsSiteInfo *site);

	
	void OnForceUpdate();
	
	void CalcCoordsForCurSel();
	void OnKeyDown(WORD wVK);
	
	static void _SitesMgrEvents (fsSitesMgrEvent ev, fsSiteInfo* site, LPVOID lp);
	
	
	BOOL m_bSelectedIsTemp;
	
	void UpdateSite (fsSiteInfo* pSite);
	
	void AddSiteToList (fsSiteInfo* pSite);
	CPoint m_rbPt;
	fsODMenu m_odmenu;
	void OnRClick();
	void UpdateMenu (CMenu* pMenu);
	CImageList m_images, m_selImages;	
	
	//{{AFX_MSG(CSitesWnd)
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	afx_msg void OnSitesDelete();
	afx_msg void OnSitesProperties();
	afx_msg void OnSitesTemprorary();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();
};

//{{AFX_INSERT_LOCATION}}

#endif 
