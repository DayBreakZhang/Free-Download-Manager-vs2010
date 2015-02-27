/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "BtDld_Misc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CBtDld_Misc, CPropertyPage)

CBtDld_Misc::CBtDld_Misc() : CPropertyPage(CBtDld_Misc::IDD)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = LS (L_MISC);
}

CBtDld_Misc::~CBtDld_Misc()
{
}

void CBtDld_Misc::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBtDld_Misc)
		
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBtDld_Misc, CPropertyPage)
	//{{AFX_MSG_MAP(CBtDld_Misc)
	ON_BN_CLICKED(IDC_LAUNCHWHENDONE, OnLaunchwhendone)
	ON_BN_CLICKED(IDC_GENERATEINFOFILE, OnGenerateinfofile)
	ON_BN_CLICKED(IDC_RESERVESPACE, OnReservespace)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CBtDld_Misc::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_RESERVESPACE, L_RESERVESPACE),
		fsDlgLngInfo (IDC_LAUNCHWHENDONE, L_LAUNCHWHENDONE),
		fsDlgLngInfo (IDC_GENERATEINFOFILE, L_GENERATEDESCFILE),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}

BOOL CBtDld_Misc::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();

	if (*m_pvDlds->at (0)->pMgr->GetBtDownloadMgr ()->get_URL () == 0)
		GetDlgItem (IDC_RESERVESPACE)->EnableWindow (TRUE);

	FlagToDlg (BTDF_RESERVE_DISK_SPACE, IDC_RESERVESPACE);
	FlagToDlg (BTDF_LAUNCH_WHEN_DONE, IDC_LAUNCHWHENDONE);
	FlagToDlg (BTDF_GENERATE_DESC_FILE, IDC_GENERATEINFOFILE);
	
	ApplyLanguage ();
	
	return TRUE;  
	              
}

void CBtDld_Misc::OnLaunchwhendone() 
{
	if (IsDlgButtonChecked (IDC_LAUNCHWHENDONE) == BST_INDETERMINATE)
		CheckDlgButton (IDC_LAUNCHWHENDONE, BST_UNCHECKED);

	SetModified ();
}

void CBtDld_Misc::OnGenerateinfofile() 
{
	if (IsDlgButtonChecked (IDC_GENERATEINFOFILE) == BST_INDETERMINATE)
		CheckDlgButton (IDC_GENERATEINFOFILE, BST_UNCHECKED);

	SetModified ();	
}

void CBtDld_Misc::FlagToDlg(DWORD dwFlag, UINT nIdCtrl)
{
	vmsDownloadSmartPtr dld0 = m_pvDlds->at (0);

	size_t i;
	for (i = 1; i < m_pvDlds->size (); i++)
	{
		
		
		
		if ((dld0->pMgr->GetBtDownloadMgr ()->get_Flags () ^
				m_pvDlds->at (i)->pMgr->GetBtDownloadMgr ()->get_Flags ()) & dwFlag)
			break;
	}
	if (i == m_pvDlds->size ())	
	{
		CheckDlgButton (nIdCtrl, dld0->pMgr->GetBtDownloadMgr ()->get_Flags () & dwFlag ? 
			BST_CHECKED : BST_UNCHECKED);
	}
}

BOOL CBtDld_Misc::OnApply() 
{
	DlgToFlag (BTDF_RESERVE_DISK_SPACE, IDC_RESERVESPACE);
	DlgToFlag (BTDF_LAUNCH_WHEN_DONE, IDC_LAUNCHWHENDONE);
	DlgToFlag (BTDF_GENERATE_DESC_FILE, IDC_GENERATEINFOFILE);
	
	return CPropertyPage::OnApply();
}

void CBtDld_Misc::DlgToFlag(DWORD dwFlag, UINT nIdCtrl)
{
	UINT u = IsDlgButtonChecked (nIdCtrl);
	if (u == BST_INDETERMINATE)
		return;

	for (size_t i = 0; i < m_pvDlds->size (); i++)
	{
		if (u == BST_CHECKED)
			m_pvDlds->at (i)->pMgr->GetBtDownloadMgr ()->enable_Flags (dwFlag);
		else
			m_pvDlds->at (i)->pMgr->GetBtDownloadMgr ()->disable_Flags (dwFlag);
	}
}

void CBtDld_Misc::OnReservespace() 
{
	if (IsDlgButtonChecked (IDC_RESERVESPACE) == BST_INDETERMINATE)
		CheckDlgButton (IDC_RESERVESPACE, BST_UNCHECKED);

	SetModified ();		
}
