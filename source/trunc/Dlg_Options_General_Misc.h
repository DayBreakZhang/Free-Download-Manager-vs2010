/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLG_OPTIONS_GENERAL_MISC_H__16743713_86E4_49D8_9720_42A72A683929__INCLUDED_)
#define AFX_DLG_OPTIONS_GENERAL_MISC_H__16743713_86E4_49D8_9720_42A72A683929__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "Dlg_Options_Page.h"
#include "resource.h"

class CDlg_Options_General_Misc : public CDlg_Options_Page
{

public:
	BOOL Apply();
	CString get_PageShortTitle();
	CString get_PageTitle();
	CDlg_Options_General_Misc(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlg_Options_General_Misc)
	enum { IDD = IDD_OPTIONS_GENERAL_MISC };
	CSliderCtrl	m_wndBlend2;
	CSliderCtrl	m_wndBlend1;
	CComboBox	m_wndShutdownTout;
	CComboBox	m_wndLaunchDldTout;
	CComboBox	m_wndHangupTout;
	CComboBox	m_wndExitTout;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlg_Options_General_Misc)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	BYTE m_blend1, m_blend2;
	void UpdateBlendsVals();
	void UpdateEnabled();
	UINT GetTimeoutForToutItem(CComboBox *pbox);
	void SelectToutItem(CComboBox *pbox, UINT uTimeout);
	void ApplyLanguage();
	bool m_bHangupToutChanged, m_bExitToutChanged, m_bShutdownToutChanged, m_bDTAEChanged;

	
	//{{AFX_MSG(CDlg_Options_General_Misc)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeHangupTout();
	afx_msg void OnSelchangeExitTout();
	afx_msg void OnSelchangeShutdownTout();
	afx_msg void OnSelchangeLaunchdldTout();
	afx_msg void OnDisablewdtaskafterexec();
	afx_msg void OnDropbox();
	afx_msg void OnDlinfo();
	afx_msg void OnCustomdrawTrancparency1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnCustomdrawTrancparency2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
