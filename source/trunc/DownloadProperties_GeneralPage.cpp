/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "DownloadProperties_GeneralPage.h"
#include "DownloadProperties.h"
#include "misc.h"
#include "DownloadsWnd.h"
#include "fsDownloadMgr.h"
#include "system.h"
#include "DownloadsWnd.h"
#include "CreateDownloadDlg.h"
#include "QueryStoringServiceInfoGuard.h"

extern CDownloadsWnd* _pwndDownloads;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CDownloadProperties_GeneralPage, CPropertyPage)

CDownloadProperties_GeneralPage::CDownloadProperties_GeneralPage() : CPropertyPage(CDownloadProperties_GeneralPage::IDD)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = LS (L_GENERAL);
}

CDownloadProperties_GeneralPage::~CDownloadProperties_GeneralPage()
{
}

void CDownloadProperties_GeneralPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDownloadProperties_GeneralPage)
	DDX_Control(pDX, IDC_GROUPS, m_wndGroups);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDownloadProperties_GeneralPage, CPropertyPage)
	//{{AFX_MSG_MAP(CDownloadProperties_GeneralPage)
	ON_CBN_SELCHANGE(IDC_GROUPS, OnSelchangeGroups)
	ON_EN_CHANGE(IDC_COMMENT, OnChangeComment)
	ON_EN_CHANGE(IDC_URL, OnChangeUrl)
	ON_EN_CHANGE(IDC_SAVEAS, OnChangeSaveas)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	ON_BN_CLICKED(IDC_USELOGIN, OnUselogin)
	ON_EN_CHANGE(IDC_USER, OnChangeUser)
	ON_EN_CHANGE(IDC_PASSWORD, OnChangePassword)
	ON_WM_HELPINFO()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

#define DNP_OFFSET(member) ( LPBYTE (&dnp.member) - LPBYTE (&dnp) )
#define DNP_SIZEOF(member) ( sizeof (dnp.member) )
#define DNP_EQ(member, bString) DNPEntry_IsAllEqual (m_pvDlds, DNP_OFFSET (member), DNP_SIZEOF (member), bString)
#define DNP_SET(member, bString, NewVal) DNPEntry_SetValue (m_pvDlds, DNP_OFFSET (member), DNP_SIZEOF (member), bString, NewVal);

#define DP_OFFSET(member) ( LPBYTE (&dp.member) - LPBYTE (&dp) )
#define DP_SIZEOF(member) ( sizeof (dp.member) )
#define DP_EQ_EX(memOffset, memSize, bString) DPEntry_IsAllEqual (m_pvDlds, memOffset, memSize, bString)
#define DP_EQ_MASK(member, mask) DPEntry_IsAllEqual_BitMask (m_pvDlds, DP_OFFSET (member), mask)
#define DP_SET_MASK(member, mask) DPEntry_SetValue_BitMask (m_pvDlds, DP_OFFSET (member), mask)
#define DP_UNSET_MASK(member, mask) DPEntry_UnsetValue_BitMask (m_pvDlds, DP_OFFSET (member), mask)

BOOL CDownloadProperties_GeneralPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	const vmsDownloadSmartPtr dld0 = m_pvDlds->at (0);
	const fsDownload_NetworkProperties *dnp0 = dld0->pMgr->GetDownloadMgr ()->GetDNP ();
	
	const int size = m_pvDlds->size ();
	

	if (size == 1)	
	{
		

		fsURL url;
		CHAR szUrl [10000];
		DWORD dwLen = sizeof (szUrl);

		url.Create (fsNPToScheme (dnp0->enProtocol), dnp0->pszServerName, dnp0->uServerPort,
			NULL, NULL, dnp0->pszPathName, szUrl, &dwLen);

		SetDlgItemText (IDC_URL, szUrl);
		SetDlgItemText (IDC_SAVEAS, m_pvDlds->at (0)->pMgr->GetDownloadMgr ()->GetDP ()->pszFileName);

		m_strUrl = szUrl;
	}
	else
	{
		

		GetDlgItem (IDC_URL)->EnableWindow (FALSE);
		GetDlgItem (IDC_SAVEAS)->EnableWindow (FALSE);
		GetDlgItem (IDC__GENERAL)->EnableWindow (FALSE);
		GetDlgItem (IDC__URL)->EnableWindow (FALSE);
		GetDlgItem (IDC__SAVEDAS)->EnableWindow (FALSE);
	}

	m_wndGroups.Fill ();

	int i = 1;
	for (i = 1; i < size; i++)
	{
		if (dld0->pGroup->nId != m_pvDlds->at (i)->pGroup->nId)
			break;
	}

	if (i == size)	
		m_wndGroups.SelectGroup (dld0->pGroup);
	else
		m_wndGroups.SelectGroup (NULL);

	for (i = 1; i < size; i++)
	{
		if (dld0->strComment != m_pvDlds->at (i)->strComment)
			break;
	}

	if (i == size)
		SetDlgItemText (IDC_COMMENT, dld0->strComment);

	m_bCommentModified = FALSE;
	m_bNeedProcessDownloads = FALSE;

	ReadAuthorization ();

	

	ApplyLanguage ();

	return TRUE;  
	              
}

