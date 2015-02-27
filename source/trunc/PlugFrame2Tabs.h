/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_PLUGFRAME2TABS_H__D7DB4034_ADD8_47E1_808A_ABF0973CD2AC__INCLUDED_)
#define AFX_PLUGFRAME2TABS_H__D7DB4034_ADD8_47E1_808A_ABF0973CD2AC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CPlugFrame2Tabs : public CTabCtrl
{

public:
	CPlugFrame2Tabs();

public:

public:

	
	//{{AFX_VIRTUAL(CPlugFrame2Tabs)
	//}}AFX_VIRTUAL

public:
	BOOL Create (CWnd* pParent);
	virtual ~CPlugFrame2Tabs();

	
protected:
	CFont m_itemsFont;
	class CPluginFrame2 *m_parent;
	//{{AFX_MSG(CPlugFrame2Tabs)
	afx_msg void OnSelchange(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
