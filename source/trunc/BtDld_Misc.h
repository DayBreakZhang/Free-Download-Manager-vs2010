/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_BTDLD_MISC_H__CF0C4432_AA8B_4B67_8A4D_3BDD305254CB__INCLUDED_)
#define AFX_BTDLD_MISC_H__CF0C4432_AA8B_4B67_8A4D_3BDD305254CB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CBtDld_Misc : public CPropertyPage
{
	DECLARE_DYNCREATE(CBtDld_Misc)

public:
	DLDS_LIST* m_pvDlds;

	CBtDld_Misc();
	~CBtDld_Misc();

	//{{AFX_DATA(CBtDld_Misc)
	enum { IDD = IDD_BTDLD_MISC };
		
		
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CBtDld_Misc)
	public:
	virtual BOOL OnApply();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	
	
	void FlagToDlg (DWORD dwFlag, UINT nIdCtrl);
	void DlgToFlag (DWORD dwFlag, UINT nIdCtrl);

	void ApplyLanguage();
	
	//{{AFX_MSG(CBtDld_Misc)
	virtual BOOL OnInitDialog();
	afx_msg void OnLaunchwhendone();
	afx_msg void OnGenerateinfofile();
	afx_msg void OnReservespace();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}

#endif 
