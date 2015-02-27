/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fdm.h"
#include "MyBalloon_Content.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CMyBalloon_Content::CMyBalloon_Content()
{
}

CMyBalloon_Content::~CMyBalloon_Content()
{
}

BEGIN_MESSAGE_MAP(CMyBalloon_Content, CWnd)
	//{{AFX_MSG_MAP(CMyBalloon_Content)
		
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

COLORREF CMyBalloon_Content::getBkColor()
{
	return GetSysColor (COLOR_INFOBK);
}

COLORREF CMyBalloon_Content::getTextColor()
{
	return GetSysColor (COLOR_INFOTEXT);
}
