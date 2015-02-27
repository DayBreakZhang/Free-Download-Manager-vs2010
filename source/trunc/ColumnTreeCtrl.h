/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once

#include "resource.h"

#define WM_CUSTTREE_CHECKBOX_CLICKED		(WM_APP+1111)

#ifdef _OWNER_DRAWN_TREE
#ifndef IDB_TREEBTNS
	#error You should insert IDB_TREEBTNS bitmap to project resources. See control documentation for more info.
#endif 
#endif 

typedef struct _CTVHITTESTINFO { 
  POINT pt; 
  UINT flags; 
  HTREEITEM hItem; 
  int iSubItem;
} CTVHITTESTINFO;

#define ID_CTCC_GETTOOLTIPTEXT	(WM_APP+1)

class CCustomTreeChildCtrl : public CTreeCtrl
{
	friend class CColumnTreeCtrl;

	DECLARE_DYNAMIC(CCustomTreeChildCtrl)

public:

	
	
	CCustomTreeChildCtrl();
	virtual ~CCustomTreeChildCtrl();

	
	
	BOOL GetBkImage(LVBKIMAGE* plvbkImage) const;
	BOOL SetBkImage(LVBKIMAGE* plvbkImage);

protected:
	BOOL PreTranslateMessage(MSG* pMsg);
	virtual int OnToolHitTest(CPoint point, TOOLINFO* pTI ) const;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	CToolTipCtrl m_ttip;
	DECLARE_MESSAGE_MAP()

	int m_nFirstColumnWidth; 
	int m_nOffsetX;      	 
	LVBKIMAGE m_bkImage;	 
	CImageList m_imgBtns;	 

	BOOL CheckHit(CPoint point);

	
	

	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);

	

#ifdef _OWNER_DRAWN_TREE
	LRESULT CustomDrawNotify(LPNMTVCUSTOMDRAW lpnm);
	LRESULT OwnerDraw(CDC* pDC);
	int OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar *pScrollBar);
#endif 

};

class CColumnTreeCtrl : public CStatic
{
public:
	DECLARE_DYNCREATE(CColumnTreeCtrl)
	
	
	 
	CColumnTreeCtrl();
	virtual ~CColumnTreeCtrl();

	
	BOOL Create(DWORD dwStyle , const RECT& rect, CWnd* pParentWnd, UINT nID);

	virtual void PreSubclassWindow();

		

#ifdef DEBUG
	virtual void AssertValid( ) const;
#endif

	CCustomTreeChildCtrl& GetTreeCtrl() { return m_Tree; }
	CHeaderCtrl& GetHeaderCtrl() { return m_Header; }

	int InsertColumn(int nCol,LPCTSTR lpszColumnHeading, int nFormat=0, int nWidth=-1, int nSubItem=-1);
	BOOL DeleteColumn(int nCol);

	void SetFirstColumnMinWidth(UINT uMinWidth);
		
	CString GetItemText(HTREEITEM hItem, int nSubItem);
	void SetItemText(HTREEITEM hItem, int nSubItem, LPCTSTR lpszText);

	HTREEITEM HitTest(CPoint pt, UINT* pFlags=NULL) const;
	HTREEITEM HitTest(CTVHITTESTINFO* pHitTestInfo) const;
	
protected:
	afx_msg LRESULT OnCtccGetToolTipText (WPARAM wp, LPARAM lp);
	bool m_bCreatingWindowByOurself;
	
	DECLARE_MESSAGE_MAP()

	enum ChildrenIDs { HeaderID = 1, TreeID = 2, HScrollID = 3, Header2ID = 4};
	
	CCustomTreeChildCtrl m_Tree;
	CScrollBar m_horScroll;
	CHeaderCtrl m_Header;
	CHeaderCtrl m_Header2;
	
	int m_cyHeader;
	int m_cxTotal;
	int m_xPos;
	int m_xOffset;
	int m_uMinFirstColWidth;
	BOOL m_bHeaderChangesBlocked;

	enum{MAX_COLUMN_COUNT=16}; 

	int m_arrColWidths[MAX_COLUMN_COUNT];
	DWORD m_arrColFormats[MAX_COLUMN_COUNT];
	
	virtual void Initialize();
	void UpdateColumns();
	void RepositionControls();

	virtual void OnDraw(CDC* pDC) {}
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnHeaderItemChanging(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnHeaderItemChanged(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnTreeCustomDraw(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnCancelMode();
	afx_msg void OnEnable(BOOL bEnable);
	afx_msg void OnSettingChange(UINT uFlags, LPCTSTR lpszSection);
	afx_msg BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT *pResult);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};