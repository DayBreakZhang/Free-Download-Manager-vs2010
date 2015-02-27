/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FDMCustomized.h"
#include "FDMCustomizedDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

BEGIN_MESSAGE_MAP(CFDMCustomizedApp, CWinApp)
	//{{AFX_MSG_MAP(CFDMCustomizedApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

CFDMCustomizedApp::CFDMCustomizedApp()
{
}

CFDMCustomizedApp theApp;

BOOL CFDMCustomizedApp::InitInstance()
{
	AfxEnableControlContainer();

	

#ifdef _AFXDLL
	Enable3dControls();			
#else
	Enable3dControlsStatic();	
#endif

	CFDMCustomizedDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
	}
	else if (nResponse == IDCANCEL)
	{
	}

	
	
	return FALSE;
}
