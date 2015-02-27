/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Dlg_TUMChanged.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlg_TUMChanged::CDlg_TUMChanged(CWnd* pParent )
	: CDialog(CDlg_TUMChanged::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_TUMChanged)
		
	//}}AFX_DATA_INIT
}

void CDlg_TUMChanged::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_TUMChanged)
	DDX_Control(pDX, IDC_I_MEDIUM, m_wndIMedium);
	DDX_Control(pDX, IDC_I_LIGHT, m_wndILight);
	DDX_Control(pDX, IDC_I_HEAVY, m_wndIHeavy);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlg_TUMChanged, CDialog)
	//{{AFX_MSG_MAP(CDlg_TUMChanged)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlg_TUMChanged::OnInitDialog() 
{
	CDialog::OnInitDialog();

	m_wndILight.SetIcon (_TBMgr.get_Images ()->ExtractIcon (0));
	m_wndIMedium.SetIcon (_TBMgr.get_Images ()->ExtractIcon (1));
	m_wndIHeavy.SetIcon (_TBMgr.get_Images ()->ExtractIcon (2));

	LOGFONT lf;
	GetFont ()->GetLogFont (&lf);
	lf.lfWeight = FW_BOLD;
	m_fntBold.CreateFontIndirect (&lf);

	ApplyLanguage ();

	return TRUE;
}

void CDlg_TUMChanged::OnOK() 
{	
	if (IsDlgButtonChecked (IDC_DONTSHOW) == BST_CHECKED)
		_App.View_TUMChanged (FALSE);

	CDialog::OnOK();
}

HBRUSH CDlg_TUMChanged::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	if (pWnd->m_hWnd == GetDlgItem (IDC__HEAVY)->m_hWnd ||
			pWnd->m_hWnd == GetDlgItem (IDC__MEDIUM)->m_hWnd ||
			pWnd->m_hWnd == GetDlgItem (IDC__LIGHT)->m_hWnd)
		SelectObject (pDC->m_hDC, m_fntBold);
	
	return hbr;
}

void CDlg_TUMChanged::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__HEAVY, L_HEAVY),
		fsDlgLngInfo (IDC__MEDIUM, L_MEDIUM),
		fsDlgLngInfo (IDC__LIGHT, L_LIGHT),
		fsDlgLngInfo (IDC_HEAVY_DESC, L_TUM_HEAVY_DESC),
		fsDlgLngInfo (IDC__MEDIUM_DESC, L_TUM_MEDIUM_DESC),
		fsDlgLngInfo (IDC__LIGHT_DESC, L_TUM_LIGHT_DESC),
		fsDlgLngInfo (IDC_DONTSHOW, L_DONTSHOWTHISWINDOWAGAIN),
	};

	CString str = LS (L_TUMCHANGED_TOP); str.Replace ("\\n", "\n");
	SetDlgItemText (IDC__TOPMSG, str);

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_TUMCHANGED);
}
