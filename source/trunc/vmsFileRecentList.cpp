/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Utils.h"
#include "vmsFileRecentList.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsFileRecentList::vmsFileRecentList()
{
	m_nMaxEntries = 10;
	InitializeCriticalSection (&m_cs);
}

vmsFileRecentList::~vmsFileRecentList()
{
	DeleteCriticalSection (&m_cs);
}

void vmsFileRecentList::Add(LPCSTR pszFileDispName, LPCSTR pszFilePathName, bool bDontQueryStoringStateInformation)
{
	EnterCriticalSection (&m_cs);

	_inc_FileInfo fi;
	fi.strDispName = pszFileDispName;
	fi.strPathName = pszFilePathName;
	m_vList.push_back (fi);

	bool bNeedDel = true;

	for (size_t i = 0; i < m_vList.size () - 1; i++)
	{
		if (lstrcmp (m_vList [i].strPathName, pszFilePathName) == 0)
		{
			m_vList.erase (m_vList.begin () + i);
			bNeedDel = false;
			break;
		}
	}

	if (bNeedDel)
	{
		if (m_vList.size () > (size_t)m_nMaxEntries)
			m_vList.erase (m_vList.begin ());
	}

	if (!bDontQueryStoringStateInformation) {
		
		
		setDirty();
	}

	LeaveCriticalSection (&m_cs);
}

BOOL vmsFileRecentList::Save(HANDLE hFile)
{
	EnterCriticalSection (&m_cs);

	size_t c = m_vList.size ();
	
	DWORD dw;

	if (FALSE == WriteFile (hFile, &c, sizeof (c), &dw, NULL))
	{
		LeaveCriticalSection (&m_cs);
		return FALSE;
	}

	for (size_t i = 0; i < c; i++)
	{
		if (FALSE == fsSaveStrToFile (get_FileDispName (i), hFile))
		{
			LeaveCriticalSection (&m_cs);
			return FALSE;
		}

		if (FALSE == fsSaveStrToFile (get_FilePathName (i), hFile))
		{
			LeaveCriticalSection (&m_cs);
			return FALSE;
		}
	}

	LeaveCriticalSection (&m_cs);
	return TRUE;
}

BOOL vmsFileRecentList::Load(HANDLE hFile)
{
	Clear (true);

	m_nMaxEntries = _App.RecentDownloadsHistorySize ();

	size_t c = 0;
	DWORD dw;

	if (FALSE == ReadFile (hFile, &c, sizeof (c), &dw, NULL))
		return FALSE;

	for (size_t i = 0; i < c; i++)
	{
		LPSTR pszDisp, pszPath;

		if (FALSE == fsReadStrFromFile (&pszDisp, hFile))
			return FALSE;

		if (FALSE == fsReadStrFromFile (&pszPath, hFile))
			return FALSE;

		Add (pszDisp, pszPath, true);

		delete [] pszDisp;
		delete [] pszPath;
	}

	return TRUE;
}

void vmsFileRecentList::Clear(bool bDontQueryStoringStateInformation)
{
	EnterCriticalSection (&m_cs);
	size_t szCount =  m_vList.size();
	m_vList.clear ();
	if (!bDontQueryStoringStateInformation) {
		if (szCount > 0) {
			
			
			setDirty();
		}
	}
	LeaveCriticalSection (&m_cs);
}

LPCSTR vmsFileRecentList::get_FileDispName(int nIndex) const
{
	return m_vList [nIndex].strDispName;
}

LPCSTR vmsFileRecentList::get_FilePathName(int nIndex) const
{
	return m_vList [nIndex].strPathName;
}

int vmsFileRecentList::get_Count() const
{
	return m_vList.size ();
}

void vmsFileRecentList::setMaxSize(int i)
{
	m_nMaxEntries = i;
	bool bHaveRemoved = false;
	while (m_vList.size () > (size_t)m_nMaxEntries) {
		m_vList.erase (m_vList.end () - 1);
		bHaveRemoved = true;
	}
	if (bHaveRemoved) {
		
		
		setDirty();
	}
}

void vmsFileRecentList::getObjectItselfStateBuffer(LPBYTE pbtBuffer, LPDWORD pdwSize, bool bSaveToStorage)
{
	EnterCriticalSection (&m_cs);

	DWORD dwRequiredSize = 0;
	LPBYTE pbtCurrentPos = pbtBuffer;

	size_t c = m_vList.size ();
	putVarToBuffer(c, pbtCurrentPos, 0, *pdwSize, &dwRequiredSize);
	
	for (size_t i = 0; i < c; i++) {
		putStrToBuffer(get_FileDispName (i), pbtCurrentPos, 0, *pdwSize, &dwRequiredSize);
		putStrToBuffer(get_FilePathName (i), pbtCurrentPos, 0, *pdwSize, &dwRequiredSize);
	}

	if (pbtBuffer == NULL) {
		if (pdwSize) {
			*pdwSize = dwRequiredSize;
		}
		LeaveCriticalSection (&m_cs);
		return;
	}

	putVarToBuffer(c, pbtCurrentPos, pbtBuffer, *pdwSize, 0);
	
	for (size_t i = 0; i < c; i++) {
		putStrToBuffer(get_FileDispName (i), pbtCurrentPos, pbtBuffer, *pdwSize, 0);
		putStrToBuffer(get_FilePathName (i), pbtCurrentPos, pbtBuffer, *pdwSize, 0);
	}

	*pdwSize = pbtCurrentPos - pbtBuffer;

	LeaveCriticalSection (&m_cs);
	return;
}

bool vmsFileRecentList::loadObjectItselfFromStateBuffer(LPBYTE pbtBuffer, LPDWORD pdwSize, DWORD dwVer)
{
	Clear (true);

	m_nMaxEntries = _App.RecentDownloadsHistorySize ();

	size_t c = 0;
	DWORD dw;

	LPBYTE pbtCurrentPos = pbtBuffer;

	if (!getVarFromBuffer(c, pbtCurrentPos, pbtBuffer, *pdwSize))
		return false;

	for (size_t i = 0; i < c; i++) {
		LPSTR pszDisp, pszPath;

		if (!getStrFromBuffer(&pszDisp, pbtCurrentPos, pbtBuffer, *pdwSize))
			return false;

		if (!getStrFromBuffer(&pszPath, pbtCurrentPos, pbtBuffer, *pdwSize))
			return false;

		Add (pszDisp, pszPath, true);

		delete [] pszDisp;
		delete [] pszPath;
	}

	return true;
}
