/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fum.h"
#include "DlgUpdate.h"
#include "fsUpdateMgr.h"
#include "mainfrm.h"
#include "mfchelp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlgUpdate::CDlgUpdate(CWnd* pParent )
	: CDialog(CDlgUpdate::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgUpdate)
		
	//}}AFX_DATA_INIT
}

void CDlgUpdate::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgUpdate)
	DDX_Control(pDX, IDC_PROGRESS, m_wndProgress);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgUpdate, CDialog)
	//{{AFX_MSG_MAP(CDlgUpdate)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlgUpdate::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	char szTmpFile [MAX_PATH];
	char szTmpPath [MAX_PATH];
	GetTempPath (MAX_PATH, szTmpPath);
	GetTempFileName (szTmpPath, "fum", 0, szTmpFile);

	m_strUpdateFile = szTmpFile;

	m_iProgress = 0;
	DWORD dw;
	CloseHandle (
		CreateThread (NULL, 0, _threadDownload, this, 0, &dw));

	SetTimer (1, 1000, NULL);

	ApplyLanguage ();
	
	return TRUE;  
	              
}

DWORD WINAPI CDlgUpdate::_threadDownload(LPVOID lp)
{
	CDlgUpdate* pthis = (CDlgUpdate*)lp;
	CMainFrame *pFrm = (CMainFrame*) AfxGetApp ()->m_pMainWnd;

	if (FALSE == pFrm->m_um.DownloadUpdate (pthis->m_strUpdateFile, &pthis->m_iProgress))
	{
		DeleteFile (pthis->m_strUpdateFile);
		pthis->m_iProgress = -1;
	}
	else
	{
		pFrm->m_iOnBeforeUpload_LastCallResult = LCR_RESTART_REQ;
		pthis->m_iProgress = -2;
	}

	return 0;
}

void CDlgUpdate::OnTimer(UINT nIDEvent) 
{
	if (m_iProgress == -1)
	{
		KillTimer (1);
		SetDlgItemText (IDCANCEL, LS (L_CLOSE));
		SetWindowText (LS (L_FAILED));
		PostMessage (WM_CLOSE);
		return;
	}

	if (m_iProgress == -2)
	{
		KillTimer (1);
		m_wndProgress.SetPos (100);

		if (IDNO == MessageBox (LS (L_NEEDRESTART), LS (L_DONE), MB_ICONQUESTION | MB_YESNO))
			AfxGetApp ()->WriteProfileString ("Update", "UpdateFile", m_strUpdateFile);
		else
		{
			if (StartUpdater (m_strUpdateFile))
				AfxGetApp ()->m_pMainWnd->PostMessage (WM_COMMAND, ID_NEED_EXIT);
			else
			{
				DeleteFile (m_strUpdateFile);
				((CMainFrame*) AfxGetApp ()->m_pMainWnd)->m_iOnBeforeUpload_LastCallResult = -1;
			}
		}
		
		PostMessage (WM_CLOSE);
		return;
	}

	if (m_wndProgress.GetPos () != m_iProgress)
		m_wndProgress.SetPos (m_iProgress);
	
	CDialog::OnTimer(nIDEvent);
}

void CDlgUpdate::OnCancel() 
{
	if (m_iProgress < 0)
	{
		CDialog::OnCancel();
	}
	else
	{
		((CMainFrame*)AfxGetApp ()->m_pMainWnd)->m_um.Abort ();
	}
}

BOOL CDlgUpdate::StartUpdater(LPCSTR pszFile)
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory (&si, sizeof (si));
	si.cb = sizeof (si);
	ZeroMemory (&pi, sizeof (pi));

	CString strCmdLine;
	strCmdLine.Format ("\"%s\" \"%s\" \"%s\" \"%s\" \"/silent\" \"1\"",
		vmsGetAppFolder () + "updater.exe", 
		((CFUMApp*)AfxGetApp ())->m_strAppPath + "fum.exe", 
		_pszAppMutex, 
		pszFile);

	if (FALSE == CreateProcess (NULL, (LPSTR)(LPCSTR)strCmdLine, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
	{
		::MessageBox (NULL, LS (L_CANTFINDUPDATER), LS (L_ERR), MB_ICONERROR);
		return FALSE;
	}

	return TRUE;
}

void CDlgUpdate::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDCANCEL, L_CANCEL),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_DOWNLOADING_UPDATE);
}
