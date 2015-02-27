/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Dlg_CheckFileIntegrity_Progress.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlg_CheckFileIntegrity_Progress::CDlg_CheckFileIntegrity_Progress(CWnd* pParent )
	: CDialog(CDlg_CheckFileIntegrity_Progress::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_CheckFileIntegrity_Progress)
		
	//}}AFX_DATA_INIT
	m_enSHA2Strength = HSHA2S_256;
}

void CDlg_CheckFileIntegrity_Progress::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_CheckFileIntegrity_Progress)
	DDX_Control(pDX, IDC_PROGRESS, m_wndProgress);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlg_CheckFileIntegrity_Progress, CDialog)
	//{{AFX_MSG_MAP(CDlg_CheckFileIntegrity_Progress)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlg_CheckFileIntegrity_Progress::OnInitDialog() 
{
	CDialog::OnInitDialog();

	ApplyLanguage ();

	DWORD dw;
	CloseHandle (
		CreateThread (NULL, 0, _threadDoJob, this, 0, &dw));
	
	return TRUE;  
	              
}

void CDlg_CheckFileIntegrity_Progress::OnCancel() 
{
	if (m_bNeedStop == false)
	{
		m_bNeedStop = true;
		GetDlgItem (IDCANCEL)->EnableWindow (false);
	}
	else
		CDialog::OnCancel ();
}

void CDlg_CheckFileIntegrity_Progress::ApplyLanguage()
{
	SetWindowText (LS (L_PLEASEWAIT));
	GetDlgItem (IDCANCEL)->SetWindowText (LS (L_CANCEL));
	GetDlgItem (IDC_MESSAGE)->SetWindowText (LS (L_CALCULATINGCHECKSUM));
}

bool CDlg_CheckFileIntegrity_Progress::OnProgressChanged(double fPercentage)
{
	m_wndProgress.SetPos ((int)fPercentage);
	return m_bNeedStop == false;
}

DWORD WINAPI CDlg_CheckFileIntegrity_Progress::_threadDoJob(LPVOID lp)
{
	CDlg_CheckFileIntegrity_Progress* pthis = (CDlg_CheckFileIntegrity_Progress*)lp;
	
	pthis->m_bNeedStop = false;
	pthis->m_bSucceeded = false;

	vmsHash hash;
	hash.set_EventsHandler (pthis);

	hash.set_SHA2Strength (pthis->m_enSHA2Strength);
	
	pthis->m_strHashResult = hash.Hash (pthis->m_strFile, pthis->m_enHashAlgorithm).c_str ();

	if (pthis->m_bNeedStop == false) 
		
		pthis->m_bSucceeded = pthis->m_strHashResult == pthis->get_ValidHashResult ();

	
	pthis->PostMessage (WM_COMMAND, pthis->m_bNeedStop ? IDCANCEL : IDOK);
	
	return 0;
}

CString CDlg_CheckFileIntegrity_Progress::get_ValidHashResult()
{
	CString str = m_strValidHashResult;
	str.MakeLower ();

	CString str2;
	LPCSTR psz = str;
	while (*psz)
	{
		if ((*psz >= '0' && *psz <= '9') ||
				(*psz >= 'a' && *psz <= 'f') )
			str2 += *psz;

		psz++;
	}

	return str2;
}

bool CDlg_CheckFileIntegrity_Progress::is_CheckingSucceeded()
{
	return m_bSucceeded;
}
