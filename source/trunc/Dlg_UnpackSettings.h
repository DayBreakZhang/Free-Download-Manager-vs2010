/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLG_UNPACKSETTINGS_H__02F59847_7CD4_4BA9_9CD5_5D9F1BAA5D9F__INCLUDED_)
#define AFX_DLG_UNPACKSETTINGS_H__02F59847_7CD4_4BA9_9CD5_5D9F1BAA5D9F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CDlg_UnpackSettings : public CDialog
{

public:
	CString m_strDstFolder;
	CDlg_UnpackSettings(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlg_UnpackSettings)
	enum { IDD = IDD_UNPACK_SETTINGS };
	CButton	m_btnBrowse;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlg_UnpackSettings)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void ApplyLanguage();

	
	//{{AFX_MSG(CDlg_UnpackSettings)
	virtual BOOL OnInitDialog();
	afx_msg void OnBrowse();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
