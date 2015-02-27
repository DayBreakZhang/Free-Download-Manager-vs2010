/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_PRG_DATA_H__68BDFB5B_3AF9_4BDA_81AC_1AFD47E9CD91__INCLUDED_)
#define AFX_PRG_DATA_H__68BDFB5B_3AF9_4BDA_81AC_1AFD47E9CD91__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CPrg_Data : public CPropertyPage
{
	DECLARE_DYNCREATE(CPrg_Data)

public:
	CPrg_Data();
	~CPrg_Data();

	//{{AFX_DATA(CPrg_Data)
	enum { IDD = IDD_PRG_DATA };
		
		
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CPrg_Data)
	public:
	virtual BOOL OnApply();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void UpdateEnabled();
	void PrepareCHMgr(CPoint point);
	void ApplyLanguage();
	
	//{{AFX_MSG(CPrg_Data)
	virtual BOOL OnInitDialog();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnWhatisthis();
	afx_msg void OnKeep1();
	afx_msg void OnKeep2();
	afx_msg void OnChangeFolder();
	afx_msg void OnChangeAutosave();
	afx_msg void OnBrowse();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}

#endif 
