/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DOWNLOADPROPERTIES_INTEGRITYPAGE_H__799048F0_3743_4224_9662_DED14E03883E__INCLUDED_)
#define AFX_DOWNLOADPROPERTIES_INTEGRITYPAGE_H__799048F0_3743_4224_9662_DED14E03883E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CDownloadProperties_IntegrityPage : public CPropertyPage
{
	friend class CDownloadPropertiesSheet;

	DECLARE_DYNCREATE(CDownloadProperties_IntegrityPage)

public:
	CDownloadProperties_IntegrityPage();
	~CDownloadProperties_IntegrityPage();

	//{{AFX_DATA(CDownloadProperties_IntegrityPage)
	enum { IDD = IDD_DOWNLOAD_INTEGRITY };
	CComboBox	m_wndAlgorithm;
	CComboBox	m_wndICFR;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDownloadProperties_IntegrityPage)
	public:
	virtual BOOL OnApply();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	
	void MakeChecksumValid (CString &str);
	void PrepareCHMgr(CPoint point);
	void UpdateEnabled();
	void ApplyLanguage();
	DLDS_LIST *m_pvDlds;
	
	//{{AFX_MSG(CDownloadProperties_IntegrityPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnPerformcheckwhendone();
	afx_msg void OnSelchangeAlgorithm();
	afx_msg void OnSelchangeIcfr();
	afx_msg void OnChangeChecksum();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnWhatisthis();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}

#endif 
