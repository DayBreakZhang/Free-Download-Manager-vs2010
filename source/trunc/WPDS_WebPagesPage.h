/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_WPDS_WEBPAGESPAGE_H__69D8E35F_3EF3_46BB_B4DB_32AD4F4B944F__INCLUDED_)
#define AFX_WPDS_WEBPAGESPAGE_H__69D8E35F_3EF3_46BB_B4DB_32AD4F4B944F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CWPDS_WebPagesPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CWPDS_WebPagesPage)

public:
	bool m_bUsedAsSetDefaults;
	fsWPDSettings* m_wpds;
	CWPDS_WebPagesPage();
	~CWPDS_WebPagesPage();

	//{{AFX_DATA(CWPDS_WebPagesPage)
	enum { IDD = IDD_WPDS_WEBPAGES };
	CSpinButtonCtrl	m_wndDepthSpin;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CWPDS_WebPagesPage)
	public:
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void PrepareCHMgr(CPoint point);
	void ApplyLanguage();
	
	//{{AFX_MSG(CWPDS_WebPagesPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnWhatisthis();
	afx_msg void OnChangeHtmlexts();
	afx_msg void OnDlstyles();
	afx_msg void OnDlwpfromothersites();
	afx_msg void OnChangeDepth();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnUsehtm();
	afx_msg void OnIgnorelist();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}

#endif 
