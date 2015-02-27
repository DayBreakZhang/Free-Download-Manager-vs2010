/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fdm.h"
#include "Dlg_Options_Downloads_Flv.h"
#include "vmsFlvSniffInjector.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlg_Options_Downloads_Flv::CDlg_Options_Downloads_Flv(CWnd* pParent )
	: CDlg_Options_Page(CDlg_Options_Downloads_Flv::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_Options_Downloads_Flv)
		
	//}}AFX_DATA_INIT
}

void CDlg_Options_Downloads_Flv::DoDataExchange(CDataExchange* pDX)
{
	CDlg_Options_Page::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_Options_Downloads_Flv)
		
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlg_Options_Downloads_Flv, CDlg_Options_Page)
	//{{AFX_MSG_MAP(CDlg_Options_Downloads_Flv)
	ON_BN_CLICKED(IDC_ENABLE_MONITORING, OnEnableMonitoring)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlg_Options_Downloads_Flv::OnInitDialog() 
{
	CDlg_Options_Page::OnInitDialog();

	DWORD dw = _App.FlvMonitoring_ProcessList ();
	m_dwOldFSDI = dw;

	if (dw & FSDI_PROCESS_IE)
		CheckDlgButton (IDC_M_IE, BST_CHECKED);
	if (dw & FSDI_PROCESS_FIREFOX)
		CheckDlgButton (IDC_M_FIREFOX, BST_CHECKED);
	if (dw & FSDI_PROCESS_OPERA)
		CheckDlgButton (IDC_M_OPERA, BST_CHECKED);
	if (dw & FSDI_PROCESS_NETSCAPE)
		CheckDlgButton (IDC_M_NETSCAPE, BST_CHECKED);
	if (dw & FSDI_PROCESS_SAFARI)
		CheckDlgButton (IDC_M_SAFARI, BST_CHECKED);
	if (dw & FSDI_PROCESS_CHROME)
		CheckDlgButton (IDC_M_CHROME, BST_CHECKED);
	if (dw & FSDI_PROCESS_SEAMONKEY)
		CheckDlgButton (IDC_M_SEAMONKEY, BST_CHECKED);

	if (_App.FlvMonitoring_Enable ())
		CheckDlgButton (IDC_ENABLE_MONITORING, BST_CHECKED);
	else
		m_dwOldFSDI = 0;

	m_dwInitialFSDI = m_dwOldFSDI;

	DWORD bShowBtn = _App.FlvMonitoring_ShowDownloadItButton ();

	if (bShowBtn)
	{
		CRegKey key;
		if (ERROR_SUCCESS == key.Open (HKEY_CURRENT_USER, 
				_T ("Software\\Microsoft\\Internet Explorer\\LowRegistry\\Software\\FreeDownloadManager.ORG\\Free Download Manager\\Settings\\FlvMonitoring"), KEY_READ))
		{
			key.QueryValue (bShowBtn, _T ("ShowDownloadItBtn"));
			if (!bShowBtn)
				_App.FlvMonitoring_ShowDownloadItButton (FALSE);
		}
	}

	if (bShowBtn)
		CheckDlgButton (IDC_SHOWGETITBTN, BST_CHECKED);

	UpdateEnabled ();
	ApplyLanguage ();
	
	return TRUE;  
	              
}

CString CDlg_Options_Downloads_Flv::get_PageShortTitle()
{
	return LS (L_FLASH_VIDEO);
}

CString CDlg_Options_Downloads_Flv::get_PageTitle()
{
	return LS (L_FVDOWNLOADS);
}

