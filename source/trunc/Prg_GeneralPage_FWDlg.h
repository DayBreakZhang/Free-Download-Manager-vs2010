/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_PRG_GENERALPAGE_FWDLG_H__80B0FE04_8005_4E85_BEB2_DAAD5AEB481A__INCLUDED_)
#define AFX_PRG_GENERALPAGE_FWDLG_H__80B0FE04_8005_4E85_BEB2_DAAD5AEB481A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CPrg_GeneralPage_FWDlg : public CDialog
{

public:
	BOOL m_bHideInFs;
	BYTE m_InfoWndTrancparency;
	BYTE m_DropBoxTrancparency;
	BOOL m_bInfoWnd;
	BOOL m_bDropBox;
	CPrg_GeneralPage_FWDlg(CWnd* pParent = NULL);   

	//{{AFX_DATA(CPrg_GeneralPage_FWDlg)
	enum { IDD = IDD_PRG_GENERAL_FW };
	CSliderCtrl	m_wndBlend2;
	CSliderCtrl	m_wndBlend1;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CPrg_GeneralPage_FWDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	BYTE m_blend1, m_blend2; 
	void UpdateBlendsVals();
	void UpdateEnabled();
	void ApplyLanguage();

	
	//{{AFX_MSG(CPrg_GeneralPage_FWDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnDropbox();
	afx_msg void OnDlinfo();
	afx_msg void OnCustomdrawTrancparency1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnCustomdrawTrancparency2(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
