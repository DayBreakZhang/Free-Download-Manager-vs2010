/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLG_CHECKFILEINTEGRITY_PROGRESS_H__10B11303_6ECA_4D9D_A330_46B984307127__INCLUDED_)
#define AFX_DLG_CHECKFILEINTEGRITY_PROGRESS_H__10B11303_6ECA_4D9D_A330_46B984307127__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "Hash\vmsHash.h"

class CDlg_CheckFileIntegrity_Progress : public CDialog,
	public vmsHashEvents
{

public:
	
	CString m_strHashResult;
	
	bool is_CheckingSucceeded();
	
	CString m_strValidHashResult;
	
	CString m_strFile;
	
	vmsHashAlgorithm m_enHashAlgorithm;
	vmsHash_SHA2Strength m_enSHA2Strength;
	CDlg_CheckFileIntegrity_Progress(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlg_CheckFileIntegrity_Progress)
	enum { IDD = IDD_CHECKFILEINTEGRITY_PROGRESS };
	CProgressCtrl	m_wndProgress;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlg_CheckFileIntegrity_Progress)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	
	bool m_bSucceeded;
	
	CString get_ValidHashResult();
	
	static DWORD WINAPI _threadDoJob (LPVOID lp);
	
	virtual bool OnProgressChanged (double fPercentage);
	
	bool m_bNeedStop;
	void ApplyLanguage();

	
	//{{AFX_MSG(CDlg_CheckFileIntegrity_Progress)
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
