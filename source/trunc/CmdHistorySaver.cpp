/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "StdAfx.h"
#include "mfchelp.h"
#include "CmdHistorySaver.h"

CCmdHistorySaver& CCmdHistorySaver::Instance()
{
	static CCmdHistorySaver chsSaver;
	return chsSaver;
}

CCmdHistorySaver::~CCmdHistorySaver()
{
}

void CCmdHistorySaver::Save()
{
	if (!isDirty())
		return;

	DWORD dwRequiredSize = 0;
	DWORD dw = 0;
	std::auto_ptr<BYTE> apbtBufferGuard;
	fsHistFileHdr hdr;

	HANDLE hFile = CreateFile (fsGetDataFilePath ("history.sav"), GENERIC_WRITE, 0, NULL, 
		CREATE_ALWAYS, FILE_ATTRIBUTE_HIDDEN, NULL);

	if (hFile == INVALID_HANDLE_VALUE)
	{
		goto _lErr;
	}

	if (FALSE == WriteFile (hFile, &hdr, sizeof(hdr), &dw, NULL) || dw != sizeof(hdr)) {
		goto _lErr;
	}

	getStateBuffer(0, &dwRequiredSize, false);

	if (dwRequiredSize == 0)
		goto _lErr;

	apbtBufferGuard.reset( new BYTE[dwRequiredSize] );
	LPBYTE pbtBuffer = apbtBufferGuard.get();
	if (pbtBuffer == 0)
		goto _lErr;
	memset(pbtBuffer, 0, dwRequiredSize);

	getStateBuffer(pbtBuffer, &dwRequiredSize, true);

	if (FALSE == WriteFile (hFile, pbtBuffer, dwRequiredSize, &dw, NULL) || dw != dwRequiredSize) {
		goto _lErr;
	}
	CloseHandle (hFile);
	onStateSavedSuccessfully();

	return;

_lErr:
	if (hFile != INVALID_HANDLE_VALUE)
		CloseHandle (hFile);

	DeleteFile (fsGetDataFilePath ("history.sav"));
}

void CCmdHistorySaver::Load()
{
	DWORD dwRequiredSize = 0;
	DWORD dw = 0;
	std::auto_ptr<BYTE> pbtBufferGuard;
	fsHistFileHdr hdr;

	_HsMgr.ReadSettings ();

	
	HANDLE hFile = CreateFile (fsGetDataFilePath ("history.sav"), GENERIC_READ, FILE_SHARE_READ, NULL, 
		OPEN_EXISTING, 0, NULL);

	if (hFile == INVALID_HANDLE_VALUE)
	{
		if (GetLastError () != ERROR_FILE_NOT_FOUND)
			goto _lErr;
		return;
	}

	dwRequiredSize = ::GetFileSize(hFile, NULL);

	if (!ReadFile (hFile, &hdr, sizeof(hdr), &dw, NULL) || dw != sizeof(hdr)) {
		goto _lErr;
	}

	dwRequiredSize -= sizeof(hdr);

	if (dwRequiredSize <= 0) {
		return;
	}

	if (hdr.wVer <= 1) {
		if (INVALID_SET_FILE_POINTER == ::SetFilePointer(hFile, -sizeof(hdr), 0, FILE_CURRENT))
			goto _lErr;

		
		if (!_LastUrlFiles.ReadFromFile (hFile))
			goto _lErr;

		
		if (!_LastUrlPaths.ReadFromFile (hFile))
			goto _lErr;

		
		if (!_LastFolders.ReadFromFile (hFile))
			goto _lErr;

		
		if (!_LastBatchUrls.ReadFromFile (hFile))
			goto _lErr;

		
		if (!_LastFind.ReadFromFile (hFile))
			goto _lErr;

		if (!_LastFlashVideoUrls.ReadFromFile (hFile))
			goto _lErr;

		if (!_LastFlashVideoDstFolders.ReadFromFile (hFile))
			goto _lErr;

		CloseHandle (hFile);

	return;
	}

	pbtBufferGuard.reset( new BYTE[dwRequiredSize] );
	LPBYTE pbtBuffer = pbtBufferGuard.get();
	if (pbtBuffer == 0) {
		goto _lErr;
	}
	memset(pbtBuffer, 0, dwRequiredSize);

	if (!ReadFile (hFile, pbtBuffer, dwRequiredSize, &dw, NULL) || dw != dwRequiredSize) {
		goto _lErr;
	}
	CloseHandle (hFile);

	if (!loadFromStateBuffer(pbtBuffer, &dwRequiredSize, hdr.wVer))
		goto _lErr;

	return;

_lErr:
	if (hFile != INVALID_HANDLE_VALUE)
		CloseHandle (hFile);
}

CCmdHistorySaver::CCmdHistorySaver()
{
}

CCmdHistorySaver::CCmdHistorySaver(const CCmdHistorySaver&)
{
}

CCmdHistorySaver& CCmdHistorySaver::operator = (const CCmdHistorySaver&)
{
	return *this;
}

void CCmdHistorySaver::getObjectItselfStateBuffer(LPBYTE pbtBuffer, LPDWORD pdwSize, bool bSaveToStorage)
{
	if (pdwSize)
		*pdwSize = 0;
}

bool CCmdHistorySaver::loadObjectItselfFromStateBuffer(LPBYTE pbtBuffer, LPDWORD pdwSize, DWORD dwVer)
{
	if (pdwSize)
		*pdwSize = 0;
	return true;
}
