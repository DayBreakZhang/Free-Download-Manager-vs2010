/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fdmapp.h"
#include "DlgPI2_IfRemind.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlgPI2_IfRemind::CDlgPI2_IfRemind(CWnd* pParent )
	: CDialog(CDlgPI2_IfRemind::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgPI2_IfRemind)
		
	//}}AFX_DATA_INIT
}

void CDlgPI2_IfRemind::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgPI2_IfRemind)
		
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgPI2_IfRemind, CDialog)
	//{{AFX_MSG_MAP(CDlgPI2_IfRemind)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlgPI2_IfRemind::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	SetDlgItemText (IDC__MSG, LS (L_DO_YOU_WANT_US_TO_REMIND));
	SetDlgItemText (IDOK, LS (L_YES));
	SetDlgItemText (IDCANCEL, LS (L_NO));
	
	return TRUE;  
	              
}
