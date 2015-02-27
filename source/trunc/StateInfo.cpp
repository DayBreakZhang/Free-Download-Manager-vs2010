/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "StateInfo.h"

CStateInfo::CStateInfo()
	: m_nId(0)
{
	getPersistObjectChildren ()->addPersistObject (&m_frlFileRecentList);
}

CStateInfo::~CStateInfo()
{
}

void CStateInfo::SetId(LONG nId)
{
	m_nId = nId;
}

LONG CStateInfo::IncId()
{
	return ++m_nId;
}

LONG CStateInfo::IncIdSafely()
{
	setDirty();
	return ::InterlockedIncrement(&m_nId);
}

LONG CStateInfo::GetId() const
{
	return m_nId;
}

vmsFileRecentList& CStateInfo::GetFileRecentList()
{
	return m_frlFileRecentList;
}

void CStateInfo::getObjectItselfStateBuffer(LPBYTE pb, LPDWORD pdwSize, bool bSaveToStorage)
{
	if (pb == NULL) {
		if (pdwSize) {
			*pdwSize = sizeof(m_nId);
		}
		return;
	}

	int* pnId = (int*)pb;
	*pnId = m_nId;
	*pdwSize = sizeof(m_nId);
}

bool CStateInfo::loadObjectItselfFromStateBuffer(LPBYTE pb, LPDWORD pdwSize, DWORD dwVer)
{
	if (pb == NULL || *pdwSize < sizeof(m_nId))
		return false;

	int* pnId = (int*)pb;
	m_nId = *pnId;
	*pdwSize = sizeof(m_nId);

	return true;
}
