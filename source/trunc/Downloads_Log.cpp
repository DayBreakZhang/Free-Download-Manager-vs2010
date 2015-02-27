/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Downloads_Log.h"
#include "DownloadsWnd.h"
#include "vmsLogger.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDownloads_Log::CDownloads_Log()
{
	m_bAutoScroll = TRUE;
	m_pActiveDownload = NULL;
}

CDownloads_Log::~CDownloads_Log()
{
}

BEGIN_MESSAGE_MAP(CDownloads_Log, CListCtrlEx)
	//{{AFX_MSG_MAP(CDownloads_Log)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_AUTOSCROLL, OnAutoscroll)
	ON_COMMAND(ID_CLEAR, OnClear)
	ON_WM_DRAWITEM()
	ON_WM_MEASUREITEM()
	ON_COMMAND(ID_COPY_TO_CB, OnCopyToCb)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDownloads_Log::Create(CWnd *pParent)
{
	CRect rc (0, 0, 50, 50);

	if (FALSE == CListCtrlEx::Create (LVS_REPORT|LVS_OWNERDRAWFIXED|LVS_NOSORTHEADER,
									  rc, pParent, 0x56789))
		return FALSE;

	SetExtendedStyle (LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP);

	InsertColumn (0, "Time", LVCFMT_LEFT, 85, 0);
	InsertColumn (1, "Date", LVCFMT_LEFT, 70, 0);
	InsertColumn (2, "Information", LVCFMT_LEFT, 300, 0);

	m_images.Create (16, 15, ILC_COLOR24 | ILC_MASK, 6, 1);
	CBitmap bmp;
	bmp.Attach (SBMP (IDB_LOGSTATES));
	m_images.Add (&bmp, RGB (255, 0, 255));
	SetImageList (&m_images, LVSIL_SMALL);

	ReadState ("DownloadsLog");

	ShowWindow (SW_SHOW);

	return TRUE;
}

void CDownloads_Log::AddRecord(fsDownloadEvents *event)
{
	SYSTEMTIME time;
	CHAR strTime [1000], strDate [1000];

	FileTimeToSystemTime (&event->timeEvent, &time);

	
	SystemTimeToStr (&time, strDate, strTime);

	char szEv [10000];
	LPCSTR pszEvent = event->strEvent;
	LPCSTR pszEv2 = pszEvent;

	int iItem = 0;
	BOOL bFirst = TRUE;

	
	while (pszEvent)
	{
		
		pszEvent = strstr (pszEvent, "\r\n");
		if (pszEvent)
		{
			
			strncpy (szEv, pszEv2, pszEvent - pszEv2);
			szEv [pszEvent - pszEv2] = 0;
			if (*szEv)
			{
				
				iItem = AddItem (bFirst ? strTime : "", event->clrBg, event->clrText, bFirst ? event->iImage : -1);
				SetItemText (iItem, 1, bFirst ? strDate : "");
				SetItemText (iItem, 2, szEv);
			}
			
			pszEvent += 2;
			pszEv2 = pszEvent;
			bFirst = FALSE;
		}
	}

	
	
	if (*pszEv2)
	{
		iItem = AddItem (bFirst ? strTime : "", event->clrBg, event->clrText, bFirst ? event->iImage : -1);
		if (bFirst)
			SetItemText (iItem, 1, strDate);
		SetItemText (iItem, 2, pszEv2);
	}

	if (m_bAutoScroll)
		EnsureVisible (iItem, FALSE);
}

void CDownloads_Log::SetActiveDownload(vmsDownloadSmartPtr dld)
{
	DeleteAllItems ();

	m_pActiveDownload = dld;

	if (dld == NULL)
		return;

	int cEvs = dld->vEvents.size ();

	BOOL b = cEvs > 100 && IsWindowVisible (); 
	if (b)
		ShowWindow (SW_HIDE);

	try 
	{
		
		for (int i = 0; i < cEvs; i++)
			AddRecord (&dld->vEvents [i]);
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CDownloads_Log::SetActiveDownload " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CDownloads_Log::SetActiveDownload unknown exception");
	}

	if (b)
		ShowWindow (SW_SHOW);
}

