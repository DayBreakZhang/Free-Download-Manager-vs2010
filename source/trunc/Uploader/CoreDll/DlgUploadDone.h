/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLGUPLOADDONE_H__7037B2F6_05B9_429F_9BDB_206308E3E39D__INCLUDED_)
#define AFX_DLGUPLOADDONE_H__7037B2F6_05B9_429F_9BDB_206308E3E39D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CDlgUploadDone : public CDialog
{

public:
	vmsUploadSmartPtr m_upl;
	CDlgUploadDone(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlgUploadDone)
	enum { IDD = IDD_UPLOAD_DONE };
		
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlgUploadDone)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:

	
	//{{AFX_MSG(CDlgUploadDone)
	virtual BOOL OnInitDialog();
	afx_msg void OnDontshowagain();
	virtual void OnCancel();
	afx_msg void OnCopy();
	afx_msg void OnOpen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
