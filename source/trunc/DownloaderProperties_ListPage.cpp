/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "DownloaderProperties_ListPage.h"
#include "DownloadsWnd.h"
#include "vmsRegisteredApp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CDownloadsWnd* _pwndDownloads;

IMPLEMENT_DYNCREATE(CDownloaderProperties_ListPage, CPropertyPage)

CDownloaderProperties_ListPage::CDownloaderProperties_ListPage() : CPropertyPage(CDownloaderProperties_ListPage::IDD)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = LS (L_ALLDLDS);
}

CDownloaderProperties_ListPage::~CDownloaderProperties_ListPage()
{
}

void CDownloaderProperties_ListPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDownloaderProperties_ListPage)
	DDX_Control(pDX, IDC_VIRNAME, m_wndVirName);
	DDX_Control(pDX, IDC_WHENDEL, m_wndWhenDel);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDownloaderProperties_ListPage, CPropertyPage)
	//{{AFX_MSG_MAP(CDownloaderProperties_ListPage)
	ON_CBN_SELCHANGE(IDC_WHENDEL, OnSelchangeWhendel)
	ON_BN_CLICKED(IDC_AUTODEL, OnAutodel)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	ON_WM_HELPINFO()
	ON_BN_CLICKED(IDC_DETAILEDLOG, OnDetailedlog)
	ON_BN_CLICKED(IDC_SIZEINBYTES, OnSizeinbytes)
	ON_BN_CLICKED(IDC_VIRCHECK, OnVircheck)
	ON_CBN_SELCHANGE(IDC_VIRNAME, OnSelchangeVirname)
	ON_CBN_EDITCHANGE(IDC_VIRNAME, OnEditchangeVirname)
	ON_EN_CHANGE(IDC_ARGS, OnChangeArgs)
	ON_EN_CHANGE(IDC_VIREXTS, OnChangeVirexts)
	ON_BN_CLICKED(IDC_CHOOSEVIR, OnChoosevir)
	ON_BN_CLICKED(IDC_SHOWDLDDLG, OnShowdlddlg)
	ON_BN_CLICKED(IDC_DONTSAVELOGS, OnDontsavelogs)
	ON_BN_CLICKED(IDC_USEWC, OnUsewc)
	ON_EN_CHANGE(IDC_WC_SIZE, OnChangeWcSize)
	ON_BN_CLICKED(IDC_PREVENT_STANDBY, OnPreventStandby)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDownloaderProperties_ListPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
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

	ApplyLanguage ();

	UpdateEnabled ();
	
	return TRUE;  
	              
}

void CDownloaderProperties_ListPage::OnSelchangeWhendel() 
{
	SetModified ();	
}

void CDownloaderProperties_ListPage::OnAutodel() 
{
	SetModified ();	
}

BOOL CDownloaderProperties_ListPage::OnApply() 
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
	
	return CPropertyPage::OnApply();
}

void CDownloaderProperties_ListPage::OnContextMenu(CWnd* , CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();
}

void CDownloaderProperties_ListPage::OnWhatisthis() 
{
	_CHMgr.OnWT ();	
}

void CDownloaderProperties_ListPage::ApplyLanguage()
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
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}

BOOL CDownloaderProperties_ListPage::OnHelpInfo(HELPINFO* pHelpInfo) 
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

void CDownloaderProperties_ListPage::PrepareCHMgr(CPoint point)
{
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC__WHENDEL, LS (L_WHENDELHERE)),
		fsCtrlContextHelp (IDC_WHENDEL, LS (L_WHENDELHERE)),
		fsCtrlContextHelp (IDC_AUTODEL, LS (L_AUTODELHERE)),
		fsCtrlContextHelp (IDC_DETAILEDLOG, LS (L_DETAILEDLOGHERE)),
		fsCtrlContextHelp (IDC_SIZEINBYTES, LS (L_SIZEINBYTESHERE)),
		fsCtrlContextHelp (IDC_VIRCHECK, LS (L_VIRCHECKHERE)),
		fsCtrlContextHelp (IDC_VIRNAME, LS (L_VIRNAMEHERE)),
		fsCtrlContextHelp (IDC__ARGS, LS (L_VIRARGSHERE)),
		fsCtrlContextHelp (IDC_ARGS, LS (L_VIRARGSHERE)),
		fsCtrlContextHelp (IDC__EXTS, LS (L_VIREXTSHERE)),
		fsCtrlContextHelp (IDC_VIREXTS, LS (L_VIREXTSHERE)),
		fsCtrlContextHelp (IDC_DONTSAVELOGS, LS (L_DONTSAVELOGS_HERE)),
		fsCtrlContextHelp (IDC_SHOWDLDDLG, LS (L_SHOWDLDDLG_HERE)),
		fsCtrlContextHelp (IDC_USEWC, LS (L_USEWRITECACHE_HERE)),
		fsCtrlContextHelp (IDC_WC_SIZE, LS (L_USEWRITECACHE_HERE)),
		fsCtrlContextHelp (IDC__WC_MB, LS (L_USEWRITECACHE_HERE)),
	};

    static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));
}

