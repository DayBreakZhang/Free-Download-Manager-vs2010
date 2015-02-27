/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "fsDownloadRegSaver.h"
#include "DownloadsWnd.h"
#include "fsDownloadMgr.h"
#include "system.h"
#include "mfchelp.h"
#include "vmsLogger.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

fsDownloadRegSaver::fsDownloadRegSaver()
{
	
}

fsDownloadRegSaver::~fsDownloadRegSaver()
{

}

fsDLLoadResult fsDownloadRegSaver::Load (vmsDownloadList& vDownloads, LPCSTR pszFileName, BOOL bDontLoadIfTooLarge, fsDLLoadFromType lt, BOOL bErrIfNotExists)
{
	HANDLE hFile = INVALID_HANDLE_VALUE;
	fsDLLoadFromType nlt = DLLFT_SAV; 
	fsDLFileHdr hdr;
	fsString strFileName = pszFileName;
	LPBYTE pBuffer = NULL;

	switch (lt)
	{
	case DLLFT_SAV:
		strFileName += ".sav";
		nlt = DLLFT_BAK;
		break;

	case DLLFT_BAK:
		strFileName += ".bak";
		nlt = DLLFT_SAV;
		break;
	}

	strFileName = fsGetDataFilePath (strFileName);

	if (GetFileAttributes (strFileName) == UINT (-1))
	{
		
		if (nlt == DLLFT_SAV)
			return bErrIfNotExists == FALSE ? DLLR_SUCCEEDED : DLLR_FAILED;
		else
			return Load (vDownloads, pszFileName, bDontLoadIfTooLarge, nlt, bErrIfNotExists);	

	}

	hFile = CreateFile (strFileName, GENERIC_READ, FILE_SHARE_READ, NULL,
			OPEN_ALWAYS, 0, NULL);

	
	
	
	bErrIfNotExists = TRUE;
	

	if (hFile == INVALID_HANDLE_VALUE)
		goto _lErr;

	if (bDontLoadIfTooLarge && 5*1024*1024 < GetFileSize (hFile, NULL))
	{
		CloseHandle (hFile);
		return DLLR_TOOLARGESIZE;
	}

	DWORD dwFileSize;	
	DWORD dw;
	BOOL bUseOLD;
	WORD wVer;

	dwFileSize = GetFileSize (hFile, NULL);
	bUseOLD = FALSE;	
	wVer = 0;	

	
	if (FALSE == ReadFile (hFile, &hdr, sizeof (hdr), &dw, NULL) || 
			strnicmp (hdr.szSig, DLFILE_SIG, strlen (DLFILE_SIG)) )
	{
		
		SetFilePointer (hFile, 0, NULL, FILE_BEGIN);
		bUseOLD = TRUE;
	}
	else
	{
		dwFileSize -= dw;  
		wVer = hdr.wVer;
		if (wVer > DLFILE_CURRENT_VERSION)
			goto _lErr;
	}

	vDownloads.DeleteAll();

	if (wVer > 16) {

		fsnew (pBuffer, BYTE, dwFileSize);

		if (!ReadFile (hFile, pBuffer, dwFileSize, &dw, NULL) || dw != dwFileSize)
			goto _lErr;
		CloseHandle (hFile);
		hFile = INVALID_HANDLE_VALUE;

		
		
		vmsDownloadList tmp;
		
		
		if (!tmp.loadFromStateBuffer(pBuffer, &dwFileSize, wVer))
			goto _lErr;

		vDownloads = tmp;

		return DLLR_SUCCEEDED;
	}

	
	while (dwFileSize)
	{
		DWORD dwSize;

		pBuffer = NULL;
		
		vmsDownloadSmartPtr dld;
		dld.CreateInstance ();
		

		
		if (!ReadFile (hFile, &dwSize, sizeof (dwSize), &dw, NULL) || dw != sizeof (dwSize))
			goto _lErr;

		if (dwFileSize < sizeof (dwSize) + dwSize)
			goto _lErr;

		
		dwFileSize -= sizeof (dwSize) + dwSize;

		fsnew (pBuffer, BYTE, dwSize);

		
		if (!ReadFile (hFile, pBuffer, dwSize, &dw, NULL) || dw != dwSize)
			goto _lErr;

		

		try{

		if (bUseOLD)
		{
			if (FALSE == OLD_LoadDownload (dld, pBuffer, &dwSize))
				goto _lErr;
		}
		else
		{
			if (FALSE == LoadDownload (dld, pBuffer, &dwSize, wVer))
				goto _lErr;
		}

		}catch (...) {goto _lErr;}

		delete [] pBuffer;

		vDownloads.Add(dld);
	}

	CloseHandle (hFile);
	
	return DLLR_SUCCEEDED;

_lErr:
	if (hFile != INVALID_HANDLE_VALUE)
		CloseHandle (hFile);

	if (pBuffer)
		delete [] pBuffer;

	if (lt != DLLFT_SAV)
		DeleteFile (strFileName);	

	if (nlt == DLLFT_SAV)		
		return DLLR_FAILED;
		
	
	return Load (vDownloads, pszFileName, bDontLoadIfTooLarge, nlt, bErrIfNotExists);
}

