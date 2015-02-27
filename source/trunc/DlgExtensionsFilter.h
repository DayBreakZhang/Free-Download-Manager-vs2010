/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLGEXTENSIONSFILTER_H__11C37517_DA6E_48B2_B30D_38C954763624__INCLUDED_)
#define AFX_DLGEXTENSIONSFILTER_H__11C37517_DA6E_48B2_B30D_38C954763624__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CDlgExtensionsFilter : public CDialog
{

public:
	
	
	BOOL m_bRemove;
	
	CString m_strExts;
	CDlgExtensionsFilter(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlgExtensionsFilter)
	enum { IDD = IDD_EXTFILTER };
		
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlgExtensionsFilter)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void ApplyLanguage();

	
	//{{AFX_MSG(CDlgExtensionsFilter)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
