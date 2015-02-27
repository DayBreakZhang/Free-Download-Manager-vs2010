/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "PlugToolBar.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

fsPluginMgr _PluginMgr;

CPlugToolBar::CPlugToolBar()
{
	m_clrBk = RGB (170, 170, 170);
	m_clrText = RGB (255, 255, 255);

	m_font.CreateFont (15, 0, 0, 0, FW_NORMAL, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, "MS Sans Serif");

	m_iMayBeSelected = m_iPressed = -1;
	m_iActivePlugin = -1;
}

CPlugToolBar::~CPlugToolBar()
{
	_App.ActivePlugin (m_iActivePlugin);
}

BEGIN_MESSAGE_MAP(CPlugToolBar, CListBox)
	//{{AFX_MSG_MAP(CPlugToolBar)
	ON_WM_MEASUREITEM_REFLECT()
	ON_WM_DRAWITEM_REFLECT()
	ON_WM_MOUSEMOVE()
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_CAPTURECHANGED()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CPlugToolBar::Create(CWnd *pParent)
{
	CRect rc (0, 0, 100, 50);

	if (FALSE == CListBox::Create (LBS_OWNERDRAWFIXED | LBS_HASSTRINGS | 
		  LBS_NOINTEGRALHEIGHT | WS_CHILD | WS_VSCROLL | WS_HSCROLL, rc, pParent, 0x123))
		return FALSE;

	

	

	if (FALSE == Initialize ())
	{
		DestroyWindow ();
		return FALSE;
	}

	ShowWindow (SW_SHOW);

	return TRUE;
}

BOOL CPlugToolBar::Initialize()
{
	m_pMainFrame = (CMainFrame*) AfxGetApp ()->m_pMainWnd;

	
	if (FALSE == _PluginMgr.LoadPlugins (m_pPlugFrame))
		return FALSE;

	int cMenuImages;

	for (int i = 0; i < _PluginMgr.GetPluginCount (); i++)
	{
		fsPluginInfo &plug = _PluginMgr.Plugin (i);
		AddString (plug.strName);
		::ShowWindow (plug.hWnd, SW_HIDE);
		
		if (plug.pbmpMenuImages)
		{
			
			cMenuImages = m_pMainFrame->m_imgsTool.GetImageCount ();
			m_pMainFrame->m_imgsTool.Add (plug.pbmpMenuImages, RGB (255, 0, 255));
			m_pMainFrame->m_dimgsTool.Add (plug.pbmpMenuDImages, RGB (255, 0, 255));
			delete plug.pbmpMenuImages;
			delete plug.pbmpMenuDImages;
			plug.pbmpMenuImages = plug.pbmpMenuDImages = NULL;
			
			

			for (int j = 0; j < plug.cMenuMainImages; j++)
			{
				plug.pMenuMainImages [j].iCheckImage += cMenuImages;
				plug.pMenuMainImages [j].iImage += cMenuImages;
			}

			for (j = 0; j < plug.cMenuViewImages; j++)
			{
				plug.pMenuViewImages [j].iCheckImage += cMenuImages;
				plug.pMenuViewImages [j].iImage += cMenuImages;
			}
		}
	}

	int iPlug = _App.ActivePlugin ();
	if (iPlug >= _PluginMgr.GetPluginCount () || iPlug < 0)
		iPlug = 0;

	SetActivePlugin (iPlug);

	return TRUE;
}

void CPlugToolBar::MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct) 
{
	lpMeasureItemStruct->itemHeight = 32 + 15 + 15;
	lpMeasureItemStruct->itemWidth  = 100;
}

