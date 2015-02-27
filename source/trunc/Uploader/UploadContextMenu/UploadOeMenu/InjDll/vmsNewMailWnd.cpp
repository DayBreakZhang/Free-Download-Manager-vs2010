/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsNewMailWnd.h"
#include <commctrl.h>
#include <comdef.h>
#include "assert.h"
#include "vmsComSupport.h"
#include <atlbase.h>
#include "vmsOleAccHelper.h"
#include <string>
#include <vector>
#include "fsLangMgr.h"
#include "../../../../lngphrases.h"
#include <Commdlg.h>
#include <AlsFolderBrowser.h>
#include <shellapi.h>
#include "resource.h"

#include "../../../FUM/FUM_i.h"
#include "../../../../Fdm.h"

_COM_SMARTPTR_TYPEDEF (IUploader, __uuidof (IUploader));
_COM_SMARTPTR_TYPEDEF (IUploadPackage, __uuidof (IUploadPackage));

WNDPROC vmsNewMailWnd::_m_pfnOrigWndProc	= NULL;
CRegKey vmsNewMailWnd::_m_keySettings;
HMENU	vmsNewMailWnd::_m_menuAttachFiles	= NULL;

#define OE_CMDID_ATTACHFILES		40237
#define OE_CMDID_SENDMAIL			40411
#define OE_CMDID_REMOVEATTACHMENT	40323

#define ID_UPLOADFILES				50000
#define ID_UPLOADFOLDER				50001
#define ID_SETTINGS					50002

vmsNewMailWnd::vmsNewMailWnd()
{
}

vmsNewMailWnd::~vmsNewMailWnd()
{

}

LRESULT WINAPI vmsNewMailWnd::_WindowProcedure(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
	if (msg == WM_COMMAND)
	{
		switch (LOWORD (wp))
		{
		case OE_CMDID_SENDMAIL:
			OnBeforeSendMail (hwnd);
			break;

		case ID_UPLOADFILES:
			OnUploadFiles (hwnd);
			return 0;

		case ID_SETTINGS:
			OnSettings ();
			return 0;

		case ID_UPLOADFOLDER:
			OnUploadFolder (hwnd);
			return 0;
		}
	}

	else if (msg == WM_NOTIFY)
	{
		NMHDR* hdr = (NMHDR*)lp;
		if (hdr->code == TBN_DROPDOWN)
		{
			LPNMTOOLBAR nmtb = (LPNMTOOLBAR)lp;
			if (nmtb->iItem == OE_CMDID_ATTACHFILES)
			{
				CreateContextMenu ();
				HMENU hMenuAttachFiles = GetSubMenu (_m_menuAttachFiles, 0);
				HWND hwndTb = FindToolbarWindow (hwnd);
				int nIndex = SendMessage (hwndTb, TB_COMMANDTOINDEX, OE_CMDID_ATTACHFILES, 0);
				RECT rc;
				SendMessage (hwndTb, TB_GETITEMRECT, nIndex, (LPARAM)&rc);
				ClientToScreen (hwndTb, (LPPOINT)&rc);
				ClientToScreen (hwndTb, (LPPOINT)&rc + 1);
				POINT pt; GetCursorPos (&pt);
				if (abs (pt.x - rc.right) > 50 || abs (pt.y - rc.bottom) > 50)
				{
					rc.left = pt.x;
					rc.bottom = pt.y;
				}
				TrackPopupMenu (hMenuAttachFiles, TPM_RIGHTBUTTON | TPM_LEFTALIGN | TPM_TOPALIGN, 
					rc.left, rc.bottom+1, 0, hwnd, NULL);
				return 0;
			}
		}
	}

	LRESULT lRes = CallWindowProc (_m_pfnOrigWndProc, hwnd, msg, wp, lp);

	
	
	if (msg == WM_INITMENUPOPUP)
	{
		CreateContextMenu ();
		HMENU menu = (HMENU) wp;
		HMENU hMenuAttachFiles = GetSubMenu (_m_menuAttachFiles, 0);
		if (GetMenuItemID (menu, 0) == OE_CMDID_ATTACHFILES &&
				menu != hMenuAttachFiles)
		{
			char sz [1000];
			GetMenuString (menu, 0, sz, sizeof (sz), MF_BYPOSITION);			
			ModifyMenu (menu, 0, MF_BYPOSITION | MF_POPUP, 
				(UINT)GetSubMenu (_m_menuAttachFiles, 0), sz);
		}
		else if (GetSubMenu (menu, 0) == hMenuAttachFiles)
		{
			EnableMenuItem (menu, 0, MF_ENABLED | MF_BYPOSITION);
		}
		else if (menu == hMenuAttachFiles)
		{
			EnableMenuItem (menu, 0, MF_ENABLED | MF_BYPOSITION);
			EnableMenuItem (menu, 1, MF_ENABLED | MF_BYPOSITION);
		}
		else if (GetMenuItemID (menu, 0) == ID_UPLOADFILES)
		{
			EnableMenuItem (menu, 0, MF_ENABLED | MF_BYPOSITION);
			EnableMenuItem (menu, 1, MF_ENABLED | MF_BYPOSITION);
		}
	}
	else if (msg == WM_UNINITMENUPOPUP)
	{
		if (_m_menuAttachFiles)
		{
			HMENU menu = (HMENU) wp;
			HMENU hMenuAttachFiles = GetSubMenu (_m_menuAttachFiles, 0);
			if (GetSubMenu (menu, 0) == hMenuAttachFiles)
			{
				char sz [1000];
				GetMenuString (menu, 0, sz, sizeof (sz), MF_BYPOSITION);
				RemoveMenu (menu, 0, MF_BYPOSITION);
				InsertMenu (menu, 0, MF_BYPOSITION | MF_STRING, OE_CMDID_ATTACHFILES, sz);
			}
		}
	}

	
	
	

	return lRes;
}

