/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_WPDS_FILESPAGE_H__2C5F33DC_43A0_45C5_9C1D_9E32D615CC87__INCLUDED_)
#define AFX_WPDS_FILESPAGE_H__2C5F33DC_43A0_45C5_9C1D_9E32D615CC87__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CWPDS_FilesPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CWPDS_FilesPage)

public:
	fsWPDSettings* m_wpds;
	CWPDS_FilesPage();
	~CWPDS_FilesPage();

	//{{AFX_DATA(CWPDS_FilesPage)
	enum { IDD = IDD_WPDS_FILES };
		
		
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CWPDS_FilesPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void PrepareCHMgr(CPoint point);
	void ApplyLanguage();
	void UpdateEnabled();
	
	//{{AFX_MSG(CWPDS_FilesPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnDlfiles();
	afx_msg void OnElon();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnWhatisthis();
	afx_msg void OnDlfilesfromothersites();
	afx_msg void OnEldl();
	afx_msg void OnEldontdl();
	afx_msg void OnChangeExts();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}

#endif 
