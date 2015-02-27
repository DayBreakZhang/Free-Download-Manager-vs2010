/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fdm.h"
#include "fdmapp.h"
#include "Dlg_Options_Downloads_Monitoring.h"
#include "vmsFirefoxMonitoring.h"
#include "DlgCustomizeIEMenu.h"
#include "DownloaderProperties_MonitorPage_SkipList.h"
#include "FolderBrowser.h"
#include "vistafx/vistafx.h"
#include "DlgElevateRequired.h"
#include "vmsElevatedFdm.h"
#include "vmsFdmUiDetails.h"
#include "vmsChromeExtensionInstaller.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlg_Options_Downloads_Monitoring::CDlg_Options_Downloads_Monitoring(CWnd* pParent )
	: CDlg_Options_Page(CDlg_Options_Downloads_Monitoring::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_Options_Downloads_Monitoring)
		
	//}}AFX_DATA_INIT
}

void CDlg_Options_Downloads_Monitoring::DoDataExchange(CDataExchange* pDX)
{
	CDlg_Options_Page::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_Options_Downloads_Monitoring)
		
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlg_Options_Downloads_Monitoring, CDlg_Options_Page)
	//{{AFX_MSG_MAP(CDlg_Options_Downloads_Monitoring)
	ON_BN_CLICKED(IDC_CUSTOMIZE, OnCustomize)
	ON_BN_CLICKED(IDC_SKIPLIST, OnSkiplist)
	ON_BN_CLICKED(IDC_IE2, OnIe2)
	ON_BN_CLICKED(IDC_FIREFOX, OnFirefox)
	ON_BN_CLICKED(IDC_DONTMONSMALL, OnDontmonsmall)
	ON_BN_CLICKED(IDC_ADDTOIEMENU, OnAddtoiemenu)
	ON_BN_CLICKED(IDC_FFPORTVER, OnFfportver)
	ON_BN_CLICKED(IDC_OPERA, OnOpera)
	ON_BN_CLICKED(IDC_NETSCAPE, OnNetscape)
	ON_BN_CLICKED(IDC_MOZILLA, OnMozilla)
	ON_BN_CLICKED(IDC_SAFARI, OnSafari)
	ON_BN_CLICKED(IDC_CHROME, OnChrome)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlg_Options_Downloads_Monitoring::OnInitDialog() 
{
	CDlg_Options_Page::OnInitDialog();
	
	BOOL bIE2 = _IECatchMgr.IsIE2Active ();	
	
	CheckDlgButton (IDC_IE2, bIE2 ? BST_CHECKED : BST_UNCHECKED);
	CheckDlgButton (IDC_CLIPBOARD, _App.Monitor_Clipboard () ? BST_CHECKED : BST_UNCHECKED);
	
	BOOL bFF = _App.Monitor_Firefox () && vmsFirefoxMonitoring::IsInstalled () &&
		vmsFirefoxMonitoring::IsFlashGotInstalled () == false;
	if (bFF)
	{
		bool bEnabled;
		if (vmsFirefoxMonitoring::IsEnabledInFirefox (bEnabled) && !bEnabled)
			bFF = FALSE;
	}
	CheckDlgButton (IDC_FIREFOX, bFF ? BST_CHECKED : BST_UNCHECKED);

	bool bChromeEnabled = true;
	vmsChromeExtensionInstaller::Enabled(bChromeEnabled);
	BOOL bChrome = _App.Monitor_Chrome() && vmsChromeExtensionInstaller::IsInstalled() && bChromeEnabled;
	CheckDlgButton (IDC_CHROME, bChrome ? BST_CHECKED : BST_UNCHECKED);
	
	
	_IECMM.ReadState ();
	m_bIEMenuWas = _IECMM.IsIEMenusPresent ();
	CheckDlgButton (IDC_ADDTOIEMENU, 
		(m_bIEMenuWas || _App.Monitor_IEMenu_Enable ()) ? BST_CHECKED : BST_UNCHECKED);
	
	CheckDlgButton (IDC_ALTPRESSED, _App.Monitor_ALTShouldPressed () ? BST_CHECKED : BST_UNCHECKED);
	
	CheckDlgButton (IDC_ALLOWIETODL, _App.Monitor_AllowDownload () ? BST_CHECKED : BST_UNCHECKED);

	size_t cBrowsers = 0;
	const vmsFdmUiDetails::KnownBrowserData *pBrowsers = vmsFdmUiDetails::getKnownBrowsersData (cBrowsers);

	for (size_t i = 0; i < cBrowsers; i++)
		CheckDlgButton (pBrowsers [i].nCtrlId, _NOMgr.getPluginInstaller (pBrowsers [i].enBrowser).IsPluginInstalled () ? BST_CHECKED : BST_UNCHECKED);
	
	CheckDlgButton (IDC_SILENT, _App.Monitor_Silent () ? BST_CHECKED : BST_UNCHECKED);
	
	int iSize = _App.Monitor_SkipSmaller ();
	CheckDlgButton (IDC_DONTMONSMALL, iSize == 0 ? BST_UNCHECKED : BST_CHECKED);
	SetDlgItemInt (IDC_SMALLSIZE, iSize ? iSize/1000 : 10);

	if (IS_PORTABLE_MODE)
		GetDlgItem (IDC_FFPORTVER)->ShowWindow (SW_SHOW);
	
	ApplyLanguage ();
	UpdateEnabled ();
	
	return TRUE;  
	              
}

