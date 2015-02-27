/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fdm.h"
#include "Dlg_Options_Downloads.h"
#include "vmsRegisteredApp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlg_Options_Downloads::CDlg_Options_Downloads(CWnd* pParent )
	: CDlg_Options_Page(CDlg_Options_Downloads::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_Options_Downloads)
		
	//}}AFX_DATA_INIT
}

void CDlg_Options_Downloads::DoDataExchange(CDataExchange* pDX)
{
	CDlg_Options_Page::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_Options_Downloads)
	DDX_Control(pDX, IDC_VIRNAME, m_wndVirName);
	DDX_Control(pDX, IDC_WHENDEL, m_wndWhenDel);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlg_Options_Downloads, CDlg_Options_Page)
	//{{AFX_MSG_MAP(CDlg_Options_Downloads)
	ON_BN_CLICKED(IDC_VIRCHECK, OnVircheck)
	ON_BN_CLICKED(IDC_CHOOSEVIR, OnChoosevir)
	ON_BN_CLICKED(IDC_USEWC, OnUsewc)
	ON_CBN_SELCHANGE(IDC_VIRNAME, OnSelchangeVirname)
	ON_BN_CLICKED(IDC_CHECKIFMAL2, OnCheckifmal2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlg_Options_Downloads::OnInitDialog() 
{
	CDlg_Options_Page::OnInitDialog();
	
	CSpinButtonCtrl *pSpin = (CSpinButtonCtrl*) GetDlgItem (IDC_WC_SPIN);
	pSpin->SetRange (1, UD_MAXVAL);
	
	
	m_wndWhenDel.AddString (LS (L_ASK));			
	m_wndWhenDel.AddString (LS (L_DONTDELFILE));	
	m_wndWhenDel.AddString (LS (L_DELFILE));		
	
	m_wndWhenDel.SetCurSel (_DldsMgr.m_enDDR);	
	
	CheckDlgButton (IDC_DONTSAVELOGS, _App.DontSaveLogs () ? BST_CHECKED : BST_UNCHECKED);
	
	CheckDlgButton (IDC_AUTODEL, _DldsMgr.m_bAutoDelCompleted ? BST_CHECKED : BST_UNCHECKED);
	CheckDlgButton (IDC_DETAILEDLOG, _DldsMgr.m_bDetLog ? BST_CHECKED : BST_UNCHECKED);
	
	CheckDlgButton (IDC_SIZEINBYTES, _pwndDownloads->m_wndDownloads.m_tasks.m_bSizesInBytes ? BST_CHECKED : BST_UNCHECKED);
	
	AvirToDlg ();
	
	CheckDlgButton (IDC_SHOWDLDDLG, _App.DownloadDialog_Use () ? BST_CHECKED : BST_UNCHECKED);
	
	DWORD dw = _App.FileWriteCacheSize () / 1024 / 1024;
	CheckDlgButton (IDC_USEWC, dw ? BST_CHECKED : BST_UNCHECKED);
	SetDlgItemInt (IDC_WC_SIZE, dw ? dw : 1, FALSE);
	
	CheckDlgButton (IDC_PREVENT_STANDBY, _App.PreventStandbyWhileDownloading () ? BST_CHECKED : BST_UNCHECKED);

	CheckDlgButton (IDC_SWITCHTOOPINIONS2, _App.Community_SwitchToOpinions () ? BST_CHECKED : BST_UNCHECKED);
	CheckDlgButton (IDC_CHECKIFMAL2, _App.Community_CheckIfMalBeforeDlding () ? BST_CHECKED : BST_UNCHECKED);
	CheckDlgButton (IDC_DISPLAYOPINIONS2, _App.Community_DisplayOpinionsAtDlding () ? BST_CHECKED : BST_UNCHECKED);
	
	SetDlgItemInt (IDC_MALREPSMINIMUM2, _App.Community_MalReportsMinPerc ());

	
	
	ApplyLanguage ();
	UpdateEnabled ();
	
	return TRUE;  
	              
}

CString CDlg_Options_Downloads::get_PageTitle()
{
	return LS (L_ESSENTIAL);
}

CString CDlg_Options_Downloads::get_PageShortTitle()
{
	return LS (L_ESSENTIAL);
}

BOOL CDlg_Options_Downloads::Apply()
{
	if (FALSE == DlgToVir ())
		return FALSE;
	
	_DldsMgr.m_enDDR = (fsDeleteDownloadReaction) m_wndWhenDel.GetCurSel ();
	_DldsMgr.m_bAutoDelCompleted = IsDlgButtonChecked (IDC_AUTODEL) == BST_CHECKED;
	_DldsMgr.UseDetailedLog (IsDlgButtonChecked (IDC_DETAILEDLOG) == BST_CHECKED);
	BOOL bSIB = IsDlgButtonChecked (IDC_SIZEINBYTES) == BST_CHECKED;
	if (bSIB != _pwndDownloads->m_wndDownloads.m_tasks.m_bSizesInBytes)
	{
		_pwndDownloads->m_wndDownloads.m_tasks.m_bSizesInBytes = bSIB;
		_pwndDownloads->m_wndDownloads.m_tasks.OnForceUpdate ();
		_pwndDownloads->m_wndDownloads.m_info.m_bt.UpdateStat ();
	}
	
	_App.DontSaveLogs (IsDlgButtonChecked (IDC_DONTSAVELOGS) == BST_CHECKED);
	
	BOOL bShow = IsDlgButtonChecked (IDC_SHOWDLDDLG) == BST_CHECKED;
	if (!bShow !=  !_App.DownloadDialog_Use ())
	{
		_App.DownloadDialog_Use (bShow);
		if (bShow)
			_App.DownloadDialog_DontAskOnHide (FALSE);
	}
	
	DWORD dw = 0;
	if (IsDlgButtonChecked (IDC_USEWC) == BST_CHECKED)
		dw = GetDlgItemInt (IDC_WC_SIZE, NULL, FALSE) * 1024 * 1024;
	_App.FileWriteCacheSize (dw);
	
	_App.PreventStandbyWhileDownloading (IsDlgButtonChecked (IDC_PREVENT_STANDBY) == BST_CHECKED);

	_App.Community_SwitchToOpinions (IsDlgButtonChecked (IDC_SWITCHTOOPINIONS2) == BST_CHECKED);
	_App.Community_DisplayOpinionsAtDlding (IsDlgButtonChecked (IDC_DISPLAYOPINIONS2) == BST_CHECKED);
	BOOL b = IsDlgButtonChecked (IDC_CHECKIFMAL2) == BST_CHECKED;
	_App.Community_CheckIfMalBeforeDlding (b);
	if (b)
		_App.Community_MalReportsMinPerc (GetDlgItemInt (IDC_MALREPSMINIMUM2));

	return TRUE;
}

void CDlg_Options_Downloads::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__LISTOFDLDS, L_LISTOFDLDS),
			fsDlgLngInfo (IDC__WHENDEL, L_WHENDEL),
			fsDlgLngInfo (IDC_AUTODEL, L_AUTODEL),
			fsDlgLngInfo (IDC_DETAILEDLOG, L_DETAILEDLOG),
			fsDlgLngInfo (IDC_SIZEINBYTES, L_SHOWSIZESINBYTES),
			fsDlgLngInfo (IDC_VIRCHECK, L_PERFVIRCHECK),
			fsDlgLngInfo (IDC__ARGS, L_DLGARGUMENTS),
			fsDlgLngInfo (IDC__EXTS, L_DLGEXTS),
			fsDlgLngInfo (IDC_DONTSAVELOGS, L_DONTSAVELOGS),
			fsDlgLngInfo (IDC_SHOWDLDDLG, L_SHOWDLDDLG),
			fsDlgLngInfo (IDC_USEWC, L_USEWRITECACHE),
			fsDlgLngInfo (IDC__WC_MB, L_MB),
			fsDlgLngInfo (IDC_PREVENT_STANDBY, L_PREVENT_STANDBY_WHILE_DLDING),

			fsDlgLngInfo (IDC__FDM_COMMUNITY, L_FDMCOMMUNITY),
			fsDlgLngInfo (IDC_SWITCHTOOPINIONS2, L_SWITCHTOOPINIONS),
			fsDlgLngInfo (IDC_CHECKIFMAL2, L_CHECKNEWDLDIFITISMALICIOUS),
			fsDlgLngInfo (IDC_DISPLAYOPINIONS2, L_DISPLAYOPINIONSWHENDOWNLOADING),
			fsDlgLngInfo (IDC__S0, L_CONSIDER_DLD_AS_MAL_IF_MIN_0),
			fsDlgLngInfo (IDC__S1, L_CONSIDER_DLD_AS_MAL_IF_MIN_1),
	};
	
	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}

