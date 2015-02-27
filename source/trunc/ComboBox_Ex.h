/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_EDITBOXEX_H__D71D7F46_8710_4A0A_8AF2_D8F06678F154__INCLUDED_)
#define AFX_EDITBOXEX_H__D71D7F46_8710_4A0A_8AF2_D8F06678F154__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CComboBox_Ex : public CComboBox
{

public:
	CComboBox_Ex();

public:

public:

	
	//{{AFX_VIRTUAL(CEditBoxEx)
	protected:
	//}}AFX_VIRTUAL

public:
	void SetReturnID (UINT nID);		
	BOOL Create (CWnd *pParent);
	virtual ~CComboBox_Ex();

	
protected:
	afx_msg LRESULT OnGetDroppedState (WPARAM, LPARAM);
	UINT m_uReturnID;		
	CFont m_font;		
	//{{AFX_MSG(CEditBoxEx)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
