/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "UploadShellExt.h"
#include "FdmUplSendToShlExt.h"

#include "../../FUM/FUM_i.h"
#include "../../../Fdm.h"

_COM_SMARTPTR_TYPEDEF (IUploader, __uuidof (IUploader));
_COM_SMARTPTR_TYPEDEF (IUploadPackage, __uuidof (IUploadPackage));

STDMETHODIMP CFdmUplSendToShlExt::DragEnter (IDataObject* pDataObj, DWORD grfKeyState,
                         POINTL pt, DWORD* pdwEffect)
{
	*pdwEffect = DROPEFFECT_NONE;

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

	for (int i = 0; i < cFiles; i++)
	{
		char szFile [MAX_PATH];
		if (0 == DragQueryFile (hDrop, i, szFile, MAX_PATH))
			continue;

		DWORD dwAttribs = GetFileAttributes (szFile);
		if (dwAttribs == DWORD (-1))
			continue;
		
		

		m_vFiles.push_back (szFile);
	}

	GlobalUnlock (stg.hGlobal);
	ReleaseStgMedium (&stg);

	if (m_vFiles.size () == 0)
		return E_INVALIDARG;

	*pdwEffect = DROPEFFECT_COPY;

	return S_OK;
}

STDMETHODIMP CFdmUplSendToShlExt::DragLeave ()
{
	return S_OK;
}

STDMETHODIMP CFdmUplSendToShlExt::Drop (IDataObject* pDataObj, DWORD grfKeyState,
                    POINTL pt, DWORD* pdwEffect)
{
	IUploaderPtr spUpldr;
	if (FAILED (spUpldr.CreateInstance (__uuidof (FUMUploader))))
		spUpldr.CreateInstance (__uuidof (FDMUploader));

	if (spUpldr == NULL)
		return E_FAIL;

	IUploadPackagePtr spPkg;
	if (FAILED (spPkg.CreateInstance (__uuidof (FUMUploadPackage))))
		spPkg.CreateInstance (__uuidof (FDMUploadPackage));

	USES_CONVERSION;
	for (size_t i = 0; i < m_vFiles.size (); i++)
		spPkg->Add (SysAllocString (A2W (m_vFiles [i])));

	long lId;
	if (FAILED (spUpldr->CreateUpload (spPkg, TRUE, &lId)))
	{
		*pdwEffect = DROPEFFECT_NONE;
		return E_FAIL; 
	}

	*pdwEffect = DROPEFFECT_COPY;

	return S_OK;
}