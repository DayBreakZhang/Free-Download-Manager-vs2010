/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DOWNLOADSGROUPSCOMBOBOX_H__6EBB97AC_6FA4_488D_8411_8BC1A862C579__INCLUDED_)
#define AFX_DOWNLOADSGROUPSCOMBOBOX_H__6EBB97AC_6FA4_488D_8411_8BC1A862C579__INCLUDED_

#include "ComboBoxTreeCtrl.h"	
#include "vmsDownloadsGroupsMgr.h"	
#include "fsTicksMgr.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

class CDownloadsGroupsComboBox : public CComboBox
{

public:
	CDownloadsGroupsComboBox();

public:

public:

	
	//{{AFX_VIRTUAL(CDownloadsGroupsComboBox)
	//}}AFX_VIRTUAL

public:
	
	
	bool m_bHasAllGroupsItem;
	
	
	void Tree_UpdateSelection(BOOL bPostNotificationMsg = TRUE);
	
	void ShowDropDown (BOOL bShow);
	
	BOOL SelectGroupById (UINT nGroupId);
	
	void RememberSelectedGroup();
	
	vmsDownloadsGroupSmartPtr GetSelectedGroup();
	
	
	vmsDownloadsGroupSmartPtr CreateNewGroup(vmsDownloadsGroupSmartPtr pParentGroup);
	
	BOOL SelectGroup (vmsDownloadsGroupSmartPtr grp);
	
	void Fill();
	virtual ~CDownloadsGroupsComboBox();

	
protected:
	
	
	
	fsTicksMgr m_timeLastHide;
	
	vmsDownloadsGroupSmartPtr m_pSelectedGroup;
	
	void FillGroups (PDLDS_GROUPS_TREE pGroupsTree, HTREEITEM hRoot);
	
	CComboBoxTreeCtrl m_wndTree;
	
	struct _inc_TreeCtrlGroups
	{
		HTREEITEM hItem;
		vmsDownloadsGroupSmartPtr pGroup;
	};
	std::vector <_inc_TreeCtrlGroups> m_vGroupItems;
	//{{AFX_MSG(CDownloadsGroupsComboBox)
	afx_msg void OnDestroy();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
