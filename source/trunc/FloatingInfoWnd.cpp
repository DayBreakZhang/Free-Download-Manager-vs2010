/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "FloatingInfoWnd.h"
#include "DownloadsWnd.h"
#include "vmsLogger.h"

extern CDownloadsWnd* _pwndDownloads;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CFloatingInfoWnd, CFrameWnd)

CFloatingInfoWnd::CFloatingInfoWnd()
{
	m_cxPercent = 0;
	m_cxSpeed = 0;
	m_bNeedToShow = FALSE;
	m_bWasFS = FALSE;
	m_bHideAlways = FALSE;
}

CFloatingInfoWnd::~CFloatingInfoWnd()
{
}

BEGIN_MESSAGE_MAP(CFloatingInfoWnd, CFrameWnd)
	//{{AFX_MSG_MAP(CFloatingInfoWnd)
	ON_WM_CREATE()
	ON_WM_CLOSE()
	ON_WM_SIZE()
	ON_WM_GETMINMAXINFO()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

int CFloatingInfoWnd::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	m_drop.Register (this);

	CRect rc (0, 0, 50, 50);

	if (FALSE == m_wndList.Create (LVS_REPORT|LVS_NOCOLUMNHEADER|LVS_OWNERDRAWFIXED, 
				rc, this, 0x76329))
		return FALSE;

	m_imgsList.Create (13, 13, ILC_MASK | ILC_COLOR24, 2, 1);
	CBitmap bmp; bmp.Attach (SBMP (IDB_DLDSINFO));
	m_imgsList.Add (&bmp, RGB (255, 0, 255));
	m_wndList.SetImageList (&m_imgsList, LVSIL_SMALL);

	m_imgsList_sel.Create (13, 13, ILC_MASK | ILC_COLOR24, 2, 1);
	CBitmap bmp2; bmp2.Attach (SBMP (IDB_DLDSINFO_SEL));
	m_imgsList_sel.Add (&bmp2, RGB (255, 0, 255));
	m_wndList.SetSelectedImages (&m_imgsList_sel);

	m_wndList.SetExtendedStyle (LVS_EX_FULLROWSELECT|LVS_EX_INFOTIP);

	m_wndList.InsertColumn (0, "", LVCFMT_LEFT, 100, 0);
	m_wndList.InsertColumn (1, "", LVCFMT_RIGHT, 50, 0);
	m_wndList.InsertColumn (2, "", LVCFMT_RIGHT, 50, 0);

	m_wndList.Initialize ();

	m_wndList.ShowWindow (SW_SHOW);

	m_cxPercent = m_wndList.GetStringWidth ("100%") + 5;
	m_cxSpeed = m_wndList.GetStringWidth ("9999.9 KB/s") + 5;

	SetTimer (1, 1000, NULL);
	SetTimer (2, 500, NULL);
	
	return 0;
}

BOOL CFloatingInfoWnd::Create()
{
	

	
	RECT rcWA;
	SystemParametersInfo (SPI_GETWORKAREA, 0, &rcWA, FALSE);
	RECT rc = {rcWA.right - 1 - 150, rcWA.bottom - 1 - 100, rcWA.right - 1, rcWA.bottom - 1};

	DWORD dwLStyle = fsSysGetOsMajorVersion () < 5 ? 0 : WS_EX_LAYERED;

	if (FALSE == CFrameWnd::CreateEx (WS_EX_TOPMOST|WS_EX_TOOLWINDOW|dwLStyle, 
			AfxRegisterWndClass (CS_DBLCLKS, LoadCursor (NULL, IDC_ARROW),	(HBRUSH)(COLOR_WINDOW+1), NULL), 
			LS (L_ACTIVEDLDS), 
			WS_OVERLAPPED|WS_CLIPSIBLINGS|WS_SYSMENU|WS_THICKFRAME, 
			rc, NULL, 0))
		return FALSE;

	SetBlend (_App.DownloadsInfoWndBlend ());

	

	_App.View_ReadWndPlacement (this, "FloatingInfoWnd", fsAppSettings::RWPA_FORCE_SWHIDE);

	

	return TRUE;
}

