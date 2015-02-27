/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_OPTSPROXYPAGE_H__52021EB8_498D_4587_9FBA_320F205EB035__INCLUDED_)
#define AFX_OPTSPROXYPAGE_H__52021EB8_498D_4587_9FBA_320F205EB035__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class COptsProxyPage : public CPropertyPage
{
	DECLARE_DYNCREATE(COptsProxyPage)

public:
	COptsProxyPage();
	~COptsProxyPage();

	//{{AFX_DATA(COptsProxyPage)
	enum { IDD = IDD_OPTS_PROXY };
		
		
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(COptsProxyPage)
	public:
	virtual BOOL OnApply();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	BOOL CrackProxyName(LPCSTR pszName, CString &strName, USHORT &uPort);
	void UpdateEnabled();
	void ApplyLanguage();
	
	//{{AFX_MSG(COptsProxyPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnAuthorization();
	afx_msg void OnGetfromie();
	afx_msg void OnManually();
	afx_msg void OnDontuseproxy();
	afx_msg void OnChangeProxyname();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}

#endif 