void CDlg_Options_Downloads::UpdateEnabled()
{
	BOOL b = IsDlgButtonChecked (IDC_VIRCHECK) == BST_CHECKED;
	UINT aIDs [] = {IDC__EXTS, IDC_VIREXTS};
	
	int i = 0;
	for (i = 0; i < sizeof (aIDs) / sizeof (UINT); i++)
		GetDlgItem (aIDs [i])->EnableWindow (b);
	
	b = IsDlgButtonChecked (IDC_USEWC) == BST_CHECKED;
	UINT aIDs2 [] = {IDC_WC_SIZE, IDC_WC_SPIN, IDC__WC_MB};
	for (i = 0; i < sizeof (aIDs2) / sizeof (UINT); i++)
		GetDlgItem (aIDs2 [i])->EnableWindow (b);

	b = IsDlgButtonChecked (IDC_CHECKIFMAL2) == BST_CHECKED;
	GetDlgItem (IDC__S0)->EnableWindow (b);
	GetDlgItem (IDC__S1)->EnableWindow (b);
	GetDlgItem (IDC_MALREPSMINIMUM2)->EnableWindow (b);
}

LPCSTR _ppszAvirs [] = {
	
	"ashQuick.exe",
	"avgw.exe",
	"avscan.exe",
	"kav.exe",
	"avp32.exe",
	"drweb32w.exe",
	"wfindv32.exe",
	"clamwin.exe",
	"f-prot.exe",
	"ibmasn.exe",
	"ibmavsp.exe",
	"im.exe",
	"scan95.exe",
	"scan32.exe",
	"scan.exe",
	"nod32.exe",
	"navw32.exe",
	"n32scan.exe",
	"n32scanw.exe",
	"navwnt.exe",
	"stop.exe",
};

