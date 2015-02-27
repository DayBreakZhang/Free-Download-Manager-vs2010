/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "UploadShellExt.h"
#include "FdmUplShellExts.h"
#include <shlobj.h>

STDMETHODIMP CFdmUplShellExts::get_ShowInExplorerContextMenu(BOOL *pVal)
{
	CRegKey key;

	if (ERROR_SUCCESS != key.Open (HKEY_CURRENT_USER, 
			"Software\\FreeDownloadManager.ORG\\Free Upload Manager\\Settings\\Integration", KEY_ALL_ACCESS))
	{
		*pVal = TRUE;
	}
	else
	{
		DWORD dw = TRUE;
		key.QueryValue (dw, "ShowInExplorerContextMenu");
		*pVal = dw;
	}
	
	return S_OK;
}

STDMETHODIMP CFdmUplShellExts::put_ShowInExplorerContextMenu(BOOL newVal)
{
	CRegKey key;

	if (ERROR_SUCCESS != key.Open (HKEY_CURRENT_USER, 
			"Software\\FreeDownloadManager.ORG\\Free Upload Manager\\Settings\\Integration", KEY_ALL_ACCESS))
	{
		if (ERROR_SUCCESS != key.Create (HKEY_CURRENT_USER, 
				"Software\\FreeDownloadManager.ORG\\Free Upload Manager\\Settings\\Integration"))
			return E_FAIL;
	}

	return ERROR_SUCCESS == key.SetValue (newVal, "ShowInExplorerContextMenu") ? S_OK : E_FAIL;
}

STDMETHODIMP CFdmUplShellExts::get_ShowInSendToContextMenu(BOOL *pVal)
{
	LPITEMIDLIST pidl;
	TCHAR        szSendtoPath [MAX_PATH];
	LPMALLOC     pMalloc;

	if (SUCCEEDED (SHGetSpecialFolderLocation (NULL, CSIDL_SENDTO, &pidl)))
    {
		if (SHGetPathFromIDList (pidl, szSendtoPath))
        {
			PathAppend (szSendtoPath, _T("Free Upload Manager.FdmUplSendToShlExt"));

			*pVal = GetFileAttributes (szSendtoPath) != DWORD (-1);
        }

        if (SUCCEEDED (SHGetMalloc (&pMalloc)))
        {
            pMalloc->Free (pidl);
            pMalloc->Release ();
        }
    }

	return S_OK;
}

STDMETHODIMP CFdmUplShellExts::put_ShowInSendToContextMenu(BOOL newVal)
{
	LPITEMIDLIST pidl;
	TCHAR        szSendtoPath [MAX_PATH];
	HANDLE       hFile;
	LPMALLOC     pMalloc;

	if (SUCCEEDED (SHGetSpecialFolderLocation (NULL, CSIDL_SENDTO, &pidl)))
    {
		if (SHGetPathFromIDList (pidl, szSendtoPath))
        {
			PathAppend (szSendtoPath, _T("Free Upload Manager.FdmUplSendToShlExt"));

			if (newVal)
			{
				hFile = CreateFile (szSendtoPath, GENERIC_WRITE, FILE_SHARE_READ,
		                               NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
			    CloseHandle (hFile);
			}
			else
			{
				DeleteFile (szSendtoPath);
			}
        }

        if (SUCCEEDED (SHGetMalloc (&pMalloc)))
        {
            pMalloc->Free (pidl);
            pMalloc->Release ();
        }
    }

	return S_OK;
}
