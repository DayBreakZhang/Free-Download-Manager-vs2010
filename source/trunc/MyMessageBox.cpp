/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "MyMessageBox.h"
#include "mfchelp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CMyMessageBox::CMyMessageBox(CWnd* pParent )
	: CDialog(CMyMessageBox::IDD, pParent)
{
	m_hIcon  = NULL;
	m_bChecked = false;
	m_bTopMost = false;
}

void CMyMessageBox::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyMessageBox)
	DDX_Control(pDX, IDC_CHECK1, m_wndCheckbox);
	DDX_Control(pDX, IDC_BTN3, m_wndBtn3);
	DDX_Control(pDX, IDC_BTN2, m_wndBtn2);
	DDX_Control(pDX, IDC_BTN1, m_wndBtn1);
	DDX_Control(pDX, IDC__MSG, m_wndMsg);
	DDX_Control(pDX, IDC__ICON, m_wndIcon);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyMessageBox, CDialog)
	//{{AFX_MSG_MAP(CMyMessageBox)
	ON_BN_CLICKED(IDC_BTN1, OnBtn1)
	ON_BN_CLICKED(IDC_BTN2, OnBtn2)
	ON_BN_CLICKED(IDC_BTN3, OnBtn3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CMyMessageBox::OnInitDialog() 
{
	CDialog::OnInitDialog();

	const int DX = 10;
	const int DY = 10;
	const int BTN_DX = 3;
	
	ASSERT (m_strBtn1Text != "");
	ASSERT (m_strText != "");

	if (m_hIcon)
		m_wndIcon.SetIcon (m_hIcon);

	CRect rcIcon;
	m_wndIcon.GetWindowRect (&rcIcon);
	ScreenToClient (&rcIcon);

	CRect rcCheckbox;
	m_wndCheckbox.GetWindowRect (&rcCheckbox);
	ScreenToClient (&rcCheckbox);

	CDC* dc = GetDC ();

	dc->SelectObject (GetFont ());

	CRect rcBtn, rcBtn1, rcBtn2 (0,0,0,0), rcBtn3 (0,0,0,0);
	m_wndBtn1.GetWindowRect (&rcBtn);
	ScreenToClient (&rcBtn);
	dc->DrawText (m_strBtn1Text, &rcBtn1, DT_CALCRECT);
	if (m_strBtn2Text != "")
	{
		dc->DrawText (m_strBtn2Text, &rcBtn2, DT_CALCRECT);
		if (m_strBtn3Text != "")
			dc->DrawText (m_strBtn3Text, &rcBtn3, DT_CALCRECT);
	}
	int w = max (rcBtn1.Width (), rcBtn2.Width ());
	w = max (w, rcBtn3.Width ());
	w += 10;
	if (w < 70)
		w = 70;
	rcBtn.right = rcBtn.left + w;
	

	CRect rcText (0,0,0,0);
	dc->DrawText (m_strText, &rcText, DT_CALCRECT);

	
	CRect rcCBText (0,0,0,0);
	dc->DrawText (m_strCheckBoxText, &rcCBText, DT_CALCRECT);
	rcCBText.right += 25;
	if (rcCBText.Width () > rcText.Width ())
		rcText.right = rcText.top + rcCBText.Width ();

	ReleaseDC (dc);

	CRect rcDlg;
	GetWindowRect (&rcDlg);
	
	CRect rcMsg;
	m_wndMsg.GetWindowRect (&rcMsg);
	ScreenToClient (&rcMsg);

	if (m_strCheckBoxText == "")
		rcDlg.bottom -= rcCheckbox.Height () + DX;

	if (m_hIcon == NULL)
		rcDlg.right -= rcIcon.Width () + DX;

	int dx = rcDlg.Width () - rcMsg.Width ();
	int dy = rcDlg.Height () - rcMsg.Height ();

	int DLG_WIDTH = rcText.Width () + dx;
	
	int FRAME_WIDTH = rcIcon.left;
	
	int LEFT = m_hIcon ? rcIcon.right + DX : FRAME_WIDTH;

	
	int BTNSW = rcBtn.Width () + LEFT + FRAME_WIDTH;
	if (m_strBtn3Text != "")
		BTNSW += (rcBtn.Width () + BTN_DX) * 2;
	else if (m_strBtn2Text != "")
		BTNSW += rcBtn.Width () + BTN_DX;

	
	if (DLG_WIDTH < BTNSW)
		DLG_WIDTH = BTNSW;

	SetWindowPos (NULL, 0, 0, DLG_WIDTH, rcText.Height () + dy, SWP_NOMOVE | SWP_NOZORDER);

	m_wndMsg.MoveWindow (LEFT, rcMsg.top, rcText.Width (), rcText.Height ());
	m_wndMsg.SetWindowText (m_strText);

	SetWindowText (m_strTitle);

	int h = rcCheckbox.Height ();
	rcCheckbox.top = rcMsg.top + rcText.Height () + DY;
	rcCheckbox.bottom = rcCheckbox.top + h;

	if (m_strCheckBoxText != "")
	{
		m_wndCheckbox.SetWindowText (m_strCheckBoxText);
		m_wndCheckbox.MoveWindow (LEFT, rcCheckbox.top, rcText.Width (), rcCheckbox.Height ());
		CheckDlgButton (IDC_CHECK1, m_bChecked ? BST_CHECKED : BST_UNCHECKED);
	}
	else
		m_wndCheckbox.ShowWindow (SW_HIDE);

	if (m_strCheckBoxText != "")
	{
		int h = rcBtn.Height ();
		rcBtn.top = rcCheckbox.bottom + DY;
		rcBtn.bottom = rcBtn.top + h;
	}
	else
	{
		int h = rcBtn.Height ();
		rcBtn.top = rcCheckbox.top;
		rcBtn.bottom = rcBtn.top + h;
	}

	CRect rc; GetClientRect (&rc);
	int BTN_X = (rc.Width () + (BTNSW - LEFT)) / 2 - rcBtn.Width ();

	if (m_strBtn3Text != "")
	{
		m_wndBtn3.SetWindowText (m_strBtn3Text);
		m_wndBtn3.MoveWindow (BTN_X, rcBtn.top, rcBtn.Width (), rcBtn.Height ());
		BTN_X -= rcBtn.Width () + BTN_DX;
	}
	else
		m_wndBtn3.ShowWindow (SW_HIDE);

	if (m_strBtn2Text != "")
	{
		m_wndBtn2.SetWindowText (m_strBtn2Text);
		m_wndBtn2.MoveWindow (BTN_X, rcBtn.top, rcBtn.Width (), rcBtn.Height ());
		BTN_X -= rcBtn.Width () + BTN_DX;
	}
	else
		m_wndBtn2.ShowWindow (SW_HIDE);

	m_wndBtn1.SetWindowText (m_strBtn1Text);
	m_wndBtn1.MoveWindow (BTN_X, rcBtn.top, rcBtn.Width (), rcBtn.Height ());
	
	if (m_strBtn2Text != "")
		m_wndBtn2.SetWindowText (m_strBtn2Text);
	else
		m_wndBtn2.ShowWindow (SW_HIDE);

	if (m_hIcon == NULL)
		m_wndIcon.ShowWindow (SW_HIDE);

	if (m_bTopMost)
	{
		fsSetForegroundWindow (m_hWnd);
        mfcSetTopmostWindow (this);
	}
	
	return TRUE;
}

void CMyMessageBox::OnBtn1() 
{
	m_bChecked = IsDlgButtonChecked (IDC_CHECK1) == BST_CHECKED;
	EndDialog (IDC_BTN1);	
}

void CMyMessageBox::OnBtn2() 
{
	m_bChecked = IsDlgButtonChecked (IDC_CHECK1) == BST_CHECKED;
	EndDialog (IDC_BTN2);	
}

void CMyMessageBox::OnBtn3() 
{
	m_bChecked = IsDlgButtonChecked (IDC_CHECK1) == BST_CHECKED;
	EndDialog (IDC_BTN3);	
}

void CMyMessageBox::OnCancel() 
{
	if (m_strBtn2Text == "")
		OnBtn1 ();
	
	
}
