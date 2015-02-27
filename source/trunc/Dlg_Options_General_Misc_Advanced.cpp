/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fdm.h"
#include "Dlg_Options_General_Misc_Advanced.h"
#include "FolderBrowser.h"
#include "mfchelp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlg_Options_General_Misc_Advanced::CDlg_Options_General_Misc_Advanced(CWnd* pParent )
	: CDlg_Options_Page(CDlg_Options_General_Misc_Advanced::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_Options_General_Misc_Advanced)
		
	//}}AFX_DATA_INIT
}

void CDlg_Options_General_Misc_Advanced::DoDataExchange(CDataExchange* pDX)
{
	CDlg_Options_Page::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_Options_General_Misc_Advanced)
		
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlg_Options_General_Misc_Advanced, CDlg_Options_Page)
	//{{AFX_MSG_MAP(CDlg_Options_General_Misc_Advanced)
	ON_BN_CLICKED(IDC_KEEP_1, OnKeep1)
	ON_BN_CLICKED(IDC_KEEP_2, OnKeep2)
	ON_BN_CLICKED(IDC_BROWSE, OnBrowse)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlg_Options_General_Misc_Advanced::OnInitDialog() 
{
	CDlg_Options_Page::OnInitDialog();
	
	CSpinButtonCtrl *pSpin = (CSpinButtonCtrl*) GetDlgItem (IDC_AUTOSAVESPIN);
	pSpin->SetRange (1, UD_MAXVAL);
	SetDlgItemInt (IDC_AUTOSAVE, _App.AutosaveInterval () / 60 / 1000, FALSE);
	
	ApplyLanguage ();
	
	CString str = _App.DataFolder ();
	if (str.IsEmpty ())
	{
		CheckDlgButton (IDC_KEEP_1, BST_CHECKED);
	}
	else
	{
		CheckDlgButton (IDC_KEEP_2, BST_CHECKED);
		SetDlgItemText (IDC_FOLDER, str);
	}
	
	UpdateEnabled ();
	
	return TRUE;  
	              
}

CString CDlg_Options_General_Misc_Advanced::get_PageTitle()
{
	return LS (L_ADVANCED);
}

CString CDlg_Options_General_Misc_Advanced::get_PageShortTitle()
{
	return LS (L_ADVANCED);
}

BOOL CDlg_Options_General_Misc_Advanced::Apply()
{
	UINT nVal;
	
	nVal = GetDlgItemInt (IDC_AUTOSAVE, NULL, FALSE);
	
	
	if (nVal == 0)
	{
		
		CString str; str.Format (LS (L_ENTERGREATER), 0);
		MessageBox (str, LS (L_INPERR), MB_ICONEXCLAMATION);
		CEdit *pE = (CEdit*) GetDlgItem (IDC_AUTOSAVE);
		pE->SetSel (0, -1);
		pE->SetFocus ();
		return FALSE;
	}
	
	_App.AutosaveInterval (nVal * 60 * 1000);
	
	CString strOldVal = _App.DataFolder ();
	CString str;
	if (IsDlgButtonChecked (IDC_KEEP_2) == BST_CHECKED)
		GetDlgItemText (IDC_FOLDER, str);
	if (strOldVal != str)
	{
		_App.DataFolder (str);
		
		CRegKey key;
		if (ERROR_SUCCESS != key.Create (HKEY_CURRENT_USER, "Software\\FreeDownloadManager.ORG\\Free Upload Manager"))
			key.Open (HKEY_CURRENT_USER, "Software\\FreeDownloadManager.ORG\\Free Upload Manager");
		
		key.SetValue (fsGetAppDataFolder (), "force_data_folder");
		
		if (IDYES == MessageBox (LS (L_COPYDATAFILESNOW), NULL, MB_YESNO))
		{
			vmsCopyFiles (fsGetAppDataFolder (), _App.DataFolder (), "*.sav");
			extern bool _bNeedRecalcAppDataFolder;
			_bNeedRecalcAppDataFolder = true;
		}
		else
		{
			MessageBox (LS (L_RESTARTISREQ));
		}
	}
	
	return TRUE;
}

void CDlg_Options_General_Misc_Advanced::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__SERVICE_FILES, L_IT_IS_SERVICE_FILES),
		fsDlgLngInfo (IDC_KEEP_1, L_KEEPDATAINUSERSFOLDER),
		fsDlgLngInfo (IDC_KEEP_2, L_KEEPINTHISFOLDER, TRUE),
		fsDlgLngInfo (IDC__AUTOSAVE, L_AUTOSAVE),
		fsDlgLngInfo (IDC__MIN, L_MIN),
		fsDlgLngInfo (IDC__DATADESC, L_FDMDATAFILESDESC),
	};
	
	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}

void CDlg_Options_General_Misc_Advanced::UpdateEnabled()
{
	BOOL b = IsDlgButtonChecked (IDC_KEEP_2) == BST_CHECKED;
	GetDlgItem (IDC_FOLDER)->EnableWindow (b);
	GetDlgItem (IDC_BROWSE)->EnableWindow (b);
}

void CDlg_Options_General_Misc_Advanced::OnKeep1() 
{
	UpdateEnabled ();	
}

void CDlg_Options_General_Misc_Advanced::OnKeep2() 
{
	CString str;
	GetDlgItemText (IDC_FOLDER, str);

	if (str.IsEmpty ())
		SetTimer (1, 100, NULL);

	UpdateEnabled ();
}

void CDlg_Options_General_Misc_Advanced::OnBrowse() 
{
	CString str;
	GetDlgItemText (IDC_FOLDER, str);
	
	if (str.GetLength () > 3 && (str [str.GetLength () - 1] == '\\' || str [str.GetLength () - 1] == '/'))
		str.GetBuffer (0) [str.GetLength () - 1] = 0;
	
	CFolderBrowser *fb = CFolderBrowser::Create (LS (L_CHOOSEOUTFOLDER), str, NULL, this);
	if (fb == NULL)
		return;
	
	SetDlgItemText (IDC_FOLDER, fb->GetPath ());
	GetDlgItem (IDC_FOLDER)->SetFocus ();	
}

void CDlg_Options_General_Misc_Advanced::OnTimer(UINT nIDEvent) 
{
	if (nIDEvent == 1)
	{
		KillTimer (1);

		OnBrowse ();
		CString str;
		GetDlgItemText (IDC_FOLDER, str);
		if (str.IsEmpty ())
		{
			GetDlgItem (IDC_KEEP_1)->SetFocus (); 
			
			CheckRadioButton (IDC_KEEP_1, IDC_KEEP_2, IDC_KEEP_1);
			UpdateEnabled ();
			return;
		}
	}
	
	CDlg_Options_Page::OnTimer(nIDEvent);
}
