/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "Dlg_Options_Page.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

BEGIN_MESSAGE_MAP(CDlg_Options_Page, CDialog)
	//{{AFX_MSG_MAP(CDlg_Options_StartupPage)
	ON_COMMAND(IDOK, OnOK)
	ON_COMMAND(IDCANCEL, OnCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CDlg_Options_Page::CDlg_Options_Page(UINT u, CWnd* wnd) : 
	CDialog (u, wnd)
{
	m_nReflectLevel = 1;
	m_bElevateRequired = false;
	m_bRestartOfBrowserIsRequired = false;
}

CDlg_Options_Page::~CDlg_Options_Page()
{

}

LPCSTR CDlg_Options_Page::get_Template()
{
	return m_lpszTemplateName;
}

void CDlg_Options_Page::OnCancel()
{
	get_ReflectParent ()->PostMessage (WM_COMMAND, IDCANCEL);
}

void CDlg_Options_Page::OnOK ()
{
	get_ReflectParent ()->PostMessage (WM_COMMAND, IDOK);
}

CWnd* CDlg_Options_Page::get_ReflectParent()
{
	CWnd* wnd = this;
	for (int i = 0; i < m_nReflectLevel; i++)
		wnd = wnd->GetParent ();
	return wnd;
}

bool CDlg_Options_Page::isElevateRequired()
{
	return m_bElevateRequired;
}

void CDlg_Options_Page::setElevateRequired(bool bRequired)
{
	m_bElevateRequired = bRequired;
}
