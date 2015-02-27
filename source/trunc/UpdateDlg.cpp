/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "UpdateDlg.h"
#include "misc.h"
#include "inetutil.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CUpdateDlg::CUpdateDlg(CWnd* pParent )
	: CDialog(CUpdateDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUpdateDlg)
		
	//}}AFX_DATA_INIT

	m_bCheckingByUser = true;
}

void CUpdateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUpdateDlg)
	DDX_Control(pDX, IDC_BPS, m_wndSpeed);
	DDX_Control(pDX, IDC_FILESIZE, m_wndSize);
	DDX_Control(pDX, IDC_TIMELEFT, m_wndTimeLeft);
	DDX_Control(pDX, IDC_PROGRESS, m_wndProgress);
	DDX_Control(pDX, IDC_MESSAGE, m_wndMsg);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CUpdateDlg, CDialog)
	//{{AFX_MSG_MAP(CUpdateDlg)
	ON_BN_CLICKED(IDC_DESC, OnDesc)
	ON_BN_CLICKED(ID_UPDATE, OnUpdate)
	ON_WM_TIMER()
	ON_WM_SYSCOMMAND()
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	ON_BN_CLICKED(ID_HELP, OnHelp)
	ON_WM_HELPINFO()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CUpdateDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	
	_UpdateMgr.SetEventsFunc (_UpdateMgrEvents, this);
	_UpdateMgr.SetDescEventsFunc (_UpdateMgrDescEvents, this);

	if (_UpdateMgr.IsRunning () == FALSE)
	{
		CheckForUpdate ();	
	}
	

	m_wndProgress.SetRange (0, 100);

	ApplyLanguage ();
	
	return TRUE;  
	              
}

void CUpdateDlg::OnDesc() 
{
	CString strWN;
	fs::list <CString>* pWN = _UpdateMgr.GetWhatNew ();

	for (int i = 0; i < pWN->size (); i++)
	{
		strWN += pWN->at (i);
		strWN += '\n';
	}

	MessageBox (strWN, LS (L_DESC), MB_ICONINFORMATION);
}

void CUpdateDlg::OnUpdate() 
{
	GetDlgItem (ID_UPDATE)->EnableWindow (FALSE);
	ShowGroup (TRUE);	
	_UpdateMgr.Update (IsDlgButtonChecked (IDC_FULLDISTRIB) == BST_CHECKED);	
	m_wndProgress.SetPos (0);
}

void CUpdateDlg::OnCancel() 
{
	_UpdateMgr.SetDescEventsFunc (NULL, 0);
	_UpdateMgr.SetEventsFunc (NULL, 0);

	_UpdateMgr.Stop ();
	CDialog::OnCancel();
}

void CUpdateDlg::_UpdateMgrEvents(fsUpdateMgrEvent ev, LPVOID lp)
{
	CUpdateDlg *pThis = (CUpdateDlg*) lp;

	

	switch (ev)
	{
		case UME_CONNECTING:
			
			pThis->m_wndMsg.SetWindowText (LS (L_CONNECTINGTOSERV));
		break;

		case UME_RETREIVINGUPDLST:
			
			_UpdateMgr.m_dldr->GetDP ()->uMaxAttempts = UINT_MAX;
			_UpdateMgr.m_dldr->ApplyProperties ();
			
			pThis->SetTimer (1, 1000, NULL);
			pThis->m_wndMsg.SetWindowText (LS (L_CHECKINGUPD));
			pThis->OnTimer (1);
		break;

		case UME_UPDLSTDONE:
			
			pThis->KillTimer (1);
			pThis->m_wndProgress.SetPos (100);
		break;

		case UME_NEWVERSIONAVAIL:
			
			pThis->ShowUpdateInfo ();
			if (pThis->m_bCheckingByUser == false && _UpdateMgr.m_enAUT == AUT_DLANDINST)
				pThis->PostMessage (WM_COMMAND, ID_UPDATE);
		break;

		case UME_NEWVERSIONNOTAVAIL:
			
			pThis->m_wndMsg.SetWindowText (LS (L_ALRNEWESTVER));
			pThis->SetDlgItemText (IDCANCEL, "OK");
		break;

		case UME_FATALERROR:
			
			char szErr [1000];
			fsIRToStr (_UpdateMgr.m_dldr->GetLastError (), szErr, sizeof (szErr));
			pThis->m_wndMsg.SetWindowText (szErr);
			pThis->KillTimer (1);
		break;

		case UME_VERIFYSIGN_ERROR:
			pThis->m_wndMsg.SetWindowText (LS (L_FILESIGNCHECK_FAILED));
			pThis->KillTimer (1);
		break;

		case UME_RETREIVINGUPDATE:
		{
			
			_UpdateMgr.m_dldr->GetDP ()->uMaxAttempts = UINT_MAX;
			_UpdateMgr.m_dldr->ApplyProperties ();
			CString str;
			str.Format (LS (L_VERAVAIL), _UpdateMgr.GetVersion (), _UpdateMgr.GetBuildNumber ());
			str += ". "; str += LS (L_DOWNLOADING); str += "...";
			pThis->m_wndMsg.SetWindowText (str);
			pThis->SetTimer (1, 1000, NULL);
			pThis->OnTimer (1);
		}
		break;

		case UME_UPDATEDONE:
			
			CString str;
			str.Format (LS (L_VERAVAIL), _UpdateMgr.GetVersion (), _UpdateMgr.GetBuildNumber ());
			str += ". "; str += LS (L_DONE); str += '.';
			pThis->m_wndMsg.SetWindowText (str);
			pThis->KillTimer (1);
			pThis->m_wndProgress.SetPos (100);
			pThis->OnUpdateDone ();
		break;
	}

	
}

