/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Dlg_CheckFileIntegrity_Result.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlg_CheckFileIntegrity_Result::CDlg_CheckFileIntegrity_Result(CWnd* pParent )
	: CDialog(CDlg_CheckFileIntegrity_Result::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_CheckFileIntegrity_Result)
		
	//}}AFX_DATA_INIT
}

void CDlg_CheckFileIntegrity_Result::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_CheckFileIntegrity_Result)
	DDX_Control(pDX, IDC__ICON, m_wndIcon);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlg_CheckFileIntegrity_Result, CDialog)
	//{{AFX_MSG_MAP(CDlg_CheckFileIntegrity_Result)
	ON_BN_CLICKED(IDC_RESTARTDOWNLOAD, OnRestartdownload)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlg_CheckFileIntegrity_Result::OnInitDialog() 
{
	CDialog::OnInitDialog();

	HICON hIco = m_bResultOK ? SICOEX (IDI_TEST_OK, 32, 32) : LoadIcon (NULL, IDI_ERROR);
	m_wndIcon.SetIcon (hIco);

	if (m_bResultOK == false)
		GetDlgItem (IDC_NEVERSHOWTHISIFTESTOK)->EnableWindow (FALSE);
	else
		GetDlgItem (IDC_RESTARTDOWNLOAD)->ShowWindow (SW_HIDE);

	CString str = "URL: "; str += m_strUrl; str += "\r\n";
	str += LS (L_FILENAME); str += ": "; str += m_strFileName; str += "\r\n";
	
	if (m_bResultOK == false)
	{
		str += LS (L_VALIDCHECKSUM); str += ": "; str += m_strValidHash; str += "\r\n";
		str += LS (L_RESULTCHECKSUM); str += ": "; str += m_strResultHash;
	}
	SetDlgItemText (IDC_FILEINFO, str);
		
	ApplyLanguage ();
	
	return TRUE;  
	              
}

void CDlg_CheckFileIntegrity_Result::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__RESULTMSG, m_bResultOK ? L_CFI_RESULTMSG_OK : L_CFI_RESULTMSG_ERR),
		fsDlgLngInfo (IDC_NEVERSHOWTHISIFTESTOK, L_CFI_NEVERSHOWIFOK),
		fsDlgLngInfo (IDC_RESTARTDOWNLOAD, L_RESTARTDL),
	};

	if (m_bResultOK == false)
		SetDlgItemText (IDOK, LS (L_CANCEL));

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 
		m_bResultOK ? L_CFI_SUCCEEDED : L_CFI_FAILED);
}

void CDlg_CheckFileIntegrity_Result::OnRestartdownload() 
{
	EndDialog (IDC_RESTARTDOWNLOAD);
}

void CDlg_CheckFileIntegrity_Result::OnOK() 
{
	if (IsDlgButtonChecked (IDC_NEVERSHOWTHISIFTESTOK) == BST_CHECKED)
		_App.View_DontShowHashCheckResultIfOK (TRUE);
	
	CDialog::OnOK();
}
