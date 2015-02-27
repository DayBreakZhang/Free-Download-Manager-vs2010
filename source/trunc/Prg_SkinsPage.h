/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_PRG_SKINSPAGE_H__33701C5E_A134_4875_9D30_1F869A332F18__INCLUDED_)
#define AFX_PRG_SKINSPAGE_H__33701C5E_A134_4875_9D30_1F869A332F18__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CPrg_SkinsPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CPrg_SkinsPage)

public:
	CPrg_SkinsPage();
	~CPrg_SkinsPage();

	//{{AFX_DATA(CPrg_SkinsPage)
	enum { IDD = IDD_PRG_SKINS };
	CComboBox	m_wndSkins;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CPrg_SkinsPage)
	public:
	virtual BOOL OnApply();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void ApplyLanguage();
	
	//{{AFX_MSG(CPrg_SkinsPage)
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}

#endif 
