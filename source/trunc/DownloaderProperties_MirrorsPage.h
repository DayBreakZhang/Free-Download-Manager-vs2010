/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DOWNLOADERPROPERTIES_MIRRORSPAGE_H__15A1AFAF_9B47_40E7_9AFA_B69DE4F26600__INCLUDED_)
#define AFX_DOWNLOADERPROPERTIES_MIRRORSPAGE_H__15A1AFAF_9B47_40E7_9AFA_B69DE4F26600__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CDownloaderProperties_MirrorsPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CDownloaderProperties_MirrorsPage)

public:
	CDownloaderProperties_MirrorsPage();
	~CDownloaderProperties_MirrorsPage();

	//{{AFX_DATA(CDownloaderProperties_MirrorsPage)
	enum { IDD = IDD_DLDR_MIRRORS };
	CComboBox	m_wndMirrServers;
	CComboBox	m_wndMinSizeDim;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDownloaderProperties_MirrorsPage)
	public:
	virtual BOOL OnApply();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void UpdateEnabled();
	void PrepareCHMgr(CPoint point);
	void ApplyLanguage();
	
	//{{AFX_MSG(CDownloaderProperties_MirrorsPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnWhatisthis();
	afx_msg void OnAuto();
	afx_msg void OnMaxmirrors();
	afx_msg void OnChangeMaxmirrorsval();
	afx_msg void OnCalcspeed();
	afx_msg void OnRecalcspeed();
	afx_msg void OnChangeRecalcval();
	afx_msg void OnChangeFileminsize();
	afx_msg void OnSelchangeFileminsizedim();
	afx_msg void OnSelchangeMirrservers();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}

#endif 
