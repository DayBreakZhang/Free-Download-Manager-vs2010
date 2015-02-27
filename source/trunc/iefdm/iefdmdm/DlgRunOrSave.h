/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __DLGRUNORSAVE_H_
#define __DLGRUNORSAVE_H_

#include "resource.h"       
#include "vmsBindStatusCallback.h"
#include "vmsStringsHelper.h"
#include "vmsFileExtension.h"

class CDlgRunOrSave : public CDialogImpl<CDlgRunOrSave>
{
public:
	CDlgRunOrSave(vmsBindStatusCallback *pBSC)
	{
		ATLASSERT (pBSC != NULL);
		m_pBSC = pBSC;
	}

	~CDlgRunOrSave()
	{
	}

	enum { IDD = IDD_RUN_OR_SAVE };

BEGIN_MSG_MAP(CDlgRunOrSave)
	MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
	COMMAND_ID_HANDLER(IDCANCEL, OnCancel)
	COMMAND_ID_HANDLER(IDC_RUN, OnRun)
	COMMAND_ID_HANDLER(IDC_SAVE, OnSave)
END_MSG_MAP()

	LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		USES_CONVERSION;	
	
		SHFILEINFO shfi; ZeroMemory (&shfi, sizeof (shfi));
		SHGetFileInfo (m_pBSC->getFileName (), FILE_ATTRIBUTE_NORMAL, &shfi, sizeof (shfi), 
			SHGFI_ICON | SHGFI_LARGEICON |  SHGFI_USEFILEATTRIBUTES);
		if (shfi.hIcon)
			SendDlgItemMessage (IDC__FILEICON, STM_SETICON, (WPARAM)shfi.hIcon);

		SetDlgItemText (IDC__NAME, m_pBSC->getFileName ());

		LPCTSTR pszExt = vmsFileExtension::getExtensionPart (m_pBSC->getFileName ());
		tstring tstrType = _T ("Unknown");
		if (pszExt)
		{
			tstring tstr = vmsFileExtension::GetExtensionName (pszExt);
			if (!tstr.empty ())
				tstrType = tstr;
		}
		UINT64 uFileSize = m_pBSC->getFileSize ();
		if (uFileSize != _UI64_MAX)
		{
			tstrType += _T (", ");
			tstring tstr;
			vmsStringsHelper::BytesToXBstring (uFileSize, tstr);
			tstrType += tstr.c_str ();
		}
		SetDlgItemText (IDC__TYPE, tstrType.c_str ());

		SetDlgItemText (IDC__FROM, A2CT (m_pBSC->getHostName ()));

		SendDlgItemMessage (IDC__WARNING, STM_SETICON, 
			(WPARAM)LoadIcon (GetModuleHandle (_T ("ieframe.dll")), MAKEINTRESOURCE (31057)));

		return 1;  
	}

	LRESULT OnOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
	{
		EndDialog(wID);
		return 0;
	}

	LRESULT OnRun(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
	{
		EndDialog(wID);
		return 0;
	}

	LRESULT OnSave(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
	{
		EndDialog(wID);
		return 0;
	}

	LRESULT OnCancel(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
	{
		EndDialog(wID);
		return 0;
	}

protected:
	vmsBindStatusCallback *m_pBSC;
};

#endif 
