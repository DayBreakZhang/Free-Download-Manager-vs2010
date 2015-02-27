/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "fsFtpFiles.h"
#include "fsURL.h"

#pragma warning (disable : 4710)

fsFtpFiles::fsFtpFiles()
{
	m_bReload = TRUE;	
}

fsFtpFiles::~fsFtpFiles()
{

}

fsInternetResult fsFtpFiles::GetList(LPCSTR pszPath)
{
	fsInternetResult ir;

	m_bAbort = FALSE;

	m_strPath = pszPath;

	
	ir = m_pServer->SetCurrentDirectory (pszPath);
	if (ir != IR_SUCCESS)
		return ir;

	
	return BuildList ();
}

fsInternetResult fsFtpFiles::BuildList()
{
	fsInternetResult ir = IR_SUCCESS;
	
	WIN32_FIND_DATA wfd;

	m_vFiles.clear ();

	if (m_bAbort)
		return IR_S_FALSE;

	
	HINTERNET hFind = FtpFindFirstFile (m_pServer->GetHandle (), NULL, &wfd, m_bReload ? INTERNET_FLAG_RELOAD : 0, NULL);

	if (hFind)
	{
		do
		{
			fsFileInfo file;

			if (strcmp (wfd.cFileName, ".") == 0 || strcmp (wfd.cFileName, "..") == 0)
				continue;

			file.strName = wfd.cFileName;
			file.uSize = wfd.nFileSizeLow;
			file.date = wfd.ftLastWriteTime;
			file.bAvailable = TRUE;
			file.bFolder = wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY;

			if (file.strName == NULL)
			{
				InternetCloseHandle (hFind);
				return IR_OUTOFMEMORY;
			}

			
			m_vFiles.add (file);
		}
		while (InternetFindNextFile (hFind, &wfd) && m_bAbort == FALSE);

		if (::GetLastError () != ERROR_NO_MORE_FILES && m_bAbort == FALSE)
			ir = fsWinInetErrorToIR ();

		InternetCloseHandle (hFind);
	}

	if (m_bAbort)
		m_vFiles.clear ();

	return m_bAbort ? IR_S_FALSE : ir;
}

void fsFtpFiles::Abort()
{
	m_bAbort = TRUE;
}

void fsFtpFiles::Reload(BOOL bReload)
{
	m_bReload = bReload;
}

LPCSTR fsFtpFiles::GetLastError()
{
	return m_pServer->GetLastError ();
}

void fsFtpFiles::SetServer(fsFtpConnection *pServer)
{
	m_pServer = pServer;
}
