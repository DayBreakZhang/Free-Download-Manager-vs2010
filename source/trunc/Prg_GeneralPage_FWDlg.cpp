/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Prg_GeneralPage_FWDlg.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CPrg_GeneralPage_FWDlg::CPrg_GeneralPage_FWDlg(CWnd* pParent )
	: CDialog(CPrg_GeneralPage_FWDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPrg_GeneralPage_FWDlg)
		
	//}}AFX_DATA_INIT
}

void CPrg_GeneralPage_FWDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPrg_GeneralPage_FWDlg)
	DDX_Control(pDX, IDC_TRANCPARENCY2, m_wndBlend2);
	DDX_Control(pDX, IDC_TRANCPARENCY1, m_wndBlend1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPrg_GeneralPage_FWDlg, CDialog)
	//{{AFX_MSG_MAP(CPrg_GeneralPage_FWDlg)
	ON_BN_CLICKED(IDC_DROPBOX, OnDropbox)
	ON_BN_CLICKED(IDC_DLINFO, OnDlinfo)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_TRANCPARENCY1, OnCustomdrawTrancparency1)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_TRANCPARENCY2, OnCustomdrawTrancparency2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CPrg_GeneralPage_FWDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	m_wndBlend1.SetRange (0, 255);
	m_wndBlend2.SetRange (0, 255);

	m_blend1 = m_DropBoxTrancparency;
	m_blend2 = m_InfoWndTrancparency;

	m_wndBlend1.SetPos (255 - m_DropBoxTrancparency);
	m_wndBlend2.SetPos (255 - m_InfoWndTrancparency);
	UpdateBlendsVals ();
	
	CheckDlgButton (IDC_DROPBOX, m_bDropBox ? BST_CHECKED : BST_UNCHECKED);
	CheckDlgButton (IDC_DLINFO, m_bInfoWnd ? BST_CHECKED : BST_UNCHECKED);

	CheckDlgButton (IDC_HIDEFWWFS, m_bHideInFs ? BST_CHECKED : BST_UNCHECKED);

	ApplyLanguage ();
	UpdateEnabled ();
	
	return TRUE;  
	              
}

void CPrg_GeneralPage_FWDlg::OnOK() 
{
	m_bHideInFs = IsDlgButtonChecked (IDC_HIDEFWWFS) == BST_CHECKED;

	m_bDropBox = IsDlgButtonChecked (IDC_DROPBOX) == BST_CHECKED;
	m_bInfoWnd = IsDlgButtonChecked (IDC_DLINFO) == BST_CHECKED;

	if (m_bDropBox)
		m_DropBoxTrancparency = (BYTE) (255 - m_wndBlend1.GetPos ());
	if (m_bInfoWnd)
		m_InfoWndTrancparency = (BYTE) (255 - m_wndBlend2.GetPos ());

	CDialog::OnOK();
}

void CPrg_GeneralPage_FWDlg::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_HIDEFWWFS, L_FLTWNDSHIDEINFSMODE),
		fsDlgLngInfo (IDC_DROPBOX, L_DROPBOX),
		fsDlgLngInfo (IDC_DLINFO, L_SHOWDLDSINFOWHILEDOWNLOADING),
		fsDlgLngInfo (IDC__TRANCPARENCY1, L_TRANCPARENCY, TRUE),
		fsDlgLngInfo (IDC__TRANCPARENCY2, L_TRANCPARENCY, TRUE),
		fsDlgLngInfo (IDCANCEL, L_CANCEL),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_ADJUST_FW);
}

void CPrg_GeneralPage_FWDlg::UpdateEnabled()
{
	BOOL b = IsDlgButtonChecked (IDC_DROPBOX) == BST_CHECKED;
	if (b)
		b = fsSysGetOsMajorVersion () >= 5;
	GetDlgItem (IDC__TRANCPARENCY1)->EnableWindow (b);
	GetDlgItem (IDC_TRANCPARENCY1)->EnableWindow (b);
	GetDlgItem (IDC__TRANCPARENCY1_VAL)->EnableWindow (b);

	BOOL b1 = IsDlgButtonChecked (IDC_DLINFO) == BST_CHECKED;
	if (b1)
		b1 = fsSysGetOsMajorVersion () >= 5;
	GetDlgItem (IDC__TRANCPARENCY2)->EnableWindow (b1);
	GetDlgItem (IDC_TRANCPARENCY2)->EnableWindow (b1);
	GetDlgItem (IDC__TRANCPARENCY2_VAL)->EnableWindow (b1);

	GetDlgItem (IDC_HIDEFWWFS)->EnableWindow (b || b1);
}

void CPrg_GeneralPage_FWDlg::OnDropbox() 
{
	UpdateEnabled ();	
}

void CPrg_GeneralPage_FWDlg::OnDlinfo() 
{
	UpdateEnabled ();	
}

void CPrg_GeneralPage_FWDlg::UpdateBlendsVals()
{
	CString str; str.Format ("%d%%", m_wndBlend1.GetPos () * 100 / 255);
	CString str2; GetDlgItemText (IDC__TRANCPARENCY1_VAL, str2);
	if (str != str2)
		SetDlgItemText (IDC__TRANCPARENCY1_VAL, str);

	str.Format ("%d%%", m_wndBlend2.GetPos () * 100 / 255);
	GetDlgItemText (IDC__TRANCPARENCY2_VAL, str2);
	if (str != str2)
		SetDlgItemText (IDC__TRANCPARENCY2_VAL, str);
}

void CPrg_GeneralPage_FWDlg::OnCustomdrawTrancparency1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	UpdateBlendsVals ();

	CMainFrame *pFrame = (CMainFrame*) AfxGetApp ()->m_pMainWnd;
	pFrame->m_pFloatWndsThread->m_wndFloating.SetBlend ((BYTE)(255 - m_wndBlend1.GetPos ()));

	*pResult = 0;
}

void CPrg_GeneralPage_FWDlg::OnCustomdrawTrancparency2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	UpdateBlendsVals ();
	
	CMainFrame *pFrame = (CMainFrame*) AfxGetApp ()->m_pMainWnd;
	pFrame->m_pFloatWndsThread->m_wndFloatingInfo.SetBlend ((BYTE)(255 - m_wndBlend2.GetPos ()));

	*pResult = 0;
}

void CPrg_GeneralPage_FWDlg::OnCancel() 
{
	CMainFrame *pFrame = (CMainFrame*) AfxGetApp ()->m_pMainWnd;
	pFrame->m_pFloatWndsThread->m_wndFloating.SetBlend (m_blend1);
	pFrame->m_pFloatWndsThread->m_wndFloatingInfo.SetBlend (m_blend2);

	CDialog::OnCancel();
}
