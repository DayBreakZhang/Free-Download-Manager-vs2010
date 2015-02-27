/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_BTDLD_FILES_H__405B1684_479A_4F03_BF6A_67DC3FACC03D__INCLUDED_)
#define AFX_BTDLD_FILES_H__405B1684_479A_4F03_BF6A_67DC3FACC03D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "resource.h"
#include "ColumnTreeCtrl.h"

class CBtDld_Files : public CPropertyPage
{
	DECLARE_DYNCREATE(CBtDld_Files)

public:
	DLDS_LIST* m_pvDlds;
	CBtDld_Files();
	~CBtDld_Files();

	//{{AFX_DATA(CBtDld_Files)
	enum { IDD = IDD_BTDLD_FILES };
	CColumnTreeCtrl	m_wndFiles;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CBtDld_Files)
	public:
	virtual BOOL OnApply();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	struct _inc_filesTreeData {
		int nFileIndex;
		int nFilePriority;
	};
	static void GetFilesPriorities (int *piPriorities, CTreeCtrl *pTreeCtrl, HTREEITEM hRoot);
	afx_msg LRESULT OnCustTreeCheckBoxClicked(WPARAM, LPARAM lp);
	void AddFiles (fs::ListTree <vmsBtDownloadManager::vmsFile>* pTree, CColumnTreeCtrl* pTreeCtrl, HTREEITEM hRoot);
	std::vector <_inc_filesTreeData*> m_vToDelete;
	
	//{{AFX_MSG(CBtDld_Files)
	virtual BOOL OnInitDialog();
	afx_msg void OnCheckUncheckAll();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}

#endif 
