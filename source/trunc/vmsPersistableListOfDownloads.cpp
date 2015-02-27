/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsPersistableListOfDownloads.h"

vmsDownloadList::vmsDownloadList()
{
}

vmsDownloadList::~vmsDownloadList()
{
}

void vmsDownloadList::resetDirty()
{
	m_bState = POS_NOTMODIFIEDSINCELASTSAVE;
}

void vmsDownloadList::Copy(DLDS_LIST& v)
{
	for (size_t szIndex = 0; szIndex < m_vObj.size(); szIndex++)
		v.push_back (m_vObj [szIndex]);
}

vmsDownloadList& vmsDownloadList::operator = (const vmsDownloadList& listObj)
{
	vmsCriticalSectionAutoLock csalStateGuardAutoLock(&m_csObj);
	m_vObj = listObj.m_vObj;
	return *this;
}

void vmsDownloadList::getObjectItselfStateBuffer(LPBYTE pb, LPDWORD pdwSize, bool bSaveToStorage)
{
	if (!pb && pdwSize) {
		*pdwSize = sizeof(DWORD);
	}

	if (pb && pdwSize) {
		if (*pdwSize < sizeof(DWORD)) {
			*pdwSize = sizeof(DWORD);
			return;
		}

		DWORD* pdwBuffer = (DWORD*)pb;
		*pdwBuffer = (DWORD)size();
		*pdwSize = sizeof(DWORD);
	}
}

bool vmsDownloadList::loadObjectItselfFromStateBuffer(LPBYTE pb, LPDWORD pdwSize, DWORD dwVer)
{
	if (!pb)
		return false;

	if (!pdwSize)
		return false;

	if (*pdwSize < sizeof(DWORD))
		return false;

	DWORD dwSize;

	dwSize = *((DWORD*)pb);

	int i = 0;
	for (i = 0; i < dwSize; i++) {
		vmsDownloadSmartPtr dld;
		dld.CreateInstance ();
		

		vmsDownloadMgrEx* pMgr = (vmsDownloadMgrEx*)dld->pMgr;
		if (!pMgr)
			return false;

		Add(dld);
	}

	*pdwSize = sizeof(dwSize);

	return true;
}

vmsDownloadList& vmsDownloadList::operator = (const DLDS_LIST& v)
{
	vmsCriticalSectionAutoLock csalStateGuardAutoLock(&m_csObj);
	m_vObj = v;
	setDirty();
	return *this;
}

