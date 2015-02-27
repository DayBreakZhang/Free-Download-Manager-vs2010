/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fdm.h"
#include "Dlg_Options_Downloads_Network.h"
#include "vmsDialogHelper.h"
#include "DlgSpecifyNetworkSpeedValue.h"
#include "DlgConnectionSpeedInfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlg_Options_Downloads_Network::CDlg_Options_Downloads_Network(CWnd* pParent )
	: CDlg_Options_Page(CDlg_Options_Downloads_Network::IDD, pParent),
	m_uConnectionSpeedChoosenValue (UINT64_MAX)
{
	//{{AFX_DATA_INIT(CDlg_Options_Downloads_Network)
		
	//}}AFX_DATA_INIT
}

void CDlg_Options_Downloads_Network::DoDataExchange(CDataExchange* pDX)
{
	CDlg_Options_Page::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_Options_Downloads_Network)
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_CONNECTIONSPEED, m_wndConnectionSpeed);
}

BEGIN_MESSAGE_MAP(CDlg_Options_Downloads_Network, CDlg_Options_Page)
	//{{AFX_MSG_MAP(CDlg_Options_Downloads_Network)
	ON_BN_CLICKED(IDC_DETECTACTIVITY, OnDetectactivity)
	//}}AFX_MSG_MAP
	ON_CBN_SELCHANGE(IDC_CONNECTIONSPEED, &CDlg_Options_Downloads_Network::OnSelchangeConnectionspeed)
	ON_BN_CLICKED(IDC_CONNECTIONSPEEDINFO, &CDlg_Options_Downloads_Network::OnBnClickedConnectionspeedinfo)
END_MESSAGE_MAP()

BOOL CDlg_Options_Downloads_Network::OnInitDialog() 
{
	CDlg_Options_Page::OnInitDialog();

	_App.GetConnectionBandwidthValues (true, m_vConnectionSpeeds);
	FillConnectionSpeedCombo ();

	m_dlgTumSettingsPerDirection.ReadSettingsFromTumMgr (true);
	m_dlgTumSettingsPerDirection.Create (IDD_TUM_SETTINGS_PERDIRECTION, this);
	CRect rc;
	GetDlgItem (IDC__TUMPERDIRSETTINGS_PLACE)->GetWindowRect (&rc);
	ScreenToClient (&rc);
	m_dlgTumSettingsPerDirection.MoveWindow (&rc);
	m_dlgTumSettingsPerDirection.ShowWindow (SW_SHOW);
		
	if (_TumMgr.GetTUMManage () == TM_OFF)
	{
		CheckRadioButton (IDC_DECBYLEVEL, IDC_SETTOLIGHT, IDC_DECBYLEVEL);
	}
	else
	{
		CheckDlgButton (IDC_DETECTACTIVITY, BST_CHECKED);
		if (_TumMgr.GetTUMManage () == TM_DECREASEBYONELEVEL)
			CheckRadioButton (IDC_DECBYLEVEL, IDC_SETTOLIGHT, IDC_DECBYLEVEL);
		else
			CheckRadioButton (IDC_DECBYLEVEL, IDC_SETTOLIGHT, IDC_SETTOLIGHT);
	}

	GetDlgItem (IDC_CONNECTIONSPEEDINFO)->EnableWindow (m_wndConnectionSpeed.GetCurSel () == (int)m_vConnectionSpeeds.size ());
	
	UpdateEnabled ();
	
	ApplyLanguage ();
	
	return TRUE;  
	              
}

void CDlg_Options_Downloads_Network::FillConnectionSpeedCombo ()
{
	m_wndConnectionSpeed.ResetContent ();

	UINT64 uCurrentValue = m_uConnectionSpeedChoosenValue == UINT64_MAX ? _TumMgr.getConnectionBandwidthSpecifiedByUser (true) : m_uConnectionSpeedChoosenValue;
	int iSelection = -1;

	for (size_t i = 0; i < m_vConnectionSpeeds.size (); i++)
	{
		UINT64 uVal = m_vConnectionSpeeds [i];
		m_wndConnectionSpeed.AddString (BytesToString (uVal) + _T ("/") + LS (L_S));
		if (uVal == uCurrentValue)
			iSelection = (int)i;
	}
	
	m_wndConnectionSpeed.AddString (LS (L_DETERMINE_AUTOMATICALLY));
	m_wndConnectionSpeed.AddString (LS (L_CHOOSE__GOESDLG));
	m_wndConnectionSpeed.SetCurSel (iSelection != -1 ? iSelection : m_vConnectionSpeeds.size ());
}

