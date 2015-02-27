/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Schedule_WTSPage.h"
#include "fsScheduleMgr.h"
#include "DownloadsWnd.h"
#include "system.h"

extern CDownloadsWnd* _pwndDownloads;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CSchedule_WTSPage, CPropertyPage)

CSchedule_WTSPage::CSchedule_WTSPage() : CPropertyPage(CSchedule_WTSPage::IDD)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = LS (L_WTS);
}

CSchedule_WTSPage::~CSchedule_WTSPage()
{
}

void CSchedule_WTSPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSchedule_WTSPage)
	DDX_Control(pDX, IDC_BPS, m_wndBPS);
	DDX_Control(pDX, IDC_UNSELDLDS, m_wndUnselDlds);
	DDX_Control(pDX, IDC_SELDLDS, m_wndSelDlds);
	DDX_Control(pDX, IDC_TUM, m_wndTUM);
	DDX_Control(pDX, IDC_TOUNSEL, m_btnToUnsel);
	DDX_Control(pDX, IDC_TOSEL, m_btnToSel);
	DDX_Control(pDX, IDC_SHUTDOWNTYPE, m_wndShutdownType);
	DDX_Control(pDX, IDC_DIALCONNECTION, m_wndDialConnection);
	DDX_Control(pDX, IDC_CONNECTION, m_wndConnection);
	DDX_Control(pDX, IDC_CHOOSENAME, m_btnChoose);
	DDX_Control(pDX, IDC_WTS, m_wndWTS);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSchedule_WTSPage, CPropertyPage)
	//{{AFX_MSG_MAP(CSchedule_WTSPage)
	ON_CBN_SELCHANGE(IDC_WTS, OnSelchangeWts)
	ON_EN_CHANGE(IDC_PROGNAME, OnChangeProgname)
	ON_EN_CHANGE(IDC_ARGUMENTS, OnChangeArguments)
	ON_BN_CLICKED(IDC_CHOOSENAME, OnChoosename)
	ON_NOTIFY(NM_CLICK, IDC_UNSELDLDS, OnClickUnseldlds)
	ON_NOTIFY(NM_CLICK, IDC_SELDLDS, OnClickSeldlds)
	ON_BN_CLICKED(IDC_TOSEL, OnTosel)
	ON_BN_CLICKED(IDC_TOUNSEL, OnTounsel)
	ON_CBN_SELCHANGE(IDC_CONNECTION, OnSelchangeConnection)
	ON_BN_CLICKED(IDC_USEMAXATTEMPTS, OnUsemaxattempts)
	ON_BN_CLICKED(IDC_USEPAUSE, OnUsepause)
	ON_EN_CHANGE(IDC_REDIALPAUSE, OnChangeRedialpause)
	ON_EN_CHANGE(IDC_MAXREDIALS, OnChangeMaxredials)
	ON_CBN_SELCHANGE(IDC_DIALCONNECTION, OnSelchangeDialconnection)
	ON_BN_CLICKED(IDC_HANGUPALL, OnHangupall)
	ON_CBN_SELCHANGE(IDC_TUM, OnSelchangeTum)
	ON_CBN_SELCHANGE(IDC_SHUTDOWNTYPE, OnSelchangeShutdowntype)
	ON_CBN_SELCHANGE(IDC_BPS, OnSelchangeBps)
	ON_BN_CLICKED(IDC_HANGUPIFLESS, OnHangupifless)
	ON_BN_CLICKED(IDC_TRYAGAIN, OnTryagain)
	ON_BN_CLICKED(IDC_NOMORETHAN, OnNomorethan)
	ON_EN_CHANGE(IDC_TIMES, OnChangeTimes)
	ON_BN_CLICKED(IDC_FORCEEXIT, OnForceexit)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	ON_WM_HELPINFO()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CSchedule_WTSPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();

	m_btnChoose.SetIcon (SICO (IDI_CHOOSEFOLDER));
	m_btnToSel.SetIcon (SICO (IDI_TOSEL));
	m_btnToUnsel.SetIcon (SICO (IDI_TOUNSEL));

	m_wndShutdownType.AddString (LS (L_SHUTDOWN));
	m_wndShutdownType.AddString (LS (L_RESTARTCOMP));
	m_wndShutdownType.AddString (LS (L_LOGOFF));
	m_wndShutdownType.AddString (LS (L_HIBERNATE));
	m_wndShutdownType.AddString (LS (L_STANDBY));

	m_wndTUM.AddString (LS (L_LIGHT));
	m_wndTUM.AddString (LS (L_MEDIUM));
	m_wndTUM.AddString (LS (L_HEAVY));

	m_wndBPS.AddString ("28.8K");
	m_wndBPS.AddString ("33.6K");
	m_wndBPS.AddString ("56K");

	if (m_ras.EnumEntries ())
	{
		UINT c = m_ras.GetEntriesCount ();
		while (c--)
		{
			m_wndConnection.AddString (m_ras.GetEntry (c));
			m_wndDialConnection.AddString (m_ras.GetEntry (c));
		}
	}

	m_wndConnection.SetCurSel (0);
	CheckRadioButton (IDC_RAD_ENABLE, IDC_RAD_INVERT, IDC_RAD_ENABLE);

	CSpinButtonCtrl *pSpin = (CSpinButtonCtrl*) GetDlgItem (IDC_MAXREDIALSSPIN);
	pSpin->SetRange (1, UD_MAXVAL);
	SetDlgItemInt (IDC_MAXREDIALS, 1);
	pSpin = (CSpinButtonCtrl*) GetDlgItem (IDC_REDIALPAUSESPIN);
	pSpin->SetRange (1, UD_MAXVAL);
	SetDlgItemInt (IDC_REDIALPAUSE, 1);
	pSpin = (CSpinButtonCtrl*) GetDlgItem (IDC_TIMESSPIN);
	pSpin->SetRange (1, UD_MAXVAL);
	SetDlgItemInt (IDC_TIMES, 1);

	CRect rc;
	m_wndSelDlds.GetClientRect (&rc);
	m_wndUnselDlds.InsertColumn (0, LS (L_ALLDLDS), LVCFMT_LEFT, rc.right);
	m_wndSelDlds.InsertColumn (0, "", LVCFMT_LEFT, rc.right);
	
	m_wndWTS.AddString (LS (L_LAUNCHPRG));
	m_wndWTS.AddString (LS (L_STARTDLDS));
	m_wndWTS.AddString (LS (L_STOPDLDS));
	m_wndWTS.AddString (LS (L_STARTALLDLDS));
	m_wndWTS.AddString (LS (L_STOPALLDLDS));
	m_wndWTS.AddString (LS (L_DIALVIAMODEM));
	m_wndWTS.AddString (LS (L_HANGMODEM));
	m_wndWTS.AddString (LS (L_CHANGETUM));
	m_wndWTS.AddString (LS (L_EXITFROM));
	m_wndWTS.AddString (LS (L_SHUTDOWNCOMP));
	m_wndWTS.AddString (LS (L_PAUSEALLDOWNLOADS));

	m_bNoRASNotified = FALSE;

	for (int i = 0; i < 11; i++)
		ShowGroup (i, FALSE);

	m_iWTS = m_task->wts.enType;
	m_wndWTS.SetCurSel (m_iWTS);
	OnSelchangeWts ();

	if (m_task->wts.enType != WTS_PROGRAM)
	{
		SetDlgItemText (IDC_PROGNAME, _App.Scheduler_LastTask_ProgName ());
		SetDlgItemText (IDC_ARGUMENTS, _App.Scheduler_LastTask_ProgArgs ());
	}
	
	ApplyLanguage ();
	
	return TRUE;  
	              
}