LPCSTR _ppszAvirsPathes [] = {
	"Alwil Software\\Avast4",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
};

LPCSTR _ppszAvirArgs [] = {
	"%file%",
	"/SE %file%",
	"/GUIMODE=1 /PATH=%file%",
	"%file% /silent /wait /minimize",
	"%file% /s /n /q",
	"%file% /AR /UP /QU /FM /HA",
	"%file%",
	"--mode=scanner --path=%file% --close",
	"/NOBOOT /NOMEM /LIST %file%",
	"-nlog -nmbr %file%",
	"-nlog -nmbr %file%",
	"/N /UN /B /VL /CF=%file%",
	"%file% /autoscan /nosplash",
	"%file% /autoscan /nosplash",
	"/nomem /all %file%",
	"%file% /quit+ /arch+ /pack+ /adware /prompt",
	"%file% /s",
	"%file% /s",
	"%file% /s",
	"%file% /s",
	"/NOAUTO /UPDATE /QUITAFTERSCAN %file%",
};

LPCSTR _ppszAvirNames [] = {
	"avast! Antivirus (\"ashQuick.exe\")",
	"AVG Free Antivirus",
	"Avira",
	"AVP, Kapersky Antivirus (\"kav.exe\")",
	"AVP, Kapersky Antivirus (\"avp32.exe\")",
	"DrWeb for Windows",
	"Dr. Solomon's FindVirus",
	"Clamwin",
	"F-secure",
	"IBM Antivirus (\"ibmasn.exe\")",
	"IBM Antivirus (\"ibmavsp.exe\")",
	"Integrity Master",
	"McAfee Virus Scan (\"scan95.exe\")",
	"McAfee Virus Scan (\"scan32.exe\")",
	"McAfee Virus Scan (\"scan.exe\")",
	"NOD32",
	"Norton Antivirus (\"navw32.exe\")",
	"Norton Antivirus (\"n32scan.exe\")",
	"Norton Antivirus (\"n32scanw.exe\")",
	"Norton Antivirus (\"navwnt.exe\")",
	"Stop!",
};

void CDlg_Options_Downloads::AvirToDlg()
{
	CheckDlgButton (IDC_VIRCHECK, _DldsMgr.m_bVirCheck ? BST_CHECKED : BST_UNCHECKED);
	
	CString strVirName = _DldsMgr.m_strVirName;
	
	
	int i = 0;
	for (i = 0; i < sizeof (_ppszAvirNames) / sizeof (LPCSTR); i++)
		m_wndVirName.AddString (_ppszAvirNames [i]);
	
	m_wndVirName.SetWindowText (_DldsMgr.m_strVirName);	
	
	for (i = 0; i < sizeof (_ppszAvirs) / sizeof (LPCSTR); i++)
	{
		if (strVirName.CompareNoCase (_ppszAvirs [i]) == 0)
		{
			m_wndVirName.SetCurSel (i);	
			break;
		}
	}
	
	GetDlgItem (IDC_ARGS)->SetWindowText (_DldsMgr.m_strVirArgs);
	GetDlgItem (IDC_VIREXTS)->SetWindowText (_DldsMgr.m_strVirExts);
}

void CDlg_Options_Downloads::OnVircheck() 
{
	UpdateEnabled ();	
}

