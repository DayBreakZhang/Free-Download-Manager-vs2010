/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_WND_DOWNLOADPROGRESS_H__C0502D42_DC5A_4BC7_8595_53B73DA2AEB2__INCLUDED_)
#define AFX_WND_DOWNLOADPROGRESS_H__C0502D42_DC5A_4BC7_8595_53B73DA2AEB2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CWnd_DownloadProgress : public CWnd
{

public:
	CWnd_DownloadProgress();

public:

public:

	
	//{{AFX_VIRTUAL(CWnd_DownloadProgress)
	//}}AFX_VIRTUAL

public:
	void Create (CWnd* pwndParent);
	vmsDownloadSmartPtr m_dld;

	virtual ~CWnd_DownloadProgress();

	
protected:
	int m_iLastProgress;
	CBitmap m_bmpProgress;
	static DWORD WINAPI _threadDraw (LPVOID lp);
	HANDLE m_hthDraw, m_hevDraw, m_hevShutdown;
	int m_nCVPcurr;
	//{{AFX_MSG(CWnd_DownloadProgress)
	afx_msg void OnPaint();
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
