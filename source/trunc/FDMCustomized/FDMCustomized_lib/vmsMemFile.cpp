/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "vmsMemFile.h"

vmsMemFile::vmsMemFile()
{
	m_pbFile  = NULL;
}

vmsMemFile::~vmsMemFile()
{
	if (m_pbFile)
		delete [] m_pbFile;
}

void vmsMemFile::Use(HANDLE hFile, BOOL bRead)
{
	m_hFile = hFile;
	m_bRead = bRead;
	m_dwPos = 0;

	if (m_pbFile)
		delete [] m_pbFile;

	if (bRead)
	{
		m_dwSize = GetFileSize (m_hFile, NULL);
		m_pbFile = new BYTE [m_dwSize];
		DWORD dw;
		if (FALSE == ::ReadFile (m_hFile, m_pbFile, m_dwSize, &dw, NULL))
			throw _pszMemFileError;
	}
	else
	{
		m_dwSize = 100*1024;
		m_pbFile = new BYTE [m_dwSize];
	}
}

void vmsMemFile::Done()
{
	DWORD dw;

	if (m_bRead == FALSE)
		if (FALSE == ::WriteFile (m_hFile, m_pbFile, m_dwPos, &dw, NULL))
			throw _pszMemFileError;		
}

LPBYTE vmsMemFile::get_FileBuffer()
{
	return m_pbFile;
}

DWORD vmsMemFile::get_FileBufferSize()
{
	return m_bRead ? m_dwSize : m_dwPos;
}

void vmsMemFile::ReadFile(LPVOID pb, DWORD dwSize)
{
	if (m_dwSize < m_dwPos + dwSize)
		throw _pszMemFileError;
	
	CopyMemory (pb, m_pbFile + m_dwPos, dwSize);
	m_dwPos += dwSize;
}

void vmsMemFile::WriteFile(LPCVOID pb, DWORD dwSize)
{
	if (m_dwSize < m_dwPos + dwSize)
	{
		LPBYTE pb = new BYTE [m_dwSize];
		CopyMemory (pb, m_pbFile, m_dwPos);
		delete [] m_pbFile;
		m_pbFile = pb;
		m_dwSize += dwSize + 100*1024;
	}

	CopyMemory (m_pbFile + m_dwPos, pb, dwSize);
	m_dwPos += dwSize;
}