void CSchedule_WTSPage::ShowGroup(int iGrp, BOOL bShow, BOOL bEnabled)
{
	
	
	
	static UINT ppGrpID [][20] = {
		{5, IDC__PROGNAME, IDC_PROGNAME, IDC_CHOOSENAME, IDC__ARGUMENTS, IDC_ARGUMENTS},
		{5, IDC_SELDLDS, IDC_TOSEL, IDC_TOUNSEL, IDC_UNSELDLDS, IDC_RESTARTDLDIFDONE},
		{4, IDC_SELDLDS, IDC_TOSEL, IDC_TOUNSEL, IDC_UNSELDLDS},
		{0},	
		{0},	
		{17, IDC__CONNECTION, IDC_DIALCONNECTION, IDC_USEMAXATTEMPTS, IDC_MAXREDIALS, IDC_MAXREDIALSSPIN, IDC_USEPAUSE, IDC_REDIALPAUSE, IDC_REDIALPAUSESPIN, IDC__DIALING, IDC__IFSUCCESSFULL, IDC_HANGUPIFLESS, IDC_BPS, IDC_TRYAGAIN, IDC_NOMORETHAN, IDC_TIMES, IDC_TIMESSPIN, IDC__TIMES},
		{3, IDC_HANGUPALL, IDC__HANGUP, IDC_CONNECTION},
		{2, IDC__TUM, IDC_TUM},
		{0},	
		{3, IDC__TYPE, IDC_SHUTDOWNTYPE, IDC_FORCEEXIT},
		{3, IDC_RAD_ENABLE, IDC_RAD_DISABLE, IDC_RAD_INVERT},
	};
	
	UINT nShow = bShow ? SW_SHOW : SW_HIDE;

	for (UINT i = 0; i < ppGrpID [iGrp][0]; i++)
	{
		CWnd *pWnd = GetDlgItem (ppGrpID [iGrp][i+1]);
		pWnd->ShowWindow (nShow);
		if (bEnabled == FALSE)
			pWnd->EnableWindow (FALSE);
	}
}

