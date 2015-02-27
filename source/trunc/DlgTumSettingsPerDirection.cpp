/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "DlgTumSettingsPerDirection.h"

IMPLEMENT_DYNAMIC(CDlgTumSettingsPerDirection, CDialog)

CDlgTumSettingsPerDirection::CDlgTumSettingsPerDirection(CWnd* pParent )
	: CDialog(CDlgTumSettingsPerDirection::IDD, pParent)
{

}

CDlgTumSettingsPerDirection::~CDlgTumSettingsPerDirection()
{
}

void CDlgTumSettingsPerDirection::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MODESTAB, m_tabTrafficModes);
}

BEGIN_MESSAGE_MAP(CDlgTumSettingsPerDirection, CDialog)
	ON_NOTIFY(TCN_SELCHANGE, IDC_MODESTAB, &CDlgTumSettingsPerDirection::OnSelchangeModestab)
	ON_NOTIFY(TCN_SELCHANGING, IDC_MODESTAB, &CDlgTumSettingsPerDirection::OnSelchangingModestab)
	ON_COMMAND(IDC_MNC_MANAGEAUTO, &CDlgTumSettingsPerDirection::OnMncManageauto)
	ON_COMMAND(IDC_MNC_SETTO, &CDlgTumSettingsPerDirection::OnMncSetto)
	ON_BN_CLICKED(IDC_MNCPS_MANAGEAUTO, &CDlgTumSettingsPerDirection::OnClickedMncpsManageauto)
	ON_COMMAND(IDC_MNCPS_SETTO, &CDlgTumSettingsPerDirection::OnMncpsSetto)
	ON_BN_CLICKED(IDC_MNT_MANAGEAUTO, &CDlgTumSettingsPerDirection::OnClickedMntManageauto)
	ON_COMMAND(IDC_MNT_SETTO, &CDlgTumSettingsPerDirection::OnMntSetto)
END_MESSAGE_MAP()

BOOL CDlgTumSettingsPerDirection::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_tabTrafficModes.InsertItem (0, LS (L_LIGHT));
	m_tabTrafficModes.InsertItem (1, LS (L_MEDIUM));
	m_tabTrafficModes.InsertItem (2, LS (L_HEAVY));
	m_tabTrafficModes.SetCurSel (2);

	UINT aSpinIds [] = {
		IDC_RESTTRAFFSSPIN, IDC_MNC_VALUESPIN, IDC_MNCPS_VALUESPIN, IDC_MNT_VALUESPIN
	};
	short aSpinMax [] = {100, 800, 800, 30};

	assert (_countof (aSpinIds) == _countof (aSpinMax));
	for (int i = 0; i < _countof (aSpinIds); i++)
	{
		CSpinButtonCtrl *pSpin = (CSpinButtonCtrl*) GetDlgItem (aSpinIds [i]);
		pSpin->SetRange (1, aSpinMax [i]);
	}

	ApplyLanguage ();

	SerializeSettings (false);

	return TRUE;  
}

void CDlgTumSettingsPerDirection::ReadSettingsFromTumMgr (bool bForDownload)
{
	for (int i = 0; i < 3; i++)
		m_settings [i] = _TumMgr.GetTumRawSettings ((fsTUM)i).getSettings (bForDownload);
}

void CDlgTumSettingsPerDirection::SaveSettingsToTumMgr (bool bForDownload)
{
	for (int i = 0; i < 3; i++)
		_TumMgr.SetTumRawSettingsPerDirection ((fsTUM)i, m_settings [i], bForDownload);
}

void CDlgTumSettingsPerDirection::UpdateEnabled(void)
{
	bool b;

	b = IsDlgButtonChecked (IDC_MNC_MANAGEAUTO) == BST_UNCHECKED;
	GetDlgItem (IDC_MNC_VALUE)->EnableWindow (b);
	GetDlgItem (IDC_MNC_VALUESPIN)->EnableWindow (b);

	b = IsDlgButtonChecked (IDC_MNCPS_MANAGEAUTO) == BST_UNCHECKED;
	GetDlgItem (IDC_MNCPS_VALUE)->EnableWindow (b);
	GetDlgItem (IDC_MNCPS_VALUESPIN)->EnableWindow (b);

	b = IsDlgButtonChecked (IDC_MNT_MANAGEAUTO) == BST_UNCHECKED;
	GetDlgItem (IDC_MNT_VALUE)->EnableWindow (b);
	GetDlgItem (IDC_MNT_VALUESPIN)->EnableWindow (b);	

	b = m_tabTrafficModes.GetCurSel () != 2;
	GetDlgItem (IDC__TRAFFRESTR)->EnableWindow (b);
	GetDlgItem (IDC_RESTRTRAFF)->EnableWindow (b);
	GetDlgItem (IDC_RESTTRAFFSSPIN)->EnableWindow (b);
	GetDlgItem (IDC__PERCOFCONNSPEED)->EnableWindow (b);
}

