/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FDMBALLOONCONTENT_H__FE26D01C_35BE_44BD_B630_81D31E201D88__INCLUDED_)
#define AFX_FDMBALLOONCONTENT_H__FE26D01C_35BE_44BD_B630_81D31E201D88__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CFdmBalloonContent : public CWnd
{

public:
	CFdmBalloonContent();

public:
	virtual CSize getRequiredSize () = NULL;

public:

	
	//{{AFX_VIRTUAL(CFdmBalloonContent)
	//}}AFX_VIRTUAL

public:
	virtual void Create (CWnd* pwndParent);
	virtual ~CFdmBalloonContent();

	
protected:
	//{{AFX_MSG(CFdmBalloonContent)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