HWND vmsNewMailWnd::FindAttachmentsListView(HWND hwndNewMailWnd)
{
	HWND hwnd = FindWindowEx (hwndNewMailWnd, NULL, "OE_Envelope", NULL);
	if (hwnd == NULL)
		return NULL;
	return FindWindowEx (hwnd, NULL, "SysListView32", NULL);
}

bool vmsNewMailWnd::ClearAttachmentsList(HWND hwndNewMailWnd)
{
	HWND hwndLV = FindAttachmentsListView (hwndNewMailWnd);
	if (hwndLV == NULL)
		return false;
	
	int cItems = ListView_GetItemCount (hwndLV);
	if (cItems == 0)
		return true;

	for (int i = 0; i < cItems; i++)
		ListView_SetItemState (hwndLV, i, LVIS_SELECTED, LVIS_SELECTED);
	SendMessage (GetParent (hwndLV), WM_COMMAND, OE_CMDID_REMOVEATTACHMENT, 0);
	assert (ListView_GetItemCount (hwndLV) == 0);

	return ListView_GetItemCount (hwndLV) == 0;
}

HWND vmsNewMailWnd::FindMailTextWindow(HWND hwndNewMailWnd)
{
	HWND hwnd = FindWindowEx (hwndNewMailWnd, NULL, "ME_DocHost", NULL);
	if (hwnd == NULL)
		return NULL;
	hwnd = FindWindowEx (hwnd, NULL, "##MimeEdit_Server", NULL);
	if (hwnd == NULL)
		return NULL;
	return FindWindowEx (hwnd, NULL, "Internet Explorer_Server", NULL);
}

bool vmsNewMailWnd::AttachToWindow(HWND hwndNewMailWnd)
{
	if (_m_keySettings.m_hKey == NULL)
	{
		_m_keySettings.Open (HKEY_CURRENT_USER, "Software\\FreeDownloadManager.ORG\\Free Upload Manager\\Settings\\Integration\\Oe");
	}

	WNDPROC pfn = (WNDPROC)GetWindowLong (hwndNewMailWnd, GWL_WNDPROC);
	
	if (pfn == _m_pfnOrigWndProc || _m_pfnOrigWndProc == NULL)
	{
		_m_pfnOrigWndProc = pfn;
		SetWindowLong (hwndNewMailWnd, GWL_WNDPROC, (LONG)_WindowProcedure);
		
		InitializeWindow (hwndNewMailWnd);

		return true;
	}

	return false;
}

