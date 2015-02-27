/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsUiWindow.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsUiWindow::vmsUiWindow()
{
	m_pParentWindow = NULL;
	m_rcPos.SetRectEmpty ();
	m_bVisible = true;
	m_bEnabled = true;
	m_pwndHoster = NULL;
	m_pChildWindowUnderMouse = NULL;
	m_nId = 0;
}

vmsUiWindow::~vmsUiWindow()
{

}

void vmsUiWindow::Draw(CDC *pdc)
{
	if (!isWindowVisible ())
		return;
	for (int i = 0; i < m_vChildWindows.size (); i++)
	{
		vmsUiWindow *p = m_vChildWindows [i];
		if (p->isVisible ())
			p->Draw (pdc);
	}
}

void vmsUiWindow::setPos(int x, int y, int cx, int cy)
{
	m_rcPos = CRect (x, y, x+cx, y+cy);
}

void vmsUiWindow::addChildWindow(vmsUiWindow *pwnd)
{
	pwnd->setParentWindow (this);
	pwnd->m_pwndHoster = m_pwndHoster;
	m_vChildWindows.push_back (pwnd);
}

const CRect* vmsUiWindow::getPos() const
{
	return &m_rcPos;
}

void vmsUiWindow::getAbsolutePos(CRect *prc) const
{
	if (m_pParentWindow)
	{
		m_pParentWindow->getAbsolutePos (prc);
		prc->left  += m_rcPos.left;
		prc->top   += m_rcPos.top;
		prc->right  = prc->left + m_rcPos.Width ();
		prc->bottom = prc->top + m_rcPos.Height ();
	}
	else
	{
		*prc = m_rcPos;
	}
}

void vmsUiWindow::setParentWindow(vmsUiWindow *pWindow)
{
	m_pParentWindow = pWindow;
}

CDC* vmsUiWindow::getDC() const
{
	if (m_pwndHoster)
		return m_pwndHoster->GetDC ();
	return m_pParentWindow ? m_pParentWindow->getDC () : NULL;
}

void vmsUiWindow::releaseDC(CDC *pdc) const
{
	if (m_pwndHoster)
		m_pwndHoster->ReleaseDC (pdc);
	else if (m_pParentWindow)
		m_pParentWindow->releaseDC (pdc);
}

void vmsUiWindow::OnLButtonDown(CPoint pt)
{
	if (!isWindowVisible () || !m_bEnabled)
		return;
	vmsUiWindow *pChildWindow = FindChildWindow (pt);
	if (pChildWindow)
	{
		pt.x -= pChildWindow->getPos ()->left;
		pt.y -= pChildWindow->getPos ()->top;
		pChildWindow->OnLButtonDown (pt);
	}
}

vmsUiWindow* vmsUiWindow::FindChildWindow(CPoint pt, bool bIgnoreInvisibleAndDisabledWindows)
{
	for (int i = 0; i < m_vChildWindows.size (); i++)
	{
		if ((bIgnoreInvisibleAndDisabledWindows == false || 
					(m_vChildWindows [i]->isVisible () && m_vChildWindows [i]->isEnabled ())) && 
				PtInRect (m_vChildWindows [i]->getPos (), pt))
			return m_vChildWindows [i];
	}
	return NULL;
}

void vmsUiWindow::setVisible(bool bVisible, bool bRedraw)
{
	if (m_bVisible == bVisible)
		return;

	m_bVisible = bVisible;
	if (bVisible == false && m_pChildWindowUnderMouse)
	{
		m_pChildWindowUnderMouse->OnMouseLeave ();
		m_pChildWindowUnderMouse = NULL;
	}

	if (bRedraw)
	{
		if (bVisible)
			Redraw ();
		else if (m_pParentWindow)
			m_pParentWindow->Redraw ();
	}
}

bool vmsUiWindow::isVisible() const
{
	return m_bVisible;
}

void vmsUiWindow::Redraw(bool bInvalidateBg)
{
	if (!isWindowVisible ())
		return;
	if (bInvalidateBg)
	{
		CWnd *pwnd = getHosterWindow ();
		if (pwnd)
		{
			CRect rc; getAbsolutePos (&rc);
			pwnd->InvalidateRect (&rc, FALSE);
			return;
		}
	}
	CDC *pdc = getDC ();
	if (pdc)
	{
		Draw (pdc);
		releaseDC (pdc);
	}
}

