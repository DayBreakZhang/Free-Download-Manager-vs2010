/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "DownloaderProperties_MonitorPage.h"
#include "DownloadsWnd.h"
#include "DlgCustomizeIEMenu.h"
#include "vmsFirefoxMonitoring.h"
#include "DownloaderProperties_MonitorPage_SkipList.h"

extern CDownloadsWnd* _pwndDownloads; 

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CDownloaderProperties_MonitorPage, CPropertyPage)

CDownloaderProperties_MonitorPage::CDownloaderProperties_MonitorPage() : CPropertyPage(CDownloaderProperties_MonitorPage::IDD)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = LS (L_MONITOR);
}

CDownloaderProperties_MonitorPage::~CDownloaderProperties_MonitorPage()
{
}

void CDownloaderProperties_MonitorPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDownloaderProperties_MonitorPage)
		
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDownloaderProperties_MonitorPage, CPropertyPage)
	//{{AFX_MSG_MAP(CDownloaderProperties_MonitorPage)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	ON_BN_CLICKED(IDC_CLIPBOARD, OnClipboard)
	ON_BN_CLICKED(IDC_ALTPRESSED, OnAltpressed)
	ON_BN_CLICKED(IDC_ADDTOIEMENU, OnAddtoiemenu)
	ON_BN_CLICKED(IDC_OPERA, OnOpera)
	ON_BN_CLICKED(IDC_NETSCAPE, OnNetscape)
	ON_WM_HELPINFO()
	ON_BN_CLICKED(IDC_IE2, OnIe2)
	ON_BN_CLICKED(IDC_ALLOWIETODL, OnAllowietodl)
	ON_BN_CLICKED(IDC_FIREFOX, OnFirefox)
	ON_BN_CLICKED(IDC_SILENT, OnSilent)
	ON_BN_CLICKED(IDC_CUSTOMIZE, OnCustomize)
	ON_BN_CLICKED(IDC_DONTMONSMALL, OnDontmonsmall)
	ON_EN_CHANGE(IDC_SMALLSIZE, OnChangeSmallsize)
	ON_BN_CLICKED(IDC_MOZILLA, OnMozilla)
	ON_BN_CLICKED(IDC_SKIPLIST, OnSkiplist)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDownloaderProperties_MonitorPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();

	BOOL bIE2 = _IECatchMgr.IsIE2Active ();	
	
	CheckDlgButton (IDC_IE2, bIE2 ? BST_CHECKED : BST_UNCHECKED);
	CheckDlgButton (IDC_CLIPBOARD, _App.Monitor_Clipboard () ? BST_CHECKED : BST_UNCHECKED);

	BOOL bFF = _App.Monitor_Firefox () && vmsFirefoxMonitoring::IsInstalled () &&
		vmsFirefoxMonitoring::IsFlashGotInstalled () == false;
	CheckDlgButton (IDC_FIREFOX, bFF ? BST_CHECKED : BST_UNCHECKED);

	
	_IECMM.ReadState ();
	m_bIEMenuWas = _IECMM.IsIEMenusPresent ();
	CheckDlgButton (IDC_ADDTOIEMENU, 
		(m_bIEMenuWas || _App.Monitor_IEMenu_Enable ()) ? BST_CHECKED : BST_UNCHECKED);
	
	CheckDlgButton (IDC_ALTPRESSED, _App.Monitor_ALTShouldPressed () ? BST_CHECKED : BST_UNCHECKED);
	
	CheckDlgButton (IDC_ALLOWIETODL, _App.Monitor_AllowDownload () ? BST_CHECKED : BST_UNCHECKED);

	CheckDlgButton (IDC_OPERA, _NOMgr.getPluginInstaller (vmsKnownBrowsers::Opera).IsPluginInstalled () ? BST_CHECKED : BST_UNCHECKED);
	CheckDlgButton (IDC_NETSCAPE, _NOMgr.getPluginInstaller (vmsKnownBrowsers::Netscape).IsPluginInstalled () ? BST_CHECKED : BST_UNCHECKED);
	CheckDlgButton (IDC_MOZILLA,  _NOMgr.getPluginInstaller (vmsKnownBrowsers::MozillaSuite).IsPluginInstalled () ? BST_CHECKED : BST_UNCHECKED);

	CheckDlgButton (IDC_SILENT, _App.Monitor_Silent () ? BST_CHECKED : BST_UNCHECKED);

	int iSize = _App.Monitor_SkipSmaller ();
	CheckDlgButton (IDC_DONTMONSMALL, iSize == 0 ? BST_UNCHECKED : BST_CHECKED);
	SetDlgItemInt (IDC_SMALLSIZE, iSize ? iSize/1000 : 10);

	ApplyLanguage ();
	UpdateEnabled ();

	return TRUE;  
	              
}

