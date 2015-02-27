/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "DlgConnectionSpeedInfo.h"

IMPLEMENT_DYNAMIC(CDlgConnectionSpeedInfo, CDialog)

CDlgConnectionSpeedInfo::CDlgConnectionSpeedInfo(CWnd* pParent )
	: CDialog(CDlgConnectionSpeedInfo::IDD, pParent)
{

}

CDlgConnectionSpeedInfo::~CDlgConnectionSpeedInfo()
{
}

void CDlgConnectionSpeedInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDlgConnectionSpeedInfo, CDialog)
	ON_BN_CLICKED(IDC_MEASUREAGAIN, &CDlgConnectionSpeedInfo::OnBnClickedMeasureagain)
	ON_WM_TIMER()
END_MESSAGE_MAP()

void CDlgConnectionSpeedInfo::OnBnClickedMeasureagain()
{
	_TumMgr.ResetAllSpeedsInfo ();
	UpdateStats ();
}

CString getMBitsText (UINT64 uVal)
{
	float f = (double)uVal / 1024 / 1024 * 8;
	CString str;
	str.Format (_T ("%.*g Mbps"), 2, f);
	return str;
}

void CDlgConnectionSpeedInfo::UpdateStats(void)
{
	UINT64 u = _TumMgr.getConnectionBandwidth (true);
	if (u == UINT64_MAX)
	{
		SetDlgItemText (IDC__DOWNSPEEDVAL, LS (L_UNKNOWN));
	}
	else
	{
		CString str = BytesToString (u);
		str += _T ("/");
		str += LS (L_S);
		str += _T (" (");
		str += getMBitsText (u);
		str += _T (")");
		SetDlgItemText (IDC__DOWNSPEEDVAL, str);
	}

	u = _TumMgr.getConnectionBandwidth (false);
	if (u == UINT64_MAX)
	{
		SetDlgItemText (IDC__UPSPEEDVAL, LS (L_UNKNOWN));
	}
	else
	{
		CString str = BytesToString (u);
		str += _T ("/");
		str += LS (L_S);
		SetDlgItemText (IDC__UPSPEEDVAL, str);
	}
}

BOOL CDlgConnectionSpeedInfo::OnInitDialog()
{
	CDialog::OnInitDialog();

	UpdateStats ();
	SetTimer (1, 1000, NULL);

	ApplyLanguage ();
	UpdateEnabled ();

	return TRUE;  
}

void CDlgConnectionSpeedInfo::OnTimer(UINT_PTR nIDEvent)
{
	if (nIDEvent == 1)
	{
		UpdateStats ();
		UpdateEnabled ();
	}

	CDialog::OnTimer(nIDEvent);
}

void CDlgConnectionSpeedInfo::ApplyLanguage(void)
{
	SetWindowText (LS(L_CONNECTION_SPEED));
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__MSG, L_CONNECTIONSPEEDINFO_MSG),
		fsDlgLngInfo (IDC__DOWNLOADSPEED, L_DOWNLOADSPEED),
		fsDlgLngInfo (IDC__UPLOADSPEED, L_UPLOAD_SPEED),
		fsDlgLngInfo (IDC_MEASUREAGAIN, L_MEASURE_AGAIN),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}

void CDlgConnectionSpeedInfo::UpdateEnabled(void)
{
	
	GetDlgItem (IDC_MEASUREAGAIN)->EnableWindow (_TumMgr.getConnectionBandwidth (true) != UINT64_MAX);
}
