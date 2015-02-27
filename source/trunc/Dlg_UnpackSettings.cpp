/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Dlg_UnpackSettings.h"
#include "FolderBrowser.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlg_UnpackSettings::CDlg_UnpackSettings(CWnd* pParent )
	: CDialog(CDlg_UnpackSettings::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_UnpackSettings)
		
	//}}AFX_DATA_INIT
}

void CDlg_UnpackSettings::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_UnpackSettings)
	DDX_Control(pDX, IDC_BROWSE, m_btnBrowse);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlg_UnpackSettings, CDialog)
	//{{AFX_MSG_MAP(CDlg_UnpackSettings)
	ON_BN_CLICKED(IDC_BROWSE, OnBrowse)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlg_UnpackSettings::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_btnBrowse.SetIcon (SICO (IDI_CHOOSEFOLDER));

	SetDlgItemText (IDC_DSTFOLDER, m_strDstFolder);

	ApplyLanguage ();
	
	return TRUE;  
	              
}

void CDlg_UnpackSettings::OnBrowse() 
{
	CString str = "";
	GetDlgItemText (IDC_DSTFOLDER, str);

	if (str.GetLength () > 3 && (str [str.GetLength () - 1] == '\\' || str [str.GetLength () - 1] == '/'))
		str.GetBuffer (0) [str.GetLength () - 1] = 0;

	CFolderBrowser *fb = CFolderBrowser::Create (LS (L_CHOOSEOUTFOLDER), str, NULL, this);
	if (fb == NULL)
		return;

	SetDlgItemText (IDC_DSTFOLDER, fb->GetPath ());
	GetDlgItem (IDC_DSTFOLDER)->SetFocus ();	
}

void CDlg_UnpackSettings::OnOK() 
{
	GetDlgItemText (IDC_DSTFOLDER, m_strDstFolder);
	
	CDialog::OnOK();
}

void CDlg_UnpackSettings::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDOK, L_EXTRACT),
		fsDlgLngInfo (IDCANCEL, L_CANCEL),
		fsDlgLngInfo (IDC__DSTFOLDER, L_DSTFOLDER, TRUE),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_EXTRACTARCHIVE);
}
