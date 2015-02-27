/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FDMCustomized.h"
#include "Dlg_ListOfDownloads.h"
#include "Dlg_Download.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlg_ListOfDownloads::CDlg_ListOfDownloads(vmsFDMCustomized* pCust, CWnd* pParent )
	: CDialog(CDlg_ListOfDownloads::IDD, pParent), m_pCust (pCust)
{
	//{{AFX_DATA_INIT(CDlg_ListOfDownloads)
		
	//}}AFX_DATA_INIT
}

void CDlg_ListOfDownloads::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_ListOfDownloads)
	DDX_Control(pDX, IDC_DOWNLOADS, m_wndDownloads);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlg_ListOfDownloads, CDialog)
	//{{AFX_MSG_MAP(CDlg_ListOfDownloads)
	ON_NOTIFY(NM_CLICK, IDC_DOWNLOADS, OnClickDownloads)
	ON_NOTIFY(NM_DBLCLK, IDC_DOWNLOADS, OnDblclkDownloads)
	ON_NOTIFY(LVN_KEYDOWN, IDC_DOWNLOADS, OnKeydownDownloads)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_REMOVE, OnRemove)
	ON_BN_CLICKED(IDC_MODIFY, OnModify)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlg_ListOfDownloads::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CRect rc;
	m_wndDownloads.GetClientRect (&rc); rc.right -= 2;
	m_wndDownloads.InsertColumn (0, "URL", LVCFMT_LEFT, rc.Width ()/2);
	m_wndDownloads.InsertColumn (1, "Referer", LVCFMT_LEFT, rc.Width ()/4);
	m_wndDownloads.InsertColumn (2, "Comment", LVCFMT_LEFT, rc.Width ()/4);

	for (int i = 0; i < m_pCust->get_DownloadCount (); i++)
	{
		vmsFDMDownloadInfo* dl = m_pCust->get_Download (i);
		m_wndDownloads.InsertItem (i, dl->strURL.c_str ());
		m_wndDownloads.SetItemText (i, 1, dl->strReferer.c_str ());
		m_wndDownloads.SetItemText (i, 2, dl->strComment.c_str ());
	}

	UpdateEnabled ();
	m_wndDownloads.SetExtendedStyle (LVS_EX_FULLROWSELECT);
	
	return TRUE;  
	              
}

void CDlg_ListOfDownloads::UpdateEnabled()
{
	BOOL b = m_wndDownloads.GetSelectedCount ();
	GetDlgItem (IDC_REMOVE)->EnableWindow (b);
	GetDlgItem (IDC_MODIFY)->EnableWindow (b);
}

void CDlg_ListOfDownloads::OnClickDownloads(NMHDR* pNMHDR, LRESULT* pResult) 
{
	UpdateEnabled ();	
	*pResult = 0;
}

void CDlg_ListOfDownloads::OnDblclkDownloads(NMHDR* pNMHDR, LRESULT* pResult) 
{
	OnModify ();	
	*pResult = 0;
}

void CDlg_ListOfDownloads::OnKeydownDownloads(NMHDR* pNMHDR, LRESULT* pResult) 
{
	LV_KEYDOWN* pLVKeyDow = (LV_KEYDOWN*)pNMHDR;
	if (pLVKeyDow->wVKey == VK_DELETE)
		OnRemove ();
	*pResult = 0;
}

void CDlg_ListOfDownloads::OnAdd() 
{
	CDlg_Download dlg;
	if (IDOK == dlg.DoModal ())
	{
		int i = m_wndDownloads.GetItemCount ();
		m_wndDownloads.InsertItem (i, dlg.m_strURL);
		m_wndDownloads.SetItemText (i, 1, dlg.m_strReferer);
		m_wndDownloads.SetItemText (i, 2, dlg.m_strComment);
	}

	UpdateEnabled ();	
}

void CDlg_ListOfDownloads::OnRemove() 
{
	POSITION pos = m_wndDownloads.GetFirstSelectedItemPosition ();
	std::vector <int> v;
	while (pos)
		v.push_back (m_wndDownloads.GetNextSelectedItem (pos));
	for (int i = v.size () - 1; i >= 0; i--)
		m_wndDownloads.DeleteItem (v [i]);
	UpdateEnabled ();	
}

void CDlg_ListOfDownloads::OnModify() 
{
	POSITION pos = m_wndDownloads.GetFirstSelectedItemPosition ();
	if (pos == NULL)
		return;
	int i = m_wndDownloads.GetNextSelectedItem (pos);

	CDlg_Download dlg;
	dlg.m_strURL = m_wndDownloads.GetItemText (i, 0);
	dlg.m_strReferer = m_wndDownloads.GetItemText (i, 1);
	dlg.m_strComment = m_wndDownloads.GetItemText (i, 2);

	if (IDOK == dlg.DoModal ())
	{
		m_wndDownloads.SetItemText (i, 0, dlg.m_strURL);
		m_wndDownloads.SetItemText (i, 1, dlg.m_strReferer);
		m_wndDownloads.SetItemText (i, 2, dlg.m_strComment);
	}

	UpdateEnabled ();	
}

void CDlg_ListOfDownloads::OnOK() 
{
	m_pCust->RemoveAllDownloads ();
	for (int i = 0; i < m_wndDownloads.GetItemCount (); i++)
	{
		vmsFDMDownloadInfo dl;
		dl.strURL = m_wndDownloads.GetItemText (i, 0);
		dl.strReferer = m_wndDownloads.GetItemText (i, 1);
		dl.strComment = m_wndDownloads.GetItemText (i, 2);
		m_pCust->add_Download (dl);
	}
	
	CDialog::OnOK();
}
