/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "DlgUnhExc2.h"
#include "afxdialogex.h"

IMPLEMENT_DYNAMIC(CDlgUnhExc2, CDialogEx)

CDlgUnhExc2::CDlgUnhExc2(CWnd* pParent )
	: CDialog(CDlgUnhExc2::IDD, pParent),
	m_bRestartApp (false)
{

	m_strDescription = _T("");
}

CDlgUnhExc2::~CDlgUnhExc2()
{
}

void CDlgUnhExc2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC__UEICON, m_wndIcon);
	DDX_Text(pDX, IDC_DESCRIPTION, m_strDescription);
	DDV_MaxChars(pDX, m_strDescription, 10000);
}

BEGIN_MESSAGE_MAP(CDlgUnhExc2, CDialog)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDOK, &CDlgUnhExc2::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CDlgUnhExc2::OnBnClickedCancel)
END_MESSAGE_MAP()

BOOL CDlgUnhExc2::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_wndIcon.SetIcon (LoadIcon (NULL, IDI_ERROR));

	LOGFONT lf;
	GetFont ()->GetLogFont (&lf);
	lf.lfWeight = FW_BOLD;
	m_fntBold.CreateFontIndirect (&lf);

	CheckDlgButton (IDC_RESTART, BST_CHECKED);

	GetDlgItem (IDC_DESCRIPTION)->SetFocus ();

	return FALSE;  
	
}

HBRUSH CDlgUnhExc2::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	if (GetDlgItem (IDC__MSG1)->m_hWnd == pWnd->m_hWnd ||
			GetDlgItem (IDC__MSG3)->m_hWnd == pWnd->m_hWnd)
		SelectObject (pDC->m_hDC, m_fntBold);

	
	return hbr;
}

void CDlgUnhExc2::OnBnClickedOk()
{
	m_bRestartApp = IsDlgButtonChecked (IDC_RESTART) == BST_CHECKED;
	CDialog::OnOK();
}

void CDlgUnhExc2::OnBnClickedCancel()
{
	m_bRestartApp = IsDlgButtonChecked (IDC_RESTART) == BST_CHECKED;
	CDialog::OnCancel();
}
