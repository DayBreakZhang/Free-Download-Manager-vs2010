/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __WAITDLG_H_
#define __WAITDLG_H_

#include "resource.h"       
#include <atlhost.h>
#include <string>
#include "vmsFdmTranslations.h"

class CWaitDlg : 
	public CAxDialogImpl<CWaitDlg>
{
public:
	HANDLE m_hEvCloseDlg;
	std::string m_strMsg;
	CWaitDlg()
	{
		m_hEvCloseDlg = NULL;
	}

	~CWaitDlg()
	{	
	}

	enum { IDD = IDD_WAIT };

BEGIN_MSG_MAP(CWaitDlg)
	MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
	COMMAND_ID_HANDLER(IDOK, OnOK)
	COMMAND_ID_HANDLER(IDCANCEL, OnCancel)
	MESSAGE_HANDLER(WM_TIMER, OnTimer)
END_MSG_MAP()

	LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		SetDlgItemText (IDC__MSG, m_strMsg.c_str ());
		std::string str = vmsFdmTranslations::o ().GetString (L_PLEASEWAIT);
		if (str.empty ())
			str = _T ("Please wait...");
		SetWindowText (str.c_str ());
		SetTimer (1, 100);
		HICON hIcon = LoadIcon (_Module.GetResourceInstance (), MAKEINTRESOURCE (IDI_FDM));
		SetIcon (hIcon, FALSE);
		return 1;  
	}

	LRESULT OnOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
	{
		
		return 0;
	}

	LRESULT OnCancel(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
	{
		
		return 0;
	}
	LRESULT OnTimer(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		ATLASSERT (m_hEvCloseDlg != NULL);
		if (WaitForSingleObject (m_hEvCloseDlg, 30) == WAIT_OBJECT_0)
		{
			KillTimer (1);
			DestroyWindow ();
		}
		return 0;
	}
};

#endif 
