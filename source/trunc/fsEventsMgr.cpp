/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "Utils.h"
#include "FdmApp.h"
#include "fsEventsMgr.h"
#include "misc.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsPersistableDescEventWrapper& vmsPersistableDescEventWrapper::operator = (const  vmsPersistableDescEventWrapper& src)
{
	deEvent = src.deEvent;
	return *this;
}

void vmsPersistableDescEventWrapper::getObjectItselfStateBuffer(LPBYTE pbtBuffer, LPDWORD pdwSize, bool bSaveToStorage)
{
	DWORD dwRequiredSize = 0;
	LPBYTE pbtCurrentPos = pbtBuffer;

	putVarToBuffer(deEvent, pbtCurrentPos, 0, 0, &dwRequiredSize);
	putStrToBuffer(deEvent.pszEvent, pbtCurrentPos, 0, 0, &dwRequiredSize);

	if (pbtBuffer == NULL) {
		if (pdwSize) {
			*pdwSize = dwRequiredSize;
		}
		return;
	}

	putVarToBuffer(deEvent, pbtCurrentPos, pbtBuffer, *pdwSize, 0);
	putStrToBuffer(deEvent.pszEvent, pbtCurrentPos, pbtBuffer, *pdwSize, 0);

	*pdwSize = pbtCurrentPos - pbtBuffer;
}

bool vmsPersistableDescEventWrapper::loadObjectItselfFromStateBuffer(LPBYTE pbtBuffer, LPDWORD pdwSize, DWORD dwVer)
{
	
	LPBYTE pbtCurrentPos = pbtBuffer;

	if (!getVarFromBuffer(deEvent, pbtCurrentPos, pbtBuffer, *pdwSize))
		return false;

	if (!getStrFromBuffer(&deEvent.pszEvent, pbtCurrentPos, pbtBuffer, *pdwSize))
		return false;

	*pdwSize = pbtCurrentPos - pbtBuffer;

	return true;
}

fsEventsMgr::fsEventsMgr()
{

}

fsEventsMgr::~fsEventsMgr()
{
	clear ();
}

void fsEventsMgr::clear()
{
	
	
	for (int i = m_vEvents.size () - 1; i >= 0; i--)
		delete [] m_vEvents [i]->deEvent.pszEvent;
	setDirty();
	getPersistObjectChildren ()->removeAllPersistObjects ();
	m_vEvents.clear ();
}

BOOL fsEventsMgr::Save(HANDLE hFile)
{
	int cRecs = m_vEvents.size ();
	DWORD dw;

	

	
	if (!WriteFile (hFile, &cRecs, sizeof (cRecs), &dw, NULL))
		return FALSE;

	

	for (int i = 0; i < cRecs; i++)
	{
		
		fsDescEvent *ev = &m_vEvents [i]->deEvent;

		if (!WriteFile (hFile, ev, sizeof (fsDescEvent), &dw, NULL))
			return FALSE;

		if (!fsSaveStrToFile (ev->pszEvent, hFile))
			return FALSE;
	}

	return TRUE;
}

BOOL fsEventsMgr::Load(HANDLE hFile)
{
	int cRecs;
	DWORD dw;

	m_vEvents.clear ();

	if (!ReadFile (hFile, &cRecs, sizeof (cRecs), &dw, NULL) || dw != sizeof (cRecs))
		return FALSE;

	while (cRecs-- > 0)
	{
		
		vmsPersistableDescEventWrapperSmartPtr pEventPtr;
		pEventPtr.CreateInstance();
		fsDescEvent& ev = pEventPtr->deEvent;

		if (!ReadFile (hFile, &ev, sizeof (fsDescEvent), &dw, NULL) || dw != sizeof (fsDescEvent))
		{
			m_vEvents.clear ();
			return FALSE;
		}

		if (!fsReadStrFromFile (&ev.pszEvent, hFile))
		{
			m_vEvents.clear ();
			return FALSE;
		}

		
		m_vEvents.add (pEventPtr);
		getPersistObjectChildren ()->addPersistObject ((vmsPersistableDescEventWrapper*)pEventPtr);
	}
	
	return TRUE;
}

void fsEventsMgr::getObjectItselfStateBuffer(LPBYTE pbtBuffer, LPDWORD pdwSize, bool bSaveToStorage)
{
	DWORD dwRequiredSize = 0;
	LPBYTE pbtCurrentPos = pbtBuffer;
	int cRecs = m_vEvents.size ();
	
	putVarToBuffer(cRecs, pbtCurrentPos, 0, 0, &dwRequiredSize);

	if (pbtBuffer == NULL) {
		if (pdwSize) {
			*pdwSize = dwRequiredSize;
		}
		return;
	}

	putVarToBuffer(cRecs, pbtCurrentPos, pbtBuffer, *pdwSize, 0);

	*pdwSize = pbtCurrentPos - pbtBuffer;
}

bool fsEventsMgr::loadObjectItselfFromStateBuffer(LPBYTE pbtBuffer, LPDWORD pdwSize, DWORD dwVer)
{

	LPBYTE pbtCurrentPos = pbtBuffer;
	int cRecs = 0;
	
	m_vEvents.clear ();

	if (!getVarFromBuffer(cRecs, pbtCurrentPos, pbtBuffer, *pdwSize))
		return false;

	int i = 0;
	for (i = 0; i < cRecs; i++) {
		vmsPersistableDescEventWrapperSmartPtr pEventPtr;
		pEventPtr.CreateInstance();
		m_vEvents.add (pEventPtr);
		getPersistObjectChildren ()->addPersistObject ((vmsPersistableDescEventWrapper*)pEventPtr);
	}

	*pdwSize = pbtCurrentPos - pbtBuffer;
	return true;
}

UINT fsEventsMgr::GetEventCount()
{
	return m_vEvents.size ();
}

fsDescEvent* fsEventsMgr::GetEvent(UINT uIndex)
{
	
	return &m_vEvents [uIndex]->deEvent;
}

void fsEventsMgr::add(fsDescEvent *ev)
{
	vmsPersistableDescEventWrapperSmartPtr pEventPtr;
	pEventPtr.CreateInstance();
	fsDescEvent* pdeEvent = &pEventPtr->deEvent;

	SYSTEMTIME time;
	GetLocalTime (&time);

	SystemTimeToFileTime (&time, &ev->timeEvent);

	*pdeEvent = *ev;

	
	m_vEvents.add (pEventPtr);
	getPersistObjectChildren ()->addPersistObject ((vmsPersistableDescEventWrapper*)pEventPtr);
}

