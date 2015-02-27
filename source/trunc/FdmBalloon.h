/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FDMBALLOON_H__794A5A35_0226_4212_B0C2_554ECBE6CFDE__INCLUDED_)
#define AFX_FDMBALLOON_H__794A5A35_0226_4212_B0C2_554ECBE6CFDE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "MyBalloon.h"
#include "FdmBalloon_Content.h"	

class CFdmBalloon : public CMyBalloon
{

public:
	CFdmBalloon(class CFdmBalloonContent*);

public:

public:

	
	//{{AFX_VIRTUAL(CFdmBalloon)
	//}}AFX_VIRTUAL

public:
	virtual ~CFdmBalloon();

	
protected:
	CFdmBalloon_Content m_wndContent;
	//{{AFX_MSG(CFdmBalloon)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
