/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "coredll.h"
#include "DlgUploadDone.h"
#include "misc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern void fsOpenUrlInBrowser (LPCSTR pszUrl);

CDlgUploadDone::CDlgUploadDone(CWnd* pParent )
	: CDialog(CDlgUploadDone::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgUploadDone)
		
	//}}AFX_DATA_INIT
}

void CDlgUploadDone::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgUploadDone)
		
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgUploadDone, CDialog)
	//{{AFX_MSG_MAP(CDlgUploadDone)
	ON_BN_CLICKED(IDC_DONTSHOWAGAIN, OnDontshowagain)
	ON_BN_CLICKED(IDC_COPY, OnCopy)
	ON_BN_CLICKED(IDC_OPEN, OnOpen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlgUploadDone::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CString str;
	str.Format (LS (L_UPLOAD_DONE_MSG), m_upl->pMgr->get_UploadName ());
	SetDlgItemText (IDC__MSG, str);

	str.Format ("[100%%] - %s", m_upl->pMgr->get_UploadName ());
	SetWindowText (str);

	SetDlgItemText (IDC_DONTSHOWAGAIN, LS (L_DONTSHOWTHISWINDOWAGAIN));

	str = LS (L_COPY); str += " && "; str += LS (L_CLOSE);
	SetDlgItemText (IDC_COPY, str);

	SetDlgItemText (IDC_URL, m_upl->pMgr->get_PackageUrl ());

	SetDlgItemText (IDCANCEL, LS (L_CLOSE));

	SetDlgItemText (IDC_OPEN, LS (L_OPEN));
	
	return TRUE;  
	              
}

void CDlgUploadDone::OnDontshowagain() 
{
	_App.View_UploadDoneDlg (IsDlgButtonChecked (IDC_DONTSHOWAGAIN) == BST_UNCHECKED);
}

void CDlgUploadDone::OnCancel() 
{
	CDialog::OnCancel();
	delete this;
}

void CDlgUploadDone::OnCopy() 
{
	CString str;
	GetDlgItemText (IDC_URL, str);
	vmsSetClipboardText (str);
	
	PostMessage (WM_COMMAND, IDCANCEL);
}

void CDlgUploadDone::OnOpen() 
{
	CString str;
	GetDlgItemText (IDC_URL, str);
	fsOpenUrlInBrowser (str);
	
	PostMessage (WM_COMMAND, IDCANCEL);
}
