/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FDMCustomized.h"
#include "FDMCustomizedDlg.h"
#include "Dlg_Banners.h"
#include "Dlg_Button.h"
#include "Dlg_Customizer.h"
#include "Dlg_ListOfDownloads.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CFDMCustomizedDlg::CFDMCustomizedDlg(CWnd* pParent )
	: CDialog(CFDMCustomizedDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFDMCustomizedDlg)
		
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFDMCustomizedDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFDMCustomizedDlg)
		
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFDMCustomizedDlg, CDialog)
	//{{AFX_MSG_MAP(CFDMCustomizedDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_GENERATE, OnGenerate)
	ON_BN_CLICKED(IDC_BANNERS, OnBanners)
	ON_BN_CLICKED(IDC_ADDBANNERS, OnAddbanners)
	ON_BN_CLICKED(IDC_ADDBUTTON, OnAddbutton)
	ON_BN_CLICKED(IDC_CUSTOMIZEBUTTON, OnCustomizebutton)
	ON_BN_CLICKED(IDC_CUSTOMIZER_MORE, OnCustomizerMore)
	ON_BN_CLICKED(IDC_ADDBUTTON_IE, OnAddbuttonIe)
	ON_BN_CLICKED(IDC_BROWSEIEICO, OnBrowseieico)
	ON_BN_CLICKED(IDC_SETUPLIST, OnSetuplist)
	ON_BN_CLICKED(IDC_ADDDOWNLOADS, OnAdddownloads)
	ON_BN_CLICKED(IDC_LAUNCH, OnLaunch)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CFDMCustomizedDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	

	
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	SetIcon(m_hIcon, TRUE);			
	SetIcon(m_hIcon, FALSE);		

	SetDlgItemText (IDC_CUSTOMIZER, "Free Downloads Center");

	UpdateEnabled ();
	
	
	return TRUE;  
}

void CFDMCustomizedDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

void CFDMCustomizedDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); 

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

HCURSOR CFDMCustomizedDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CFDMCustomizedDlg::OnGenerate() 
{
	FromDialog ();

	m_FDMCustomized.Generate (
		"e:\\fdm\\FDMCustomized_PreExe.exe");	
}

void CFDMCustomizedDlg::OnBanners() 
{
	CDlg_Banners dlg (&m_FDMCustomized, this);
	dlg.DoModal ();
	if (m_FDMCustomized.get_BannerCount () == 0)
	{
		CheckDlgButton (IDC_ADDBANNERS, BST_UNCHECKED);
		UpdateEnabled ();
	}
}

void CFDMCustomizedDlg::OnAddbanners() 
{
	if (IsDlgButtonChecked (IDC_ADDBANNERS) == BST_CHECKED &&
			m_FDMCustomized.get_BannerCount () == 0)
	{
		OnBanners ();
	}

	UpdateEnabled ();
}

void CFDMCustomizedDlg::UpdateEnabled()
{
	GetDlgItem (IDC_BANNERS)->EnableWindow (
		IsDlgButtonChecked (IDC_ADDBANNERS) == BST_CHECKED);

	GetDlgItem (IDC_CUSTOMIZEBUTTON)->EnableWindow (
		IsDlgButtonChecked (IDC_ADDBUTTON) == BST_CHECKED);

	BOOL b = IsDlgButtonChecked (IDC_ADDBUTTON_IE) == BST_CHECKED;
	GetDlgItem (IDC_STATIC1)->EnableWindow (b);
	GetDlgItem (IDC_IEBTNICOFILE)->EnableWindow (b);
	GetDlgItem (IDC_BROWSEIEICO)->EnableWindow (b);

	GetDlgItem (IDC_SETUPLIST)->EnableWindow (
		IsDlgButtonChecked (IDC_ADDDOWNLOADS) == BST_CHECKED);
}

void CFDMCustomizedDlg::OnAddbutton() 
{
	if (IsDlgButtonChecked (IDC_ADDBUTTON) == BST_CHECKED &&
			m_FDMCustomized.get_ButtonInfo ()->strText.length () == 0)
	{
		OnCustomizebutton ();
	}
	
	UpdateEnabled ();
}

void CFDMCustomizedDlg::OnCustomizebutton() 
{
	CDlg_Button dlg;
	vmsFDMButtonInfo* btn = m_FDMCustomized.get_ButtonInfo ();
	dlg.m_strText = btn->strText.c_str ();
	dlg.m_strURL  = btn->strURL.c_str ();
	dlg.m_strIco  = btn->strIcon.c_str ();
	dlg.DoModal ();
	btn->strText = dlg.m_strText;
	btn->strURL	 = dlg.m_strURL;
	btn->strIcon = dlg.m_strIco;

	if (dlg.m_strText == "")
	{
		CheckDlgButton (IDC_ADDBUTTON, BST_UNCHECKED);
		UpdateEnabled ();
	}
}

