/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FDMBALLOON_ONDOWNLOADDONE_H__DE5E2EDC_D350_4D04_B383_1AC36133C690__INCLUDED_)
#define AFX_FDMBALLOON_ONDOWNLOADDONE_H__DE5E2EDC_D350_4D04_B383_1AC36133C690__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "FdmBalloonContent.h"

class CFdmBalloon_OnDownloadDone : public CFdmBalloonContent
{

public:
	CFdmBalloon_OnDownloadDone();

public:
	struct DownloadedItem 
	{
		CString strName;
		CString strFile;
	};
	std::vector <DownloadedItem> m_vItems;

public:

public:

	
	//{{AFX_VIRTUAL(CFdmBalloon_OnDownloadDone)
	//}}AFX_VIRTUAL

public:
	CSize getRequiredSize();
	virtual ~CFdmBalloon_OnDownloadDone();

	
protected:
	int FindLinkIndexUnderCursor();
	int m_cxDone;
	std::vector <CRect> m_vLinksPos;
	std::vector <bool> m_vWasLaunched;
	CFont m_fntUnderline;
	//{{AFX_MSG(CFdmBalloon_OnDownloadDone)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
