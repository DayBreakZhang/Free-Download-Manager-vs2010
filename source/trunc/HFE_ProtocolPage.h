/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_HFE_PROTOCOLPAGE_H__73CA96B6_2F6C_44BA_A1C9_614A0E140F18__INCLUDED_)
#define AFX_HFE_PROTOCOLPAGE_H__73CA96B6_2F6C_44BA_A1C9_614A0E140F18__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CHFE_ProtocolPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CHFE_ProtocolPage)

public:
	CHFE_ProtocolPage();
	~CHFE_ProtocolPage();

	//{{AFX_DATA(CHFE_ProtocolPage)
	enum { IDD = IDD_HFE_PROTOCOL };
		
		
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CHFE_ProtocolPage)
	public:
	virtual BOOL OnApply();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void PrepareCHMgr(CPoint point);
	void ApplyLanguage();
	
	//{{AFX_MSG(CHFE_ProtocolPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnRetreiveaddinfo();
	afx_msg void OnPassivemode();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnWhatisthis();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}

#endif 
