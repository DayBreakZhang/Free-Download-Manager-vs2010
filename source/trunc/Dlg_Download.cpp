/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Dlg_Download.h"
#include "Downloads_Tasks.h"
#include "DownloadsWnd.h"
#include "Dlg_Download_OnHide.h"

extern CDownloadsWnd* _pwndDownloads;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlg_Download::CDlg_Download(CWnd* pParent )
	: CDialog(CDlg_Download::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_Download)
		
	//}}AFX_DATA_INIT
}

void CDlg_Download::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_Download)
		
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlg_Download, CDialog)
	//{{AFX_MSG_MAP(CDlg_Download)
	ON_WM_TIMER()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_HIDE, OnHide)
	ON_BN_CLICKED(IDC_AUTOCLOSE, OnAutoclose)
	ON_BN_CLICKED(IDC_STOP, OnStop)
	ON_BN_CLICKED(IDC_OPENFILE, OnOpenfile)
	ON_BN_CLICKED(IDC_OPENFOLDER, OnOpenfolder)
	ON_BN_CLICKED(IDC_AUTOLAUNCH, OnAutolaunch)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CDlg_Download::Create(vmsDownloadSmartPtr dld)
{
	m_dld = dld;

	CWnd wnd;
	wnd.m_hWnd = NULL;
	CDialog::Create (IDD_DOWNLOAD, &wnd);
}

CDlg_Download::~CDlg_Download()
{
}

BOOL CDlg_Download::OnInitDialog() 
{
	CDialog::OnInitDialog();

	m_wndProgress.Create (this);
	CRect rc;
	GetDlgItem (IDC__PROGRESS)->GetWindowRect (&rc);
	ScreenToClient (&rc);
	m_wndProgress.MoveWindow (&rc);
	m_wndProgress.m_dld = m_dld;

	LOGFONT lf;
	GetFont ()->GetLogFont (&lf);
	lf.lfWeight = FW_BOLD;
	m_fntBold.CreateFontIndirect (&lf);

	if (m_dld->pMgr->IsBittorrent ())
		SetDlgItemText (IDC__URL_, LS (L_NAME));
	
	ApplyLanguage ();
	SetTimer (1, 1000, NULL);

	CheckDlgButton (IDC_AUTOCLOSE, _App.DownloadDialog_AutoClose () ? BST_CHECKED : BST_UNCHECKED);
	CheckDlgButton (IDC_AUTOLAUNCH, m_dld->pMgr->IsLaunchWhenDone () ? BST_CHECKED : BST_UNCHECKED);

	NeedUpdate ();

	SetTimer (2, 300, NULL);

	GetDlgItem (IDC_URL)->SetFont (&m_fntBold);
	GetDlgItem (IDC__RST)->SetFont (&m_fntBold);
	
	return TRUE;
}

void CDlg_Download::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__SAVEDIN_, L_SAVEDINFILE, TRUE),
		fsDlgLngInfo (IDC__FILESIZE_, L_FILESIZE, TRUE),
		fsDlgLngInfo (IDC__RESUMESUPPORT_, m_dld->pMgr->IsBittorrent () == FALSE ? L_RESUMESUPPORT : L_STATE, TRUE),
		fsDlgLngInfo (IDC__DOWNLOADED_, L_DOWNLOADED, TRUE),
		fsDlgLngInfo (IDC_SPEED_, L_SPEED, TRUE),
		fsDlgLngInfo (IDC_TIMELEFT_, L_TIMELEFT, TRUE),
		fsDlgLngInfo (IDC_AUTOCLOSE, L_CLOSEWINDOWWHENDONE),
		fsDlgLngInfo (IDC_OPENFOLDER, L_OPENFOLDER),
		fsDlgLngInfo (IDC_OPENFILE, L_LAUNCH),
		fsDlgLngInfo (IDC_STOP, L_STOP),
		fsDlgLngInfo (IDC_HIDE, L_HIDE),
		fsDlgLngInfo (IDC_AUTOLAUNCH, L_LAUNCHWHENDONE),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_DOWNLOAD);
}

