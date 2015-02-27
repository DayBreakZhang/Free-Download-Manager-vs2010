/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Dlg_ShutdownType.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlg_ShutdownType::CDlg_ShutdownType(CWnd* pParent )
	: CDialog(CDlg_ShutdownType::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_ShutdownType)
		
	//}}AFX_DATA_INIT

	m_enType = ST_SHUTDOWN;
	m_bRemember = FALSE;
}

void CDlg_ShutdownType::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_ShutdownType)
	DDX_Control(pDX, IDC_TYPE, m_wndShutdownType);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlg_ShutdownType, CDialog)
	//{{AFX_MSG_MAP(CDlg_ShutdownType)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlg_ShutdownType::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_wndShutdownType.AddString (LS (L_SHUTDOWN));
	m_wndShutdownType.AddString (LS (L_RESTARTCOMP));
	m_wndShutdownType.AddString (LS (L_LOGOFF));
	m_wndShutdownType.AddString (LS (L_HIBERNATE));
	m_wndShutdownType.AddString (LS (L_STANDBY));
	m_wndShutdownType.SetCurSel (m_enType);

	if (m_bRemember)
		CheckDlgButton (IDC_REMEMBER, BST_CHECKED);

	SetDlgItemText (IDC_REMEMBER, LS (L_DONTASKAGAIN));
	SetDlgItemText (IDCANCEL, LS (L_CANCEL));

	CString str = LS (L_SHUTDOWNTYPE);
	if (str [str.GetLength () - 1] == ':')
		str.Delete (str.GetLength () - 1, 1);
	SetWindowText (str);
	
	return TRUE; 
}

void CDlg_ShutdownType::OnOK() 
{
	m_enType = (fsShutdownType) m_wndShutdownType.GetCurSel ();
	m_bRemember = IsDlgButtonChecked (IDC_REMEMBER) == BST_CHECKED;
	
	CDialog::OnOK();
}
