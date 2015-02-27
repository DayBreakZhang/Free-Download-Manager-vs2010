/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "DownloadsGroupsComboBox.h"
#include "GroupDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDownloadsGroupsComboBox::CDownloadsGroupsComboBox()
{
	m_wndTree.m_pCombo = this;
	m_bHasAllGroupsItem = false;
}

CDownloadsGroupsComboBox::~CDownloadsGroupsComboBox()
{
}

BEGIN_MESSAGE_MAP(CDownloadsGroupsComboBox, CComboBox)
	//{{AFX_MSG_MAP(CDownloadsGroupsComboBox)
	ON_WM_DESTROY()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_KEYDOWN()
	ON_WM_KILLFOCUS()
	ON_WM_SETFOCUS()
	ON_WM_LBUTTONDBLCLK()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CDownloadsGroupsComboBox::Fill()
{
	m_wndTree.CreateEx (WS_EX_TOPMOST, WC_TREEVIEW, "", WS_POPUP | WS_BORDER |
		TVS_FULLROWSELECT | TVS_HASLINES |  TVS_TRACKSELECT, 
		CRect (0,0,0,0), GetParent (), 0);
	m_wndTree.SetWindowPos (&CWnd::wndTopMost, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

	HTREEITEM hRoot = TVI_ROOT;

	if (m_bHasAllGroupsItem)
	{
		_inc_TreeCtrlGroups item;
		item.pGroup = NULL;
		hRoot = item.hItem = m_wndTree.InsertItem (LS (L_ALLGROUPS), TVI_ROOT, TVI_SORT);
		m_wndTree.SetItemData (item.hItem, NULL);
		m_vGroupItems.push_back (item);
	}

	FillGroups (_DldsGrps.GetGroupsTree (), hRoot);

	if (m_bHasAllGroupsItem)
		m_wndTree.Expand (hRoot, TVE_EXPAND);

	UINT nId = _App.CreateDld_IdOfLastGrpSelected ();
	size_t i;
	for (i = m_bHasAllGroupsItem ? 1 : 0; i < m_vGroupItems.size (); i++)
	{
		if (m_vGroupItems [i].pGroup->nId == nId)
		{
			m_wndTree.SelectItem (m_vGroupItems [i].hItem);
			break;
		}
	}
	if (i == m_vGroupItems.size ())
		m_wndTree.SelectItem (m_vGroupItems [0].hItem);

	Tree_UpdateSelection (FALSE);
}

BOOL CDownloadsGroupsComboBox::SelectGroup(vmsDownloadsGroupSmartPtr grp)
{
	HTREEITEM hSelect = NULL;

	if (grp == NULL)
	{
		if (m_bHasAllGroupsItem)
		{
			hSelect = m_vGroupItems [0].hItem;
		}
	}
	else
	{
		for (size_t i = m_bHasAllGroupsItem ? 1 : 0; i < m_vGroupItems.size (); i++)
		{
			if (m_vGroupItems [i].pGroup->nId == grp->nId)
			{
				hSelect = m_vGroupItems [i].hItem;
				break;
			}
		}

		if (hSelect == NULL)
			return FALSE;
	}

	m_wndTree.SelectItem (hSelect);

	Tree_UpdateSelection (FALSE);

	return TRUE;
}

vmsDownloadsGroupSmartPtr CDownloadsGroupsComboBox::CreateNewGroup(vmsDownloadsGroupSmartPtr pParentGroup)
{
	CGroupDlg dlg (NULL, pParentGroup, this);
   	if (IDCANCEL == _DlgMgr.DoModal (&dlg))
		return NULL;

	HTREEITEM hRoot = TVI_ROOT;
	if (dlg.m_pParentGroup != NULL)
	{
		for (size_t i = m_bHasAllGroupsItem ? 1 : 0; i < m_vGroupItems.size (); i++)
		{
			if (dlg.m_pParentGroup->nId == m_vGroupItems [i].pGroup->nId)
			{
				hRoot = m_vGroupItems [i].hItem;
				break;	
			}
		}
	}

	_inc_TreeCtrlGroups item;
	item.pGroup = dlg.m_pGroup;
	item.hItem = m_wndTree.InsertItem (dlg.m_pGroup->strName, hRoot, TVI_SORT);
	m_wndTree.SetItemData (item.hItem, (DWORD_PTR)(vmsDownloadsGroup*)dlg.m_pGroup);
	m_vGroupItems.push_back (item);

	SelectGroup (dlg.m_pGroup);

	return dlg.m_pGroup;
}

vmsDownloadsGroupSmartPtr CDownloadsGroupsComboBox::GetSelectedGroup()
{
	return m_pSelectedGroup;
}

void CDownloadsGroupsComboBox::OnDestroy() 
{
	RememberSelectedGroup ();	

	CComboBox::OnDestroy();
}

void CDownloadsGroupsComboBox::RememberSelectedGroup()
{
	vmsDownloadsGroupSmartPtr pGroup = GetSelectedGroup ();
	if (pGroup != NULL)
		_App.CreateDld_IdOfLastGrpSelected (pGroup->nId);
}

BOOL CDownloadsGroupsComboBox::SelectGroupById(UINT nGroupId)
{
	if (nGroupId == (UINT)-1)
		return FALSE;

	vmsDownloadsGroupSmartPtr pGroup = _DldsGrps.FindGroup (nGroupId);
	if (pGroup == NULL)
		return FALSE;

	return SelectGroup (pGroup);
}

void CDownloadsGroupsComboBox::OnLButtonDown(UINT nFlags, CPoint point) 
{
	fsTicksMgr timeNow; timeNow.Now ();
	if (timeNow - m_timeLastHide > 300) 
	{
		CComboBox::OnLButtonDown(nFlags, point);

		if (m_wndTree.IsWindowVisible () == FALSE)
			ShowDropDown (TRUE);
	}
}

void CDownloadsGroupsComboBox::OnLButtonUp(UINT nFlags, CPoint point) 
{
	CComboBox::OnLButtonUp(nFlags, point);
}

void CDownloadsGroupsComboBox::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	if (nChar == VK_DOWN || nChar == VK_UP)
	{
		m_wndTree.SendMessage (WM_KEYDOWN, nChar, 0);
		Tree_UpdateSelection ();
	}

	CComboBox::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CDownloadsGroupsComboBox::ShowDropDown(BOOL bShow)
{
	if (m_wndTree.IsWindowVisible ())
	{
		if (bShow == FALSE)
		{
			m_wndTree.ShowWindow (SW_HIDE);
			m_timeLastHide.Now ();
		}
		return;
	}

	if (bShow == FALSE)
		return;

	CRect rc;
	GetWindowRect (&rc);

	rc.top = rc.bottom;
	rc.bottom += 150;

	m_wndTree.MoveWindow (&rc);

	m_wndTree.ShowWindow (SW_SHOW);

	m_wndTree.SetFocus ();
}

void CDownloadsGroupsComboBox::OnKillFocus(CWnd* pNewWnd) 
{
	CComboBox::OnKillFocus(pNewWnd);
}

void CDownloadsGroupsComboBox::OnSetFocus(CWnd* pOldWnd) 
{
	CComboBox::OnSetFocus(pOldWnd);
	
	if (pOldWnd != NULL && pOldWnd->m_hWnd == m_wndTree.m_hWnd)
		ShowDropDown (FALSE);
}

void CDownloadsGroupsComboBox::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	OnLButtonDown (nFlags, point);
	
}

