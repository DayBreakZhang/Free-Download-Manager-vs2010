/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Dlg_Opinions.h"
#include "vmsMaliciousDownloadChecker.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlg_Opinions::CDlg_Opinions(CWnd* pParent )
	: CDialog(CDlg_Opinions::IDD, pParent)
{
	m_pszUrl = NULL;
}

void CDlg_Opinions::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_Opinions)
	DDX_Control(pDX, IDC_EXPLORER1, m_wndWB);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlg_Opinions, CDialog)
	//{{AFX_MSG_MAP(CDlg_Opinions)
	ON_BN_CLICKED(IDC_ABORT, OnAbort)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlg_Opinions::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	ASSERT (m_pszUrl != NULL);

	SetDlgItemText (IDC_ABORT, LS (L_DONTDOWNLOADTHIS));
	SetDlgItemText (IDCANCEL, LS (L_CLOSE));

	m_wbEvents.set_WebBrowser (&m_wndWB);
	m_wbEvents.set_UIHandler (&m_UIHandler);
	m_wbEvents.Attach ();

	CString str;
	str.Format ("http://fdm.freedownloadmanager.org/fromfdm/showopinions.html?url=%s",
		vmsMaliciousDownloadChecker::EncodeUrl (m_pszUrl));
	CString strLoading;
	strLoading.Format ("about:%s...", LS (L_LOADING));

	m_wndWB.Navigate (strLoading, 0, 0, 0, 0);
	m_wndWB.Navigate (str, NULL, NULL, NULL, NULL);

	SetWindowText (LS (L_OPINIONS));
	
	return TRUE;
}

void CDlg_Opinions::OnAbort() 
{
	EndDialog (IDC_ABORT);	
}