bool vmsNewMailWnd::InitializeWindow(HWND hwndNewMailWnd)
{
	HWND hwndTb = FindToolbarWindow (hwndNewMailWnd);
	assert (hwndTb != NULL);
	if (hwndTb != NULL)
	{
		TBBUTTONINFO tbbi;
		tbbi.cbSize = sizeof (tbbi);
		tbbi.dwMask = TBIF_STYLE;
		if (-1 != SendMessage (hwndTb, TB_GETBUTTONINFO, OE_CMDID_ATTACHFILES, (LPARAM)&tbbi))
		{
			tbbi.fsStyle |= TBSTYLE_DROPDOWN;
			SendMessage (hwndTb, TB_SETBUTTONINFO, OE_CMDID_ATTACHFILES, (LPARAM)&tbbi);
		}
	}

	return true;
}

HWND vmsNewMailWnd::FindToolbarWindow(HWND hwndNewMailWnd)
{
	HWND hwnd = FindWindowEx (hwndNewMailWnd, NULL, "SizableRebar", NULL);
	if (hwnd == NULL)
		return NULL;
	hwnd = FindWindowEx (hwnd, NULL, "ReBarWindow32", NULL);
	if (hwnd == NULL)
		return NULL;

	HWND hwnd2 = FindWindowEx (hwnd, NULL, "ToolbarWindow32", NULL);
	if (hwnd2 == NULL)
		return NULL;
	if ((GetWindowLong (hwnd2, GWL_STYLE) & TBSTYLE_TOOLTIPS) == 0)
	{
		hwnd2 = FindWindowEx (hwnd, hwnd2, "ToolbarWindow32", NULL);
		if (hwnd2 == NULL)
			return NULL;
		assert (GetWindowLong (hwnd2, GWL_STYLE) & TBSTYLE_TOOLTIPS);
		if ((GetWindowLong (hwnd2, GWL_STYLE) & TBSTYLE_TOOLTIPS) == 0)
			return NULL;		
	}

	return hwnd2;
}

void vmsNewMailWnd::OnUploadFiles(HWND hwndNewMailWnd)
{
	OPENFILENAME ofn;
	ZeroMemory (&ofn, sizeof (ofn));
	ofn.lStructSize = sizeof (ofn);
	ofn.hwndOwner = hwndNewMailWnd;

	
	char szFilter [200]; lstrcpy (szFilter, LS (L_ALLFILES));
	lstrcat (szFilter, " (*.*)");
	int n = lstrlen (szFilter) + 1;
	lstrcpy (szFilter + n, "*.*");
	n += lstrlen (szFilter + n) + 1;
	lstrcpy (szFilter + lstrlen (szFilter) + 1, "");

	ofn.lpstrFilter = szFilter;

	char szFiles [10000] = "";
	ofn.lpstrFile = szFiles;
	ofn.nMaxFile = sizeof (szFiles);

	ofn.lpstrTitle = LS (L_UPLOADFILES);
	ofn.Flags = OFN_ALLOWMULTISELECT | 0x02000000 | 
		OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY | OFN_NOCHANGEDIR | 
		OFN_NONETWORKBUTTON | OFN_PATHMUSTEXIST;

	if (FALSE == GetOpenFileName (&ofn))
		return;

	vmsComSupport comSupp;

	IUploaderPtr spUpldr;
	if (FAILED (spUpldr.CreateInstance (__uuidof (FUMUploader))))
		spUpldr.CreateInstance (__uuidof (FDMUploader));

	if (spUpldr == NULL)
		return;

	IUploadPackagePtr spPkg;
	if (FAILED (spPkg.CreateInstance (__uuidof (FUMUploadPackage))))
		spPkg.CreateInstance (__uuidof (FDMUploadPackage));;

	USES_CONVERSION;
	std::wstring wstrPkgName;

	if (szFiles [ofn.nFileOffset - 1] == 0)
	{
		LPSTR psz = szFiles + ofn.nFileOffset;
		while (*psz)
		{
			std::string str = szFiles;
			str += '\\';
			str += psz;

			wstrPkgName += A2W (psz);		
			spPkg->Add (SysAllocString (A2W (str.c_str ())));

			psz += lstrlen (psz) + 1;
			if (*psz)
				wstrPkgName += L", ";
		}
	}
	else
	{
		wstrPkgName = A2W (szFiles + ofn.nFileOffset);
		spPkg->Add (SysAllocString (A2W (szFiles)));
	}

	spPkg->put_Name (SysAllocString (wstrPkgName.c_str ()));

	long lId;
	if (FAILED (spUpldr->CreateUpload (spPkg, TRUE, &lId)))
		return; 

	CComBSTR bstrResUrl;
	spUpldr->GetUploadTargetUrl (lId, &bstrResUrl);

	CComBSTR bstrPkgName;
	spUpldr->GetUploadPackageName (lId, &bstrPkgName);

	if (bstrResUrl.Length () > 0)
		InsertUploadUrlToMailText (hwndNewMailWnd, bstrPkgName, bstrResUrl);
	else
		MessageBox (hwndNewMailWnd, LS (L_FAILED_TO_START_UPLOADING), LS (L_ERR), MB_ICONERROR);
}

