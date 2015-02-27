/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsPersistObject.h"

vmsPersistObject::vmsPersistObject()
	: m_bState(POS_NOTMODIFIEDSINCELASTSAVE),
	m_persistChildObjects (&m_csObj),
	m_pPersistChildObjects (&m_persistChildObjects)
{
}

vmsPersistObject::~vmsPersistObject()
{
}

bool vmsPersistObject::isDirty()
{
	if (m_bState & POS_DIRTY)
		return true;

	vmsCriticalSectionAutoLock csalModifiedGuardAutoLock(&m_csObj);

	size_t i = 0;
	for (i = 0; i < m_pPersistChildObjects->getPersistObjectCount (); i++) 
	{
		if (m_pPersistChildObjects->getPersistObject (i)->isDirty())
			return true;
	}

	return false;
}

void vmsPersistObject::setDirty()
{
	vmsCriticalSectionAutoLock csalModifiedGuardAutoLock(&m_csObj);
	m_bState |=  POS_DIRTY;
	m_bState &= ~POS_NOTMODIFIEDSINCELASTSAVE;
}

void vmsPersistObject::onStateSavedSuccessfully()
{
	vmsCriticalSectionAutoLock csalStateGuard(&m_csObj);

	if ((m_bState & POS_NOTMODIFIEDSINCELASTSAVE) != 0)
		m_bState &= ~POS_DIRTY;

	size_t i = 0;
	for (i = 0; i < getPersistObjectChildren ()->getPersistObjectCount (); i++)
		getPersistObjectChildren ()->getPersistObject (i)->onStateSavedSuccessfully();
}

bool vmsPersistObject::loadFromStateBuffer(LPBYTE pb, LPDWORD pdwSize, DWORD dwVer)
{
	assert (pb != NULL && pdwSize != NULL);
	if (!pb || !pdwSize)
		return false;

	DWORD dwBufferSize = *pdwSize;
	DWORD dwSize;
	
	*pdwSize = 0;
	
	dwSize = dwBufferSize;
	if (!loadObjectItselfFromStateBuffer(pb, &dwSize, dwVer))
		return false;

	pb += dwSize;
	dwBufferSize -= dwSize;
	*pdwSize += dwSize;

	

	size_t i = 0;
	for (i = 0; i < getPersistObjectChildren ()->getPersistObjectCount (); i++) {

		dwSize = dwBufferSize;
		bool bResult = getPersistObjectChildren ()->getPersistObject (i)->loadFromStateBuffer(pb, &dwSize, dwVer);
		onChildObjectLoadFinished (getPersistObjectChildren ()->getPersistObject (i), bResult);
		if (!bResult)
			return false;

		pb += dwSize;
		*pdwSize += dwSize;
		dwBufferSize -= dwSize;
	}

	return true;
}

void vmsPersistObject::getStateBuffer(LPBYTE pb, LPDWORD pdwSize, bool bSaveToStorage)
{
	{
		vmsCriticalSectionAutoLock csalStateGuardAutoLock(&m_csObj);

		if (bSaveToStorage)
			m_bState |= POS_NOTMODIFIEDSINCELASTSAVE;
	}

	DWORD dwSize = 0;
	DWORD dwBufferSize = 0;
	
	if (!pb && pdwSize) {
			*pdwSize = 0;
	} else if (pb && pdwSize) {
		dwSize = *pdwSize;
		dwBufferSize = *pdwSize;
		*pdwSize = 0;
	}

	

	getObjectItselfStateBuffer(pb, &dwSize, bSaveToStorage);

	if (!pb && pdwSize) {
		*pdwSize += dwSize;
	}

	if (pb)
		pb += dwSize;
	
	if (pb && pdwSize) {
		*pdwSize += dwSize;
		dwBufferSize -= dwSize;
		dwSize = dwBufferSize;
	}

	

	size_t i = 0;
	for (i = 0; i < getPersistObjectChildren ()->getPersistObjectCount (); i++) {

		if (!pb) {
			dwSize = 0;
		}

		getPersistObjectChildren ()->getPersistObject (i)->getStateBuffer(pb, &dwSize, bSaveToStorage);

		if (!pb && pdwSize) {
			*pdwSize += dwSize;
		} 

		if (pb)
			pb += dwSize;
		
		if (pb && pdwSize) {
			*pdwSize += dwSize;
			dwBufferSize -= dwSize;
			dwSize = dwBufferSize;
		}
	}
}

void vmsPersistObject::getObjectItselfStateBuffer(LPBYTE pb, LPDWORD pdwSize, bool bSaveToStorage)
{
	
	if (pdwSize)
		*pdwSize = 0;
}

bool vmsPersistObject::loadObjectItselfFromStateBuffer(LPBYTE pb, LPDWORD pdwSize, DWORD dwVer)
{
	if (!pb || !pdwSize)
		return false;
	*pdwSize = 0;
	return true;
}

void vmsPersistObject::resetDirty()
{
	vmsCriticalSectionAutoLock csalModifiedGuardAutoLock(&m_csObj);

	size_t i = 0;
	for (i = 0; i < getPersistObjectChildren ()->getPersistObjectCount (); i++) {
		getPersistObjectChildren ()->getPersistObject (i)->resetDirty();
	}

	m_bState = POS_NOTMODIFIEDSINCELASTSAVE;
}
