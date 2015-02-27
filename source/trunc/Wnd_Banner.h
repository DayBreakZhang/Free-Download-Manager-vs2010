/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_WND_BANNER_H__44965A78_BA2D_4C40_AADC_3564F4202F1A__INCLUDED_)
#define AFX_WND_BANNER_H__44965A78_BA2D_4C40_AADC_3564F4202F1A__INCLUDED_

#include "vmsImage_CtxFree.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

class CWnd_Banner : public CWnd
{

public:
	CWnd_Banner();

public:

public:

	
	//{{AFX_VIRTUAL(CWnd_Banner)
	//}}AFX_VIRTUAL

public:
	void Shutdown();
	
	
	
	void SetBanner (LPCSTR pszFile, LPCSTR pszURL);
	BOOL Create (CWnd* pWndParent, int cy);
	virtual ~CWnd_Banner();

	
protected:
	
	int m_iCurrentFrame;
	
	void Initialize();
	BOOL m_bRunning;	
	HDC m_hDCNow;		
	CString m_strImgFile;	
	volatile DWORD m_dwThrJob;	
	
	static DWORD WINAPI _threadImage (LPVOID lp);
	CString m_strURL;	
	vmsImage_CtxFree m_img;	
	//{{AFX_MSG(CWnd_Banner)
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
