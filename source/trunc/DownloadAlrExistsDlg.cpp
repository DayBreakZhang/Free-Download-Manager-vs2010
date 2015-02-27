/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "DownloadAlrExistsDlg.h"
#include "mfchelp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDownloadAlrExistsDlg::CDownloadAlrExistsDlg(CWnd* pParent )
	: CDialog(CDownloadAlrExistsDlg::IDD, pParent)
{
	m_bNeedTopMost = FALSE;
}

void CDownloadAlrExistsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDownloadAlrExistsDlg)
		
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDownloadAlrExistsDlg, CDialog)
	//{{AFX_MSG_MAP(CDownloadAlrExistsDlg)
	ON_BN_CLICKED(IDC_RESUME, OnResume)
	ON_BN_CLICKED(IDC_RESTART, OnRestart)
	ON_BN_CLICKED(IDC_LAUNCH, OnLaunch)
	ON_WM_CONTEXTMENU()
	ON_WM_HELPINFO()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CDownloadAlrExistsDlg::OnResume() 
{
	if (IsDlgButtonChecked (IDC_DONTCHECKAGAIN) == BST_CHECKED)
		_App.CheckIfDownloadWithSameUrlExists (FALSE);
	EndDialog (IDC_RESUME);	
}

void CDownloadAlrExistsDlg::OnRestart() 
{
	if (IsDlgButtonChecked (IDC_DONTCHECKAGAIN) == BST_CHECKED)
		_App.CheckIfDownloadWithSameUrlExists (FALSE);
	EndDialog (IDC_RESTART);	
}

void CDownloadAlrExistsDlg::OnLaunch() 
{
	if (IsDlgButtonChecked (IDC_DONTCHECKAGAIN) == BST_CHECKED)
		_App.CheckIfDownloadWithSameUrlExists (FALSE);
	EndDialog (IDC_LAUNCH);	
}

BOOL CDownloadAlrExistsDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	
	((CStatic*) GetDlgItem (IDC_DLGICON))->SetIcon (LoadIcon (NULL, IDI_QUESTION));

	if (m_dld->pMgr->GetPercentDone() == -1)
		GetDlgItem (IDC_RESUME)->EnableWindow (FALSE);

	if (m_dld->pMgr->IsRunning ())
		GetDlgItem (IDC_RESTART)->EnableWindow (FALSE);

	if (m_dld->pMgr->IsDone () == FALSE)
	{
		
		GetDlgItem (IDC_LAUNCH)->EnableWindow (FALSE);
	}
	
	ApplyLanguage ();

	if (m_bNeedTopMost)
	{
		fsSetForegroundWindow (m_hWnd);
        mfcSetTopmostWindow (this);
	}
	
	return TRUE;
}

void CDownloadAlrExistsDlg::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__MSG, L_DLDALREXISTS),
		fsDlgLngInfo (IDC_RESUME, L_RESUME),
		fsDlgLngInfo (IDC_RESTART, L_RESTART),
		fsDlgLngInfo (IDC_LAUNCH, L_LAUNCH),
		fsDlgLngInfo (IDCANCEL, L_CANCEL),
		fsDlgLngInfo (IDC_DONTCHECKAGAIN, L_DONTCHECKAGAIN),
	};

	CString str = LS (L_COMMENT); str += ':';
	SetDlgItemText (IDC__COMMENT, str);

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_NEWDLD);
}

void CDownloadAlrExistsDlg::OnContextMenu(CWnd* , CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();
}

void CDownloadAlrExistsDlg::PrepareCHMgr(CPoint point)
{
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC_RESUME, LS (L_RESUMEHERE)),
		fsCtrlContextHelp (IDC_RESTART, LS (L_RESTARTHERE)),
		fsCtrlContextHelp (IDC_LAUNCH, LS (L_LAUNCHHERE)),
	};

    static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));		
}

BOOL CDownloadAlrExistsDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
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

void CDownloadAlrExistsDlg::OnCancel() 
{
	if (IsDlgButtonChecked (IDC_DONTCHECKAGAIN) == BST_CHECKED)
		_App.CheckIfDownloadWithSameUrlExists (FALSE);
	
	CDialog::OnCancel();
}