void CFloatingInfoWnd::OnClose() 
{
	TurnOffWindow ();
}

void CFloatingInfoWnd::OnSize(UINT , int cx, int cy) 
{
	m_wndList.MoveWindow (0, 0, cx, cy);

	m_cxPercent = m_wndList.GetStringWidth ("100%") + 5;
	m_cxSpeed = m_wndList.GetStringWidth ("9999.9 KB/s") + 5;
	
	m_wndList.SetColumnWidth (0, cx - m_cxPercent - m_cxSpeed );
	m_wndList.SetColumnWidth (1, m_cxPercent);
	m_wndList.SetColumnWidth (2, m_cxSpeed);
}

void CFloatingInfoWnd::OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI) 
{
	CFrameWnd::OnGetMinMaxInfo(lpMMI);
	lpMMI->ptMinTrackSize.x = m_cxPercent + m_cxSpeed + 10 + GetSystemMetrics (SM_CXVSCROLL) + 
		2 * GetSystemMetrics (SM_CXBORDER);
	lpMMI->ptMinTrackSize.y = 30;
}

void CFloatingInfoWnd::RebuildList()
{
	if (IsWindow (m_wndList) == FALSE)
		return;

	bool bDownloading = false;

	m_mxList.Lock ();

	m_wndList.DeleteAllItems ();

	try
	{
		DLDS_LIST vAddToList, v;

		_DldsMgr.LockList (true);
		size_t nCount = _DldsMgr.GetCount ();
		for (size_t i = 0; i < nCount; i++)
		{
			vmsDownloadSmartPtr dld = _DldsMgr.GetDownload (i);
			if (dld->pMgr->IsRunning ())
			{
				bDownloading = true;
				vAddToList.push_back (dld);
			}
			if (dld->pMgr->IsBittorrent () && 
					dld->pMgr->GetBtDownloadMgr ()->GetUploadSpeed ())
			{
				v.push_back (dld);
			}
		}
		_DldsMgr.UnlockList (true);

		for (size_t i = 0; i < vAddToList.size (); i++)
			AddDownloadToList (vAddToList [i], false);

		for (size_t i = 0; i < v.size (); i++)
			AddDownloadToList (v [i], true);

	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CFloatingInfoWnd::RebuildList " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CFloatingInfoWnd::RebuildList unknown exception");
	}
	
	m_mxList.Unlock ();

	if (m_bNeedToShow && (m_wndList.GetItemCount () == 0 || bDownloading == false))
		NeedToShow (FALSE);
}

void CFloatingInfoWnd::AddDownloadToList(vmsDownloadSmartPtr dld, bool bUploadInfo)
{
	char szFile [MY_MAX_PATH];
	CDownloads_Tasks::GetFileName (dld, szFile);

	m_mxList.Lock ();

	int iItem = m_wndList.GetItemCount ();

	m_wndList.AddItem (szFile, GetSysColor (COLOR_WINDOW), 
		GetSysColor (COLOR_WINDOWTEXT), bUploadInfo ? 1 : 0);
	m_wndList.SetItemData (iItem, (ULONG)(fsDownload*)dld);

	m_mxList.Unlock ();

	UpdateDownloadProgress (iItem);
	UpdateDownloadSpeed (iItem);
}

void CFloatingInfoWnd::UpdateDownloadProgress(int nItem)
{
	try
	{
		CString str;
		bool bUpload = m_wndList.GetItemImage (nItem) == 1;
		if (bUpload == false)
		{
			const int nPercentDone = (int)((fsDownload*) m_wndList.GetItemData (nItem))->pMgr->GetPercentDone ();
			if (nPercentDone == -1)
			{
				UINT64 uDone = (int)((fsDownload*) m_wndList.GetItemData (nItem))->pMgr->GetDownloadedBytesCount ();
				float val;
				char szDim [10];
				BytesToXBytes (uDone, &val, szDim);
				str.Format ("%.*g %s", val > 999 ? 4 : 3, val, szDim);
			}
			else
				str.Format ("%d%%", nPercentDone);
		}
		m_wndList.SetItemText (nItem, 1, str);
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CFloatingInfoWnd::UpdateDownloadProgress " + tstring(ex.what()));
	}
	catch (...)
	{
		vmsLogger::WriteLog("CFloatingInfoWnd::UpdateDownloadProgress unknown exception");
	}
}

