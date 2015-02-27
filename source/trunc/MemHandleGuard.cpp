/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "StdAfx.h"
#include "MemHandleGuard.h"
#include "vmsLogger.h"

CMemHandleGuard::CMemHandleGuard(LPVOID& pMemPtr, bool& bFailedToRelease)
	: m_pMemPtr(pMemPtr),
	  m_bFailedToRelease(bFailedToRelease)
{
}

CMemHandleGuard::~CMemHandleGuard()
{
	try 
	{
		HLOCAL hMem = (HLOCAL)m_pMemPtr;
		if (hMem != 0) {
			if (LocalFree(hMem) != 0) {

				m_bFailedToRelease = true;
				
			}
			m_pMemPtr = 0;
		}
	} 
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CMemHandleGuard::~CMemHandleGuard " + tstring(ex.what()));
		m_bFailedToRelease = true;
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CMemHandleGuard::~CMemHandleGuard unknown exception");
		m_bFailedToRelease = true;
	}
}