BOOL fsDownloadRegSaver::Save(vmsDownloadList& vDownloads, LPCSTR pszFileName)
{
	

	
	
	
	size_t szIndex = 0;
	for (szIndex = 0; szIndex < vDownloads.size(); szIndex++) {
		vmsDownloadSmartPtr& dldCur = vDownloads[szIndex];
		if (dldCur->pMgr && dldCur->pMgr->IsTp()) {
			vmsTpDownloadMgr* pTpMgr = dldCur->pMgr->GetTpDownloadMgr();
			if (pTpMgr) {
				pTpMgr->GetStreamingSpeed();
				pTpMgr->GetDownloadedBytesCount();
				pTpMgr->GetNumberOfSections();
				pTpMgr->GetTotalFilesSize();
				pTpMgr->GetPercentDone();
			}
		}
	}

	if (!vDownloads.isDirty())
		return TRUE;

	fsString strFileName = pszFileName;
	fsString strFileNameBak = pszFileName;

	strFileName += ".sav";
	strFileNameBak += ".bak";

	strFileName = fsGetDataFilePath (strFileName);
	strFileNameBak = fsGetDataFilePath (strFileNameBak);

	
	HANDLE hFile = CreateFile (strFileNameBak, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS,
		FILE_ATTRIBUTE_HIDDEN, NULL);

	if (hFile == INVALID_HANDLE_VALUE)
		return FALSE;

	DWORD dw;

	
	fsDLFileHdr hdr;
	if (FALSE == WriteFile (hFile, &hdr, sizeof (hdr), &dw, NULL))
	{
		CloseHandle (hFile);
		return FALSE;
	}

	DWORD dwSize = 0;
	LPBYTE pBuffer = NULL;

	try 
	{
		vDownloads.getStateBuffer(0, &dwSize, false);
		fsnew (pBuffer, BYTE, dwSize);
		vDownloads.getStateBuffer(pBuffer, &dwSize, true);
	} 
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadRegSaver::Save " + tstring(ex.what()));

		if (pBuffer)
			delete [] pBuffer;
		CloseHandle (hFile);
		return FALSE;
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadRegSaver::Save unknown exception");

		if (pBuffer)
			delete [] pBuffer;
		CloseHandle (hFile);
		return FALSE;
	}

	if (FALSE == WriteFile (hFile, pBuffer, dwSize, &dw, NULL)) 
	{
		if (pBuffer)
			delete [] pBuffer;
		CloseHandle (hFile);
		return FALSE;
	}

	if (pBuffer)
		delete [] pBuffer;

	BOOL bOK = FlushFileBuffers (hFile);
	BOOL bOK2 = CloseHandle (hFile);

	if (!bOK || !bOK2)
		return FALSE;

	if (GetFileAttributes (strFileName) != DWORD (-1))
	{
		
		SetFileAttributes (strFileName, FILE_ATTRIBUTE_HIDDEN);
		DeleteFile (strFileName);
	}

	
	bOK = MoveFile (strFileNameBak, strFileName);

	vDownloads.onStateSavedSuccessfully();

	return bOK;
}

