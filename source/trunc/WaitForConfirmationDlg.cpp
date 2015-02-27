/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "WaitForConfirmationDlg.h"
#include "system.h"
#include "mfchelp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CWaitForConfirmationDlg::CWaitForConfirmationDlg(CWnd* pParent )
	: CDialog(CWaitForConfirmationDlg::IDD, pParent)
{
	m_bShowDontAsk = FALSE;
	m_bNoIsDefault = FALSE;
	m_bDontAsk = FALSE;
	m_pszIcon = IDI_QUESTION;
}

void CWaitForConfirmationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWaitForConfirmationDlg)
		
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWaitForConfirmationDlg, CDialog)
	//{{AFX_MSG_MAP(CWaitForConfirmationDlg)
	ON_WM_TIMER()
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	ON_BN_CLICKED(IDC_DONTASK, OnDontask)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CWaitForConfirmationDlg::Init(LPCSTR pszMsg, UINT uWait, BOOL bShowDontAsk, BOOL bNoIsDefault, LPCSTR pszDontAskAgainText, LPCSTR pszMsgIfDontAskAgain)
{
	m_msg = pszMsg;
	m_wait = uWait;
	m_bShowDontAsk = bShowDontAsk;
	m_bNoIsDefault = bNoIsDefault;

	if (pszDontAskAgainText)
		m_strDontAskAgainText = pszDontAskAgainText;
	else
		m_strDontAskAgainText = "";

	if (pszMsgIfDontAskAgain)
		m_strMsgIfDontAskAfain = pszMsgIfDontAskAgain;
	else
		m_strMsgIfDontAskAfain = "";
}

BOOL CWaitForConfirmationDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	SetDlgItemText (IDC__MESSAGE, m_msg);
	((CStatic*) GetDlgItem (IDC_DLGICON))->SetIcon (::LoadIcon (NULL, m_pszIcon));

	fsSetForegroundWindow (m_hWnd);
    mfcSetTopmostWindow (this);

	ApplyLanguage ();

	if (m_strDontAskAgainText.GetLength () != 0)
		SetDlgItemText (IDC_DONTASK, m_strDontAskAgainText);

	
	if (m_wait != UINT_MAX)
	{
		SetTimer (1, 1000, NULL);
		SetTimerText ();
	}

	GetDlgItem (IDC_DONTASK)->ShowWindow (m_bShowDontAsk ? SW_SHOW : SW_HIDE);
	m_bDontAsk = FALSE;

	return TRUE;  
	              
}

void CWaitForConfirmationDlg::OnTimer(UINT nIDEvent) 
{
	

	if (--m_wait == 0)
		EndDialog (m_bNoIsDefault ? IDCANCEL : IDOK);
	else
		SetTimerText ();

	
	
	CDialog::OnTimer(nIDEvent);

	
}

void CWaitForConfirmationDlg::SetTimerText()
{
	CString str;
	str.Format ("%s (%d)", m_bNoIsDefault ? LS (L_NO) : LS (L_YES), m_wait);
	SetDlgItemText (m_bNoIsDefault ? IDCANCEL : IDOK, str);
}

void CWaitForConfirmationDlg::OnContextMenu(CWnd* , CPoint point) 
{
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDOK, "Perform operation"),
		fsCtrlContextHelp (IDCANCEL, "Cancel operation"),
	};

        static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));	
	_CHMgr.ShowMenu ();
}

void CWaitForConfirmationDlg::OnWhatisthis() 
{
	_CHMgr.OnWT ();	
}

void CWaitForConfirmationDlg::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDOK, L_YES),
		fsDlgLngInfo (IDCANCEL, L_NO),
		fsDlgLngInfo (IDC_DONTASK, L_DONTASKAGAIN),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_CONFIRMATION);
}

void CWaitForConfirmationDlg::OnDontask() 
{
	m_bDontAsk = IsDlgButtonChecked (IDC_DONTASK) == BST_CHECKED;	
}

void CWaitForConfirmationDlg::OnOK() 
{
	DoPostDlg ();	
	CDialog::OnOK();
}

void CWaitForConfirmationDlg::OnCancel() 
{
	DoPostDlg ();	
	CDialog::OnCancel();
}

void CWaitForConfirmationDlg::DoPostDlg()
{
	if (m_bDontAsk && m_strMsgIfDontAskAfain.GetLength () != 0)
		MessageBox (m_strMsgIfDontAskAfain, vmsFdmAppMgr::getAppName (), MB_OK);
}
