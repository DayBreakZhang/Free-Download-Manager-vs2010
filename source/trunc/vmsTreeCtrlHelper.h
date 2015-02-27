/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSTREECTRLHELPER_H__4E1DCEAD_E983_4AF4_9875_E497382938A2__INCLUDED_)
#define AFX_VMSTREECTRLHELPER_H__4E1DCEAD_E983_4AF4_9875_E497382938A2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsTreeCtrlHelper  
{
public:
	static void ExpandAll(CTreeCtrl *pCtrl, HTREEITEM hRoot, bool bExpand);
	static void ExpandAll (CTreeCtrl *pCtrl, bool bExpand);
	static void SetCheckOnChildItems (CTreeCtrl *pTreeCtrl, HTREEITEM hItem, BOOL bCheck);
	static BOOL isAtLeast1ChildChecked (CTreeCtrl* pTreeCtrl, HTREEITEM hRoot);
	vmsTreeCtrlHelper();
	virtual ~vmsTreeCtrlHelper();

};

#endif 
