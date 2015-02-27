/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_WNDDLDONENOTIFICATION_H__E20F33DE_1D3F_41A5_B5C4_E00954FE6244__INCLUDED_)
#define AFX_WNDDLDONENOTIFICATION_H__E20F33DE_1D3F_41A5_B5C4_E00954FE6244__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CWndDlDoneNotification : public CFrameWnd
{
public:
	CWndDlDoneNotification();           

public:

public:
	void SetBlend (BYTE val);
	void Create(fsDownload *dld);

	
	//{{AFX_VIRTUAL(CWndDlDoneNotification)
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

protected:
	CRect m_rcName, m_rcLaunch, m_rcOpenFolder;
	bool m_bWasDeletedByAutoDel;
	static void GetWindowPosition (int iPos, CRect *prc);
	int m_nPos;
	void GetNextWindowPosition (CRect *prc);
	vmsDownloadSmartPtr m_dld;
	
	static int m_acWnds [4];
	static vmsCriticalSectionEx m_csWnds;

	virtual ~CWndDlDoneNotification();

	
	//{{AFX_MSG(CWndDlDoneNotification)
	afx_msg void OnDestroy();
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
