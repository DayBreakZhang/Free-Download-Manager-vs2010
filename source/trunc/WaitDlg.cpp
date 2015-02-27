/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "WaitDlg.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CWaitDlg::CWaitDlg(CWnd* pParent )
	: CDialog(CWaitDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWaitDlg)
		
	//}}AFX_DATA_INIT
}

void CWaitDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWaitDlg)
	DDX_Control(pDX, IDC_PROGRESS, m_wndProgress);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWaitDlg, CDialog)
	//{{AFX_MSG_MAP(CWaitDlg)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CWaitDlg::OnCancel() 
{
	
	
	m_info.bNeedStop = TRUE;
	GetDlgItem (IDCANCEL)->EnableWindow (FALSE);
}

UINT CWaitDlg::StartWaiting(LPCSTR pszMessage, LPTHREAD_START_ROUTINE procWait, BOOL bEnableCancel, LPVOID lpParam1, LPVOID lpParam2, LPVOID lpParam3, LPVOID lpParam4, LPVOID lpParam5, LPVOID lpParam6, BOOL bModal)
{
	m_info.hwndDlg = NULL;
	m_info.bNeedStop = FALSE;
	m_info.bWaitDone = FALSE;
	m_info.lpParam1  = lpParam1;
	m_info.lpParam2  = lpParam2;
	m_info.lpParam3  = lpParam3;
	m_info.lpParam4  = lpParam4;
	m_info.lpParam5	 = lpParam5;
	m_info.lpParam6  = lpParam6;
	m_info.iProgress = 0;

	m_strMsg = pszMessage;
	m_pfnThread = procWait;
	m_bCancel = bEnableCancel;

	m_bNeedRelease = bModal == false;

	if (bModal)
	{
		return AfxGetApp ()->m_pMainWnd->SendMessage (WM_DOMODAL, 0, (LPARAM)this);
	}
	else
	{
		Create (IDD_WAITER, AfxGetApp ()->m_pMainWnd);
		ShowWindow (SW_SHOW);
		SetForegroundWindow ();
		return TRUE;
	}
}

BOOL CWaitDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	m_info.hwndDlg = m_hWnd;

	DWORD dw;
	CloseHandle (
		CreateThread (NULL, 0, m_pfnThread, &m_info, 0, &dw));

	SetDlgItemText (IDC_MESSAGE, m_strMsg);

	GetDlgItem (IDCANCEL)->EnableWindow (m_bCancel);

	m_wndProgress.SetRange (0, 100);
	
	SetTimer (1, 500, NULL);

	SetWindowText (LS (L_PLEASEWAIT));
	GetDlgItem (IDCANCEL)->SetWindowText (LS (L_CANCEL));

	return TRUE;  
	              
}

void CWaitDlg::OnTimer(UINT ) 
{
	if (m_info.bWaitDone)
	{
		EndDialog (m_info.bNeedStop == FALSE ? IDOK : IDCANCEL);
		if (m_bNeedRelease)
			delete this;
		return;
	}

	m_wndProgress.SetPos (m_info.iProgress);
}
