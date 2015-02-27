/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "DDRDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDDRDlg::CDDRDlg(CWnd* pParent )
	: CDialog(CDDRDlg::IDD, pParent)
{
	m_enDDR = DDR_WITHFILE;
	m_bForAll = FALSE;
	m_bNoCancel = FALSE;
	//{{AFX_DATA_INIT(CDDRDlg)
		
	//}}AFX_DATA_INIT
}

void CDDRDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDDRDlg)
		
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDDRDlg, CDialog)
	//{{AFX_MSG_MAP(CDDRDlg)
	ON_BN_CLICKED(IDC_YES, OnYes)
	ON_BN_CLICKED(IDC_NO2, OnNo)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	ON_WM_HELPINFO()
	ON_BN_CLICKED(IDC_YESTOALL, OnYestoall)
	ON_BN_CLICKED(IDC_NOTOALL, OnNotoall)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CDDRDlg::OnYes() 
{
	m_enDDR = DDR_WITHFILE;
	m_bDontAskAgain = IsDlgButtonChecked (IDC_DONTASKAGAIN) == BST_CHECKED;
	EndDialog (IDOK);
}

void CDDRDlg::OnNo() 
{
	m_enDDR = DDR_FROMLISTONLY;
	m_bDontAskAgain = IsDlgButtonChecked (IDC_DONTASKAGAIN) == BST_CHECKED;
	EndDialog (IDOK);
}

BOOL CDDRDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	((CStatic*) GetDlgItem (IDC_DLGICON))->SetIcon (LoadIcon (NULL, IDI_QUESTION));
	
	
	CString str;
	str.Format ("%s\r\n \"%s\"\r\n%s", LS (L_DOWNLOAD2), m_strUrl, LS (L_WBDELETED));
	SetDlgItemText (IDC_MESSAGE, str);

	if (m_bNoCancel)
		GetDlgItem (IDCANCEL)->EnableWindow (FALSE);

	ApplyLanguage ();
	
	return TRUE; 
}

void CDDRDlg::OnContextMenu(CWnd* , CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();
}

void CDDRDlg::OnWhatisthis() 
{
	_CHMgr.OnWT ();	
}

void CDDRDlg::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_DONTASKAGAIN, L_DONTASKAGAIN),
		fsDlgLngInfo (IDC_YES, L_YES),
		fsDlgLngInfo (IDC_YESTOALL, L_YESTOALL),
		fsDlgLngInfo (IDC_NO2, L_NO),
		fsDlgLngInfo (IDC_NOTOALL, L_NOTOALL),
		fsDlgLngInfo (IDCANCEL, L_CANCEL),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_ASKUSER);
}

BOOL CDDRDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
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

void CDDRDlg::PrepareCHMgr(CPoint point)
{
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC_DONTASKAGAIN, LS (L_DONTASKAGAINHERE)),
		fsCtrlContextHelp (IDC_YES, LS (L_YES)),
		fsCtrlContextHelp (IDC_YESTOALL, LS (L_YESTOALL)),
		fsCtrlContextHelp (IDC_NO_, LS (L_NO)),
		fsCtrlContextHelp (IDC_NOTOALL, LS (L_NOTOALL)),
		fsCtrlContextHelp (IDCANCEL, LS (L_CANCEL)),
	};

    static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));
}

void CDDRDlg::OnYestoall() 
{
	m_enDDR = DDR_WITHFILE;
	m_bDontAskAgain = IsDlgButtonChecked (IDC_DONTASKAGAIN) == BST_CHECKED;
	m_bForAll = TRUE;
	EndDialog (IDOK);
}

void CDDRDlg::OnNotoall() 
{
	m_enDDR = DDR_FROMLISTONLY;
	m_bDontAskAgain = IsDlgButtonChecked (IDC_DONTASKAGAIN) == BST_CHECKED;
	m_bForAll = TRUE;
	EndDialog (IDOK);
}

void CDDRDlg::OnClose() 
{
	if (m_bNoCancel == FALSE)
		CDialog::OnClose();
}