void CDownloadProperties_GeneralPage::OnSelchangeGroups() 
{
	SetModified ();	
}

void CDownloadProperties_GeneralPage::OnChangeComment() 
{
	m_bCommentModified = TRUE;
	SetModified ();
}

BOOL CDownloadProperties_GeneralPage::OnApply() 
{
	const int size = m_pvDlds->size ();

	if (size == 1)
	{
		CString strNewUrl;
		CString strNewFile;
		GetDlgItemText (IDC_URL, strNewUrl);
		GetDlgItemText (IDC_SAVEAS, strNewFile);
        if (FALSE == CCreateDownloadDlg::_CheckFolderName (this, IDC_SAVEAS))
			return FALSE;

		
		if (strNewUrl != m_strUrl)
		{
			
			{
				fsURL url;
				
				if (url.Crack (strNewUrl) != IR_SUCCESS || 
					 (url.GetInternetScheme () != INTERNET_SCHEME_FILE && *url.GetHostName () == 0))
				{
					MessageBox (LS (L_CHECKURL), LS (L_INPERR), MB_ICONEXCLAMATION);
					((CEdit*) GetDlgItem (IDC_URL))->SetSel (0, -1);
					GetDlgItem (IDC_URL)->SetFocus ();
					return FALSE;
				}

				m_pvDlds->at (0)->pMgr->GetDownloadMgr ()->CreateByUrl (strNewUrl, TRUE);
				m_pvDlds->at (0)->pMgr->GetDownloadMgr ()->setDirty();
				if (*m_pvDlds->at (0)->pMgr->GetDownloadMgr ()->GetDNP ()->pszUserName)
					ReadAuthorization ();
			}
		}

		fsDownload_Properties *dp = m_pvDlds->at (0)->pMgr->GetDownloadMgr ()->GetDP ();

		
		if (strNewFile != dp->pszFileName)
		{
			if (FALSE == m_pvDlds->at (0)->pMgr->GetDownloadMgr ()->MoveFile (strNewFile))
			{
				if (GetLastError () == 0)
				{
					
					MessageBox (LS (L_CANTCHANGEFILENAME), LS (L_ERR), MB_ICONERROR);
				}
				else
				{
					CString strErr;
					CHAR szErr [1000];

					fsErrorToStr (szErr, 1000);

					strErr.Format ("%s\n\n%s: %s", LS (L_CANTRENAME), LS (L_ERR), szErr); 
					MessageBox (strErr, LS (L_ERR), MB_ICONERROR);
				}
			}
		}
	}

	_pwndDownloads->UpdateDownload (m_pvDlds->at (0), TRUE);

	vmsDownloadsGroupSmartPtr pGroup = m_wndGroups.GetSelectedGroup ();
	if (pGroup != NULL)
	{
		for (int i = 0; i < size; i++)
		{
			if (m_pvDlds->at (i)->pGroup->nId != pGroup->nId)
			{
				m_pvDlds->at (i)->pGroup->cDownloads--;
				m_pvDlds->at (i)->pGroup = pGroup;
				pGroup->cDownloads++;
				m_pvDlds->at (i)->pMgr->GetDownloadMgr ()->MoveToFolder (pGroup->strOutFolder);
				m_pvDlds->at (i)->setDirty(); 
			}
		}

		m_bNeedUpdateTasks = TRUE;
		_pwndDownloads->UpdateNumbersOfDownloadsInGroups ();
	}
	else
		m_bNeedUpdateTasks = FALSE;

	if (m_bCommentModified)
	{
		CString strComment;
		GetDlgItemText (IDC_COMMENT, strComment);

		for (int i = 0; i < size; i++)
		{
			m_pvDlds->at (i)->strComment = strComment;
			m_pvDlds->at (i)->setDirty();
			_pwndDownloads->UpdateDownload (m_pvDlds->at (i));
		}

		m_bNeedUpdateTasks = TRUE;
	}

	WriteAuthorization ();
	
	
	
	return CPropertyPage::OnApply();
}

void CDownloadProperties_GeneralPage::OnChangeUrl() 
{
	SetModified ();
}

void CDownloadProperties_GeneralPage::OnChangeSaveas() 
{
	SetModified ();
}

void CDownloadProperties_GeneralPage::OnContextMenu(CWnd* , CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();
}

void CDownloadProperties_GeneralPage::OnWhatisthis() 
{
	_CHMgr.OnWT ();
}

void CDownloadProperties_GeneralPage::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__GENERAL, L_GENERALINFO),
		fsDlgLngInfo (IDC__USER, L_USER),
		fsDlgLngInfo (IDC__PASSWORD, L_PASSWORD),
		fsDlgLngInfo (IDC_USELOGIN, L_LOGINREQ),
		fsDlgLngInfo (IDC__SAVEDAS, L_SAVEDAS),
		fsDlgLngInfo (IDC__GROUP, L_GROUP),
		fsDlgLngInfo (IDC__COMMENT, L_COMMENT, TRUE),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}

