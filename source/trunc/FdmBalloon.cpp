/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fdm.h"
#include "FdmBalloon.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CFdmBalloon::CFdmBalloon(CFdmBalloonContent* p) : 
	m_wndContent (p),
	CMyBalloon (&m_wndContent)
{
}

CFdmBalloon::~CFdmBalloon()
{
}

BEGIN_MESSAGE_MAP(CFdmBalloon, CMyBalloon)
	//{{AFX_MSG_MAP(CFdmBalloon)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

int CFdmBalloon::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CMyBalloon::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	return 0;
}
