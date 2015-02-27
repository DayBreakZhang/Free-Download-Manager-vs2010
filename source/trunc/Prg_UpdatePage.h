/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_PRG_UPDATEPAGE_H__1096C9B4_07EE_4C66_9F61_69850C2C1137__INCLUDED_)
#define AFX_PRG_UPDATEPAGE_H__1096C9B4_07EE_4C66_9F61_69850C2C1137__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CPrg_UpdatePage : public CPropertyPage
{
	DECLARE_DYNCREATE(CPrg_UpdatePage)

public:
	CPrg_UpdatePage();
	~CPrg_UpdatePage();

	//{{AFX_DATA(CPrg_UpdatePage)
	enum { IDD = IDD_PRG_UPDATE };
		
		
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CPrg_UpdatePage)
	public:
	virtual BOOL OnApply();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void UpdateEnabled();
	void PrepareCHMgr(CPoint point);
	void ApplyLanguage();
	
	//{{AFX_MSG(CPrg_UpdatePage)
	virtual BOOL OnInitDialog();
	afx_msg void OnChangeUpdateurl();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnWhatisthis();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnAutoupdatesInstall();
	afx_msg void OnAutoupdatesNotifyonly();
	afx_msg void OnAutoupdatesTurnoff();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}

#endif 
