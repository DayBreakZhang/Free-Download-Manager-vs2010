/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSDSHOWFILTERDETECTOR_H__7B357AEC_A90F_4E5D_B217_875875A49469__INCLUDED_)
#define AFX_FSDSHOWFILTERDETECTOR_H__7B357AEC_A90F_4E5D_B217_875875A49469__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include <dshow.h>
#include <limits.h>

class fsDShowFilterDetector  
{
public:
	
	const AM_MEDIA_TYPE* Get_MediaType();
	
	
	const AM_MEDIA_TYPE* DetectMediaType (HANDLE hFile, UINT64 uFileOkLen = _UI64_MAX);

	fsDShowFilterDetector();
	virtual ~fsDShowFilterDetector();

protected:
	UINT64 m_uFileOkLen;
	
	 
	BOOL IsFilterMeets (HANDLE hFile, LPCSTR pszOffset, LPCSTR pszCb, LPCSTR pszMask, LPCSTR pszVal);
	BOOL IsFilterMeets (HANDLE hFile, LPCSTR pszCheckBytes);
	BOOL IsFilterMeets (HANDLE hFile, HKEY hkFilter);
	const AM_MEDIA_TYPE* DetectMediaType (HANDLE hFile, HKEY hkFiltrs);
	AM_MEDIA_TYPE m_mt;
};

#endif 
