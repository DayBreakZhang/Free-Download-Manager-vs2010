/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fdm.h"
#include "Dlg_CreateNewTorrent.h"
#include "FolderBrowser.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlg_CreateNewTorrent::CDlg_CreateNewTorrent(CWnd* pParent )
	: CDialog(CDlg_CreateNewTorrent::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_CreateNewTorrent)
		
	//}}AFX_DATA_INIT
	m_bCreatingTorrent = FALSE;
}

void CDlg_CreateNewTorrent::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_CreateNewTorrent)
	DDX_Control(pDX, IDC_PROGRESS, m_wndProgress);
	DDX_Control(pDX, IDC_TRACKERS, m_wndTracker);
	DDX_Control(pDX, IDC_TRACKER_LIST, m_wndTrackerList);
	DDX_Control(pDX, IDC_SOURCE, m_wndSource);
	DDX_Control(pDX, IDC_PIECE_SIZE, m_wndPS);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlg_CreateNewTorrent, CDialog)
	//{{AFX_MSG_MAP(CDlg_CreateNewTorrent)
	ON_BN_CLICKED(IDC_FILE, OnFile)
	ON_BN_CLICKED(IDC_FOLDER, OnFolder)
	ON_BN_CLICKED(IDC_ADD_TRACKER, OnAddTracker)
	ON_LBN_SELCHANGE(IDC_TRACKER_LIST, OnSelchangeTrackerList)
	ON_BN_CLICKED(IDC_REMOVE_TRACKER, OnRemoveTracker)
	ON_BN_CLICKED(IDC_SAVE_TRACKERS, OnSaveTrackers)
	ON_BN_CLICKED(IDC_RESTORE_TRACKERS, OnRestoreTrackers)
	ON_BN_CLICKED(IDC_CLEAR_TRACKERS, OnClearTrackers)
	ON_WM_TIMER()
	ON_MESSAGE(WM_CLOSE_CREATE_TORRENT, OnCloseCreateTorrent)

	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlg_CreateNewTorrent::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	int ai_bt_PS [] = {0, 16*1024, 32*1024, 64*1024, 128*1024, 256*1024,
		512*1024, 1024*1024, 2*1024*1024, 4*1024*1024, 8*1024*1024};
	LPCSTR apsz_bt_PS [] = {LS (L_AUTO_WQ), "16 KB", "32 KB", "64 KB", "128 KB", "256 KB", 
		"512 KB", "1024 KB", "2048 KB", "4096 KB", "8192 KB"};
	for (int i = 0; i < sizeof (ai_bt_PS)/sizeof (int); i++)
	{
		m_wndPS.AddString (apsz_bt_PS [i]);
		m_wndPS.SetItemData (i, ai_bt_PS [i]);
	}
	m_wndPS.SetCurSel (0);

	OnRestoreTrackers ();

	GetDlgItem (IDC_REMOVE_TRACKER)->EnableWindow (m_wndTrackerList.GetSelCount () != 0);

	ApplyLanguage ();
	
	return TRUE;  
	              
}

void CDlg_CreateNewTorrent::OnFile() 
{
	CString strFilter;
	strFilter.Format ("%s (*.*)|*.*||", LS (L_ALLFILES));
	
	CFileDialog dlg (TRUE, "", NULL, OFN_HIDEREADONLY|OFN_NOCHANGEDIR, strFilter, this);
	if (_DlgMgr.DoModal (&dlg) != IDOK)
		return;
	m_wndSource.SetWindowText (dlg.GetPathName ());
}

void CDlg_CreateNewTorrent::OnFolder() 
{
	CString str;
	m_wndSource.GetWindowText (str);
	
	if (str.GetLength () > 3 && (str [str.GetLength () - 1] == '\\' || str [str.GetLength () - 1] == '/'))
		str.Delete (str.GetLength () - 1);
	
	CFolderBrowser *fb = CFolderBrowser::Create (NULL, str, NULL, this);
	if (fb == NULL)
		return;
	
	m_wndSource.SetWindowText (fb->GetPath ());
	m_wndSource.SetFocus ();
}

void CDlg_CreateNewTorrent::OnAddTracker() 
{
	CString str;
	m_wndTracker.GetWindowText (str);	
	if (str.IsEmpty ())
		return;
	if (m_wndTrackerList.FindString (0, str) == -1)
		m_wndTrackerList.AddString (str);
}

void CDlg_CreateNewTorrent::OnSelchangeTrackerList() 
{
	GetDlgItem (IDC_REMOVE_TRACKER)->EnableWindow (m_wndTrackerList.GetSelCount () != 0);
}

void CDlg_CreateNewTorrent::OnRemoveTracker() 
{
	int n = m_wndTrackerList.GetSelCount ();
	int *paiInd = (int*) _alloca (n * sizeof (int));
	m_wndTrackerList.GetSelItems (n, paiInd);
	while (n--)
		m_wndTrackerList.DeleteString (paiInd [n]);
	GetDlgItem (IDC_REMOVE_TRACKER)->EnableWindow (FALSE);
}

