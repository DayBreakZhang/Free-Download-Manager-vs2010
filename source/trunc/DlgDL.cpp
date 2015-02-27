/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fdmapp.h"
#include "DlgDL.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlgDL::CDlgDL(CWnd* pParent )
	: CDialog(CDlgDL::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgDL)
		
	//}}AFX_DATA_INIT

	m_bSucceeded = false;
	m_bCancelled = false;
}

void CDlgDL::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgDL)
	DDX_Control(pDX, IDC_PROGRESS, m_wndProgress);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgDL, CDialog)
	//{{AFX_MSG_MAP(CDlgDL)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlgDL::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_dldr.CreateByUrl (m_strUrl, TRUE);

	fsDownload_Properties *dp = m_dldr.GetDP ();
	fsDownload_NetworkProperties *dnp = m_dldr.GetDNP ();
	
	SAFE_DELETE_ARRAY (dp->pszFileName);
	fsnew (dp->pszFileName, char, m_strFile.GetLength () + 1);
	strcpy (dp->pszFileName, m_strFile);
	dp->uMaxSections = 1;
	dp->uMaxAttempts = 1;
	dp->dwFlags |= DPF_DONTRESTARTIFNORESUME;
	dp->enSCR = SCR_STOP;
	dp->enAER = AER_REWRITE;
	*dp->pszAdditionalExt = 0;
	
	SAFE_DELETE_ARRAY (dnp->pszReferer);
	fsnew (dnp->pszReferer, char, 1);
	*dnp->pszReferer = 0;

	m_dldr.StartDownloading ();

	SetTimer (1, 200, NULL);

	SetDlgItemText (IDC__MSG, m_strDlName);

	SetWindowText (LS (L_PLEASEWAIT));
	
	return TRUE;  
	              
}

void CDlgDL::OnTimer(UINT nIDEvent) 
{
	if (nIDEvent == 1)
	{
		if (m_dldr.IsRunning () == FALSE)
		{
			m_bSucceeded = m_dldr.IsDone () != FALSE;
			EndDialog (IDOK);
			return;
		}

		m_wndProgress.SetPos ((int)m_dldr.GetDownloader ()->GetPercentDone ());
	}
	
	CDialog::OnTimer(nIDEvent);
}

void CDlgDL::OnCancel() 
{
	m_dldr.StopDownloading ();
	const int sleepVal = 10;
	for (int i = 0; i < 7 * 1000 / sleepVal && m_dldr.IsRunning (); i += sleepVal)
		Sleep (sleepVal);
	m_bCancelled = true;
	
	CDialog::OnCancel();
}
