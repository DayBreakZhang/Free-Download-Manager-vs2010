/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_COMBOBOXTREECTRL_H__7417A448_E598_4661_B199_27794E369546__INCLUDED_)
#define AFX_COMBOBOXTREECTRL_H__7417A448_E598_4661_B199_27794E369546__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CComboBoxTreeCtrl : public CTreeCtrl
{

public:
	CComboBoxTreeCtrl();

public:

public:

	
	//{{AFX_VIRTUAL(CComboBoxTreeCtrl)
	//}}AFX_VIRTUAL

public:
	class CDownloadsGroupsComboBox* m_pCombo;
	virtual ~CComboBoxTreeCtrl();

	
	
	BOOL CreateEx(DWORD dwExStyle, LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect,
			CWnd* pParentWnd, UINT nID, LPVOID lpParam = NULL);
	BOOL CreateEx(DWORD dwExStyle, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);

	
protected:
	//{{AFX_MSG(CComboBoxTreeCtrl)
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnKeydown(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
