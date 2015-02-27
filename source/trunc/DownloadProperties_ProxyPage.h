/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DOWNLOADPROPERTIES_PROXYPAGE_H__2D6926B0_70AF_4201_807B_D2AECC4980B8__INCLUDED_)
#define AFX_DOWNLOADPROPERTIES_PROXYPAGE_H__2D6926B0_70AF_4201_807B_D2AECC4980B8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "list.h"

class CDownloadProperties_ProxyPage : public CPropertyPage
{
	friend class CDownloadPropertiesSheet;

	DECLARE_DYNCREATE(CDownloadProperties_ProxyPage)

public:
	CDownloadProperties_ProxyPage();
	~CDownloadProperties_ProxyPage();

	//{{AFX_DATA(CDownloadProperties_ProxyPage)
	enum { IDD = IDD_DOWNLOAD_PROXY };
	CComboBox	m_wndProtocols;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDownloadProperties_ProxyPage)
	public:
	virtual BOOL OnApply();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void PrepareCHMgr(CPoint point);
	void ApplyLanguage();
	
	struct ProxyInfo
	{
		CString strName;	
		UINT uAuthorization;	
		CString strUser;		
		CString strPassword;	
		BOOL bNameModified;		
		BOOL bUserModified;		
		BOOL bPasswordModified;	

		ProxyInfo () { bNameModified = bUserModified = bPasswordModified = FALSE; }
	};

	
	void ApplyPS (DLDS_LIST *pvDlds, ProxyInfo* pi);
	
	BOOL ReadPS();
	BOOL m_bIChange;	
	void UpdatePS();
	int m_iCurProtocol;	

	
	
	BOOL CrackProxyName (LPCSTR pszName, CString& strName, USHORT &uPort);

	fs::list <ProxyInfo> m_vProxies;	

	void UpdateEnabled();
	
	DLDS_LIST *m_pvDlds;
	
	DLDS_LIST m_vHttp, m_vHttps, m_vFtp;
	
	//{{AFX_MSG(CDownloadProperties_ProxyPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnGetfromie();
	afx_msg void OnManually();
	afx_msg void OnUsesocks();
	afx_msg void OnDontuseproxy();
	afx_msg void OnChangeProxyname();
	afx_msg void OnChangePort();
	afx_msg void OnAuthorization();
	afx_msg void OnChangeUser();
	afx_msg void OnChangePassword();
	afx_msg void OnSelchangeProtocols();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnWhatisthis();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnUserollback();
	afx_msg void OnChangeRollbacksize();
	afx_msg void OnFromfirefox();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}

#endif 
