/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Downloads_Bittorrent_General.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDownloads_Bittorrent_General::CDownloads_Bittorrent_General()
{
}

CDownloads_Bittorrent_General::~CDownloads_Bittorrent_General()
{
}

BEGIN_MESSAGE_MAP(CDownloads_Bittorrent_General, CListCtrl)
	//{{AFX_MSG_MAP(CDownloads_Bittorrent_General)
	ON_WM_SHOWWINDOW()
	ON_COMMAND(ID_UPDATE, OnCmdUpdate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDownloads_Bittorrent_General::Create(CWnd *pParent)
{
	CRect rc (0, 0, 50, 50);

	if (FALSE == CListCtrl::Create (WS_CHILD | LVS_NOCOLUMNHEADER | LVS_REPORT | LVS_SINGLESEL,
			rc, pParent, 0xaa1))
		return FALSE;

	SetExtendedStyle (LVS_EX_FULLROWSELECT);

	InsertColumn (0, "");
	InsertColumn (1, "");

	return TRUE;
}

void CDownloads_Bittorrent_General::set_ActiveDownload(vmsDownloadSmartPtr dld)
{
	m_dld = dld;
	if (dld == NULL)
	{
		DeleteAllItems ();
		return;
	}
	UpdateStat ();	
}

void CDownloads_Bittorrent_General::UpdateStat()
{
	if (m_dld == NULL)
		return;

	if (IsWindowVisible () == FALSE)
		return;

	DeleteAllItems ();

	vmsBtDownloadManager *mgr = m_dld->pMgr->GetBtDownloadMgr ();
	
	

	CString str = LS (L_INFO_HASH); str += ':';
	InsertItem (0, str);
	str = mgr->get_InfoHash ();
	str.MakeUpper ();
	str.Insert (8, ' ');
	str.Insert (8+8+1, ' ');
	str.Insert (8+8+8+2, ' ');
	str.Insert (8+8+8+8+3, ' ');
	SetItemText (0, 1, str);

	str = LS (L_PIECES); str += ':';
	InsertItem (1, str);
	str.Format ("%d x %s", mgr->get_PieceCount (),
		BytesToString (mgr->get_PieceSize ())); 
	SetItemText (1, 1, str);

	InsertItem (2, "");

	
	str = LS (L_TRACKER); str += ':';
	InsertItem (3, str);
	SetItemText (3, 1, mgr->get_LastTracker ());
	str = LS (L_TRACKER_STATUS); str += ':';
	InsertItem (4, str);
	SetItemText (4, 1, mgr->getLastTrackerStatus ().c_str ());

	InsertItem (5, "");

	str = LS (L_UPLOAD_SPEED); str += ':';
	InsertItem (6, str);
	str = LS (L_BYTES_UPLOADED); str += ':';
	InsertItem (7, str);
	str = LS (L_SHARE_RATING); str += ':';
	InsertItem (8, str);
	UpdateUploadStat ();

	InsertItem (9, "");

	str = LS (L_PEERS); str += ':';
	InsertItem (10, str);
	UpdatePeersStat ();

	InsertItem (11, "");

	str = LS (L_WASTED_BYTE_COUNT); str += ':';
	InsertItem (12, str);
	UpdateWastedStat ();

	SetColumnWidth (0, LVSCW_AUTOSIZE);
	SetColumnWidth (1, LVSCW_AUTOSIZE);

	int w = GetColumnWidth (0);
	SetColumnWidth (0, w + 33);
}

void CDownloads_Bittorrent_General::ApplyLanguage()
{
	if (m_dld != NULL)
		UpdateStat ();
}

void CDownloads_Bittorrent_General::UpdateUploadStat()
{
	if (m_dld == NULL || GetItemCount () < 9)
		return;

	if (IsWindowVisible () == FALSE)
		return;

	vmsBtDownloadManager *mgr = m_dld->pMgr->GetBtDownloadMgr ();

	CString str = BytesToString (mgr->GetUploadSpeed ());
	str += '/'; str += LS (L_S);
	SetItemText (6, 1, str);

	SetItemText (7, 1, BytesToString (mgr->get_TotalUploadedByteCount ()));

	str.Format ("%.*g", 4, (float)mgr->getRatio ());
	SetItemText (8, 1, str);
}

void CDownloads_Bittorrent_General::UpdatePeersStat()
{
	if (m_dld == NULL || GetItemCount () < 11)
		return;

	if (IsWindowVisible () == FALSE)
		return;

	CString str;
	int nPeersConnected, nSeedsTotal, nLeechersTotal, nSeedsConnected;
	m_dld->pMgr->GetBtDownloadMgr ()->get_PeersStat (
		&nPeersConnected, &nSeedsTotal,	&nLeechersTotal, &nSeedsConnected);
	if (nSeedsTotal != -1 && nLeechersTotal != -1)
		str.Format ("total: %d, seeds: %d, connected: %d (%d - seeds)",
			nSeedsTotal+nLeechersTotal, nSeedsTotal, nPeersConnected, nSeedsConnected);
	else
		str.Format ("connected: %d (%d - seeds)", nPeersConnected, nSeedsConnected);
	SetItemText (10, 1, str);
}

void CDownloads_Bittorrent_General::UpdateWastedStat()
{
	if (m_dld == NULL || GetItemCount () < 13)
		return;

	if (IsWindowVisible () == FALSE)
		return;

	SetItemText (12, 1, 
		BytesToString (m_dld->pMgr->GetBtDownloadMgr ()->get_WastedByteCount ()));
}

void CDownloads_Bittorrent_General::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CListCtrl::OnShowWindow(bShow, nStatus);

	PostMessage (WM_COMMAND, ID_UPDATE);
}

void CDownloads_Bittorrent_General::OnCmdUpdate() 
{
	UpdateStat ();	
	Invalidate ();
}
