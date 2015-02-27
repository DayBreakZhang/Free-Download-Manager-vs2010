/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fdm.h"
#include "DlgCreateFlvDownloadsByWebPageUrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlgCreateFlvDownloadsByWebPageUrl::CDlgCreateFlvDownloadsByWebPageUrl(CWnd* pParent )
	: CDialog(CDlgCreateFlvDownloadsByWebPageUrl::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgCreateFlvDownloadsByWebPageUrl)
	//}}AFX_DATA_INIT
}

void CDlgCreateFlvDownloadsByWebPageUrl::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgCreateFlvDownloadsByWebPageUrl)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgCreateFlvDownloadsByWebPageUrl, CDialog)
	//{{AFX_MSG_MAP(CDlgCreateFlvDownloadsByWebPageUrl)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CDlgCreateFlvDownloadsByWebPageUrl::OnOK() 
{
	GetDlgItemText (IDC_WPURL, m_strWebPageUrl);

	fsURL url;
	if (IR_SUCCESS != url.Crack (m_strWebPageUrl))
	{
		MessageBox (LS (L_CHECKURL), LS (L_INPERR), MB_ICONEXCLAMATION);
		GetDlgItem (IDC_WPURL)->SetFocus ();
		return;
	}

	_LastFlashVideoUrls.AddRecord (m_strWebPageUrl);
	
	CDialog::OnOK();
}

BOOL CDlgCreateFlvDownloadsByWebPageUrl::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	LPCSTR pszUrl = _ClipbrdMgr.Text ();
	if (pszUrl && *pszUrl)
	{
		fsURL url;
		if (url.Crack (pszUrl) == IR_SUCCESS && *url.GetHostName ())
			m_strWebPageUrl = pszUrl;
	}

	if (m_strWebPageUrl.IsEmpty ())
		m_strWebPageUrl = "http://";

	CComboBox *pUrls = (CComboBox*) GetDlgItem (IDC_WPURL);
	for (int i = 0; i < _LastFlashVideoUrls.GetRecordCount (); i++)
		pUrls->AddString (_LastFlashVideoUrls.GetRecord (i));

	SetDlgItemText (IDC_WPURL, m_strWebPageUrl);

	ApplyLanguage ();
	
	return TRUE;  
	              
}

void CDlgCreateFlvDownloadsByWebPageUrl::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__WEBPAGE, L_WEBPAGE, TRUE),
		fsDlgLngInfo (IDC__NOTE, L_CREATEFLVDLD_FROM_WPURL_NOTE),
		fsDlgLngInfo (IDCANCEL, L_CANCEL),
	};
	
	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_CREATEFVDLD);
}
