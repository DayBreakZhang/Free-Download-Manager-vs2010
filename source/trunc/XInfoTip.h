/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef _XPOPUPTIP_H_INCLUDE_
#define _XPOPUPTIP_H_INCLUDE_

#if _MSC_VER >= 1000
#pragma once
#endif 

#include <afxtempl.h>

class CXInfoTip : public CWnd
{
protected:
	
	
	
	typedef struct
	{
		CString	szText;											
		HICON	hIcon;											
	} TipToolInfo;

	
	enum
	{
		timerShow			= 100,								
		timerHide			= 101,								
		timerShowNAH		= 102								
	};

	LPCTSTR		m_szClass;										

	int			m_nShowDelay;									

	CPoint		m_ptOrigin;										

	CString		m_szText;										
	CString		m_strCaption;
	int m_nCaptionHeight;

	UINT		m_nTimer;										

	HICON		m_hIcon;										
	CSize		m_IconSize;										

	CFont		m_fntNormal;									
	CFont		m_fntBold;

	CMap<HWND, HWND, TipToolInfo, TipToolInfo>	m_ToolMap;		

public:
	void SetAutohideDelay (int nDelay);
	BOOL is_DontShowChecked();
	CXInfoTip();
	virtual ~CXInfoTip();

	BOOL Create(CWnd *parent);

	void AddTool(CWnd *pWnd, LPCTSTR szTooltipText, HICON hIcon = NULL);
	void RemoveTool(CWnd *pWnd);

	void Show(LPCSTR pszCaption, CString szText, BOOL bAutoHide = TRUE, CPoint *pt = NULL);
	void Hide() { 
		ShowWindow(SW_HIDE); 
		if (m_nTimer == timerShowNAH)
			m_nTimer = 0; 
	};

	
	void SetShowDelay(int nDelay) { m_nShowDelay = nDelay; };

	void SetIcon(HICON hIcon);

	
	

	void RelayEvent(LPMSG lpMsg);

protected:
	BOOL GetWindowRegion(CDC *pDC, HRGN* hRegion, CSize* Size = NULL);

protected:
	int m_nAutohideDelay;
	BOOL m_bShowDSA;
	BOOL m_bDSAChecked;
	afx_msg void OnDSA();
	afx_msg BOOL OnSetCursor (CWnd* pWnd, UINT nHitTest, UINT message);
	bool m_bPlaced;
	int m_yDSA, m_cxDSA;
	CBrush m_brWnd;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CButton m_btnDSA;	
	afx_msg void OnLButtonDown (UINT, CPoint);
	//{{AFX_MSG(CXInfoTip)
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}

#endif 
