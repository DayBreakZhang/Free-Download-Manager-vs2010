/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_HFE_ADDRESS_H__F157DF67_3742_4B46_975C_12E9CD724673__INCLUDED_)
#define AFX_HFE_ADDRESS_H__F157DF67_3742_4B46_975C_12E9CD724673__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "ComboBox_Ex.h"

class CHFE_Address : public CWnd
{
	friend class CHFEWnd;
	friend class CHFE_FileList;

public:
	CHFE_Address();

public:

public:

	
	//{{AFX_VIRTUAL(CHFE_Address)
	//}}AFX_VIRTUAL

public:
	void ClearHistory();
	
	CString PopUrl();
	
	void PushUrl (LPCSTR pszUrl);
	
	void UpdateUrl();
	void ApplyLanguage();
	
	LPCSTR GetUrl();
	BOOL Create (CWnd* pParent);
	virtual ~CHFE_Address();

	
protected:
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	
	
	void HfeGo(BOOL bPushUrl = TRUE);
	
	afx_msg void OnHfeBack();
	fs::list <CString> m_vAddrs;	
	CImageList m_imgsBarGo, m_imgsBarBack, m_imgsBarBack_D;
	
	void CreateBars();
	CToolBar m_barGo;
	CToolBar m_barBack;
	CString m_strUrl;	
	CRect m_rcUrl;		
	void DrawUrlFrame (CDC* dc);
	CFont m_font;		
	CComboBox_Ex m_wndUrl;
	
	//{{AFX_MSG(CHFE_Address)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
	afx_msg void OnHfeGo();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
