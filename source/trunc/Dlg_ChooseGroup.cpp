/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Dlg_ChooseGroup.h"
#include "DownloadsWnd.h"
#include "GroupDlg.h"

extern CDownloadsWnd* _pwndDownloads;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlg_ChooseGroup::CDlg_ChooseGroup(CWnd* pParent )
	: CDialog(CDlg_ChooseGroup::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_ChooseGroup)
		
	//}}AFX_DATA_INIT

	m_pGroup = NULL;
}

void CDlg_ChooseGroup::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_ChooseGroup)
	DDX_Control(pDX, IDC_GROUPS, m_wndGroup);
	DDX_Control(pDX, IDC_CREATEGROUP, m_btnNewGrp);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlg_ChooseGroup, CDialog)
	//{{AFX_MSG_MAP(CDlg_ChooseGroup)
	ON_BN_CLICKED(IDC_CREATEGROUP, OnCreategroup)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlg_ChooseGroup::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_btnNewGrp.SetIcon (SICO (IDI_CREATEGROUP));

	m_wndGroup.Fill ();

	m_wndGroup.SelectGroupById (_App.NewDL_GroupId ());
		
	ApplyLanguage ();
	
	return TRUE;  
	              
}

void CDlg_ChooseGroup::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__GROUP, L_GROUP),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_CHOOSEGROUP);
}

void CDlg_ChooseGroup::OnCreategroup() 
{
	m_wndGroup.CreateNewGroup (m_wndGroup.GetSelectedGroup ());
}

void CDlg_ChooseGroup::OnOK() 
{
	m_pGroup = m_wndGroup.GetSelectedGroup ();	
	CDialog::OnOK();
}

