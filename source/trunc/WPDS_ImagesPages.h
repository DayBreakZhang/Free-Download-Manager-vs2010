/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_WPDS_IMAGESPAGES_H__F7343A80_2790_41E3_8935_F61E433D4A29__INCLUDED_)
#define AFX_WPDS_IMAGESPAGES_H__F7343A80_2790_41E3_8935_F61E433D4A29__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CWPDS_ImagesPages : public CPropertyPage
{
	DECLARE_DYNCREATE(CWPDS_ImagesPages)

public:
	fsWPDSettings* m_wpds;
	CWPDS_ImagesPages();
	~CWPDS_ImagesPages();

	//{{AFX_DATA(CWPDS_ImagesPages)
	enum { IDD = IDD_WPDS_IMAGES };
		
		
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CWPDS_ImagesPages)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void PrepareCHMgr(CPoint point);
	void UpdateEnabled();
	void ApplyLanguage();
	
	//{{AFX_MSG(CWPDS_ImagesPages)
	virtual BOOL OnInitDialog();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnWhatisthis();
	afx_msg void OnDlimages();
	afx_msg void OnElon();
	afx_msg void OnDlimagesfromothersites();
	afx_msg void OnEldl();
	afx_msg void OnEldontdl();
	afx_msg void OnChangeExts();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}

#endif 
