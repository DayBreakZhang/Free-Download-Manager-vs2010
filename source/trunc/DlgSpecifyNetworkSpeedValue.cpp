/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "DlgSpecifyNetworkSpeedValue.h"
#include "vmsDialogHelper.h"

IMPLEMENT_DYNAMIC(CDlgSpecifyNetworkSpeedValue, CDialog)

CDlgSpecifyNetworkSpeedValue::CDlgSpecifyNetworkSpeedValue(CWnd* pParent )
	: CDialog(CDlgSpecifyNetworkSpeedValue::IDD, pParent),
	m_uValue (UINT64_MAX)
{

}

CDlgSpecifyNetworkSpeedValue::~CDlgSpecifyNetworkSpeedValue()
{
}

void CDlgSpecifyNetworkSpeedValue::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DIM, m_wndDim);
}

BEGIN_MESSAGE_MAP(CDlgSpecifyNetworkSpeedValue, CDialog)
	ON_BN_CLICKED(IDC_INBITS, &CDlgSpecifyNetworkSpeedValue::OnBnClickedInbits)
END_MESSAGE_MAP()

BOOL CDlgSpecifyNetworkSpeedValue::OnInitDialog()
{
	CDialog::OnInitDialog();

	bool bBits = _App.SpecifyNetworkSpeedValueInBits ();

	if (bBits)
		CheckDlgButton (IDC_INBITS, BST_CHECKED);

	ApplyInBitsToDim ();

	if (m_uValue != UINT64_MAX)
		vmsDialogHelper::SetDlgBytesGroup (this, bBits ? m_uValue * 8 : m_uValue, IDC_VAL, IDC_DIM);

	ApplyLanguage ();

	GetDlgItem (IDC_VAL)->SetFocus ();

	return FALSE;  
}

void CDlgSpecifyNetworkSpeedValue::OnOK()
{
	if (!vmsDialogHelper::GetDlgBytesGroup (this, IDC_VAL, IDC_DIM, &m_uValue))
		return;

	bool bBits = IsDlgButtonChecked (IDC_INBITS) == BST_CHECKED;
	if (bBits)
		m_uValue /= 8;

	CDialog::OnOK();
}

void CDlgSpecifyNetworkSpeedValue::ApplyLanguage(void)
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_INBITS, L_SPECIFY_IN_BITS_INSTEAD_OF_BYTES),
		fsDlgLngInfo (IDCANCEL, L_CANCEL),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_SPECIFY_VALUE);
}

void CDlgSpecifyNetworkSpeedValue::OnBnClickedInbits()
{
	bool bBits = IsDlgButtonChecked (IDC_INBITS) == BST_CHECKED;
	_App.SpecifyNetworkSpeedValueInBits (bBits);
	ApplyInBitsToDim ();
}

void CDlgSpecifyNetworkSpeedValue::ApplyInBitsToDim(void)
{
	bool bBits = IsDlgButtonChecked (IDC_INBITS) == BST_CHECKED;

	CString str0, str1, str2;

	if (!bBits)
	{
		str0.Format ("%s/%s", LS (L_B), LS (L_S)); 
		str1.Format ("%s/%s", LS (L_KB), LS (L_S));
		str2.Format ("%s/%s", LS (L_MB), LS (L_S));
	}
	else
	{
		str0 = _T ("Bps");
		str1 = _T ("Kbps");
		str2= _T ("Mbps");
	}

	int nCurSel = m_wndDim.GetCurSel ();
	m_wndDim.ResetContent ();
	m_wndDim.AddString (str0);
	m_wndDim.AddString (str1);
	m_wndDim.AddString (str2);
	m_wndDim.SetCurSel (nCurSel == CB_ERR ? 0 : nCurSel);
}
