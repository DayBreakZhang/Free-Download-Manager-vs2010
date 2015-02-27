/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_PLUGTOOLBAR_H__7F4831DD_9204_4457_A718_5BBC46CA373E__INCLUDED_)
#define AFX_PLUGTOOLBAR_H__7F4831DD_9204_4457_A718_5BBC46CA373E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "DownloadsWnd.h"	
#include "fsPluginMgr.h"

class CPlugToolBar : public CListBox
{

public:
	CPlugToolBar();

public:

public:

	
	//{{AFX_VIRTUAL(CPlugToolBar)
	//}}AFX_VIRTUAL

public:
	
	void OnNewLng();
	int GetActivePlugin();
	void SetActivePlugin (int iPlugin);
	void SendPluginCommand (UINT uCmd);
	class CPlugFrame* m_pPlugFrame;
	BOOL Create (CWnd *pParent);
	virtual ~CPlugToolBar();

	
protected:
	int m_iActivePlugin;
	class CMainFrame* m_pMainFrame;
	void OnClickItem (int iItem);
	void DrawPressed (CDC *pDC, CPoint pt);
	void InvalidateItem (int item, BOOL bErase = FALSE);
	void DrawMayBeSelected (CDC *pDC, CPoint ptImage);
	int m_iMayBeSelected, m_iPressed;
	void Erase (CDC *pDC, RECT &rc);
	CFont m_font;
	COLORREF m_clrBk, m_clrText;
	BOOL Initialize();
	//{{AFX_MSG(CPlugToolBar)
	afx_msg void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	afx_msg void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnCaptureChanged(CWnd *pWnd);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
