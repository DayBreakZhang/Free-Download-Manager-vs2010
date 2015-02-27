/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FDMCustomized.h"
#include "Dlg_Download.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlg_Download::CDlg_Download(CWnd* pParent )
	: CDialog(CDlg_Download::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_Download)
	m_strURL = _T("");
	m_strReferer = _T("");
	m_strComment = _T("");
	//}}AFX_DATA_INIT
}

void CDlg_Download::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_Download)
	DDX_Text(pDX, IDC_URL, m_strURL);
	DDX_Text(pDX, IDC_REFERER, m_strReferer);
	DDX_Text(pDX, IDC_COMMENT, m_strComment);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlg_Download, CDialog)
	//{{AFX_MSG_MAP(CDlg_Download)
		
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

