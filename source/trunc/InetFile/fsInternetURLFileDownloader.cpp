/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "fsInternetURLFileDownloader.h"
#include "fsURL.h"
#include "common.h"

fsInternetURLFileDownloader::fsInternetURLFileDownloader()
{
	m_pBuffer = NULL;
	m_pfnEvents = NULL;
}

fsInternetURLFileDownloader::~fsInternetURLFileDownloader()
{
	Free_FileBuffer ();
}

fsInternetResult fsInternetURLFileDownloader::Download(LPCSTR pszUrl)
{
	fsURL url;
	fsInternetResult ir;

	ir = url.Crack (pszUrl);
	if (ir != IR_SUCCESS)
		return ir;

	Event (UFDE_CONNECTING);

	Get_File ()->set_EnableAutoRedirect (TRUE);

	ir = Get_File ()->Open (url.GetInternetScheme (), url.GetHostName (), url.GetUserName (),
		url.GetPassword (), url.GetPort (), url.GetPath (), 0);
	if (ir != IR_SUCCESS)
		return ir;

	m_bAbort = FALSE;

	Event (UFDE_DOWNLOADING);

	Free_FileBuffer ();
	ir = fsDownloadFile (Get_File (), &m_pBuffer, &m_uFileSize, &m_bAbort);

	if (ir == IR_SUCCESS)
		Event (UFDE_DONE);

	return ir;
}

fsInternetResult fsInternetURLFileDownloader::Initialize(fsInternetSession *pSession)
{
	return Get_File ()->Initialize (pSession);
}

void fsInternetURLFileDownloader::Abort()
{
	m_bAbort = TRUE;
	Get_File ()->CloseHandle ();
}

fsInternetURLFile* fsInternetURLFileDownloader::Get_File()
{
	return &m_file;
}

LPBYTE fsInternetURLFileDownloader::Get_FileBuffer()
{
	return m_pBuffer;
}

void fsInternetURLFileDownloader::Free_FileBuffer()
{
	SAFE_DELETE_ARRAY (m_pBuffer);
}

void fsInternetURLFileDownloader::SetEventFunc(fntInternetURLFileDownloaderEvents pfn, LPVOID lpParam)
{
	m_pfnEvents = pfn;
	m_lpEvParam = lpParam;
}

void fsInternetURLFileDownloader::Event(fsInternetURLFileDownloaderEvent ev)
{
	if (m_pfnEvents)
		m_pfnEvents (ev, m_lpEvParam);
}

UINT fsInternetURLFileDownloader::Get_FileSize()
{
	return m_uFileSize;
}
