/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsSharedData.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsSharedData::vmsSharedData(LPCSTR pszName, BOOL bOpenExisting, DWORD dwSize)
{
	m_hFileMapping = NULL;
	m_pViewOfFile  = NULL;

	if (pszName)
		Aquire (pszName, bOpenExisting, dwSize);
}

vmsSharedData::~vmsSharedData()
{
	Release ();
}

BOOL vmsSharedData::Aquire(LPCSTR pszName, BOOL bOpenExisting, DWORD dwSize)
{
	Release ();

	if (pszName == NULL)
		return FALSE;

	if (bOpenExisting == FALSE)
		m_hFileMapping = CreateFileMapping (INVALID_HANDLE_VALUE,
			NULL, PAGE_READWRITE, 0, dwSize, pszName);
	else
		m_hFileMapping = OpenFileMapping (FILE_MAP_ALL_ACCESS, FALSE, pszName);

	if (m_hFileMapping == NULL)
		return FALSE;

	

	m_pViewOfFile = MapViewOfFile (m_hFileMapping, FILE_MAP_ALL_ACCESS,
		0, 0, 0);

	if (m_pViewOfFile == NULL)
		return FALSE;

	return TRUE;
}

void vmsSharedData::Release()
{
	if (m_hFileMapping)
	{
		if (m_pViewOfFile)
			UnmapViewOfFile (m_pViewOfFile);
		CloseHandle (m_hFileMapping);

		m_hFileMapping = NULL;
		m_pViewOfFile  = NULL;
	}
}

LPVOID vmsSharedData::get_Data()
{
	return m_pViewOfFile;
}