extern HANDLE _hModule;

INT_PTR CALLBACK _UploadRecommDialogProc (HWND hDlg, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{
	case WM_INITDIALOG:
		SetDlgItemText (hDlg, IDC__MSG, LS (L_UPL_RECOMMENDED_MSG));
		SetDlgItemText (hDlg, IDC_DONTSHOWAGAIN, LS (L_DONTSHOWTHISWINDOWAGAIN));
		SetDlgItemText (hDlg, IDOK, LS (L_YES));
		SetDlgItemText (hDlg, IDCANCEL, LS (L_NO));
		SetWindowText  (hDlg, LS (L_UPL_IS_RECOMMENDED));
		return TRUE;

	case WM_COMMAND:
		switch (LOWORD (wp))
		{
		case IDOK:
		case IDCANCEL:
			if (IsDlgButtonChecked (hDlg, IDC_DONTSHOWAGAIN) == BST_CHECKED)
				vmsNewMailWnd::_m_keySettings.SetValue (UINT_MAX, "MinSizeOfFileToUpload");
			EndDialog (hDlg, LOWORD (wp));
			break;
		}
		return TRUE;
	}

	return FALSE;
}

BOOL vmsNewMailWnd::OnBeforeSendMail(HWND hwndNewMailWnd)
{
	HWND hwndLV = FindAttachmentsListView (hwndNewMailWnd);
	if (hwndLV == NULL)
		return FALSE;
	
	int cItems = ListView_GetItemCount (hwndLV);
	if (cItems == 0)
		return FALSE;

	std::vector <std::wstring> vFiles;
	std::vector <int> vIndexes;
	LVITEM item;
	item.iSubItem = 0;
	item.mask = LVIF_PARAM;
	for (item.iItem = 0; item.iItem < cItems; item.iItem++)
	{
		if (FALSE == ListView_GetItem (hwndLV, &item))
			return FALSE;

		LPWSTR pwszFile = (LPWSTR)item.lParam;
		if (*pwszFile == 0)
			return FALSE;

		WIN32_FIND_DATA wfd;
		USES_CONVERSION;
		HANDLE hFind = FindFirstFile (W2A (pwszFile), &wfd);
		if (hFind != NULL)
		{
			DWORD dw = 1024;
			if (_m_keySettings.m_hKey)
				_m_keySettings.QueryValue (dw, "MinSizeOfFileToUpload");
			if (wfd.nFileSizeLow > dw*1024)
			{
				vFiles.push_back (pwszFile);
				vIndexes.push_back (item.iItem);
			}
			FindClose (hFind);
		}
	}

	if (vFiles.size () == 0)
		return FALSE;

	if (IDOK != DialogBox ((HINSTANCE)_hModule, MAKEINTRESOURCE (IDD_UPLOAD_RECOMMENDED),
			hwndNewMailWnd, _UploadRecommDialogProc))
		return FALSE;

	vmsComSupport comSupp;

	IUploaderPtr spUpldr;
	if (FAILED (spUpldr.CreateInstance (__uuidof (FUMUploader))))
		spUpldr.CreateInstance (__uuidof (FDMUploader));

	if (spUpldr == NULL)
		return FALSE;

	IUploadPackagePtr spPkg;
	if (FAILED (spPkg.CreateInstance (__uuidof (FUMUploadPackage))))
		spPkg.CreateInstance (__uuidof (FDMUploadPackage));;

	for (size_t i = 0; i < vFiles.size (); i++)
		spPkg->Add (SysAllocString (vFiles [i].c_str ()));

	std::wstring wstrLinkText;
	
	for (i = 0; i < vFiles.size (); i++)
	{
		wchar_t wszName [MAX_PATH];
		LPCWSTR pwsz = wcsrchr (vFiles [i].c_str (), '\\');
		if (pwsz == NULL)
			pwsz = vFiles [i].c_str ();
		else
			pwsz++;

		wcscpy (wszName, pwsz); 
		wstrLinkText += wszName;
		if (i != vFiles.size () - 1)
			wstrLinkText += L", ";
	}

	spPkg->put_Name (SysAllocString (wstrLinkText.c_str ()));

	long lId;
	if (FAILED (spUpldr->CreateUpload (spPkg, TRUE, &lId)))
		return FALSE;

	CComBSTR bstrResUrl;
	spUpldr->GetUploadTargetUrl (lId, &bstrResUrl);

	if (bstrResUrl.Length () > 0)
	{
		InsertUploadUrlToMailText (hwndNewMailWnd, wstrLinkText.c_str (), bstrResUrl);

		for (i = 0; i < cItems; i++)
			ListView_SetItemState (hwndLV, i, 0, LVIS_SELECTED);
		for (i = 0; i < vIndexes.size (); i++)
			ListView_SetItemState (hwndLV, vIndexes [i], LVIS_SELECTED, LVIS_SELECTED);
		SendMessage (GetParent (hwndLV), WM_COMMAND, OE_CMDID_REMOVEATTACHMENT, 0);
	}
	else
	{
		MessageBox (hwndNewMailWnd, LS (L_FAILED_TO_START_UPLOADING), LS (L_ERR), MB_ICONERROR);
	}

	return TRUE;
}

