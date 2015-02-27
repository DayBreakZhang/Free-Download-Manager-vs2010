/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLG_OPTIONS_DOWNLOADS_NETWORK_H__B5E47FAF_5F5E_4790_9979_7ABF3645B72B__INCLUDED_)
#define AFX_DLG_OPTIONS_DOWNLOADS_NETWORK_H__B5E47FAF_5F5E_4790_9979_7ABF3645B72B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "Dlg_Options_Page.h"
#include "DlgTumSettingsPerDirection.h"
#include "resource.h"

class CDlg_Options_Downloads_Network : public CDlg_Options_Page
{

public:
	BOOL Apply();
	CString get_PageShortTitle();
	CString get_PageTitle();
	CDlg_Options_Downloads_Network(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlg_Options_Downloads_Network)
	enum { IDD = IDD_OPTIONS_DOWNLOADS_NETWORK };
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlg_Options_Downloads_Network)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void InsertValueIntoSortedList (std::vector <UINT64> &vValues, UINT64 uValue);
	CDlgTumSettingsPerDirection m_dlgTumSettingsPerDirection;
	void ApplyLanguage();
	void UpdateEnabled();

	
	//{{AFX_MSG(CDlg_Options_Downloads_Network)
	virtual BOOL OnInitDialog();
	afx_msg void OnDetectactivity();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	void FillConnectionSpeedCombo ();
	UINT64 m_uConnectionSpeedChoosenValue;
public:
	CComboBox m_wndConnectionSpeed;
	std::vector <UINT64> m_vConnectionSpeeds;
	afx_msg void OnSelchangeConnectionspeed();
	afx_msg void OnBnClickedConnectionspeedinfo();
};

//{{AFX_INSERT_LOCATION}}

#endif 
