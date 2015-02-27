/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#define WINVER 0x501
#define _WIN32_IE 0x501
#define _WIN32_WINNT 0x501

#include "fsFileStream.h"
#include "../system.h"

fsFileStream::fsFileStream()
{
	m_uCurPos = 0;
	m_bMediaIsValid = FALSE;
	m_hFile = m_hIdx1File = INVALID_HANDLE_VALUE;
}

fsFileStream::~fsFileStream ()
{
	Close ();
}

DWORD fsFileStream::Alignment()
{
	return 1;
}

void fsFileStream::Lock()
{
	m_csLock.Lock();
}

void fsFileStream::Unlock()
{
	m_csLock.Unlock();
}

HRESULT fsFileStream::SetPointer(LONGLONG llPos)
{
	m_uCurPos = llPos;
	SetFilePointer (m_hFile, LONG (llPos), NULL, FILE_BEGIN);
	return S_OK;
}

HRESULT fsFileStream::Size(LONGLONG *pllTotal, LONGLONG *pllAvail)
{
	*pllTotal = GetFileSize (m_hFile, NULL);
	if (pllAvail)
		*pllAvail = m_uInMaxAvail == _UI64_MAX ? *pllTotal - m_uCurPos : m_uInMaxAvail;
	return VFW_S_ESTIMATED;
}

typedef struct {
    DWORD  ckid;
    DWORD  dwFlags;
    DWORD  dwChunkOffset;
    DWORD  dwChunkLength;
} AVIINDEXENTRY;

typedef struct {
    DWORD  dwMicroSecPerFrame;
    DWORD  dwMaxBytesPerSec;
    DWORD  dwReserved1;
    DWORD  dwFlags;	
    DWORD  dwTotalFrames;
    DWORD  dwInitialFrames;
    DWORD  dwStreams;
    DWORD  dwSuggestedBufferSize;
    DWORD  dwWidth;
    DWORD  dwHeight;
    DWORD  dwScale;
    DWORD  dwRate;
    DWORD  dwStart;
    DWORD  dwLength;
} MainAVIHeader;

HRESULT fsFileStream::Read(PBYTE pbBuffer, DWORD dwBytesToRead, BOOL bAlign, LPDWORD pdwBytesRead)
{
	CAutoLock lck(&m_csLock);

	BOOL bFilled = FALSE;

	if (m_hIdx1File != INVALID_HANDLE_VALUE)
	{
		
		if (m_uCurPos >= m_idx1.Get_Idx1StartPosition ())
		{
			fsSetFilePointer (m_hIdx1File, m_uCurPos-m_idx1.Get_Idx1StartPosition (), FILE_BEGIN);
			ReadFile (m_hIdx1File, pbBuffer, dwBytesToRead, pdwBytesRead, 0);
			bFilled = TRUE;
		}
	}

	if (m_uCurPos + dwBytesToRead > m_uInMaxAvail)
	{
		if (m_hIdx1File == INVALID_HANDLE_VALUE ||
				m_uCurPos < m_idx1.Get_Idx1StartPosition ())
		{
			if (pdwBytesRead)
				*pdwBytesRead = 0;
			return E_FAIL;
		}
	}
	
	if (bFilled == FALSE)
		ReadFile (m_hFile, pbBuffer, dwBytesToRead, pdwBytesRead, NULL);

	m_uCurPos += dwBytesToRead;
	
	return S_OK;
}

void fsFileStream::Attach(HANDLE hFile, UINT64 uInMaxAvail)
{
	Close ();
	m_hFile = hFile;
	
	m_bMediaIsValid = NULL != m_mtd.DetectMediaType (hFile);
	m_uInMaxAvail = uInMaxAvail;
	if (m_bMediaIsValid)
	{
		
		if (m_mtd.Get_MediaType ()->subtype == MEDIASUBTYPE_Avi && 
			uInMaxAvail != _UI64_MAX)
		{
			

			char szTmp [MAX_PATH], szTmpFile [MAX_PATH];
			GetTempPath (MAX_PATH, szTmp); 
						
			GetTempFileName (szTmp, "afs", 0, szTmpFile);

			m_hIdx1File = CreateFile (szTmpFile, GENERIC_READ|GENERIC_WRITE,
				0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_TEMPORARY | FILE_FLAG_DELETE_ON_CLOSE,
				NULL);

			if (m_hIdx1File != INVALID_HANDLE_VALUE)
			{
				if (FALSE == m_idx1.BuildIdx1 (hFile, m_hIdx1File, uInMaxAvail))
				{
					CloseHandle (m_hIdx1File);
					m_hIdx1File = INVALID_HANDLE_VALUE;
				}
			}
		}
	}
}

void fsFileStream::Close()
{
	HANDLE hFile = Detach ();
	if (hFile != INVALID_HANDLE_VALUE)
		CloseHandle (hFile);
}

const AM_MEDIA_TYPE* fsFileStream::Get_MediaType()
{
	return m_bMediaIsValid ? m_mtd.Get_MediaType () : NULL;
}

HANDLE fsFileStream::Detach()
{
	HANDLE hFile = m_hFile;

	if (m_hFile != INVALID_HANDLE_VALUE)
	{
		if (m_hIdx1File != INVALID_HANDLE_VALUE)
		{
			CloseHandle (m_hIdx1File);
			m_hIdx1File = INVALID_HANDLE_VALUE;
		}

		m_hFile = INVALID_HANDLE_VALUE;
		m_bMediaIsValid = FALSE;
	}

	return hFile;
}