void CFDMCustomizedDlg::OnCustomizerMore() 
{
	CDlg_Customizer dlg;
	dlg.m_strURL = m_FDMCustomized.get_Customizer_SiteURL ();
	dlg.m_strIcon = m_FDMCustomized.get_Customizer_SiteIconFile ();
	dlg.DoModal ();
	m_FDMCustomized.set_Customizer_SiteURL (dlg.m_strURL);
	m_FDMCustomized.set_Customizer_SiteIconFile (dlg.m_strIcon);
}

void CFDMCustomizedDlg::FromDialog()
{
	CString str;
	GetDlgItemText (IDC_CUSTOMIZER, str);
	m_FDMCustomized.set_Customizer (str);

	DWORD dw = 0;
	if (IsDlgButtonChecked (IDC_MODIFYHP) == BST_CHECKED)
		dw |= FC_MODIFYHOMEPAGE;
	if (IsDlgButtonChecked (IDC_ADDLINK_FAVOR) == BST_CHECKED)
		dw |= FC_ADDLINKTOFAVOR;
	if (IsDlgButtonChecked (IDC_ADDLINK_SM) == BST_CHECKED)
		dw |= FC_ADDLINKTOSTARTMENU;
	if (IsDlgButtonChecked (IDC_ADDBUTTON_IE) == BST_CHECKED)
		dw |= FC_ADDBUTTONTOIE;
	if (IsDlgButtonChecked (IDC_ADDDOWNLOADS) == BST_CHECKED)
		dw |= FC_ADDDOWNLOADS;
	if (IsDlgButtonChecked (IDC_ADDBANNERS) == BST_CHECKED)
		dw |= FC_ADDBANNERS;
	if (IsDlgButtonChecked (IDC_MHP_CHECKED) == BST_CHECKED)
		dw |= FC_MHP_CHECKEDBYDEF;
	if (IsDlgButtonChecked (IDC_FAV_OPTIONAL) == BST_CHECKED)
		dw |= FC_FAV_OPTIONAL;
	if (IsDlgButtonChecked (IDC_FAV_CHECKED) == BST_CHECKED)
		dw |= FC_FAV_CHECKEDBYDEF;
	if (IsDlgButtonChecked (IDC_SM_OPTIONAL) == BST_CHECKED)
		dw |= FC_SM_OPTIONAL;
	if (IsDlgButtonChecked (IDC_SM_CHECKED) == BST_CHECKED)
		dw |= FC_SM_CHECKEDBYDEF;
	if (IsDlgButtonChecked (IDC_IEBTN_OPTIONAL) == BST_CHECKED)
		dw |= FC_IEBTN_OPTIONAL;
	if (IsDlgButtonChecked (IDC_IEBTN_CHECKED) == BST_CHECKED)
		dw |= FC_IEBTN_CHECKEDBYDEF;

	m_FDMCustomized.set_Flags (dw);

	m_FDMCustomized.set_UseButton (
		IsDlgButtonChecked (IDC_ADDBUTTON) == BST_CHECKED);

	m_FDMCustomized.set_UseFDMCVerBtn (
		IsDlgButtonChecked (IDC_FDMCVERBTN) == BST_CHECKED);

	m_FDMCustomized.m_id = GetDlgItemInt (IDC_ID);

	GetDlgItemText (IDC_IEBTNICOFILE, str);
	m_FDMCustomized.set_IEButtonIcon (str);
}

void CFDMCustomizedDlg::OnAddbuttonIe() 
{
	UpdateEnabled ();	
}

void CFDMCustomizedDlg::OnBrowseieico() 
{
	CString str;
	GetDlgItemText (IDC_IEBTNICOFILE, str);
	CFileDialog dlg (TRUE, NULL, str, OFN_HIDEREADONLY|OFN_NOCHANGEDIR, 
		"Files with icons (*.ico)|*.ico|All files (*.*)|*.*||", this);
	if (dlg.DoModal () == IDOK)
		SetDlgItemText (IDC_IEBTNICOFILE, dlg.GetPathName ());
}

void CFDMCustomizedDlg::OnSetuplist() 
{
	CDlg_ListOfDownloads dlg (&m_FDMCustomized, this);
	dlg.DoModal ();
	if (m_FDMCustomized.get_DownloadCount () == 0)
	{
		CheckDlgButton (IDC_ADDDOWNLOADS, BST_UNCHECKED);
		UpdateEnabled ();
	}
}

void CFDMCustomizedDlg::OnAdddownloads() 
{
	if (m_FDMCustomized.get_DownloadCount () == 0)
		OnSetuplist ();
	UpdateEnabled ();
}

void CFDMCustomizedDlg::OnLaunch() 
{
	ShellExecute (m_hWnd, "open", "e:\\fdm\\FDMCustomized_PreExe.exe", 
		NULL, NULL, SW_SHOW);		
}
