/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLGVIDSEEK_H__909ED8B4_A02B_4EFE_9297_AA426833BB15__INCLUDED_)
#define AFX_DLGVIDSEEK_H__909ED8B4_A02B_4EFE_9297_AA426833BB15__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CDlgVidSeek : public CDialog
{

public:
	HWND m_hWndDuration;
	CString GetDuration();
	
	void Set_MediaSeeking (IMediaSeeking* seek);
	CDlgVidSeek(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlgVidSeek)
	enum { IDD = IDD_VIDSEEK };
	CSliderCtrl	m_wndSeek;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlgVidSeek)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	CBrush m_brClrWindow;
	CString DurationToString (LONGLONG llDur, BOOL* pbNeedHours = NULL);
	LONGLONG m_llDuration;
	IMediaSeeking* m_seek;

	
	//{{AFX_MSG(CDlgVidSeek)
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