void CSchedule_WTSPage::OnSelchangeWts() 
{
	
	ShowGroup (m_iWTS, FALSE);

	
	m_iWTS = m_wndWTS.GetCurSel ();

	LPCSTR psz1 = "", psz2 = "";

	switch (m_iWTS)
	{
		case WTS_PROGRAM:
			
			if (m_iWTS == m_task->wts.enType)
			{
				
				psz1 = m_task->wts.prog.pszName;
				psz2 = m_task->wts.prog.pszArgs;
			}

			SetDlgItemText (IDC_PROGNAME, psz1);
			SetDlgItemText (IDC_ARGUMENTS, psz2);
		break;

		case WTS_STARTDOWNLOAD:
			BuildDownloadsList ();
			CheckDlgButton (IDC_RESTARTDLDIFDONE, 
				m_task->wts.dlds.dwFlags & SDI_RESTART_COMPLETED_DOWNLOADS ? BST_CHECKED : BST_UNCHECKED);
			LVCOLUMN col;
			col.mask = LVCF_TEXT;
			col.pszText = (LPSTR) LS (L_DLDSTOSTART);
			m_wndSelDlds.SetColumn (0, &col);
		break;

		case WTS_STOPDOWNLOAD:
			BuildDownloadsList ();
			col.mask = LVCF_TEXT;
			col.pszText = (LPSTR) LS (L_DLDSTOSTOP);
			m_wndSelDlds.SetColumn (0, &col);
		break;

		case WTS_DIAL:
			if (WTS_DIAL == m_task->wts.enType)
			{
				if (m_task->wts.dial.pszConnection)
					m_wndDialConnection.SelectString (-1, m_task->wts.dial.pszConnection);
				if (m_task->wts.dial.cAttempts != UINT_MAX)
					SetDlgItemInt (IDC_MAXREDIALS, m_task->wts.dial.cAttempts);
				CheckDlgButton (IDC_USEMAXATTEMPTS, m_task->wts.dial.cAttempts != UINT_MAX);
				
				if (m_task->wts.dial.cPauseBetween != 0)
					SetDlgItemInt (IDC_REDIALPAUSE, m_task->wts.dial.cPauseBetween);
				CheckDlgButton (IDC_USEPAUSE, m_task->wts.dial.cPauseBetween != 0 ? BST_CHECKED : BST_UNCHECKED);

				int iCur = -1;
				switch (m_task->wts.dial.dwHangupLess)
				{
					case 28800:
						iCur = 0;
						break;

					case 33600:
						iCur = 1;
						break;

					case 56000:
						iCur = 2;
						break;
				}

				if (iCur != -1)
					m_wndBPS.SetCurSel (iCur);
				else
					m_wndBPS.SetCurSel (0);

				CheckDlgButton (IDC_HANGUPIFLESS, iCur == -1 ? BST_UNCHECKED : BST_CHECKED);

				CheckDlgButton (IDC_TRYAGAIN, m_task->wts.dial.cAgains > 0 ? BST_CHECKED : BST_UNCHECKED);
				CheckDlgButton (IDC_NOMORETHAN, m_task->wts.dial.cAgains == UINT_MAX || m_task->wts.dial.cAgains == 0 ? BST_UNCHECKED : BST_CHECKED);

				SetDlgItemInt (IDC_TIMES, 1);

				if (m_task->wts.dial.cAgains != UINT_MAX && m_task->wts.dial.cAgains)
					SetDlgItemInt (IDC_TIMES, m_task->wts.dial.cAgains, FALSE);
			}
			else
			{
				m_wndDialConnection.SetCurSel (0);
				SetDlgItemInt (IDC_MAXREDIALS, 100);
				CheckDlgButton (IDC_USEMAXATTEMPTS, BST_CHECKED);
				
				SetDlgItemInt (IDC_REDIALPAUSE, 5);
				CheckDlgButton (IDC_USEPAUSE, BST_CHECKED);

				CheckDlgButton (IDC_HANGUPIFLESS, BST_UNCHECKED);
				SetDlgItemInt (IDC_TIMES, 1);
				m_wndBPS.SetCurSel (0);
			}

			if (m_ras.GetEntriesCount () == 0)
			{
				if (m_bNoRASNotified == FALSE)
				{
					MessageBox (LS (L_NODIALENTRIES), LS (L_ERR), MB_ICONEXCLAMATION);
					m_bNoRASNotified = TRUE;
				}
			}

		break;

		case WTS_HANGUP:
			if (WTS_HANGUP == m_task->wts.enType)
			{
				if (m_task->wts.pszHangupConnection)
					m_wndConnection.SelectString (-1, m_task->wts.pszHangupConnection);

				CheckDlgButton (IDC_HANGUPALL, m_task->wts.pszHangupConnection ? BST_UNCHECKED : BST_CHECKED);
			}
			else
			{
				CheckDlgButton (IDC_HANGUPALL, BST_CHECKED);
			}

			if (m_ras.GetEntriesCount () == 0)
			{
				if (m_bNoRASNotified == FALSE)
				{
					MessageBox (LS (L_NODIALENTRIES), LS (L_ERR), MB_ICONEXCLAMATION);
					m_bNoRASNotified = TRUE;
				}
			}

		break;

		case WTS_CHANGE_TUM:
			if (m_iWTS == m_task->wts.enType)
				m_wndTUM.SetCurSel (m_task->wts.enTUM);
			else
				m_wndTUM.SetCurSel (0);
		break;

		case WTS_SHUTDOWN:
			if (m_iWTS == m_task->wts.enType)
			{
				m_wndShutdownType.SetCurSel (m_task->wts.shutdown.enShutdown);
				CheckDlgButton (IDC_FORCEEXIT, m_task->wts.shutdown.bForce ? BST_CHECKED : BST_UNCHECKED);
			}
			else
			{
				m_wndShutdownType.SetCurSel (0);
				CheckDlgButton (IDC_FORCEEXIT, BST_UNCHECKED);
			}
		break;

		case WTS_RESTRAINALLDLDS:
			if (WTS_RESTRAINALLDLDS == m_task->wts.enType)
			{
				CheckRadioButton (IDC_RAD_ENABLE, IDC_RAD_INVERT, IDC_RAD_ENABLE + 
					m_task->wts.enRAD);
			}
		break;
	}

	
	
	if (m_bNoRASNotified && 
		(m_iWTS == WTS_DIAL || m_iWTS == WTS_HANGUP) )
	{
		
		ShowGroup (m_iWTS, TRUE, FALSE);
	}
	else
	{
		
		ShowGroup (m_iWTS);
		UpdateEnabled ();
		SetModified ();
	}
}

