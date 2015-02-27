/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fdm.h"
#include "FdmBalloonContent.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CFdmBalloonContent::CFdmBalloonContent()
{
}

CFdmBalloonContent::~CFdmBalloonContent()
{
}

BEGIN_MESSAGE_MAP(CFdmBalloonContent, CWnd)
	//{{AFX_MSG_MAP(CFdmBalloonContent)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

int CFdmBalloonContent::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	
	
	return 0;
}

void CFdmBalloonContent::Create(CWnd *pwndParent)
{
	CRect rc;
	CWnd::Create (AfxRegisterWndClass (0, LoadCursor (NULL, IDC_ARROW), NULL, NULL), NULL,
		WS_CHILD | WS_VISIBLE, rc, pwndParent, 0);
}
