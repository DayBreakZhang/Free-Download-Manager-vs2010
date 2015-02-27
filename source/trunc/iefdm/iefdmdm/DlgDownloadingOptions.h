/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __DLGDOWNLOADINGOPTIONS_H_
#define __DLGDOWNLOADINGOPTIONS_H_

#include "resource.h"       
#include <atlhost.h>
#include "vmsIeHKCU.h"

class CDlgDownloadingOptions : 
	public CAxDialogImpl<CDlgDownloadingOptions>
{
public:
	CDlgDownloadingOptions()
	{
	}

	~CDlgDownloadingOptions()
	{
	}

	enum { IDD = IDD_DLGDOWNLOADINGOPTIONS };

BEGIN_MSG_MAP(CDlgDownloadingOptions)
	MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
	COMMAND_ID_HANDLER(IDOK, OnOK)
	COMMAND_ID_HANDLER(IDCANCEL, OnCancel)
END_MSG_MAP()

	LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		CheckDlgButton (IDC_RADIO1, BST_CHECKED);
		return 1;  
	}

	LRESULT OnOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
	{
		if (IsDlgButtonChecked (IDC_RADIO2) == BST_CHECKED)
		{
			vmsIeHKCU key;
			if (ERROR_SUCCESS != key.Open (_T ("Software\\FreeDownloadManager.ORG\\Free Download Manager\\Settings\\Monitor"), KEY_WRITE))
				key.Create (_T ("Software\\FreeDownloadManager.ORG\\Free Download Manager\\Settings\\Monitor"), KEY_ALL_ACCESS);
			key.getKey ().SetValue (TRUE, _T ("UseIeNativeDownloader"));
			MessageBox (_T ("Setting will be applied for further downloads."), _T ("Free Download Manager"), MB_ICONINFORMATION);
		}
		EndDialog(wID);
		return 0;
	}

	LRESULT OnCancel(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
	{
		EndDialog(wID);
		return 0;
	}
};

#endif 
