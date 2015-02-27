/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FDMCustomized.h"
#include "vmsImage.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsImage::vmsImage()
{
	m_pImage = NULL;
}

vmsImage::~vmsImage()
{
	Free ();
}

HRESULT vmsImage::Load(LPCSTR pszFile)
{
	Free ();

	HRESULT hr = CoCreateInstance (CLSID_IImgCtx, NULL, CLSCTX_INPROC_SERVER,
		IID_IImgCtx, (void**)&m_pImage);
	if (FAILED (hr))
		return hr;

	char szPath [MAX_PATH];
	strcpy (szPath, "file://");
	strcat (szPath, pszFile);
	LPSTR psz = szPath;
	while (*psz)
	{
		if (*psz == '\\')
			*psz = '/';
		psz++;
	}

	wchar_t wszPath [MAX_PATH];
	MultiByteToWideChar (CP_ACP, 0, szPath, lstrlen (szPath), wszPath, MAX_PATH);
	wszPath [lstrlen (szPath)] = 0;

	hr = m_pImage->Load (wszPath, 0);
	if (FAILED (hr))
		return hr;

	DWORD dwState;
	do {

		hr = m_pImage->GetStateInfo (&dwState, NULL, FALSE);
		if (FAILED (hr))
			return hr;
		if (dwState & IMGLOAD_LOADING)
			Sleep (10);

	} while(IMGLOAD_LOADING & dwState);

	if ((dwState & IMGLOAD_COMPLETE) == 0)
		return E_FAIL;

	return S_OK;
}

void vmsImage::Free()
{
	if (m_pImage)
	{
		m_pImage->Release ();
		m_pImage = NULL;
	}
}

CSize vmsImage::get_Size()
{
	DWORD dw;
	SIZE size;
	m_pImage->GetStateInfo (&dw, &size, FALSE);
	return size;
}
