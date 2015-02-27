/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Dlg_SpreadHelp.h"
#include "Dlg_SpreadHelp_LinkCode.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlg_SpreadHelp::CDlg_SpreadHelp(CWnd* pParent )
	: CDialog(CDlg_SpreadHelp::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_SpreadHelp)
		
	//}}AFX_DATA_INIT
}

void CDlg_SpreadHelp::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_SpreadHelp)
		
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlg_SpreadHelp, CDialog)
	//{{AFX_MSG_MAP(CDlg_SpreadHelp)
	ON_BN_CLICKED(IDC_VIEWLINKCODE, OnViewlinkcode)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CDlg_SpreadHelp::OnViewlinkcode() 
{
	CDlg_SpreadHelp_LinkCode dlg;
	_DlgMgr.DoModal (&dlg);
}

void CDlg_SpreadHelp::OnOK() 
{
	if (IsDlgButtonChecked (IDC_REMIND_NEXTSTART) == BST_CHECKED)
		_App.View_SpreadHelpDialog (SHR_NEXTSTART);
	else if (IsDlgButtonChecked (IDC_REMIND_IN3DAYS) == BST_CHECKED)
		_App.View_SpreadHelpDialog (SHR_IN3DAYS);
	else
		_App.View_SpreadHelpDialog (SHR_NEVER);

	CDialog::OnOK();
}

BOOL CDlg_SpreadHelp::OnInitDialog() 
{
	CDialog::OnInitDialog();

	vmsSpreadHelpRemind en = _App.View_SpreadHelpDialog ();
	if (en == SHR_WAIT1STTIME)
		_App.View_SpreadHelpDialog (en = SHR_IN3DAYS);
	
	CheckRadioButton (IDC_REMIND_NEXTSTART, IDC_REMIND_NEVER, 
		IDC_REMIND_NEXTSTART + en);

	SYSTEMTIME st;
	FILETIME ft;
	GetLocalTime (&st);
	SystemTimeToFileTime (&st, &ft);
	_App.View_SpreadHelpDialog_LastTimeShown_save (ft);

	ApplyLanguage ();
	
	return TRUE;
}

void CDlg_SpreadHelp::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__TEXT1, L_SPREADHELPDLG_TEXT1),
		fsDlgLngInfo (IDC__TEXT2, L_SPREADHELPDLG_TEXT2),
		fsDlgLngInfo (IDC__TEXT3, L_SPREADHELPDLG_TEXT3),
		fsDlgLngInfo (IDC_REMIND_IN3DAYS, L_REMIND_IN3DAYS),
		fsDlgLngInfo (IDC_REMIND_NEXTSTART, L_REMIND_NEXTSTART),
		fsDlgLngInfo (IDC_REMIND_NEVER, L_DONTSHOWTHISWINDOWAGAIN),
		fsDlgLngInfo (IDC_VIEWLINKCODE, L_VIEWLINKHTMLCODE),
	};

	CString str = LS (L_SPREADHELPDLG_TEXT4); str.Replace ("\\n", "\n");
	SetDlgItemText (IDC__TEXT4, str);

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_PLACELINKTOFDM2);
}

