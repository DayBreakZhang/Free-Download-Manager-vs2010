/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSODMENU_H__96CA51C4_937D_4832_A83D_65A4A3C7E117__INCLUDED_)
#define AFX_FSODMENU_H__96CA51C4_937D_4832_A83D_65A4A3C7E117__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "plugins.h"

#define ODMENU_CHECKIMAGE_CHECK	(-1)
#define ODMENU_CHECKIMAGE_RADIO	(-2)

struct fsODMenuItemData
{
	CString strMenuText;	
	BOOL bMenuBar;			
	BOOL bBold;				
	int iImage;				
	int iCheckImage;		
};

typedef wgMenuItemImage fsSetImage;

struct fsSetText 
{
	UINT nIDItem;		
	LPCSTR pszText;		

	fsSetText (UINT nID, LPCSTR psz) : nIDItem (nID), pszText (psz) {}
};

class fsODMenu
{
public:
	
	
	void Attach (CMenu* pMenu, BOOL bMainMenu);
	
	void Detach();
	
	void OnDrawItem (LPDRAWITEMSTRUCT pdis);
	void OnMeasureItem (LPMEASUREITEMSTRUCT pmis);

	
	void SetImageList (CImageList* pList, CImageList *pDisList);
	
	
	
	int InsertMenu (CMenu* pMenu, int iWhere, CMenu *pMenuWhere = NULL);
	
	
	
	
	void RemoveMenu (int iWhere, int iCount, CMenu *pMenuWhere = NULL);
	
	
	
	
	
	void InsertMenuItem (CMenu* pMenu, LPCSTR pszItem, UINT nID, UINT uWhere, BOOL bByPos);
	
	fsODMenuItemData* AddItem (CMenu *pMenu, UINT nID, LPCSTR pszItem);
	
	void RemoveMenuItem (CMenu* pMenu, UINT nID, BOOL bByPos);
	
	
	
	
	void SetMenuItemsText (CMenu* pMenu, fsSetText* pTexts, UINT nSize, BOOL bByPos);
	
	void SetMenuItemText (CMenu* pMenu, LPCSTR pszText, UINT nID, BOOL bByPos = FALSE);
	
	
	
	void SetImages (fsSetImage* pImages,  int cImages, CMenu* pMenu = NULL, BOOL fByPos = FALSE);
	
	fsODMenu();
	virtual ~fsODMenu();

protected:
	
	
	void AttachMenu (CMenu* pMenu, BOOL bMenuBar = FALSE);
	
	
	fsODMenuItemData* AttachMenuItem (CMenu *pMenu, UINT iPos, BOOL bByPos = TRUE);
	
	void DetachMenu (CMenu* pMenu);
	
	void DetachMenuItem (CMenu *pMenu, UINT iPos, BOOL bByPos = TRUE);
	
	
	
	
	
	void DrawCheckMark (CDC *dc, RECT& rc, BOOL bSelected, BOOL bGrayed);
	
	HMENU CopyMenu (HMENU hMenu);

	
	CImageList* m_pImages, *m_pDisImages;
	CFont m_font;	
	UINT m_cyIcon;	
	UINT m_cxIcon;	
	CFont m_fontBold;	
	HMENU m_hMenu;	
};

#endif 