CString CDlg_Options_Downloads_Monitoring::get_PageTitle()
{
	return LS (L_MONITOR);
}

CString CDlg_Options_Downloads_Monitoring::get_PageShortTitle()
{
	return LS (L_MONITOR);
}

BOOL CDlg_Options_Downloads_Monitoring::Apply()
{
	BOOL bIE2 = FALSE;

	DWORD dwMUSO = 0;	
		
	bIE2 = IsDlgButtonChecked (IDC_IE2) == BST_CHECKED;

	
	_App.Monitor_IE1 ( FALSE);
	
	BOOL bIE2Active = _IECatchMgr.IsIE2Active ();

	BOOL bRR = FALSE;	

	BOOL bFF = IsDlgButtonChecked (IDC_FIREFOX) == BST_CHECKED;
	if (bFF && vmsFirefoxMonitoring::IsInstalled () == false)
	{
		if (vmsFirefoxMonitoring::Install (true) == false)
		{
			MessageBox (LS (L_CANTINITFFMONITOR), LS (L_ERR), MB_ICONERROR);
			CheckDlgButton (IDC_FIREFOX, BST_UNCHECKED);
			bFF = FALSE;
		}
	}
	if (bFF && vmsFirefoxMonitoring::IsFlashGotInstalled ())
	{
		MessageBox (LS (L_FLASHGOTDETECTED), vmsFdmAppMgr::getAppName (), MB_ICONWARNING);
		CheckDlgButton (IDC_FIREFOX, BST_UNCHECKED);
		bFF = FALSE;
	}
	if (bFF)
	{
		DWORD dwResult = 0;
		((CFdmApp*)AfxGetApp ())->CheckFirefoxExtension (&dwResult);
		if (dwResult)
		{
			if (!(dwResult & (1<<1)))
			{
				CheckDlgButton (IDC_FIREFOX, BST_UNCHECKED);
				bFF = FALSE;
			}
			else
			{
				
				_App.get_SettingsStore ()->WriteProfileInt (_T ("State"), _T ("FfExtChecked"), FALSE);
			}
		}
	}
	if (bFF)
		dwMUSO |= MONITOR_USERSWITCHEDON_FIREFOX;
	_App.Monitor_Firefox (bFF);
	if (bFF)
		vmsFirefoxMonitoring::Install (true); 

	BOOL bChrome = IsDlgButtonChecked(IDC_CHROME) == BST_CHECKED;
	bool bChromeEnabled = true;
	vmsChromeExtensionInstaller::Enabled(bChromeEnabled);
	BOOL bOldChrome = _App.Monitor_Chrome() && vmsChromeExtensionInstaller::IsInstalled() && bChromeEnabled;
	_App.Monitor_Chrome (bChrome);
	if(bChrome)
	{
		if(!bOldChrome && !vmsChromeExtensionInstaller::IsInstalled())
		{
			if(!vmsChromeExtensionInstaller::Install())
				MessageBox (LS (L_CANTINITCHROMEMONITOR), LS (L_ERR), MB_ICONERROR);
			if(!vmsChromeExtensionInstaller::IsInstalled())
			{
				_App.Monitor_Chrome (FALSE);
				bChrome = FALSE;
			}
		}
		else
		{
			if(!bOldChrome && vmsChromeExtensionInstaller::IsInstalled() && bChromeEnabled)
				bRR = TRUE;
		}
	}
	else
	{
		
		if(bOldChrome)
			bRR = TRUE;
	}
	if(bChrome)
		if(!bChromeEnabled)
			vmsChromeExtensionInstaller::Enable();

	
	if ((bIE2 == FALSE && bIE2Active) || (bIE2 && bIE2Active == FALSE))
	{
		if (bIE2 && _IECatchMgr.IsMonitoringDllRegistered () == FALSE)
		{
			BOOL bOK = _IECatchMgr.InstallIeIntegration (TRUE, IS_PORTABLE_MODE);
			if (!bOK)
				bOK = vmsElevatedFdm::o ().InstallIeIntegration (true);
			if (!bOK)
			{
				MessageBox (LS (L_ERRIE), LS (L_ERR), MB_ICONERROR);
				CheckDlgButton (IDC_IE2, bIE2Active ? BST_CHECKED : BST_UNCHECKED);
			}
			else
				bRR = TRUE;
		}
		
		_App.Monitor_IE2 (bIE2);
	}
	if (bIE2)
		dwMUSO |= MONITOR_USERSWITCHEDON_IE;

	BOOL b = IsDlgButtonChecked (IDC_ADDTOIEMENU) == BST_CHECKED;
	_App.Monitor_IEMenu_Enable (b);
	if (b)
		_IECMM.AddIEMenus ();
	else
		_IECMM.DeleteIEMenus ();
	if (b != m_bIEMenuWas)
	{
		bRR = TRUE;
		m_bIEMenuWas = b;
	}

	b = IsDlgButtonChecked (IDC_CLIPBOARD) == BST_CHECKED;
	_App.Monitor_Clipboard (b);
	_pwndDownloads->m_ClpbrdCatch.Enable (b);

	_App.Monitor_ALTShouldPressed (IsDlgButtonChecked (IDC_ALTPRESSED) == BST_CHECKED);
	_App.Monitor_AllowDownload (IsDlgButtonChecked (IDC_ALLOWIETODL) == BST_CHECKED);

	
	_IECatchMgr.ReadSettings ();

	size_t cBrowsers = 0;
	const vmsFdmUiDetails::KnownBrowserData *pBrowsers = vmsFdmUiDetails::getKnownBrowsersData (cBrowsers);

	std::vector <vmsKnownBrowsers::Browser> vBrowsersToInstall, vBrowsersToDeinstall;

	for (size_t nBrowser = 0; nBrowser < cBrowsers; nBrowser++)
	{
		const vmsFdmUiDetails::KnownBrowserData& bd = pBrowsers [nBrowser];
		vmsNpPluginInstaller& pluginInstaller = _NOMgr.getPluginInstaller (bd.enBrowser);

		
		if (IsDlgButtonChecked (bd.nCtrlId) == BST_CHECKED)
		{
			dwMUSO |= bd.dwUserSwitchedOnFlag;

			
			if (pluginInstaller.IsPluginInstalled (TRUE) == FALSE)
				vBrowsersToInstall.push_back (bd.enBrowser);
		}
		else if (pluginInstaller.IsPluginInstalled (!pluginInstaller.getPluginsDirPath ().empty ()))
		{
			vBrowsersToDeinstall.push_back (bd.enBrowser);
		}
	}

	bool bRR2 = false;
	_NOMgr.InstallDeinstallPluginsExWithErrMsg (m_hWnd, vBrowsersToInstall, vBrowsersToDeinstall, bRR2);
	if (bRR2)
		bRR = TRUE;

	_App.Monitor_UserSwitchedOn (dwMUSO);

	_App.Monitor_Silent (IsDlgButtonChecked (IDC_SILENT) == BST_CHECKED);
	int iSize = 0;
	if (IsDlgButtonChecked (IDC_DONTMONSMALL) == BST_CHECKED)
		iSize = GetDlgItemInt (IDC_SMALLSIZE);
	_App.Monitor_SkipSmaller (iSize*1000);

	if (bRR)
		setBrowserRestartRequired (true);

	UpdateEnabled ();
	
	return TRUE;
}

