/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "DialDlg.h"
#include "fsScheduleMgr.h"
#include "fsRASMgr.h"
#include "system.h"
#include "ShedulerWnd.h"

extern CShedulerWnd* _pwndScheduler;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define WM_DIALDLG_ENDDIALOG	(WM_APP + 500)

CDialDlg::CDialDlg(CWnd* pParent )
	: CDialog(CDialDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialDlg)
		
	//}}AFX_DATA_INIT
}

void CDialDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialDlg)
	DDX_Control(pDX, IDC_ENTRY, m_wndEntries);
	DDX_Control(pDX, IDC_LOG, m_wndLog);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDialDlg, CDialog)
	//{{AFX_MSG_MAP(CDialDlg)
	ON_BN_CLICKED(IDC_CONNECT, OnConnect)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	ON_BN_CLICKED(IDC_AUTO, OnAuto)
	ON_WM_HELPINFO()
	//}}AFX_MSG_MAP
	ON_MESSAGE (WM_DIALDLG_ENDDIALOG, OnNeedEndDialog)
END_MESSAGE_MAP()

void CDialDlg::Init(fsDialInfo *dial)
{
	m_dial = dial;
}

BOOL CDialDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	
	if (m_pThis)
	{
		EndDialog (IDCANCEL);
		return FALSE;
	}

	if (m_hConn)
	{
		fsRasHangUp (m_hConn);
		m_hConn = NULL;
	}

	
	m_pThis = this;
	m_pThisRefs = 1;
	m_bNeedStop = FALSE;

	CRect rc;
	m_wndLog.GetClientRect (&rc);
	m_wndLog.InsertColumn (0, "", LVCFMT_LEFT, rc.right);
	
	if (m_dial)	
	{
		
		m_wndEntries.AddString (m_dial->pszConnection);
		m_wndEntries.SetCurSel (0);

		
		GetDlgItem (IDC_AUTO)->EnableWindow (FALSE);

		
		StartConnect ();
	}
	else
	{
		fsRASMgr mgr;
		if (FALSE == mgr.EnumEntries () || mgr.GetEntriesCount () == 0)
		{
			
			MessageBox (LS (L_NODIALENTRIES), LS (L_ERR), MB_ICONERROR);
			Release_pThis ();
			EndDialog (IDCANCEL);
			return FALSE;
		}

		
		UINT i = 0;
		for (i = 0; i < mgr.GetEntriesCount (); i++)
			m_wndEntries.AddString (mgr.GetEntry (i));
		
		for (i = 0; i < (UINT)m_wndEntries.GetCount (); i++)
		{
			CString strEntry;
			m_wndEntries.GetLBText (i, strEntry);
			if (lstrcmpi (strEntry, _App.Dial_LastEntry ()) == 0)
			{
				m_wndEntries.SetCurSel (i);
				break;
			}
		}

		if (CB_ERR == m_wndEntries.GetCurSel ())
			m_wndEntries.SetCurSel (0);

		if (_App.Dial_Auto ())	
		{
			CheckDlgButton (IDC_AUTO, BST_CHECKED);
			PostMessage (WM_COMMAND, IDC_CONNECT);
		}
	}

	ApplyLanguage ();
	
	return TRUE;  
	              
}

CDialDlg* CDialDlg::m_pThis = NULL;
int CDialDlg::m_pThisRefs = 0;
HRASCONN CDialDlg::m_hConn = NULL;
BOOL CDialDlg::m_bNeedStop = FALSE;
BOOL CDialDlg::m_bInRasFunc = FALSE;

