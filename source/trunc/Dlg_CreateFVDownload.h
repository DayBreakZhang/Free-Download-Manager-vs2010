/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLG_CREATEFVDOWNLOAD_H__F59E3765_0708_4379_A4B8_5B2499EE03CC__INCLUDED_)
#define AFX_DLG_CREATEFVDOWNLOAD_H__F59E3765_0708_4379_A4B8_5B2499EE03CC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CDlg_CreateFVDownload : public CDialog
{

public:
	BOOL m_bSetupAdvStgs;
	BOOL m_bAutoConvert;
	vmsMediaFileConvertSettings m_stgsAutoConvert;
	CString m_strUrl;
	CDlg_CreateFVDownload(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlg_CreateFVDownload)
	enum { IDD = IDD_CREATEFVDOWNLOAD };
	CComboBox	m_wndSSites;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlg_CreateFVDownload)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void UpdateEnabled();
	void ApplyLanguage();
	CRect m_rcOldSize;

	
	//{{AFX_MSG(CDlg_CreateFVDownload)
	virtual BOOL OnInitDialog();
	afx_msg void OnViewSSites();
	virtual void OnOK();
	afx_msg void OnUseAutoConvert();
	afx_msg void OnSettings();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
