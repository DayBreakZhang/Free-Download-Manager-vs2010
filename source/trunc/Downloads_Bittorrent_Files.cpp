/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Downloads_Bittorrent_Files.h"
#include "vmsTreeCtrlHelper.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDownloads_Bittorrent_Files::CDownloads_Bittorrent_Files()
{
}

CDownloads_Bittorrent_Files::~CDownloads_Bittorrent_Files()
{
}

BEGIN_MESSAGE_MAP(CDownloads_Bittorrent_Files, CColumnTreeCtrl)
	//{{AFX_MSG_MAP(CDownloads_Bittorrent_Files)
	ON_COMMAND(ID_BTFILES_DONTDOWNLOAD, OnBtfilesDontdownload)
	ON_COMMAND(ID_BTFILES_HIGHPIORITY, OnBtfilesHighpiority)
	ON_COMMAND(ID_BTFILES_NORMALPRIORITY, OnBtfilesNormalpriority)
	ON_WM_SHOWWINDOW()
	//}}AFX_MSG_MAP
	ON_NOTIFY_REFLECT(NM_RCLICK, OnRclick)
END_MESSAGE_MAP()

BOOL CDownloads_Bittorrent_Files::Create(CWnd *pwndParent)
{
	CRect rc (0, 0, 50, 50);

	CColumnTreeCtrl::Create (WS_CHILD, rc, pwndParent, 0);

	

	GetTreeCtrl().ModifyStyle (0, TVS_HASBUTTONS | TVS_HASLINES | 
		TVS_LINESATROOT | TVS_FULLROWSELECT);
	InsertColumn (0, LS (L_NAME), LVCFMT_LEFT, 250);
	InsertColumn (1, LS (L_SIZE), LVCFMT_LEFT, 130);
	InsertColumn (2, LS (L_PROGRESS), LVCFMT_LEFT, 70);
	InsertColumn (3, LS (L_PRIORITY), LVCFMT_LEFT, 100);
	
	return TRUE;
}

void CDownloads_Bittorrent_Files::ApplyLanguage()
{
	HDITEM item;
	item.mask = HDI_TEXT;

	item.pszText = (LPSTR) LS (L_NAME);
	GetHeaderCtrl ().SetItem (0, &item);

	item.pszText = (LPSTR) LS (L_SIZE);
	GetHeaderCtrl ().SetItem (1, &item);

	item.pszText = (LPSTR) LS (L_PROGRESS);
	GetHeaderCtrl ().SetItem (2, &item);

	item.pszText = (LPSTR) LS (L_PRIORITY);
	GetHeaderCtrl ().SetItem (3, &item);
}

void CDownloads_Bittorrent_Files::set_ActiveDownload(vmsDownloadSmartPtr dld)
{
	GetTreeCtrl ().DeleteAllItems ();

	m_dld = dld;
	if (dld == NULL)
		return;

	fs::ListTree <vmsBtDownloadManager::vmsFile>::ListTreePtr tFiles;
	tFiles.CreateInstance ();
	m_dld->pMgr->GetBtDownloadMgr ()->GetFilesTree (tFiles);

	AddFiles (tFiles, this, TVI_ROOT);
	
	
}

void CDownloads_Bittorrent_Files::UpdateProgress()
{
	if (IsWindowVisible () == FALSE || m_dld == NULL)
		return;

	int c = GetTreeCtrl ().GetVisibleCount ();
	HTREEITEM hItem = GetTreeCtrl ().GetFirstVisibleItem ();
	while (hItem && c--)
	{
		int nFile = GetTreeCtrl ().GetItemData (hItem);
		if (nFile != -1)
		{
			CString str; str.Format ("%d%%", m_dld->pMgr->GetBtDownloadMgr ()->get_FilePercentDone (nFile));
			SetItemText (hItem, 2, str);
		}
		hItem = GetTreeCtrl ().GetNextVisibleItem (hItem);
	}
}

