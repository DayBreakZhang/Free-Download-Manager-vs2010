/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLG_SAVEPASSWORD_H__D4D7881E_19A8_40EB_A503_E50B971C5C73__INCLUDED_)
#define AFX_DLG_SAVEPASSWORD_H__D4D7881E_19A8_40EB_A503_E50B971C5C73__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CDlg_SavePassword : public CDialog
{

public:
	CDlg_SavePassword(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlg_SavePassword)
	enum { IDD = IDD_SAVEPASSWORD };
		
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlg_SavePassword)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void ApplyLanguage();

	
	//{{AFX_MSG(CDlg_SavePassword)
	virtual void OnOK();
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