void CUpdateDlg::CheckForUpdate()
{
	_UpdateMgr.CheckForUpdate (m_bCheckingByUser);
	GetDlgItem (ID_UPDATE)->EnableWindow (FALSE);
	GetDlgItem (IDC_DESC)->EnableWindow (FALSE);

	ShowGroup (TRUE);
}

void CUpdateDlg::ShowUpdateInfo()
{
	GetDlgItem (ID_UPDATE)->EnableWindow ();
	GetDlgItem (IDC_DESC)->EnableWindow ();

	CString str;
	str.Format (LS (L_VERAVAIL), _UpdateMgr.GetVersion (), _UpdateMgr.GetBuildNumber ());
	m_wndMsg.SetWindowText (str);

	ShowGroup (FALSE);

	str.Format (LS (L_FULLDISTR),  _UpdateMgr.GetVersion (), _UpdateMgr.GetFullSize ());
	SetDlgItemText (IDC_FULLDISTRIB, str);

	LPCSTR pszUpgSize = _UpdateMgr.GetUpgSize ();
	
	
	if (*pszUpgSize == 0)
	{
		

		str.Format (LS (L_UPGTOVER), _UpdateMgr.GetVersion ());
		SetDlgItemText (IDC_UPGDISTRIB, str);
		
		GetDlgItem (IDC_UPGDISTRIB)->EnableWindow (FALSE);
		CheckRadioButton (IDC_FULLDISTRIB, IDC_UPGDISTRIB, IDC_FULLDISTRIB);
	}
	else
	{
		str.Format (LS (L_UPGTOVER2), _UpdateMgr.GetVersion (), pszUpgSize);
		SetDlgItemText (IDC_UPGDISTRIB, str);
		CheckRadioButton (IDC_FULLDISTRIB, IDC_UPGDISTRIB, IDC_UPGDISTRIB);
	}

	ShowWindow (SW_SHOW);
	SetFocus ();
}

void CUpdateDlg::OnTimer(UINT )
{
	UINT64 uBytesLeft = _UpdateMgr.m_dldr->GetDownloader ()->GetBytesLeft ();
	UINT uSpeed = _UpdateMgr.m_dldr->GetDownloader ()->GetSpeed ();
	UINT64 uSize = _UpdateMgr.m_dldr->GetDownloader ()->GetSSFileSize ();

	if (uSize != _UI64_MAX && uSize != 0) 
	{
		m_wndProgress.SetPos (100 - (int) (double ((INT64)uBytesLeft) / (INT64)uSize * 100));
		if (uSpeed)
			m_wndTimeLeft.SetWindowText (fsTimeInSecondsToStr (DWORD ((INT64)uBytesLeft / (INT64)uSpeed)));
		else
			m_wndTimeLeft.SetWindowText ("");
	}
	else
	{
		m_wndTimeLeft.SetWindowText ("");
	}

	float val;
	char szDim [100];
	CString str;

	if (uSize != _UI64_MAX)
	{
		BytesToXBytes (uSize, &val, szDim);
		str.Format ("%.*g %s", val > 999 ? 4 : 3, val, szDim);
	}
	else
	{
		str = LS (L_UNKNOWN);
	}
	m_wndSize.SetWindowText (str);

	BytesToXBytes (uSpeed, &val, szDim);
	str.Format ("%.*g %s/s", val > 999 ? 4 : 3, val, szDim);
	m_wndSpeed.SetWindowText (str);
}

