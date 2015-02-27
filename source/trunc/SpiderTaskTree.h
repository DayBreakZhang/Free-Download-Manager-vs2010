/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_SPIDERTASKTREE_H__DE64DB79_BA42_476D_AD93_B2A20E13FF48__INCLUDED_)
#define AFX_SPIDERTASKTREE_H__DE64DB79_BA42_476D_AD93_B2A20E13FF48__INCLUDED_

#include "fsWebPageDownloader.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

class CSpiderTaskTree : public CTreeCtrl
{

public:
	CSpiderTaskTree();

public:

public:

	
	//{{AFX_VIRTUAL(CSpiderTaskTree)
	//}}AFX_VIRTUAL

public:
	
	
	void OnWebPageWillBeDeleted (fsDLWebPage* wp);
	
	void OnDldWillBeDeleted (vmsDownloadSmartPtr dld);
	
	
	void OnFileAdded (fsDLWebPageTree root, fsDLWebPageTree child);
	
	void UpdateDownload (vmsDownloadSmartPtr dld);
	void UpdateAll();
	fsWebPageDownloader *m_wpd;	

	BOOL Create (CWnd* pParent);
	virtual ~CSpiderTaskTree();

	
protected:
	void ShowContextMenu();
	void CalcCoordsForCurSel();

	
	
	struct _Conformity
	{
		HTREEITEM hItem;
		fsDLWebPageTreePtr wptree;
	};

	fs::list <_Conformity> m_vConfs;	

	
	int FindTree (HTREEITEM hItem);
	
	int FindTree (fsDLWebPageTree tree);
	
	int FindDownload (vmsDownloadSmartPtr dld);
	
	int GetDownloadImage (fsDLWebPage *wp);
	
	
	void AddTree (fsDLWebPageTree tree, HTREEITEM hParent);

	CImageList m_images;
	POINT m_rbPt;
	//{{AFX_MSG(CSpiderTaskTree)
	afx_msg void OnRclick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnDontdownloadanddel();
	afx_msg void OnKeydown(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