void CDlg_Options_Downloads_Monitoring::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__MONITORFOR, L_MONITORFOR),
		fsDlgLngInfo (IDC_CLIPBOARD, L_CLIPBOARD),
		fsDlgLngInfo (IDC_ADDTOIEMENU, L_ADDTOBRMENU),
		fsDlgLngInfo (IDC_ALTPRESSED, L_ALTSHOULD),
		fsDlgLngInfo (IDC_ALLOWIETODL, L_ALLOWBRTODL),
		fsDlgLngInfo (IDC_SILENT, L_SILENTMONITORING),
		fsDlgLngInfo (IDC_CUSTOMIZE, L_CUSTOMIZE),
		fsDlgLngInfo (IDC_DONTMONSMALL, L_DONTMONSMALL),
		fsDlgLngInfo (IDC__KBYTES, L_KBYTES),
		fsDlgLngInfo (IDC_SKIPLIST, L_SKIPLIST),
	};
	
	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}

void CDlg_Options_Downloads_Monitoring::UpdateEnabled()
{
	BOOL bIE = IsDlgButtonChecked (IDC_IE2) == BST_CHECKED ||
		IsDlgButtonChecked (IDC_FIREFOX) == BST_CHECKED ||
		IsDlgButtonChecked (IDC_CHROME) == BST_CHECKED;
	
	GetDlgItem (IDC_ALTPRESSED)->EnableWindow (bIE);
	GetDlgItem (IDC_ALLOWIETODL)->EnableWindow (bIE);
	GetDlgItem (IDC_DONTMONSMALL)->EnableWindow (bIE);
	
	BOOL b = bIE || IsDlgButtonChecked (IDC_CLIPBOARD) == BST_CHECKED;
	GetDlgItem (IDC_SKIPLIST)->EnableWindow (b);
	
	GetDlgItem (IDC_CUSTOMIZE)->EnableWindow (
		IsDlgButtonChecked (IDC_ADDTOIEMENU) == BST_CHECKED);
	
	b = bIE && IsDlgButtonChecked (IDC_DONTMONSMALL) == BST_CHECKED;
	GetDlgItem (IDC_SMALLSIZE)->EnableWindow (b);
	GetDlgItem (IDC__KBYTES)->EnableWindow (b);
}