BOOL CDlg_Options_Downloads::DlgToVir()
{
	CString strVir, strVirPath;
	m_wndVirName.GetWindowText (strVir);

	BOOL bVirCheck = IsDlgButtonChecked (IDC_VIRCHECK) == BST_CHECKED;

	if (strVir == "")
	{
		if (bVirCheck)
		{
			MessageBox (LS (L_ENTERAVIRNAME), LS (L_INPERR), MB_ICONEXCLAMATION);
			m_wndVirName.SetFocus ();
			return FALSE;
		}

		_DldsMgr.m_bVirCheck = FALSE;
		_DldsMgr.m_strVirName = "";
		return TRUE;
	}

	BOOL bPredefined = FALSE;

	
	for (int i = 0; i < sizeof (_ppszAvirNames) / sizeof (LPCSTR); i++)
	{
		if (strVir.CompareNoCase (_ppszAvirNames [i]) == 0)
		{
			strVir = _ppszAvirs [i];	
			strVirPath = _ppszAvirsPathes [i];
			bPredefined = TRUE;
			break;
		}
	}

	
	if (bPredefined)
	{
		bool bFound = false;
		

		bFound = DWORD (-1) != GetFileAttributes (vmsRegisteredApp::GetFullPath (strVir));

		if (bFound == false && strVirPath.IsEmpty () == FALSE)
		{
			LPITEMIDLIST pidl = NULL;
			if (SUCCEEDED (SHGetSpecialFolderLocation (NULL, CSIDL_PROGRAM_FILES, &pidl)))
			{
				char sz [MY_MAX_PATH];
				SHGetPathFromIDList (pidl, sz);
				if (sz [lstrlen (sz)-1] != '\\')
					lstrcat (sz, "\\");
				IMallocPtr spMalloc;
				SHGetMalloc (&spMalloc);
				spMalloc->Free (pidl);
				lstrcat (sz, strVirPath);
				lstrcat (sz, "\\");
				lstrcat (sz, strVir);
				if (GetFileAttributes (sz) != DWORD (-1))
				{
					strVir = sz;
					bFound = true;
				}
			}
		}
		
		if (bFound == false) {
			MessageBox (LS (L_FAILEDTOFOUNDTHISAVIRTRYSPECIFYMANUALLY), LS (L_INPERR), MB_ICONEXCLAMATION);
			PostMessage (WM_COMMAND, IDC_CHOOSEVIR);
			return FALSE;
		}
	}
	else if (GetFileAttributes (strVir) == DWORD (-1))
	{
		MessageBox (LS (L_NAMEISINVALID), LS (L_INPERR), MB_ICONEXCLAMATION);
		m_wndVirName.SetFocus ();
		return FALSE;
	}

	CString strArgs, strExts;
	GetDlgItemText (IDC_ARGS, strArgs);
	GetDlgItemText (IDC_VIREXTS, strExts);

	if (strArgs.Find ("%file%", 0) == -1)
	{
		CString str = LS (L_ARGSHAVNTFILEMACRO);
		str += "\n\n"; str += LS (L_CONTINUEANYWAY);
		if (IDNO == MessageBox (str, LS (L_WARNING), MB_ICONEXCLAMATION | MB_YESNO))
		{
			GetDlgItem (IDC_ARGS)->SetFocus ();
			return FALSE;
		}
	}

	if (strExts == "" && bVirCheck)
	{
		MessageBox (LS (L_ENTEREXTS), LS (L_INPERR), MB_ICONEXCLAMATION);
		GetDlgItem (IDC_VIREXTS)->SetFocus ();
		return FALSE;
	}

	_DldsMgr.m_bVirCheck = TRUE;
	_DldsMgr.m_strVirName = strVir;
	_DldsMgr.m_strVirArgs = strArgs;
	_DldsMgr.m_strVirExts = strExts;

	_DldsMgr.m_bVirCheck = bVirCheck;

	return TRUE;
}

void CDlg_Options_Downloads::OnChoosevir() 
{
	CString strFilter;
	strFilter.Format ("%s (*.exe, *.com)|*.exe;*.com||", LS (L_APPLICATIONS));
	
	CFileDialog dlg (TRUE, "exe", NULL, OFN_HIDEREADONLY|OFN_NOCHANGEDIR, strFilter, this);
	if (_DlgMgr.DoModal (&dlg) != IDOK)
		return;
	m_wndVirName.SetWindowText (dlg.GetPathName ());	
}

void CDlg_Options_Downloads::OnUsewc() 
{
	UpdateEnabled ();	
}

void CDlg_Options_Downloads::OnSelchangeVirname() 
{
	SetDlgItemText (IDC_ARGS, _ppszAvirArgs [m_wndVirName.GetCurSel ()]);	
}

void CDlg_Options_Downloads::OnCheckifmal2() 
{
	UpdateEnabled ();	
}