BOOL CDownloaderProperties_MonitorPage::OnApply() 
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
		dwMUSO |= MONITOR_USERSWITCHEDON_FIREFOX;
	_App.Monitor_Firefox (bFF);
	if (bFF)
		vmsFirefoxMonitoring::Install (true); 

	
	if ((bIE2 == FALSE && bIE2Active) || (bIE2 && bIE2Active == FALSE))
	{
		if (bIE2 && _IECatchMgr.IsMonitoringDllRegistered () == FALSE)
		{
			if (_IECatchMgr.InstallIeIntegration (TRUE) == FALSE)
			{
				MessageBox (LS (L_ERRIE), LS (L_ERR), MB_ICONERROR);
				CheckDlgButton (IDC_IE2, bIE2Active ? BST_CHECKED : BST_UNCHECKED);
			}
			else
				bRR = TRUE;
		}
		else
		{
			_App.Monitor_IE2 (bIE2);
		}
	}
	if (bIE2)
		dwMUSO |= MONITOR_USERSWITCHEDON_IE;

	BOOL b = IsDlgButtonChecked (IDC_ADDTOIEMENU) == BST_CHECKED;
	if (b)
		_IECMM.AddIEMenus ();
	else
		_IECMM.DeleteIEMenus ();
	_App.Monitor_IEMenu_Enable (b);
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
	
	
	CString strOpDir = _App.Monitor_OperaPDInstalledTo ();
	CString strNDir = _App.Monitor_NetscapePDInstalledTo ();
	CString strMozDir = _App.Monitor_MozillaSuitePDInstalledTo ();

	
	if (IsDlgButtonChecked (IDC_OPERA) == BST_CHECKED)
	{
		dwMUSO |= MONITOR_USERSWITCHEDON_OPERA;

		
		if (_NOMgr.getPluginInstaller (vmsKnownBrowsers::Opera).IsPluginInstalled (TRUE) == FALSE)
		{
			if (FALSE == _NOMgr.getPluginInstaller (vmsKnownBrowsers::Opera).InstallPlugin ())
			{
				MessageBox (LS (L_CANTINITOPMONITOR), LS (L_ERR), MB_ICONERROR);
				CheckDlgButton (IDC_OPERA, BST_UNCHECKED);
			}
			else
				bRR = TRUE;
		}
	}
	else if (_NOMgr.getPluginInstaller (vmsKnownBrowsers::Opera).IsPluginInstalled (strOpDir.GetLength () != 0))
	{
		if (FALSE == _NOMgr.getPluginInstaller (vmsKnownBrowsers::Opera).DeinstallPlugin ())
		{
			MessageBox (LS (L_CANTDEINITOPMONITOR), LS (L_ERR), MB_ICONERROR);
			CheckDlgButton (IDC_OPERA, BST_CHECKED);
		}
		else
			bRR = TRUE;
	}

	

	if (IsDlgButtonChecked (IDC_NETSCAPE) == BST_CHECKED)
	{
		dwMUSO |= MONITOR_USERSWITCHEDON_NETSCAPE;

		if (_NOMgr.getPluginInstaller (vmsKnownBrowsers::Netscape).IsPluginInstalled (TRUE) == FALSE)
		{
			if (FALSE == _NOMgr.getPluginInstaller (vmsKnownBrowsers::Netscape).InstallPlugin ())
			{
				MessageBox (LS (L_CANTINITNETMONITOR), LS (L_ERR), MB_ICONERROR);
				CheckDlgButton (IDC_NETSCAPE, BST_UNCHECKED);
			}
			else
				bRR = TRUE;
		}
	}
	else if (_NOMgr.getPluginInstaller (vmsKnownBrowsers::Netscape).IsPluginInstalled (strNDir.GetLength () != 0))
	{
		if (FALSE == _NOMgr.getPluginInstaller (vmsKnownBrowsers::Netscape).DeinstallPlugin ())
		{
			MessageBox (LS (L_CANTDEINITNETMONITOR), LS (L_ERR), MB_ICONERROR);
			CheckDlgButton (IDC_NETSCAPE, BST_CHECKED);
		}
		else
			bRR = TRUE;
	}

	

	if (IsDlgButtonChecked (IDC_MOZILLA) == BST_CHECKED)
	{
		dwMUSO |= MONITOR_USERSWITCHEDON_SEAMONKEY;

		if (_NOMgr.getPluginInstaller (vmsKnownBrowsers::MozillaSuite).IsPluginInstalled (TRUE) == FALSE)
		{
			if (FALSE == _NOMgr.getPluginInstaller (vmsKnownBrowsers::MozillaSuite).InstallPlugin ())
			{
				MessageBox (LS (L_CANTINITMOZMONITOR), LS (L_ERR), MB_ICONERROR);
				CheckDlgButton (IDC_MOZILLA, BST_UNCHECKED);
			}
			else
				bRR = TRUE;
		}
	}
	else if (_NOMgr.getPluginInstaller (vmsKnownBrowsers::MozillaSuite).IsPluginInstalled (strMozDir.GetLength () != 0))
	{
		if (FALSE == _NOMgr.getPluginInstaller (vmsKnownBrowsers::MozillaSuite).DeinstallPlugin ())
		{
			MessageBox (LS (L_CANTDEINITMOZMONITOR), LS (L_ERR), MB_ICONERROR);
			CheckDlgButton (IDC_MOZILLA, BST_CHECKED);
		}
		else
			bRR = TRUE;
	}

	_App.Monitor_UserSwitchedOn (dwMUSO);

	_App.Monitor_Silent (IsDlgButtonChecked (IDC_SILENT) == BST_CHECKED);
	int iSize = 0;
	if (IsDlgButtonChecked (IDC_DONTMONSMALL) == BST_CHECKED)
		iSize = GetDlgItemInt (IDC_SMALLSIZE);
	_App.Monitor_SkipSmaller (iSize*1000);

	if (bRR)
		MessageBox (LS (L_BROWSERRESTARTREQ));

	UpdateEnabled ();
	
	return CPropertyPage::OnApply();
}

