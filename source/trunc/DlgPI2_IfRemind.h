/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLGPI2_IFREMIND_H__0141B5F5_38BD_4A3F_89B1_F390A688FB7A__INCLUDED_)
#define AFX_DLGPI2_IFREMIND_H__0141B5F5_38BD_4A3F_89B1_F390A688FB7A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CDlgPI2_IfRemind : public CDialog
{

public:
	CDlgPI2_IfRemind(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlgPI2_IfRemind)
	enum { IDD = IDD_PI2_IFREMIND };
		
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlgPI2_IfRemind)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:

	
	//{{AFX_MSG(CDlgPI2_IfRemind)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
