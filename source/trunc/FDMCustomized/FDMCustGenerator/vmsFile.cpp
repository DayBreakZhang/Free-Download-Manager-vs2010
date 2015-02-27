/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsFile.h"
#include <string>

vmsFile::vmsFile()
{
	m_hFile = INVALID_HANDLE_VALUE;
}

vmsFile::~vmsFile()
{
	Close ();
}

void vmsFile::Close()
{
	if (m_hFile != INVALID_HANDLE_VALUE)
	{
		CloseHandle (m_hFile);
		m_hFile = INVALID_HANDLE_VALUE;
	}
}

void vmsFile::Open(LPCSTR pszFile, BOOL bRead)
{
	Close ();

	m_hFile = CreateFile (pszFile, bRead ? GENERIC_READ : GENERIC_WRITE,
		bRead ? FILE_SHARE_READ : 0, NULL, OPEN_EXISTING, 0, NULL);
	if (m_hFile == INVALID_HANDLE_VALUE)
		throw "failed to open file";
}

void vmsFile::Create(LPCSTR pszFile)
{
	Close ();

	m_hFile = CreateFile (pszFile, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 
		FILE_ATTRIBUTE_NORMAL, NULL);
	if (m_hFile == INVALID_HANDLE_VALUE)
		throw "failed to create file";
}

DWORD vmsFile::get_Size()
{
	return GetFileSize (m_hFile, NULL);
}

void vmsFile::Write(LPCVOID pb, DWORD dwSize)
{
	DWORD dw;
	if (FALSE == WriteFile (m_hFile, pb, dwSize, &dw, NULL))
		throw "failed to write to file";
}

void vmsFile::Read(LPVOID lp, DWORD dwSize)
{
	DWORD dw;
	if (FALSE == ReadFile (m_hFile, lp, dwSize, &dw, NULL))
		throw "failed to read from file";
}

vmsFile::operator HANDLE() const
{
	return m_hFile;
}

DWORD vmsFile::get_Pos()
{
	return SetFilePointer (m_hFile, 0, NULL, FILE_CURRENT);
}

void vmsFile::set_Pos(DWORD dwPos, DWORD dwMethod)
{
	SetFilePointer (m_hFile, dwPos, NULL, dwMethod);
}
