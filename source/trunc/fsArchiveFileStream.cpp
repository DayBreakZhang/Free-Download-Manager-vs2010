/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fsArchiveFileStream.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

using namespace fsArchive;

fsArchiveFileStream::fsArchiveFileStream()
{
	m_hFile = INVALID_HANDLE_VALUE;
}

fsArchiveFileStream::~fsArchiveFileStream()
{
	Close ();
}

int fsArchiveFileStream::Read(LPVOID buf, int cBytes)
{
	DWORD dwRead;

	if (FALSE == ReadFile (m_hFile, buf, cBytes, &dwRead, 
			NULL))
		return -1;

	return dwRead;
}

int fsArchiveFileStream::Write(LPVOID buf, int cBytes)
{
	DWORD dwWritten;

	if (FALSE == WriteFile (m_hFile, buf, cBytes, &dwWritten, 
			NULL))
		return -1;

	return dwWritten;
}

BOOL fsArchiveFileStream::Seek(UINT64 dist, fsSeekType met)
{
	DWORD dwMet;
	switch (met)
	{
		case ST_CURRENT:
			dwMet = FILE_CURRENT;
			break;

		case ST_END:
			dwMet = FILE_END;
			break;

		case ST_BEGIN:
			dwMet = FILE_BEGIN;
			break;

		default:
			return FALSE;
	}

	return fsSetFilePointer (m_hFile, dist, dwMet);
}

DWORD fsArchiveFileStream::Open(LPCSTR pszFile, DWORD dwGenFlags)
{
	m_hFile = CreateFile (pszFile, dwGenFlags, FILE_SHARE_READ | FILE_SHARE_WRITE, 
		NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if (m_hFile == INVALID_HANDLE_VALUE)
		return GetLastError ();

	return NOERROR;
}

void fsArchiveFileStream::Close()
{
	if (m_hFile != INVALID_HANDLE_VALUE)
	{
		CloseHandle (m_hFile);
		m_hFile = INVALID_HANDLE_VALUE;
	}
}

void fsArchiveFileStream::Attach(HANDLE hFile)
{
	Close ();
	m_hFile = hFile;
}

HANDLE fsArchiveFileStream::Detach()
{
	HANDLE h = m_hFile;
	m_hFile = INVALID_HANDLE_VALUE;
	return h;
}
