/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "SpiderTaskTree.h"
#include "Downloads_Tasks.h"
#include "DownloadsWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CDownloadsWnd *_pwndDownloads;

CSpiderTaskTree::CSpiderTaskTree()
{
	m_wpd = NULL;
}

CSpiderTaskTree::~CSpiderTaskTree()
{
}

BEGIN_MESSAGE_MAP(CSpiderTaskTree, CTreeCtrl)
	//{{AFX_MSG_MAP(CSpiderTaskTree)
	ON_NOTIFY_REFLECT(NM_RCLICK, OnRclick)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_DONTDOWNLOADANDDEL, OnDontdownloadanddel)
	ON_NOTIFY_REFLECT(TVN_KEYDOWN, OnKeydown)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CSpiderTaskTree::Create(CWnd *pParent)
{
	CRect rc (0, 0, 150, 50);

	if (FALSE == CTreeCtrl::Create (TVS_HASLINES | TVS_HASBUTTONS | TVS_LINESATROOT | TVS_SHOWSELALWAYS, rc, pParent, 0x996))
		return FALSE;

	CBitmap bmpg;
	bmpg.Attach (SBMP (IDB_DOWNLOADSTASKS));
	m_images.Create (16, 17, ILC_COLOR24 | ILC_MASK, 6, 2);
	m_images.Add (&bmpg, RGB (255, 0, 255));
	SetImageList (&m_images, TVSIL_NORMAL);

	ShowWindow (SW_SHOW);

	return TRUE;
}

void CSpiderTaskTree::UpdateAll()
{
	DeleteAllItems ();
	m_vConfs.clear ();
	
	if (m_wpd == NULL)
		return;

	fsDLWebPageTree tree = m_wpd->GetRootPage ();

	AddTree (tree, TVI_ROOT);
}

void CSpiderTaskTree::AddTree(fsDLWebPageTree tree, HTREEITEM hParent)
{
	fsDLWebPage *wp = tree->GetData ();
	int iImage = GetDownloadImage (wp);
	HTREEITEM hItem = InsertItem (wp->strURL, iImage,  iImage, hParent, TVI_SORT);
	
	_Conformity conf; 
	conf.hItem = hItem;
	conf.wptree = tree;
	m_vConfs.add (conf);

	SetItemData (hItem, (DWORD)tree);

	
	for (int i = 0; i < tree->GetLeafCount (); i++)
		AddTree (tree->GetLeaf (i), hItem);

	Expand (hItem, TVE_EXPAND);
}

int CSpiderTaskTree::GetDownloadImage(fsDLWebPage *wp)
{
	if (wp->dld)
		return CDownloads_Tasks::GetDownloadImage (wp->dld);
	else if (wp->bState & WPSTATE_DLDWASDELETED)	
		return 6;
	else
		return 1;	
}

void CSpiderTaskTree::UpdateDownload(vmsDownloadSmartPtr dld)
{
	int iIndex = FindDownload (dld);
	if (iIndex == -1)
		return;

	int iImage = GetDownloadImage (m_vConfs [iIndex].wptree->GetData ());
	SetItemImage (m_vConfs [iIndex].hItem, iImage, iImage);
}

int CSpiderTaskTree::FindDownload(vmsDownloadSmartPtr dld)
{
	for (int i = 0; i < m_vConfs.size (); i++)
	{
		if (m_vConfs [i].wptree->GetData ()->dld == dld)
			return i;
	}

	return -1;
}

void CSpiderTaskTree::OnFileAdded(fsDLWebPageTree root, fsDLWebPageTree child)
{
	int iIndex = FindTree (root);
	if (iIndex == -1)
		return;

	AddTree (child, m_vConfs [iIndex].hItem);
	Expand (m_vConfs [iIndex].hItem, TVE_EXPAND);
}

int CSpiderTaskTree::FindTree(fsDLWebPageTree tree)
{
	for (int i = 0; i < m_vConfs.size (); i++)
	{
		if (m_vConfs [i].wptree == tree)
			return i;
	}

	return -1;
}

void CSpiderTaskTree::OnDldWillBeDeleted(vmsDownloadSmartPtr dld)
{
	int iIndex = FindDownload (dld);
	if (iIndex == -1)
		return;

	int iImage = dld->pMgr->IsDone () ? 1 : 6;
	SetItemImage (m_vConfs [iIndex].hItem, iImage, iImage);
}

