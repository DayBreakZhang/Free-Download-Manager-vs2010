/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "DlgT1ToT2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlgT1ToT2::CDlgT1ToT2(CWnd* pParent )
	: CDialog(CDlgT1ToT2::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgT1ToT2)
		
	//}}AFX_DATA_INIT
}

void CDlgT1ToT2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgT1ToT2)
	DDX_Control(pDX, IDC_TO, m_wndTo);
	DDX_Control(pDX, IDC_FROM, m_wndFrom);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgT1ToT2, CDialog)
	//{{AFX_MSG_MAP(CDlgT1ToT2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlgT1ToT2::OnInitDialog() 
{
	CDialog::OnInitDialog();

	if (m_t1.dwHighDateTime && m_t2.dwHighDateTime)
	{
		SYSTEMTIME t1, t2;

		FileTimeToSystemTime (&m_t1, &t1);
		FileTimeToSystemTime (&m_t2, &t2);

		m_wndFrom.SetTime (&t1);
		m_wndTo.SetTime (&t2);
	}

	ApplyLanguage ();
	
	return TRUE;  
	              
}

void CDlgT1ToT2::OnOK() 
{
	SYSTEMTIME t1, t2;

	m_wndFrom.GetTime (&t1);
	m_wndTo.GetTime (&t2);

	t1.wHour = t1.wMinute = t1.wSecond = t1.wMilliseconds = 0;

	t2.wHour = 23;
	t2.wMinute = 59;
	t2.wSecond = 59;
	t2.wMilliseconds = 0;

	SystemTimeToFileTime (&t1, &m_t1);
	SystemTimeToFileTime (&t2, &m_t2);
	
	CDialog::OnOK();
}

void CDlgT1ToT2::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__FROM, L_DLGFROM),
		fsDlgLngInfo (IDC__TO, L_DLGTO),
		fsDlgLngInfo (IDCANCEL, L_CANCEL),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_CHOOSETIMERANGE);
}
