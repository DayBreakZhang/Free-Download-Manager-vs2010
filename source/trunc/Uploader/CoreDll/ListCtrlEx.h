/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_LISTCTRLEX_H__1447784E_2A04_4014_9A96_4D11F169E148__INCLUDED_)
#define AFX_LISTCTRLEX_H__1447784E_2A04_4014_9A96_4D11F169E148__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "list.h"

struct ListEx_ItemInfo
{
	COLORREF clrBg;	
	COLORREF clrText;	
};

const int LISTEX_MAXCOLUMNS	= 15;

enum fsLCSortMode
{
	LCSM_NONE = 0,	
	LCSM_ASCENDING = 1,	
	LCSM_DESCENDING = 2	
};

enum fsLCSortModeSupport
{
	LCSM_ALL_SUPPORTED = 0,
	LCSM_ASCENDING_NOTSUPPORTED = 1,
	LCSM_DESCENDING_NOTSUPPORTED = 2
};

class CListCtrlEx : public CListCtrl
{

public:
	CListCtrlEx();

public:

public:

	
	//{{AFX_VIRTUAL(CListCtrlEx)
	protected:
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	//}}AFX_VIRTUAL

public:
	int SubItemToSubItem (int nSubItem);
	void VirtualView_AllItemsWillBeDeleted();
	void VirtualView_ItemWillBeDeleted (int nItem);
	void VirtualView_ItemWillBeAdded (COLORREF clrBg, COLORREF clrText, BOOL bAddToBeginning);
	
	void ChangeColumnVisibility (int iColumn);
	
	BOOL IsColumnShown (int iCol);
	
	void SetItemText (int iItem, int iSubItem, LPCSTR pszText);
	
	void SetColumnText (int iCol, LPCSTR pszText);
	
	
	void Initialize ();
	
	void DeleteHdrItem (int iItem);
	
	void SetSelectedImages (CImageList* pImages);
	
	void SetItemColor (int iItem, COLORREF clr, BOOL bUpdate = TRUE);
	
	
	void ReadState (LPCSTR pszName);
	
	void SaveState (LPCSTR pszName);
	
	void UseGrid (BOOL bUse = TRUE);
	
	int AddItem (LPCSTR pszItem, COLORREF clrBg = GetSysColor (COLOR_WINDOW), COLORREF clrText = GetSysColor (COLOR_WINDOWTEXT), int iImage = 0, BOOL bAddToBeginning = FALSE);
	virtual ~CListCtrlEx();

	
protected:
	virtual void OnItemChanged (NM_LISTVIEW* pLV);
	CImageList m_imgsSort;	
	void InitSortImages();
	
	virtual void OnSortModeChanged ();
	fsLCSortMode m_sortMode;	
	fsLCSortModeSupport m_sortModeSupport;
	int m_iSortCol;				
	
	void InsertHdrItem (int iCol);
	
	afx_msg void OnShowCol (UINT uCmd);
	
	void RebuildAIndex();
	int m_cTotalCols;	
	CImageList *m_pSelImages;	
	COLORREF m_clrGrid;	
	BOOL m_bGrid;	
	
	
	int m_aIndex [LISTEX_MAXCOLUMNS];
	
	LPCSTR m_appszCols [LISTEX_MAXCOLUMNS];
	
	void SetItemImage (int iItem, int iImage);
	int GetItemImage(int iItem);
	
	
	
	virtual void OnForceUpdate ();
	
	virtual void OnKeyDown(WORD wVK);
	
	virtual void OnDeleteAllItems ();
	
	virtual void OnDeleteItem (NM_LISTVIEW *pNM);
	
	virtual void OnRClick ();
	
	virtual void OnClick();
	

	
	
	std::vector <ListEx_ItemInfo> m_vInfo;

	
	void DrawItem (LPDRAWITEMSTRUCT lpDraw);

	//{{AFX_MSG(CListCtrlEx)
	afx_msg void OnClick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnRclick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeleteitem(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeleteallitems(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnKeydown(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnParentNotify(UINT message, LPARAM lParam);
	afx_msg void OnColumnclick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnItemchanged(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
