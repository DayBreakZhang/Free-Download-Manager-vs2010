/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsUiLinkWindow.h"
#include "vmsUiFonts.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsUiLinkWindow::vmsUiLinkWindow()
{
	m_pfntLnk = NULL;
	m_uDrawTextFormat = 0;
}

vmsUiLinkWindow::~vmsUiLinkWindow()
{

}

void vmsUiLinkWindow::setLink(LPCTSTR ptszText, LPCTSTR ptszUrl, UINT uDrawTextFormat)
{
	m_tstrText = ptszText;
	m_tstrUrl = ptszUrl;
	m_uDrawTextFormat = uDrawTextFormat;
}

CSize vmsUiLinkWindow::getSize() const
{
	CDC *pdc = getDC ();
	if (pdc == NULL)
	{
		return CSize (0,0);
	}

	CFont *pfntOld = pdc->SelectObject (m_pfntLnk ? m_pfntLnk : vmsUiFonts::Tahoma_11underline ());

	CSize s;

	if (m_uDrawTextFormat == 0)
	{
		s = pdc->GetTextExtent (m_tstrText.c_str ());
	}
	else
	{
		CRect rc = m_rcPos;
		pdc->DrawText (m_tstrText.c_str (), &rc, DT_CALCRECT | m_uDrawTextFormat);
		s = CSize (rc.Width (), rc.Height ());
	}

	pdc->SelectObject (pfntOld);
	releaseDC (pdc);

	return s;
}

void vmsUiLinkWindow::Draw(CDC *pdc)
{
	CFont *pfntOld = pdc->SelectObject (m_pfntLnk ? m_pfntLnk : vmsUiFonts::Tahoma_11underline ());
	CRect rc; getAbsolutePos (&rc);
	if (m_tstrUrl.empty () && m_uDrawTextFormat == 0)
	{
		DrawState (pdc->GetSafeHdc (), NULL, NULL, (LPARAM)m_tstrText.c_str (), 0, rc.left, rc.top, 
			rc.Width (), rc.Height (), DST_TEXT | DSS_DISABLED);
	}
	else
	{
		pdc->SetTextColor (_SkinMgr.getLinkTextColor ());
		pdc->DrawText (m_tstrText.c_str (), &rc, m_uDrawTextFormat);

		if (m_uDrawTextFormat)
		{
			pdc->DrawText (m_tstrText.c_str (), &rc, m_uDrawTextFormat);
		}
	}
	pdc->SelectObject (pfntOld);
	pdc->SetTextColor (RGB (0,0,0));
}

void vmsUiLinkWindow::OnMouseMove(CPoint pt)
{
	if (m_tstrUrl.empty ())
		return;

	static HCURSOR _hCur = NULL;
	if (!_hCur)
		_hCur = LoadCursor (AfxGetResourceHandle (), MAKEINTRESOURCE (IDC_HAND_));

	SetCursor (_hCur);
}

void vmsUiLinkWindow::OnLButtonDown(CPoint pt)
{
	USES_CONVERSION;

	if (m_tstrUrl.empty ())
		return;

	extern void fsOpenUrlInBrowser (LPCTSTR pszUrl);

	if (_istdigit (m_tstrUrl [0]))
		m_pwndHoster->PostMessage (WM_COMMAND, _ttoi (m_tstrUrl.c_str ()));
	else if (_tcsnicmp (m_tstrUrl.c_str (), _T ("mailto:"), 7))
		fsOpenUrlInBrowser (m_tstrUrl.c_str ());
	else
		ShellExecute (::GetDesktopWindow (), _T ("open"), m_tstrUrl.c_str (), NULL, NULL, SW_SHOW);
}

void vmsUiLinkWindow::setLinkTextFont(CFont *pfnt)
{
	m_pfntLnk = pfnt;
}
