/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_OPTSGENERALPAGE_H__71B9929F_19DF_4AF9_9007_F0A1A28A5B08__INCLUDED_)
#define AFX_OPTSGENERALPAGE_H__71B9929F_19DF_4AF9_9007_F0A1A28A5B08__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class COptsGeneralPage : public CPropertyPage
{
	DECLARE_DYNCREATE(COptsGeneralPage)

public:
	COptsGeneralPage();
	~COptsGeneralPage();

	//{{AFX_DATA(COptsGeneralPage)
	enum { IDD = IDD_OPTS_GENERAL };
		
		
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(COptsGeneralPage)
	public:
	virtual BOOL OnApply();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void ApplyLanguage();
	
	//{{AFX_MSG(COptsGeneralPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnAutostart();
	afx_msg void OnStartminimized();
	afx_msg void OnMintotray();
	afx_msg void OnCloseasminimize();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}

#endif 
