/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "Utils.h"
#include "FdmApp.h"
#include "fsCmdHistoryMgr.h"
#include "misc.h"
#include "CmdHistorySaver.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

void fsCmdHistoryMgr::fs1DayRecords::getObjectItselfStateBuffer(LPBYTE pbtBuffer, LPDWORD pdwSize, bool bSaveToStorage)
{
	DWORD dwRequiredSize = 0;
	LPBYTE pbtCurrentPos = pbtBuffer;
	int cRecs = vRecs.size ();

	putVarToBuffer(day, pbtCurrentPos, 0, 0, &dwRequiredSize);
	putVarToBuffer(cRecs, pbtCurrentPos, 0, 0, &dwRequiredSize);

	int j = 0;
	for (j = 0; j < cRecs; j++) {
		putStrToBuffer((LPCTSTR)vRecs[j], pbtCurrentPos, 0, 0, &dwRequiredSize);
	}

	if (pbtBuffer == NULL) {
		if (pdwSize) {
			*pdwSize = dwRequiredSize;
		}
		return;
	}

	putVarToBuffer(day, pbtCurrentPos, pbtBuffer, *pdwSize, 0);
	putVarToBuffer(cRecs, pbtCurrentPos, pbtBuffer, *pdwSize, &dwRequiredSize);

	for (j = 0; j < cRecs; j++) {
		putStrToBuffer((LPCTSTR)vRecs[j], pbtCurrentPos, pbtBuffer, *pdwSize, &dwRequiredSize);
	}

	*pdwSize = pbtCurrentPos - pbtBuffer;
}

bool fsCmdHistoryMgr::fs1DayRecords::loadObjectItselfFromStateBuffer(LPBYTE pbtBuffer, LPDWORD pdwSize, DWORD dwVer)
{

	int cRecs = 0;
	LPBYTE pbtCurrentPos = pbtBuffer;

	if (!getVarFromBuffer(day, pbtCurrentPos, pbtBuffer, *pdwSize))
		return false;

	if (!getVarFromBuffer(cRecs, pbtCurrentPos, pbtBuffer, *pdwSize))
		return false;

	while (cRecs--) {

		char *pszRec = 0;

		if (!getStrFromBuffer(&pszRec, pbtCurrentPos, pbtBuffer, *pdwSize))
			return false;
		
		vRecs.add (pszRec);
		delete [] pszRec;
	}

	*pdwSize = pbtCurrentPos - pbtBuffer;

	return true;
}

fsCmdHistoryMgr::fsCmdHistoryMgr()
{
	m_cMaxDays = 15;
	m_cMaxRecords = 30;
	GetLocalTime (&m_curday);

	CCmdHistorySaver& chsSaver = CCmdHistorySaver::Instance();
	chsSaver.getPersistObjectChildren ()->addPersistObject (this);
}

fsCmdHistoryMgr::~fsCmdHistoryMgr()
{

}

BOOL fsCmdHistoryMgr::SaveToFile(HANDLE hFile)
{
	fsHistFileHdr hdr;
	DWORD dw;

	if (!WriteFile (hFile, &hdr, sizeof (hdr), &dw, NULL))
		return FALSE;

	int cDays = m_vRecs.size ();

	if (!WriteFile (hFile, &cDays, sizeof (cDays), &dw, NULL))
		return FALSE;

	for (int i = 0; i < m_vRecs.size (); i++)
	{
		if (!WriteFile (hFile, &m_vRecs [i]->day, sizeof (FILETIME), &dw, NULL))
			return FALSE;

		int cRecs = m_vRecs [i]->vRecs.size ();
		
		if (!WriteFile (hFile, &cRecs, sizeof (cRecs), &dw, NULL))
			return FALSE;
		
		for (int j = 0; j < cRecs; j++)
		{
			if (!fsSaveStrToFile (m_vRecs [i]->vRecs [j], hFile))
				return FALSE;
		}
	}

	return TRUE;
}

