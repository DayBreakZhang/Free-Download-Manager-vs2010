/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Dlg_SavePassword.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlg_SavePassword::CDlg_SavePassword(CWnd* pParent )
	: CDialog(CDlg_SavePassword::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_SavePassword)
		
	//}}AFX_DATA_INIT
}

void CDlg_SavePassword::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_SavePassword)
		
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlg_SavePassword, CDialog)
	//{{AFX_MSG_MAP(CDlg_SavePassword)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CDlg_SavePassword::ApplyLanguage()
{
	CString str = LS (L_SAVEPASSWORD_0);
	str += "\n"; str += LS (L_SAVEPASSWORD_1);
	SetDlgItemText (IDC__MSG, str);
	
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_DONTSUGGEST, L_DONTSUGGESTTOSAVEPWDS),
		fsDlgLngInfo (IDOK, L_YES),
		fsDlgLngInfo (IDCANCEL, L_NO),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_SAVEPASSWORD);
}

void CDlg_SavePassword::OnOK() 
{
	if (IsDlgButtonChecked (IDC_DONTSUGGEST) == BST_CHECKED)
		_App.SM_PwdsManualAddition (TRUE);

	CDialog::OnOK();
}

void CDlg_SavePassword::OnCancel() 
{
	if (IsDlgButtonChecked (IDC_DONTSUGGEST) == BST_CHECKED)
		_App.SM_PwdsManualAddition (TRUE);
	
	CDialog::OnCancel();
}

BOOL CDlg_SavePassword::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	ApplyLanguage ();
	
	return TRUE;  
	              
}
