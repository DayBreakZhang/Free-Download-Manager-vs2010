/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "Utils.h"
#include "FdmApp.h"
#include "fsDownloadsHistoryMgr.h"
#include "mfchelp.h"
#include "WaitForConfirmationDlg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

fsDownloadsHistoryMgr::fsDownloadsHistoryMgr()
{
	m_pfnEventFunc = NULL;
}

fsDownloadsHistoryMgr::~fsDownloadsHistoryMgr()
{

}

void fsDownloadsHistoryMgr::ReadSettings()
{
	m_bUse = _App.History_Downloads_Use ();
	m_cDaysMax = _App.History_Downloads_KeepDays ();
	m_bCompOnly = _App.History_Downloads_CompletedOnly ();

	ApplySettings ();
}

void fsDownloadsHistoryMgr::ApplySettings()
{
	if (m_bUse == FALSE)
	{
		ClearHistory ();
		return;
	}

	SYSTEMTIME stime;
	GetLocalTime (&stime);
	FILETIME time;
	SystemTimeToFileTime (&stime, &time);

	vmsAUTOLOCKSECTION (m_csRecords);

	for (int i = m_vRecords.size () - 1; i >= 0; i--)
	{
		fsDLHistoryRecord* r = m_vRecords [i];
		int cDays = fsGetFTimeDaysDelta (time, r->dateRecordAdded);

		
		if (UINT (cDays) < m_cDaysMax)
			break;	

		Event (DHME_RECORDDELETED, r);

		m_vRecords.erase (m_vRecords.begin () + i);
		setDirty();
	}
}

void fsDownloadsHistoryMgr::ClearHistory()
{
	vmsAUTOLOCKSECTION (m_csRecords);
	m_vRecords.clear ();
	vmsAUTOLOCKSECTION_UNLOCK (m_csRecords);
	setDirty();
	Event (DHME_HISTORYCLEARED);
}

void fsDownloadsHistoryMgr::SetEventFunc(fntDHMEEventFunc pfn, LPVOID lpParam)
{
	m_pfnEventFunc = pfn;
	m_lpEvParam = lpParam;
}

void fsDownloadsHistoryMgr::Event(fsDownloadsHistoryMgrEvent ev, fsDLHistoryRecord *rec)
{
	if (m_pfnEventFunc)
		m_pfnEventFunc (ev, rec, m_lpEvParam);
}

void fsDownloadsHistoryMgr::AddToHistory(vmsDownloadSmartPtr dld)
{
	if (m_bUse == FALSE)
		return;

	if (m_bCompOnly && dld->pMgr->IsDone () == FALSE)
		return;

	fsDLHistoryRecordPtr r;
	r.CreateInstance ();
	
	r->strURL = dld->pMgr->get_URL ();
	r->dateAdded = dld->dateAdded;
	
	SYSTEMTIME t;
	FILETIME time;
	GetLocalTime (&t);
	SystemTimeToFileTime (&t, &time);

	r->dateRecordAdded = time;
	if (dld->pMgr->IsDone ())
		r->dateDownloaded = time;
	else
		ZeroMemory (&r->dateDownloaded, sizeof (FILETIME));

	char sz [MY_MAX_PATH];
	CDownloads_Tasks::GetFileName (dld, sz);
	r->strFileName = sz;

	r->strSavedTo = dld->pMgr->get_OutputFilePathName ();

	r->uFileSize = dld->pMgr->GetLDFileSize ();
	if (r->uFileSize == 0 && dld->pMgr->GetNumberOfSections () == 0)
		r->uFileSize = _UI64_MAX;

	r->strComment = dld->strComment;

	vmsAUTOLOCKSECTION (m_csRecords);
	m_vRecords.insert (m_vRecords.begin (), r);
	vmsAUTOLOCKSECTION_UNLOCK (m_csRecords);

	setDirty();
	
	Event (DHME_RECORDADDED, m_vRecords [0]);
}

int fsDownloadsHistoryMgr::GetRecordCount()
{
	vmsAUTOLOCKSECTION (m_csRecords);
	return m_vRecords.size ();
}

BOOL fsDownloadsHistoryMgr::SaveHistory()
{
	if (!isDirty())
		return TRUE;

	HANDLE hFile = CreateFile (fsGetDataFilePath ("downloads.his.sav"), GENERIC_WRITE, 0, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_HIDDEN, NULL);

	if (hFile == INVALID_HANDLE_VALUE)
		return FALSE;

	fsDownloadsHistMgrFileHdr hdr;
	DWORD dw;

	if (FALSE == WriteFile (hFile, &hdr, sizeof (hdr), &dw, NULL))
	{
		CloseHandle (hFile);
		return FALSE;
	}

	DWORD dwBufferSize = 0;
	getStateBuffer(0, &dwBufferSize, false);

	std::auto_ptr<BYTE> apbtBufferGuard( new BYTE[dwBufferSize] );
	LPBYTE pbtBuffer = apbtBufferGuard.get();

	if (pbtBuffer == 0) {
		CloseHandle (hFile);
		return FALSE;
	}

	getStateBuffer(pbtBuffer, &dwBufferSize, true);

	if (FALSE == WriteFile (hFile, pbtBuffer, dwBufferSize, &dw, NULL) || dw != dwBufferSize)
	{
		CloseHandle (hFile);
		return FALSE;
	}

	CloseHandle (hFile);

	onStateSavedSuccessfully();

	return TRUE;

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}

