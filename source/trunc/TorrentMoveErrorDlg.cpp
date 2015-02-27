/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "TorrentMoveErrorDlg.h"
#include "afxdialogex.h"

IMPLEMENT_DYNAMIC(CTorrentMoveErrorDlg, CDialog)

CTorrentMoveErrorDlg::CTorrentMoveErrorDlg(CWnd* pParent )
	: CDialog(CTorrentMoveErrorDlg::IDD, pParent)
{
	m_strMsg = _T("");
}

CTorrentMoveErrorDlg::~CTorrentMoveErrorDlg()
{
}

void CTorrentMoveErrorDlg::DoDataExchange(CDataExchange* pDX)
{
	DDX_Text(pDX, IDC__MSG, m_strMsg);
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTorrentMoveErrorDlg, CDialog)
	ON_BN_CLICKED(IDC_RETRY, &CTorrentMoveErrorDlg::OnBnClickedRetry)
	ON_BN_CLICKED(IDC_ABORT, &CTorrentMoveErrorDlg::OnBnClickedAbort)
	ON_BN_CLICKED(IDC_ABORTALL, &CTorrentMoveErrorDlg::OnBnClickedAbortAll)
END_MESSAGE_MAP()

BOOL CTorrentMoveErrorDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	
	((CStatic*) GetDlgItem (IDC_DLGICON))->SetIcon (LoadIcon (NULL, IDI_QUESTION));

	ApplyLanguage ();

	return TRUE;
}

void CTorrentMoveErrorDlg::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_RETRY, L_RETRY),
		fsDlgLngInfo (IDC_ABORT, L_ABORT),
		fsDlgLngInfo (IDC_ABORTALL, L_ABORTALL),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}

void CTorrentMoveErrorDlg::OnBnClickedRetry()
{
	EndDialog (IDC_RETRY);
}

void CTorrentMoveErrorDlg::OnBnClickedAbort()
{
	EndDialog (IDC_ABORT);
}

void CTorrentMoveErrorDlg::OnBnClickedAbortAll()
{
	EndDialog (IDC_ABORTALL);
}

void CTorrentMoveErrorDlg::OnCancel() 
{
	EndDialog (IDC_ABORTALL);
}