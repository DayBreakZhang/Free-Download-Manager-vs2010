/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Prg_Data.h"
#include "FolderBrowser.h"
#include "mfchelp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CPrg_Data, CPropertyPage)

CPrg_Data::CPrg_Data() : CPropertyPage(CPrg_Data::IDD)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = LS (L_DATA);
}

CPrg_Data::~CPrg_Data()
{
}

void CPrg_Data::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPrg_Data)
		
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPrg_Data, CPropertyPage)
	//{{AFX_MSG_MAP(CPrg_Data)
	ON_WM_CONTEXTMENU()
	ON_WM_HELPINFO()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	ON_BN_CLICKED(IDC_KEEP_1, OnKeep1)
	ON_BN_CLICKED(IDC_KEEP_2, OnKeep2)
	ON_EN_CHANGE(IDC_FOLDER, OnChangeFolder)
	ON_EN_CHANGE(IDC_AUTOSAVE, OnChangeAutosave)
	ON_BN_CLICKED(IDC_BROWSE, OnBrowse)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CPrg_Data::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
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

void CPrg_Data::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_KEEP_1, L_KEEPDATAINUSERSFOLDER),
		fsDlgLngInfo (IDC_KEEP_2, L_KEEPINTHISFOLDER, TRUE),
		fsDlgLngInfo (IDC__AUTOSAVE, L_AUTOSAVE),
		fsDlgLngInfo (IDC__MIN, L_MIN),
		fsDlgLngInfo (IDC__DATADESC, L_FDMDATAFILESDESC),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}

BOOL CPrg_Data::OnApply() 
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
	
	return CPropertyPage::OnApply();
}

void CPrg_Data::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();	
}

BOOL CPrg_Data::OnHelpInfo(HELPINFO* pHelpInfo) 
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

void CPrg_Data::OnWhatisthis() 
{
	_CHMgr.OnWT ();		
}

void CPrg_Data::PrepareCHMgr(CPoint point)
{
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC__AUTOSAVE, LS (L_AUTOSAVEHERE)),
		fsCtrlContextHelp (IDC_AUTOSAVE, LS (L_AUTOSAVEHERE)),
	};

    static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));
}

void CPrg_Data::UpdateEnabled()
{
	BOOL b = IsDlgButtonChecked (IDC_KEEP_2) == BST_CHECKED;
	GetDlgItem (IDC_FOLDER)->EnableWindow (b);
	GetDlgItem (IDC_BROWSE)->EnableWindow (b);
}

void CPrg_Data::OnKeep1() 
{
	UpdateEnabled ();
	SetModified ();
}

void CPrg_Data::OnKeep2() 
{
	CString str;
	GetDlgItemText (IDC_FOLDER, str);

	if (str.IsEmpty ())
	{
		OnBrowse ();
		GetDlgItemText (IDC_FOLDER, str);
		if (str.IsEmpty ())
		{
			CheckRadioButton (IDC_KEEP_1, IDC_KEEP_2, IDC_KEEP_1);
			return;
		}		
	}

	UpdateEnabled ();	
	SetModified ();
}

void CPrg_Data::OnChangeFolder() 
{
	SetModified ();
}

void CPrg_Data::OnChangeAutosave() 
{
	SetModified ();
}

void CPrg_Data::OnBrowse() 
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