void CDownloads_Bittorrent_Files::AddFiles(fs::ListTree <vmsBtDownloadManager::vmsFile>* pTree, CColumnTreeCtrl *pTreeCtrl, HTREEITEM hRoot)
{
	for (int i = 0; i < pTree->GetLeafCount (); i++)
	{
		vmsBtDownloadManager::vmsFile &file = pTree->GetLeaf (i)->GetData ();
		if (file.nIndex == -1)
		{
			HTREEITEM hItem = pTreeCtrl->GetTreeCtrl ().InsertItem (TVIF_TEXT | TVIF_PARAM | TVIF_STATE, 
				file.strName, 0, 0, TVIS_EXPANDED, TVIS_EXPANDED, -1, hRoot, TVI_LAST);
			pTreeCtrl->SetItemText (hItem, 1, BytesToString (file.nFileSize));
			AddFiles (pTree->GetLeaf (i), pTreeCtrl, hItem);
			
		}
		else
		{
			HTREEITEM hItem = pTreeCtrl->GetTreeCtrl ().InsertItem (TVIF_TEXT | TVIF_PARAM | TVIF_PARAM, 
				file.strName, 0, 0, 0, 0, file.nIndex, hRoot, TVI_LAST);
			pTreeCtrl->SetItemText (hItem, 1, BytesToString (file.nFileSize));
			CString str; str.Format ("%d%%", m_dld->pMgr->GetBtDownloadMgr ()->get_FilePercentDone (file.nIndex));
			pTreeCtrl->SetItemText (hItem, 2, str);
			if (file.iPriority == 0)
				pTreeCtrl->SetItemText (hItem, 3, LS (L_PRIORITY_SKIP));
			else if (file.iPriority == 1)
				pTreeCtrl->SetItemText (hItem, 3, LS (L_PRIORITY_NORMAL));
			else 
				pTreeCtrl->SetItemText (hItem, 3, LS (L_PRIORITY_HIGH));
			
		}
	}	
}

void CDownloads_Bittorrent_Files::OnRclick(NMHDR *, LRESULT *pResult)
{
	HTREEITEM hItem;

	CPoint pt; GetCursorPos (&pt);
	ScreenToClient (&pt);
	
	hItem = HitTest (pt);
	
	if (hItem)
	{
		GetTreeCtrl ().SelectItem (hItem);	
		ShowContextMenu (hItem);
	}
	
	*pResult = 0;
}

void CDownloads_Bittorrent_Files::ShowContextMenu(HTREEITEM hItem)
{
	CMenu menu;
	menu.LoadMenu (IDM_BTFILES);
	ApplyLanguageToMenuBtFiles (&menu);
	CMenu *pPopup = menu.GetSubMenu (0);

	CPoint pt; GetCursorPos (&pt);
	
	
	pPopup->TrackPopupMenu (TPM_RIGHTBUTTON | TPM_TOPALIGN | TPM_LEFTALIGN,	pt.x, pt.y, this);
		
	menu.DestroyMenu ();
}

void CDownloads_Bittorrent_Files::OnBtfilesDontdownload() 
{
	HTREEITEM hItem = GetTreeCtrl ().GetSelectedItem ();
	int iFile = GetTreeCtrl ().GetItemData (hItem);
	if (iFile == -1)
		return;
	if (m_dld->pMgr->GetBtDownloadMgr ()->getFilePriority (iFile) != 0)
	{
		m_dld->pMgr->GetBtDownloadMgr ()->setFilePriority (iFile, 0);
		SetItemText (hItem, 3, LS (L_PRIORITY_SKIP));
	}
}

void CDownloads_Bittorrent_Files::OnBtfilesHighpiority() 
{
	HTREEITEM hItem = GetTreeCtrl ().GetSelectedItem ();
	int iFile = GetTreeCtrl ().GetItemData (hItem);
	if (iFile == -1)
		return;
	if (m_dld->pMgr->GetBtDownloadMgr ()->getFilePriority (iFile) != 7)
	{
		m_dld->pMgr->GetBtDownloadMgr ()->setFilePriority (iFile, 7);
		SetItemText (hItem, 3, LS (L_PRIORITY_HIGH));
	}	
}

void CDownloads_Bittorrent_Files::OnBtfilesNormalpriority() 
{
	HTREEITEM hItem = GetTreeCtrl ().GetSelectedItem ();
	int iFile = GetTreeCtrl ().GetItemData (hItem);
	if (iFile == -1)
		return;
	if (m_dld->pMgr->GetBtDownloadMgr ()->getFilePriority (iFile) != 1)
	{
		m_dld->pMgr->GetBtDownloadMgr ()->setFilePriority (iFile, 1);
		SetItemText (hItem, 3, LS (L_PRIORITY_NORMAL));
	}	
}

void CDownloads_Bittorrent_Files::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CColumnTreeCtrl::OnShowWindow(bShow, nStatus);
	
	if (bShow)
		UpdateProgress ();
}

void CDownloads_Bittorrent_Files::ApplyLanguageToMenuBtFiles(CMenu *pmenu)
{
	pmenu->ModifyMenu (ID_BTFILES_NORMALPRIORITY, MF_BYCOMMAND|MF_STRING, ID_BTFILES_NORMALPRIORITY, 
		LS (L_NORMAL_PRIORITY));
	pmenu->ModifyMenu (ID_BTFILES_HIGHPIORITY, MF_BYCOMMAND|MF_STRING, ID_BTFILES_HIGHPIORITY, 
		LS (L_HIGH_PRIORITY));
	pmenu->ModifyMenu (ID_BTFILES_DONTDOWNLOAD, MF_BYCOMMAND|MF_STRING, ID_BTFILES_DONTDOWNLOAD, 
		LS (L_DONTDOWNLOAD));
}