void CDlg_CreateNewTorrent::OnSaveTrackers() 
{
	CStringList sl;
	getTrackerList (sl);
	int len = 1;
	POSITION pos = sl.GetHeadPosition ();
	while (pos)
		len += sl.GetNext (pos).GetLength () + 1;
	LPSTR psz = (LPSTR)_alloca (len);
	LPSTR psz2 = psz;
	pos = sl.GetHeadPosition ();
	while (pos)
	{
		CString str = sl.GetNext (pos);
		lstrcpy (psz, str);
		psz += str.GetLength () + 1;
	}
	*psz = 0;
	AfxGetApp ()->WriteProfileBinary ("Settings\\Torrents", "DefaultTrackerListForNewTorrent", (LPBYTE)psz2, len);
}

void CDlg_CreateNewTorrent::OnRestoreTrackers() 
{
	LPSTR psz = NULL;
	UINT len = 0;
	AfxGetApp ()->GetProfileBinary ("Settings\\Torrents", "DefaultTrackerListForNewTorrent", (LPBYTE*)&psz, &len); 
	if (psz == NULL || len == 0)
		return;
	LPCSTR psz2 = psz;
	m_wndTrackerList.ResetContent ();
	while (*psz2)
	{
		m_wndTrackerList.AddString (psz2);
		psz2 += lstrlen (psz2) + 1;
	}
	delete [] psz;
}

void CDlg_CreateNewTorrent::OnClearTrackers() 
{
	if (MessageBox (LS (L_AREYOUSURE), LS (L_CONFIRMATION), MB_ICONQUESTION | MB_YESNO) == IDNO)
		return;
	m_wndTrackerList.ResetContent ();
}

void CDlg_CreateNewTorrent::getTrackerList(CStringList &sl)
{
	for (int i = 0; i < m_wndTrackerList.GetCount (); i++)
	{
		CString str;
		m_wndTrackerList.GetText (i, str);
		sl.AddTail (str);
	}
}

void CDlg_CreateNewTorrent::OnOK() 
{
	CString strSrcFile; m_wndSource.GetWindowText (strSrcFile);
	if (strSrcFile.IsEmpty ())
	{
		MessageBox (LS (L_INPERR), LS (L_ERR), MB_ICONERROR);
		m_wndSource.SetFocus ();
		return;
	}
	
	CStringList sl;
	getTrackerList (sl);
	if (sl.IsEmpty ())
	{
		MessageBox (LS (L_INPERR), LS (L_ERR), MB_ICONERROR);
		m_wndTrackerList.SetFocus ();
		return;
	}

	UINT aids [] = {IDC__SOURCE, IDC_SOURCE, IDC_FILE, IDC_FOLDER, IDC__PIECE_SIZE,
		IDC_PIECE_SIZE, IDC__TRACKERS, IDC_TRACKERS, IDC_ADD_TRACKER, IDC_REMOVE_TRACKER,
		IDC_SAVE_TRACKERS, IDC_RESTORE_TRACKERS, IDC_CLEAR_TRACKERS, IDC_TRACKER_LIST,
		IDC__COMMENT, IDC_COMMENT, IDOK,
	};
	for (int i = 0; i < sizeof (aids)/sizeof (UINT); i++)
		GetDlgItem (aids [i])->EnableWindow (FALSE);
	GetDlgItem (IDC__COMMENT)->ShowWindow (SW_HIDE);
	GetDlgItem (IDC_COMMENT)->ShowWindow (SW_HIDE);
	m_wndProgress.ShowWindow (SW_SHOW);

	m_nProgress = 0;
	m_bNeedCancel = FALSE;
	m_bCreatingTorrent = TRUE;

	DWORD dw;
	CloseHandle (
		CreateThread (NULL, 0, _threadCreateNewTorrent, this, 0, &dw));

	SetTimer (1, 1000, NULL);
}

