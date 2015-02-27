/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLG_CHECKFILEINTEGRITY_H__84C8B3F7_51D2_40B7_829A_DBEDAC35D780__INCLUDED_)
#define AFX_DLG_CHECKFILEINTEGRITY_H__84C8B3F7_51D2_40B7_829A_DBEDAC35D780__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CDlg_CheckFileIntegrity : public CDialog
{

public:
	int m_nAlgorithm;		
	int m_nSHA2Strength;	
	CString m_strChecksum;	
	CDlg_CheckFileIntegrity(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlg_CheckFileIntegrity)
	enum { IDD = IDD_CHECKFILEINTEGRITY };
	CComboBox	m_wndAlgorithm;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlg_CheckFileIntegrity)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	
	
	void PasteChecksum (bool bCheckValid);
	void ApplyLanguage();

	
	//{{AFX_MSG(CDlg_CheckFileIntegrity)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnPastefromclipboard();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
