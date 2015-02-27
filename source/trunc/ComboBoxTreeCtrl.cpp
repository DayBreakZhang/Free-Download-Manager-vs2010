/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "ComboBoxTreeCtrl.h"
#include "DownloadsGroupsComboBox.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CComboBoxTreeCtrl::CComboBoxTreeCtrl()
{
}

CComboBoxTreeCtrl::~CComboBoxTreeCtrl()
{
}

BEGIN_MESSAGE_MAP(CComboBoxTreeCtrl, CTreeCtrl)
	//{{AFX_MSG_MAP(CComboBoxTreeCtrl)
	ON_WM_KILLFOCUS()
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, OnSelchanged)
	ON_NOTIFY_REFLECT(TVN_KEYDOWN, OnKeydown)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CComboBoxTreeCtrl::OnKillFocus(CWnd* pNewWnd) 
{
	CTreeCtrl::OnKillFocus(pNewWnd);
	
	if (pNewWnd == NULL || pNewWnd->m_hWnd != m_pCombo->m_hWnd)
		m_pCombo->ShowDropDown (FALSE);
	
}

void CComboBoxTreeCtrl::OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult) 
{
	

	if (IsWindowVisible ())
	{
		m_pCombo->Tree_UpdateSelection ();
		m_pCombo->ShowDropDown (FALSE);
	}

	*pResult = 0;
}

void CComboBoxTreeCtrl::OnKeydown(NMHDR* pNMHDR, LRESULT* pResult) 
{
	TV_KEYDOWN* pTVKeyDown = (TV_KEYDOWN*)pNMHDR;
	
	if (pTVKeyDown->wVKey == VK_ESCAPE && IsWindowVisible ())
		m_pCombo->ShowDropDown (FALSE);
	
	*pResult = 0;
}

BOOL CComboBoxTreeCtrl::CreateEx(DWORD dwExStyle, LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect,
			CWnd* pParentWnd, UINT nID, LPVOID lpParam)
{
	return CWnd::CreateEx(dwExStyle, lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, lpParam);
}

BOOL CComboBoxTreeCtrl::CreateEx(DWORD dwExStyle, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID)
{
	return CTreeCtrl::CreateEx(dwExStyle, dwStyle, rect, pParentWnd, nID);
}