BOOL vmsNewMailWnd::InsertLinkToMailText(HWND hwndNewMailWnd, LPCWSTR pwszText, LPCWSTR pwszHref)
{
	HWND hwnd = FindMailTextWindow (hwndNewMailWnd);
	if (hwnd == NULL)
		return FALSE;

	vmsComSupport comSupport;

	IHTMLDocument2Ptr spDoc = vmsOleAccHelper::GetDocumentFromHWND (hwnd);
	if (spDoc == NULL)
		return FALSE;

	IHTMLElementCollectionPtr spAll;
	spDoc->get_all (&spAll);
	if (spAll == NULL)
		return FALSE;

	IHTMLElementPtr spDiv, spLastDiv;

	long lCount = 0;
	spAll->get_length (&lCount);
	for (long i = 0; i < lCount; i++)
	{
		IDispatchPtr spdisp;
		spAll->item (CComVariant (i), CComVariant (i), &spdisp);

		IHTMLElementPtr spEl (spdisp);

		BSTR bstrTag, bstrText;
		spEl->get_tagName (&bstrTag);
		spEl->get_innerText (&bstrText);
		if ((bstrText == NULL || *bstrText == 0) && wcsicmp (bstrTag, L"DIV") == 0)
			spDiv = spEl;
		else
			spLastDiv = spEl;
		SysFreeString (bstrTag);
		SysFreeString (bstrText);
	}

	if (spDiv == NULL)
		spDiv = spLastDiv;

	if (spDiv != NULL)
	{
		std::wstring wstr;
		wstr = L"<br><a href=\"";
		wstr += pwszHref; 
		wstr += L"\">"; 
		wstr += pwszText;
		wstr += L"</a><br>";
		
		spDiv->insertAdjacentHTML (L"beforeBegin", (LPWSTR)wstr.c_str ());
	}

	return TRUE;
}

