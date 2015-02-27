/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "fsWebPageDownloadsMgr.h"
#include "mfchelp.h"
#include "Utils.h"
#include "vmsLogger.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

fsWebPageDownloadsMgr::fsWebPageDownloadsMgr()
{
	m_pfnEvents = NULL;
}

fsWebPageDownloadsMgr::~fsWebPageDownloadsMgr()
{

}

void fsWebPageDownloadsMgr::Add(fsWebPageDownloader *wpd)
{
	wpd->SetEventFunc (_DownloaderEvents, this);
	m_vWPDs.add (wpd);
	setDirty();
	wpd->setDirty();
	wpd->GetWDPS()->m_ppoOwner = (vmsPersistObject*)wpd;
	getPersistObjectChildren ()->addPersistObject ((vmsPersistObject*)wpd);
}

void fsWebPageDownloadsMgr::_DownloaderEvents(fsWebPageDownloader* dldr, fsWPDEvent ev, fsDownload *dld, fsDLWebPage *wp, fsDLWebPageTree wptree, LPVOID lp)
{
	fsWebPageDownloadsMgr* pThis = (fsWebPageDownloadsMgr*) lp;
	if (pThis->m_pfnEvents)
		pThis->m_pfnEvents (dldr, ev, dld, wp, wptree, pThis->m_lpEventsParam);
}

void fsWebPageDownloadsMgr::SetEventsFunc(fntWPDEvents pfn, LPVOID lp)
{
	m_pfnEvents = pfn;
	m_lpEventsParam = lp;
}

int fsWebPageDownloadsMgr::GetWPDCount()
{
	return m_vWPDs.size ();
}

fsWebPageDownloader* fsWebPageDownloadsMgr::GetWPD(int iIndex)
{
	return m_vWPDs [iIndex];
}

void fsWebPageDownloadsMgr::Delete(fsWebPageDownloader *wpd)
{
	for (int i = 0; i < m_vWPDs.size (); i++)
	{
		if (m_vWPDs [i] == wpd)
		{
			m_vWPDs.del (i);
			setDirty();
			getPersistObjectChildren ()->removePersistObject (i);
			return;
		}
	}
}

BOOL fsWebPageDownloadsMgr::Save()
{
	if (!isDirty())
		return TRUE;

	HANDLE hFile = CreateFile (fsGetDataFilePath ("spider.sav"), GENERIC_WRITE, FILE_SHARE_READ, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_HIDDEN, NULL);

	if (hFile == INVALID_HANDLE_VALUE)
		return FALSE;

	try
	{
		DWORD dw = 0;
		fsSpiderFileHdr hdr;

		if (FALSE == WriteFile (hFile, &hdr, sizeof (hdr), &dw, NULL))
		{
			CloseHandle (hFile);
			return FALSE;
		}

		DWORD dwRequiredSize = 0;

		getStateBuffer(0, &dwRequiredSize, false);

		if (dwRequiredSize == 0)
			return FALSE;

		std::auto_ptr<BYTE> apbtBufferGuard( new BYTE[dwRequiredSize] );
		LPBYTE pbtBuffer = apbtBufferGuard.get();
		if (pbtBuffer == 0)
			return FALSE;
		memset(pbtBuffer, 0, dwRequiredSize);

		getStateBuffer(pbtBuffer, &dwRequiredSize, true);

		if (FALSE == WriteFile (hFile, pbtBuffer, dwRequiredSize, &dw, NULL) || dw != dwRequiredSize) {
			CloseHandle (hFile);
			return FALSE;
		}
		CloseHandle (hFile);
		hFile = INVALID_HANDLE_VALUE;
		onStateSavedSuccessfully();
		
		return TRUE;

	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsWebPageDownloadsMgr::Save " + tstring(ex.what()));
		if (hFile != INVALID_HANDLE_VALUE)
			CloseHandle (hFile);
		return FALSE;
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsWebPageDownloadsMgr::Save unknown exception");
		if (hFile != INVALID_HANDLE_VALUE)
			CloseHandle (hFile);
		return FALSE;
	}
}

void fsWebPageDownloadsMgr::getObjectItselfStateBuffer(LPBYTE pbtBuffer, LPDWORD pdwSize, bool bSaveToStorage)
{
	DWORD dwRequiredSize = 0;
	LPBYTE pbtCurrentPos = pbtBuffer;
	int cWPD = m_vWPDs.size ();

	putVarToBuffer(cWPD, pbtCurrentPos, 0, 0, &dwRequiredSize);

	if (pbtBuffer == NULL) {
		if (pdwSize != 0) {
			*pdwSize = dwRequiredSize;
		}
		return;
	}

	putVarToBuffer(cWPD, pbtCurrentPos, pbtBuffer, *pdwSize, &dwRequiredSize);

	*pdwSize = pbtCurrentPos - pbtBuffer;
}

