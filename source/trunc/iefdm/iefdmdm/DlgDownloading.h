/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __DLGDOWNLOADING_H_
#define __DLGDOWNLOADING_H_

#include "resource.h"       
#include "vmsBindStatusCallback.h"
#include "vmsFileExtension.h"
#include <commctrl.h>
#include "DlgRunOrSave.h"
#include "vmsStringsHelper.h"
#include "vmsIeProtectedMode.h"
#include <shlobj.h>
#include "vmsUrlWnd.h"
#include "DlgDownloadingOptions.h"

#define ID_PREPARE_DOWNLOAD		50

class CDlgDownloading : 
	public CDialogImpl<CDlgDownloading>
{
public:
	vmsBindStatusCallback* m_pBSC;
	CDlgDownloading()
	{
		m_pBSC = NULL;
		m_hFile = INVALID_HANDLE_VALUE;
		m_dwTicksLastUpdate = 0;
		m_bRun = m_bDelFile = false;
		m_dwTicksStart = 0;
		m_hIePmSaveFileState = NULL;
	}

	~CDlgDownloading()
	{
		if (m_hFile != INVALID_HANDLE_VALUE)
			CloseHandle (m_hFile);
	}

	enum { IDD = IDD_DOWNLOADING };

BEGIN_MSG_MAP(CDlgDownloading)
	MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
	COMMAND_ID_HANDLER(IDCANCEL, OnCancel)
	MESSAGE_HANDLER(WM_TIMER, OnTimer)
	COMMAND_ID_HANDLER(ID_PREPARE_DOWNLOAD, OnPrepareDownload)
	COMMAND_HANDLER(IDC_CLOSEWHENCOMPLETES, BN_CLICKED, OnClickedClosewhencompletes)
	COMMAND_HANDLER(IDC_OPEN, BN_CLICKED, OnClickedOpen)
	COMMAND_HANDLER(IDC_OPENFOLDER, BN_CLICKED, OnClickedOpenfolder)
	COMMAND_HANDLER(IDC_OPTIONS, BN_CLICKED, OnClickedOptions)
END_MSG_MAP()

	int getProgress () const
	{
		UINT64 uDownloaded, uFileSize;
		m_pBSC->getProgress (&uDownloaded, &uFileSize);
		if (uFileSize != _UI64_MAX && uFileSize != 0)
			return (int) (uDownloaded * 100 / uFileSize);
		else
			return -1;
	}

	void UpdateWindowTitle ()
	{
		USES_CONVERSION;
		TCHAR tsz [100] = _T ("");
		int progress = getProgress ();
		if (progress != -1)
		{
			_sntprintf (tsz, sizeof (tsz)/sizeof(TCHAR), _T ("[%d%%] of %s from %s"), progress, 
				m_pBSC->getFileName (), A2CT (m_pBSC->getHostName ()));
		}
		else
		{
			UINT64 uDownloaded = 0;
			m_pBSC->getProgress (&uDownloaded, NULL);
			tstring tstr; vmsStringsHelper::BytesToXBstring (uDownloaded, tstr);
			_sntprintf (tsz, sizeof (tsz)/sizeof(TCHAR), _T ("[%s] of %s from %s"), tstr.c_str (), 
				m_pBSC->getFileName (), A2CT (m_pBSC->getHostName ()));
		}
		SetWindowText (tsz);
	}

	
	int getTimeLeft ()
	{
		UINT64 uDownloaded, uFileSize;
		m_pBSC->getProgress (&uDownloaded, &uFileSize);
		if (uFileSize == _UI64_MAX || uFileSize == 0)
			return -1;
		UINT uSpeed = m_pBSC->getSpeed ();
		if (uSpeed == 0)
			return -1; 
		return (uFileSize - uDownloaded) / uSpeed;
	}

	vmsUrlWnd m_wndUrlOptions;

	LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		m_dwTicksStart = GetTickCount ();
		SendDlgItemMessage (IDC_ANIMATE1, ACM_OPEN, 
			(WPARAM)GetModuleHandle (_T ("ieframe.dll")), (LPARAM)MAKEINTRESOURCE (544));
		SendDlgItemMessage (IDC__DONE_ICON, STM_SETICON, 
			(WPARAM)LoadIcon (GetModuleHandle (_T ("ieframe.dll")), MAKEINTRESOURCE (13104)));
		SendDlgItemMessage (IDC_PROGRESS, PBM_SETRANGE, 0, MAKELPARAM (0, 100));
		UpdateWindowTitle ();
		PostMessage (WM_COMMAND, ID_PREPARE_DOWNLOAD);
		CRegKey key;
		if (ERROR_SUCCESS == key.Open (HKEY_CURRENT_USER, _T ("Software\\FreeDownloadManager.ORG\\Free Download Manager\\IeDm"), KEY_READ))
		{
			DWORD dw = 0;
			key.QueryValue (dw, _T ("CloseWhenDlCompletes"));
			CheckDlgButton (IDC_CLOSEWHENCOMPLETES, dw ? BST_CHECKED : BST_UNCHECKED);
		}

		RECT rc; ::GetWindowRect (GetDlgItem (IDC__OPTIONS), &rc);
		ScreenToClient (&rc);
		m_wndUrlOptions.Create (m_hWnd, rc, _T ("Options"), _T ("220"));

		return 1;  
	}

	LRESULT OnCancel(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
	{
		if (!m_pBSC->isDone ())
		{
			m_pBSC->setAbort ();
			if (m_hFile != INVALID_HANDLE_VALUE)
			{
				m_pBSC->setDstFile (INVALID_HANDLE_VALUE);
				CloseHandle (m_hFile);
				m_hFile = INVALID_HANDLE_VALUE;
				DeleteFile (m_tstrCurFile.c_str ());
			}
			if (m_hIePmSaveFileState)
			{
				vmsIeProtectedMode::IECancelSaveFile (m_hIePmSaveFileState);
				m_hIePmSaveFileState = NULL;
			}
		}
		DestroyWindow ();
		PostQuitMessage (0);
		return 0;
	}
	LRESULT OnTimer(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		int newpos = getProgress ();
		if (newpos != -1)
		{
			int pos = SendDlgItemMessage (IDC_PROGRESS, PBM_GETPOS);
			if (newpos != pos)
			{
				SendDlgItemMessage (IDC_PROGRESS, PBM_SETPOS, newpos);
				UpdateWindowTitle ();
			}
		}

		if (GetTickCount () - m_dwTicksLastUpdate >= 1000)
		{
			if (newpos == -1)
				UpdateWindowTitle ();

			UINT64 uDownloaded, uFileSize;
			m_pBSC->getProgress (&uDownloaded, &uFileSize);

			tstring tstrD; vmsStringsHelper::BytesToXBstring (uDownloaded, tstrD);

			TCHAR tsz [100];
			int nFileShortVersionLen = 0;

			int nSeconds = getTimeLeft ();
			if (nSeconds != -1)
			{
				tstring tstr;
				vmsStringsHelper::SecondsToString (nSeconds, tstr);
				if (uFileSize != _UI64_MAX)
				{
					tstring tstrFS; vmsStringsHelper::BytesToXBstring (uFileSize, tstrFS);
					_stprintf (tsz, _T ("%s (%s of %s copied)"), tstr.c_str (), tstrD.c_str (), tstrFS.c_str ());
					nFileShortVersionLen = _tcslen (tsz);
				}
				else
				{
					_stprintf (tsz, _T ("%s (%s copied)"), tstr.c_str (), tstrD.c_str ());
					nFileShortVersionLen = _tcslen (tsz) + 7;
				}
			}
			else
			{
				if (uFileSize != _UI64_MAX)
				{
					tstring tstrFS; vmsStringsHelper::BytesToXBstring (uFileSize, tstrFS);
					_stprintf (tsz, _T ("%s of %s copied"), tstrD.c_str (), tstrFS.c_str ());
					nFileShortVersionLen = _tcslen (tsz) * 1.5;
				}
				else
				{
					_stprintf (tsz, _T ("%s copied"), tstrD.c_str ());
					nFileShortVersionLen = _tcslen (tsz) * 2;
				}
			}

			SetDlgItemText (IDC__TIMELEFT, tsz);

			*tsz = 0;
			GetDlgItemText (IDC__DLTO, tsz, sizeof (tsz)-1);
			tstring tstrF; vmsStringsHelper::GetFilePathShortDisplayString (m_tstrDstFile.c_str (),
				nFileShortVersionLen, tstrF);
			if (_tcslen (tsz) < tstrF.length ())
				SetDlgItemText (IDC__DLTO, tstrF.c_str ());
			
			tstring tstr;
			vmsStringsHelper::BytesToXBstring (m_pBSC->getSpeed (), tstr);
			tstr += _T ("/Sec");
			SetDlgItemText (IDC__SPEED, tstr.c_str ());

			m_dwTicksLastUpdate = GetTickCount ();
		}

		if (m_pBSC->isDone ())
		{
			KillTimer (1);
			m_pBSC->FlushDataToFile ();
			CloseHandle (m_hFile);
			m_hFile = INVALID_HANDLE_VALUE;
			OnFileDownloadDone ();
		}

		return 0;
	}

	LRESULT OnPrepareDownload (WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
	{
		ATLASSERT (m_pBSC != NULL);

		UINT nRes = IDC_SAVE;

		
		tstring tstrFile = m_pBSC->getFileName ();
		LPCTSTR ptszExt = vmsFileExtension::getExtensionPart (tstrFile.c_str ());

		
		
		if (ptszExt != NULL && *ptszExt != 0)
		{
			CDlgRunOrSave dlgRS (m_pBSC);
			nRes = dlgRS.DoModal (*this);
			if (nRes == IDCANCEL)
			{
				PostMessage (WM_COMMAND, IDCANCEL);
				return 0;
			}
		}

		if (nRes == IDC_SAVE)
		{
			if (FALSE == PromptUserChooseSaveLocation ())
			{
				m_pBSC->setAbort ();
				DestroyWindow ();
				PostQuitMessage (0);
				return 0;
			}
		}
		else 
		{
			TCHAR tszTmpPath [MAX_PATH] = _T ("");
			GetTempPath (MAX_PATH, tszTmpPath);
			if (*tszTmpPath && tszTmpPath [_tcslen (tszTmpPath)-1] != '\\')
				_tcscat (tszTmpPath, _T ("\\"));
			_tcscat (tszTmpPath, m_pBSC->getFileName ());
			m_tstrCurFile = m_tstrDstFile = tszTmpPath;
			m_bRun = true;
			m_bDelFile = true;
		}

		m_hFile = CreateFile (m_tstrCurFile.c_str (), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 
			FILE_ATTRIBUTE_NORMAL, NULL);

		if (m_hFile == INVALID_HANDLE_VALUE)
		{
			MessageBox (_T ("Failed write to file."), _T ("Fatal error"), MB_ICONERROR);
			PostMessage (WM_COMMAND, IDCANCEL);
			return 0;
		}

		m_pBSC->setDstFile (m_hFile);
		m_pBSC->setAllowDownload ();

		SendDlgItemMessage (IDC_ANIMATE1, ACM_PLAY, -1, -1);

		SetTimer (1, 200);

		return 0;
	}

	void OnFileDownloadDone ()
	{
		bool bClose = false;

		if (m_hIePmSaveFileState != NULL && m_tstrCurFile != m_tstrDstFile)
		{
			USES_CONVERSION;
			HRESULT hr = vmsIeProtectedMode::IESaveFile (m_hIePmSaveFileState, (LPWSTR) T2CW (m_tstrCurFile.c_str ()));
			m_hIePmSaveFileState = NULL;
			if (FAILED (hr))
				MessageBox (_T ("Failed to save the file"), _T ("Error"), MB_ICONERROR);
			else
				m_tstrCurFile = m_tstrDstFile;
		}

		if (m_bRun)
		{
			LaunchFile (m_tstrCurFile.c_str ());
			bClose = true;
		}
		else
		{
			SendDlgItemMessage (IDC_ANIMATE1, ACM_STOP, 0, 0);
			::ShowWindow (GetDlgItem (IDC_ANIMATE1), SW_HIDE);
			::ShowWindow (GetDlgItem (IDC__DONE_ICON), SW_SHOW);
			::ShowWindow (GetDlgItem (IDC__DONE_MSG), SW_SHOW);

			SetDlgItemText (IDC__TIMELEFT0, _T ("Downloaded:"));
			TCHAR tsz [1000] = _T ("");
			UINT64 uDownloaded = 0; m_pBSC->getProgress (&uDownloaded, NULL);
			tstring tstr1; vmsStringsHelper::BytesToXBstring (uDownloaded, tstr1);
			tstring tstr2; vmsStringsHelper::SecondsToString ((GetTickCount () - m_dwTicksStart) / 1000, tstr2);
			_stprintf (tsz, _T ("%s in %s"), tstr1.c_str (), tstr2.c_str ());
			SetDlgItemText (IDC__TIMELEFT, tsz);

			SetDlgItemText (IDCANCEL, _T ("Close"));
			SetWindowText (_T ("Download complete"));

			::EnableWindow (GetDlgItem (IDC_OPEN), TRUE);
			::EnableWindow (GetDlgItem (IDC_OPENFOLDER), TRUE);
			
		}
		if (m_bDelFile)
			;
		if (IsDlgButtonChecked (IDC_CLOSEWHENCOMPLETES) == BST_CHECKED)
			bClose = true;

		if (bClose)
		{
			DestroyWindow ();
			PostQuitMessage (0);
		}
	}

	LRESULT OnClickedClosewhencompletes(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
	{
		CRegKey key;
		key.Open (HKEY_CURRENT_USER, _T ("Software\\FreeDownloadManager.ORG\\Free Download Manager\\IeDm"), KEY_ALL_ACCESS);
		if (key == NULL)
			key.Create (HKEY_CURRENT_USER, _T ("Software\\FreeDownloadManager.ORG\\Free Download Manager\\IeDm"), NULL, 0, KEY_ALL_ACCESS, NULL, NULL);
		key.SetValue (IsDlgButtonChecked (IDC_CLOSEWHENCOMPLETES) == BST_CHECKED, _T ("CloseWhenDlCompletes"));
		return 0;
	}

	

	enum OPEN_AS_INFO_FLAGS
	{
		OAIF_ALLOW_REGISTRATION = 1,
		OAIF_REGISTER_EXT       = 2,
		OAIF_EXEC               = 4,
		OAIF_FORCE_REGISTRATION = 8,
		OAIF_HIDE_REGISTRATION  = 32,
		OAIF_URL_PROTOCOL       = 64,
	};
	struct OPENASINFO 
	{
		LPCTSTR pcszFile;
		LPCTSTR pcszClass;
		OPEN_AS_INFO_FLAGS oaifInFlags;
	};

	HRESULT doSHOpenWithDialog (HWND hwndParent, const OPENASINFO* poainfo)
	{
		typedef HRESULT (WINAPI *FNSHOWD)(HWND, const OPENASINFO* poainfo);
		HMODULE hDll = LoadLibrary (_T ("shell32.dll"));
		if (!hDll)
			return E_UNEXPECTED;
		#ifdef _UNICODE
			FNSHOWD pfn = (FNSHOWD)GetProcAddress (hDll, "SHOpenWithDialogW");
		#else
			FNSHOWD pfn = (FNSHOWD)GetProcAddress (hDll, "SHOpenWithDialogA");
		#endif
		if (!pfn)
			pfn = (FNSHOWD)GetProcAddress (hDll, "SHOpenWithDialog");
		HRESULT hr = E_NOTIMPL;
		if (pfn)
			hr = pfn (hwndParent, poainfo);
		FreeLibrary (hDll);
		return hr;
	}

	void LaunchFile (LPCTSTR ptszFile)
	{
		SHELLEXECUTEINFO sei = {0};
		sei.cbSize = sizeof (sei);
		sei.fMask = SEE_MASK_FLAG_NO_UI;
		sei.lpVerb = _T ("open");
		
		sei.lpFile = ptszFile;
		sei.nShow = SW_SHOWNORMAL;
		if (ShellExecuteEx (&sei))
			return;
		TCHAR tszArgs [MAX_PATH] = _T ("");
		if (GetLastError () == ERROR_NO_ASSOCIATION)
		{
			sei.lpFile = _T ("Rundll32.exe");
			_tcscpy (tszArgs, _T ("shell32.dll,OpenAs_RunDLL "));
			_tcscat (tszArgs, ptszFile);
			sei.lpParameters = tszArgs;
			if (ShellExecuteEx (&sei))
					return;			
			
			
		}
		if (GetLastError () == 740)
		{
			sei.lpVerb = _T ("runas");
			if (ShellExecuteEx (&sei))
				return;
		}
		
		TCHAR tsz [100];
		_stprintf (tsz, _T ("Failed to launch file.\nError: %d"), GetLastError ());
		MessageBox (tsz, _T ("Error"), MB_ICONERROR);
	}

	LRESULT OnClickedOpen(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
	{
		LaunchFile (m_tstrCurFile.c_str ());
		DestroyWindow ();
		PostQuitMessage (0);
		return 0;
	}

	LRESULT OnClickedOpenfolder(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
	{
		DestroyWindow ();
		PostQuitMessage (0);
		TCHAR tsz [MAX_PATH];
		_stprintf (tsz, _T ("/select, \"%s\""), m_tstrCurFile.c_str ());
		ShellExecute (NULL, _T ("open"), _T ("explorer.exe"), tsz, NULL, SW_SHOW);
		return 0;
	}

protected:
	BOOL PromptUserChooseSaveLocation();
	HANDLE m_hIePmSaveFileState;
	DWORD m_dwTicksStart;
	DWORD m_dwTicksLastUpdate;
	HANDLE m_hFile;
	tstring m_tstrCurFile, m_tstrDstFile;
	bool m_bRun, m_bDelFile;
	LRESULT OnClickedOptions(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
	{
		CDlgDownloadingOptions dlg;
		dlg.DoModal ();
		return 0;
	}
};

#endif 
