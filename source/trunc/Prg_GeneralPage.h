/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_PRG_GENERALPAGE_H__9323C7FE_FE52_4A8A_8AA8_27E5A0E18A13__INCLUDED_)
#define AFX_PRG_GENERALPAGE_H__9323C7FE_FE52_4A8A_8AA8_27E5A0E18A13__INCLUDED_

#include "Prg_GeneralPage_FWDlg.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

class CPrg_GeneralPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CPrg_GeneralPage)

public:
	CPrg_GeneralPage();
	~CPrg_GeneralPage();

	//{{AFX_DATA(CPrg_GeneralPage)
	enum { IDD = IDD_PRG_GENERAL };
		
		
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CPrg_GeneralPage)
	public:
	virtual BOOL OnApply();
	virtual void OnCancel();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	CPrg_GeneralPage_FWDlg m_dlgFW;
	void PrepareCHMgr(CPoint point);
	void ApplyLanguage();
	BOOL m_bAutostartChanged;	
	
	//{{AFX_MSG(CPrg_GeneralPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnAutostart();
	afx_msg void OnStartminimized();
	afx_msg void OnMintotray();
	afx_msg void OnCloseasminimize();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnWhatisthis();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnModifyieuseragent();
	afx_msg void OnAdjustFw();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}

#endif 