std::wstring vmsNewMailWnd::GetSubject(HWND hwndNewMailWnd)
{
	USES_CONVERSION;
	char sz [10000] = "";
	GetWindowText (hwndNewMailWnd, sz, sizeof (sz));
	return A2W (sz);
}

BOOL vmsNewMailWnd::InsertUploadUrlToMailText(HWND hwndNewMailWnd, LPCWSTR pwszPkgName, LPCWSTR pwszUrl)
{
	HWND hwnd = FindMailTextWindow (hwndNewMailWnd);
	if (hwnd == NULL)
		return FALSE;

	vmsComSupport comSupport;

	IHTMLDocument2Ptr spDoc = vmsOleAccHelper::GetDocumentFromHWND (hwnd);
	if (spDoc == NULL)
		return FALSE;

	IHTMLElementCollectionPtr spAll;
	spDoc->get_all (&spAll);
	if (spAll == NULL)
		return FALSE;

	IHTMLElementPtr spDiv, spLastDiv;

	long lCount = 0;
	spAll->get_length (&lCount);
	for (long i = 0; i < lCount; i++)
	{
		IDispatchPtr spdisp;
		spAll->item (CComVariant (i), CComVariant (i), &spdisp);

		IHTMLElementPtr spEl (spdisp);

		BSTR bstrTag, bstrText;
		spEl->get_tagName (&bstrTag);
		spEl->get_innerText (&bstrText);
		if ((bstrText == NULL || *bstrText == 0) && wcsicmp (bstrTag, L"DIV") == 0)
			spDiv = spEl;
		else
			spLastDiv = spEl;
		SysFreeString (bstrTag);
		SysFreeString (bstrText);
	}

	if (spDiv == NULL)
		spDiv = spLastDiv;

	if (spDiv != NULL)
	{
		std::wstring wstr;
		wstr = L"<br>";
		wstr += pwszPkgName; 
		wstr += L":<br>"; 
		wstr += L"<a href=\""; wstr += pwszUrl; wstr += L"\">"; wstr += pwszUrl; 
		wstr += L"</a>";
		wstr += L"<br>";
		
		spDiv->insertAdjacentHTML (L"beforeBegin", (LPWSTR)wstr.c_str ());
	}

	return TRUE;
}

void vmsNewMailWnd::OnUploadFolder(HWND hwndNewMailWnd)
{
	AlsFolderBrowser fb;
	if (FALSE == fb.Create ("Upload folder", NULL, NULL, hwndNewMailWnd))
		return;

	vmsComSupport comSupp;

	IUploaderPtr spUpldr;
	if (FAILED (spUpldr.CreateInstance (__uuidof (FUMUploader))))
		spUpldr.CreateInstance (__uuidof (FDMUploader));

	if (spUpldr == NULL)
		return;

	IUploadPackagePtr spPkg;
	if (FAILED (spPkg.CreateInstance (__uuidof (FUMUploadPackage))))
		spPkg.CreateInstance (__uuidof (FDMUploadPackage));

	USES_CONVERSION;
	std::wstring wstrPkgName;

	LPCSTR psz = strrchr (fb.GetPath (), '\\');
	if (psz [1] != 0)
		psz++;
	else
	{
		while (psz != fb.GetPath () && *(--psz) != '\\');
		if (psz == fb.GetPath ())
			return;
		psz++;
	}
	wstrPkgName = A2W (psz);
	spPkg->Add (SysAllocString (A2W (fb.GetPath ())));

	spPkg->put_Name (SysAllocString (wstrPkgName.c_str ()));

	long lId;
	if (FAILED (spUpldr->CreateUpload (spPkg, TRUE, &lId)))
		return; 

	CComBSTR bstrResUrl;
	spUpldr->GetUploadTargetUrl (lId, &bstrResUrl);

	CComBSTR bstrPkgName;
	spUpldr->GetUploadPackageName (lId, &bstrPkgName);

	if (bstrResUrl.Length () > 0)
		InsertUploadUrlToMailText (hwndNewMailWnd, bstrPkgName, bstrResUrl);
	else
		MessageBox (hwndNewMailWnd, LS (L_FAILED_TO_START_UPLOADING), LS (L_ERR), MB_ICONERROR);
}

