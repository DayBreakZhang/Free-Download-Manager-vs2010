/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_UPLOAD_GENERALPAGE_H__4A6191B7_DD9F_4010_93ED_08E1DD4DEA6D__INCLUDED_)
#define AFX_UPLOAD_GENERALPAGE_H__4A6191B7_DD9F_4010_93ED_08E1DD4DEA6D__INCLUDED_

#include "fsUpload.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

class CUpload_GeneralPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CUpload_GeneralPage)

public:
	vmsUploadSmartPtr m_upl;
	CUpload_GeneralPage();
	~CUpload_GeneralPage();

	//{{AFX_DATA(CUpload_GeneralPage)
	enum { IDD = IDD_UPLOAD_GENERAL };
	CComboBox	m_wndCompress;
	CListCtrl	m_wndFiles;
	CComboBox	m_wndDaysToKeep;
	CComboBox	m_wndNumberOfDlds;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CUpload_GeneralPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void ApplyLanguage();
	void UpdateEnabled();
	
	//{{AFX_MSG(CUpload_GeneralPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnSetpwd();
	afx_msg void OnAdvancedinfo();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}

#endif 
