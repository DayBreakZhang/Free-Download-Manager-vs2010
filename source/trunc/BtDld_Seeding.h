/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_BTDLD_SEEDING_H__CD98DAFB_5AB4_46C0_B3DF_41003245D221__INCLUDED_)
#define AFX_BTDLD_SEEDING_H__CD98DAFB_5AB4_46C0_B3DF_41003245D221__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CBtDld_Seeding : public CPropertyPage
{
	DECLARE_DYNCREATE(CBtDld_Seeding)

public:
	DLDS_LIST* m_pvDlds;
	
	CBtDld_Seeding();
	~CBtDld_Seeding();

	//{{AFX_DATA(CBtDld_Seeding)
	enum { IDD = IDD_BTDLD_SEEDING };
	CComboBox	m_wndRatio;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CBtDld_Seeding)
	public:
	virtual BOOL OnApply();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void UpdateEnabled();
	void ApplyLanguage();
	
	//{{AFX_MSG(CBtDld_Seeding)
	virtual BOOL OnInitDialog();
	afx_msg void OnEnableSeeding();
	afx_msg void OnUnlimitedSeeding();
	afx_msg void OnLimitByRatio();
	afx_msg void OnSelchangeRatioList();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}

#endif 
