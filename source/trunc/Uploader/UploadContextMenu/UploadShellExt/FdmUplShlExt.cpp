/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "UploadShellExt.h"
#include "FdmUplShlExt.h"

#include "../../FUM/FUM_i.h"
#include "../../../Fdm.h"

_COM_SMARTPTR_TYPEDEF (IUploader, __uuidof (IUploader));
_COM_SMARTPTR_TYPEDEF (IUploadPackage, __uuidof (IUploadPackage));

STDMETHODIMP CFdmUplShlExt::Initialize(LPCITEMIDLIST pidlFolder, IDataObject *pDataObj, HKEY hkeyProgID)
{
	CRegKey key;
	if (ERROR_SUCCESS == key.Open (HKEY_CURRENT_USER, 
			"Software\\FreeDownloadManager.ORG\\Free Upload Manager\\Settings\\Integration", KEY_READ))
	{
		DWORD dw = TRUE;
		key.QueryValue (dw, "ShowInExplorerContextMenu");
		if (dw == FALSE)
			return E_FAIL;
	}

	FORMATETC fmt = { CF_HDROP, NULL, DVASPECT_CONTENT, -1, TYMED_HGLOBAL };
	STGMEDIUM stg = { TYMED_HGLOBAL };
	HDROP hDrop;

	if (FAILED (pDataObj->GetData (&fmt, &stg)))
		return E_INVALIDARG;

	hDrop = (HDROP) GlobalLock (stg.hGlobal);

	if (hDrop == NULL)
		return E_INVALIDARG;

	int cFiles = DragQueryFile (hDrop, 0xFFFFFFFF, NULL, 0);

	if (cFiles == 0)
	{
		GlobalUnlock (stg.hGlobal);
		ReleaseStgMedium (&stg);
		return E_INVALIDARG;
	}

	bool bHasNotLnkFiles = false;

	for (int i = 0; i < cFiles; i++)
	{
		char szFile [MAX_PATH];
		if (0 == DragQueryFile (hDrop, i, szFile, MAX_PATH))
			continue;

		DWORD dwAttribs = GetFileAttributes (szFile);
		if (dwAttribs == DWORD (-1))
			continue;

		if (bHasNotLnkFiles == false)
		{
			LPSTR psz = strrchr (szFile, '.');
			if (psz == NULL || stricmp (psz + 1, "lnk"))
				bHasNotLnkFiles = true;
		}
		
		

		m_vFiles.push_back (szFile);
	}

	GlobalUnlock (stg.hGlobal);
	ReleaseStgMedium (&stg);

	if (bHasNotLnkFiles == false)
		return E_INVALIDARG;

	return S_OK;
}

STDMETHODIMP CFdmUplShlExt::GetCommandString(UINT_PTR idCmd, UINT uFlags, UINT *pwReserved, LPSTR pszName, UINT cchMax)
{
	return E_INVALIDARG;
}

STDMETHODIMP CFdmUplShlExt::InvokeCommand(LPCMINVOKECOMMANDINFO pCmdInfo)
{
	if (0 != HIWORD (pCmdInfo->lpVerb))
		return E_INVALIDARG;

	int nCmd = LOWORD (pCmdInfo->lpVerb);

	IUploaderPtr spUpldr;
	if (FAILED (spUpldr.CreateInstance (__uuidof (FUMUploader))))
		spUpldr.CreateInstance (__uuidof (FDMUploader));

	if (spUpldr == NULL)
		return E_FAIL;

	IUploadPackagePtr spPkg;
	if (FAILED (spPkg.CreateInstance (__uuidof (FUMUploadPackage))))
		spPkg.CreateInstance (__uuidof (FDMUploadPackage));;

	USES_CONVERSION;
	for (size_t i = 0; i < m_vFiles.size (); i++)
		spPkg->Add (SysAllocString (A2W (m_vFiles [i])));

	long lId;
	if (FAILED (spUpldr->CreateUpload (spPkg, TRUE, &lId)))
		return S_FALSE; 

	return S_OK;
}

STDMETHODIMP CFdmUplShlExt::QueryContextMenu(HMENU hmenu, UINT uMenuIndex, UINT uidFirstCmd, UINT idCmdLast, UINT uFlags)
{
	if (uFlags & CMF_DEFAULTONLY)
		return MAKE_HRESULT (SEVERITY_SUCCESS, FACILITY_NULL, 0);

	char sz [1000] = "";

	CRegKey key;
	if (ERROR_SUCCESS == key.Open (HKEY_CURRENT_USER, 
			"Software\\FreeDownloadManager.ORG\\Free Upload Manager\\Settings\\Integration", KEY_READ))
	{
		DWORD dw = sizeof (sz);
		key.QueryValue (sz, "UploadString", &dw);
	}

	InsertMenu (hmenu, uMenuIndex++, MF_BYPOSITION, MF_SEPARATOR, 0);
	InsertMenu (hmenu, uMenuIndex, MF_BYPOSITION, uidFirstCmd, *sz ? sz : "Upload");
	
	
	return MAKE_HRESULT (SEVERITY_SUCCESS, FACILITY_NULL, 2);
}
