/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsImage.h"
#include "vmsAnimatedGIF.h"

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

	char szFile [10000];
	if (pszFile [1] != ':')
	{
		GetCurrentDirectory (sizeof (szFile), szFile);
		lstrcat (szFile, "\\");
		lstrcat (szFile, pszFile);
		pszFile = szFile;
	}

	vmsAnimatedGIF gif;
	if (gif.Load (pszFile))
	{
		

		char szTemp [MAX_PATH];	
		strcpy (szTemp, pszFile);
		int l = lstrlen (szTemp) - 4 - 1;
		strcpy (szTemp + l,  "(%d).gif"); 
		int cFrames = gif.SaveGIFFrames (szTemp);
		for (int i = 0; i < cFrames; i++)
		{
			char sz [MAX_PATH];
			wsprintf (sz, szTemp, i);
			m_vFrames.push_back (LoadImage (sz));
			m_vFrameDelays.push_back (gif.get_FrameInfo (i)->m_nDelay);
			m_vFrameDisps.push_back (gif.get_FrameInfo (i)->m_nDisposal);
			DeleteFile (sz);
		}
		
		m_pImage = m_vFrames [0];
	}
	else
	{
		m_pImage = LoadImage (pszFile);
	}

	return m_pImage ? S_OK : E_FAIL;
}

void vmsImage::Free()
{
	if (m_vFrames.size () != 0)
	{
		m_pImage = NULL;
		for (int i = 0; i < (int)m_vFrames.size (); i++)
			m_vFrames [i]->Release ();
		m_vFrames.clear ();
	}
	else if (m_pImage)
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

void vmsImage::Draw(HDC dc, RECT &rc)
{
	ULONG lC = IMGCHG_ANIMATE;
	lC |= 0x5 << 4;
	m_pImage->SelectChanges (lC, 0, FALSE);

	m_pImage->Draw (dc, &rc);
}

BOOL vmsImage::is_Loaded()
{
	if (m_pImage == NULL)
		return FALSE;

	DWORD dw;
	m_pImage->GetStateInfo (&dw, NULL, FALSE);
	return (dw & IMGLOAD_COMPLETE) != 0;
}

IImgCtx* vmsImage::LoadImage(LPCSTR pszFile)
{
	IImgCtx* pImage = NULL;

	HRESULT hr = CoCreateInstance (CLSID_IImgCtx, NULL, CLSCTX_ALL,
		IID_IImgCtx, (void**)&pImage);
	if (FAILED (hr))
		return NULL;

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

	hr = pImage->Load (wszPath, 0);
	if (FAILED (hr))
	{
		pImage->Release ();		
		return NULL;
	}

	DWORD dwState;
	do {

		hr = pImage->GetStateInfo (&dwState, NULL, FALSE);
		if (FAILED (hr))
		{
			pImage->Release ();
			return NULL;
		}
		if (dwState & IMGLOAD_LOADING)
			Sleep (10);

	} while(IMGLOAD_LOADING & dwState);

	if ((dwState & IMGLOAD_COMPLETE) == 0)
	{
		pImage->Release ();
		return NULL;
	}
	
	return pImage;
}

int vmsImage::get_FrameCount()
{
	return m_vFrames.size ();
}

void vmsImage::set_CurrentFrame(int iIndex)
{
	if ((int)m_vFrames.size () > iIndex)
		m_pImage = m_vFrames [iIndex];
}

UINT vmsImage::get_FrameDelay (int iIndex)
{
	return m_vFrameDelays [iIndex];
}

int vmsImage::get_FrameDisp(int iIndex)
{
	return m_vFrameDisps [iIndex];
}
