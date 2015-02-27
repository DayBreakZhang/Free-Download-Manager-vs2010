/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "coredll.h"
#include "Dlg_AskCaptcha.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlg_AskCaptcha::CDlg_AskCaptcha(CWnd* pParent )
	: CDialog(CDlg_AskCaptcha::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_AskCaptcha)
		
	//}}AFX_DATA_INIT
}

void CDlg_AskCaptcha::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_AskCaptcha)
		
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlg_AskCaptcha, CDialog)
	//{{AFX_MSG_MAP(CDlg_AskCaptcha)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlg_AskCaptcha::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CSize sImage = m_img.get_Size ();

	CRect rc;
	GetDlgItem (IDC__IMG)->GetWindowRect (&rc);
	ScreenToClient (&rc);

	int FRAME_WIDTH = rc.left;

	m_rcImage = rc;
	m_rcImage.right = m_rcImage.left + sImage.cx;
	m_rcImage.bottom = m_rcImage.top + sImage.cy;

	rc.left = m_rcImage.right + FRAME_WIDTH;
	rc.right = rc.left + 170;
	rc.bottom += FRAME_WIDTH - 2;
	GetDlgItem (IDC__MSG)->MoveWindow (&rc);
	rc.bottom -= FRAME_WIDTH - 2;

	CRect rc2;
	GetDlgItem (IDC_VALUE)->GetWindowRect (&rc2);

	rc.left = FRAME_WIDTH;
	rc.top = rc.bottom + FRAME_WIDTH;
	rc.bottom = rc.top + rc2.Height ();
	GetDlgItem (IDC_VALUE)->MoveWindow (&rc);

	GetDlgItem (IDOK)->GetWindowRect (&rc2);
	rc.left = rc.right - rc2.Width ();
	rc.top = rc.bottom + FRAME_WIDTH;
	rc.bottom = rc.top + rc2.Height ();
	GetDlgItem (IDOK)->MoveWindow (&rc);

	GetClientRect (&rc2);
	int cxAdd = rc.right + 2*FRAME_WIDTH - rc2.Width ();
	int cyAdd = rc.bottom + 2*FRAME_WIDTH - rc2.Height ();

	GetWindowRect (&rc2);

	SetWindowPos (NULL, 0, 0, rc2.Width () + cxAdd, rc2.Height () + cyAdd,
		SWP_NOZORDER | SWP_NOMOVE);

	ApplyLanguage ();
	
	return TRUE;  
	              
}

void CDlg_AskCaptcha::OnPaint() 
{
	CDialog::OnPaint();

	CDC* dc = GetDC ();
	m_img.Draw (*dc, m_rcImage);
	ReleaseDC (dc);
}

void CDlg_AskCaptcha::OnOK() 
{
	GetDlgItemText (IDC_VALUE, m_strValue);	
	CDialog::OnOK();
}

BOOL CDlg_AskCaptcha::DestroyWindow() 
{
	m_img.Free ();	
	return CDialog::DestroyWindow();
}

void CDlg_AskCaptcha::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__MSG, L_UPLOAD_REQ_ACTIVATION_MSG),
	};

	vmsMfcLngHelper::ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_UPLOAD_ACTIVATION);
}

void CDlg_AskCaptcha::OnCancel() 
{

}