void CSchedule_WTSPage::BuildDownloadsList()
{
	m_wndUnselDlds.DeleteAllItems ();
	m_wndSelDlds.DeleteAllItems ();

	DLDS_LIST vSel, vUnsel;

	_DldsMgr.LockList (true);

	int cDlds = _DldsMgr.GetCount ();
	vUnsel.reserve (cDlds);
	
	for (int i = 0; i < cDlds; i++)
	{
		vmsDownloadSmartPtr dld = _DldsMgr.GetDownload (i);	
		BOOL bToUnsel = TRUE;

		if (m_task->wts.enType == m_iWTS && m_task->wts.dlds.pvIDs != NULL)
		{
			for (int i = m_task->wts.dlds.pvIDs->size () - 1; i >= 0; i--)
			{
				
				if (m_task->wts.dlds.pvIDs->at (i) == dld->nID)
				{
					
					bToUnsel = FALSE;
					break;
				}
			}
		}

		if (bToUnsel)
			vUnsel.push_back (dld);
		else
			vSel.push_back (dld);
	}

	_DldsMgr.UnlockList (true);

	for (size_t i = 0; i < vSel.size (); i++)
	{
		m_wndSelDlds.InsertItem (i, vSel [i]->pMgr->get_URL (), 0);
		m_wndSelDlds.SetItemData (i, vSel [i]->nID);
	}

	for (size_t i = 0; i < vUnsel.size (); i++)
	{
		m_wndUnselDlds.InsertItem (i, vUnsel [i]->pMgr->get_URL (), 0);
		m_wndUnselDlds.SetItemData (i, vUnsel [i]->nID);
	}
}

void CSchedule_WTSPage::UpdateEnabled()
{
	BOOL b;

	switch (m_iWTS)
	{
		case WTS_STARTDOWNLOAD:
		case WTS_STOPDOWNLOAD:
			m_btnToSel.EnableWindow (m_wndUnselDlds.GetSelectedCount ());
			m_btnToUnsel.EnableWindow (m_wndSelDlds.GetSelectedCount ());
			break;

		case WTS_DIAL:
			b = IsDlgButtonChecked (IDC_USEMAXATTEMPTS) == BST_CHECKED;
			GetDlgItem (IDC_MAXREDIALS)->EnableWindow (b);
			GetDlgItem (IDC_MAXREDIALSSPIN)->EnableWindow (b);

			b = IsDlgButtonChecked (IDC_USEPAUSE) == BST_CHECKED;
			GetDlgItem (IDC_REDIALPAUSE)->EnableWindow (b);
			GetDlgItem (IDC_REDIALPAUSESPIN)->EnableWindow (b);

			b = IsDlgButtonChecked (IDC_HANGUPIFLESS) == BST_CHECKED;
			GetDlgItem (IDC_BPS)->EnableWindow (b);
			GetDlgItem (IDC_TRYAGAIN)->EnableWindow (b);
			b = b && IsDlgButtonChecked (IDC_TRYAGAIN) == BST_CHECKED;
			GetDlgItem (IDC_NOMORETHAN)->EnableWindow (b);
			b = b && IsDlgButtonChecked (IDC_NOMORETHAN);
			GetDlgItem (IDC_TIMES)->EnableWindow (b);
			GetDlgItem (IDC_TIMESSPIN)->EnableWindow (b);
			GetDlgItem (IDC__TIMES)->EnableWindow (b);
			break;

		case WTS_HANGUP:
			b = IsDlgButtonChecked (IDC_HANGUPALL) == BST_UNCHECKED;
			GetDlgItem (IDC__HANGUP)->EnableWindow (b);
			m_wndConnection.EnableWindow (b);
			break;
	}
}