void CDownloaderProperties_ListPage::OnDetailedlog() 
{
	SetModified ();	
}

void CDownloaderProperties_ListPage::OnSizeinbytes() 
{
	SetModified ();	
}

void CDownloaderProperties_ListPage::OnVircheck() 
{
	SetModified ();
	UpdateEnabled ();
}

LPCSTR _ppszAvirs2 [] = {
	
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

LPCSTR _ppszAvirArgs2 [] = {
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

LPCSTR _ppszAvirNames2 [] = {
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

void CDownloaderProperties_ListPage::OnSelchangeVirname() 
{
	SetDlgItemText (IDC_ARGS, _ppszAvirArgs2 [m_wndVirName.GetCurSel ()]);
	SetModified ();	
}

void CDownloaderProperties_ListPage::OnEditchangeVirname() 
{
	SetModified ();	
}

void CDownloaderProperties_ListPage::OnChangeArgs() 
{
	SetModified ();
}

void CDownloaderProperties_ListPage::OnChangeVirexts() 
{
	SetModified ();
}

void CDownloaderProperties_ListPage::UpdateEnabled()
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
}

void CDownloaderProperties_ListPage::AvirToDlg()
{
	CheckDlgButton (IDC_VIRCHECK, _DldsMgr.m_bVirCheck ? BST_CHECKED : BST_UNCHECKED);

	CString strVirName = _DldsMgr.m_strVirName;

	
	int i = 0;
	for (i = 0; i < sizeof (_ppszAvirNames2) / sizeof (LPCSTR); i++)
		m_wndVirName.AddString (_ppszAvirNames2 [i]);

	m_wndVirName.SetWindowText (_DldsMgr.m_strVirName);	
	
	for (i = 0; i < sizeof (_ppszAvirs2) / sizeof (LPCSTR); i++)
	{
		if (strVirName.CompareNoCase (_ppszAvirs2 [i]) == 0)
		{
			m_wndVirName.SetCurSel (i);	
			break;
		}
	}

	GetDlgItem (IDC_ARGS)->SetWindowText (_DldsMgr.m_strVirArgs);
	GetDlgItem (IDC_VIREXTS)->SetWindowText (_DldsMgr.m_strVirExts);
}

BOOL CDownloaderProperties_ListPage::DlgToVir()
{
	CString strVir;
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

	
	for (int i = 0; i < sizeof (_ppszAvirNames2) / sizeof (LPCSTR); i++)
	{
		if (strVir.CompareNoCase (_ppszAvirNames2 [i]) == 0)
		{
			strVir = _ppszAvirs2 [i];	
			bPredefined = TRUE;
			break;
		}
	}

	
	if (bPredefined)
	{
		bool bFound = false;
		

		bFound = DWORD (-1) != GetFileAttributes (vmsRegisteredApp::GetFullPath (strVir));
		

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

void CDownloaderProperties_ListPage::OnChoosevir() 
{
	CString strFilter;
        strFilter.Format ("%s (*.exe, *.com)|*.exe;*.com||", LS (L_APPLICATIONS));

	CFileDialog dlg (TRUE, "exe", NULL, OFN_HIDEREADONLY|OFN_NOCHANGEDIR, strFilter, this);
	if (_DlgMgr.DoModal (&dlg) != IDOK)
		return;
	m_wndVirName.SetWindowText (dlg.GetPathName ());
	SetModified ();
}

void CDownloaderProperties_ListPage::OnShowdlddlg() 
{
	SetModified ();	
}

void CDownloaderProperties_ListPage::OnDontsavelogs() 
{
	SetModified ();	
}

void CDownloaderProperties_ListPage::OnUsewc() 
{
	UpdateEnabled ();
	SetModified ();
}

void CDownloaderProperties_ListPage::OnChangeWcSize() 
{
	SetModified ();
}

void CDownloaderProperties_ListPage::OnPreventStandby() 
{
	SetModified ();	
}