void vmsNewMailWnd::CreateContextMenu()
{
	
	HMENU hMenu;
	BOOL bCreated = FALSE;

	if (_m_menuAttachFiles != NULL)
		return;

	if (_m_menuAttachFiles == NULL)
	{
		_m_menuAttachFiles = CreateMenu ();
		
		hMenu = CreateMenu ();
		bCreated = TRUE;

		InsertMenu (hMenu, 0, MF_BYPOSITION | MF_STRING,
			OE_CMDID_ATTACHFILES, LS (L_ATTACH_TO_LETTER));
	}
	else
	{
		hMenu = GetSubMenu (_m_menuAttachFiles, 0);
		HMENU hSubMenu = GetSubMenu (hMenu, 1);
		RemoveMenu (hMenu, 1, MF_BYPOSITION);
		if (hSubMenu)
			DestroyMenu (hSubMenu);
	}

	InsertMenu (hMenu, 1, MF_BYPOSITION | MF_STRING, ID_UPLOADFILES, LS (L_UPLOAD_AND_INSERT_LINK));
	std::string str = LS (L_SETTINGS); str += "...";
	InsertMenu (hMenu, 2, MF_BYPOSITION | MF_STRING, ID_SETTINGS, str.c_str ());

	if (bCreated)
		InsertMenu (_m_menuAttachFiles, 0, MF_BYPOSITION | MF_POPUP, (UINT)hMenu, "-");
}

void vmsNewMailWnd::DetachFromWindow(HWND hwndNewMailWnd)
{
	SetWindowLong (hwndNewMailWnd, GWL_WNDPROC, (LONG)_m_pfnOrigWndProc);

	HWND hwndTb = FindToolbarWindow (hwndNewMailWnd);
	assert (hwndTb != NULL);
	if (hwndTb != NULL)
	{
		TBBUTTONINFO tbbi;
		tbbi.cbSize = sizeof (tbbi);
		tbbi.dwMask = TBIF_STYLE;
		if (-1 != SendMessage (hwndTb, TB_GETBUTTONINFO, OE_CMDID_ATTACHFILES, (LPARAM)&tbbi))
		{
			tbbi.fsStyle &= ~TBSTYLE_DROPDOWN;
			SendMessage (hwndTb, TB_SETBUTTONINFO, OE_CMDID_ATTACHFILES, (LPARAM)&tbbi);
		}
	}
}

void vmsNewMailWnd::OnSettings()
{
	CRegKey key;
	char szPath [MAX_PATH] = ""; DWORD dw = sizeof (szPath);

	if (ERROR_SUCCESS == key.Open (HKEY_CURRENT_USER, "Software\\FreeDownloadManager.ORG\\Free Upload Manager", KEY_READ))
	{
		key.QueryValue (szPath, "Path", &dw);
		if (*szPath)
		{
			if (szPath [lstrlen (szPath) - 1] != '\\')
				lstrcat (szPath, "\\");
			lstrcat (szPath, "fum.exe");
			if (GetFileAttributes (szPath) == DWORD (-1))
				*szPath = 0;
		}
	}

	if (*szPath == 0)
	{
		if (ERROR_SUCCESS == key.Open (HKEY_CURRENT_USER, "Software\\FreeDownloadManager.ORG\\Free Download Manager", KEY_READ))
		{
			dw = sizeof (szPath);
			key.QueryValue (szPath, "Path", &dw);
			if (*szPath)
			{
				if (szPath [lstrlen (szPath) - 1] != '\\')
					lstrcat (szPath, "\\");
				lstrcat (szPath, "fdm.exe");
				if (GetFileAttributes (szPath) == DWORD (-1))
					*szPath = 0;
			}
		}
	}
	
	if (*szPath == 0)
		return;

	ShellExecute (NULL, "open", szPath, "-suis", NULL, SW_SHOW);
}