void CPlugToolBar::DrawItem(LPDRAWITEMSTRUCT lpDraw) 
{
	
	
	CDC *pDC = CDC::FromHandle (lpDraw->hDC);
	CString strItem;

	Erase (pDC, lpDraw->rcItem);

	GetText (lpDraw->itemID, strItem);

	CPoint pt (lpDraw->rcItem.left + (lpDraw->rcItem.right - lpDraw->rcItem.left) / 2 - 32/2, lpDraw->rcItem.top + 5);

	
	if (m_iPressed == (int)lpDraw->itemID)
		DrawPressed (pDC, pt);
	else if (m_iMayBeSelected == (int)lpDraw->itemID)	
		DrawMayBeSelected (pDC, pt);

	lpDraw->rcItem.top += 32+6+3;
	SetBkMode (lpDraw->hDC, TRANSPARENT);
	if (lpDraw->itemID == (UINT) m_iActivePlugin)
		pDC->SetTextColor (RGB (255, 255, 255));
	else
		SetTextColor (lpDraw->hDC, RGB (235, 235, 235));

	HGDIOBJ oldFont = SelectObject (lpDraw->hDC, m_font.m_hObject);

	
	DrawText (lpDraw->hDC, strItem, strItem.GetLength (), &lpDraw->rcItem, DT_TOP | DT_CENTER);

	SelectObject (lpDraw->hDC, oldFont);

	if (m_iPressed == (int)lpDraw->itemID)
	{
		pt.x++;
		pt.y++;
	}

	
	_PluginMgr.GetImages ()->Draw (pDC, lpDraw->itemID, pt, ILD_TRANSPARENT);
}

void CPlugToolBar::OnMouseMove(UINT nFlags, CPoint point) 
{
	BOOL bOutside;	
	int i;

	i = ItemFromPoint (point, bOutside);

	if (bOutside)
	{
		if (m_iMayBeSelected != -1)
		{
			InvalidateItem (m_iMayBeSelected);
			ReleaseCapture ();
		}

		m_iMayBeSelected = m_iPressed = -1;
		return;
	}

	CRect rcItem;
	GetItemRect (i, &rcItem);
	CPoint pt (rcItem.left + (rcItem.right - rcItem.left) / 2 - 32/2, rcItem.top + 5);
	
	
	rcItem.left = pt.x;
	rcItem.top  = pt.y;
	rcItem.right = pt.x + 32;
	rcItem.bottom = pt.y + 32;

	
	if (!PtInRect (&rcItem, point))
	{
		if (m_iMayBeSelected != -1)
		{
			InvalidateItem (m_iMayBeSelected);
			ReleaseCapture ();
		}

		m_iMayBeSelected = m_iPressed = -1;
		return;
	}

	if (m_iMayBeSelected == i)
		return;
	else if (m_iMayBeSelected != -1)
	{
		InvalidateItem (m_iMayBeSelected);
		ReleaseCapture ();
	}

	m_iMayBeSelected = i;
	m_iPressed = -1;

	InvalidateItem (i);

	SetCapture ();

	CListBox::OnMouseMove(nFlags, point);
}

BOOL CPlugToolBar::OnEraseBkgnd(CDC* pDC) 
{
	CRect rc;
	GetClientRect (&rc);

	Erase (pDC, rc);

	return TRUE;
}

void CPlugToolBar::Erase(CDC *pDC, RECT &rc)
{
	CBrush br (m_clrBk);
	CPen pen (PS_NULL, 1, RGB (0,0,0));

	CBrush *oldBr = pDC->SelectObject (&br);
	CPen *oldPen  = pDC->SelectObject (&pen); 

	pDC->Rectangle (&rc);

	pDC->SelectObject (oldBr);
	pDC->SelectObject (oldPen);
}

void CPlugToolBar::DrawMayBeSelected(CDC *pDC, CPoint pt)
{
	CPen penLight (PS_SOLID, 1, GetSysColor (COLOR_3DLIGHT));
	CPen penShadow (PS_SOLID, 1, GetSysColor (COLOR_3DDKSHADOW));

	CPen *oldPen = pDC->SelectObject (&penLight);
	pDC->MoveTo (pt.x + 32 + 3, pt.y - 3);
	pDC->LineTo (pt.x - 3, pt.y - 3);
	pDC->LineTo (pt.x - 3, pt.y + 32 + 3);

	pDC->SelectObject (&penShadow);
	pDC->MoveTo (pt.x + 32 + 3, pt.y - 3);
	pDC->LineTo (pt.x + 32 + 3, pt.y + 32 + 3);
	pDC->LineTo (pt.x - 3, pt.y + 32 + 3);

	pDC->SelectObject (oldPen);
}

void CPlugToolBar::InvalidateItem(int , BOOL bErase)
{
	CRect rcItem;
	GetItemRect (m_iMayBeSelected, &rcItem);
	InvalidateRect (&rcItem, bErase);
}

void CPlugToolBar::OnLButtonUp(UINT , CPoint ) 
{
	if (m_iPressed != -1)
	{
		int i = m_iPressed;
		m_iPressed = -1;
		InvalidateItem (i);
		OnClickItem (i);
	}
}

