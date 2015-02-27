/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLGCUSTOMIZEIEMENU_H__3A951E42_C8F9_41E4_A27C_74650E6CFFEA__INCLUDED_)
#define AFX_DLGCUSTOMIZEIEMENU_H__3A951E42_C8F9_41E4_A27C_74650E6CFFEA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CDlgCustomizeIEMenu : public CDialog
{

public:
	CDlgCustomizeIEMenu(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlgCustomizeIEMenu)
	enum { IDD = IDD_CUSTOMIZEIEMENU };
		
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlgCustomizeIEMenu)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	BOOL m_bDLThisWas, m_bDLPageWas, m_bDLAllWas, m_bDLSelectedWas, m_bDLVideoWas;
	void ApplyLanguage();
	
	//{{AFX_MSG(CDlgCustomizeIEMenu)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
