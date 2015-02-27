/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fdm.h"
#include "Dlg_Options_SiteMgr.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlg_Options_SiteMgr::CDlg_Options_SiteMgr(CWnd* pParent )
	: CDlg_Options_Page(CDlg_Options_SiteMgr::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_Options_SiteMgr)
		
	//}}AFX_DATA_INIT
}

void CDlg_Options_SiteMgr::DoDataExchange(CDataExchange* pDX)
{
	CDlg_Options_Page::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_Options_SiteMgr)
		
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlg_Options_SiteMgr, CDlg_Options_Page)
	//{{AFX_MSG_MAP(CDlg_Options_SiteMgr)
	ON_BN_CLICKED(IDC_DELALL, OnDelall)
	ON_BN_CLICKED(IDC_USE, OnUse)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlg_Options_SiteMgr::OnInitDialog() 
{
	CDlg_Options_Page::OnInitDialog();
	
	CheckDlgButton (IDC_USE, _App.SM_KeepPasswords () ? BST_CHECKED : BST_UNCHECKED);
	CheckRadioButton (IDC_ASK, IDC_DONTASK, _App.SM_PwdsManualAddition () ? IDC_DONTASK : IDC_ASK);
	CheckDlgButton (IDC_AUTODEL, _App.SM_DontSavePwdsToDisk () ? BST_CHECKED : BST_UNCHECKED);
	
	ApplyLanguage ();
	UpdateEnabled ();
	
	return TRUE;  
	              
}

CString CDlg_Options_SiteMgr::get_PageTitle()
{
	return LS (L_SITESMGR);
}

CString CDlg_Options_SiteMgr::get_PageShortTitle()
{
	return LS (L_SITESMGR);
}

BOOL CDlg_Options_SiteMgr::Apply()
{
	if (IsDlgButtonChecked (IDC_USE) == BST_CHECKED)
	{
		_App.SM_PwdsManualAddition (IsDlgButtonChecked (IDC_ASK) == BST_UNCHECKED);
		_App.SM_DontSavePwdsToDisk (IsDlgButtonChecked (IDC_AUTODEL) == BST_CHECKED);
		_App.SM_KeepPasswords (TRUE);
	}
	else
	{
		_App.SM_KeepPasswords (FALSE);
	}

	return TRUE;
}

void CDlg_Options_SiteMgr::OnDelall() 
{
	if (IDYES == MessageBox (LS (L_AREYOUSURE), LS (L_CONFIRMATION), MB_OK|MB_YESNO))
		_SitesMgr.DeleteAllPasswords ();		
}

void CDlg_Options_SiteMgr::UpdateEnabled()
{
	BOOL b = IsDlgButtonChecked (IDC_USE) == BST_CHECKED;
	GetDlgItem (IDC_ASK)->EnableWindow (b);
	GetDlgItem (IDC_DONTASK)->EnableWindow (b);
	GetDlgItem (IDC_AUTODEL)->EnableWindow (b);
}

void CDlg_Options_SiteMgr::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__PASSWORDS, L_PASSWORDS),
		fsDlgLngInfo (IDC_USE, L_USESMTOSTOREPWDS),
		fsDlgLngInfo (IDC_ASK, L_ASKMETOSAVEPWDS),
		fsDlgLngInfo (IDC_DONTASK, L_DONTASKMETOSAVEPWDS),
		fsDlgLngInfo (IDC_AUTODEL, L_DELPWDSBEFOREEXIT),
		fsDlgLngInfo (IDC_DELALL, L_DELETEALLPWDS),
	};
	
	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}

void CDlg_Options_SiteMgr::OnUse() 
{
	UpdateEnabled ();	
}