void CSpiderTaskTree::OnRclick(NMHDR* , LRESULT* pResult) 
{
	HTREEITEM hItem;
	
	*pResult = 0;

	hItem = HitTest (CPoint (m_rbPt.x, m_rbPt.y));

	if (hItem)
		SelectItem (hItem);
	else
		return;

	ShowContextMenu ();
}

void CSpiderTaskTree::OnRButtonDown(UINT nFlags, CPoint point) 
{
	m_rbPt = point;	
	CTreeCtrl::OnRButtonDown(nFlags, point);
}

int CSpiderTaskTree::FindTree(HTREEITEM hItem)
{
	for (int i = 0; i < m_vConfs.size (); i++)
	{
		if (m_vConfs [i].hItem == hItem)
			return i;
	}

	return -1;
}

void CSpiderTaskTree::OnDontdownloadanddel() 
{
	HTREEITEM hItem = GetSelectedItem ();
	if (hItem == NULL)
		return;

    if (_App.Deleted_ConfirmDeletion ())
	if (IDNO == MessageBox (LS (L_AREYOUSURE), LS (L_CONFIRMATION), MB_YESNO|MB_ICONQUESTION))
	{
		SetFocus ();
		return;
	}

	hItem = GetSelectedItem ();

	SetFocus ();

	int iItem = FindTree (hItem);
	if (iItem == -1)
		return;

	_pwndDownloads->DeleteDownload (m_vConfs [iItem].wptree->GetData ()->dld, TRUE);
}

void CSpiderTaskTree::OnWebPageWillBeDeleted(fsDLWebPage *wp)
{
	if (m_wpd == NULL)
		return;

	fsDLWebPageTree wptree = m_wpd->FindWebPageTree (wp->dld);

	if (wptree == NULL)
		return;

	int iItem = FindTree (wptree);
	if (iItem == -1)
		return;

	DeleteItem (m_vConfs [iItem].hItem);
	m_vConfs.del (iItem);
}

void CSpiderTaskTree::OnKeydown(NMHDR* pNMHDR, LRESULT* pResult) 
{
	TV_KEYDOWN* pTVKeyDown = (TV_KEYDOWN*)pNMHDR;
	

	switch (pTVKeyDown->wVKey)
	{
		case VK_DELETE:
			OnDontdownloadanddel ();
		break;

		case VK_APPS:
			CalcCoordsForCurSel ();
			ShowContextMenu ();
		break;
	}
	
	*pResult = 0;
}

void CSpiderTaskTree::CalcCoordsForCurSel()
{
	HTREEITEM hCur = GetSelectedItem ();
	if (hCur != NULL)
	{
		RECT rc;
		GetItemRect (hCur, &rc, TRUE);
		m_rbPt.x = rc.left;
		m_rbPt.y = rc.top;
	}
	else
		m_rbPt.x = m_rbPt.y = 30;
}

void CSpiderTaskTree::ShowContextMenu()
{
	HTREEITEM hItem = GetSelectedItem ();
	if (hItem == NULL)
		return;

	int iItem = FindTree (hItem);
	if (iItem == -1)
		return;

	CMenu menu;
	menu.LoadMenu (IDM_SPIDER_TREE);
	CMenu *pPopup = menu.GetSubMenu (0);

	CString str = LS (L_DONTDOWNLOADANDDEL); str += "\tDel";
	menu.ModifyMenu (ID_DONTDOWNLOADANDDEL, MF_BYCOMMAND|MF_STRING, ID_DONTDOWNLOADANDDEL, str);

	fsDLWebPage *wp = m_vConfs [iItem].wptree->GetData ();
	if (wp->dld == NULL || wp->dld->pMgr->IsDone ())
		pPopup->EnableMenuItem (ID_DONTDOWNLOADANDDEL, MF_BYCOMMAND | MF_GRAYED);

	ClientToScreen (&m_rbPt);
	pPopup->TrackPopupMenu (TPM_RIGHTBUTTON | TPM_TOPALIGN | TPM_LEFTALIGN,	m_rbPt.x, m_rbPt.y, this);
	menu.DestroyMenu ();
}