void CSchedule_WTSPage::OnChangeProgname() 
{
	SetModified ();	
}

void CSchedule_WTSPage::OnChangeArguments() 
{
	SetModified ();
}

void CSchedule_WTSPage::OnChoosename() 
{
	CString strFilter;
	strFilter.Format ("%s (*.com; *.exe)|*.com;*.exe|%s (*.*)|*.*||", LS (L_APPS), LS (L_ALLFILES));
	CFileDialog dlg (TRUE, NULL, NULL, OFN_HIDEREADONLY|OFN_FILEMUSTEXIST|OFN_NOCHANGEDIR, 
		strFilter, this);	

    _DlgMgr.OnDoModal (&dlg);

	if (IDOK != dlg.DoModal ())
	{
		_DlgMgr.OnEndDialog (&dlg);
		return;
	}

    _DlgMgr.OnEndDialog (&dlg);

	SetDlgItemText (IDC_PROGNAME, dlg.GetPathName ());
}

void CSchedule_WTSPage::OnClickUnseldlds(NMHDR* , LRESULT* pResult) 
{
	UpdateEnabled ();
	*pResult = 0;
}

void CSchedule_WTSPage::OnClickSeldlds(NMHDR* , LRESULT* pResult) 
{
	UpdateEnabled ();	
	*pResult = 0;
}

void CSchedule_WTSPage::OnTosel() 
{
	POSITION pos = m_wndUnselDlds.GetFirstSelectedItemPosition ();
	int cItems = m_wndSelDlds.GetItemCount ();
	fs::list <int> vItems;

	while (pos)
	{
		int iItem = m_wndUnselDlds.GetNextSelectedItem (pos);
		m_wndSelDlds.InsertItem (cItems, m_wndUnselDlds.GetItemText (iItem, 0), 0);
		m_wndSelDlds.SetItemData (cItems++, m_wndUnselDlds.GetItemData (iItem));
		vItems.add (iItem);
	}

	for (int i = vItems.size () - 1; i >= 0; i--)
	{
		m_wndUnselDlds.DeleteItem (vItems [i]);
	}

	UpdateEnabled ();
	SetModified ();
}

void CSchedule_WTSPage::OnTounsel() 
{
	POSITION pos = m_wndSelDlds.GetFirstSelectedItemPosition ();
	int cItems = m_wndUnselDlds.GetItemCount ();
	fs::list <int> vItems;

	while (pos)
	{
		int iItem = m_wndSelDlds.GetNextSelectedItem (pos);
		m_wndUnselDlds.InsertItem (cItems, m_wndSelDlds.GetItemText (iItem, 0), 0);
		m_wndUnselDlds.SetItemData (cItems++, m_wndSelDlds.GetItemData (iItem));
		vItems.add (iItem);
	}

	for (int i = vItems.size () - 1; i >= 0; i--)
	{
		m_wndSelDlds.DeleteItem (vItems [i]);
	}

	UpdateEnabled ();
	SetModified ();
}

void CSchedule_WTSPage::OnSelchangeConnection() 
{
	SetModified ();	
}

void CSchedule_WTSPage::OnUsemaxattempts() 
{
	SetModified ();
	UpdateEnabled ();
}

void CSchedule_WTSPage::OnUsepause() 
{
	SetModified ();
	UpdateEnabled ();
}

void CSchedule_WTSPage::OnChangeRedialpause() 
{
	SetModified ();
}

void CSchedule_WTSPage::OnChangeMaxredials() 
{
	SetModified ();
}

void CSchedule_WTSPage::OnSelchangeDialconnection() 
{
	SetModified ();	
}

void CSchedule_WTSPage::OnHangupall() 
{
	UpdateEnabled ();
	SetModified ();
}

void CSchedule_WTSPage::OnSelchangeTum() 
{
	SetModified ();	
}

void CSchedule_WTSPage::OnSelchangeShutdowntype() 
{
	SetModified ();	
}

void CSchedule_WTSPage::OnSelchangeBps() 
{
	SetModified ();	
}