void CDownloaderProperties_MonitorPage::OnContextMenu(CWnd* , CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();
}

void CDownloaderProperties_MonitorPage::OnWhatisthis() 
{
	_CHMgr.OnWT ();	
}

void CDownloaderProperties_MonitorPage::OnClipboard() 
{
	SetModified ();	
	UpdateEnabled ();
}

void CDownloaderProperties_MonitorPage::OnAltpressed() 
{
	SetModified ();	
}

void CDownloaderProperties_MonitorPage::ApplyLanguage()
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

void CDownloaderProperties_MonitorPage::OnAddtoiemenu() 
{
	SetModified ();	
	UpdateEnabled ();
}

void CDownloaderProperties_MonitorPage::OnOpera() 
{
	SetModified ();	
}

void CDownloaderProperties_MonitorPage::OnNetscape() 
{
	SetModified ();	
}

void CDownloaderProperties_MonitorPage::PrepareCHMgr(CPoint point)
{
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC_ADDTOIEMENU, LS (L_ADDTOBRMENUHERE)),
		fsCtrlContextHelp (IDC_CLIPBOARD, LS (L_CLIPBOARDHERE)),
		fsCtrlContextHelp (IDC_ALTPRESSED, LS (L_ALTSHOULDHERE)),
		fsCtrlContextHelp (IDC_OPERA, LS (L_OPERAHERE)),
		fsCtrlContextHelp (IDC_NETSCAPE, LS (L_NETSCAPEHERE)),
		fsCtrlContextHelp (IDC_FIREFOX, LS (L_FIREFOXHERE2)),
		fsCtrlContextHelp (IDC_IE2, LS (L_IEXPLOREHERE)),
		fsCtrlContextHelp (IDC_ALLOWIETODL, LS (L_ALLOWBRDLHERE)),
		fsCtrlContextHelp (IDC_SILENT, LS (L_SILENTMONITORINGHERE)),
		fsCtrlContextHelp (IDC_CUSTOMIZE, LS (L_CUSTOMIZEBRMENUHERE)),
		fsCtrlContextHelp (IDC_DONTMONSMALL, LS (L_DONTMONSMALLHERE)),
		fsCtrlContextHelp (IDC_MOZILLA, LS (L_SEAMONKEYHERE)),
		fsCtrlContextHelp (IDC_SKIPLIST, LS (L_SKIPLIST_HERE)),
	};

    static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));
}

BOOL CDownloaderProperties_MonitorPage::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	RECT rc;
	CWnd *pItem = GetDlgItem (pHelpInfo->iCtrlId);
	if (pItem == NULL)
		return TRUE;
	pItem->GetWindowRect (&rc);
	if (PtInRect (&rc, pHelpInfo->MousePos) == FALSE)
	{
		pHelpInfo->MousePos.x = rc.left + (rc.right - rc.left) / 2;
		pHelpInfo->MousePos.y = rc.top + (rc.bottom - rc.top) / 2;
	}
	PrepareCHMgr (pHelpInfo->MousePos);
	_CHMgr.OnWT ();
	return TRUE;
}

void CDownloaderProperties_MonitorPage::OnIe2() 
{
	SetModified ();	
	UpdateEnabled ();
}

void CDownloaderProperties_MonitorPage::UpdateEnabled()
{
	BOOL bIE = IsDlgButtonChecked (IDC_IE2) == BST_CHECKED ||
		IsDlgButtonChecked (IDC_FIREFOX) == BST_CHECKED;
	
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

void CDownloaderProperties_MonitorPage::OnAllowietodl() 
{
	SetModified ();
}

void CDownloaderProperties_MonitorPage::OnFirefox() 
{
	UpdateEnabled ();
	SetModified ();
}

void CDownloaderProperties_MonitorPage::OnSilent() 
{
	SetModified ();	
}

void CDownloaderProperties_MonitorPage::OnCustomize() 
{
	CDlgCustomizeIEMenu dlg;
	_DlgMgr.DoModal (&dlg);
}

void CDownloaderProperties_MonitorPage::OnDontmonsmall() 
{
	SetModified ();
	UpdateEnabled ();
}

void CDownloaderProperties_MonitorPage::OnChangeSmallsize() 
{
	SetModified ();
}

void CDownloaderProperties_MonitorPage::OnMozilla() 
{
	SetModified ();	
}

void CDownloaderProperties_MonitorPage::OnSkiplist() 
{
	CDownloaderProperties_MonitorPage_SkipList dlg;
	_DlgMgr.DoModal (&dlg);
}
