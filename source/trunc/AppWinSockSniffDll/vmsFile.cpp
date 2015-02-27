/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsFile.h"
using namespace vmsFDM;

vmsFile::vmsFile(HANDLE hFile, bool bAutoClose)
{
	m_hFile = hFile;
	m_bAutoClose = bAutoClose;
	m_bThrowOnPartialRead = true;
}

vmsFile::~vmsFile()
{
	if (m_bAutoClose)
		Close ();
}

void vmsFile::Create(LPCTSTR pszFileName, DWORD dwAccess, DWORD dwShareMode, DWORD dwCreationDisposition, DWORD dwFlags)
{
	Close ();

	m_hFile = CreateFile (pszFileName, dwAccess, dwShareMode, NULL, dwCreationDisposition,
		dwFlags, NULL);

	if (m_hFile == INVALID_HANDLE_VALUE)
		throw GetLastError ();
}

void vmsFile::Close()
{
	if (m_hFile != INVALID_HANDLE_VALUE)
	{
		if (FALSE == CloseHandle (Detach ()))
			throw GetLastError ();
	}
}

void vmsFile::Read(LPVOID pvBuffer, DWORD dwToRead, DWORD *pdwRead)
{
	if (m_hFile == INVALID_HANDLE_VALUE)
		throw ERROR_INVALID_HANDLE;

	DWORD dwRead = 0;

	if (FALSE == ReadFile (m_hFile, pvBuffer, dwToRead, &dwRead, NULL))
		throw GetLastError ();

	if (pdwRead)
		*pdwRead = dwRead;

	if (m_bThrowOnPartialRead && dwRead != dwToRead)
		throw ERROR_BAD_FORMAT;
}

void vmsFile::Write(LPCVOID pvBuffer, DWORD dwToWrite)
{
	if (m_hFile == INVALID_HANDLE_VALUE)
		throw ERROR_INVALID_HANDLE;

	DWORD dwWritten = 0;

	if (FALSE == WriteFile (m_hFile, pvBuffer, dwToWrite, &dwWritten, NULL))
		throw GetLastError ();

	if (dwWritten != dwToWrite)
		throw ERROR_BAD_LENGTH;
}

void vmsFile::Attach(HANDLE hFile, bool bAutoClose)
{
	Close ();
	m_hFile = hFile;
	m_bAutoClose = bAutoClose;
}

HANDLE vmsFile::Detach()
{
	HANDLE h = m_hFile;
	m_hFile = INVALID_HANDLE_VALUE;
	return h;
}

DWORD vmsFile::GetSize()
{
	if (m_hFile == INVALID_HANDLE_VALUE)
		throw ERROR_INVALID_HANDLE;

	return GetFileSize (m_hFile, NULL);
}

void vmsFile::Seek(DWORD dwDistance, DWORD dwMethod)
{
	SetFilePointer (m_hFile, dwDistance, NULL, dwMethod);
}

BOOL fsSaveStrToFile(LPCSTR pszStr, HANDLE hFile)
{
	int len;
	
	if (pszStr == NULL)
		len = -1;
	else
		len = strlen (pszStr);
	
	DWORD dw;
	
	if (!WriteFile (hFile, &len, sizeof (len), &dw, NULL))
		return FALSE;
	
	if (len != -1)
		return WriteFile (hFile, pszStr, len, &dw, NULL);
	
	return TRUE;
}

BOOL fsReadStrFromFile(LPSTR *ppszStr, HANDLE hFile)
{
	int len;
	
	DWORD dw;
	
	if (!ReadFile (hFile, &len, sizeof (len), &dw, NULL) || dw != sizeof (len))
		return FALSE;
	
	if (len != -1)
	{
		if (UINT (len) > 100000)
			return FALSE; 
		
		*ppszStr = new char [len+1];
		if (!ReadFile (hFile, *ppszStr, len, &dw, NULL))
			return FALSE;
		
		if (len != int (dw))
			return FALSE;
		
		(*ppszStr) [len] = 0;
	}
	else
		*ppszStr = NULL;
	
	return TRUE;
}

void vmsFile::WriteString(LPCSTR psz)
{
	if (FALSE == fsSaveStrToFile (psz, m_hFile))
		throw GetLastError ();
}

void vmsFile::ReadString(string& str)
{
	LPSTR psz;
	if (FALSE == fsReadStrFromFile (&psz, m_hFile))
		throw GetLastError ();
	str  = psz;
	delete [] psz;
}

void vmsFile::WriteDouble(double f)
{
	Write (&f, sizeof (f));
}

void vmsFile::WriteInt64(__int64 i)
{
	Write (&i, sizeof (i));
}

void vmsFile::WriteInt(int i)
{
	Write (&i, sizeof (i));
}

void vmsFile::ReadInt(int &i)
{
	Read (&i, sizeof (i));
}

void vmsFile::ReadInt64(__int64 &i)
{
	Read (&i, sizeof (i));
}

void vmsFile::ReadDouble(double &f)
{
	Read (&f, sizeof (f));
}
