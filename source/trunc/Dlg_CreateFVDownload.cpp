/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Dlg_CreateFVDownload.h"
#include "vmsVideoSiteHtmlCodeParser.h"
#include "mfchelp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlg_CreateFVDownload::CDlg_CreateFVDownload(CWnd* pParent )
	: CDialog(CDlg_CreateFVDownload::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_CreateFVDownload)
		
	//}}AFX_DATA_INIT
}

void CDlg_CreateFVDownload::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_CreateFVDownload)
	DDX_Control(pDX, IDC_S_SITES, m_wndSSites);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlg_CreateFVDownload, CDialog)
	//{{AFX_MSG_MAP(CDlg_CreateFVDownload)
	ON_BN_CLICKED(IDC_VIEW_S_SITES, OnViewSSites)
	ON_BN_CLICKED(IDC_USE_AUTO_CONVERT, OnUseAutoConvert)
	ON_BN_CLICKED(IDC_SETTINGS2, OnSettings)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlg_CreateFVDownload::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	
	CRect rc;
	GetDlgItem (IDC__S0)->GetWindowRect (&rc);
	ScreenToClient (&rc);

	CRect rc2;
	GetClientRect (&rc2);

	GetWindowRect (&m_rcOldSize);

	SetWindowPos (NULL, 0, 0, m_rcOldSize.Width (), m_rcOldSize.Height () - (rc2.bottom - rc.top),
		SWP_NOZORDER | SWP_NOMOVE);
	

	LPCSTR apszSites [] = {
		"Youtube", "http://youtube.com/watch?v=xPxDw7ajfGE",
		"Google Video", "http://video.google.com/url?docid=1688669...",
		"LiveDigital", "http://livedigital.com/video/",
		"MySpace Videos", "http://vids.myspace.com/index.cfm?fuseaction=...",
		"Blennus", "http://blennus.com/index.php?option=content&task=...",
		"Dailymotion", "http://www.dailymotion.com/us/cluster/animals/...",
	};

	CString str;
	int i = 0;
	for (i = 0; i < sizeof (apszSites) / sizeof (LPCSTR) / 2; i++)
	{
		str.Format ("%s, %s %s", apszSites [i*2], LS (L_E_G), apszSites [i*2+1]);
		m_wndSSites.AddString (str);
	}
	m_wndSSites.SetCurSel (0);
	m_wndSSites.ShowWindow (SW_HIDE);

	CComboBox *pUrls = (CComboBox*) GetDlgItem (IDC_URL);
	for (i = 0; i < _LastFlashVideoUrls.GetRecordCount (); i++)
		pUrls->AddString (_LastFlashVideoUrls.GetRecord (i));

	if (m_strUrl.IsEmpty ())
	{
		LPCSTR pszUrl = _ClipbrdMgr.Text ();
		if (pszUrl && *pszUrl)
		{
			fsURL url;
			if (url.Crack (pszUrl) == IR_SUCCESS && 
					vmsVideoSiteHtmlCodeParser::IsSiteSupported (url.GetHostName ()))
				SetDlgItemText (IDC_URL, pszUrl);
		}
	}
	else
	{
		SetDlgItemText (IDC_URL, m_strUrl);
	}

	if (_App.View_CreateFVDownload_SetupAdvStgs ())
		CheckDlgButton (IDC_ADVANCED, BST_CHECKED);

	if (_App.FVDownloads_AutoConvertVideo () && _AppMgr.IsMediaFeaturesInstalled ())
	{
		CheckDlgButton (IDC_USE_AUTO_CONVERT, BST_CHECKED);
		UpdateEnabled ();
	}

	vmsMediaConvertMgr::GetDefaultSettings (m_stgsAutoConvert);

	ApplyLanguage ();

	mfcSetForegroundWindow (this);
	
	return TRUE;  
	              
}

void CDlg_CreateFVDownload::OnViewSSites() 
{
	m_wndSSites.ShowWindow (SW_SHOW);

	SetWindowPos (NULL, 0, 0, m_rcOldSize.Width (), m_rcOldSize.Height (),
		SWP_NOZORDER | SWP_NOMOVE);	

	GetDlgItem (IDC_VIEW_S_SITES)->ShowWindow (SW_HIDE);
}

void CDlg_CreateFVDownload::OnOK() 
{
	GetDlgItemText (IDC_URL, m_strUrl);

	fsURL url;
	if (url.Crack (m_strUrl) != IR_SUCCESS ||
			FALSE == vmsVideoSiteHtmlCodeParser::IsSiteSupported (url.GetHostName ()))
	{
		MessageBox (LS (L_FVDLD_SITEISNOTSUPP), LS (L_INPERR), MB_ICONERROR);
		return;
	}

	_LastFlashVideoUrls.AddRecord (m_strUrl);
	m_bSetupAdvStgs = IsDlgButtonChecked (IDC_ADVANCED) == BST_CHECKED;
	_App.View_CreateFVDownload_SetupAdvStgs (m_bSetupAdvStgs);

	m_bAutoConvert = IsDlgButtonChecked (IDC_USE_AUTO_CONVERT) == BST_CHECKED;

	CDialog::OnOK();
}

void CDlg_CreateFVDownload::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_ADVANCED, L_SETUPADVOPTIONS),
		fsDlgLngInfo (IDC_VIEW_S_SITES, L_VIEW_LIST_OF_SUPP_SITES),
		fsDlgLngInfo (IDC_USE_AUTO_CONVERT, L_USE_AUTO_CONVERT),
		fsDlgLngInfo (IDC_SETTINGS2, L_CUSTOMIZE),
		fsDlgLngInfo (IDCANCEL, L_CANCEL),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_CREATEFVDLD);
}

void CDlg_CreateFVDownload::OnUseAutoConvert() 
{
	if (_AppMgr.IsMediaFeaturesInstalled () == FALSE)
	{
		_AppMgr.ShowInstallMediaFeaturesMessage ();
		CheckDlgButton (IDC_USE_AUTO_CONVERT, BST_UNCHECKED);
		return;
	}

	_App.FVDownloads_AutoConvertVideo (
		IsDlgButtonChecked (IDC_USE_AUTO_CONVERT) == BST_CHECKED);
	UpdateEnabled ();
}

void CDlg_CreateFVDownload::UpdateEnabled()
{
	GetDlgItem (IDC_SETTINGS2)->EnableWindow (
		IsDlgButtonChecked (IDC_USE_AUTO_CONVERT) == BST_CHECKED);
}

void CDlg_CreateFVDownload::OnSettings() 
{
	vmsMediaConvertMgr::ShowSettingsUI (m_stgsAutoConvert);
}