void vmsUiWindow::setHosterWindow(CWnd *pwndHoster)
{
	m_pwndHoster = pwndHoster;
	for (int i = 0; i < m_vChildWindows.size (); i++)
		m_vChildWindows [i]->setHosterWindow (pwndHoster);
}

void vmsUiWindow::OnLButtonUp(CPoint pt)
{
	if (!isWindowVisible () || !m_bEnabled)
		return;
	vmsUiWindow *pChildWindow = FindChildWindow (pt);
	if (pChildWindow)
	{
		pt.x -= pChildWindow->getPos ()->left;
		pt.y -= pChildWindow->getPos ()->top;
		pChildWindow->OnLButtonUp (pt);
	}
}

void vmsUiWindow::OnMouseMove(CPoint pt)
{
	if (!isWindowVisible () || !m_bEnabled)
		return;

	vmsUiWindow *pChildWindow = FindChildWindow (pt);
	
	if (m_pChildWindowUnderMouse != pChildWindow)
	{
		if (m_pChildWindowUnderMouse)
			m_pChildWindowUnderMouse->OnMouseLeave ();
		m_pChildWindowUnderMouse = pChildWindow;
		if (m_pChildWindowUnderMouse)
			m_pChildWindowUnderMouse->OnMouseEnter ();
	}

	if (pChildWindow)
	{
		pt.x -= pChildWindow->getPos ()->left;
		pt.y -= pChildWindow->getPos ()->top;
		pChildWindow->OnMouseMove (pt);
	}
}

void vmsUiWindow::OnMouseEnter()
{

}

void vmsUiWindow::OnMouseLeave()
{
	if (m_pChildWindowUnderMouse)
	{
		m_pChildWindowUnderMouse->OnMouseLeave ();
		m_pChildWindowUnderMouse = NULL;
	}
}

void vmsUiWindow::OnKillHosterWindowFocus()
{
	if (m_pChildWindowUnderMouse)
		OnMouseLeave ();
}

void vmsUiWindow::OnIdle()
{
	ASSERT (m_pwndHoster != NULL);
	if (m_pChildWindowUnderMouse)
		m_pChildWindowUnderMouse->OnIdle ();
}

void vmsUiWindow::OnHosterWindowEnterIdle()
{
	if (m_pChildWindowUnderMouse)
		m_pChildWindowUnderMouse->OnMouseLeave ();
}

void vmsUiWindow::setEnable(bool bEnable)
{
	if (m_bEnabled == bEnable)
		return;

	m_bEnabled = bEnable;

	if (!bEnable)
	{
		if (m_pChildWindowUnderMouse)
			m_pChildWindowUnderMouse->OnMouseLeave ();
	}

	Redraw ();
}

bool vmsUiWindow::isEnabled() const
{
	return m_bEnabled;
}

bool vmsUiWindow::OnRButtonDown(POINT pt)
{
	if (!isWindowVisible () || !m_bEnabled)
		return false;
	vmsUiWindow *pChildWindow = FindChildWindow (pt);
	if (pChildWindow)
	{
		pt.x -= pChildWindow->getPos ()->left;
		pt.y -= pChildWindow->getPos ()->top;
		pChildWindow->OnRButtonDown (pt);
		return true;
	}
	return false;
}

bool vmsUiWindow::isWindowVisible() const
{
	if (!m_bVisible)
		return false;
	if (m_pParentWindow)
		return m_pParentWindow->isWindowVisible ();
	return true;
}

CWnd* vmsUiWindow::getHosterWindow() const
{
	if (m_pwndHoster)
		return m_pwndHoster;
	if (m_pParentWindow)
		return m_pParentWindow->getHosterWindow ();
	return NULL;
}

void vmsUiWindow::RemoveAllChildWindows()
{
	m_pChildWindowUnderMouse = NULL;
	m_vChildWindows.clear ();
}

void vmsUiWindow::setId(UINT nId)
{
	m_nId = nId;
}
