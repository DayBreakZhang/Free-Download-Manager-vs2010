/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "UEDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CUEDlg::CUEDlg(CWnd* pParent )
	: CDialog(CUEDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUEDlg)
		
	//}}AFX_DATA_INIT
}

void CUEDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUEDlg)
	DDX_Control(pDX, IDC__UEICON, m_wndIcon);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CUEDlg, CDialog)
	//{{AFX_MSG_MAP(CUEDlg)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CUEDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_wndIcon.SetIcon (LoadIcon (NULL, IDI_ERROR));

	LOGFONT lf;
	GetFont ()->GetLogFont (&lf);
	lf.lfWeight = FW_BOLD;
	m_fntBold.CreateFontIndirect (&lf);

	SetDlgItemText (IDC__MSG6, "2. Free Download Manager has generated a special report on this error. It contains no information about you, only about configuration of your computer and some other technical information. Attach this report to your e-mail. (It is located in \"fdm.dmp\" file in the Free Download Manager's installation folder.)");

	CString str;
	GetDlgItemText (IDC__MSG7, str);
	CString str2;
	str2.Format (str, vmsFdmAppMgr::getVersion ()->m_appVersion [2].dwVal);
	SetDlgItemText (IDC__MSG7, str2);
	
	return TRUE;  
	              
}

void CUEDlg::OnOK() 
{
	CString str;
	str.Format ("mailto:bugs@freedownloadmanager.org?subject=Bug%%20in%%20Free%%20Download%%20Manager%%20build%%20%d%%20found!&body=Dear%%20user!%%20Please%%20don't%%20forget%%20to%%20attach%%20the%%20%%22fdm%d.dmp%%22%%20file%%20that%%20is%%20located%%20in%%20temp%%20folder%%20of%%20your%%20computer.%%20And%%20please%%20try%%20to%%20describe%%20in%%20detail%%20the%%20sequence%%20of%%20actions%%20resulting%%20in%%20a%%20bug.%%20Without%%20this%%20information%%20your%%20report%%20may%%20be%%20useless.%%20Thank%%20you.", vmsFdmAppMgr::getVersion ()->m_appVersion [2].dwVal, vmsFdmAppMgr::getVersion ()->m_appVersion [2].dwVal);
	ShellExecute (NULL, "open", str, NULL, NULL, SW_SHOWNORMAL);

	char sz [MAX_PATH];
	GetTempPath (MAX_PATH, sz);
	str.Format ("/select,\"%sfdm%d.dmp\"", sz, vmsFdmAppMgr::getVersion ()->m_appVersion [2].dwVal);
	ShellExecute (m_hWnd, "open", "explorer.exe", str, NULL, SW_SHOW);

	CDialog::OnOK();
}

HBRUSH CUEDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	if (GetDlgItem (IDC__MSG1)->m_hWnd == pWnd->m_hWnd ||
			GetDlgItem (IDC__MSG3)->m_hWnd == pWnd->m_hWnd)
		SelectObject (pDC->m_hDC, m_fntBold);

	return hbr;
}
