/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLGT1TOT2_H__A3905778_E901_4CA2_8A43_FC0AB84F13E6__INCLUDED_)
#define AFX_DLGT1TOT2_H__A3905778_E901_4CA2_8A43_FC0AB84F13E6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CDlgT1ToT2 : public CDialog
{

public:
	FILETIME m_t2;	
	FILETIME m_t1;	
	CDlgT1ToT2(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlgT1ToT2)
	enum { IDD = IDD_T1TOT2 };
	CDateTimeCtrl	m_wndTo;
	CDateTimeCtrl	m_wndFrom;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlgT1ToT2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void ApplyLanguage();

	
	//{{AFX_MSG(CDlgT1ToT2)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
