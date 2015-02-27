/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLG_UNPACKPROGRESS_H__73FC2783_CE33_4E19_B98A_3D826DD2A65C__INCLUDED_)
#define AFX_DLG_UNPACKPROGRESS_H__73FC2783_CE33_4E19_B98A_3D826DD2A65C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsArchiveCallback.h"

class CDlg_UnpackProgress : public CDialog,
	public vmsArchiveCallback 
{

public:
	
	CString m_strArchive, m_strDstFolder;

	CDlg_UnpackProgress(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlg_UnpackProgress)
	enum { IDD = IDD_UNPACK_PROGRESS };
	CProgressCtrl	m_wndProgress;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlg_UnpackProgress)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	
	virtual void AskOverwrite (vmsOverwriteFileInfo& ofi, vmsAC_OverwriteMode& enOM, bool& bForAll);
	void ApplyLanguage();
	bool m_bDone; 
	bool m_bNeedStop; 
	static DWORD WINAPI _threadExtract (LPVOID lp);
	
	virtual bool SetProgress (int nProgress);
	
	virtual bool AfterExtract (LPCSTR pszFile, vmsAC_ExtractResult res);
	
	virtual bool BeforeExtract (LPCSTR pszFile);

	
	//{{AFX_MSG(CDlg_UnpackProgress)
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	afx_msg void OnOpenfolder();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