void CDlg_Download::OnTimer(UINT nIDEvent) 
{
	if (nIDEvent == 2)
	{
		KillTimer (2);
		m_wndProgress.Invalidate (TRUE);
		return;		
	}

	Update ();
	
	CDialog::OnTimer(nIDEvent);
}

void CDlg_Download::Update()
{
	SetDlgItemText2 (IDC_URL, m_dld->pMgr->IsBittorrent () == FALSE ? m_dld->pMgr->get_URL () : 
		m_dld->pMgr->GetBtDownloadMgr ()->get_TorrentName ());

	SetDlgItemText2 (IDC__SAVEDIN, m_dld->pMgr->get_OutputFilePathName ());

	SetDlgItemText2 (IDC__FILESIZE, CDownloads_Tasks::GetDownloadText (m_dld, 1));

	int nProgress = (int) m_dld->pMgr->GetPercentDone ();
	
	if (m_dld->pMgr->IsBittorrent ())
	{
		UINT64 nToDownload, nDownloaded;
		m_dld->pMgr->GetBtDownloadMgr ()->getPartialDownloadProgress (&nToDownload, &nDownloaded);
		if (nToDownload != m_dld->pMgr->GetLDFileSize ())
			nProgress = nToDownload ? (int)((double)(INT64)nDownloaded / (INT64)nToDownload * 100) : 100;

		switch (m_dld->pMgr->GetBtDownloadMgr ()->get_State ())
		{
		case BTDS_CHECKING_RESUME_DATA:
		case BTDS_CHECKING_FILES:
		case BTDS_ALLOCATING:
			SetDlgItemText2 (IDC__RST, LS (L_PREP_FILES_ONDISK_SHORT));
			break;

		case BTDS_CONNECTING_TRACKER:
			SetDlgItemText2 (IDC__RST, LS (L_BT_TRACKER_ANNOUNCE));
			break;

		case BTDS_DOWNLOADING:
			SetDlgItemText2 (IDC__RESUMESUPPORT_, LS (L_RESUMESUPPORT));
			SetDlgItemText2 (IDC__RST, LS (L_YES));
			break;
		}
	}
	else if (m_dld->pMgr->IsTp ())
	{
		UINT64 uSize = m_dld->pMgr->GetLDFileSize ();
		if (uSize != _UI64_MAX && uSize != 0)
		{
			if (nProgress == -1)
				SetDlgItemText2 (IDC__RST, LS (L_NO));
			else
				SetDlgItemText2 (IDC__RST, LS (L_YES));
		}
	}
	else
	{
		switch (m_dld->pMgr->IsResumeSupported ())
		{
		case RST_PRESENT:
			SetDlgItemText2 (IDC__RST, LS (L_YES));
			break;

		case RST_NONE:
			SetDlgItemText2 (IDC__RST, LS (L_NO));
			break;

		case RST_UNKNOWN:
			SetDlgItemText2 (IDC__RST, LS (L_UNKNOWN));
			break;
		}
	}

	SetDlgItemText2 (IDC__DOWNLOADED, CDownloads_Tasks::GetDownloadText (m_dld, 2));

	SetDlgItemText2 (IDC__SPEED, CDownloads_Tasks::GetDownloadText (m_dld, 5));

	SetDlgItemText2 (IDC__TIMELEFT, CDownloads_Tasks::GetDownloadText (m_dld, 3));

	char szName [10000] = "";
	CDownloads_Tasks::GetFileName (m_dld, szName);
	CString str;

	switch (nProgress)
	{
	case 100:
		str.Format ("%s - %s", szName, LS (L_DONE));
		break;
	case -1: {
		UINT64 uDone = m_dld->pMgr->GetDownloadedBytesCount ();
		float val;
		char szDim [10];
		BytesToXBytes (uDone, &val, szDim);
		str.Format ("%s - %.*g %s", szName, val > 999 ? 4 : 3, val, szDim);
		break;
			}

	default:
		str.Format ("[%d%%] - %s", nProgress, szName);
		break;
	}

	SetWindowText (str);

	m_wndProgress.Invalidate (FALSE);
}

