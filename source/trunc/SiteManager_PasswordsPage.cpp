/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "SiteManager_PasswordsPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CSiteManager_PasswordsPage, CPropertyPage)

CSiteManager_PasswordsPage::CSiteManager_PasswordsPage() : CPropertyPage(CSiteManager_PasswordsPage::IDD)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = LS (L_PASSWORDS);
}

CSiteManager_PasswordsPage::~CSiteManager_PasswordsPage()
{
}

void CSiteManager_PasswordsPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSiteManager_PasswordsPage)
		
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSiteManager_PasswordsPage, CPropertyPage)
	//{{AFX_MSG_MAP(CSiteManager_PasswordsPage)
	ON_BN_CLICKED(IDC_USE, OnUse)
	ON_BN_CLICKED(IDC_DELALL, OnDelall)
	ON_BN_CLICKED(IDC_ASK, OnAsk)
	ON_BN_CLICKED(IDC_DONTASK, OnDontask)
	ON_BN_CLICKED(IDC_AUTODEL, OnAutodel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CSiteManager_PasswordsPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	CheckDlgButton (IDC_USE, _App.SM_KeepPasswords () ? BST_CHECKED : BST_UNCHECKED);
	CheckRadioButton (IDC_ASK, IDC_DONTASK, _App.SM_PwdsManualAddition () ? IDC_DONTASK : IDC_ASK);
	CheckDlgButton (IDC_AUTODEL, _App.SM_DontSavePwdsToDisk () ? BST_CHECKED : BST_UNCHECKED);

	ApplyLanguage ();
	UpdateEnabled ();
		
	return TRUE;
}

void CSiteManager_PasswordsPage::OnUse() 
{
	UpdateEnabled ();	
	SetModified ();
}

void CSiteManager_PasswordsPage::OnDelall() 
{
	if (IDYES == MessageBox (LS (L_AREYOUSURE), LS (L_CONFIRMATION), MB_OK|MB_YESNO))
		_SitesMgr.DeleteAllPasswords ();	
}

void CSiteManager_PasswordsPage::UpdateEnabled()
{
	BOOL b = IsDlgButtonChecked (IDC_USE) == BST_CHECKED;
	GetDlgItem (IDC_ASK)->EnableWindow (b);
	GetDlgItem (IDC_DONTASK)->EnableWindow (b);
	GetDlgItem (IDC_AUTODEL)->EnableWindow (b);
}

BOOL CSiteManager_PasswordsPage::OnApply() 
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

	return CPropertyPage::OnApply();
}

void CSiteManager_PasswordsPage::OnAsk() 
{
	SetModified ();	
}

void CSiteManager_PasswordsPage::OnDontask() 
{
	SetModified ();	
}

void CSiteManager_PasswordsPage::OnAutodel() 
{
	SetModified ();	
}

void CSiteManager_PasswordsPage::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_USE, L_USESMTOSTOREPWDS),
		fsDlgLngInfo (IDC_ASK, L_ASKMETOSAVEPWDS),
		fsDlgLngInfo (IDC_DONTASK, L_DONTASKMETOSAVEPWDS),
		fsDlgLngInfo (IDC_AUTODEL, L_DELPWDSBEFOREEXIT),
		fsDlgLngInfo (IDC_DELALL, L_DELETEALLPWDS),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}