void CUpdateDlg::_UpdateMgrDescEvents(LPCSTR , LPVOID )
{
	
}

void CUpdateDlg::ShowGroup(BOOL bFirstGroup)
{
	UINT n1show = bFirstGroup ? SW_SHOW : SW_HIDE;
	UINT n2show = bFirstGroup ? SW_HIDE : SW_SHOW;

	GetDlgItem (IDC_FULLDISTRIB)->ShowWindow (n2show);
	GetDlgItem (IDC_UPGDISTRIB)->ShowWindow (n2show);
	GetDlgItem (IDC__TYPE)->ShowWindow (n2show);

	GetDlgItem (IDC__SPEED)->ShowWindow (n1show);
	GetDlgItem (IDC__TIMELEFT)->ShowWindow (n1show);
	GetDlgItem (IDC__SIZE)->ShowWindow (n1show);
	m_wndSize.ShowWindow (n1show);
	m_wndSpeed.ShowWindow (n1show);
	m_wndTimeLeft.ShowWindow (n1show);
}

void CUpdateDlg::OnSysCommand(UINT nID, LPARAM lParam) 
{
	if (nID == SC_CLOSE)
	{
		OnCancel ();
		return;
	}
	
	CDialog::OnSysCommand(nID, lParam);
}

void CUpdateDlg::OnUpdateDone()
{
	
	if (IDYES == MessageBox (LS (L_NEEDRESTART), LS (L_UPDDONE), MB_ICONQUESTION|MB_YESNO))
	{
		
		if (_UpdateMgr.StartUpdater ())
		{
			
			_DlgMgr.EndAllDialogs ();
			AfxGetApp ()->m_pMainWnd->PostMessage (WM_COMMAND, ID_NEED_EXIT);
		}	
		else
			MessageBox (LS (L_CANTFINDUPDATER), LS (L_ERR), MB_ICONERROR);
	}
	else
	{
		_UpdateMgr.UpdateOnNextStart ();	
	}

	EndDialog (IDOK);
}

void CUpdateDlg::OnContextMenu(CWnd* , CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();
}

void CUpdateDlg::OnWhatisthis() 
{
	_CHMgr.OnWT ();	
}

void CUpdateDlg::OnHelp() 
{
	
	::HtmlHelp (AfxGetApp ()->m_pMainWnd->m_hWnd, "Help\\Free Download Manager.chm::/Update.htm", HH_DISPLAY_TOPIC, NULL);	
}

void CUpdateDlg::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDCANCEL, L_CANCEL),
		fsDlgLngInfo (ID_HELP, L_HELP),
		fsDlgLngInfo (ID_UPDATE, L_TOUPDATE),
		fsDlgLngInfo (IDC_DESC, L_DESC),
		fsDlgLngInfo (IDC__TYPE, L_UPDATEUSING),
		fsDlgLngInfo (IDC__SPEED, L_SPEED),
		fsDlgLngInfo (IDC__TIMELEFT, L_TIMELEFT),
		fsDlgLngInfo (IDC__SIZE, L_SIZE),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_UPDATE);
}

void CUpdateDlg::PrepareCHMgr(CPoint point)
{
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC__TYPE, LS (L_UPDTYPEHERE)),
		fsCtrlContextHelp (IDC_FULLDISTRIB, LS (L_USINGFULLHERE)),
		fsCtrlContextHelp (IDC_UPGDISTRIB, LS (L_USINGPARTHERE)),
		fsCtrlContextHelp (ID_HELP, LS (L_UPDHELPHERE)),
		fsCtrlContextHelp (IDC_DESC, LS (L_DESCHERE)),
		fsCtrlContextHelp (ID_UPDATE, LS (L_UPDATEHERE)),
		fsCtrlContextHelp (IDCANCEL, LS (L_UPDCANCELHERE)),
	};

    static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));
}

BOOL CUpdateDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	RECT rc;
	CWnd *pItem = GetDlgItem (pHelpInfo->iCtrlId);
	if (pItem == NULL)
		return TRUE;
	pItem->GetWindowRect (&rc);
	if (PtInRect (&rc, pHelpInfo->MousePos) == FALSE)
	{
		pHelpInfo->MousePos.x = rc.left + (rc.right - rc.left) / 2;
		pHelpInfo->MousePos.y = rc.top + (rc.bottom - rc.top) / 2;
	}
	PrepareCHMgr (pHelpInfo->MousePos);
	_CHMgr.OnWT ();
	return TRUE;
}