void CDlgTumSettingsPerDirection::ApplyLanguage(void)
{
	CString str1 = LS (L_MAXCOUNTOFCONNS), str2 = LS (L_MAXCOUNTOFCONNSPERSERV),
		str3 = LS (L_MAXDLDS);
	if (str1.Right (1) == _T (":"))
		str1.Delete (str1.GetLength () - 1);
	if (str2.Right (1) == _T (":"))
		str2.Delete (str2.GetLength () - 1);
	if (str3.Right (1) == _T (":"))
		str3.Delete (str3.GetLength () - 1);
	SetDlgItemText (IDC__MAXNUMBEROFCONNS, str1);
	SetDlgItemText (IDC__MAXNUMBEROFCONNSPERSERV, str2);
	SetDlgItemText (IDC__MAXNUMBEROFTASKS, str3);

	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__TRAFFRESTR, L_TUR),
		fsDlgLngInfo (IDC__PERCOFCONNSPEED, L_PERCOFCONNSPEED),
		fsDlgLngInfo (IDC_MNC_MANAGEAUTO, L_MANAGE_AUTOMATICALLY),
		fsDlgLngInfo (IDC_MNCPS_MANAGEAUTO, L_MANAGE_AUTOMATICALLY),
		fsDlgLngInfo (IDC_MNT_MANAGEAUTO, L_MANAGE_AUTOMATICALLY),
		fsDlgLngInfo (IDC_MNC_SETTO, L_SETTO),
		fsDlgLngInfo (IDC_MNCPS_SETTO, L_SETTO),
		fsDlgLngInfo (IDC_MNT_SETTO, L_SETTO),
	};
	
	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}

void CDlgTumSettingsPerDirection::OnSelchangeModestab(NMHDR *pNMHDR, LRESULT *pResult)
{
	SerializeSettings (false);
	*pResult = 0;
}

void CDlgTumSettingsPerDirection::OnSelchangingModestab(NMHDR *pNMHDR, LRESULT *pResult)
{
	SerializeSettings (true);
	*pResult = 0;
}

bool CDlgTumSettingsPerDirection::SerializeSettings(bool bSave)
{
	int iTUM = m_tabTrafficModes.GetCurSel ();
	vmsTrafficUsageModeRawSettings::PerDirection& s = m_settings [iTUM];

	if (!bSave)
	{
		if (iTUM != 2)
			SetDlgItemInt (IDC_RESTRTRAFF, m_settings [iTUM].u8TrafficLimitPerc);
		else
			SetDlgItemInt (IDC_RESTRTRAFF, 100);

		CheckDlgButton (IDC_MNC_MANAGEAUTO, s.uMaxConns == 0 ? BST_CHECKED : BST_UNCHECKED);
		CheckDlgButton (IDC_MNC_SETTO, s.uMaxConns == 0 ? BST_UNCHECKED : BST_CHECKED);
		SetDlgItemInt (IDC_MNC_VALUE, s.uMaxConns ? s.uMaxConns : 1);

		CheckDlgButton (IDC_MNCPS_MANAGEAUTO, s.uMaxConnsPS == 0 ? BST_CHECKED : BST_UNCHECKED);
		CheckDlgButton (IDC_MNCPS_SETTO, s.uMaxConnsPS == 0 ? BST_UNCHECKED : BST_CHECKED);
		SetDlgItemInt (IDC_MNCPS_VALUE, s.uMaxConnsPS ? s.uMaxConnsPS : 1);

		CheckDlgButton (IDC_MNT_MANAGEAUTO, s.uMaxTasks == 0 ? BST_CHECKED : BST_UNCHECKED);
		CheckDlgButton (IDC_MNT_SETTO, s.uMaxTasks == 0 ? BST_UNCHECKED : BST_CHECKED);
		SetDlgItemInt (IDC_MNT_VALUE, s.uMaxTasks ? s.uMaxTasks : 1);

		UpdateEnabled ();
	}
	else
	{
		if (iTUM != 2)	
		{
			UINT i = GetDlgItemInt (IDC_RESTRTRAFF);
			if (i > 0 && i < 101)
				s.u8TrafficLimitPerc = (BYTE)i;
		}

		s.uMaxConns = IsDlgButtonChecked (IDC_MNC_MANAGEAUTO) == BST_CHECKED ? 0 : GetDlgItemInt (IDC_MNC_VALUE);
		if (s.uMaxConns > 800)
			s.uMaxConns = 800;

		s.uMaxConnsPS = IsDlgButtonChecked (IDC_MNCPS_MANAGEAUTO) == BST_CHECKED ? 0 : GetDlgItemInt (IDC_MNCPS_VALUE);
		if (s.uMaxConnsPS > 800)
			s.uMaxConnsPS = 800;

		s.uMaxTasks = IsDlgButtonChecked (IDC_MNT_MANAGEAUTO) == BST_CHECKED ? 0 : GetDlgItemInt (IDC_MNT_VALUE);
		if (s.uMaxTasks > 30)
			s.uMaxConns = 30;
	}		

	return true;
}

void CDlgTumSettingsPerDirection::OnMncManageauto()
{
	UpdateEnabled ();
}

void CDlgTumSettingsPerDirection::OnMncSetto()
{
	UpdateEnabled ();
}

void CDlgTumSettingsPerDirection::OnClickedMncpsManageauto()
{
	UpdateEnabled ();
}

void CDlgTumSettingsPerDirection::OnMncpsSetto()
{
	UpdateEnabled ();
}

void CDlgTumSettingsPerDirection::OnClickedMntManageauto()
{
	UpdateEnabled ();
}

void CDlgTumSettingsPerDirection::OnMntSetto()
{
	UpdateEnabled ();
}
