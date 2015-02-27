/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fdm.h"
#include "DlgElevateRequired.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlgElevateRequired::CDlgElevateRequired(CWnd* pParent )
	: CDialog(CDlgElevateRequired::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgElevateRequired)
	m_strMsg = _T("");
	//}}AFX_DATA_INIT
}

void CDlgElevateRequired::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgElevateRequired)
	DDX_Text(pDX, IDC__MSG, m_strMsg);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgElevateRequired, CDialog)
	//{{AFX_MSG_MAP(CDlgElevateRequired)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlgElevateRequired::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	SetDlgItemText (IDOK, LS (L_CONTINUE));
	SendDlgItemMessage (IDOK, 0x160C , 0, TRUE);	

	((CStatic*)GetDlgItem (IDC__ICON))->SetIcon (LoadIcon (NULL, IDI_WARNING));

	SetWindowText (LS (L_NOT_ENOUGH_RIGHTS));

	return TRUE;  
	              
}
