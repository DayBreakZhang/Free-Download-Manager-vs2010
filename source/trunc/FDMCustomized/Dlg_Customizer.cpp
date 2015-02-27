/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FDMCustomized.h"
#include "Dlg_Customizer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlg_Customizer::CDlg_Customizer(CWnd* pParent )
	: CDialog(CDlg_Customizer::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_Customizer)
	m_strURL = _T("");
	m_strIcon = _T("");
	//}}AFX_DATA_INIT
}

void CDlg_Customizer::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_Customizer)
	DDX_Text(pDX, IDC_URL, m_strURL);
	DDX_Text(pDX, IDC_FILE, m_strIcon);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlg_Customizer, CDialog)
	//{{AFX_MSG_MAP(CDlg_Customizer)
	ON_BN_CLICKED(IDC_BROWSE, OnBrowse)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CDlg_Customizer::OnBrowse() 
{
	CFileDialog dlg (TRUE, NULL, m_strIcon, OFN_HIDEREADONLY|OFN_NOCHANGEDIR, 
		"Files with icons (*.ico)|*.ico|All files (*.*)|*.*||", this);
	if (dlg.DoModal () == IDOK)
	{
		m_strIcon = dlg.GetPathName ();
		SetDlgItemText (IDC_FILE, m_strIcon);
	}		
}
