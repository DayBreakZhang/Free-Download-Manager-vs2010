/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "DownloadProperties_MirrorsPage.h"
#include "WaitDlg.h"
#include "UrlWithLoginDlg.h"
#include "inetutil.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CDownloadProperties_MirrorsPage, CPropertyPage)

CDownloadProperties_MirrorsPage::CDownloadProperties_MirrorsPage() : CPropertyPage(CDownloadProperties_MirrorsPage::IDD)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = LS (L_MIRRORS);
}

CDownloadProperties_MirrorsPage::~CDownloadProperties_MirrorsPage()
{
}

void CDownloadProperties_MirrorsPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDownloadProperties_MirrorsPage)
	DDX_Control(pDX, IDC_MIRRS, m_wndMirrs);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDownloadProperties_MirrorsPage, CPropertyPage)
	//{{AFX_MSG_MAP(CDownloadProperties_MirrorsPage)
	ON_WM_CONTEXTMENU()
	ON_WM_HELPINFO()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	ON_BN_CLICKED(IDC_CALCMIRRSPEED, OnCalcmirrspeed)
	ON_BN_CLICKED(IDC_ADDMIRROR, OnAddmirror)
	ON_BN_CLICKED(IDC_FINDMIRRORS, OnFindmirrors)
	ON_NOTIFY(NM_CLICK, IDC_MIRRS, OnClickMirrs)
	ON_NOTIFY(LVN_KEYDOWN, IDC_MIRRS, OnKeydownMirrs)
	ON_BN_CLICKED(IDC_REMOVE, OnRemove)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDownloadProperties_MirrorsPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();

	RECT rc;
	m_wndMirrs.GetClientRect (&rc);
	m_wndMirrs.InsertColumn (0, LS (L_MIRRURLS), LVCFMT_LEFT, rc.right - 50-90 - 
		GetSystemMetrics (SM_CXVSCROLL) - 1);
	m_wndMirrs.InsertColumn (1, LS (L_SERVSPEED), LVCFMT_LEFT, 90);
	m_wndMirrs.InsertColumn (2, LS (L_ISUSED), LVCFMT_LEFT, 50);
	m_wndMirrs.SetExtendedStyle (LVS_EX_FULLROWSELECT | LVS_EX_INFOTIP);

	fsInternetDownloader* dldr = m_dld->pMgr->GetDownloadMgr ()->GetDownloader ();

	FillMirrsList ();

	UpdateMirrSpeed ();
	UpdateMirrUsing ();

	if (dldr->GetMirrorURLCount () == 0)
		GetDlgItem (IDC_CALCMIRRSPEED)->EnableWindow (FALSE);

	if (dldr->IsMirrSearchPerformed ())
		GetDlgItem (IDC_FINDMIRRORS)->EnableWindow (FALSE);
	
	ApplyLanguage ();
	UpdateEnabled ();
	
	return TRUE;
}

void CDownloadProperties_MirrorsPage::OnContextMenu(CWnd* , CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();	
}

BOOL CDownloadProperties_MirrorsPage::OnHelpInfo(HELPINFO* pHelpInfo) 
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

void CDownloadProperties_MirrorsPage::OnWhatisthis() 
{
	_CHMgr.OnWT ();	
}

void CDownloadProperties_MirrorsPage::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_ADDMIRROR, L_ADD),
		fsDlgLngInfo (IDC_REMOVE, L_REMOVE),
		fsDlgLngInfo (IDC_FINDMIRRORS, L_FINDMIRROR),
		fsDlgLngInfo (IDC_CALCMIRRSPEED, L_CALCMIRRSSPEED),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}

void CDownloadProperties_MirrorsPage::PrepareCHMgr(CPoint point)
{
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC_ADDMIRROR, LS (L_ADDMIRRORHERE)),
		fsCtrlContextHelp (IDC_FINDMIRRORS, LS (L_FINDMIRRORHERE)),
		fsCtrlContextHelp (IDC_CALCMIRRSPEED, LS (L_CALCMIRRSSPEEDHERE)),
	};

    static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));
}

void CDownloadProperties_MirrorsPage::UpdateMirrSpeed()
{
	fsInternetDownloader *dldr = m_dld->pMgr->GetDownloadMgr ()->GetDownloader ();

	DWORD dwBasePing = dldr->Get_BaseServerPingTime ();
	if (dwBasePing == UINT_MAX)
	{
		for (int i = 0; i < dldr->GetMirrorURLCount (); i++)
			dwBasePing = min (dwBasePing, dldr->GetMirrorPingTime (i));
	}
	
	double fBasePing = dwBasePing;

	for (int i = 0; i < dldr->GetMirrorURLCount (); i++)
	{
		UINT uPT = dldr->GetMirrorPingTime (i);
		CString str;
		if (uPT)
		{
			if (uPT != UINT_MAX)
			{
				str.Format ("%.*g", 3, fBasePing / double (uPT) * 100.0);
				str += "%";
			}
			else
				str = LS (L_UNKNOWN);
		}
		else
			str = "local";
		m_wndMirrs.SetItemText (i, 1, str);
	}
}