VOID WINAPI CDialDlg::_RasDialFunc(UINT, RASCONNSTATE state, DWORD dwError)
{
	if (m_bNeedStop)
		return;

	if (m_pThis == NULL)
		return;

	m_bInRasFunc = TRUE;

	
	m_pThisRefs++;

	if (dwError && m_bNeedStop == FALSE)	
	{
		switch (dwError)
		{
			case ERROR_LINE_BUSY:	
				
				m_pThis->Log (LS (L_LINEBUSY));
			break;

			case ERROR_PORT_OR_DEVICE:	
				m_pThis->Log (LS (L_HARDWAREFAILURE));
			break;

			case ERROR_NO_DIALTONE:	
				m_pThis->Log (LS (L_NODIALTONE));
			break;

			case ERROR_AUTHENTICATION_FAILURE:	
				m_pThis->Log (LS (L_INVLOGIN2));
			break;

			default:	
				

				char szErr [256];	
				fsRasGetErrorString (dwError, szErr, sizeof (szErr));
				m_pThis->Log (szErr);
				
				if (m_pThis->m_dial == NULL)
					m_pThis->Cancel ();	
				else
				{
					
					m_pThis->PostMessage (WM_DIALDLG_ENDDIALOG, IDCANCEL);
					Release_pThis ();
				}
				Release_pThis ();
				m_bInRasFunc = FALSE;
				return;
		}
		
		
		fsRasHangUp (m_hConn);
		m_hConn = NULL;

		m_pThis->m_cAttempts++;	

		if (m_pThis->m_dial)
		{
			
			if (m_pThis->m_dial->cAttempts > m_pThis->m_cAttempts)
			{
				
				m_pThis->SleepInterval ();
			}
			else
			{
				

				if (m_hConn)
				{
					fsRasHangUp (m_hConn);
					m_hConn = NULL;
				}
				m_pThis->PostMessage (WM_DIALDLG_ENDDIALOG, IDCANCEL);
				Release_pThis ();
				Release_pThis ();
				m_bInRasFunc = FALSE;
				return;
			}
		}
		
		if (m_bNeedStop == FALSE)
		{
			

			m_pThis->Log ("");
			CString str;
			str.Format ("%s... %s %d", LS (L_DIALING), LS (L_ATTEMPT), m_pThis->m_cAttempts+1);
			m_pThis->Log (str);

			
			fsRasDial (NULL, NULL, &m_pThis->m_rp, 0, _RasDialFunc, &m_hConn);
		}

		Release_pThis ();
		m_bInRasFunc = FALSE;
		return;
	}

	
	switch (state)
	{
		case RASCS_OpenPort:	
			m_pThis->Log (LS (L_OPENPORT));
		break;

		case RASCS_ConnectDevice:	
			m_pThis->Log (LS (L_DIALTOPROVIDER));
		break;

		case RASCS_DeviceConnected:	
			m_pThis->Log (LS (L_CONNECTEDTOREMOTE));
		break;

		case RASCS_Authenticate:	
			m_pThis->Log (LS (L_VERUSERANDPASS));
		break;

		case RASCS_Connected:	
			RAS_STATS stat;
			stat.dwSize = sizeof (stat);

			
			if (fsSysGetOsMajorVersion () >= 5)
				
				fsSysGetConnectionStatistics (m_hConn, &stat);
			else
				stat.dwBps = UINT_MAX;	

			
			if (m_pThis->m_dial && stat.dwBps < m_pThis->m_dial->dwHangupLess)
			{
				CString str;
				str.Format (LS (L_CONNSPEEDNOW), stat.dwBps);
				m_pThis->Log (str);
				m_pThis->Log (LS (L_HANGUPIT));
				fsRasHangUp (m_hConn);	
				m_hConn = NULL;

				
				if (m_pThis->m_cAgains < m_pThis->m_dial->cAgains)
				{
					

					m_pThis->m_cAttempts = 0;
					m_pThis->Log ("");
					CString str;
					str.Format ("%s %d", LS (L_REPETITION), m_pThis->m_cAgains+1);
					m_pThis->Log (str);
					m_pThis->Log ("");
					str.Format ("%s... %s %d", LS (L_DIALING), LS (L_ATTEMPT), m_pThis->m_cAttempts+1);
					m_pThis->Log (str);
					fsRasDial (NULL, NULL, &m_pThis->m_rp, 0, _RasDialFunc, &m_hConn);
					m_pThis->m_cAgains++;
				}
				else
				{
					
					m_pThis->PostMessage (WM_DIALDLG_ENDDIALOG, IDCANCEL);
					if (m_hConn)
					{
						fsRasHangUp (m_hConn);
						m_hConn = NULL;
					}
					Release_pThis ();
				}
			}
			else
			{
				
				m_hConn = NULL;
				InternetAutodial (INTERNET_AUTODIAL_FORCE_ONLINE, NULL); 
				m_pThis->PostMessage (WM_DIALDLG_ENDDIALOG, IDOK);
				Release_pThis ();
			}
		break;
	}

	Release_pThis ();
	m_bInRasFunc = FALSE;
}

void CDialDlg::Log(LPCSTR pszRecord)
{
	if (IsWindow (m_hWnd) == FALSE)
		return;

	int iItem = m_wndLog.GetItemCount ();
	m_wndLog.InsertItem (iItem, pszRecord, 0);
	m_wndLog.EnsureVisible (iItem, FALSE);
}

