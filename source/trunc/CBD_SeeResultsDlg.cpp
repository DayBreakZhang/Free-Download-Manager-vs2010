/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "CBD_SeeResultsDlg.h"
#include "vmsBatchList.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CCBD_SeeResultsDlg::CCBD_SeeResultsDlg(CWnd* pParent )
	: CDialog(CCBD_SeeResultsDlg::IDD, pParent)
{
	m_bl = NULL;
}

void CCBD_SeeResultsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCBD_SeeResultsDlg)
	DDX_Control(pDX, IDC_LIST, m_wndList);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCBD_SeeResultsDlg, CDialog)
	//{{AFX_MSG_MAP(CCBD_SeeResultsDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CCBD_SeeResultsDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CRect rc;
	m_wndList.GetClientRect (&rc);
	m_wndList.InsertColumn (0, "", LVCFMT_LEFT, rc.right);

	for (int i = 0; i < m_bl->get_ResultCount (); i++)
		m_wndList.InsertItem (i, m_bl->get_Result (i));

	m_wndList.SetColumnWidth (0, LVSCW_AUTOSIZE);

	SetWindowText (LS (L_SEERESULTS));
	
	return TRUE;
}

