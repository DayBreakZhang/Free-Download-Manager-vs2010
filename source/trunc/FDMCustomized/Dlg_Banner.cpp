/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FDMCustomized.h"
#include "Dlg_Banner.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlg_Banner::CDlg_Banner(CWnd* pParent )
	: CDialog(CDlg_Banner::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_Banner)
	m_strFile = _T("");
	m_strURL = _T("");
	//}}AFX_DATA_INIT
}

void CDlg_Banner::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_Banner)
	DDX_Text(pDX, IDC_FILE, m_strFile);
	DDX_Text(pDX, IDC_URL, m_strURL);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlg_Banner, CDialog)
	//{{AFX_MSG_MAP(CDlg_Banner)
	ON_BN_CLICKED(IDC_BROWSE, OnBrowse)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CDlg_Banner::OnBrowse() 
{
	CFileDialog dlg (TRUE, NULL, m_strFile, OFN_HIDEREADONLY|OFN_NOCHANGEDIR, 
		"Banner's images (*.jpg,*.gif)|*.jpg;*.gif|All files (*.*)|*.*||", this);
	if (dlg.DoModal () == IDOK)
	{
		m_strFile = dlg.GetPathName ();
		SetDlgItemText (IDC_FILE, m_strFile);
	}
}
