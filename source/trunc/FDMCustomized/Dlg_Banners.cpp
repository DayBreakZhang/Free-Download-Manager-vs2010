/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FDMCustomized.h"
#include "Dlg_Banners.h"
#include "Dlg_Banner.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlg_Banners::CDlg_Banners(vmsFDMCustomized* pCust, CWnd* pParent )
	: CDialog(CDlg_Banners::IDD, pParent), m_pCust (pCust)
{
	//{{AFX_DATA_INIT(CDlg_Banners)
		
	//}}AFX_DATA_INIT
}

void CDlg_Banners::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_Banners)
	DDX_Control(pDX, IDC_BANNERS, m_wndBanners);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlg_Banners, CDialog)
	//{{AFX_MSG_MAP(CDlg_Banners)
	ON_NOTIFY(NM_CLICK, IDC_BANNERS, OnClickBanners)
	ON_NOTIFY(NM_DBLCLK, IDC_BANNERS, OnDblclkBanners)
	ON_NOTIFY(LVN_KEYDOWN, IDC_BANNERS, OnKeydownBanners)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_REMOVE, OnRemove)
	ON_BN_CLICKED(IDC_MODIFY, OnModify)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlg_Banners::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CRect rc;
	m_wndBanners.GetClientRect (&rc); rc.right -= 2;
	m_wndBanners.InsertColumn (0, "Image file", LVCFMT_LEFT, rc.Width ()/2);
	m_wndBanners.InsertColumn (1, "URL", LVCFMT_LEFT, rc.Width ()/2);

	for (int i = 0; i < m_pCust->get_BannerCount (); i++)
	{
		vmsFDMBannerInfo* banner = m_pCust->get_Banner (i);
		m_wndBanners.InsertItem (i, banner->strFile.c_str ());
		m_wndBanners.SetItemText (i, 1, banner->strURL.c_str ());
	}

	UpdateEnabled ();
	m_wndBanners.SetExtendedStyle (LVS_EX_FULLROWSELECT);
	
	return TRUE;  
	              
}

void CDlg_Banners::UpdateEnabled()
{
	BOOL b = m_wndBanners.GetSelectedCount ();
	GetDlgItem (IDC_REMOVE)->EnableWindow (b);
	GetDlgItem (IDC_MODIFY)->EnableWindow (b);
}

void CDlg_Banners::OnClickBanners(NMHDR* , LRESULT* pResult) 
{
	UpdateEnabled ();	
	*pResult = 0;
}

void CDlg_Banners::OnDblclkBanners(NMHDR* , LRESULT* pResult) 
{
	OnModify ();
	*pResult = 0;
}

void CDlg_Banners::OnKeydownBanners(NMHDR* pNMHDR, LRESULT* pResult) 
{
	LV_KEYDOWN* pLVKeyDow = (LV_KEYDOWN*)pNMHDR;
	if (pLVKeyDow->wVKey == VK_DELETE)
		OnRemove ();
	*pResult = 0;
}

void CDlg_Banners::OnAdd() 
{
	CDlg_Banner dlg;
	if (IDOK == dlg.DoModal ())
	{
		int i = m_wndBanners.GetItemCount ();
		m_wndBanners.InsertItem (i, dlg.m_strFile);
		m_wndBanners.SetItemText (i, 1, dlg.m_strURL);
	}

	UpdateEnabled ();
}

void CDlg_Banners::OnRemove() 
{
	POSITION pos = m_wndBanners.GetFirstSelectedItemPosition ();
	std::vector <int> v;
	while (pos)
		v.push_back (m_wndBanners.GetNextSelectedItem (pos));
	for (int i = v.size () - 1; i >= 0; i--)
		m_wndBanners.DeleteItem (v [i]);
	UpdateEnabled ();
}

void CDlg_Banners::OnModify() 
{
	POSITION pos = m_wndBanners.GetFirstSelectedItemPosition ();
	if (pos == NULL)
		return;
	int i = m_wndBanners.GetNextSelectedItem (pos);

	CDlg_Banner dlg;
	dlg.m_strFile = m_wndBanners.GetItemText (i, 0);
	dlg.m_strURL = m_wndBanners.GetItemText (i, 1);

	if (IDOK == dlg.DoModal ())
	{
		m_wndBanners.SetItemText (i, 0, dlg.m_strFile);
		m_wndBanners.SetItemText (i, 1, dlg.m_strURL);
	}

	UpdateEnabled ();
}

void CDlg_Banners::OnOK() 
{
	m_pCust->RemoveAllBanners ();
	for (int i = 0; i < m_wndBanners.GetItemCount (); i++)
	{
		vmsFDMBannerInfo banner;
		banner.strFile = m_wndBanners.GetItemText (i, 0);
		banner.strURL  = m_wndBanners.GetItemText (i, 1);
		m_pCust->add_Banner (banner);
	}
	
	CDialog::OnOK();
}
