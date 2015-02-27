/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "WndLog.h"
#include "fsEventsMgr.h"
#include "misc.h"
#include "fsODMenu.h"
#include "resource.h"
#include "CoreDll.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CWndLog::CWndLog()
{
	m_bAutoScroll = TRUE;
	m_pEvMgr = NULL;
}

CWndLog::~CWndLog()
{
}

BEGIN_MESSAGE_MAP(CWndLog, CListCtrlEx)
	//{{AFX_MSG_MAP(CWndLog)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_AUTOSCROLL, OnAutoscroll)
	ON_COMMAND(ID_CLEAR, OnClear)
	ON_WM_MEASUREITEM()
	ON_WM_DRAWITEM()
	ON_COMMAND(ID_COPY_TO_CB, OnCopyToCb)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CWndLog::Create(CWnd *pParent)
{
	CRect rc (0, 0, 50, 50);

	if (FALSE == CListCtrl::Create (LVS_REPORT|LVS_NOSORTHEADER|LVS_SHOWSELALWAYS|LVS_OWNERDRAWFIXED, rc, pParent, 0x76329))
		return FALSE;

	SetExtendedStyle (LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP);

	

	m_images.Create (16, 15, ILC_COLOR24 | ILC_MASK, 6, 1);
	CBitmap bmp;
	bmp.Attach (_pDllCaller->GetBitmap (BMP_FOR_LOGLIST));
	m_images.Add (&bmp, RGB (255, 0, 255));
	SetImageList (&m_images, LVSIL_SMALL);

	InsertColumn (0, "Time", LVCFMT_LEFT, 80, 0);
	InsertColumn (1, "Date", LVCFMT_LEFT, 100, 0);
	InsertColumn (2, "Information", LVCFMT_LEFT, 400, 0);

	ShowWindow (SW_SHOW);

	return TRUE;
}

void CWndLog::AddRecord(fsDescEvent *event)
{
	SYSTEMTIME time;
	CHAR strTime [1000], strDate [1000];

	FileTimeToSystemTime (&event->timeEvent, &time);

	SystemTimeToStr (&time, strDate, strTime);

	int iItem = AddItem (strTime, event->clrBg, event->clrText, event->iImage);
	SetItemText (iItem, 1, strDate);
	SetItemText (iItem, 2, event->pszEvent);

	if (m_bAutoScroll)
		EnsureVisible (iItem, FALSE);
}

void CWndLog::OnRClick()
{
	AFX_MANAGE_STATE (AfxGetStaticModuleState ());

	CMenu menu;
	menu.LoadMenu (IDM_LOG);
	CMenu *pPopup = menu.GetSubMenu (0);
	ApplyLanguageToMenu (pPopup);

	if (m_bAutoScroll)
		pPopup->CheckMenuItem (ID_AUTOSCROLL, MF_CHECKED | MF_BYCOMMAND);

	if (GetItemCount () == 0)
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

void CWndLog::OnRButtonDown(UINT nFlags, CPoint point) 
{
	m_rbPt = point;
	
	CListCtrlEx::OnRButtonDown(nFlags, point);
}

void CWndLog::OnAutoscroll() 
{
	m_bAutoScroll = !m_bAutoScroll;	
}

void CWndLog::OnClear()
{
	DeleteAllItems ();
	if (m_pEvMgr)
		m_pEvMgr->clear ();
}

void CWndLog::OnMeasureItem(int , LPMEASUREITEMSTRUCT lpMeasureItemStruct) 
{
	m_odmenu.OnMeasureItem (lpMeasureItemStruct);
}

void CWndLog::OnDrawItem(int , LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	m_odmenu.OnDrawItem (lpDrawItemStruct);
}

void CWndLog::ApplyLanguage()
{
	SetColumnText (0, LS (L_TIME));
	SetColumnText (1, LS (L_DATE));
	SetColumnText (2, LS (L_INFORMATION));
}

void CWndLog::ApplyLanguageToMenu(CMenu *menu)
{
	menu->ModifyMenu (ID_CLEAR, MF_BYCOMMAND|MF_STRING, ID_CLEAR, LS (L_CLEAR));
	menu->ModifyMenu (ID_COPY_TO_CB, MF_BYCOMMAND|MF_STRING, ID_COPY_TO_CB, LS (L_COPYTOCB));
	menu->ModifyMenu (ID_AUTOSCROLL, MF_BYCOMMAND|MF_STRING, ID_AUTOSCROLL, LS (L_AUTOSCROLL));
}

void CWndLog::OnKeyDown(WORD wVK)
{
	switch (wVK)
	{
		case VK_APPS:
			CalcCoordsForCurSel ();
			OnRClick ();
			break;
	}
}

void CWndLog::CalcCoordsForCurSel()
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

void CWndLog::OnForceUpdate()
{
	DeleteAllItems ();

	if (m_pEvMgr)
	{
		int cEvents = m_pEvMgr->GetEventCount ();
		for (int i = 0; i < cEvents; i++)
			AddRecord (m_pEvMgr->GetEvent (i));	
	}
}

void CWndLog::SetEvMgr(fsEventsMgr *mgr)
{
	m_pEvMgr = mgr;
}

void CWndLog::OnCopyToCb() 
{
	SYSTEMTIME time;
	CHAR strTime [1000], strDate [1000];

	CString strText;

	for (UINT i = 0; i < m_pEvMgr->GetEventCount (); i++)
	{
		fsDescEvent* event = m_pEvMgr->GetEvent (i);

		FileTimeToSystemTime (&event->timeEvent, &time);
		SystemTimeToStr (&time, strDate, strTime);

		strText += strTime; strText += ' '; 
		strText += strDate; strText += ' ';
		strText += event->pszEvent;
		strText += "\r\n";
	}

	fsSetClipboardText (m_hWnd, strText);
}