fsDLLoadResult fsDownloadRegSaver::Load(t_downloads *vDownloads, LPCSTR pszFileName, BOOL bDontLoadIfTooLarge, fsDLLoadFromType lt, BOOL bErrIfNotExists)
{
	HANDLE hFile = INVALID_HANDLE_VALUE;
	fsDLLoadFromType nlt = DLLFT_SAV; 
	fsDLFileHdr hdr;
	fsString strFileName = pszFileName;
	LPBYTE pBuffer = NULL;

	switch (lt)
	{
	case DLLFT_SAV:
		strFileName += ".sav";
		nlt = DLLFT_BAK;
		break;

	case DLLFT_BAK:
		strFileName += ".bak";
		nlt = DLLFT_SAV;
		break;
	}

	strFileName = fsGetDataFilePath (strFileName);

	if (GetFileAttributes (strFileName) == UINT (-1))
	{
		
		if (nlt == DLLFT_SAV)
			return bErrIfNotExists == FALSE ? DLLR_SUCCEEDED : DLLR_FAILED;
		else
			return Load (vDownloads, pszFileName, bDontLoadIfTooLarge, nlt, bErrIfNotExists);	

	}

	hFile = CreateFile (strFileName, GENERIC_READ, FILE_SHARE_READ, NULL,
			OPEN_ALWAYS, 0, NULL);

	
	
	
	bErrIfNotExists = TRUE;
	

	if (hFile == INVALID_HANDLE_VALUE)
		goto _lErr;

	if (bDontLoadIfTooLarge && 5*1024*1024 < GetFileSize (hFile, NULL))
	{
		CloseHandle (hFile);
		return DLLR_TOOLARGESIZE;
	}

	DWORD dwFileSize;	
	DWORD dw;
	BOOL bUseOLD;
	WORD wVer;

	dwFileSize = GetFileSize (hFile, NULL);
	bUseOLD = FALSE;	
	wVer = 0;	

	
	if (FALSE == ReadFile (hFile, &hdr, sizeof (hdr), &dw, NULL) || 
			strnicmp (hdr.szSig, DLFILE_SIG, strlen (DLFILE_SIG)) )
	{
		
		SetFilePointer (hFile, 0, NULL, FILE_BEGIN);
		bUseOLD = TRUE;
	}
	else
	{
		dwFileSize -= dw;  
		wVer = hdr.wVer;
		if (wVer > DLFILE_CURRENT_VERSION)
			goto _lErr;
	}

	vDownloads->clear ();

	
	while (dwFileSize)
	{
		DWORD dwSize;

		pBuffer = NULL;
		
		vmsDownloadSmartPtr dld;
		dld.CreateInstance ();
		

		
		if (!ReadFile (hFile, &dwSize, sizeof (dwSize), &dw, NULL) || dw != sizeof (dwSize))
			goto _lErr;

		if (dwFileSize < sizeof (dwSize) + dwSize)
			goto _lErr;

		
		dwFileSize -= sizeof (dwSize) + dwSize;

		fsnew (pBuffer, BYTE, dwSize);

		
		if (!ReadFile (hFile, pBuffer, dwSize, &dw, NULL) || dw != dwSize)
			goto _lErr;

		

		try
		{
			if (bUseOLD)
			{
				if (FALSE == OLD_LoadDownload (dld, pBuffer, &dwSize))
					goto _lErr;
			}
			else
			{
				if (FALSE == LoadDownload (dld, pBuffer, &dwSize, wVer))
					goto _lErr;
			}
		}
		catch (const std::exception& ex)
		{
			ASSERT (FALSE);
			vmsLogger::WriteLog("fsDownloadRegSaver::Load " + tstring(ex.what()));
			goto _lErr;
		}
		catch (...)
		{
			ASSERT (FALSE);
			vmsLogger::WriteLog("fsDownloadRegSaver::Load unknown exception");
			goto _lErr;
		}

		delete [] pBuffer;

		vDownloads->push_back (dld);
	}

	CloseHandle (hFile);
	
	return DLLR_SUCCEEDED;

_lErr:
	if (hFile != INVALID_HANDLE_VALUE)
		CloseHandle (hFile);

	if (pBuffer)
		delete [] pBuffer;

	if (lt != DLLFT_SAV)
		DeleteFile (strFileName);	

	if (nlt == DLLFT_SAV)		
		return DLLR_FAILED;
		
	
	return Load (vDownloads, pszFileName, bDontLoadIfTooLarge, nlt, bErrIfNotExists);
}

