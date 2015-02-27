/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "vmsWaitDlg.h"
#include "resource.h"
#include "vmsFdmTranslations.h"

vmsWaitDlg::vmsWaitDlg()
{
	m_hwnd = NULL;
	m_hevCloseDlg = NULL;
	m_bPostQuitMsg = true;
	m_hIcon = NULL;
}

vmsWaitDlg::~vmsWaitDlg()
{

}

INT_PTR CALLBACK vmsWaitDlg::_DlgProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
	if (msg == WM_INITDIALOG)
	{
		vmsWaitDlg *pthis = (vmsWaitDlg*)lp;
		setThisPtr (hwnd, pthis);
		SetDlgItemText (hwnd, IDC__MSG, pthis->m_strMsg.c_str ());
		std::string str = vmsFdmTranslations::o ().GetString (L_PLEASEWAIT);
		if (str.empty ())
			str = "Please wait...";
		SetWindowText (hwnd, str.c_str ());

		SetTimer (hwnd, 1, 100, NULL);

		if (pthis->m_hIcon)
			SendMessage (hwnd, WM_SETICON, ICON_SMALL, (LPARAM)pthis->m_hIcon);

		return TRUE;
	}

	else if (msg == WM_TIMER)
	{
		vmsWaitDlg *pthis = getThisPtr (hwnd);
		if (WaitForSingleObject (pthis->m_hevCloseDlg, 30) == WAIT_OBJECT_0)
		{
			KillTimer (hwnd, 1);
			EndDialog (hwnd, IDOK);
			if (pthis->m_bPostQuitMsg)
				PostQuitMessage (0);
		}

		return TRUE;		
	}

	return 0;
}

BOOL vmsWaitDlg::Create(HINSTANCE hInstance, LPCTSTR lpTemplate, HWND hWndParent)
{
	m_hwnd = CreateDialogParam (hInstance, lpTemplate, hWndParent, _DlgProc, (LPARAM)this);
	if (!IsWindow (m_hwnd))
		return FALSE;
	
	return TRUE;
}

void vmsWaitDlg::setThisPtr(HWND hwnd, vmsWaitDlg *pthis)
{
	SetWindowLongPtr (hwnd, GWL_USERDATA, (LONG_PTR)pthis);
}

vmsWaitDlg* vmsWaitDlg::getThisPtr(HWND hwnd)
{
	return (vmsWaitDlg*) GetWindowLongPtr (hwnd, GWL_USERDATA);
}

