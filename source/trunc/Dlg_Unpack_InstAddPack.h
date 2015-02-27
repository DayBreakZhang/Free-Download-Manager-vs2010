/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLG_UNPACK_INSTADDPACK_H__C56EAEEE_7B76_4239_928A_28B0D45AE5A7__INCLUDED_)
#define AFX_DLG_UNPACK_INSTADDPACK_H__C56EAEEE_7B76_4239_928A_28B0D45AE5A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CDlg_Unpack_InstAddPack : public CDialog
{

public:
	CDlg_Unpack_InstAddPack(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlg_Unpack_InstAddPack)
	enum { IDD = IDD_UNPACK_INSTADDPACK };
		
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlg_Unpack_InstAddPack)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void ApplyLanguage();

	
	//{{AFX_MSG(CDlg_Unpack_InstAddPack)
	virtual BOOL OnInitDialog();
	afx_msg void OnVisitwebsite();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