void CDownloadProperties_GeneralPage::ReadAuthorization()
{
	fsDownload_NetworkProperties dnp;
	fsDownload_NetworkProperties *dnp0 = m_pvDlds->at (0)->pMgr->GetDownloadMgr ()->GetDNP ();

	if (DNP_EQ (pszUserName, TRUE))
		SetDlgItemText (IDC_USER, dnp0->pszUserName);

	if (DNP_EQ (pszPassword, TRUE))
		SetDlgItemText (IDC_PASSWORD, dnp0->pszPassword);

	BOOL bUse = dnp0->pszUserName [0] != 0;
	CheckDlgButton (IDC_USELOGIN, bUse ? BST_CHECKED : BST_UNCHECKED);
	for (int i = m_pvDlds->size () - 1; i > 0; i--)
	{
		BOOL bU = m_pvDlds->at (i)->pMgr->GetDownloadMgr ()->GetDNP ()->pszUserName [0] != 0;

		if (bU != bUse)
		{
			CheckDlgButton (IDC_USELOGIN, BST_INDETERMINATE);
			break;
		}
	}

	m_bUserChanged = m_bPasswordChanged = FALSE;

	UpdateEnabled ();
}

void CDownloadProperties_GeneralPage::UpdateEnabled()
{
	BOOL bE = IsDlgButtonChecked (IDC_USELOGIN) == BST_CHECKED;

	GetDlgItem (IDC_USER)->EnableWindow (bE);
	GetDlgItem (IDC_PASSWORD)->EnableWindow (bE);
	GetDlgItem (IDC__USER)->EnableWindow (bE);
	GetDlgItem (IDC__PASSWORD)->EnableWindow (bE);
}

void CDownloadProperties_GeneralPage::OnUselogin() 
{
	if (IsDlgButtonChecked (IDC_USELOGIN) == BST_INDETERMINATE)
		CheckDlgButton (IDC_USELOGIN, BST_UNCHECKED);

	UpdateEnabled ();
	SetModified ();	
}

void CDownloadProperties_GeneralPage::OnChangeUser() 
{
	SetModified ();
	m_bUserChanged = TRUE;
}

void CDownloadProperties_GeneralPage::OnChangePassword() 
{
	SetModified ();	
	m_bPasswordChanged = TRUE;
}

void CDownloadProperties_GeneralPage::WriteAuthorization()
{
	UINT nChecked = IsDlgButtonChecked (IDC_USELOGIN);
	fsDownload_NetworkProperties dnp;
	CString str;

	switch (nChecked)
	{
		case BST_CHECKED:
			GetDlgItemText (IDC_USER, str);
			if (m_bUserChanged || str.GetLength ()) {
				DNP_SET (pszUserName, TRUE, str);
			}

			GetDlgItemText (IDC_PASSWORD, str);
			if (m_bPasswordChanged || str.GetLength ()) {
				DNP_SET (pszPassword, TRUE, str);
			}
			break;

		case BST_UNCHECKED:
			DNP_SET (pszUserName, TRUE, "");
			DNP_SET (pszPassword, TRUE, "");
			break;
	}
}

BOOL CDownloadProperties_GeneralPage::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	RECT rc;
	CWnd *pItem = GetDlgItem (pHelpInfo->iCtrlId);
	if (pItem == NULL)
		return TRUE;
	pItem->GetWindowRect (&rc);
	if (PtInRect (&rc, pHelpInfo->MousePos) == FALSE)
	{
		pHelpInfo->MousePos.x = rc.left + (rc.right - rc.left) / 2;
		pHelpInfo->MousePos.y = rc.top + (rc.bottom - rc.top) / 2;
	}
	PrepareCHMgr (pHelpInfo->MousePos);
	_CHMgr.OnWT ();
	return TRUE;
}

void CDownloadProperties_GeneralPage::PrepareCHMgr(CPoint point)
{
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC__URL, LS (L_ADDROFFILE)),
		fsCtrlContextHelp (IDC_URL, LS (L_ADDROFFILE)),
		fsCtrlContextHelp (IDC__USER, LS (L_USERHERE)),
		fsCtrlContextHelp (IDC_USER, LS (L_USERHERE)),
		fsCtrlContextHelp (IDC__PASSWORD, LS (L_PWDHERE)),
		fsCtrlContextHelp (IDC_PASSWORD, LS (L_PWDHERE)),
		fsCtrlContextHelp (IDC_USELOGIN, LS (L_LOGINHERE)),
		fsCtrlContextHelp (IDC__SAVEDAS, LS (L_SAVEDASHERE)),
		fsCtrlContextHelp (IDC_SAVEAS, LS (L_SAVEDASHERE)),
		fsCtrlContextHelp (IDC__GROUP, LS (L_GROUPHERE)),
		fsCtrlContextHelp (IDC_GROUPS, LS (L_GROUPHERE)),
		fsCtrlContextHelp (IDC__COMMENT, LS (L_DLDSHORTDESC)),
		fsCtrlContextHelp (IDC_COMMENT, LS (L_DLDSHORTDESC)),
		
	};

    static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));	
}

