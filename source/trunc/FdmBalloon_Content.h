/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FDMBALLOON_CONTENT_H__E4926C1D_2011_49F7_BC5E_7E5D6CB28C60__INCLUDED_)
#define AFX_FDMBALLOON_CONTENT_H__E4926C1D_2011_49F7_BC5E_7E5D6CB28C60__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "MyBalloon_Content.h"

class CFdmBalloon_Content : public CMyBalloon_Content
{

public:
	CFdmBalloon_Content(class CFdmBalloonContent*);

public:

public:

	
	//{{AFX_VIRTUAL(CFdmBalloon_Content)
	//}}AFX_VIRTUAL

public:
	CSize getRequiredSize();
	virtual ~CFdmBalloon_Content();

	
protected:
	CSize m_sCaption;
	CFdmBalloonContent* m_pContent;
	CString m_strCaption;
	CFont m_fntBold;
	//{{AFX_MSG(CFdmBalloon_Content)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
