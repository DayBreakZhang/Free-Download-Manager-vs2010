/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLGDELETEDPROPERTIES_H__AEB20296_23CA_42E0_B0D1_6CBC2A9D7917__INCLUDED_)
#define AFX_DLGDELETEDPROPERTIES_H__AEB20296_23CA_42E0_B0D1_6CBC2A9D7917__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CDlgDeletedProperties : public CDialog
{

public:
	CDlgDeletedProperties(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlgDeletedProperties)
	enum { IDD = IDD_DELETED_PROPS };
	CSpinButtonCtrl	m_wndMaxValSpin;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlgDeletedProperties)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void PrepareCHMgr(CPoint point);
	void UpdateEnabled();
	void ApplyLanguage();

	
	//{{AFX_MSG(CDlgDeletedProperties)
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnDontuse();
	virtual void OnOK();
	afx_msg void OnUsemax();
	afx_msg void OnWhatisthis();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
