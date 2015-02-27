/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DOWNLOADERPROPERTIES_BTPAGE_H__D0AE310B_373D_4D46_B06F_37634BB7AB9A__INCLUDED_)
#define AFX_DOWNLOADERPROPERTIES_BTPAGE_H__D0AE310B_373D_4D46_B06F_37634BB7AB9A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CDownloaderProperties_BtPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CDownloaderProperties_BtPage)

public:
	CDownloaderProperties_BtPage();
	~CDownloaderProperties_BtPage();

	//{{AFX_DATA(CDownloaderProperties_BtPage)
	enum { IDD = IDD_DLDR_BT };
	CComboBox	m_wndLimitDim;
	CTabCtrl	m_tabTrafficModes;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDownloaderProperties_BtPage)
	public:
	virtual BOOL OnApply();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void PrepareCHMgr(CPoint point);
	void ApplyLanguage();
	
	bool m_bDontSetModif;
	int m_iOldMode;
	void UpdateEnabled();
	
	void DlgToMode(int mode);
	
	void ModeToDlg();
	
	struct _inc_ModeStgs {
		int iUplTrafLim;	
		int iUplConnLim;	
		int iMaxHalfConnections;
		_inc_ModeStgs (int t = -1, int c = -1, int hc = 8) : iUplTrafLim (t), iUplConnLim (c), iMaxHalfConnections (hc) {}
	};
	
	std::vector <_inc_ModeStgs> m_vModes;

	
	//{{AFX_MSG(CDownloaderProperties_BtPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeTrafficmodestab(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnLimit();
	afx_msg void OnLimituploads();
	afx_msg void OnEnable();
	afx_msg void OnChangeLimitval();
	afx_msg void OnSelchangeLimitdim();
	afx_msg void OnChangeUpllimitval();
	afx_msg void OnChangePortFrom();
	afx_msg void OnChangePortTo();
	afx_msg void OnUseDht();
	afx_msg void OnUseLocalPeer();
	afx_msg void OnUseUPnP();
	afx_msg void OnUseNATPMP();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnWhatisthis();
	afx_msg void OnAssocwithtorrent();
	afx_msg void OnAssocwithMagnet();
	afx_msg void OnDisableSeeding();
	afx_msg void OnChangeMaxhalfsval();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}

#endif 
