/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "ChildView.h"
#include "plugincmds.h"
#include "DownloadsWnd.h"
#include "vmsAppTipsMgr.h"

extern CDownloadsWnd* _pwndDownloads;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define ID_APPLY_SHOWSMALLTIPS_SETTING		200

extern fsPluginMgr _PluginMgr;

IMPLEMENT_DYNAMIC(CChildView, CWnd)

CChildView::CChildView()
{
	m_bShowSmallTip = false;
}

CChildView::~CChildView()
{
}

BEGIN_MESSAGE_MAP(CChildView,CWnd )
	//{{AFX_MSG_MAP(CChildView)
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_CREATE()
	ON_WM_SETFOCUS()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
	ON_COMMAND_RANGE (WGP_MENU_CMDFIRST, WGP_MENU_CMDLAST, OnPluginCommand)
	ON_UPDATE_COMMAND_UI_RANGE (WGP_MENU_CMDFIRST, WGP_MENU_VIEWSMPLITEM_CMDSTART-1, OnUpdatePluginCommand)
	ON_COMMAND(ID_SMALLTIP_CLOSE, OnSmallTipClose)
	ON_COMMAND(ID_SMALLTIP_CHANGED, OnSmallTipChanged)
	ON_COMMAND(ID_APPLY_SHOWSMALLTIPS_SETTING, OnApplyShowSmallTipsSetting)
END_MESSAGE_MAP()

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle = 0; 
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), HBRUSH(COLOR_BTNFACE+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); 
	
	CRect rc;
	GetClientRect (&rc);

	
	
}

void CChildView::OnSize(UINT, int cx, int cy) 
{
	ApplySize (cx, cy);
}

int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CWnd ::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (FALSE == m_wndClient.Create (this))
		return -1;

	ApplyShowSmallTipsSetting ();
	
	return 0;
}

void CChildView::OnPluginCommand(UINT uCmd) 
{
	m_wndClient.m_plugs2.SendPluginCommand (uCmd);
}

void CChildView::OnUpdatePluginCommand(CCmdUI *pCmdUI)
{
	
	int state = _PluginMgr.OnUpdateToolBar (pCmdUI->m_nID);

	pCmdUI->Enable ((state & WGP_CMDITEMSTATE_DISABLED) == 0);
	pCmdUI->SetCheck (state & WGP_CMDITEMSTATE_CHECKED ? 1 : 0);
}

void CChildView::OnSetFocus(CWnd* pOldWnd) 
{
	CWnd ::OnSetFocus(pOldWnd);
	m_wndClient.SetFocus ();	
}

BOOL CChildView::OnEraseBkgnd(CDC* pDC) 
{
	
	
	
	
	if (_pwndDownloads->m_wndDownloads.m_info.m_video.m_wndVideo.m_player.Get_State () != VFPS_CLOSED)
	{
    		CRect rc;

		
		_pwndDownloads->m_wndDownloads.m_info.m_video.GetWindowRect(&rc);
		ScreenToClient(&rc);

		
		pDC->ExcludeClipRect(&rc);
	}
	
	return CWnd ::OnEraseBkgnd(pDC);
}

void CChildView::OnSmallTipClose() 
{
	if (IDYES != MessageBox (LS (L_OKTODISABLETIPS), LS (L_CONFIRMATION), MB_ICONQUESTION | MB_YESNO))
		return;
	_App.SmallTips_Show (FALSE);
	ApplyShowSmallTipsSetting ();	
}

void CChildView::ApplySize(int cx, int cy)
{
	int cyAdd = 0;
	
	if (m_bShowSmallTip)
	{
		CSize s = m_wndSmallTip.getRequiredSize ();
		s.cx = min (s.cx, cx-6-6);
		m_wndSmallTip.MoveWindow (6, 3, s.cx, s.cy);
		cyAdd += s.cy+3;
	}
	
	m_wndClient.MoveWindow (0, 3+cyAdd, cx, cy-(3+cyAdd), TRUE);
}

void CChildView::OnSmallTipChanged() 
{
	CRect rc; GetClientRect (&rc);
	ApplySize (rc.Width (), rc.Height ());
	m_wndSmallTip.Invalidate (FALSE);
}

void CChildView::ApplyShowSmallTipsSetting()
{
	SendMessage (WM_COMMAND, ID_APPLY_SHOWSMALLTIPS_SETTING);
}

void CChildView::OnApplyShowSmallTipsSetting() 
{
	bool bApplySize = false;
	
	if (_App.SmallTips_Show () && vmsAppSmallTipsMgr::o ().getTip ().empty () == false)
	{
		if (m_bShowSmallTip == false)
		{
			m_bShowSmallTip = true;
			m_wndSmallTip.Create (this);
			m_wndSmallTip.ShowWindow (SW_SHOW);
			bApplySize = true;
		}
	}
	else
	{
		if (m_bShowSmallTip)
		{
			m_bShowSmallTip = false;
			m_wndSmallTip.DestroyWindow ();
			bApplySize = true;
		}
	}
	
	if (bApplySize)
	{
		CRect rc; GetClientRect (&rc);
		ApplySize (rc.Width (), rc.Height ());
	}	
}