BOOL fsCmdHistoryMgr::ReadFromFile(HANDLE hFile)
{
	DWORD dw;
	fsHistFileHdr hdr;
	int cDays;

	if (!ReadFile (hFile, &hdr, sizeof (hdr), &dw, NULL))
		return FALSE;

	if (strnicmp (hdr.szSig, HISTFILE_SIG, strlen (HISTFILE_SIG)))
		return FALSE;

	if (hdr.wVer != 1)
		return FALSE;

	if (!ReadFile (hFile, &cDays, sizeof (cDays), &dw, NULL))
		return FALSE;

	for (int i = 0; i < cDays; i++)
	{
		
		vms1DayRecordsSmartPtr pRecPtr;
		pRecPtr.CreateInstance();
		if ((fs1DayRecords*)pRecPtr == 0)
			return FALSE;

		if (!ReadFile (hFile, &pRecPtr->day, sizeof (pRecPtr->day), &dw, NULL))
			return FALSE;

		int cRecs;
		if (!ReadFile (hFile, &cRecs, sizeof (cRecs), &dw, NULL))
			return FALSE;

		while (cRecs--)
		{
			char *pszRec;

			if (!fsReadStrFromFile (&pszRec, hFile))
				return FALSE;
		
			pRecPtr->vRecs.add (pszRec);
			delete [] pszRec;
		}

		m_vRecs.add (pRecPtr);
		getPersistObjectChildren ()->addPersistObject ((fs1DayRecords*)pRecPtr);

		if (i == cDays-1)
			FileTimeToSystemTime (&pRecPtr->day, &m_curday);
	}

	Set_MaxRecordCount (m_cMaxRecords);
	Set_MaxDaysCount (m_cMaxDays);

	return TRUE;
}

void fsCmdHistoryMgr::getObjectItselfStateBuffer(LPBYTE pbtBuffer, LPDWORD pdwSize, bool bSaveToStorage)
{
	DWORD dwRequiredSize = 0;
	LPBYTE pbtCurrentPos = pbtBuffer;
	int cDays = m_vRecs.size ();

	putVarToBuffer(cDays, pbtCurrentPos, 0, 0, &dwRequiredSize);

	if (pbtBuffer == NULL) {
		if (pdwSize) {
			*pdwSize = dwRequiredSize;
		}
		return;
	}

	putVarToBuffer(cDays, pbtCurrentPos, pbtBuffer, *pdwSize, 0);

	*pdwSize = pbtCurrentPos - pbtBuffer;
}

bool fsCmdHistoryMgr::loadObjectItselfFromStateBuffer(LPBYTE pbtBuffer, LPDWORD pdwSize, DWORD dwVer)
{
	LPBYTE pbtCurrentPos = pbtBuffer;
	int cDays = 0;
	if (!getVarFromBuffer(cDays, pbtCurrentPos, pbtBuffer, *pdwSize))
		return false;

	m_vRecs.clear();
	int i = 0;
	for (i = 0; i < cDays; i++) {
		vms1DayRecordsSmartPtr pOneDayRecordsPtr;
		pOneDayRecordsPtr.CreateInstance();

		m_vRecs.add(pOneDayRecordsPtr);
		getPersistObjectChildren ()->addPersistObject ((fs1DayRecords*)pOneDayRecordsPtr);
	}

	*pdwSize = pbtCurrentPos - pbtBuffer;

	return true;
}

int fsCmdHistoryMgr::GetRecordCount()
{
	int cRecords = 0;
	for (int i = 0; i < m_vRecs.size (); i++)
		cRecords += m_vRecs [i]->vRecs.size ();
	return cRecords;
}

