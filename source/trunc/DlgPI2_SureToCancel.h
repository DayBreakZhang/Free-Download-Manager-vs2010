/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLGPI2_SURETOCANCEL_H__ADFCECA4_D294_4763_9FCA_54F64C798C04__INCLUDED_)
#define AFX_DLGPI2_SURETOCANCEL_H__ADFCECA4_D294_4763_9FCA_54F64C798C04__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CDlgPI2_SureToCancel : public CDialog
{

public:
	CDlgPI2_SureToCancel(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlgPI2_SureToCancel)
	enum { IDD = IDD_PI2_SURETOCANCEL };
		
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlgPI2_SureToCancel)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:

	
	//{{AFX_MSG(CDlgPI2_SureToCancel)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