DWORD WINAPI CDlg_CreateNewTorrent::_threadCreateNewTorrent(LPVOID lp)
{
	CDlg_CreateNewTorrent *pthis = (CDlg_CreateNewTorrent*)lp;

	CString strSrcFile; pthis->m_wndSource.GetWindowText (strSrcFile);
	USES_CONVERSION;
	LPCWSTR lpcwstrSrcFile = A2CW (strSrcFile);
	CString strComment; pthis->GetDlgItemText (IDC_COMMENT, strComment);
		
	CStringList sl;
	pthis->getTrackerList (sl);
	
	int len = 1;
	POSITION pos = sl.GetHeadPosition ();
	while (pos)
		len += sl.GetNext (pos).GetLength () + 1;
	LPSTR psz = (LPSTR)_alloca (len);
	LPSTR pszTrackers = psz;
	pos = sl.GetHeadPosition ();
	while (pos)
	{
		CString str = sl.GetNext (pos);
		lstrcpy (psz, str);
		psz += str.GetLength () + 1;
	}
	*psz = 0;
	
	BOOL bRes = FALSE;

	vmsBtFile *pBtFile = _BT.CreateTorrentFileObject ();
	
	if (pBtFile)
	{
		bRes = pBtFile->CreateNewTorrent2 (lpcwstrSrcFile, pszTrackers, NULL, NULL, strComment, 
			pthis->m_wndPS.GetItemData (pthis->m_wndPS.GetCurSel ()), &pthis->m_nProgress,
			&pthis->m_bNeedCancel);
	}

	pthis->m_bCreatingTorrent = FALSE;

	int nButton;
	if (bRes)
	{
		pthis->m_nProgress = 100;

		if (pthis->m_bNeedCancel)
			nButton = IDCANCEL;
		else
		{
			BOOL bOk = FALSE;
			CString str; str.Format ("%s (*.torrent)|*.torrent||", LS (L_TORRENT_FILES));
			CFileDialog dlg (FALSE, "torrent", NULL, OFN_OVERWRITEPROMPT|OFN_NOCHANGEDIR, str, pthis);
			if (dlg.DoModal () == IDOK)
			{
				HANDLE hFile = CreateFile (dlg.GetPathName (), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS,
					FILE_ATTRIBUTE_NORMAL, NULL);
				DWORD dw; 
				if (hFile != INVALID_HANDLE_VALUE && pBtFile->get_TorrentBuffer (NULL, 0, &dw))
				{
					if (dw)
					{
						LPBYTE pb = new BYTE [dw];
						pBtFile->get_TorrentBuffer (pb, dw, &dw);
						WriteFile (hFile, pb, dw, &dw, NULL);
						delete [] pb;
						bOk = TRUE;
					}
					CloseHandle (hFile);					
				}
				if (bOk)
				{
					if (pthis->IsDlgButtonChecked (IDC_SEED) == BST_CHECKED)
					{
						CString strSavePath = strSrcFile;
						while (strSavePath.IsEmpty () == FALSE && strSavePath.Right (1) != '\\' &&
								strSavePath.Right (1) != '/')
							strSavePath.Delete (strSavePath.GetLength () - 1);
						CString strUrl = "file://"; strUrl += dlg.GetPathName ();
						_pwndDownloads->CreateBtDownload(dlg.GetPathName (), strUrl, TRUE, TRUE, strSavePath);
					}
				}
				else
				{
					pthis->MessageBox (LS (L_ERR), LS (L_ERR), MB_ICONERROR);
				}
			}
			nButton = bOk ? IDOK : IDCANCEL;
		}
	}
	else
	{
		nButton = IDCANCEL;
		pthis->MessageBox (LS (L_ERR), LS (L_ERR), MB_ICONERROR);
	}
	
	pBtFile->Release ();
	::PostMessage(pthis->m_hWnd, WM_CLOSE_CREATE_TORRENT, 0, nButton);
	return 0;
}

void CDlg_CreateNewTorrent::OnTimer(UINT nIDEvent) 
{
	if (nIDEvent == 1)
	{
		if (m_wndProgress.GetPos () != m_nProgress)
			m_wndProgress.SetPos (m_nProgress);

		if (m_nProgress == 100)
			KillTimer (1);
	}
	
	CDialog::OnTimer(nIDEvent);
}

void CDlg_CreateNewTorrent::OnCancel() 
{
	if (m_bCreatingTorrent)
	{
		m_bNeedCancel = TRUE;
		return;
	}
	
	CDialog::OnCancel();
}

void CDlg_CreateNewTorrent::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__SOURCE, L_SOURCE, TRUE),
		fsDlgLngInfo (IDC_FILE, L_FILE),
		fsDlgLngInfo (IDC_FOLDER, L_FOLDER),
		fsDlgLngInfo (IDC__PIECE_SIZE, L_PIECE_SIZE, TRUE),
		fsDlgLngInfo (IDC__TRACKERS, L_TRACKERS, TRUE),
		fsDlgLngInfo (IDC_ADD_TRACKER, L_ADD_TRACKER),
		fsDlgLngInfo (IDC_REMOVE_TRACKER, L_REMOVE_TRACKER),
		fsDlgLngInfo (IDC_SAVE_TRACKERS, L_SAVE),
		fsDlgLngInfo (IDC_RESTORE_TRACKERS, L_RESTORE),
		fsDlgLngInfo (IDC_CLEAR_TRACKERS, L_CLEAR),
		fsDlgLngInfo (IDC__COMMENT, L_COMMENT, TRUE),
		fsDlgLngInfo (IDC_SEED, L_START_SEEDING_TORRENT),
		fsDlgLngInfo (IDCANCEL, L_CANCEL),
	};
	
	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_CREATE_NEW_TORRENT);
}

LRESULT CDlg_CreateNewTorrent::OnCloseCreateTorrent(WPARAM wparam, LPARAM lparam)
{
	EndDialog (static_cast<int>(lparam));
	return 0;
}