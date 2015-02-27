/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DOWNLOADERPROPERTIES_NOTIFICATIONSPAGE_H__E9EA3649_0C17_43B7_BA1F_6724AF46A755__INCLUDED_)
#define AFX_DOWNLOADERPROPERTIES_NOTIFICATIONSPAGE_H__E9EA3649_0C17_43B7_BA1F_6724AF46A755__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CDownloaderProperties_NotificationsPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CDownloaderProperties_NotificationsPage)

public:
	CDownloaderProperties_NotificationsPage();
	~CDownloaderProperties_NotificationsPage();

	//{{AFX_DATA(CDownloaderProperties_NotificationsPage)
	enum { IDD = IDD_DLDR_NOTIFICATIONS };
	CSpinButtonCtrl	m_wndTSpin;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDownloaderProperties_NotificationsPage)
	public:
	virtual BOOL OnApply();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void UpdateEnabled();
	void PrepareCHMgr(CPoint point);
	void ApplyLanguage();
	
	//{{AFX_MSG(CDownloaderProperties_NotificationsPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnWhatisthis();
	afx_msg void OnChangeTimeout();
	afx_msg void OnUseballoon();
	afx_msg void OnUsesounds();
	afx_msg void OnCustomize();
	afx_msg void OnDisableforbatchdlds();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}

#endif 