BOOL CDlg_Options_Downloads_Flv::Apply()
{
	CRegKey keyIeLow;
	if (ERROR_SUCCESS != keyIeLow.Open (HKEY_CURRENT_USER, 
		_T ("Software\\Microsoft\\Internet Explorer\\LowRegistry\\Software\\FreeDownloadManager.ORG\\Free Download Manager\\Settings\\FlvMonitoring"), KEY_ALL_ACCESS))
	{
		keyIeLow.Create (HKEY_CURRENT_USER, 
			_T ("Software\\Microsoft\\Internet Explorer\\LowRegistry\\Software\\FreeDownloadManager.ORG\\Free Download Manager\\Settings\\FlvMonitoring"),
			NULL, 0, KEY_ALL_ACCESS, NULL, NULL);
	}

	BOOL bShowBtn = IsDlgButtonChecked (IDC_SHOWGETITBTN) == BST_CHECKED;
	_App.FlvMonitoring_ShowDownloadItButton (bShowBtn);
	keyIeLow.SetValue (bShowBtn, _T ("ShowDownloadItBtn"));

	bool bEnable = IsDlgButtonChecked (IDC_ENABLE_MONITORING) == BST_CHECKED;
	_App.FlvMonitoring_Enable (bEnable);
	keyIeLow.SetValue (bEnable, _T ("Enable"));

	DWORD dwFSDI = 0;

	if (bEnable)
	{	
		DWORD dw = 0;
		if (IsDlgButtonChecked (IDC_M_IE) == BST_CHECKED)
			dw |= FSDI_PROCESS_IE;
		if (IsDlgButtonChecked (IDC_M_FIREFOX) == BST_CHECKED)
			dw |= FSDI_PROCESS_FIREFOX;
		if (IsDlgButtonChecked (IDC_M_OPERA) == BST_CHECKED)
			dw |= FSDI_PROCESS_OPERA;
		if (IsDlgButtonChecked (IDC_M_NETSCAPE) == BST_CHECKED)
			dw |= FSDI_PROCESS_NETSCAPE;
		if (IsDlgButtonChecked (IDC_M_SAFARI) == BST_CHECKED)
			dw |= FSDI_PROCESS_SAFARI;
		if (IsDlgButtonChecked (IDC_M_CHROME) == BST_CHECKED)
			dw |= FSDI_PROCESS_CHROME;
		if (IsDlgButtonChecked (IDC_M_SEAMONKEY) == BST_CHECKED)
			dw |= FSDI_PROCESS_SEAMONKEY;

		dwFSDI = dw;

		_App.FlvMonitoring_ProcessList (dw);
		keyIeLow.SetValue (dw, _T ("ProcessList"));

		std::vector <tstring> v;
		getFsdiProcessList (dw, v);
		vmsFlvSniffInjector::o ().setProcessList (v);
	}

	vmsFlvSniffInjector::o ().Enable (bEnable);

	if (dwFSDI != m_dwOldFSDI)
	{
		if (dwFSDI != m_dwInitialFSDI)
			setBrowserRestartRequired (true);
		m_dwOldFSDI = dwFSDI;
	}

	return TRUE;
}

void CDlg_Options_Downloads_Flv::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_ENABLE_MONITORING, L_FLV_ENABLEMONITORING),
		fsDlgLngInfo (IDC__WARNING, L_FLV_MONITOR_WARNING),
	};
	
	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);

	CString str = LS (L_SHOWDOWNLOADITBTN_);
	str += ' ';
	str += LS (L_IE_AND_FF_ONLY);
	SetDlgItemText (IDC_SHOWGETITBTN, str);
}

void CDlg_Options_Downloads_Flv::OnEnableMonitoring() 
{
	UpdateEnabled ();
}	

void CDlg_Options_Downloads_Flv::UpdateEnabled()
{
	bool b = IsDlgButtonChecked (IDC_ENABLE_MONITORING) == BST_CHECKED;
	GetDlgItem (IDC_M_IE)->EnableWindow (b);
	GetDlgItem (IDC_M_FIREFOX)->EnableWindow (b);
	GetDlgItem (IDC_M_OPERA)->EnableWindow (b);
	GetDlgItem (IDC_M_NETSCAPE)->EnableWindow (b);
	GetDlgItem (IDC_M_SAFARI)->EnableWindow (b);
	GetDlgItem (IDC_M_CHROME)->EnableWindow (b);
	GetDlgItem (IDC_M_SEAMONKEY)->EnableWindow (b);
}