void fsCmdHistoryMgr::AddRecord(LPCSTR pszRecord)
{
	if (m_bNoHistory)
		return;

	if (m_vRecs.size () == 0)
	{
		
		vms1DayRecordsSmartPtr pRecPtr;
		pRecPtr.CreateInstance();
		if ((fs1DayRecords*)pRecPtr == 0)
			return;

		GetLocalTime (&m_curday);
		SystemTimeToFileTime (&m_curday, &pRecPtr->day);
		pRecPtr->vRecs.add (pszRecord);
		m_vRecs.add (pRecPtr);
		setDirty();
		m_vRecs[m_vRecs.size()-1]->setDirty();
		getPersistObjectChildren ()->addPersistObject ((fs1DayRecords*)m_vRecs[m_vRecs.size()-1]);
		return;
	}

	SYSTEMTIME time;
	GetLocalTime (&time);
	if (time.wDay != m_curday.wDay)
	{
		
		
		vms1DayRecordsSmartPtr pRecPtr;
		pRecPtr.CreateInstance();
		if ((fs1DayRecords*)pRecPtr == 0)
			return;

		m_curday = time;
		SystemTimeToFileTime (&m_curday, &pRecPtr->day);
		m_vRecs.add (pRecPtr); 
		setDirty();
		m_vRecs[m_vRecs.size()-1]->setDirty();
		getPersistObjectChildren ()->addPersistObject ((fs1DayRecords*)m_vRecs[m_vRecs.size()-1]);
	}
	
	

	for (int i = 0; i < m_vRecs.size (); i++)
	{
		fs::list <CString>* recs = &m_vRecs [i]->vRecs;
		
		int j = 0;
		for (j = 0; j < recs->size (); j++)
		{
			if (recs->at (j).CompareNoCase (pszRecord) == 0)
			{
				recs->del (j);
				m_vRecs [i]->setDirty();
				break;
			}
		}

		
		if (j != recs->size ())
			break; 
	}

	

	fs::list <CString>* recs = &m_vRecs [m_vRecs.size () - 1]->vRecs;
	
	recs->insert (0, pszRecord);
	m_vRecs [m_vRecs.size () - 1]->setDirty();

	if (m_vRecs.size () > m_cMaxDays) {
		m_vRecs.del (0);
		setDirty();
		getPersistObjectChildren ()->removePersistObject (size_t (0));
	}

	

	while (GetRecordCount () > m_cMaxRecords)
	{
		while (m_vRecs [0]->vRecs.size () == 0) {
			m_vRecs.del (0);
			setDirty();
			getPersistObjectChildren ()->removePersistObject (size_t (0));
		}
		
		m_vRecs [0]->vRecs.del (m_vRecs [0]->vRecs.size ()-1);
		m_vRecs [0]->setDirty();
		
		if (m_vRecs [0]->vRecs.size () == 0) {
			m_vRecs.del (0);
			setDirty();
			getPersistObjectChildren ()->removePersistObject (size_t (0));
		}
	}
}

LPCSTR fsCmdHistoryMgr::GetRecord(int iRec)
{
	
	
	for (int i = m_vRecs.size () - 1; i >= 0, iRec >= 0; i--)
	{
		if (m_vRecs [i]->vRecs.size () <= iRec)
		{
			iRec -= m_vRecs [i]->vRecs.size ();
			continue; 
		}
	
		
		return m_vRecs [i]->vRecs [iRec];
	}

	return NULL; 
}

void fsCmdHistoryMgr::Set_MaxRecordCount(int iMax)
{
	m_cMaxRecords = iMax;
	int nExcess = GetRecordCount () - m_cMaxRecords;
	while (nExcess > 0)
	{
		
		int sz = m_vRecs [0]->vRecs.size ();
		if (sz <= nExcess)
		{
			
			m_vRecs.del (0);
			nExcess -= sz;
			setDirty();
			getPersistObjectChildren ()->removePersistObject (size_t (0));
		}
		else
		{
			
			while (nExcess-- > 0)
			{
				m_vRecs [0]->vRecs.del (--sz);
				m_vRecs [0]->setDirty();
			}
		}
	}
}

void fsCmdHistoryMgr::ClearHistory()
{
	m_vRecs.clear ();
	setDirty();
	getPersistObjectChildren ()->removeAllPersistObjects ();
}

void fsCmdHistoryMgr::Set_NoHistory(BOOL b)
{
	m_bNoHistory = b;
	if (m_bNoHistory)
		ClearHistory ();
}

void fsCmdHistoryMgr::Set_MaxDaysCount(int cMax)
{
	m_cMaxDays = cMax;
	while (m_vRecs.size () > m_cMaxDays) {
		m_vRecs.del (0);
		setDirty();
		getPersistObjectChildren ()->removePersistObject (size_t (0));
	}
}

