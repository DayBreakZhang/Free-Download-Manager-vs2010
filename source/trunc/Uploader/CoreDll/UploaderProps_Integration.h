/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_UPLOADERPROPS_INTEGRATION_H__B34F3D56_36AC_44EF_B603_18B54418DC9A__INCLUDED_)
#define AFX_UPLOADERPROPS_INTEGRATION_H__B34F3D56_36AC_44EF_B603_18B54418DC9A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CUploaderProps_Integration : public CPropertyPage
{
	DECLARE_DYNCREATE(CUploaderProps_Integration)

public:
	CUploaderProps_Integration();
	~CUploaderProps_Integration();

	//{{AFX_DATA(CUploaderProps_Integration)
	enum { IDD = IDD_UPLDR_INTEGRATION };
		
		
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CUploaderProps_Integration)
	public:
	virtual BOOL OnApply();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void ApplyLanguage();
	BOOL m_bOeIntegrRunning;
	void UpdateEnabled();
	
	//{{AFX_MSG(CUploaderProps_Integration)
	afx_msg void OnCm();
	afx_msg void OnStm();
	afx_msg void OnOe();
	afx_msg void OnChangeOeMinsize();
	virtual BOOL OnInitDialog();
	afx_msg void OnOeAskupload();
	afx_msg void OnIe();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}

#endif 
