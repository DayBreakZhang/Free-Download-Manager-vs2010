/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Downloads_Bittorrent.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDownloads_Bittorrent::CDownloads_Bittorrent()
{
	m_vTabs.push_back (&m_general);
	m_vTabs.push_back (&m_peers);
	m_vTabs.push_back (&m_files);
}

CDownloads_Bittorrent::~CDownloads_Bittorrent()
{
}

BEGIN_MESSAGE_MAP(CDownloads_Bittorrent, CTabCtrl)
	//{{AFX_MSG_MAP(CDownloads_Bittorrent)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_NOTIFY_REFLECT(TCN_SELCHANGE, OnSelchange)
	ON_WM_SHOWWINDOW()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDownloads_Bittorrent::Create(CWnd *pParent)
{
	CRect rc (50, 50, 275, 70);

	if (FALSE == CTabCtrl::Create (TCS_SINGLELINE|TCS_RIGHTJUSTIFY|TCS_FOCUSNEVER,
			rc, pParent, 0))
		return FALSE;

	LOGFONT lf;
	NONCLIENTMETRICS nm;

	ZeroMemory (&nm, sizeof (nm));
	nm.cbSize = sizeof (nm);
	SystemParametersInfo (SPI_GETNONCLIENTMETRICS, nm.cbSize, &nm, 0);
	lf = nm.lfMenuFont;
	lf.lfCharSet = DEFAULT_CHARSET;

	m_fontItems.CreateFontIndirect (&lf);

	SetFont (&m_fontItems, FALSE);

	return TRUE;
}

void CDownloads_Bittorrent::Set_ActiveDownload(vmsDownloadSmartPtr dld)
{
	if (dld != NULL && dld->pMgr->IsBittorrent () == FALSE)
		dld = NULL;
	m_general.set_ActiveDownload (dld);
	m_peers.set_ActiveDownload (dld);
	m_files.set_ActiveDownload (dld);
	m_dldActive = dld;
}

void CDownloads_Bittorrent::ApplyLanguage()
{
	TCITEM item;
	ZeroMemory (&item, sizeof (item));

	item.mask = TCIF_TEXT;
	item.pszText = (LPSTR) LS (L_GENERAL);
	SetItem (0, &item);

	item.pszText = (LPSTR) LS (L_PEERS);
	SetItem (1, &item);

	item.pszText = (LPSTR) LS (L_FILES);
	SetItem (2, &item);

	m_general.ApplyLanguage ();
	m_peers.ApplyLanguage ();
	m_files.ApplyLanguage ();	
}

int CDownloads_Bittorrent::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CTabCtrl::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	m_general.Create (this);
	m_peers.Create (this);
	m_files.Create (this);

	InsertItem (0, ""); 
	InsertItem (1, ""); 
	InsertItem (2, ""); 

	set_ActiveTab (0);
	
	return 0;
}

void CDownloads_Bittorrent::OnSize(UINT nType, int cx, int cy) 
{
	CTabCtrl::OnSize(nType, cx, cy);
	ApplySize ();
}

void CDownloads_Bittorrent::UpdateStat()
{
	m_general.UpdateStat ();
}

void CDownloads_Bittorrent::set_ActiveTab(int nTab)
{
	SetCurSel (nTab);
	nTab = GetCurSel ();
	ApplyCurTab ();
}

void CDownloads_Bittorrent::ApplySize()
{
	int nTab = GetCurSel ();
	if (nTab == -1)
		return;

	CRect rc;
	GetItemRect (0, &rc);

	int x = 2, y = rc.bottom + 3;

	GetClientRect (&rc);
	
	m_vTabs [nTab]->MoveWindow (x, y, rc.Width () - x - 3, rc.Height () - y - 3);
}

void CDownloads_Bittorrent::ApplyCurTab()
{
	size_t nCur = GetCurSel ();

	ApplySize ();

	for (size_t i = 0; i < m_vTabs.size (); i++)
		m_vTabs [i]->ShowWindow (nCur == i ? SW_SHOW : SW_HIDE);
}

void CDownloads_Bittorrent::OnSelchange(NMHDR* pNMHDR, LRESULT* pResult) 
{
	ApplyCurTab ();	
	*pResult = 0;
}

void CDownloads_Bittorrent::UpdatePeersStat()
{
	m_general.UpdatePeersStat ();
	m_peers.UpdateStat ();
}

void CDownloads_Bittorrent::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CTabCtrl::OnShowWindow(bShow, nStatus);
	size_t nCur = GetCurSel ();
	if (nCur != -1)
		m_vTabs [nCur]->PostMessage (WM_COMMAND, ID_UPDATE);
}

vmsDownloadSmartPtr CDownloads_Bittorrent::getActiveDownload()
{
	return m_dldActive;
}	

void CDownloads_Bittorrent::UpdateActiveDownload()
{
	Set_ActiveDownload (m_dldActive);
}
