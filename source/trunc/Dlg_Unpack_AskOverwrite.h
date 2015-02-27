/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLG_UNPACK_ASKOVERWRITE_H__8CBD27E8_A44F_4B99_BEE8_897C224AFDB5__INCLUDED_)
#define AFX_DLG_UNPACK_ASKOVERWRITE_H__8CBD27E8_A44F_4B99_BEE8_897C224AFDB5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsArchiveCallback.h"

class CDlg_Unpack_AskOverwrite : public CDialog
{

public:
	vmsAC_OverwriteMode m_enOM;
	
	bool m_bForAll;

	
	CString m_strFile;
	
	UINT64* m_puNewSize;
	
	FILETIME* m_ptimeNewLastModified;

	CDlg_Unpack_AskOverwrite(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlg_Unpack_AskOverwrite)
	enum { IDD = IDD_UNPACK_ASKOVERWRITE };
		
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlg_Unpack_AskOverwrite)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void ApplyLanguage();
	
	CString GetFileInfoString (FILETIME* time, UINT64* size);

	
	//{{AFX_MSG(CDlg_Unpack_AskOverwrite)
	afx_msg void OnYes();
	afx_msg void OnYesforall();
	afx_msg void OnNo();
	afx_msg void OnNoforall();
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
