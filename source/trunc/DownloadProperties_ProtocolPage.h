/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DOWNLOADPROPERTIES_PROTOCOLPAGE_H__2D4E9684_45C0_4AB9_8556_8064788A5BA7__INCLUDED_)
#define AFX_DOWNLOADPROPERTIES_PROTOCOLPAGE_H__2D4E9684_45C0_4AB9_8556_8064788A5BA7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "list.h"

class CDownloadProperties_ProtocolPage : public CPropertyPage
{
	friend class CDownloadPropertiesSheet;

	DECLARE_DYNCREATE(CDownloadProperties_ProtocolPage)

public:
	CDownloadProperties_ProtocolPage();
	~CDownloadProperties_ProtocolPage();

	//{{AFX_DATA(CDownloadProperties_ProtocolPage)
	enum { IDD = IDD_DOWNLOAD_PROTOCOL };
		
		
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDownloadProperties_ProtocolPage)
	public:
	virtual BOOL OnApply();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void PrepareCHMgr(CPoint point);
	void ApplyLanguage();
	BOOL m_bRefererModified;	
	void UpdateEnabled();
	CComboBox m_wndUserAgent;

	DLDS_LIST *m_pvDlds;
	
	//{{AFX_MSG(CDownloadProperties_ProtocolPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnBinary();
	afx_msg void OnAscii();
	afx_msg void OnAsciiforexts();
	afx_msg void OnEditchangeUseragent();
	afx_msg void OnSelchangeUseragent();
	afx_msg void OnChangeReferer();
	afx_msg void OnUsehttp11();
	afx_msg void OnUsecookie();
	afx_msg void OnUsepassivemode();
	afx_msg void OnChangeAsciiexts();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnWhatisthis();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnDontsendlist();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}

#endif 