void CDownloadsGroupsComboBox::Tree_UpdateSelection(BOOL bPostNotificationMsg)
{
	
	
	DeleteString (0); 
	HTREEITEM hItem = m_wndTree.GetSelectedItem ();
	if (hItem)
	{
		

		m_pSelectedGroup = (vmsDownloadsGroup*)m_wndTree.GetItemData (hItem);
		AddString (m_wndTree.GetItemText (hItem));
	}
	else
	{
		

		m_pSelectedGroup = NULL;
		AddString ("");
	}
	SetCurSel (0);	

	if (bPostNotificationMsg)
	{
		GetParent ()->PostMessage (WM_COMMAND, MAKEWPARAM (GetDlgCtrlID (), CBN_SELCHANGE), 
			(LPARAM)m_hWnd);
	}
}

void CDownloadsGroupsComboBox::FillGroups(PDLDS_GROUPS_TREE pGroupsTree, HTREEITEM hRoot)
{
	for (int i = 0; i < pGroupsTree->GetLeafCount (); i++)
	{
		
		_inc_TreeCtrlGroups item;
		item.pGroup = pGroupsTree->GetLeaf (i)->GetData ();
		item.hItem = m_wndTree.InsertItem (
			item.pGroup->nId != GRP_OTHER_ID ? item.pGroup->strName : LS (L_OTHER), 
			hRoot, TVI_SORT);
		m_wndTree.SetItemData (item.hItem, (DWORD_PTR)(vmsDownloadsGroup*)item.pGroup);
		m_vGroupItems.push_back (item);
		
		FillGroups (pGroupsTree->GetLeaf (i), item.hItem);
		
		m_wndTree.Expand (item.hItem, TVE_EXPAND);
	}
}