void CSchedule_WTSPage::OnHangupifless() 
{
	if (fsSysGetOsMajorVersion () < 5)
	{
		MessageBox (LS (L_AVAILON2000), LS (L_ERR), MB_ICONEXCLAMATION);
		CheckDlgButton (IDC_HANGUPIFLESS, BST_UNCHECKED);
		return;
	}

	SetModified ();
	UpdateEnabled ();
}

void CSchedule_WTSPage::OnTryagain() 
{
	SetModified ();
	UpdateEnabled ();	
}

void CSchedule_WTSPage::OnNomorethan() 
{
	SetModified ();
	UpdateEnabled ();	
}

void CSchedule_WTSPage::OnChangeTimes() 
{
	SetModified ();
}

BOOL CSchedule_WTSPage::OnApply() 
{
	switch (m_iWTS)
	{
		case WTS_PROGRAM:
			if (FALSE == ApplyProg ())
				return FALSE;
		break;

		case WTS_STARTDOWNLOAD:
		case WTS_STOPDOWNLOAD:
			if (FALSE == ApplyStartStopDownloads ())
				return FALSE;
			m_task->wts.enType = (fsWhatToStartType) m_iWTS;
		break;

		case WTS_STARTALLDOWNLOADS:
		case WTS_STOPALLDOWNLOADS:
		case WTS_EXIT:
			FreeSchedule ();
			m_task->wts.enType = (fsWhatToStartType) m_iWTS;
		break;

		case WTS_DIAL:
			if (FALSE == ApplyDial ())
				return FALSE;
		break;

		case WTS_HANGUP:
			if (FALSE == ApplyHangup ())
				return FALSE;
		break;

		case WTS_CHANGE_TUM:
			FreeSchedule ();
			m_task->wts.enType = WTS_CHANGE_TUM;
			m_task->wts.enTUM = (fsTUM) m_wndTUM.GetCurSel ();
		break;

		case WTS_SHUTDOWN:
			FreeSchedule ();
			m_task->wts.enType = WTS_SHUTDOWN;
			m_task->wts.shutdown.enShutdown = (fsShutdownType) m_wndShutdownType.GetCurSel ();
			m_task->wts.shutdown.bForce = IsDlgButtonChecked (IDC_FORCEEXIT) == BST_CHECKED;
		break;

		case WTS_RESTRAINALLDLDS:
			FreeSchedule ();
			m_task->wts.enType = WTS_RESTRAINALLDLDS;
			if (IsDlgButtonChecked (IDC_RAD_ENABLE) == BST_CHECKED)
				m_task->wts.enRAD = RAD_ENABLE;
			else if (IsDlgButtonChecked (IDC_RAD_DISABLE) == BST_CHECKED)
				m_task->wts.enRAD = RAD_DISABLE;
			else
				m_task->wts.enRAD = RAD_INVERT;			
		break;
	}

	fsScheduleEx* pschScheduleParam = (fsScheduleEx*)m_task;
	if (pschScheduleParam->m_ppoTaskWrapper)
		pschScheduleParam->m_ppoTaskWrapper->setDirty();
	
	return CPropertyPage::OnApply();
}

BOOL CSchedule_WTSPage::ApplyProg()
{
	CString strProg, strArgs;
			
	GetDlgItemText (IDC_PROGNAME, strProg);
	GetDlgItemText (IDC_ARGUMENTS, strArgs);

	if (strProg.GetLength () == 0)
	{
		MessageBox (LS (L_ENTERPRGNAME), LS (L_INPERR), MB_ICONEXCLAMATION);
		return FALSE;
	}

	FreeSchedule ();

	m_task->wts.enType = (fsWhatToStartType) m_iWTS;

	fsnew (m_task->wts.prog.pszName, char, strProg.GetLength () + 1);
	fsnew (m_task->wts.prog.pszArgs, char, strArgs.GetLength () + 1);

	strcpy (m_task->wts.prog.pszName, strProg);
	strcpy (m_task->wts.prog.pszArgs, strArgs);

	fsScheduleEx* pschScheduleParam = (fsScheduleEx*)m_task;
	if (pschScheduleParam->m_ppoTaskWrapper)
		pschScheduleParam->m_ppoTaskWrapper->setDirty();

	return TRUE;
}

void CSchedule_WTSPage::FreeSchedule()
{
	fsScheduleMgr::FreeTask (m_task);
}

BOOL CSchedule_WTSPage::ApplyStartStopDownloads()
{
	if (m_wndSelDlds.GetItemCount () == 0)
	{
		MessageBox (LS (L_ENTERDLDS), LS (L_INPERR), MB_ICONEXCLAMATION);
		return FALSE;
	}

	FreeSchedule ();

	fsnew1 (m_task->wts.dlds.pvIDs, fs::list <UINT>);

	int cItems = m_wndSelDlds.GetItemCount ();

	for (int i = 0; i < cItems; i++)
		m_task->wts.dlds.pvIDs->add (m_wndSelDlds.GetItemData (i));

	m_task->wts.dlds.dwFlags = 0;
	if (IsDlgButtonChecked (IDC_RESTARTDLDIFDONE) == BST_CHECKED)
		m_task->wts.dlds.dwFlags |= SDI_RESTART_COMPLETED_DOWNLOADS;

	fsScheduleEx* pschScheduleParam = (fsScheduleEx*)m_task;
	if (pschScheduleParam->m_ppoTaskWrapper)
		pschScheduleParam->m_ppoTaskWrapper->setDirty();

	return TRUE;
}