BOOL fsWebPageDownloadsMgr::Load()
{
	m_vWPDs.clear ();

	HANDLE hFile = CreateFile (fsGetDataFilePath ("spider.sav"), GENERIC_READ, FILE_SHARE_READ, NULL,
		OPEN_ALWAYS, FILE_ATTRIBUTE_HIDDEN, NULL);

	if (hFile == INVALID_HANDLE_VALUE)
		return FALSE;

	if (GetLastError () != ERROR_ALREADY_EXISTS)
	{
		CloseHandle (hFile);
		return TRUE;
	}

	int cWPD = 0;
	DWORD dw;
	fsSpiderFileHdr hdr;
	WORD wVer = SPIDERFILE_CURRENT_VERSION;
	DWORD dwRequiredSize = ::GetFileSize(hFile, NULL);

	if (FALSE == ReadFile (hFile, &hdr, sizeof (hdr), &dw, NULL))
	{
		wVer = 1;
	}
	else
	{
		if (dw < sizeof(hdr) || strcmp (hdr.szSig, SPIDERFILE_SIG))
		{
			wVer = 1;
			SetFilePointer (hFile, 0, NULL, FILE_BEGIN);
		}
		else
		{
			wVer = hdr.wVer;
			dwRequiredSize -= sizeof (hdr);
		}
	}

	if (wVer == 1) {

		if (FALSE == ReadFile (hFile, &cWPD, sizeof (cWPD), &dw, NULL))
		{
			CloseHandle (hFile);
			return FALSE;
		}

		for (int i = 0; i < cWPD; i++)
		{
			fsWebPageDownloaderPtr wpd; wpd.CreateInstance ();
			if (FALSE == wpd->Load (hFile, wVer))
			{
				CloseHandle (hFile);
				return FALSE;
			}
			Add (wpd);
		}

		resetDirty();

		CloseHandle (hFile);
		return TRUE;

	}

	std::auto_ptr<BYTE> pbtBufferGuard( new BYTE[dwRequiredSize] );
	LPBYTE pbtBuffer = pbtBufferGuard.get();
	if (pbtBuffer == 0) {
		CloseHandle (hFile);
		return FALSE;
	}
	memset(pbtBuffer, 0, dwRequiredSize);

	if (!ReadFile (hFile, pbtBuffer, dwRequiredSize, &dw, NULL) || dw != dwRequiredSize) {
		CloseHandle (hFile);
		return FALSE;
	}

	if (!loadFromStateBuffer(pbtBuffer, &dwRequiredSize, hdr.wVer)) {
		getPersistObjectChildren ()->removeAllPersistObjects ();
		m_vWPDs.clear ();
		CloseHandle (hFile);
		return FALSE;
	}

	resetDirty();

	CloseHandle (hFile);
	return TRUE;
}

bool fsWebPageDownloadsMgr::loadObjectItselfFromStateBuffer(LPBYTE pbtBuffer, LPDWORD pdwSize, DWORD dwVer)
{
	int cWPD = 0;

	DWORD dwRequiredSize = 0;
	LPBYTE pbtCurrentPos = pbtBuffer;

	if (!getVarFromBuffer(cWPD, pbtCurrentPos, pbtBuffer, *pdwSize))
		return false;

	for (int i = 0; i < cWPD; i++) {
		fsWebPageDownloaderPtr wpd; 
		wpd.CreateInstance ();
		Add (wpd);
	}

	*pdwSize = pbtCurrentPos - pbtBuffer;
	return true;
}

BOOL fsWebPageDownloadsMgr::OnDownloadRestored(vmsDownloadSmartPtr dld)
{
	for (int i = m_vWPDs.size () - 1; i >= 0; i--)
	{
		fsWebPageDownloader* wpd = m_vWPDs [i];
		if (fsWebPageDownloader::_DldEvents (dld, NULL, DME_DLDRESTORED, wpd))
			return TRUE;
	}

	return FALSE;
}

void fsWebPageDownloadsMgr::StopAll()
{
	for (int i = m_vWPDs.size () - 1; i >= 0; i--)
	{
		fsWebPageDownloader* wpd = m_vWPDs [i];
		wpd->StopDownloading ();
	}
}

bool fsWebPageDownloadsMgr::IsDownloadsMgrRequired()
{
	for (int i = m_vWPDs.size () - 1; i >= 0; i--)
	{
		if (m_vWPDs [i]->isDownloadsMgrRequired ())
			return true;
	}

	return false;
}