void CDlg_Download::SetDlgItemText2(UINT nID, LPCSTR pszText)
{
	CString str; 
	GetDlgItemText (nID, str);
	if (str != pszText)
		SetDlgItemText (nID, pszText);
}

HBRUSH CDlg_Download::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	pDC->SetBkMode (TRANSPARENT);
	if (GetDlgItem (IDC__RST)->m_hWnd == pWnd->m_hWnd)
	{
		if (m_dld->pMgr->IsBittorrent () == FALSE ||
				m_dld->pMgr->GetBtDownloadMgr ()->get_State () == BTDS_DOWNLOADING)
		{
			switch (m_dld->pMgr->IsResumeSupported ())
			{
			case RST_PRESENT:
				pDC->SetTextColor (RGB (0, 100, 0));
				break;

			case RST_NONE:
				pDC->SetTextColor (RGB (150, 0, 0));
				break;

			case RST_UNKNOWN:
				pDC->SetTextColor (RGB (150, 150, 0));
				break;
			}
		}
	}
	
	
	return hbr;
}

void CDlg_Download::OnHide() 
{
	HWND hwndThis = m_hWnd;

	if (_App.DownloadDialog_DontAskOnHide () == FALSE && m_dld->pMgr->IsDone () == FALSE && 
			m_dld->pMgr->IsRunning ())
	{
		CDlg_Download_OnHide dlg (this);
	
		if (_DlgMgr.DoModal (&dlg) == IDCANCEL)
			return;

		
		
		
		if (!_pwndDownloads || !IsWindow (hwndThis))
			return;

		switch (dlg.m_enResult)
		{
		case DDOR_SHOW:
			if (dlg.m_bDontAskAgain)
				_App.DownloadDialog_DontAskOnHide (TRUE);
			break;

		case DDOR_DONTSHOW:
			_App.DownloadDialog_Use (FALSE);
			_App.DownloadDialog_DontAskOnHide (TRUE);
			break;

		case DDOR_DONTSHOWFORTHISDLD:
			m_dld->dwFlags |= DLD_DONTSHOWDIALOG;
			m_dld->setDirty();
			break;
		}
	}	

	if (_pwndDownloads)
	{
		m_dld->AddRef (); 
		_pwndDownloads->PostMessage (WM_DW_CLOSEDLDDIALOG, 0, (LPARAM)(fsDownload*) m_dld);
	}
}

void CDlg_Download::OnAutoclose() 
{
	_App.DownloadDialog_AutoClose (IsDlgButtonChecked (IDC_AUTOCLOSE) == BST_CHECKED);
}

void CDlg_Download::NeedUpdate()
{
	if (IsWindow (m_hWnd) == FALSE)
		return;

	if (m_dld->pMgr->IsRunning ())
		SetDlgItemText (IDC_STOP, LS (L_STOP));
	else
		SetDlgItemText (IDC_STOP, LS (L_START));

	BOOL bDone = m_dld->pMgr->IsDone ();
	GetDlgItem (IDC_STOP)->EnableWindow (bDone == FALSE);
	GetDlgItem (IDC_OPENFILE)->EnableWindow (bDone);

	Update ();
}

void CDlg_Download::OnCancel() 
{
	OnHide ();
}

void CDlg_Download::OnStop() 
{
	DLDS_LIST vDlds;
	
	vDlds.push_back (m_dld);

	if (m_dld->pMgr->IsRunning ())
		_DldsMgr.StopDownloads (vDlds, TRUE);
	else
		_DldsMgr.StartDownloads (vDlds, TRUE);	
}

void CDlg_Download::OnOpenfile() 
{
	_DldsMgr.LaunchDownload (m_dld);
	OnHide ();	
}

void CDlg_Download::OnOpenfolder() 
{
	m_dld->pMgr->Do_OpenFolder ();
	if (m_dld->pMgr->IsDone ())
		OnHide ();
}

void CDlg_Download::OnAutolaunch() 
{
	m_dld->pMgr->set_LaunchWhenDone (IsDlgButtonChecked (IDC_AUTOLAUNCH) == BST_CHECKED);
}
