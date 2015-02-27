/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_SITEMANAGER_PASSWORDSPAGE_H__39AB8AEC_2C1D_494A_9C22_D7768A516111__INCLUDED_)
#define AFX_SITEMANAGER_PASSWORDSPAGE_H__39AB8AEC_2C1D_494A_9C22_D7768A516111__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CSiteManager_PasswordsPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CSiteManager_PasswordsPage)

public:
	CSiteManager_PasswordsPage();
	~CSiteManager_PasswordsPage();

	//{{AFX_DATA(CSiteManager_PasswordsPage)
	enum { IDD = IDD_SM_PASSWORDS };
		
		
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CSiteManager_PasswordsPage)
	public:
	virtual BOOL OnApply();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void ApplyLanguage();
	void UpdateEnabled ();
	
	//{{AFX_MSG(CSiteManager_PasswordsPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnUse();
	afx_msg void OnDelall();
	afx_msg void OnAsk();
	afx_msg void OnDontask();
	afx_msg void OnAutodel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}

#endif 
