/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Dlg_SpreadHelp2.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlg_SpreadHelp2::CDlg_SpreadHelp2(CWnd* pParent )
	: CDialog(CDlg_SpreadHelp2::IDD, pParent),
	m_wbe (&m_wb, &m_wbuih)
{
	//{{AFX_DATA_INIT(CDlg_SpreadHelp2)
		
	//}}AFX_DATA_INIT
}

void CDlg_SpreadHelp2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_SpreadHelp2)
	DDX_Control(pDX, IDC_WB, m_wb);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlg_SpreadHelp2, CDialog)
	//{{AFX_MSG_MAP(CDlg_SpreadHelp2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlg_SpreadHelp2::OnInitDialog() 
{
	CDialog::OnInitDialog();

	m_wbe.Attach ();
	m_wb.Navigate ("about:blank", 0, 0, 0, 0);

	CString strHTML;
	CString strNewHTML = _App.View_SpreadHelpDialog_LinkToUsText ();

	if (strNewHTML == "")
	{
		CString str2;
		str2.Format ("%x", GetSysColor (COLOR_3DFACE));

		char c0 = str2[0], c1 = str2[1];
		str2.SetAt (0, str2 [4]);
		str2.SetAt (1, str2 [5]);
		str2.SetAt (4, c0);
		str2.SetAt (5, c1);

		CString str5 = LS (L_SHDLG_M5);
		str5.Replace ("\n", "<br>");

		UINT nM3 = L_SHDLG_M3;
		SYSTEMTIME time;
		GetLocalTime (&time);
		if (time.wDay < 16 && time.wMonth == 8 && time.wYear == 2006)
			nM3 = L_SHDLG_M3_BEFORE_AUG16_2006;

		CString str;
		str.Format ("<html><style type=\"text/css\"><!--\nbody {margin-left: 0px;	margin-top: 0px; margin-right: 0px;\
margin-bottom: 0px; } \n-->\n</style><body bgcolor='#%s'>\
<font face='ms sans serif' size='-8pt'>%s<br><br>%s<br><br>%s<br><br>%s<br><br>%s<br><br>%s</font></body></html>", 
			str2, LS (L_DEARFOLK), LS (L_SHDLG_M1),
			LS (L_SHDLG_M2), LS (nM3), LS (L_SHDLG_M4), str5);

		CMainFrame* pFrm = (CMainFrame*) AfxGetApp ()->m_pMainWnd;

		CString str3;
		str3.Format ("<a href='http://fdm.freedownloadmanager.org/fromfdm/buzz.php3?from=%s_%d'>%s</a>", 
			vmsFdmAppMgr::getBuildNumberAsString (), pFrm->m_Customizations.get_AffiliateID (), LS (L_FDMBUZZ));

		CString str4;
		str4.Format ("<a href='http://fdm.freedownloadmanager.org/fromfdm/blog.php3?from=%s_%d'>%s</a>",
			vmsFdmAppMgr::getBuildNumberAsString (), pFrm->m_Customizations.get_AffiliateID (), LS (L_BLOG));

		strHTML.Format (str, str3, str4);
	}
	else
	{
		CString str2;
		str2.Format ("%x", GetSysColor (COLOR_3DFACE));

		char c0 = str2[0], c1 = str2[1];
		str2.SetAt (0, str2 [4]);
		str2.SetAt (1, str2 [5]);
		str2.SetAt (4, c0);
		str2.SetAt (5, c1);

		CString str;
		str.Format ("<html><style type=\"text/css\"><!--\nbody {margin-left: 0px;	margin-top: 0px; margin-right: 0px;\
margin-bottom: 0px; } \n-->\n</style><body bgcolor='#%s'>\
<font face='ms sans serif' size='-8pt'>%s</font></body></html>", 
			str2, strNewHTML);

		CMainFrame* pFrm = (CMainFrame*) AfxGetApp ()->m_pMainWnd;

		CString str3;
		str3.Format ("http://fdm.freedownloadmanager.org/fromfdm/buzz.php3?from=%s_%d", 
			vmsFdmAppMgr::getBuildNumberAsString (), pFrm->m_Customizations.get_AffiliateID ());

		CString str4;
		str4.Format ("http://fdm.freedownloadmanager.org/fromfdm/blog.php3?from=%s_%d",
			vmsFdmAppMgr::getBuildNumberAsString (), pFrm->m_Customizations.get_AffiliateID ());

		strHTML.Format (str, str3, str4);
	}

	CStdioFile file;
	char szTmpPath [MY_MAX_PATH];
	char szTmpFile [MY_MAX_PATH];
	GetTempPath (MY_MAX_PATH, szTmpPath);
	GetTempFileName (szTmpPath, "fdm", 0, szTmpFile);
	m_strFile = szTmpFile;
	file.Open (m_strFile, CFile::modeCreate | CFile::modeWrite);
	file.WriteString (strHTML);
	file.Close ();

	CString str;
	str.Format ("file://%s", m_strFile);

	m_wb.Navigate (str, 0, 0, 0, 0);

	ApplyLanguage ();

	vmsSpreadHelpRemind en = _App.View_SpreadHelpDialog ();
	if (en == SHR_WAIT1STTIME)
		_App.View_SpreadHelpDialog (en = SHR_IN3DAYS);
	
	if (en == SHR_IN3DAYS)
		CheckDlgButton (IDC_REMIND_IN3DAYS, BST_CHECKED);
	else
		CheckDlgButton (IDC_DONTSHOWAGAIN, BST_CHECKED);
	
	return TRUE;  
	              
}

CDlg_SpreadHelp2::~CDlg_SpreadHelp2()
{
	DeleteFile (m_strFile);
}

void CDlg_SpreadHelp2::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_REMIND_IN3DAYS, L_REMIND_IN3DAYS),
		fsDlgLngInfo (IDC_DONTSHOWAGAIN, L_SHDLG_DONTSHOWAGAIN),
		fsDlgLngInfo (IDOK, L_JOINBUZZ),
		fsDlgLngInfo (IDCANCEL, L_NOTHANKYOU),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_PLACELINKTOFDM2);

	CString str = _App.View_SpreadHelpDialog_RadioButton1Text ();
	if (str != "")
		SetDlgItemText (IDC_REMIND_IN3DAYS, str);
	str = _App.View_SpreadHelpDialog_RadioButton2Text ();
	if (str != "")
		SetDlgItemText (IDC_DONTSHOWAGAIN, str);
}

void CDlg_SpreadHelp2::OnOK() 
{
	CString str;
	CMainFrame* pFrm = (CMainFrame*) AfxGetApp ()->m_pMainWnd;

	str.Format ("http://fdm.freedownloadmanager.org/fromfdm/buzz.php3?from=%s_%d",
		vmsFdmAppMgr::getBuildNumberAsString (), pFrm->m_Customizations.get_AffiliateID ());

	fsOpenUrlInBrowser (str);

	_App.View_SpreadHelpDialog (SHR_NEVER);
	
	CDialog::OnOK();
}

void CDlg_SpreadHelp2::OnCancel() 
{
	if (IsDlgButtonChecked (IDC_REMIND_IN3DAYS) == BST_CHECKED)
		_App.View_SpreadHelpDialog (SHR_IN3DAYS);
	else
		_App.View_SpreadHelpDialog (SHR_NEVER);

	CDialog::OnCancel();
}
