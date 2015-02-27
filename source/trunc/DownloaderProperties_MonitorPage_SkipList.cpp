/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "DownloaderProperties_MonitorPage_SkipList.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDownloaderProperties_MonitorPage_SkipList::CDownloaderProperties_MonitorPage_SkipList(CWnd* pParent )
	: CDialog(CDownloaderProperties_MonitorPage_SkipList::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDownloaderProperties_MonitorPage_SkipList)
		
	//}}AFX_DATA_INIT
}

void CDownloaderProperties_MonitorPage_SkipList::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDownloaderProperties_MonitorPage_SkipList)
		
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDownloaderProperties_MonitorPage_SkipList, CDialog)
	//{{AFX_MSG_MAP(CDownloaderProperties_MonitorPage_SkipList)
	ON_WM_HELPINFO()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	ON_WM_CONTEXTMENU()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDownloaderProperties_MonitorPage_SkipList::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	SetDlgItemText (IDC_EXTS, _App.Monitor_SkipExts ());
	SetDlgItemText (IDC_SERVERS, _App.Monitor_SkipServers ());

	ApplyLanguage ();
	
	return TRUE;  
	              
}

void CDownloaderProperties_MonitorPage_SkipList::OnOK() 
{
	CString str;
	GetDlgItemText (IDC_EXTS, str);
	_App.Monitor_SkipExts (str);

	GetDlgItemText (IDC_SERVERS, str);
	str.Replace ("\r\n", " ");
	str.Replace ("\r", " ");
	str.Replace ("\n", " ");
	str.Replace ("http://", "");
	str.Replace ("https://", "");
	str.Replace ("ftp://", "");
	_App.Monitor_SkipServers (str);
	
	CDialog::OnOK();
}

void CDownloaderProperties_MonitorPage_SkipList::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_SKIPEXTS, L_SKIPFILESWITHEXTS),
		fsDlgLngInfo (IDC__SKIPSERVERS, L_SKIPSERVERS),
		fsDlgLngInfo (IDCANCEL, L_CANCEL),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_SKIPLIST);
}

void CDownloaderProperties_MonitorPage_SkipList::PrepareCHMgr(CPoint point)
{
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC_SKIPEXTS, LS (L_SKIPFILESWITHEXTSHERE)),
		fsCtrlContextHelp (IDC_EXTS, LS (L_SKIPFILESWITHEXTSHERE)),
		fsCtrlContextHelp (IDC__SKIPSERVERS, LS (L_SKIPSERVERS_HERE)),
		fsCtrlContextHelp (IDC_SERVERS, LS (L_SKIPSERVERS_HERE)),
	};

    static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));
}

BOOL CDownloaderProperties_MonitorPage_SkipList::OnHelpInfo(HELPINFO* pHelpInfo) 
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

void CDownloaderProperties_MonitorPage_SkipList::OnWhatisthis() 
{
	_CHMgr.OnWT ();	
}

void CDownloaderProperties_MonitorPage_SkipList::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();	
}
