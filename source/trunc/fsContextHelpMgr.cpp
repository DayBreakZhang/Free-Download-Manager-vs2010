/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "fsContextHelpMgr.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

fsContextHelpMgr::fsContextHelpMgr()
{
	m_bInWT = FALSE;
}

fsContextHelpMgr::~fsContextHelpMgr()
{

}

void fsContextHelpMgr::PrepareContextMenu(CDialog *pDlg, CPoint point, fsCtrlContextHelp* pCtrls, int cCtrls)
{
	m_pLastCtrls = pCtrls;
	m_cLastCtrls = cCtrls;
	m_pLastDlg = pDlg;
	m_ptLast = point;
	m_iLastCtrl = FindControl (point);

	if (m_iLastCtrl == -1)
		return;
}

int fsContextHelpMgr::FindControl(CPoint pt)
{
	for (int i = 0; i < m_cLastCtrls; i++)
	{
		CWnd* pCtrl = m_pLastDlg->GetDlgItem (m_pLastCtrls [i].nIDCtrl);
		
		if (pCtrl->IsWindowVisible () == FALSE) 
			continue;

		CRect rcCtrl;
		pCtrl->GetWindowRect (&rcCtrl);
		if (PtInRect (&rcCtrl, pt))
			return i;
	}

	return -1;
}

void fsContextHelpMgr::OnWT()
{
	if (m_bInWT)
		return;

	if (m_iLastCtrl == -1)
		return;

	m_bInWT = TRUE;

	HH_POPUP popup;
	ZeroMemory (&popup, sizeof (popup));

	popup.cbStruct = sizeof (popup);
	popup.pszText = m_pLastCtrls [m_iLastCtrl].pszDesc;
	popup.pt = m_ptLast;
	popup.clrForeground = UINT (-1);
	popup.clrBackground = UINT (-1);
	popup.rcMargins = CRect (-1, -1, -1, -1);
	popup.pszFont = "MS Sans Serif, 8, DEFAULT_CHARSET";

	HtmlHelp (m_pLastDlg->m_hWnd, NULL, HH_DISPLAY_TEXT_POPUP, (DWORD) &popup);		

	m_bInWT = FALSE;
}

void fsContextHelpMgr::ShowMenu()
{
	if (m_iLastCtrl == -1)
		return;

	CMenu menu;
	menu.LoadMenu (IDM_WT);

	CMenu *popup = menu.GetSubMenu (0);
	popup->ModifyMenu (ID_WHATISTHIS, MF_BYCOMMAND|MF_STRING, ID_WHATISTHIS, LS (L_WHATISTHIS));

	popup->TrackPopupMenu (TPM_RIGHTBUTTON | TPM_TOPALIGN | TPM_LEFTALIGN, m_ptLast.x, m_ptLast.y, m_pLastDlg);
}
