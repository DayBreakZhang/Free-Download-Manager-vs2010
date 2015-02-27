/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLG_CHECKFILEINTEGRITY_RESULT_H__EBCE6699_8717_4898_B563_C1929B768777__INCLUDED_)
#define AFX_DLG_CHECKFILEINTEGRITY_RESULT_H__EBCE6699_8717_4898_B563_C1929B768777__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CDlg_CheckFileIntegrity_Result : public CDialog
{

public:
	
	bool m_bResultOK;
	
	CString m_strFileName;
	
	CString m_strUrl;
	
	CString m_strValidHash;
	
	CString m_strResultHash;
	CDlg_CheckFileIntegrity_Result(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlg_CheckFileIntegrity_Result)
	enum { IDD = IDD_CHECKFILEINTEGRITY_RESULT };
	CStatic	m_wndIcon;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlg_CheckFileIntegrity_Result)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void ApplyLanguage();

	
	//{{AFX_MSG(CDlg_CheckFileIntegrity_Result)
	virtual BOOL OnInitDialog();
	afx_msg void OnRestartdownload();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
