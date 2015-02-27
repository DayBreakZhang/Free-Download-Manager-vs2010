/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "PlugToolBarContainer.h"
#include "misc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CPlugToolBarContainer::CPlugToolBarContainer()
{
}

CPlugToolBarContainer::~CPlugToolBarContainer()
{
}

BEGIN_MESSAGE_MAP(CPlugToolBarContainer, CWnd)
	//{{AFX_MSG_MAP(CPlugToolBarContainer)
	ON_WM_SIZE()
	ON_WM_CREATE()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CPlugToolBarContainer::Create(CWnd *pParent)
{
	CRect rc (0, 0, 100, 50);

	return CWnd::Create (AfxRegisterWndClass (0, NULL, (HBRUSH) (COLOR_3DFACE+1), NULL), NULL, WS_CHILD | WS_VISIBLE, rc, pParent, 0x111);
}

void CPlugToolBarContainer::OnSize(UINT , int cx, int cy) 
{
	if (cx && cy)
	{
		m_plugToolBar.MoveWindow (0, 1, cx+1, cy-1, FALSE);	
		m_plugToolBar.Invalidate (FALSE); 
	}
}

int CPlugToolBarContainer::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (FALSE == m_plugToolBar.Create (this))
		return -1;
	
	return 0;
}

void CPlugToolBarContainer::OnPaint() 
{
	CPaintDC dc(this); 
	
	CRect rc;
	GetClientRect (&rc);

	CPen pen (PS_SOLID, 1, GetSysColor (COLOR_3DSHADOW)), *oldPen;

	oldPen = dc.SelectObject (&pen);

	
	dc.MoveTo (0, 0);
	dc.LineTo (rc.right, 0);

	dc.SelectObject (oldPen);
}

void CPlugToolBarContainer::SetPlugsFrame(CPlugFrame *pFrame)
{
	m_plugToolBar.m_pPlugFrame = pFrame;
}
