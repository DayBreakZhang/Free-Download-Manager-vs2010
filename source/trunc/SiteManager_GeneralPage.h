/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_SITEMANAGER_GENERALPAGE_H__D48E1BB0_7646_40D2_A661_D4B72CFBCF8F__INCLUDED_)
#define AFX_SITEMANAGER_GENERALPAGE_H__D48E1BB0_7646_40D2_A661_D4B72CFBCF8F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CSiteManager_GeneralPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CSiteManager_GeneralPage)

public:
	CSiteManager_GeneralPage();
	~CSiteManager_GeneralPage();

	//{{AFX_DATA(CSiteManager_GeneralPage)
	enum { IDD = IDD_SM_GENERAL };
		
		
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CSiteManager_GeneralPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	
	//{{AFX_MSG(CSiteManager_GeneralPage)
		
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}

#endif 
