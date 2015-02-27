/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fdm.h"
#include "vmsTreeCtrlHelper.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsTreeCtrlHelper::vmsTreeCtrlHelper()
{

}

vmsTreeCtrlHelper::~vmsTreeCtrlHelper()
{

}

BOOL vmsTreeCtrlHelper::isAtLeast1ChildChecked(CTreeCtrl *pTreeCtrl, HTREEITEM hRoot)
{
	HTREEITEM hChild = pTreeCtrl->GetChildItem (hRoot);
	while (hChild)
	{
		if (pTreeCtrl->GetCheck (hChild))
			return TRUE;
		if (pTreeCtrl->GetChildItem (hChild))
		{
			if (isAtLeast1ChildChecked (pTreeCtrl, hChild))
				return TRUE;
		}
		hChild = pTreeCtrl->GetNextItem (hChild, TVGN_NEXT);
	}
	return FALSE;
}

void vmsTreeCtrlHelper::SetCheckOnChildItems(CTreeCtrl *pTreeCtrl, HTREEITEM hItem, BOOL bCheck)
{
	HTREEITEM hChild = pTreeCtrl->GetChildItem (hItem);
	while (hChild)
	{
		pTreeCtrl->SetCheck (hChild, bCheck);
		if (pTreeCtrl->GetChildItem (hChild))
			SetCheckOnChildItems (pTreeCtrl, hChild, bCheck);
		hChild = pTreeCtrl->GetNextItem (hChild, TVGN_NEXT);
	}
}

void vmsTreeCtrlHelper::ExpandAll(CTreeCtrl *pCtrl, bool bExpand)
{
	ExpandAll (pCtrl, TVI_ROOT, bExpand);
}

void vmsTreeCtrlHelper::ExpandAll(CTreeCtrl *pCtrl, HTREEITEM hRoot, bool bExpand)
{
	pCtrl->Expand (hRoot, bExpand ? TVE_EXPAND : TVE_COLLAPSE);
	HTREEITEM hChild = pCtrl->GetChildItem (hRoot);
	while (hChild)
	{
		ExpandAll (pCtrl, hChild, bExpand);
		hChild = pCtrl->GetNextItem (hChild, TVGN_NEXT);
	}
}
