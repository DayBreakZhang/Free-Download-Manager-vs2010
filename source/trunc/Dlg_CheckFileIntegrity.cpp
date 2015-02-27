/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Dlg_CheckFileIntegrity.h"
#include "Hash\vmsHash.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlg_CheckFileIntegrity::CDlg_CheckFileIntegrity(CWnd* pParent )
	: CDialog(CDlg_CheckFileIntegrity::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_CheckFileIntegrity)
		
	//}}AFX_DATA_INIT
}

void CDlg_CheckFileIntegrity::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_CheckFileIntegrity)
	DDX_Control(pDX, IDC_ALGORITHM, m_wndAlgorithm);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlg_CheckFileIntegrity, CDialog)
	//{{AFX_MSG_MAP(CDlg_CheckFileIntegrity)
	ON_BN_CLICKED(IDC_PASTEFROMCLIPBOARD, OnPastefromclipboard)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlg_CheckFileIntegrity::OnInitDialog() 
{
	CDialog::OnInitDialog();

	LPCSTR ppszAlgs [] = {
		"MD5", "SHA-1", "SHA-2 256", "SHA-2 384", "SHA-2 512",
		"CRC 32"
	};

	
	UINT ppnAlgs [] = {
		HA_MD5, HA_SHA1, 
		HA_SHA2, HA_SHA2 + 1000 + HSHA2S_384, HA_SHA2 + 1000 + HSHA2S_512, 
		HA_CRC32,
	};
	

	CString strLastAlg = _App.Hash_LastAlgorithm ();

	for (int i = 0; i < sizeof (ppszAlgs) / sizeof (LPCSTR); i++)
	{
		m_wndAlgorithm.AddString (ppszAlgs [i]);
		m_wndAlgorithm.SetItemData (i, ppnAlgs [i]);
		if (strLastAlg.CompareNoCase (ppszAlgs [i]) == 0)
			m_wndAlgorithm.SetCurSel (i);
	}

	if (CB_ERR == m_wndAlgorithm.GetCurSel ())
		m_wndAlgorithm.SetCurSel (0);
	
	ApplyLanguage ();

	if (m_strChecksum.IsEmpty () == FALSE)
	{
		SetDlgItemText (IDC_CHECKSUM, m_strChecksum);
		UINT nAlg = m_nAlgorithm;
		if (nAlg == HA_SHA2 && m_nSHA2Strength != 0)
			nAlg += 1000 + m_nSHA2Strength;
		for (int i = 0; i < m_wndAlgorithm.GetCount (); i++)
		{
			if (m_wndAlgorithm.GetItemData (i) == nAlg)
			{
				m_wndAlgorithm.SetCurSel (i);
				break;
			}
		}
	}
	else
	{
		PasteChecksum (true);
	}

	((CEdit*)GetDlgItem (IDC_CHECKSUM))->SetSel (MAKELPARAM (-1, 0));
	
	return TRUE;  
	              
}

void CDlg_CheckFileIntegrity::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__INFOMSG, L_CHECKINTEGRITY_INFOMSG),
		fsDlgLngInfo (IDC__ALGORITHM, L_ALGORITHM, TRUE),
		fsDlgLngInfo (IDC__CHECKSUM, L_CHECKSUM, TRUE),
		fsDlgLngInfo (IDC_PASTEFROMCLIPBOARD, L_PASTEFROMCLIPBOARD),
		fsDlgLngInfo (IDCANCEL, L_CANCEL),
		fsDlgLngInfo (IDOK, L_CHECK),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_CHECKFILEINTEGRITY);
}

void CDlg_CheckFileIntegrity::OnOK() 
{
	m_nAlgorithm = m_wndAlgorithm.GetItemData (m_wndAlgorithm.GetCurSel ());
	m_nSHA2Strength = HSHA2S_256;
	
	if (m_nAlgorithm >= 1000) {
		m_nSHA2Strength = m_nAlgorithm - HA_SHA2 - 1000;
		m_nAlgorithm = HA_SHA2;
	}
	if (m_nAlgorithm != HA_SHA2)
		m_nSHA2Strength = 0;

	GetDlgItemText (IDC_CHECKSUM, m_strChecksum);
	if (m_strChecksum.GetLength () == 0)
		return;

	CString str; m_wndAlgorithm.GetWindowText (str);
	_App.Hash_LastAlgorithm (str);
	
	CDialog::OnOK();
}

void CDlg_CheckFileIntegrity::OnPastefromclipboard() 
{
	PasteChecksum (false);
}

void CDlg_CheckFileIntegrity::PasteChecksum(bool bCheckValid)
{
	LPCSTR psz = _ClipbrdMgr.Text ();
	if (psz) {
		if (bCheckValid) {
			LPCSTR psz2 = psz;
			while (*psz2) {
				if (!(
					  (*psz2 >= '0' && *psz2 <= '9') ||
					  (*psz2 >= 'a' && *psz2 <= 'f') ||
					  (*psz2 >= 'A' && *psz2 <= 'F') ||
					  (*psz2 == ' ' || *psz2 == '-')
					  ))
					return; 
				psz2++;
			}
		}
		SetDlgItemText (IDC_CHECKSUM, psz);
	}
}
