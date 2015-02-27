/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "vmsZip.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsZip::vmsZip()
{
	m_zip = NULL;
}

vmsZip::~vmsZip()
{
	if (m_zip)
		zipClose (m_zip, NULL);
}

BOOL vmsZip::CreateNewZipFile(LPCTSTR ptszFileName)
{
	USES_CONVERSION;
	m_zip = zipOpen (T2A ((LPTSTR)ptszFileName), 0);
	return m_zip != NULL;
}

void vmsZip::CloseZipFile()
{
	if (m_zip)
	{
		zipClose (m_zip, NULL);
		m_zip = NULL;
	}
}

BOOL vmsZip::AddBuffer(LPCVOID pData, DWORD dwDataSize, LPCTSTR ptszName)
{
	USES_CONVERSION;

	zip_fileinfo zfileinfo = {0};
    struct _stat file_stat = {0};

	if (ZIP_OK != zipOpenNewFileInZip (m_zip, T2A ((LPTSTR)ptszName), &zfileinfo, NULL, 0, NULL, 0, NULL, Z_DEFLATED, 9))
		return FALSE;

	if (ZIP_OK != zipWriteInFileInZip (m_zip, pData, dwDataSize))
		return FALSE;

	if (Z_OK != zipCloseFileInZip (m_zip))
		return FALSE;

	return TRUE;
}

BOOL vmsZip::AddFile(LPCTSTR ptszFileName, LPCTSTR ptszName)
{
	HANDLE hFile = CreateFile (ptszFileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
		return FALSE;
	DWORD dwDataSize = GetFileSize (hFile, NULL);
	LPVOID pData = new BYTE [dwDataSize];
	ReadFile (hFile, pData, dwDataSize, &dwDataSize, NULL);
	CloseHandle (hFile);
	AddBuffer (pData, dwDataSize, ptszName);
	return TRUE;
}
