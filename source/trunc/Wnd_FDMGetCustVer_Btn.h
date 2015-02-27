/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_WND_FDMGETCUSTVER_BTN_H__9F5E62B7_7B56_4A19_A96E_A676E4B9FF37__INCLUDED_)
#define AFX_WND_FDMGETCUSTVER_BTN_H__9F5E62B7_7B56_4A19_A96E_A676E4B9FF37__INCLUDED_

#include "fsODMenu.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

class CWnd_FDMGetCustVer_Btn : public CWnd
{

public:
	CWnd_FDMGetCustVer_Btn();

public:

public:

	
	//{{AFX_VIRTUAL(CWnd_FDMGetCustVer_Btn)
	//}}AFX_VIRTUAL

public:
	void set_AffiliateID (DWORD dwID);
	BOOL Create (CWnd* pwndParent);
	virtual ~CWnd_FDMGetCustVer_Btn();

	
protected:
	fsODMenu m_odmenu;

	
	BOOL is_BtnCanBeMultiline();
	int m_AffiliateID;	
	
	BOOL is_TextMultiline();
	CRect m_rcText;
	
	void CalculateTextRect();
	CFont m_fntText;
	CString m_strBtnText;
	CString m_strBtnURL;
	CBitmap m_bmBtn;	
	//{{AFX_MSG(CWnd_FDMGetCustVer_Btn)
	afx_msg void OnPaint();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	afx_msg void OnHide();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