BOOL fsDownloadsHistoryMgr::LoadHistory()
{
	vmsAUTOLOCKSECTION (m_csRecords);

	if (GetFileAttributes (fsGetDataFilePath ("downloads.his.sav")) == UINT (-1))
		return TRUE;

	HANDLE hFile = CreateFile (fsGetDataFilePath ("downloads.his.sav"), GENERIC_READ, FILE_SHARE_READ, NULL,
		OPEN_EXISTING, 0, NULL);

	if (hFile == INVALID_HANDLE_VALUE)
		return FALSE;

	if (_App.CheckHistorySize () && GetFileSize (hFile, NULL) > 1*1024*1024)
	{
		CWaitForConfirmationDlg dlg;
		dlg.Init (LS (L_HISTTOOLARGE), UINT_MAX, TRUE, FALSE, LS (L_DONTCHECKAGAIN));
		dlg.m_pszIcon = IDI_WARNING;
		UINT nRet = dlg.DoModal ();
		if (dlg.m_bDontAsk)
			_App.CheckHistorySize (FALSE);
		if (nRet == IDOK)
		{
			CloseHandle (hFile);
			return TRUE;
		}
	}

	fsDownloadsHistMgrFileHdr hdr;
	DWORD dw;
	DWORD dwRequiredSize = ::GetFileSize(hFile, NULL);
	if (dwRequiredSize < sizeof (hdr))
		return FALSE;

	if (FALSE == ReadFile (hFile, &hdr, sizeof (hdr), &dw, NULL))
	{
		CloseHandle (hFile);
		return FALSE;
	}

	dwRequiredSize -= sizeof(hdr);

	
	if (hdr.wVer != DLHISTFILE_CURRENT_VERSION ||
			strnicmp (hdr.szSig, DLHISTFILE_SIG, strlen (DLHISTFILE_SIG)))
	{
		CloseHandle (hFile);
		return FALSE;
	}

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

	std::auto_ptr<BYTE> apbtBufferGuard( new BYTE[dwRequiredSize] );
	LPBYTE pbtBuffer = apbtBufferGuard.get();
	if (pbtBuffer == 0)
		return false;
	memset(pbtBuffer, 0, dwRequiredSize);

	if (FALSE == ReadFile (hFile, pbtBuffer, dwRequiredSize, &dw, NULL) || dw != dwRequiredSize)
	{
		CloseHandle (hFile);
		return FALSE;
	}
	CloseHandle (hFile);

	loadFromStateBuffer(pbtBuffer, &dwRequiredSize, hdr.wVer);

	return TRUE;
}

fsDLHistoryRecord* fsDownloadsHistoryMgr::GetRecord(int iIndex)
{
	vmsAUTOLOCKSECTION (m_csRecords);
	return m_vRecords [iIndex];
}

void fsDownloadsHistoryMgr::DeleteRecord(fsDLHistoryRecord *rec)
{
	vmsAUTOLOCKSECTION (m_csRecords);
	int i = FindIndex (rec);
	if (i != -1)
	{
		Event (DHME_RECORDDELETED, rec);
		m_vRecords.erase (m_vRecords.begin () + i);
		setDirty();
	}
}

int fsDownloadsHistoryMgr::FindIndex(fsDLHistoryRecord *rec)
{
	for (size_t i = 0; i < m_vRecords.size (); i++)
	{
		if (m_vRecords [i] == rec)
			return (int)i;
	}

	return -1;
}

