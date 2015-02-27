/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "DlgCustomizeIEMenu.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlgCustomizeIEMenu::CDlgCustomizeIEMenu(CWnd* pParent )
	: CDialog(CDlgCustomizeIEMenu::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgCustomizeIEMenu)
		
	//}}AFX_DATA_INIT
}

void CDlgCustomizeIEMenu::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgCustomizeIEMenu)
		
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgCustomizeIEMenu, CDialog)
	//{{AFX_MSG_MAP(CDlgCustomizeIEMenu)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CDlgCustomizeIEMenu::OnOK() 
{
	BOOL bDLThis = IsDlgButtonChecked (IDC_DLTHIS) == BST_CHECKED;
	BOOL bDLPage = IsDlgButtonChecked (IDC_DLPAGE) == BST_CHECKED;
	BOOL bDLAll = IsDlgButtonChecked (IDC_DLALL) == BST_CHECKED;
	BOOL bDLSelected = IsDlgButtonChecked (IDC_DLSELECTED) == BST_CHECKED;
	BOOL bDLVideo = IsDlgButtonChecked (IDC_DLVIDEO) == BST_CHECKED;

	if (bDLThis || bDLPage || bDLAll || bDLSelected || bDLVideo)
	{
		_IECMM.DeleteIEMenus ();
		_App.Monitor_IEMenu_DLThis (bDLThis);
		_App.Monitor_IEMenu_DLPage (bDLPage);
		_App.Monitor_IEMenu_DLAll (bDLAll);
		_App.Monitor_IEMenu_DLSelected (bDLSelected);
		_App.Monitor_IEMenu_DLFlashVideo (bDLVideo);
		_IECMM.AddIEMenus ();

		if (m_bDLThisWas != bDLThis || m_bDLPageWas != bDLPage ||
				m_bDLAllWas != bDLAll || m_bDLSelectedWas != bDLSelected || 
				m_bDLVideoWas != bDLVideo)
			MessageBox (LS (L_BROWSERRESTARTREQ));
	}
	else
	{
		MessageBox (LS (L_ATLEAST1MENUITEMMUSTBESELECTED), LS (L_INPERR), 
			MB_ICONEXCLAMATION);
		return;
	}

	CDialog::OnOK();
}

BOOL CDlgCustomizeIEMenu::OnInitDialog() 
{
	CDialog::OnInitDialog();

	CheckDlgButton (IDC_DLTHIS, m_bDLThisWas = _App.Monitor_IEMenu_DLThis () ? BST_CHECKED : BST_UNCHECKED);
	CheckDlgButton (IDC_DLPAGE, m_bDLPageWas = _App.Monitor_IEMenu_DLPage () ? BST_CHECKED : BST_UNCHECKED);
	CheckDlgButton (IDC_DLALL, m_bDLAllWas = _App.Monitor_IEMenu_DLAll () ? BST_CHECKED : BST_UNCHECKED);
	CheckDlgButton (IDC_DLSELECTED, m_bDLSelectedWas = _App.Monitor_IEMenu_DLSelected () ? BST_CHECKED : BST_UNCHECKED);
	CheckDlgButton (IDC_DLVIDEO, m_bDLVideoWas = _App.Monitor_IEMenu_DLFlashVideo () ? BST_CHECKED : BST_UNCHECKED);
	
	ApplyLanguage ();
	
	return TRUE;  
	              
}

void CDlgCustomizeIEMenu::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_DLTHIS, L_DLTHISIEMENU),
		fsDlgLngInfo (IDC_DLPAGE, L_DLPAGEIEMENU),
		fsDlgLngInfo (IDC_DLALL, L_DLALLIEMENU),
		fsDlgLngInfo (IDC_DLSELECTED, L_DLSELECTEDIEMENU),
		fsDlgLngInfo (IDC_DLVIDEO, L_DLFLASHVIDEOIEMENU),
		fsDlgLngInfo (IDCANCEL, L_CANCEL),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_CUSTOMIZEIEMENU);
}
