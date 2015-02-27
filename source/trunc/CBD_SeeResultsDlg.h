/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_CBD_SEERESULTSDLG_H__B7D0A137_54C2_4E97_9612_D80668269D1C__INCLUDED_)
#define AFX_CBD_SEERESULTSDLG_H__B7D0A137_54C2_4E97_9612_D80668269D1C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CCBD_SeeResultsDlg : public CDialog
{

public:
	class vmsBatchList* m_bl;
	CCBD_SeeResultsDlg(CWnd* pParent = NULL);   

	//{{AFX_DATA(CCBD_SeeResultsDlg)
	enum { IDD = IDD_CBD_RESULTS };
	CListCtrl	m_wndList;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CCBD_SeeResultsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:

	
	//{{AFX_MSG(CCBD_SeeResultsDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
