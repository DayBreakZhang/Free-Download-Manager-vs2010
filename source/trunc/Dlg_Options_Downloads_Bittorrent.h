/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLG_OPTIONS_DOWNLOADS_BITTORRENT_H__E19EF673_B654_4748_87FC_F10AA1F10077__INCLUDED_)
#define AFX_DLG_OPTIONS_DOWNLOADS_BITTORRENT_H__E19EF673_B654_4748_87FC_F10AA1F10077__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "Dlg_Options_Page.h"
#include "resource.h"

class CDlg_Options_Downloads_Bittorrent : public CDlg_Options_Page
{

public:
	BOOL Apply();
	CString get_PageShortTitle();
	CString get_PageTitle();
	CDlg_Options_Downloads_Bittorrent(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlg_Options_Downloads_Bittorrent)
	enum { IDD = IDD_OPTIONS_DOWNLOADS_BITTORRENT };
	CComboBox	m_wndLimitDim;
	CTabCtrl	m_tabTrafficModes;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlg_Options_Downloads_Bittorrent)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	int m_iOldMode;
	
	struct _inc_ModeStgs {
		int iMaxConnections;
		int iMaxHalfConnections;
		int iUplTrafLim;	
		int iUplConnLim;	
		_inc_ModeStgs (int t = -1, int c = -1, int hc = 8, int conns = -1) : iUplTrafLim (t), iUplConnLim (c), iMaxHalfConnections (hc), iMaxConnections (conns) {}
	};
	
	std::vector <_inc_ModeStgs> m_vModes;

	void ApplyLanguage();
	void UpdateEnabled();
	void DlgToMode(int mode);
	void ModeToDlg();

	
	//{{AFX_MSG(CDlg_Options_Downloads_Bittorrent)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeTrafficmodestab(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnLimit();
	afx_msg void OnLimituploads();
	afx_msg void OnEnable();
	afx_msg void OnLimitconns();
	afx_msg void OnAssocwithtorrent();
	afx_msg void OnAssocwithMagnet();
	afx_msg void OnChangeConnslimitval();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
