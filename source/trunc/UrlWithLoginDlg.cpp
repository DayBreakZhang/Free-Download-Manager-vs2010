/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "UrlWithLoginDlg.h"
#include "DownloadPropertiesSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CUrlWithLoginDlg::CUrlWithLoginDlg(CWnd* pParent )
	: CDialog(CUrlWithLoginDlg::IDD, pParent)
{
	m_CaptionLngID = L_ENTERMIRRURL;
	Download_CreateInstance (m_dld);
}

void CUrlWithLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUrlWithLoginDlg)
		
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CUrlWithLoginDlg, CDialog)
	//{{AFX_MSG_MAP(CUrlWithLoginDlg)
	ON_BN_CLICKED(IDC_USELOGIN, OnUselogin)
	ON_BN_CLICKED(IDC_ADVANCED, OnAdvanced)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CUrlWithLoginDlg::OnOK() 
{
	if (FALSE == UpdateDNP ())
		return;

	GetDlgItemText (IDC_URL, m_strUrl);
	fsURL url;
	if (url.Crack (m_strUrl) != IR_SUCCESS || *url.GetHostName () == 0 || *url.GetPath () == 0)
	{
		MessageBox (LS (L_CHECKURL), LS (L_INPERR), MB_ICONEXCLAMATION);
		GetDlgItem (IDC_URL)->SetFocus ();
		return;
	}

	if (IsDlgButtonChecked (IDC_USELOGIN) == BST_CHECKED)
	{
		GetDlgItemText (IDC_USER, m_strUser);
		GetDlgItemText (IDC_PASSWORD, m_strPassword);

		if (m_strUser.GetLength () == 0)
		{
			MessageBox (LS (L_ENTERUSER), LS (L_INPERR), MB_ICONEXCLAMATION);
			GetDlgItem (IDC_USER)->SetFocus ();
			return;
		}
	}
	else
	{
		m_strUser = m_strPassword = "";
	}

	fsDNP_CloneSettings (&m_dnp, m_dld->pMgr->GetDownloadMgr ()->GetDNP ());
	
	CDialog::OnOK();
}

BOOL CUrlWithLoginDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	ZeroMemory (&m_dnp, sizeof (m_dnp));

	if (m_strUrl.GetLength () == 0)
	{
		LPCSTR pszUrl = _ClipbrdMgr.Text ();
		if (pszUrl && *pszUrl)
		{
			fsURL url;
			if (url.Crack (pszUrl) == IR_SUCCESS && *url.GetHostName ())
				m_strUrl = pszUrl;
		}
		
		if (m_strUrl.GetLength () == 0)
			m_strUrl = "http://";
	}

	ASSERT (m_dld->pMgr->GetDownloadMgr () != NULL);

	if (IR_SUCCESS != m_dld->pMgr->GetDownloadMgr ()->CreateByUrl (m_strUrl, TRUE))
		m_dld->pMgr->GetDownloadMgr ()->CreateByUrl ("http://", TRUE);

	SetDlgItemText (IDC_URL, m_strUrl);
	((CEdit*) GetDlgItem (IDC_URL))->SetSel (0, -1);
	GetDlgItem (IDC_URL)->SetFocus ();

	ApplyLanguage ();
	UpdateEnabled ();
	
	return FALSE; 
}

void CUrlWithLoginDlg::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_USELOGIN, L_AUTHORIZATION),
		fsDlgLngInfo (IDC__USER, L_USER),
		fsDlgLngInfo (IDC__PASSWORD, L_PASSWORD),
		fsDlgLngInfo (IDC_ADVANCED, L_ADVANCED),
		fsDlgLngInfo (IDCANCEL, L_CANCEL),
	};

	CString str = LS (L_COMMENT); str += ':';
	SetDlgItemText (IDC__COMMENT, str);

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), m_CaptionLngID);
}

void CUrlWithLoginDlg::OnUselogin() 
{
	UpdateEnabled ();	
}

void CUrlWithLoginDlg::UpdateEnabled()
{
	BOOL b = IsDlgButtonChecked (IDC_USELOGIN) == BST_CHECKED;

	GetDlgItem (IDC__USER)->EnableWindow (b);
	GetDlgItem (IDC_USER)->EnableWindow (b);
	GetDlgItem (IDC__PASSWORD)->EnableWindow (b);
	GetDlgItem (IDC_PASSWORD)->EnableWindow (b);
}

void CUrlWithLoginDlg::OnAdvanced() 
{
	if (FALSE == UpdateDNP ())
		return;

	DLDS_LIST v;
	v.push_back (m_dld);

	 CDownloadPropertiesSheet sheet (LS (L_ADVANCED), this);
	sheet.Init (&v, DPS_SHP_PROTOCOL|DPS_SHP_PROXY);
    _DlgMgr.OnDoModal (&sheet);
	sheet.DoModal ();
    _DlgMgr.OnEndDialog (&sheet);
}

BOOL CUrlWithLoginDlg::UpdateDNP()
{
	fsDownload_NetworkProperties *dnp = m_dld->pMgr->GetDownloadMgr ()->GetDNP ();

	GetDlgItemText (IDC_URL, m_strUrl);

	fsURL url;
	if (IR_SUCCESS != url.Crack (m_strUrl))
	{
		WrongURL ();
		return FALSE;
	}

	if (fsDNP_ApplyUrl (dnp, m_strUrl) != IR_SUCCESS)
	{
		WrongURL ();
		return FALSE;
	}

	return TRUE;
}

void CUrlWithLoginDlg::WrongURL()
{
	MessageBox (LS (L_CHECKURL), LS (L_INPERR), MB_ICONEXCLAMATION);
	GetDlgItem (IDC_URL)->SetFocus ();
}
