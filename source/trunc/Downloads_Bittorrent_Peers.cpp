/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Downloads_Bittorrent_Peers.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDownloads_Bittorrent_Peers::CDownloads_Bittorrent_Peers()
{
	m_bDldChanged = false;
}

CDownloads_Bittorrent_Peers::~CDownloads_Bittorrent_Peers()
{
}

BEGIN_MESSAGE_MAP(CDownloads_Bittorrent_Peers, CListCtrl)
	//{{AFX_MSG_MAP(CDownloads_Bittorrent_Peers)
	ON_WM_SHOWWINDOW()
	ON_COMMAND(ID_UPDATE, OnCmdUpdate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDownloads_Bittorrent_Peers::Create(CWnd *pwndParent)
{
	CRect rc (0, 0, 50, 50);

	if (FALSE == CListCtrl::Create (WS_CHILD | LVS_REPORT | LVS_SINGLESEL | LVS_NOSORTHEADER,
			rc, pwndParent, 0x1fa1))
		return FALSE;

	SetExtendedStyle (LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	InsertColumn (0, "", LVCFMT_LEFT, 50);
	InsertColumn (1, "", LVCFMT_LEFT, 50);
	InsertColumn (2, "", LVCFMT_LEFT, 150);
	InsertColumn (3, "", LVCFMT_LEFT, 150);

	return TRUE;
}

void CDownloads_Bittorrent_Peers::set_ActiveDownload(vmsDownloadSmartPtr dld)
{
	m_dld = dld;
	if (dld == NULL)
		return;
	m_bDldChanged = true;
	UpdateStat ();
}

void CDownloads_Bittorrent_Peers::UpdateStat()
{
	if (IsWindowVisible () == FALSE)
		return;

	vmsBtDownloadPeerInfoList *p;
	p = m_dld ? m_dld->pMgr->GetBtDownloadMgr ()->get_PeerInfoList () : NULL;
	if (p == NULL)
	{
		DeleteAllItems ();
		m_vPeers.clear ();
		return;
	}

	if (p->UpdateList () || m_bDldChanged || m_vPeers.size () != (size_t)p->get_PeerCount ())
	{
		m_bDldChanged = false;
		
		

		m_vPeers.clear ();

		size_t i = 0;
		for (i = 0; i < (size_t)p->get_PeerCount (); i++)
		{
			vmsBtDownloadPeerInfo *peer = p->get_Peer (i);
			_inc_peer peer1;

			peer1.uBytesDownloaded = peer->get_BytesDownloaded ();
			peer1.uBytesUploaded = peer->get_BytesUploaded ();

			if (peer1.uBytesDownloaded == 0 && peer1.uBytesUploaded == 0)
				continue;

			peer1.uDownloadSpeed = peer->get_DownloadSpeed ();
			peer1.uUploadSpeed = peer->get_UploadSpeed ();

			char sz [1000];
			peer->get_Ip (sz);
			peer1.strIp = sz;
			
			peer->get_Client (sz);
			wchar_t wsz [1000];
			MultiByteToWideChar (CP_UTF8, 0, sz, -1, wsz, 1000);
			WideCharToMultiByte (CP_ACP, 0, wsz, -1, sz, 1000, NULL, NULL);
			peer1.strClient = sz;

			m_vPeers.push_back (peer1);
		}

		size_t cItems = GetItemCount ();
		for (i = 0; i < m_vPeers.size (); i++)
		{
			if (i < cItems)
				SetItemText (i, 0, m_vPeers [i].strIp);
			else
				InsertItem (i, m_vPeers [i].strIp);
			SetItemText (i, 1, m_vPeers [i].strClient);
		}

		while ((size_t)GetItemCount () > m_vPeers.size ())
			DeleteItem (GetItemCount () - 1);

		if (m_vPeers.size ())
		{
			SetColumnWidth (0, LVSCW_AUTOSIZE);
			SetColumnWidth (1, LVSCW_AUTOSIZE);
			for (int i = 0; i < 2; i++)
			{
				if (GetColumnWidth (i) < 50)
					SetColumnWidth (i, 50);
			}
		}
	}
	else
	{
		for (size_t i = 0; i < (size_t)p->get_PeerCount (); i++)
		{
			vmsBtDownloadPeerInfo *peer = p->get_Peer (i);
			_inc_peer &peer1 = m_vPeers [i];
			peer1.uBytesDownloaded = peer->get_BytesDownloaded ();
			peer1.uBytesUploaded = peer->get_BytesUploaded ();
			peer1.uDownloadSpeed = peer->get_DownloadSpeed ();
			peer1.uUploadSpeed = peer->get_UploadSpeed ();
		}
	}

	UpdatePeersDetails ();
}

void CDownloads_Bittorrent_Peers::UpdatePeersDetails()
{
	if (m_vPeers.size () == 0)
		return;

	if ((size_t)GetItemCount () != m_vPeers.size ())
		return;

	for (size_t i = 0; i < m_vPeers.size (); i++)
	{
		_inc_peer &peer = m_vPeers [i];

		CString str;

		str.Format ("%s, %s/%s", BytesToString (peer.uBytesDownloaded),
			BytesToString (peer.uDownloadSpeed), LS (L_S));
		SetItemText (i, 2, str);

		str.Format ("%s, %s/%s", BytesToString (peer.uBytesUploaded),
			BytesToString (peer.uUploadSpeed), LS (L_S));
		SetItemText (i, 3, str);

		
	}	
}

void CDownloads_Bittorrent_Peers::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CListCtrl::OnShowWindow(bShow, nStatus);
	PostMessage (WM_COMMAND, ID_UPDATE);
}

void CDownloads_Bittorrent_Peers::OnCmdUpdate() 
{
	UpdateStat ();
}

void CDownloads_Bittorrent_Peers::ApplyLanguage()
{
	HDITEM item;
	item.mask = HDI_TEXT;

	item.pszText = (LPSTR) "IP";
	GetHeaderCtrl ()->SetItem (0, &item);

	item.pszText = (LPSTR) LS (L_CLIENT);
	GetHeaderCtrl ()->SetItem (1, &item);

	item.pszText = (LPSTR) LS (L_DOWNLOADED);
	GetHeaderCtrl ()->SetItem (2, &item);

	item.pszText = (LPSTR) LS (L_UPLOADED);
	GetHeaderCtrl ()->SetItem (3, &item);
}
