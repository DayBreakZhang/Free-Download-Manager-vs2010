/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLG_CONVERT_H__EF2ECB4B_4C91_4251_B43B_D948CDB7C7E4__INCLUDED_)
#define AFX_DLG_CONVERT_H__EF2ECB4B_4C91_4251_B43B_D948CDB7C7E4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CDlg_Convert : public CDialog
{

public:
	bool m_bCustomizingDefSettings;

	CDlg_Convert(vmsMediaFileConvertSettings *stgs, CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlg_Convert)
	enum { IDD = IDD_CONVERT };
	CComboBox	m_wndVideoSize;
	CComboBox	m_wndQuality;
	CComboBox	m_wndFormat;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlg_Convert)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	vmsMediaFileConvertSettings *m_stgs;
	void ApplyLanguage();

	
	//{{AFX_MSG(CDlg_Convert)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