void CDownloadProperties_MirrorsPage::UpdateMirrUsing()
{
	fsInternetDownloader *dldr = m_dld->pMgr->GetDownloadMgr ()->GetDownloader ();

	for (int i = 0; i < dldr->GetMirrorURLCount (); i++)
	{
		int cRefs = dldr->GetMirrorRefs (i);
		CString str = "";
		if (cRefs)
			str.Format ("%d", cRefs);
		m_wndMirrs.SetItemText (i, 2, str);
	}
}

void CDownloadProperties_MirrorsPage::OnCalcmirrspeed() 
{
	CWaitDlg dlg;
	dlg.StartWaiting (LS (L_CALCULATINGMIRRORSSPEED), _threadCalcMirrSpeed, TRUE, this);

	UpdateMirrSpeed ();
	UpdateMirrUsing ();
}

void CDownloadProperties_MirrorsPage::OnAddmirror() 
{
	CUrlWithLoginDlg dlg;
	
	_DlgMgr.OnDoModal (&dlg);
	UINT nRet = dlg.DoModal ();
	_DlgMgr.OnEndDialog (&dlg);

	if (nRet == IDCANCEL)
		return;

	m_dld->pMgr->GetDownloadMgr ()->GetDownloader ()->AddMirrorURL (dlg.m_strUrl, 
		dlg.m_strUser, dlg.m_strPassword);

	

	

	FullUpdateMirrList ();
	CancelToClose ();
}

void CDownloadProperties_MirrorsPage::OnFindmirrors() 
{
	if (m_dld->pMgr->GetDownloadMgr ()->GetDownloader ()->IsMirrSearchPerformed ())
	{
		MessageBox (LS (L_MIRRSEARCHPERFORMEDALREADY), LS (L_DONE), MB_ICONEXCLAMATION);
		return;
	}

	CWaitDlg dlg;
	dlg.StartWaiting (LS (L_SEARCHINGFORMIRRORS), _threadFindMirrors, TRUE, this);

	FullUpdateMirrList ();

	if (m_dld->pMgr->GetDownloadMgr ()->GetDownloader ()->GetFoundMirrorCount ())
	{
		char sz [10000];
		sprintf (sz, LS (L_NMIRRORSFOUND), m_dld->pMgr->GetDownloadMgr ()->GetDownloader ()->GetFoundMirrorCount ());
		MessageBox (sz, LS (L_DONE));
		CancelToClose ();
	}
	else
		MessageBox (LS (L_NOMIRRORSFOUND), LS (L_DONE));
}

void CDownloadProperties_MirrorsPage::CheckFileSizeKnown()
{
	if (m_dld->pMgr->GetDownloadMgr ()->IsRunning () == FALSE && m_dld->pMgr->GetDownloadMgr ()->IsDone () == FALSE && 
		m_dld->pMgr->GetDownloadMgr ()->IsQueringSize () == FALSE && 
		m_dld->pMgr->GetDownloadMgr ()->GetDownloader ()->GetNumberOfSections () == 0)
	{
		m_dld->pMgr->GetDownloadMgr ()->QuerySize2 ();
		while (m_dld->pMgr->GetDownloadMgr ()->IsQueringSize ())
			Sleep (10);
	}
}

DWORD WINAPI CDownloadProperties_MirrorsPage::_threadFindMirrors(LPVOID lp)
{
	ProcWaitInfo *info = (ProcWaitInfo*) lp;
	CDownloadProperties_MirrorsPage* pThis = (CDownloadProperties_MirrorsPage*) info->lpParam1;

	pThis->m_bNeedStop = FALSE;

	DWORD dwThread;
	HANDLE hThread = CreateThread (NULL, 0, _threadFindMirrors2, pThis, 0, &dwThread);

	DWORD dw;
	do 
	{
		dw = WaitForSingleObject (hThread, 500);

		if (info->bNeedStop)
		{
			pThis->m_bNeedStop = TRUE;

			if (pThis->m_dld->pMgr->GetDownloadMgr ()->IsQueringSize ())
				pThis->m_dld->pMgr->GetDownloadMgr ()->StopQuering ();
		
			pThis->m_dld->pMgr->GetDownloadMgr ()->StopDownloading ();

			break;
		}
	}
	while (dw == WAIT_TIMEOUT);

	if (dw == WAIT_TIMEOUT)
		WaitForSingleObject (hThread, INFINITE);

	CloseHandle (hThread);

	info->bWaitDone = TRUE;
	
	return 0;
}

