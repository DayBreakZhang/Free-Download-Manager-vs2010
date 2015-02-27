/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fdm.h"
#include "Dlg_Options_Downloads_TimeLimit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlg_Options_Downloads_TimeLimit::CDlg_Options_Downloads_TimeLimit(CWnd* pParent )
	: CDlg_Options_Page(CDlg_Options_Downloads_TimeLimit::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_Options_Downloads_TimeLimit)
		
	//}}AFX_DATA_INIT
}

void CDlg_Options_Downloads_TimeLimit::DoDataExchange(CDataExchange* pDX)
{
	CDlg_Options_Page::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_Options_Downloads_TimeLimit)
	DDX_Control(pDX, IDC_TO, m_wndTo);
	DDX_Control(pDX, IDC_FROM, m_wndFrom);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlg_Options_Downloads_TimeLimit, CDlg_Options_Page)
	//{{AFX_MSG_MAP(CDlg_Options_Downloads_TimeLimit)
	ON_BN_CLICKED(IDC_SETLIMIT, OnSetlimit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlg_Options_Downloads_TimeLimit::OnInitDialog() 
{
	CDlg_Options_Page::OnInitDialog();

	FillTimes (&m_wndFrom);
	FillTimes (&m_wndTo);
	
	DWORD dw = _DldsMgr.m_dwPDTimeLimit;

	if (dw)
	{
		CheckDlgButton (IDC_SETLIMIT, BST_CHECKED);
		m_wndFrom.SetCurSel (LOWORD (dw));
		m_wndTo.SetCurSel (HIWORD (dw));
	}
	else
	{
		m_wndFrom.SetCurSel (0);
		m_wndTo.SetCurSel (0);
	}

	UpdateEnabled ();
	ApplyLanguage ();
	
	return TRUE;  
	              
}

CString CDlg_Options_Downloads_TimeLimit::get_PageShortTitle()
{
	return LS (L_TIME_LIMIT);
}

CString CDlg_Options_Downloads_TimeLimit::get_PageTitle()
{
	return LS (L_TIME_LIMIT);
}

BOOL CDlg_Options_Downloads_TimeLimit::Apply()
{
	DWORD dw = 0;

	if (IsDlgButtonChecked (IDC_SETLIMIT) == BST_CHECKED)
	{
		int i1 = m_wndFrom.GetCurSel ();
		int i2 = m_wndTo.GetCurSel ();
		if (i1 == i2)
		{
			MessageBox (LS (L_INPERR), LS (L_ERR), MB_ICONEXCLAMATION);
			return FALSE;
		}
		dw = (i2 << 16) + i1;
	}
	
	_App.DldsMgrPDTimeLimit (_DldsMgr.m_dwPDTimeLimit = dw);

	return TRUE;
}

void CDlg_Options_Downloads_TimeLimit::FillTimes(CComboBox *pbox)
{
	char sz [100]; SYSTEMTIME st; ZeroMemory (&st, sizeof (st)); 

	pbox->ResetContent ();

	for (WORD i = 0; i < 24; i++)
	{
		st.wHour = i;
		GetTimeFormat (LOCALE_USER_DEFAULT, TIME_NOSECONDS, &st, NULL, sz, 100);
		if (strlen (sz) <= 2)
			strcat (sz, LS (L_HR));
		pbox->AddString (sz);
	}
}

void CDlg_Options_Downloads_TimeLimit::OnSetlimit() 
{
	UpdateEnabled ();	
}

void CDlg_Options_Downloads_TimeLimit::UpdateEnabled()
{
	BOOL b = IsDlgButtonChecked (IDC_SETLIMIT) == BST_CHECKED;
	GetDlgItem (IDC__S0)->EnableWindow (b);
	GetDlgItem (IDC__S1)->EnableWindow (b);
	m_wndFrom.EnableWindow (b);
	m_wndTo.EnableWindow (b);
}

void CDlg_Options_Downloads_TimeLimit::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_SETLIMIT, L_LIMITSTARTDLDSTIME),
		fsDlgLngInfo (IDC__S0, L_ALLOWSTARTONLYFROM),
		fsDlgLngInfo (IDC__S1, L_TO),
	};
	
	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}