void CDialDlg::OnCancel() 
{
	m_bNeedStop = TRUE;

	
	while (m_bInRasFunc)
		Sleep (50);

	Log (LS (L_CANCELED));
	Cancel ();
}

void CDialDlg::SleepInterval()
{
	if (m_dial->cPauseBetween == 0)
		return;

	CString str;

	str.Format (LS (L_PAUSESECS), m_dial->cPauseBetween);
	Log (str);
	
	int u = m_dial->cPauseBetween * 1000;	

	while (u > 0)
	{
		Sleep (500);
		u -= 500;
		if (m_bNeedStop)
			break;
	}
}

void CDialDlg::StartConnect()
{
	m_bNeedStop = FALSE;

	ZeroMemory (&m_rp, sizeof (m_rp));
	m_rp.dwSize = sizeof (m_rp);
	m_wndEntries.GetLBText (m_wndEntries.GetCurSel (), m_rp.szEntryName);

	BOOL bPassword;
	fsRasGetEntryDialParams (NULL, &m_rp, &bPassword);

	m_cAttempts = 0;
	m_cAgains = 0;

	CString str;
	str.Format ("%s... %s 1", LS (L_DIALING), LS (L_ATTEMPT));
	Log (str);
	fsRasDial (NULL, NULL, &m_rp, 0, _RasDialFunc, &m_hConn);

	GetDlgItem (IDC_CONNECT)->EnableWindow (FALSE);
	m_wndEntries.EnableWindow (FALSE);
}

void CDialDlg::OnConnect() 
{
	CString str;
	m_wndEntries.GetLBText (m_wndEntries.GetCurSel (), str);
	_App.Dial_LastEntry (str);
	StartConnect ();
}

LRESULT CDialDlg::OnNeedEndDialog(WPARAM wp, LPARAM)
{
	Release_pThis ();
	EndDialog (wp);

	
	if (wp == IDOK)
	{
		
		_pwndScheduler->GetMgr ()->ExciteEvent (EV_DIALINGSUCCESS);
		_Snds.Event (SME_DIALINGOK);
	}
	else
	{
		
		_pwndScheduler->GetMgr ()->ExciteEvent (EV_DIALINGFAILED);
                _Snds.Event (SME_DIALINGFAILED);
	}

	return 0;
}

void CDialDlg::OnContextMenu(CWnd* , CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();
}

void CDialDlg::OnWhatisthis() 
{
	_CHMgr.OnWT ();	
}

void CDialDlg::OnAuto() 
{
	_App.Dial_Auto (IsDlgButtonChecked (IDC_AUTO) == BST_CHECKED);	
}

void CDialDlg::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__DIALINGTO, L_CONNECTTO),
		fsDlgLngInfo (IDC_AUTO, L_AUTODIAL),
		fsDlgLngInfo (IDC_CONNECT, L_CONNECT),
		fsDlgLngInfo (IDCANCEL, L_CANCEL),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_DIALCONNECTION);
}

void CDialDlg::Release_pThis()
{
	if (m_pThisRefs)
	{
		if (--m_pThisRefs == 0)
			m_pThis = NULL;
	}
}

void CDialDlg::Cancel()
{
	BOOL bExit = FALSE;	

	m_bNeedStop = TRUE;

	
	
	if (m_hConn)
	{
		
		fsRasHangUp (m_hConn);
		m_hConn = NULL;
	}
	else
		bExit = TRUE;	
	
	
	
	if (m_dial)
		bExit = TRUE;

	if (bExit) 
	{
		if (m_hConn)
		{
			fsRasHangUp (m_hConn);
			m_hConn = NULL;
		}
		CDialog::OnCancel();
		Release_pThis ();
	}
	else
	{
		GetDlgItem (IDC_CONNECT)->EnableWindow (TRUE);
		m_wndEntries.EnableWindow (TRUE);
	}
}

BOOL CDialDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
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

void CDialDlg::PrepareCHMgr(CPoint point)
{
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC__DIALINGTO, LS (L_CHOOSEENTRY)),
		fsCtrlContextHelp (IDC_ENTRY, LS (L_CHOOSEENTRY)),
		fsCtrlContextHelp (IDC_AUTO, LS (L_AUTODIALHERE)),
		fsCtrlContextHelp (IDC_CONNECT, LS (L_DIALNOW)),
		fsCtrlContextHelp (IDCANCEL, LS (L_DONTDIAL)),
	};

     static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));
}