int CFloatingInfoWnd::FindIndex(vmsDownloadSmartPtr dld)
{
	LVFINDINFO fi;

	fi.flags = LVFI_PARAM;
	fi.lParam = (LPARAM)(fsDownload*) dld;

	return m_wndList.FindItem (&fi);
}

void CFloatingInfoWnd::OnTimer(UINT nIDEvent) 
{
	if (nIDEvent == 2)
	{
		KillTimer (2);
		RebuildList ();
		return;
	}
	
	try 
	{
		for (int i = 0; i < m_wndList.GetItemCount (); i++)
		{
			UpdateDownloadProgress (i);
			UpdateDownloadSpeed (i);
		}
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CFloatingInfoWnd::OnTimer " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CFloatingInfoWnd::OnTimer unknown exception");
	}

	BOOL bFS = fsIsSystemInFullScreenMode ();	
	if (!m_bWasFS != !bFS) 
	{
		

		m_bWasFS = bFS;	
		
		

		if (bFS && IsWindowVisible () && _App.FloatingWndsHideInFSMode ())
			ShowWindow (SW_HIDE);
		else if (bFS == FALSE && m_bNeedToShow && IsWindowVisible () == FALSE && m_bHideAlways == FALSE)
			ShowWindow (SW_SHOW);
	}
	
	CFrameWnd::OnTimer(nIDEvent);
}

void CFloatingInfoWnd::SaveState()
{
	_App.View_SaveWndPlacement (this, "FloatingInfoWnd");
}

void CFloatingInfoWnd::NeedToShow(BOOL b)
{
	b = b && m_bHideAlways == FALSE;

	m_bNeedToShow = b;
	
	if (b == FALSE || fsIsSystemInFullScreenMode () == FALSE || _App.FloatingWndsHideInFSMode () == FALSE)
		ShowWindow (b ? SW_SHOW : SW_HIDE);
}

void CFloatingInfoWnd::UpdateDownloadSpeed(int nItem)
{
	try
	{
		CString str;
		CHAR szDim [10];
		float val;

		bool bUpload = m_wndList.GetItemImage (nItem) == 1;

		fsDownload *dld = (fsDownload*)m_wndList.GetItemData (nItem);

		BytesToXBytes (bUpload ? dld->pMgr->GetBtDownloadMgr ()->GetUploadSpeed () : 
			dld->pMgr->GetSpeed (), &val, szDim);
		str.Format ("%.*g %s/s", val > 999 ? 4 : 3, val, szDim);
		m_wndList.SetItemText (nItem, 2, str);
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CFloatingInfoWnd::UpdateDownloadSpeed " + tstring(ex.what()));
	}
	catch (...)
	{
		
		vmsLogger::WriteLog("CFloatingInfoWnd::UpdateDownloadSpeed unknown exception");
	}
}

void CFloatingInfoWnd::TurnOffWindow()
{
	_App.View_FloatingInfoWindow (FALSE);
	NeedToShow (FALSE);
	ShowWindow (SW_HIDE);
}

void CFloatingInfoWnd::SetBlend (BYTE val)
{
	m_blend = val;
	if (fsSysGetOsMajorVersion () >= 5)
		fsSetLayeredWindowAttributes (m_hWnd, 0, m_blend, LWA_ALPHA);
}

void CFloatingInfoWnd::HideAlways()
{
	m_bHideAlways = TRUE;
	NeedToShow (FALSE);
}