BOOL CSchedule_WTSPage::ApplyDial()
{
	if (m_ras.GetEntriesCount () == 0)
		return FALSE;

	CString strConn;
	UINT uMaxAtt, uPause;
	DWORD dwHL = 0;
	UINT cAgains = 0;

	m_wndDialConnection.GetLBText (m_wndDialConnection.GetCurSel (), strConn);

	if (IsDlgButtonChecked (IDC_USEMAXATTEMPTS) == BST_CHECKED)
		uMaxAtt = GetDlgItemInt (IDC_MAXREDIALS);
	else
		uMaxAtt = UINT_MAX;

	if (uMaxAtt == 0)
	{
		CString str; str.Format (LS (L_ENTERGREATER), 0);
		MessageBox (str, LS (L_INPERR), MB_ICONEXCLAMATION);
		CEdit *pEdit = (CEdit*) GetDlgItem (IDC_MAXREDIALS);
		pEdit->SetSel (0, -1);
		pEdit->SetFocus ();
		return FALSE;
	}

	if (IsDlgButtonChecked (IDC_USEPAUSE) == BST_CHECKED)
		uPause = GetDlgItemInt (IDC_REDIALPAUSE);
	else
		uPause = 0;

	if (IsDlgButtonChecked (IDC_HANGUPIFLESS) == BST_CHECKED)
	{
		int iCur = m_wndBPS.GetCurSel ();
		switch (iCur)
		{
			case 0:
				dwHL = 28800;
				break;

			case 1:
				dwHL = 33600;
				break;

			case 2:
				dwHL = 56000;
				break;
		}

		if (IsDlgButtonChecked (IDC_TRYAGAIN) == BST_CHECKED)
		{
			if (IsDlgButtonChecked (IDC_NOMORETHAN) == BST_CHECKED)
				cAgains = GetDlgItemInt (IDC_TIMES);
			else
				cAgains = UINT_MAX;

			if (cAgains == 0)
			{
				CString str; str.Format (LS (L_ENTERGREATER), 0);
				MessageBox (str, LS (L_INPERR), MB_ICONEXCLAMATION);
				CEdit *pEdit = (CEdit*) GetDlgItem (IDC_TIMES);
				pEdit->SetSel (0, -1);
				pEdit->SetFocus ();
				return FALSE;
			}
		}
	}
	
	FreeSchedule ();
	m_task->wts.enType = WTS_DIAL;
	
	fsnew (m_task->wts.dial.pszConnection, char, strConn.GetLength () + 1);
	strcpy (m_task->wts.dial.pszConnection, strConn);

	m_task->wts.dial.cAttempts = uMaxAtt;
	m_task->wts.dial.cPauseBetween = uPause;

	m_task->wts.dial.dwHangupLess = dwHL;
	m_task->wts.dial.cAgains = cAgains;

	fsScheduleEx* pschScheduleParam = (fsScheduleEx*)m_task;
	if (pschScheduleParam->m_ppoTaskWrapper)
		pschScheduleParam->m_ppoTaskWrapper->setDirty();

	return TRUE;
}

BOOL CSchedule_WTSPage::ApplyHangup()
{
	if (m_ras.GetEntriesCount () == 0)
		return FALSE;

	FreeSchedule ();

	m_task->wts.enType = WTS_HANGUP;

	if (IsDlgButtonChecked (IDC_HANGUPALL) == BST_CHECKED)
	{
		m_task->wts.pszHangupConnection = NULL;
	}
	else
	{
		CString strConn;
		m_wndConnection.GetLBText (m_wndConnection.GetCurSel (), strConn);

		fsnew (m_task->wts.pszHangupConnection, char, strConn.GetLength () + 1);
		strcpy (m_task->wts.pszHangupConnection, strConn);
	}

	fsScheduleEx* pschScheduleParam = (fsScheduleEx*)m_task;
	if (pschScheduleParam->m_ppoTaskWrapper)
		pschScheduleParam->m_ppoTaskWrapper->setDirty();

	return TRUE;
}

void CSchedule_WTSPage::OnForceexit() 
{
	SetModified ();	
}

void CSchedule_WTSPage::OnContextMenu(CWnd* , CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();
}

void CSchedule_WTSPage::OnWhatisthis() 
{
	_CHMgr.OnWT ();	
}