void CDownloads_Log::OnRClick()
{
	CMenu menu;
	menu.LoadMenu (IDM_LOG);
	CMenu *pPopup = menu.GetSubMenu (0);
	ApplyLanguageToMenu (&menu);

	if (m_bAutoScroll)
		pPopup->CheckMenuItem (ID_AUTOSCROLL, MF_CHECKED | MF_BYCOMMAND);

	if (m_pActiveDownload == NULL || m_pActiveDownload->vEvents.size () == 0)
	{
		pPopup->EnableMenuItem (ID_CLEAR, MF_BYCOMMAND | MF_GRAYED);
		pPopup->EnableMenuItem (ID_COPY_TO_CB, MF_BYCOMMAND | MF_GRAYED);
	}

	ClientToScreen (&m_rbPt);

	m_odmenu.Attach (&menu, FALSE);
	pPopup->TrackPopupMenu (TPM_RIGHTBUTTON | TPM_TOPALIGN | TPM_LEFTALIGN,	m_rbPt.x, m_rbPt.y, this);
	m_odmenu.Detach ();

	menu.DestroyMenu ();
}

void CDownloads_Log::OnRButtonDown(UINT nFlags, CPoint point) 
{
	m_rbPt = point;
	
	CListCtrlEx::OnRButtonDown(nFlags, point);
}

void CDownloads_Log::OnAutoscroll() 
{
	m_bAutoScroll = !m_bAutoScroll;	
}

void CDownloads_Log::OnClear() 
{
	m_pActiveDownload->vEvents.clear ();
	
	m_pActiveDownload->isDirty();
	DeleteAllItems ();
}

void CDownloads_Log::OnDrawItem(int , LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	m_odmenu.OnDrawItem (lpDrawItemStruct);
}

void CDownloads_Log::OnMeasureItem(int , LPMEASUREITEMSTRUCT lpMeasureItemStruct) 
{
	m_odmenu.OnMeasureItem (lpMeasureItemStruct);
}

void CDownloads_Log::ApplyLanguage()
{
	SetColumnText (0, LS (L_TIME));
	SetColumnText (1, LS (L_DATE));
	SetColumnText (2, LS (L_INFORMATION));
}

void CDownloads_Log::ApplyLanguageToMenu(CMenu *menu)
{
	menu->ModifyMenu (ID_CLEAR, MF_BYCOMMAND|MF_STRING, ID_CLEAR, LS (L_CLEAR));
	menu->ModifyMenu (ID_COPY_TO_CB, MF_BYCOMMAND|MF_STRING, ID_COPY_TO_CB, LS (L_COPYTOCB));
	menu->ModifyMenu (ID_AUTOSCROLL, MF_BYCOMMAND|MF_STRING, ID_AUTOSCROLL, LS (L_AUTOSCROLL));
}

void CDownloads_Log::OnKeyDown(WORD wVK)
{
	switch (wVK)
	{
		case VK_APPS:
			CalcCoordsForCurSel ();
			OnRClick ();
			break;
	}
}

void CDownloads_Log::CalcCoordsForCurSel()
{
	int iCurSel = GetSelectionMark ();
	if (iCurSel == -1)
	{
		POSITION pos = GetFirstSelectedItemPosition ();
		if (pos)
			iCurSel = GetNextSelectedItem (pos);
	}

	if (iCurSel != -1)
	{
		RECT rc;
		GetItemRect (iCurSel, &rc, LVIR_BOUNDS);
		m_rbPt.x = rc.left + 30;
		m_rbPt.y = rc.top;
	}
	else
		m_rbPt.x = m_rbPt.y = 30;
}

void CDownloads_Log::OnForceUpdate()
{
	SetActiveDownload (m_pActiveDownload);
}

void CDownloads_Log::OnCopyToCb() 
{
	SYSTEMTIME time;
	CHAR strTime [1000], strDate [1000];

	CString strText;

	for (int i = 0; i < m_pActiveDownload->vEvents.size (); i++)
	{
		fsDownloadEvents* event = &m_pActiveDownload->vEvents [i];

		FileTimeToSystemTime (&event->timeEvent, &time);
		SystemTimeToStr (&time, strDate, strTime);

		strText += strTime; strText += ' '; 
		strText += strDate; strText += ' ';
		strText += event->strEvent;
		strText += "\r\n";
	}

	_ClipbrdMgr.Text (strText);	
}