void CDlg_Options_Downloads_Monitoring::OnCustomize() 
{
	CDlgCustomizeIEMenu dlg;
	_DlgMgr.DoModal (&dlg);	
}

void CDlg_Options_Downloads_Monitoring::OnSkiplist() 
{
	CDownloaderProperties_MonitorPage_SkipList dlg;
	_DlgMgr.DoModal (&dlg);	
}

void CDlg_Options_Downloads_Monitoring::OnIe2() 
{
	UpdateEnabled ();	
}

void CDlg_Options_Downloads_Monitoring::OnFirefox() 
{
	UpdateEnabled ();	
}

void CDlg_Options_Downloads_Monitoring::OnDontmonsmall() 
{
	UpdateEnabled ();	
}

void CDlg_Options_Downloads_Monitoring::OnAddtoiemenu() 
{
	UpdateEnabled ();	
}

void CDlg_Options_Downloads_Monitoring::OnFfportver() 
{
	MessageBox (LS (L_SPECIFYFFPORTVERFOLDER));
	CString str; 
	CFolderBrowser *fb = CFolderBrowser::Create (LS (L_SPECIFYFFPORTVERFOLDER), str, NULL, this);
	if (fb == NULL)
		return;
	_App.Firefox_PortableVersionPath (fb->GetPath ());
}

void CDlg_Options_Downloads_Monitoring::OnOpera() 
{
	UpdateElevateReq ();	
}

void CDlg_Options_Downloads_Monitoring::OnNetscape() 
{
	UpdateElevateReq ();	
}

void CDlg_Options_Downloads_Monitoring::OnMozilla() 
{
	UpdateElevateReq ();	
}

void CDlg_Options_Downloads_Monitoring::OnSafari() 
{
	UpdateElevateReq ();	
}

void CDlg_Options_Downloads_Monitoring::OnChrome() 
{
	UpdateEnabled ();
}

void CDlg_Options_Downloads_Monitoring::UpdateElevateReq()
{
	
}
