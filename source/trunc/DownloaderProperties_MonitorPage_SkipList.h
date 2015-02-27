/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DOWNLOADERPROPERTIES_MONITORPAGE_SKIPLIST_H__EE259FB4_630B_4A0A_8356_1464FE3E18C2__INCLUDED_)
#define AFX_DOWNLOADERPROPERTIES_MONITORPAGE_SKIPLIST_H__EE259FB4_630B_4A0A_8356_1464FE3E18C2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CDownloaderProperties_MonitorPage_SkipList : public CDialog
{

public:
	CDownloaderProperties_MonitorPage_SkipList(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDownloaderProperties_MonitorPage_SkipList)
	enum { IDD = IDD_DLDR_MONITOR_SKIPLIST };
		
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDownloaderProperties_MonitorPage_SkipList)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void PrepareCHMgr(CPoint point);
	void ApplyLanguage();

	
	//{{AFX_MSG(CDownloaderProperties_MonitorPage_SkipList)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnWhatisthis();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