void CPlugToolBar::OnLButtonDown(UINT , CPoint ) 
{
	if (m_iMayBeSelected != -1)
	{
		m_iPressed = m_iMayBeSelected;
		InvalidateItem (m_iPressed);
	}
}

void CPlugToolBar::DrawPressed(CDC *pDC, CPoint pt)
{
	CPen penLight (PS_SOLID, 1, GetSysColor (COLOR_3DLIGHT));
	CPen penShadow (PS_SOLID, 1, GetSysColor (COLOR_3DDKSHADOW));

	CPen *oldPen = pDC->SelectObject (&penShadow);
	pDC->MoveTo (pt.x + 32 + 3, pt.y - 3);
	pDC->LineTo (pt.x - 3, pt.y - 3);
	pDC->LineTo (pt.x - 3, pt.y + 32 + 3);

	pDC->SelectObject (&penLight);
	pDC->MoveTo (pt.x + 32 + 3, pt.y - 3);
	pDC->LineTo (pt.x + 32 + 3, pt.y + 32 + 3);
	pDC->LineTo (pt.x - 3, pt.y + 32 + 3);

	pDC->SelectObject (oldPen);
}

void CPlugToolBar::OnCaptureChanged(CWnd *pWnd) 
{
	int i = m_iMayBeSelected;

	m_iPressed = m_iMayBeSelected = -1;

	if (i != -1)
		InvalidateItem (i);
	
	CListBox::OnCaptureChanged(pWnd);
}

void CPlugToolBar::OnClickItem(int iItem)
{
	SetActivePlugin (iItem);
}

void CPlugToolBar::SetActivePlugin(int iPlugin)
{
	if (m_iActivePlugin == iPlugin)
		return;

	if (m_iActivePlugin != -1)
	{
		
		

		::ShowWindow (_PluginMgr.Plugin (m_iActivePlugin).hWnd, SW_HIDE);
		m_pMainFrame->RemovePluginMenu ();
		m_pMainFrame->RemovePluginMenuView ();
		_TBMgr.HideGroup (m_iActivePlugin + 1);
	}

	int iOld = m_iActivePlugin;
	m_iActivePlugin = iPlugin;
	
	CRect rc;
	
	GetItemRect (iOld, &rc);
	InvalidateRect (&rc, FALSE);
	GetItemRect (iPlugin, &rc);
	InvalidateRect (&rc, FALSE);

	fsPluginInfo &plug = _PluginMgr.Plugin (iPlugin);
	m_pMainFrame->AddPluginMenu (plug.hMenuMain, plug.pMenuMainImages, plug.cMenuMainImages);
	m_pMainFrame->AddPluginMenuView (plug.hMenuView, plug.pMenuViewImages, plug.cMenuViewImages, plug.pMenuViewItems, plug.cMenuViewItems);
	m_pPlugFrame->SetPluginWindow (plug.hWnd);
	m_pPlugFrame->SetFrameName (plug.strLongName);
	::ShowWindow (plug.hWnd, SW_SHOW);
	::SetFocus (plug.hWnd);
	_TBMgr.ShowGroup (m_iActivePlugin + 1, 6);

	_PluginMgr.OnSetActivePlugin (iPlugin);
}

void CPlugToolBar::SendPluginCommand(UINT uCmd)
{
	::SendMessage (_PluginMgr.Plugin (m_iActivePlugin).hWnd, WM_COMMAND, uCmd, 0);
}

int CPlugToolBar::GetActivePlugin()
{
	return m_iActivePlugin;
}

void CPlugToolBar::OnNewLng()
{
	ResetContent ();

	for (int i = 0; i < _PluginMgr.GetPluginCount (); i++)
	{
		fsPluginInfo *plug = &_PluginMgr.Plugin (i);
		AddString (plug->strName);
		if (i == m_iActivePlugin)
		{
			m_pPlugFrame->SetFrameName (plug->strLongName);
			m_pMainFrame->AddPluginMenu (plug->hMenuMain, plug->pMenuMainImages, plug->cMenuMainImages);
			m_pMainFrame->AddPluginMenuView (plug->hMenuView, plug->pMenuViewImages, plug->cMenuViewImages, plug->pMenuViewItems, plug->cMenuViewItems);
		}
	}
}
