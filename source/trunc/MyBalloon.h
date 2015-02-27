/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_MYBALLOON_H__F9900663_1031_434B_ACAF_5224B2E68F2B__INCLUDED_)
#define AFX_MYBALLOON_H__F9900663_1031_434B_ACAF_5224B2E68F2B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

const int CX_ROUNDED = 12, CY_ROUNDED = 10;
const int CX_LEADER  = 20, CY_LEADER  = 20;
const int CX_LEADER_MARGIN = 7;

#define WM_MYBALLOON_CLOSED		(WM_APP+7)

class CMyBalloon : public CWnd
{

public:
	CMyBalloon(class CMyBalloon_Content*);

public:

public:

	
	//{{AFX_VIRTUAL(CMyBalloon)
	//}}AFX_VIRTUAL

public:
	virtual void CloseBalloon (bool bByUser);
	void setAnchorPoint (CPoint pt);
	
	void Create (CWnd *pwndParent, bool bTrayBalloon, BYTE byteTrancparency = 255);
	virtual ~CMyBalloon();

	
protected:
	CWnd* m_pwndParent;
	CMyBalloon_Content* m_pContent;
	bool m_bTrayBalloon;
	bool m_bLeaderAtRight, m_bLeaderAtTop;
	CPoint m_ptAnchor;
	void SetupWindowRgn();
	//{{AFX_MSG(CMyBalloon)
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDestroy();
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
