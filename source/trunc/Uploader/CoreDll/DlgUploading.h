/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLGUPLOADING_H__209DF3E6_EF86_4FB7_8443_4099233A6BA2__INCLUDED_)
#define AFX_DLGUPLOADING_H__209DF3E6_EF86_4FB7_8443_4099233A6BA2__INCLUDED_

#include "fsUpload.h"	
#include "resource.h"
#if _MSC_VER > 1000
#pragma once
#endif 

class CDlgUploading : public CDialog
{

public:
	void Release();
	static CDlgUploading* CreateInstance (vmsUploadSmartPtr upl, CWnd *pwndParent = NULL);
	CDlgUploading(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlgUploading)
	enum { IDD = IDD_UPLOADING };
	CProgressCtrl	m_wndProgress;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlgUploading)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void ApplyLanguage();
	void UpdateStat(BOOL bForceUpdate = FALSE);
	bool m_bDontReleaseIfStopped;
	vmsUploadSmartPtr m_upl;

	
	//{{AFX_MSG(CDlgUploading)
	virtual void OnCancel();
	afx_msg void OnAbort();
	afx_msg void OnPause();
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnCopy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
