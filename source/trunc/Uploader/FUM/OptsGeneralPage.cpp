/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fum.h"
#include "OptsGeneralPage.h"
#include "fsAutorunMgr.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(COptsGeneralPage, CPropertyPage)

COptsGeneralPage::COptsGeneralPage() : CPropertyPage(COptsGeneralPage::IDD)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = LS (L_GENERAL);
}

COptsGeneralPage::~COptsGeneralPage()
{
}

void COptsGeneralPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COptsGeneralPage)
		
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(COptsGeneralPage, CPropertyPage)
	//{{AFX_MSG_MAP(COptsGeneralPage)
	ON_BN_CLICKED(IDC_AUTOSTART, OnAutostart)
	ON_BN_CLICKED(IDC_STARTMINIMIZED, OnStartminimized)
	ON_BN_CLICKED(IDC_MINTOTRAY, OnMintotray)
	ON_BN_CLICKED(IDC_CLOSEASMINIMIZE, OnCloseasminimize)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL COptsGeneralPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();

	fsAutorunMgr am;
	
	CheckDlgButton (IDC_AUTOSTART, am.IsAutoStart () ? BST_CHECKED : BST_UNCHECKED);
	CheckDlgButton (IDC_STARTMINIMIZED, _App.Prg_StartMinimized () ? BST_CHECKED : BST_UNCHECKED);

	CheckDlgButton (IDC_MINTOTRAY, _App.Prg_MinToTray () ? BST_CHECKED : BST_UNCHECKED);
	CheckDlgButton (IDC_CLOSEASMINIMIZE, _App.Prg_CloseAsMinimize () ? BST_CHECKED : BST_UNCHECKED);

	ApplyLanguage ();
	
	return TRUE;  
	              
}

void COptsGeneralPage::OnAutostart() 
{
	SetModified ();	
}

BOOL COptsGeneralPage::OnApply() 
{
	fsAutorunMgr am;
	am.SetAutoStart (IsDlgButtonChecked (IDC_AUTOSTART) == BST_CHECKED);

	_App.Prg_StartMinimized (IsDlgButtonChecked (IDC_STARTMINIMIZED) == BST_CHECKED);

	_App.Prg_CloseAsMinimize (IsDlgButtonChecked (IDC_CLOSEASMINIMIZE) == BST_CHECKED);
	_App.Prg_MinToTray (IsDlgButtonChecked (IDC_MINTOTRAY) == BST_CHECKED);
	
	return CPropertyPage::OnApply();
}

void COptsGeneralPage::OnStartminimized() 
{
	SetModified ();	
}

void COptsGeneralPage::OnMintotray() 
{
	SetModified ();	
}

void COptsGeneralPage::OnCloseasminimize() 
{
	SetModified ();
}

void COptsGeneralPage::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__STARTUP, L_STARTUP),
		fsDlgLngInfo (IDC_AUTOSTART, L_AUTOSTART),
		fsDlgLngInfo (IDC_STARTMINIMIZED, L_STARTMINIMIZED),
		fsDlgLngInfo (IDC__SYSTEM, L_SYSTEM),
		fsDlgLngInfo (IDC_MINTOTRAY, L_MINTOTRAY),
		fsDlgLngInfo (IDC_CLOSEASMINIMIZE, L_CLOSEASMINIMIZE),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}
