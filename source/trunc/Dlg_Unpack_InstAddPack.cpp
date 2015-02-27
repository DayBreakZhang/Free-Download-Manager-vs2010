/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Dlg_Unpack_InstAddPack.h"
#include "DownloadsWnd.h"

extern CDownloadsWnd* _pwndDownloads;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlg_Unpack_InstAddPack::CDlg_Unpack_InstAddPack(CWnd* pParent )
	: CDialog(CDlg_Unpack_InstAddPack::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_Unpack_InstAddPack)
		
	//}}AFX_DATA_INIT
}

void CDlg_Unpack_InstAddPack::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_Unpack_InstAddPack)
		
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlg_Unpack_InstAddPack, CDialog)
	//{{AFX_MSG_MAP(CDlg_Unpack_InstAddPack)
	ON_BN_CLICKED(IDC_VISITWEBSITE, OnVisitwebsite)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlg_Unpack_InstAddPack::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	ApplyLanguage ();
	
	return TRUE;  
	              
}

void CDlg_Unpack_InstAddPack::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_DONTASKAGAIN, L_DONTASKAGAIN),
		fsDlgLngInfo (IDC_VISITWEBSITE, L_VISITWEBSITE),
		fsDlgLngInfo (IDOK, L_INSTALLPACK),
		fsDlgLngInfo (IDCANCEL, L_CANCEL),
	};

	CString str = LS (L_UNSUPPARCFMT); str += "\n\n";
	str += LS (L_ADDPACKCANBEINSTALLED_MSG);
	SetDlgItemText (IDC__MSG, str);

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_ARCFMTISUNKN);
}

void CDlg_Unpack_InstAddPack::OnVisitwebsite() 
{
	if (IsDlgButtonChecked (IDC_DONTASKAGAIN) == BST_CHECKED)
		_App.DontShowInstallAP (TRUE);

	fsOpenUrlInBrowser ("http://www.freedownloadmanager.org/download.htm");
	EndDialog (IDCANCEL);
}

void CDlg_Unpack_InstAddPack::OnOK() 
{
	BOOL bAutoStart = TRUE;
	vmsDWCD_AdditionalParameters ap;

	ap.dwMask = DWCDAP_GROUP | DWCDAP_FLAGS;
	ap.pGroup = _DldsGrps.FindGroup (GRP_OTHER_ID);
	ap.dwFlags = DWDCDAP_F_SAVETOTEMPFLDR | DWDCDAP_F_DELWHENDONE |
		DWDCDAP_F_IGNOREALLRESTRICTS | DWDCDAP_F_PLACETOTOP | 
		DWDCDAP_F_NOGRPAUTOCHANGE;

	_pwndDownloads->CreateDownload (
		"http://files.freedownloadmanager.org/fdmapinst.exe",
		FALSE, LS (L_ARCPACK), NULL, TRUE, DWCD_FORCEAUTOLAUNCH_NOCONF,
		&bAutoStart, &ap, NULL);	

	CDialog::OnOK();
}

void CDlg_Unpack_InstAddPack::OnCancel() 
{
	if (IsDlgButtonChecked (IDC_DONTASKAGAIN) == BST_CHECKED)
		_App.DontShowInstallAP (TRUE);

	CDialog::OnCancel();
}
