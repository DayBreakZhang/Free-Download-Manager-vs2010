/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "AppStatusBar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CAppStatusBar::CAppStatusBar()
{
}

CAppStatusBar::~CAppStatusBar()
{
}

BEGIN_MESSAGE_MAP(CAppStatusBar, CStatusBar)
	//{{AFX_MSG_MAP(CAppStatusBar)
	ON_WM_CREATE()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

int CAppStatusBar::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CStatusBar::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	m_ttip.Create (this, TTS_ALWAYSTIP);
	
	
	m_ttip.SendMessage(TTM_SETMAXTIPWIDTH, 0, (UINT)(WORD)-1);

	CRect rc (0, 0, 0, 0);
	m_ttip.AddTool (this, " ", &rc, ID_SB_TRAFFIC_THISMONTH);
	m_ttip.AddTool (this, LS (L_TOTAL_SPEED_SBTEXT), &rc, ID_SB_TOTALSPEED);
	
	return 0;
}

void CAppStatusBar::OnSize(UINT nType, int cx, int cy) 
{
	CStatusBar::OnSize(nType, cx, cy);
	
	CRect rc;
	int i = CommandToIndex (ID_SB_TRAFFIC_THISMONTH);
	GetStatusBarCtrl ().GetRect (i, &rc);
	m_ttip.SetToolRect (this, ID_SB_TRAFFIC_THISMONTH, &rc);

	i = CommandToIndex (ID_SB_TOTALSPEED);
	GetStatusBarCtrl ().GetRect (i, &rc);
	m_ttip.SetToolRect (this, ID_SB_TOTALSPEED, &rc);	
}

void CAppStatusBar::SetToolTipText(UINT nIDTip, LPCSTR pszText)
{
	m_ttip.UpdateTipText (pszText, this, nIDTip);
}

BOOL CAppStatusBar::PreTranslateMessage(MSG *pMsg)
{
	m_ttip.RelayEvent (pMsg);
	return CStatusBar::PreTranslateMessage (pMsg);
}
