/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_SITES_ADVANCEDPAGE_H__7ED6DEC4_2A5E_462C_A8E5_0EC01BC641DE__INCLUDED_)
#define AFX_SITES_ADVANCEDPAGE_H__7ED6DEC4_2A5E_462C_A8E5_0EC01BC641DE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CSites_AdvancedPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CSites_AdvancedPage)

public:
	
	void ToDialog();
	
	void FromDialog();
	
	BOOL IsUserChangedProtocols();
	void SetMode(bool bIsAddingSite);
	fsSiteInfo* m_pSite;	
	CSites_AdvancedPage();
	~CSites_AdvancedPage();

	//{{AFX_DATA(CSites_AdvancedPage)
	enum { IDD = IDD_SITES_ADVANCED };
		
		
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CSites_AdvancedPage)
	public:
	virtual BOOL OnApply();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void PrepareCHMgr(CPoint point);
	BOOL m_bUserChangedProtocols; 
	BOOL m_bDialogWasInited;
	void ApplyLanguage();
	
	//{{AFX_MSG(CSites_AdvancedPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnWhatisthis();
	afx_msg void OnValidhttp();
	afx_msg void OnValidhttps();
	afx_msg void OnValidftp();
	afx_msg void OnValidsubdomains();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	bool m_bIsAddingSite;

};

//{{AFX_INSERT_LOCATION}}

#endif 
