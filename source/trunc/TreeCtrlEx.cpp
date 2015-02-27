/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "TreeCtrlEx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CTreeCtrlEx::CTreeCtrlEx()
{
}

CTreeCtrlEx::~CTreeCtrlEx()
{
}

BEGIN_MESSAGE_MAP(CTreeCtrlEx, CTreeCtrl)
	//{{AFX_MSG_MAP(CTreeCtrlEx)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CTreeCtrlEx::OnLButtonDown(UINT nFlags, CPoint point) 
{
	UINT uFlags;
	HTREEITEM hItem = HitTest (point, &uFlags);

	if (hItem && uFlags == TVHT_ONITEMSTATEICON)
	{
		BOOL bChecked = IsChecked (hItem);
		SetCheck (hItem, !bChecked);
		return;
	}
	
	CTreeCtrl::OnLButtonDown(nFlags, point);
}

void CTreeCtrlEx::SetCheck(HTREEITEM hItem, BOOL bCheck)
{
	SetItemState (hItem, INDEXTOSTATEIMAGEMASK ((bCheck ? 2 : 1)), TVIS_STATEIMAGEMASK);
}

BOOL CTreeCtrlEx::IsChecked(HTREEITEM hItem)
{
	return GetItemState (hItem, TVIS_STATEIMAGEMASK) >> 12 == 2;
}