DWORD WINAPI CDownloadProperties_MirrorsPage::_threadFindMirrors2(LPVOID lp)
{
	CDownloadProperties_MirrorsPage* pThis = (CDownloadProperties_MirrorsPage*) lp;

	pThis->CheckFileSizeKnown ();

	if (pThis->m_dld->pMgr->GetDownloadMgr ()->GetDownloader ()->GetSSFileSize () == UINT_MAX)
	{
		
	}

	if (pThis->m_bNeedStop)
		return 0;

	fsInternetResult ir = pThis->m_dld->pMgr->GetDownloadMgr ()->FindMirrors ();

	if (ir != IR_SUCCESS)
	{
		char szErr [10000];
		fsIRToStr (ir, szErr, sizeof (szErr));
		pThis->MessageBox (szErr, LS (L_ERR), MB_ICONERROR);
	}

	return 0;
}

void CDownloadProperties_MirrorsPage::FillMirrsList()
{
	fsInternetDownloader* dldr = m_dld->pMgr->GetDownloadMgr ()->GetDownloader ();

	m_wndMirrs.DeleteAllItems ();

	for (int i = 0; i < dldr->GetMirrorURLCount (); i++)
	{
		fsDownload_NetworkProperties *dnp = dldr->MirrorDNP (i);
		fsURL url;
		char szUrl [10000];
		DWORD dwLen = sizeof (szUrl);

		url.Create (fsNPToScheme (dnp->enProtocol), dnp->pszServerName,
			dnp->uServerPort, "", "", dnp->pszPathName, szUrl, &dwLen);

		m_wndMirrs.InsertItem (i, szUrl);
	}
}

DWORD WINAPI CDownloadProperties_MirrorsPage::_threadCalcMirrSpeed(LPVOID lp)
{
	ProcWaitInfo *info = (ProcWaitInfo*) lp;
	CDownloadProperties_MirrorsPage* pThis = (CDownloadProperties_MirrorsPage*) info->lpParam1;

	pThis->m_bNeedStop = FALSE;

	DWORD dwThread;
	HANDLE hThread = CreateThread (NULL, 0, _threadCalcMirrSpeed2, pThis, 0, &dwThread);

	DWORD dw;
	do 
	{
		dw = WaitForSingleObject (hThread, 500);

		if (info->bNeedStop)
		{
			pThis->m_dld->pMgr->GetDownloadMgr ()->StopDownloading ();
			break;
		}
	}
	while (dw == WAIT_TIMEOUT);

	if (dw == WAIT_TIMEOUT)
		WaitForSingleObject (hThread, INFINITE);

	CloseHandle (hThread);

	info->bWaitDone = TRUE;
	
	return 0;
}

DWORD WINAPI CDownloadProperties_MirrorsPage::_threadCalcMirrSpeed2(LPVOID lp)
{
	CDownloadProperties_MirrorsPage* pThis = (CDownloadProperties_MirrorsPage*) lp;

	if (pThis->m_bNeedStop)
		return 0;

	pThis->m_dld->pMgr->GetDownloadMgr ()->MeasureMirrorsSpeed ();

	return 0;
}

void CDownloadProperties_MirrorsPage::FullUpdateMirrList()
{
	FillMirrsList ();
	UpdateMirrSpeed ();
	UpdateMirrUsing ();

	if (m_dld->pMgr->GetDownloadMgr ()->GetDownloader ()->GetMirrorURLCount ())
		GetDlgItem (IDC_CALCMIRRSPEED)->EnableWindow (TRUE);

	UpdateEnabled ();
}

void CDownloadProperties_MirrorsPage::UpdateEnabled()
{
	GetDlgItem (IDC_REMOVE)->EnableWindow (m_wndMirrs.GetSelectedCount ());
}

void CDownloadProperties_MirrorsPage::OnClickMirrs(NMHDR* pNMHDR, LRESULT* pResult) 
{
	UpdateEnabled ();	
	*pResult = 0;
}

void CDownloadProperties_MirrorsPage::OnKeydownMirrs(NMHDR* pNMHDR, LRESULT* pResult) 
{
	LV_KEYDOWN* pLVKeyDow = (LV_KEYDOWN*)pNMHDR;

	if (pLVKeyDow->wVKey == VK_DELETE)
		OnRemove ();

	UpdateEnabled ();
	*pResult = 0;
}

void CDownloadProperties_MirrorsPage::OnRemove() 
{
	fs::list <int> v;
	POSITION pos = m_wndMirrs.GetFirstSelectedItemPosition ();
	while (pos)
		v.add (m_wndMirrs.GetNextSelectedItem (pos));

	BOOL bAllWasDeleted = TRUE;

	for (int i = v.size ()-1; i >= 0; i--)
	{
		if (m_dld->pMgr->GetDownloadMgr ()->GetDownloader ()->RemoveMirror (v [i]))
			m_wndMirrs.DeleteItem (v [i]);
		else
			bAllWasDeleted = FALSE;
	}

	CancelToClose ();
	UpdateEnabled ();

	if (bAllWasDeleted == FALSE)
		MessageBox ("Failed to remove mirros(s).\nPlease try again later.", "Failed", MB_OK | MB_ICONEXCLAMATION);
}
