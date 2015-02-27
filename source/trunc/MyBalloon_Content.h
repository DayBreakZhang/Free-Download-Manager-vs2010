/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_MYBALLOON_CONTENT_H__F5392B7A_0B9F_40A4_ABC8_5246775A1AA3__INCLUDED_)
#define AFX_MYBALLOON_CONTENT_H__F5392B7A_0B9F_40A4_ABC8_5246775A1AA3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CMyBalloon_Content : public CWnd
{

public:
	CMyBalloon_Content();

public:
	virtual CSize getRequiredSize () = NULL;

public:

	
	//{{AFX_VIRTUAL(CMyBalloon_Content)
	//}}AFX_VIRTUAL

public:
	virtual COLORREF getTextColor ();
	virtual COLORREF getBkColor();
	virtual ~CMyBalloon_Content();

	
protected:
	//{{AFX_MSG(CMyBalloon_Content)
		
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
