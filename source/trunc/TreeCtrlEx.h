/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_TREECTRLEX_H__A6E8AFC4_C287_483E_B97E_EED3162C8A66__INCLUDED_)
#define AFX_TREECTRLEX_H__A6E8AFC4_C287_483E_B97E_EED3162C8A66__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CTreeCtrlEx : public CTreeCtrl
{

public:
	CTreeCtrlEx();

public:

public:

	
	//{{AFX_VIRTUAL(CTreeCtrlEx)
	//}}AFX_VIRTUAL

public:
	
	BOOL IsChecked (HTREEITEM hItem);
	
	void SetCheck (HTREEITEM hItem, BOOL bCheck = TRUE);
	virtual ~CTreeCtrlEx();

	
protected:
	//{{AFX_MSG(CTreeCtrlEx)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