CString CDlg_Options_Downloads_Network::get_PageTitle()
{
	return LS (L_NETWORK);
}

CString CDlg_Options_Downloads_Network::get_PageShortTitle()
{
	return LS (L_NETWORK);
}

BOOL CDlg_Options_Downloads_Network::Apply()
{
	UINT64 uConnectionSpeed = UINT64_MAX;
	if (m_wndConnectionSpeed.GetCurSel () < (int)m_vConnectionSpeeds.size ())
	{
		uConnectionSpeed = m_vConnectionSpeeds [m_wndConnectionSpeed.GetCurSel ()];
		if (uConnectionSpeed == m_uConnectionSpeedChoosenValue)
		{
			std::vector <UINT64> v;
			_App.GetConnectionBandwidthValues (true, v);
			InsertValueIntoSortedList (v, uConnectionSpeed);
			_App.SetConnectionBandwidthValues (true, v);
		}
	}

	if (!m_dlgTumSettingsPerDirection.SerializeSettings (true))
		return FALSE;

	m_dlgTumSettingsPerDirection.SaveSettingsToTumMgr (true);

	_TumMgr.setConnectionBandwidthSpecifiedByUser (true, uConnectionSpeed);
	
	
	if (IsDlgButtonChecked (IDC_DETECTACTIVITY) == BST_CHECKED)
	{
		if (IsDlgButtonChecked (IDC_DECBYLEVEL) == BST_CHECKED)
			_TumMgr.SetTUMManage (TM_DECREASEBYONELEVEL);
		else
			_TumMgr.SetTUMManage (TM_SETTOLIGHT);
	}
	else
		_TumMgr.SetTUMManage (TM_OFF);

	_DldsMgr.setNeedProcessDownloads ();

	return TRUE;
}

void CDlg_Options_Downloads_Network::UpdateEnabled()
{
	BOOL b = IsDlgButtonChecked (IDC_DETECTACTIVITY) == BST_CHECKED;
	GetDlgItem (IDC_DECBYLEVEL)->EnableWindow (b);
	GetDlgItem (IDC_SETTOLIGHT)->EnableWindow (b);
}

void CDlg_Options_Downloads_Network::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__CONNECTIONSPEED, L_CONNECTION_SPEED, TRUE),
		fsDlgLngInfo (IDC_DETECTACTIVITY, L_DETECTACTIVITY),
		fsDlgLngInfo (IDC_DECBYLEVEL, L_DECBYLEVEL),
		fsDlgLngInfo (IDC_SETTOLIGHT, L_SETTOLIGHT),
		fsDlgLngInfo (IDC__TUMSETTINGS, L_STGS_FOR_TUMS, TRUE),
	};
	
	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}

void CDlg_Options_Downloads_Network::OnDetectactivity() 
{
	UpdateEnabled ();	
}

void CDlg_Options_Downloads_Network::InsertValueIntoSortedList (std::vector <UINT64> &vValues, UINT64 uValue)
{
	for (size_t i = 0; i < vValues.size (); i++)
	{
		if (vValues [i] == uValue)
			return;
	}
	if (vValues.size () > 20)
		vValues.erase (vValues.end ()-1);
	for (size_t i = 0; i < vValues.size (); i++)
	{
		if (vValues [i] > uValue)
		{
			vValues.insert (vValues.begin () + i, uValue);
			return;
		}
	}
	vValues.push_back (uValue);
}

void CDlg_Options_Downloads_Network::OnSelchangeConnectionspeed()
{
	if (m_wndConnectionSpeed.GetCurSel () == (int)m_vConnectionSpeeds.size () + 1)
	{
		CDlgSpecifyNetworkSpeedValue dlg;
		dlg.m_uValue = m_uConnectionSpeedChoosenValue;
		if (dlg.DoModal () == IDOK && dlg.m_uValue)
		{
			if (dlg.m_uValue > 300*1024*1024*1024ui64)
			{
				MessageBox (_T ("Entered value is too big."), LS (L_INPERR), MB_ICONEXCLAMATION);
			}
			else
			{
				m_uConnectionSpeedChoosenValue = dlg.m_uValue;
				InsertValueIntoSortedList (m_vConnectionSpeeds, m_uConnectionSpeedChoosenValue);
			}
		}
		FillConnectionSpeedCombo ();
	}
}

void CDlg_Options_Downloads_Network::OnBnClickedConnectionspeedinfo()
{
	CDlgConnectionSpeedInfo dlg;
	_DlgMgr.DoModal (&dlg);
}
