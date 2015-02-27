/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Dlg_WPD_IgnoreList.h"
#include "Dlg_WPD_IL_Add.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlg_WPD_IgnoreList::CDlg_WPD_IgnoreList(fsWPDSettings* wpds, CWnd* pParent )
	: CDialog(CDlg_WPD_IgnoreList::IDD, pParent),
	m_wpds (wpds)
{
	//{{AFX_DATA_INIT(CDlg_WPD_IgnoreList)
		
	//}}AFX_DATA_INIT
}

void CDlg_WPD_IgnoreList::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_WPD_IgnoreList)
	DDX_Control(pDX, IDC_LIST, m_wndList);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlg_WPD_IgnoreList, CDialog)
	//{{AFX_MSG_MAP(CDlg_WPD_IgnoreList)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_REMOVE, OnRemove)
	ON_NOTIFY(NM_CLICK, IDC_LIST, OnClickList)
	ON_NOTIFY(LVN_KEYDOWN, IDC_LIST, OnKeydownList)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CDlg_WPD_IgnoreList::OnAdd() 
{
	CDlg_WPD_IL_Add dlg;
	if (IDCANCEL == _DlgMgr.DoModal (&dlg))
		return;

	int i = m_wndList.GetItemCount ();
	m_wndList.InsertItem (i, dlg.m_strURL);
	m_wndList.SetItemText (i, 1, dlg.m_bThisOnly ? LS (L_ONLY) : LS (L_IGNORE));
	m_wndList.SetItemText (i, 2, dlg.m_bSubfoldersAlso ?  LS (L_YES) : LS (L_NO));
}

BOOL CDlg_WPD_IgnoreList::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CRect rc;
	m_wndList.GetClientRect (&rc);
	m_wndList.InsertColumn (0, "URL", LVCFMT_LEFT, rc.Width () - 2*70);
	m_wndList.InsertColumn (1, LS (L_TYPE), LVCFMT_LEFT, 70);
	m_wndList.InsertColumn (2, LS (L_SUBFOLDERS), LVCFMT_LEFT, 70);

	for (int i = 0; i < m_wpds->vIgnoreList.size (); i++)
	{
		m_wndList.InsertItem (i, m_wpds->vIgnoreList [i]->strURL);
		m_wndList.SetItemText (i, 1, m_wpds->vIgnoreList [i]->dwFlags & WPD_ILITEM_THISPATHONLY ? 
			LS (L_ONLY) : LS (L_IGNORE));
		m_wndList.SetItemText (i, 2, m_wpds->vIgnoreList [i]->dwFlags & WPD_ILITEM_SUBFOLDERSALSO ? 
			LS (L_YES) : LS (L_NO));
	}

	ApplyLanguage ();
	UpdateEnabled ();

	m_wndList.SetExtendedStyle (LVS_EX_FULLROWSELECT);
	
	return TRUE;  
	              
}

void CDlg_WPD_IgnoreList::UpdateEnabled()
{
	GetDlgItem (IDC_REMOVE)->EnableWindow (m_wndList.GetSelectedCount ());
}

void CDlg_WPD_IgnoreList::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_ADD, L_ADD),
		fsDlgLngInfo (IDC_REMOVE, L_REMOVE),
		fsDlgLngInfo (IDCANCEL, L_CANCEL),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_IGNORELIST);
}

void CDlg_WPD_IgnoreList::OnOK() 
{
	int i = 0;
	for (i = 0; i < m_wpds->vIgnoreList.size (); i++)
		delete m_wpds->vIgnoreList [i];
	m_wpds->vIgnoreList.clear ();
	if (m_wpds->m_ppoOwner)
		m_wpds->m_ppoOwner->setDirty();

	for (i = 0; i < m_wndList.GetItemCount (); i++)
	{
		fsWPDIgnoreListItem* item = new fsWPDIgnoreListItem;
	
		item->strURL = m_wndList.GetItemText (i, 0);
		item->dwFlags = m_wndList.GetItemText (i, 1) == LS (L_ONLY) ? WPD_ILITEM_THISPATHONLY : 0;
		if (m_wndList.GetItemText (i, 2) == LS (L_YES))
			item->dwFlags |=  WPD_ILITEM_SUBFOLDERSALSO;

		m_wpds->vIgnoreList.add (item);
		if (m_wpds->m_ppoOwner)
			m_wpds->m_ppoOwner->setDirty();
	}
	
	CDialog::OnOK();
}

void CDlg_WPD_IgnoreList::OnRemove() 
{
	POSITION pos = m_wndList.GetFirstSelectedItemPosition ();
	fs::list <int> v;
	while (pos)
		v.add (m_wndList.GetNextSelectedItem (pos));

	for (int i = v.size () - 1; i >= 0; i--)
		m_wndList.DeleteItem (v [i]);

	UpdateEnabled ();
}

void CDlg_WPD_IgnoreList::OnClickList(NMHDR* , LRESULT* pResult) 
{
	UpdateEnabled ();	
	*pResult = 0;
}

void CDlg_WPD_IgnoreList::OnKeydownList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	LPNMLVKEYDOWN pKD = (LPNMLVKEYDOWN) pNMHDR;

	if (VK_DELETE == pKD->wVKey)
		OnRemove ();

	UpdateEnabled ();	
	*pResult = 0;
}
