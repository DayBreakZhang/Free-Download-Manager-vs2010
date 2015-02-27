/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fdm.h"
#include "BtDld_Files.h"
#include "vmsTreeCtrlHelper.h"
#include "TorrentsWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CBtDld_Files, CPropertyPage)

CBtDld_Files::CBtDld_Files() : CPropertyPage(CBtDld_Files::IDD)
{
	//{{AFX_DATA_INIT(CBtDld_Files)
		
	//}}AFX_DATA_INIT

	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = LS (L_FILES);
}

CBtDld_Files::~CBtDld_Files()
{
	for (size_t i = 0; i < m_vToDelete.size (); i++)
		delete m_vToDelete [i];
}

void CBtDld_Files::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBtDld_Files)
	DDX_Control(pDX, IDC_FILES, m_wndFiles);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBtDld_Files, CPropertyPage)
	//{{AFX_MSG_MAP(CBtDld_Files)
	ON_BN_CLICKED(IDC_CHECK_UNCHECK_ALL, OnCheckUncheckAll)
	//}}AFX_MSG_MAP
	ON_MESSAGE (WM_CUSTTREE_CHECKBOX_CLICKED, OnCustTreeCheckBoxClicked)
END_MESSAGE_MAP()

BOOL CBtDld_Files::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();

	
	m_wndFiles.ModifyStyle (TVS_CHECKBOXES, 0);
	m_wndFiles.ModifyStyle (0, TVS_CHECKBOXES);

	fs::ListTree <vmsBtDownloadManager::vmsFile>::ListTreePtr tFiles;
	tFiles.CreateInstance ();
	m_pvDlds->at (0)->pMgr->GetBtDownloadMgr ()->GetFilesTree (tFiles);

	CRect rc; m_wndFiles.GetClientRect (&rc);
	m_wndFiles.GetTreeCtrl().ModifyStyle (0, TVS_HASBUTTONS | TVS_HASLINES | 
		TVS_LINESATROOT | TVS_CHECKBOXES | TVS_FULLROWSELECT);
	m_wndFiles.InsertColumn (0, LS (L_NAME), LVCFMT_LEFT, rc.Width () - 130 - GetSystemMetrics (SM_CXVSCROLL));
	m_wndFiles.InsertColumn (1, LS (L_SIZE), LVCFMT_LEFT, 130);
	AddFiles (tFiles, &m_wndFiles, TVI_ROOT);

	HTREEITEM hChild = m_wndFiles.GetTreeCtrl ().GetChildItem (TVI_ROOT);
	if (hChild && m_wndFiles.GetTreeCtrl ().GetNextItem (hChild, TVGN_NEXT) == NULL)
		m_wndFiles.GetTreeCtrl ().Expand (hChild, TVE_EXPAND);
	
	return TRUE;  
	              
}

void CBtDld_Files::AddFiles(fs::ListTree <vmsBtDownloadManager::vmsFile>* pTree, CColumnTreeCtrl *pTreeCtrl, HTREEITEM hRoot)
{
	for (int i = 0; i < pTree->GetLeafCount (); i++)
	{
		vmsBtDownloadManager::vmsFile &file = pTree->GetLeaf (i)->GetData ();
		if (file.nIndex == -1)
		{
			HTREEITEM hItem = pTreeCtrl->GetTreeCtrl ().InsertItem (TVIF_TEXT | TVIF_PARAM, 
				file.strName, 0, 0, 0, 0, (DWORD_PTR)NULL, hRoot, TVI_LAST);
			pTreeCtrl->SetItemText (hItem, 1, BytesToString (file.nFileSize));
			AddFiles (pTree->GetLeaf (i), pTreeCtrl, hItem);
			pTreeCtrl->GetTreeCtrl ().SetCheck (hItem, vmsTreeCtrlHelper::isAtLeast1ChildChecked (&pTreeCtrl->GetTreeCtrl (), hItem));
		}
		else
		{
			_inc_filesTreeData *pTD = new _inc_filesTreeData;
			m_vToDelete.push_back (pTD);
			pTD->nFileIndex = file.nIndex;
			pTD->nFilePriority = file.iPriority;
			HTREEITEM hItem = pTreeCtrl->GetTreeCtrl ().InsertItem (TVIF_TEXT | TVIF_PARAM, 
				file.strName, 0, 0, 0, 0, (DWORD_PTR)pTD, hRoot, TVI_LAST);
			pTreeCtrl->SetItemText (hItem, 1, BytesToString (file.nFileSize));
			pTreeCtrl->GetTreeCtrl ().SetCheck (hItem, file.iPriority != 0);
		}
	}
}

BOOL CBtDld_Files::OnApply() 
{
	fsDownload *dld = m_pvDlds->at (0);
	int *pi = new int [dld->pMgr->GetBtDownloadMgr ()->get_FileCount ()];
	GetFilesPriorities (pi, &m_wndFiles.GetTreeCtrl (), TVI_ROOT);
	dld->pMgr->GetBtDownloadMgr ()->PrioritizeFiles (pi);
	delete [] pi;

	if (_pwndDownloads->m_wndDownloads.m_info.m_bt.getActiveDownload () == dld)
		_pwndDownloads->m_wndDownloads.m_info.m_bt.UpdateActiveDownload ();
	if (_pwndTorrents && _pwndTorrents->m_wndBtTab.getActiveDownload () == dld)
		_pwndTorrents->m_wndBtTab.UpdateActiveDownload ();
	
	return CPropertyPage::OnApply();
}

LRESULT CBtDld_Files::OnCustTreeCheckBoxClicked(WPARAM, LPARAM lp)
{
	HTREEITEM hItem = (HTREEITEM)lp;
	vmsTreeCtrlHelper::SetCheckOnChildItems (&m_wndFiles.GetTreeCtrl (), 
		hItem, !m_wndFiles.GetTreeCtrl ().GetCheck (hItem));

	SetModified ();
	return 0;
}

void CBtDld_Files::OnCheckUncheckAll() 
{
	HTREEITEM hItem = m_wndFiles.GetTreeCtrl ().GetChildItem (TVI_ROOT);
	vmsTreeCtrlHelper::SetCheckOnChildItems (&m_wndFiles.GetTreeCtrl (), TVI_ROOT, 
		!m_wndFiles.GetTreeCtrl ().GetCheck (hItem));	
}

void CBtDld_Files::GetFilesPriorities(int *piPriorities, CTreeCtrl *pTreeCtrl, HTREEITEM hRoot)
{
	HTREEITEM hItem = pTreeCtrl->GetChildItem (hRoot);
	while (hItem)
	{
		BOOL bChecked = pTreeCtrl->GetCheck (hItem);
		_inc_filesTreeData *pTD = (_inc_filesTreeData*)pTreeCtrl->GetItemData (hItem);
		if (pTD)
		{
			int iPriority = 0;
			if (bChecked)
			{
				iPriority = pTD->nFilePriority;
				if (!iPriority)
					iPriority = 1;
			}
			piPriorities [pTD->nFileIndex] = iPriority;
		}

		if (pTreeCtrl->GetChildItem (hItem))
			GetFilesPriorities (piPriorities, pTreeCtrl, hItem);

		hItem = pTreeCtrl->GetNextItem (hItem, TVGN_NEXT);
	}
}
