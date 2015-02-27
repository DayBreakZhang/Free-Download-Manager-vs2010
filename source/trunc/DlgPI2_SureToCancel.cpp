/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fdmapp.h"
#include "DlgPI2_SureToCancel.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlgPI2_SureToCancel::CDlgPI2_SureToCancel(CWnd* pParent )
	: CDialog(CDlgPI2_SureToCancel::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgPI2_SureToCancel)
		
	//}}AFX_DATA_INIT
}

void CDlgPI2_SureToCancel::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgPI2_SureToCancel)
		
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgPI2_SureToCancel, CDialog)
	//{{AFX_MSG_MAP(CDlgPI2_SureToCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlgPI2_SureToCancel::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	SetDlgItemText (IDC__MSG, LS (L_PI_SURETOCANCEL));
	SetDlgItemText (IDCANCEL, LS (L_STILL_CANCEL));
	SetDlgItemText (IDOK, LS (L_PROCEED));

	CDC *pdc = GetDC ();
	pdc->SelectObject (GetFont ());
	int cx = pdc->GetTextExtent (LS (L_STILL_CANCEL)).cx;
	CRect rc; GetDlgItem (IDCANCEL)->GetWindowRect (&rc);
	if (rc.Width () < cx + 10)
	{
		rc.left -= cx - rc.Width () + 10;
		ScreenToClient (&rc);
		GetDlgItem (IDCANCEL)->MoveWindow (&rc);
	}
	
	return TRUE;  
	              
}