void CSchedule_WTSPage::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_USEMAXATTEMPTS, L_MAXDIALATTEMPTS),
		fsDlgLngInfo (IDC_USEPAUSE, L_PAUSEBETWEENDIAL),
		fsDlgLngInfo (IDC_HANGUPIFLESS, L_HANGUPIFLESS),
		fsDlgLngInfo (IDC_TRYAGAIN, L_TRYAGAIN),
		fsDlgLngInfo (IDC_NOMORETHAN, L_NOMORETHAN),
		fsDlgLngInfo (IDC__CONNECTION, L_CONNECTIONTOUSE),
		fsDlgLngInfo (IDC__DIALING, L_DIAL),
		fsDlgLngInfo (IDC__IFSUCCESSFULL, L_IFSUCC),
		fsDlgLngInfo (IDC__TIMES, L_TIMES),
		fsDlgLngInfo (IDC_HANGUPALL, L_HANGUPALL),
		fsDlgLngInfo (IDC__HANGUP, L_CONNTOHANG),
		fsDlgLngInfo (IDC__PROGNAME, L_PRGNAME),
		fsDlgLngInfo (IDC__ARGUMENTS, L_ARGS),
		fsDlgLngInfo (IDC__TYPE, L_SHUTDOWNTYPE),
		fsDlgLngInfo (IDC_FORCEEXIT, L_FORCEAPPS),
		fsDlgLngInfo (IDC_RAD_ENABLE, L_ENABLE),
		fsDlgLngInfo (IDC_RAD_DISABLE, L_DISABLE),
		fsDlgLngInfo (IDC_RAD_INVERT, L_SWITCH),
		fsDlgLngInfo (IDC_RESTARTDLDIFDONE, L_RESTARTCOMPLDLDS),
	};

	CString str = LS (L_CHANGETUMTO); str += ':';
	SetDlgItemText (IDC__TUM, str);

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}

void CSchedule_WTSPage::PrepareCHMgr(CPoint point)
{
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC__TUM, LS (L_SETTUMHERE)),
		fsCtrlContextHelp (IDC_TUM, LS (L_SETTUMHERE)),
		fsCtrlContextHelp (IDC__CONNECTION, LS (L_CHOOSEENTRY)),
		fsCtrlContextHelp (IDC_DIALCONNECTION, LS (L_CHOOSEENTRY)),
		fsCtrlContextHelp (IDC_USEMAXATTEMPTS, LS (L_MAXDIALSHERE)),
		fsCtrlContextHelp (IDC_USEPAUSE, LS (L_USEPAUSEHERE)),
		fsCtrlContextHelp (IDC_HANGUPIFLESS, LS (L_HANGUPIFLESSHERE)),
		fsCtrlContextHelp (IDC_BPS, LS (L_MINBPSHERE)),
		fsCtrlContextHelp (IDC_TRYAGAIN, LS (L_TRYAGAINHERE)),
		fsCtrlContextHelp (IDC_NOMORETHAN, LS (L_NOMORETHANHERE)),
		fsCtrlContextHelp (IDC_SELDLDS, LS (L_SELDLDSHERE)),
		fsCtrlContextHelp (IDC_UNSELDLDS, LS (L_ALLDLDSHERE)),
		fsCtrlContextHelp (IDC_TOSEL, LS (L_TOSELHERE)),
		fsCtrlContextHelp (IDC_TOUNSEL, LS (L_TOUNSELHERE)),
		fsCtrlContextHelp (IDC__PROGNAME, LS (L_PROGNAMEHERE)),
		fsCtrlContextHelp (IDC_PROGNAME, LS (L_PROGNAMEHERE)),
		fsCtrlContextHelp (IDC_CHOOSENAME, LS (L_CHOOSEPROGHERE)),
		fsCtrlContextHelp (IDC__ARGUMENTS, LS (L_ARGSHERE)),
		fsCtrlContextHelp (IDC_ARGUMENTS, LS (L_ARGSHERE)),
		fsCtrlContextHelp (IDC__TYPE, LS (L_TYPEHERE)),
		fsCtrlContextHelp (IDC_SHUTDOWNTYPE, LS (L_TYPEHERE)),
		fsCtrlContextHelp (IDC_FORCEEXIT, LS (L_FORCEEXITHERE)),
		fsCtrlContextHelp (IDC_WTS, LS (L_WTSHERE)),
		fsCtrlContextHelp (IDC_HANGUPALL, LS (L_HANGALLHERE)),
		fsCtrlContextHelp (IDC__HANGUP, LS (L_CONNTOHANGHERE)),
		fsCtrlContextHelp (IDC_CONNECTION, LS (L_CONNTOHANGHERE)),
		fsCtrlContextHelp (IDC_RAD_INVERT, LS (L_RAD_INVERT_HERE)),
	};

    static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));	
}

BOOL CSchedule_WTSPage::OnHelpInfo(HELPINFO* pHelpInfo) 
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