BOOL fsDownloadRegSaver::LoadDownload(vmsDownloadSmartPtr dld, LPVOID lpBuffer, LPDWORD lpdwSize, WORD wVer)
{
#define CHECK_BOUNDS(need) if (need < 0 || need > int(*lpdwSize) - (pB - LPBYTE (lpBuffer))) return FALSE;
	
	LPBYTE pB = LPBYTE (lpBuffer);
	DWORD dw = *lpdwSize;
	LPSTR szStr;
	int iReserved;

	if (FALSE == dld->pMgr->LoadState (pB, &dw, wVer))
		return FALSE;
	pB += dw;

	CHECK_BOUNDS (sizeof (dld->bAutoStart));

	CopyMemory (&dld->bAutoStart, pB, sizeof (dld->bAutoStart));
	pB += sizeof (dld->bAutoStart);

	CHECK_BOUNDS (sizeof (iReserved));

	CopyMemory (&iReserved, pB, sizeof (iReserved));
	pB += sizeof (iReserved);

	CHECK_BOUNDS (sizeof (dld->nID));

	CopyMemory (&dld->nID, pB, sizeof (dld->nID));
	pB += sizeof (dld->nID);

	CHECK_BOUNDS (sizeof (dw));

	CopyMemory (&dw, pB, sizeof (dw));
	CHECK_BOUNDS (int (dw));
	pB += sizeof (dw); fsnew (szStr, CHAR, dw+1);
	CopyMemory (szStr, pB, dw);
	szStr [dw] = 0; dld->strComment = szStr; delete [] szStr;
	pB += dw;

	if (wVer < 9)
	{
		CHECK_BOUNDS (sizeof (dw));

		CopyMemory (&dw, pB, sizeof (dw));
		CHECK_BOUNDS (int (dw));
		pB += sizeof (dw); fsnew (szStr, CHAR, dw+1);
		CopyMemory (szStr, pB, dw);
		szStr [dw] = 0; 
		dld->pGroup = _DldsGrps.FindGroupByName (szStr);
		delete [] szStr;
		pB += dw;
	}
	else
	{
		UINT nGrpId;
		CHECK_BOUNDS (sizeof (UINT));
		CopyMemory (&nGrpId, pB, sizeof (UINT));
		pB += sizeof (UINT);
		dld->pGroup = _DldsGrps.FindGroup (nGrpId);
	}

	if (dld->pGroup == NULL)
		dld->pGroup = _DldsGrps.FindGroup (GRP_OTHER_ID);

	CHECK_BOUNDS (sizeof (dld->dwFlags));
	CopyMemory (&dld->dwFlags, pB, sizeof (dld->dwFlags));
	pB += sizeof (dld->dwFlags);

	CHECK_BOUNDS (sizeof (dld->dwReserved));
	CopyMemory (&dld->dwReserved, pB, sizeof (dld->dwReserved));
	pB += sizeof (dld->dwReserved);

	CHECK_BOUNDS (sizeof (dld->dateAdded));
	CopyMemory (&dld->dateAdded, pB, sizeof (dld->dateAdded));
	pB += sizeof (dld->dateAdded);

	if (wVer >= 15)
	{
		CHECK_BOUNDS (sizeof (dld->dateCompleted));
		CopyMemory (&dld->dateCompleted, pB, sizeof (dld->dateCompleted));
		pB += sizeof (dld->dateCompleted);
	}
	
	DWORD cEvents;
	CHECK_BOUNDS (sizeof (cEvents));
	CopyMemory (&cEvents, pB, sizeof (cEvents));
	pB += sizeof (cEvents);

	dld->vEvents.clear ();

	while (cEvents--)
	{
		fsDownloadEvents ev;

		CHECK_BOUNDS (sizeof (ev.clrBg));
		
		CopyMemory (&ev.clrBg, pB, sizeof (ev.clrBg));
		pB += sizeof (ev.clrBg);

		CHECK_BOUNDS (sizeof (ev.clrText));

		CopyMemory (&ev.clrText, pB, sizeof (ev.clrText));
		pB += sizeof (ev.clrText);

		CHECK_BOUNDS (sizeof (ev.timeEvent));

		CopyMemory (&ev.timeEvent, pB, sizeof (ev.timeEvent));
		pB += sizeof (ev.timeEvent);

		CHECK_BOUNDS (sizeof (ev.iImage));

		CopyMemory (&ev.iImage, pB, sizeof (ev.iImage));
		pB += sizeof (ev.iImage);

		CHECK_BOUNDS (sizeof (dw));

		CopyMemory (&dw, pB, sizeof (dw));
		CHECK_BOUNDS (int (dw));
		pB += sizeof (dw); fsnew (szStr, CHAR, dw+1);
		CopyMemory (szStr, pB, dw);
		szStr [dw] = 0; ev.strEvent = szStr; delete [] szStr;
		pB += dw;

		dld->vEvents.add (ev);
	}

	*lpdwSize = pB - LPBYTE (lpBuffer);
	
	return TRUE;
}