void fsDownloadsHistoryMgr::getObjectItselfStateBuffer(LPBYTE pbtBuffer, LPDWORD pdwSize, bool bSaveToStorage)
{
	DWORD dwSizeRequired = 0;
	
	LPBYTE pbtCurrentPos = pbtBuffer;

	int cRecs = GetRecordCount ();
	putVarToBuffer(cRecs, pbtCurrentPos, 0, *pdwSize, &dwSizeRequired);

	int i = 0;
	for (i = 0; i < cRecs; i++) {
		fsDLHistoryRecord* rec = GetRecord (i);
		if (!rec)
			return;

		
		putStrToBuffer(rec->strFileName, pbtCurrentPos, 0, *pdwSize, &dwSizeRequired);
		putStrToBuffer(rec->strSavedTo, pbtCurrentPos, 0, *pdwSize, &dwSizeRequired);
		putStrToBuffer(rec->strURL, pbtCurrentPos, 0, *pdwSize, &dwSizeRequired);
		putStrToBuffer(rec->strComment, pbtCurrentPos, 0, *pdwSize, &dwSizeRequired);

		putVarToBuffer(rec->dateAdded, pbtCurrentPos, 0, *pdwSize, &dwSizeRequired);
		putVarToBuffer(rec->dateDownloaded, pbtCurrentPos, 0, *pdwSize, &dwSizeRequired);
		putVarToBuffer(rec->dateRecordAdded, pbtCurrentPos, 0, *pdwSize, &dwSizeRequired);
		putVarToBuffer(rec->uFileSize, pbtCurrentPos, 0, *pdwSize, &dwSizeRequired);
	}

	if (pbtBuffer == NULL) {
		if (pdwSize)
			*pdwSize = dwSizeRequired;
		return;
	}

	putVarToBuffer(cRecs, pbtCurrentPos, pbtBuffer, *pdwSize, 0);

	for (i = 0; i < cRecs; i++) {
		fsDLHistoryRecord* rec = GetRecord (i);
		if (!rec)
			return;

		putStrToBuffer(rec->strFileName, pbtCurrentPos, pbtBuffer, *pdwSize, 0);
		putStrToBuffer(rec->strSavedTo, pbtCurrentPos, pbtBuffer, *pdwSize, 0);
		putStrToBuffer(rec->strURL, pbtCurrentPos, pbtBuffer, *pdwSize, 0);
		putStrToBuffer(rec->strComment, pbtCurrentPos, pbtBuffer, *pdwSize, 0);

		putVarToBuffer(rec->dateAdded, pbtCurrentPos, pbtBuffer, *pdwSize, 0);
		putVarToBuffer(rec->dateDownloaded, pbtCurrentPos, pbtBuffer, *pdwSize, 0);
		putVarToBuffer(rec->dateRecordAdded, pbtCurrentPos, pbtBuffer, *pdwSize, 0);
		putVarToBuffer(rec->uFileSize, pbtCurrentPos, pbtBuffer, *pdwSize, 0);
	}

	*pdwSize = pbtCurrentPos - pbtBuffer;
}

bool fsDownloadsHistoryMgr::loadHistoryRecordStrAttributes(fsDLHistoryRecordPtr& rec, LPBYTE& pbtCurrentPos, LPBYTE pbtBuffer, DWORD dwSize, DWORD dwVer)
{
	if (!getStrFromBuffer(&rec->strFileName.pszString, pbtCurrentPos, pbtBuffer, dwSize))
		return false;

	if (!getStrFromBuffer(&rec->strSavedTo.pszString, pbtCurrentPos, pbtBuffer, dwSize))
		return false;

	if (!getStrFromBuffer(&rec->strURL.pszString, pbtCurrentPos, pbtBuffer, dwSize))
		return false;

	if (!getStrFromBuffer(&rec->strComment.pszString, pbtCurrentPos, pbtBuffer, dwSize))
		return false;

	return true;
}

bool fsDownloadsHistoryMgr::loadHistoryRecordNonStrAttributes(fsDLHistoryRecordPtr& rec, LPBYTE& pbtCurrentPos, LPBYTE pbtBuffer, DWORD dwSize, DWORD dwVer)
{
	if (!getVarFromBuffer(rec->dateAdded, pbtCurrentPos, pbtBuffer, dwSize))
		return false;

	if (!getVarFromBuffer(rec->dateDownloaded, pbtCurrentPos, pbtBuffer, dwSize))
		return false;

	if (!getVarFromBuffer(rec->dateRecordAdded, pbtCurrentPos, pbtBuffer, dwSize))
		return false;

	if (!getVarFromBuffer(rec->uFileSize, pbtCurrentPos, pbtBuffer, dwSize))
		return false;

	return true;
}

bool fsDownloadsHistoryMgr::loadHistoryRecordAttributes(fsDLHistoryRecordPtr& rec, LPBYTE& pbtCurrentPos, LPBYTE pbtBuffer, DWORD dwSize, DWORD dwVer)
{
	if (!loadHistoryRecordStrAttributes(rec, pbtCurrentPos, pbtBuffer, dwSize, dwVer))
		return false;

	if (!loadHistoryRecordNonStrAttributes(rec, pbtCurrentPos, pbtBuffer, dwSize, dwVer))
		return false;

	return true;
}

bool fsDownloadsHistoryMgr::loadObjectItselfFromStateBuffer(LPBYTE pbtBuffer, LPDWORD pdwSize, DWORD dwVer)
{
	LPBYTE pbtCurrentPos = pbtBuffer;

	int cRecs = GetRecordCount ();
	if (!getVarFromBuffer(cRecs, pbtCurrentPos, pbtBuffer, *pdwSize))
		return false;

	int i = 0;
	for (i = 0; i < cRecs; i++) {

		fsDLHistoryRecordPtr rec; rec.CreateInstance ();

		if (!loadHistoryRecordAttributes(rec, pbtCurrentPos, pbtBuffer, *pdwSize, dwVer))
			return false;

		m_vRecords.push_back (rec);
	}

	*pdwSize = pbtCurrentPos - pbtBuffer;

	return true;
}

