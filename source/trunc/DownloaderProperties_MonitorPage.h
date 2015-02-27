/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DOWNLOADERPROPERTIES_MONITORPAGE_H__F249E6AE_5787_4BDD_B6B4_81109CC031B8__INCLUDED_)
#define AFX_DOWNLOADERPROPERTIES_MONITORPAGE_H__F249E6AE_5787_4BDD_B6B4_81109CC031B8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CDownloaderProperties_MonitorPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CDownloaderProperties_MonitorPage)

public:
	CDownloaderProperties_MonitorPage();
	~CDownloaderProperties_MonitorPage();

	//{{AFX_DATA(CDownloaderProperties_MonitorPage)
	enum { IDD = IDD_DLDR_MONITOR };
		
		
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDownloaderProperties_MonitorPage)
	public:
	virtual BOOL OnApply();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	
	BOOL m_bIEMenuWas;
	void UpdateEnabled();
	void PrepareCHMgr(CPoint point);
	void ApplyLanguage();
	
	//{{AFX_MSG(CDownloaderProperties_MonitorPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnWhatisthis();
	afx_msg void OnClipboard();
	afx_msg void OnAltpressed();
	afx_msg void OnAddtoiemenu();
	afx_msg void OnOpera();
	afx_msg void OnNetscape();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnIe2();
	afx_msg void OnAllowietodl();
	afx_msg void OnFirefox();
	afx_msg void OnSilent();
	afx_msg void OnCustomize();
	afx_msg void OnDontmonsmall();
	afx_msg void OnChangeSmallsize();
	afx_msg void OnMozilla();
	afx_msg void OnSkiplist();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}

#endif 
