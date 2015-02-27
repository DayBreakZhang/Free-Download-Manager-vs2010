/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Dlg_Download_OnHide.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlg_Download_OnHide::CDlg_Download_OnHide(CWnd* pParent )
	: CDialog(CDlg_Download_OnHide::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_Download_OnHide)
		
	//}}AFX_DATA_INIT
}

void CDlg_Download_OnHide::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_Download_OnHide)
	DDX_Control(pDX, IDC_DIALOG_ICON, m_wndIcon);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlg_Download_OnHide, CDialog)
	//{{AFX_MSG_MAP(CDlg_Download_OnHide)
	ON_BN_CLICKED(IDC_SHOW, OnShow)
	ON_BN_CLICKED(IDC_DONTSHOW_, OnDontshow)
	ON_BN_CLICKED(IDC_DONTSHOW_FORTHISDLD, OnDontshowForthisdld)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CDlg_Download_OnHide::OnOK() 
{
	m_bDontAskAgain = IsDlgButtonChecked (IDC_DONTASKAGAIN) == BST_CHECKED;

	if (IsDlgButtonChecked (IDC_SHOW) == BST_CHECKED)
		m_enResult = DDOR_SHOW;
	else if (IsDlgButtonChecked (IDC_DONTSHOW_) == BST_CHECKED)
		m_enResult = DDOR_DONTSHOW;
	else
		m_enResult = DDOR_DONTSHOWFORTHISDLD;
	
	CDialog::OnOK();
}

void CDlg_Download_OnHide::OnShow() 
{
	GetDlgItem (IDC_DONTASKAGAIN)->EnableWindow (TRUE);	
}

void CDlg_Download_OnHide::OnDontshow() 
{
	CheckDlgButton (IDC_DONTASKAGAIN, BST_CHECKED);
	GetDlgItem (IDC_DONTASKAGAIN)->EnableWindow (FALSE);	
}

void CDlg_Download_OnHide::OnDontshowForthisdld() 
{
	GetDlgItem (IDC_DONTASKAGAIN)->EnableWindow (FALSE);	
}

void CDlg_Download_OnHide::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__S1, L_DOYOUWANTTOSEEDLPROGRESSWNDAGAIN),
		fsDlgLngInfo (IDC_SHOW, L_YESIWANTTOSEE),
		fsDlgLngInfo (IDC_DONTSHOW_, L_NOIDONTWANTTOSEE),
		fsDlgLngInfo (IDC_DONTSHOW_FORTHISDLD, L_YESBUTNOFORTHISDLD),
		fsDlgLngInfo (IDC_DONTASKAGAIN, L_DONTASKAGAIN),
		fsDlgLngInfo (IDCANCEL, L_CANCEL),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
	SetWindowText (vmsFdmAppMgr::getVersion ()->m_tstrProductName.c_str ());
}

BOOL CDlg_Download_OnHide::OnInitDialog() 
{
	CDialog::OnInitDialog();

	m_wndIcon.SetIcon (LoadIcon (NULL, IDI_QUESTION));
	
	CheckDlgButton (IDC_SHOW, BST_CHECKED);
	ApplyLanguage ();
	
	return TRUE;  
	              
}