BOOL fsDownloadRegSaver::OLD_LoadDownload(vmsDownloadSmartPtr dld, LPVOID lpBuffer, LPDWORD lpdwSize)
{
	#define CHECK_BOUNDS(need) if (need < 0 || need > int(*lpdwSize) - (pB - LPBYTE (lpBuffer))) return FALSE;
	
	LPBYTE pB = LPBYTE (lpBuffer);
	DWORD dw = *lpdwSize;
	LPSTR szStr;
	int iReserved = 0;

	if (FALSE == dld->pMgr->LoadState (pB, &dw, 0))
		return FALSE;
	pB += dw;

	CHECK_BOUNDS (sizeof (dld->bAutoStart));

	CopyMemory (&dld->bAutoStart, pB, sizeof (dld->bAutoStart));
	pB += sizeof (dld->bAutoStart);

	CHECK_BOUNDS (sizeof (iReserved));

	CopyMemory (&iReserved, pB, sizeof (iReserved));
	pB += sizeof (iReserved);

	CHECK_BOUNDS (sizeof (dld->nID));

	CopyMemory (&dld->nID, pB, sizeof (dld->nID));
	pB += sizeof (dld->nID);

	CHECK_BOUNDS (sizeof (dw));

	CopyMemory (&dw, pB, sizeof (dw));
	CHECK_BOUNDS (int (dw));
	pB += sizeof (dw); fsnew (szStr, CHAR, dw+1);
	CopyMemory (szStr, pB, dw);
	szStr [dw] = 0; dld->strComment = szStr; delete [] szStr;
	pB += dw;

	CHECK_BOUNDS (sizeof (dw));

	CopyMemory (&dw, pB, sizeof (dw));
	CHECK_BOUNDS (int (dw));
	pB += sizeof (dw);  fsnew (szStr, CHAR, dw+1);
	CopyMemory (szStr, pB, dw);
	szStr [dw] = 0; 
	dld->pGroup = _DldsGrps.FindGroupByName (szStr);
	if (dld->pGroup == NULL)
		dld->pGroup = _DldsGrps.FindGroup (GRP_OTHER_ID);
	delete [] szStr;
	pB += dw;

	dld->dwFlags = dld->dwReserved = 0;
	
	DWORD cEvents;
	CHECK_BOUNDS (sizeof (cEvents));
	CopyMemory (&cEvents, pB, sizeof (cEvents));
	pB += sizeof (cEvents);

	dld->vEvents.clear ();

	while (cEvents--)
	{
		fsDownloadEvents ev;

		CHECK_BOUNDS (sizeof (ev.clrBg));
		
		CopyMemory (&ev.clrBg, pB, sizeof (ev.clrBg));
		pB += sizeof (ev.clrBg);

		CHECK_BOUNDS (sizeof (ev.clrText));

		CopyMemory (&ev.clrText, pB, sizeof (ev.clrText));
		pB += sizeof (ev.clrText);

		CHECK_BOUNDS (sizeof (ev.timeEvent));

		CopyMemory (&ev.timeEvent, pB, sizeof (ev.timeEvent));
		pB += sizeof (ev.timeEvent);

		CHECK_BOUNDS (sizeof (ev.iImage));

		CopyMemory (&ev.iImage, pB, sizeof (ev.iImage));
		pB += sizeof (ev.iImage);

		CHECK_BOUNDS (sizeof (dw));

		CopyMemory (&dw, pB, sizeof (dw));
		CHECK_BOUNDS (int (dw));
		pB += sizeof (dw); fsnew (szStr, CHAR, dw+1);
		CopyMemory (szStr, pB, dw);
		szStr [dw] = 0; ev.strEvent = szStr; delete [] szStr;
		pB += dw;

		dld->vEvents.add (ev);
	}

	*lpdwSize = pB - LPBYTE (lpBuffer);
	
	return TRUE;
}

bool fsDownloadRegSaver::IsStoringLogTurnedOn()
{
	return m_bDontSaveLogs != FALSE;
}
