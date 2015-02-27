/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLG_SPREADHELP2_H__D067C8D5_5415_47E8_8CEB_058365533C29__INCLUDED_)
#define AFX_DLG_SPREADHELP2_H__D067C8D5_5415_47E8_8CEB_058365533C29__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

//{{AFX_INCLUDES()
#include "webbrowser2.h"
#include "Dlg_SpreadHelp2_wb_Events.h"	
#include "Dlg_SpreadHelp2_wb_UIHandler.h"	
//}}AFX_INCLUDES

class CDlg_SpreadHelp2 : public CDialog
{

public:
	~CDlg_SpreadHelp2();
	CDlg_SpreadHelp2(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlg_SpreadHelp2)
	enum { IDD = IDD_SPREADHELP2 };
	CWebBrowser2	m_wb;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlg_SpreadHelp2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void ApplyLanguage();
	CString m_strFile;
	CDlg_SpreadHelp2_wb_UIHandler m_wbuih;
	CDlg_SpreadHelp2_wb_Events m_wbe;

	
	//{{AFX_MSG(CDlg_SpreadHelp2)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
