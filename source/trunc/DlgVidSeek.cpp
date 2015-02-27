/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "DlgVidSeek.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlgVidSeek::CDlgVidSeek(CWnd* pParent )
	: CDialog(CDlgVidSeek::IDD, pParent)
{
	m_hWndDuration = NULL;
	m_seek = NULL;
}

void CDlgVidSeek::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgVidSeek)
	DDX_Control(pDX, IDC_SEEK, m_wndSeek);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgVidSeek, CDialog)
	//{{AFX_MSG_MAP(CDlgVidSeek)
	ON_WM_CTLCOLOR()
	ON_WM_SIZE()
	ON_WM_TIMER()
	ON_WM_HSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

HBRUSH CDlgVidSeek::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = m_brClrWindow;
	pDC->SetBkMode (TRANSPARENT);
	return hbr;
}

void CDlgVidSeek::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	if (cx && cy && IsWindow (m_wndSeek))
		m_wndSeek.MoveWindow (0, 0, cx, cy);	
}

BOOL CDlgVidSeek::OnInitDialog() 
{
	CDialog::OnInitDialog();

	m_brClrWindow.CreateSolidBrush (GetSysColor (COLOR_WINDOW));

	m_seek = NULL;
	m_wndSeek.EnableWindow (FALSE);
	
	return TRUE;
}

void CDlgVidSeek::OnTimer(UINT nIDEvent) 
{
	LONGLONG cur, stop;

	if (m_seek == NULL)
		return;

	

	if (m_hWndDuration)
		::SetWindowText (m_hWndDuration, GetDuration ());

	m_seek->GetPositions (&cur, &stop);

	double pos = (double) cur / m_llDuration;
	if (m_llDuration > 1000)	
		pos *= 1000.0;
	else
		pos *= m_llDuration;

	m_wndSeek.SetPos (int (pos));
	
	CDialog::OnTimer(nIDEvent);
}

void CDlgVidSeek::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	static BOOL bStartScroll = TRUE;

	if (bStartScroll)
	{
		bStartScroll = FALSE;
		KillTimer (1);
	}

        ASSERT (m_seek != NULL);
        if (m_seek == NULL)
		return;

	if (nSBCode == SB_ENDSCROLL)
	{
		double pos = m_wndSeek.GetPos ();
		if (m_llDuration < 1000 && m_llDuration != 0)	
			pos /= m_llDuration;
		else
			pos /= 1000.0;

		LONGLONG cur, stop;
		m_seek->GetPositions (&cur, &stop);

		cur = (LONGLONG) (m_llDuration * pos);

		m_seek->SetPositions (&cur, AM_SEEKING_AbsolutePositioning, 
			&stop, AM_SEEKING_AbsolutePositioning);

		SetTimer (1, 1000, NULL);
		bStartScroll = TRUE;
	}
	
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CDlgVidSeek::Set_MediaSeeking(IMediaSeeking *seek)
{
	if (m_seek)
	{
		KillTimer (1);
		m_wndSeek.SetPos (0);
		m_seek->Release ();
	}

	m_seek = seek;

	if (m_seek)
	{
		if (FAILED (seek->GetDuration (&m_llDuration)))
			m_seek = NULL;
		else
		{
			m_wndSeek.SetRange (0, m_llDuration > 1000 ? 1000 : (int)m_llDuration);
			SetTimer (1, 1000, NULL);
			m_seek->AddRef ();
		}
	}
	
	m_wndSeek.EnableWindow (m_seek != NULL);
}

CString CDlgVidSeek::GetDuration()
{
	if (m_seek == NULL)
		return "00:00/00:00";

	LONGLONG cur, stop;

	m_seek->GetPositions (&cur, &stop);

	
	ULONG nTotalMS = (ULONG) (cur / 10000); 
	int nSeconds = nTotalMS / 1000;
	
	nSeconds %= 60;

	CString str1, str2;
	BOOL bH = FALSE;

	str2 = DurationToString (m_llDuration, &bH);
	str1 = DurationToString (cur, &bH);

	CString strDuration;
	strDuration.Format ("%s/%s", str1, str2);

	return strDuration;
}

CString CDlgVidSeek::DurationToString(LONGLONG llDur, BOOL* pbNeedHours)
{
	
	ULONG nTotalMS = (ULONG) (llDur / 10000); 
	int nSeconds = nTotalMS / 1000;
	int nMinutes = nSeconds / 60;
	int nHours = nMinutes / 60;
	nSeconds %= 60;
	nMinutes %= 60;

	CString strDur;

	BOOL bH = pbNeedHours ? *pbNeedHours : FALSE;

	if (nHours == 0 && bH == FALSE)
		strDur.Format ("%02d:%02d", nMinutes, nSeconds);
	else
	{
		strDur.Format ("%02d:%02d:%02d", nHours, nMinutes, nSeconds);
		bH = TRUE;
	}

	if (pbNeedHours)
		*pbNeedHours = bH;

	return strDur;
}

