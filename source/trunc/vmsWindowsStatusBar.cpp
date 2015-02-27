/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsWindowsStatusBar.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsWindowsStatusBar::vmsWindowsStatusBar()
{
	m_uBarPrevState = UINT (-1);
}

vmsWindowsStatusBar::~vmsWindowsStatusBar()
{
	RestoreBarStateIfRequired ();
}

void vmsWindowsStatusBar::MakeSureBarIsVisible()
{
	if (m_uBarPrevState != UINT (-1))
		return;

	APPBARDATA abd;
	abd.cbSize = sizeof (abd);
	abd.hWnd = NULL;
	m_uBarPrevState = SHAppBarMessage (ABM_GETSTATE, &abd);
	
	if ((m_uBarPrevState & ABS_AUTOHIDE) || (m_uBarPrevState & ABS_ALWAYSONTOP) == 0)
	{
		abd.lParam = ABS_ALWAYSONTOP;
		SHAppBarMessage (ABM_SETSTATE, &abd);
	}
	else
	{
		m_uBarPrevState = UINT (-1);
	}
}

void vmsWindowsStatusBar::RestoreBarStateIfRequired()
{
	if (m_uBarPrevState == UINT (-1))
		return;

	APPBARDATA abd;
	abd.cbSize = sizeof (abd);
	abd.hWnd = NULL;
	abd.lParam = m_uBarPrevState;
	SHAppBarMessage (ABM_SETSTATE, &abd);

	m_uBarPrevState = UINT (-1);
}

static vmsWindowsStatusBar _oWSB;
vmsWindowsStatusBar& vmsWindowsStatusBar::o()
{
	return ::_oWSB;
}
