/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "DlgExtensionsFilter.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlgExtensionsFilter::CDlgExtensionsFilter(CWnd* pParent )
	: CDialog(CDlgExtensionsFilter::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgExtensionsFilter)
		
	//}}AFX_DATA_INIT

	m_bRemove = FALSE;
}

void CDlgExtensionsFilter::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgExtensionsFilter)
		
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgExtensionsFilter, CDialog)
	//{{AFX_MSG_MAP(CDlgExtensionsFilter)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlgExtensionsFilter::OnInitDialog() 
{
	CDialog::OnInitDialog();

	SetDlgItemText (IDC_EXTS, m_strExts);
	CheckRadioButton (IDC_REMOVE, IDC_LEAVE, m_bRemove ? IDC_REMOVE : IDC_LEAVE);
	
	ApplyLanguage ();
	
	return TRUE;  
	              
}

void CDlgExtensionsFilter::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__EXTS, L_EXTS_EG),
		fsDlgLngInfo (IDC_REMOVE, L_REMOVEEXTS),
		fsDlgLngInfo (IDC_LEAVE, L_LEAVEEXTS),
		fsDlgLngInfo (IDCANCEL, L_CANCEL),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_FILTER);
}

void CDlgExtensionsFilter::OnOK() 
{
	GetDlgItemText (IDC_EXTS, m_strExts);
	m_bRemove = IsDlgButtonChecked (IDC_REMOVE) == BST_CHECKED;

	if (m_strExts.GetLength () == 0)
	{
		MessageBox (LS (L_ENTEREXTS), LS (L_INPERR), MB_ICONEXCLAMATION);
		GetDlgItem (IDC_EXTS)->SetFocus ();
		return;
	}
	
	CDialog::OnOK();
}

