/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FDMCustomized.h"
#include "Dlg_Button.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlg_Button::CDlg_Button(CWnd* pParent )
	: CDialog(CDlg_Button::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_Button)
	m_strIco = _T("");
	m_strText = _T("");
	m_strURL = _T("");
	//}}AFX_DATA_INIT
}

void CDlg_Button::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_Button)
	DDX_Text(pDX, IDC_FILE, m_strIco);
	DDX_Text(pDX, IDC_TEXT, m_strText);
	DDX_Text(pDX, IDC_URL, m_strURL);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlg_Button, CDialog)
	//{{AFX_MSG_MAP(CDlg_Button)
	ON_BN_CLICKED(IDC_BROWSE, OnBrowse)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CDlg_Button::OnBrowse() 
{
	CFileDialog dlg (TRUE, NULL, m_strIco, OFN_HIDEREADONLY|OFN_NOCHANGEDIR, 
		"Files with icons (*.ico)|*.ico|All files (*.*)|*.*||", this);
	if (dlg.DoModal () == IDOK)
	{
		m_strIco = dlg.GetPathName ();
		SetDlgItemText (IDC_FILE, m_strIco);
	}	
}
