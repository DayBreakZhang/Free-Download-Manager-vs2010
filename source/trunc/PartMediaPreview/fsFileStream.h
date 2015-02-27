/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FILESTREAM_H__12E13660_1A04_4D65_9212_886BC37480EB__INCLUDED_)
#define AFX_FILESTREAM_H__12E13660_1A04_4D65_9212_886BC37480EB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include <dshow.h>
#include <DShow/wxdebug.h>
#include <DShow/combase.h>
#include <DShow/wxutil.h>
#include <DShow/wxlist.h>
#include <DShow/asyncio.h>
#include "fsDShowFilterDetector.h"	
#include "fsAVIIdx1Builder.h"	

class fsFileStream : public CAsyncStream  
{
public:
	HANDLE Detach();
	const AM_MEDIA_TYPE* Get_MediaType();
	void Close();
	
	
	void Attach (HANDLE hFile, UINT64 uInMaxAvail = _UI64_MAX);
	HRESULT Read (PBYTE pbBuffer, DWORD dwBytesToRead, BOOL bAlign, LPDWORD pdwBytesRead);
	HRESULT Size (LONGLONG* pllTotal, LONGLONG* pllAvail);
	HRESULT SetPointer (LONGLONG llPos);
	void Unlock();
	void Lock();
	DWORD Alignment();
	fsFileStream ();
	virtual ~fsFileStream();

protected:
	UINT64 m_uInMaxAvail;
	HANDLE m_hIdx1File;
	fsAVIIdx1Builder m_idx1;	
	BOOL m_bMediaIsValid;
	fsDShowFilterDetector m_mtd;
	UINT64 m_uCurPos;
	CCritSec m_csLock;
	HANDLE m_hFile;
};

#endif 
