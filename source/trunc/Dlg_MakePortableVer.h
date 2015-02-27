/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLG_MAKEPORTABLEVER_H__348C0367_D3F0_40C6_9559_B70EA600AF7E__INCLUDED_)
#define AFX_DLG_MAKEPORTABLEVER_H__348C0367_D3F0_40C6_9559_B70EA600AF7E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CDlg_MakePortableVer : public CDialog
{

public:
	CDlg_MakePortableVer(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlg_MakePortableVer)
	enum { IDD = IDD_MAKE_PORTABLE_VER };
	CProgressCtrl	m_wndProgress;
	CButton	m_btnChooseFolder;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlg_MakePortableVer)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	bool m_bNeedStop;
	bool m_bThreadRunning;
	void CopyDirTree(CString SrcPath, CString DstPath, int& nCurIndex, int nTotalCount);
	static DWORD WINAPI _threadCreatePortableVer (LPVOID lp);
	void ApplyLanguage();

	
	//{{AFX_MSG(CDlg_MakePortableVer)
	afx_msg void OnChoosefolder();
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
