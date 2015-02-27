/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __VMSREADERWRITERLOCK_H_
#define __VMSREADERWRITERLOCK_H_

#include "vmsCriticalSection.h"
#include "vmsTls.h"

class vmsReaderWriterLock
{
public:
	void AcquireReaderLock ()
	{
		DWORD dwThreadId = GetCurrentThreadId ();
		if (dwThreadId == m_dwWritingThreadId)
			return;
		DWORD cLocks = (DWORD)m_cTlsReadLocks.getValue ();
		if (!cLocks)
		{
			vmsAUTOLOCKSECTION (m_csWrite);
			if (InterlockedIncrement (&m_cTotalThreadsHavingReadLocks) == 1)
				ResetEvent (m_hevNoReads);
		}
		cLocks++;
		m_cTlsReadLocks.setValue ((LPVOID)cLocks);
	}
	void ReleaseReaderLock ()
	{
		DWORD dwThreadId = GetCurrentThreadId ();
		if (dwThreadId == m_dwWritingThreadId)
			return;
		DWORD cLocks = (DWORD)m_cTlsReadLocks.getValue ();
		assert (cLocks != 0);
		if (!cLocks)
			return;
		cLocks--;
		m_cTlsReadLocks.setValue ((LPVOID)cLocks);
		if (!cLocks)
		{
			if (!InterlockedDecrement (&m_cTotalThreadsHavingReadLocks))
				SetEvent (m_hevNoReads);
		}

	}
	void AcquireWriterLock ()
	{
		DWORD dwThreadId = GetCurrentThreadId ();
		if (dwThreadId == m_dwWritingThreadId)
		{
			m_cWritingThreadLocks++;
			return;
		}

		EnterCriticalSection (&m_csWrite);
		assert (m_dwWritingThreadId == 0);
		m_dwWritingThreadId = dwThreadId;
		assert (m_cWritingThreadLocks == 0);
		m_cWritingThreadLocks = 1;

		WaitForSingleObject (m_hevNoReads, INFINITE);
	}
	void ReleaseWriterLock ()
	{
		assert (GetCurrentThreadId () == m_dwWritingThreadId);
		if (--m_cWritingThreadLocks)		
			return;
		m_dwWritingThreadId = 0;
		LeaveCriticalSection (&m_csWrite);
	}

public:
	vmsReaderWriterLock () 
	{
		if (!m_cTlsReadLocks.isTlsAllocatedSuccessfully ())
			throw std::exception ("Failed allocate TLS value for ReaderWriterLock");
		m_hevNoReads = CreateEvent (NULL, TRUE, TRUE, NULL);
		m_dwWritingThreadId = 0;
		m_cWritingThreadLocks = 0;
		m_cTotalThreadsHavingReadLocks = 0;
	}
	~vmsReaderWriterLock () 
	{

	}
protected:
	vmsCriticalSection m_csWrite, m_csRLI;
	HANDLE m_hevNoReads;
	LONG m_cTotalThreadsHavingReadLocks;
	LONG m_cWritingThreadLocks;
	DWORD m_dwWritingThreadId;
	vmsTls m_cTlsReadLocks;
};

class vmsReaderWriterLockAutoLockRead
{
public:
	vmsReaderWriterLockAutoLockRead (vmsReaderWriterLock *p) {
		assert (p != NULL);
		m_prwl = p; 
		if (p) 
			p->AcquireReaderLock ();
	}
	~vmsReaderWriterLockAutoLockRead () {
		if (m_prwl)
			m_prwl->ReleaseReaderLock ();
	}
	void Unlock () {
		if (m_prwl)
		{
			m_prwl->ReleaseReaderLock ();
			m_prwl = NULL;
		}
	}
protected:
	vmsReaderWriterLock *m_prwl;
};

class vmsReaderWriterLockAutoLockWrite
{
public:
	vmsReaderWriterLockAutoLockWrite (vmsReaderWriterLock *p) {
		assert (p != NULL);
		m_prwl = p; 
		if (p) 
			p->AcquireWriterLock ();
	}
	~vmsReaderWriterLockAutoLockWrite () {
		if (m_prwl)
			m_prwl->ReleaseWriterLock ();
	}
	void Unlock () {
		if (m_prwl)
		{
			m_prwl->ReleaseWriterLock ();
			m_prwl = NULL;
		}
	}
protected:
	vmsReaderWriterLock *m_prwl;
};

#define vmsAUTOLOCKRW_READ(rw) vmsReaderWriterLockAutoLockRead rwalr_##rw (&rw)
#define vmsAUTOLOCKRW_READ_UNLOCK(rw) rwalr_##rw.Unlock()
#define vmsAUTOLOCKRW_WRITE(rw) vmsReaderWriterLockAutoLockWrite rwalw_##rw (&rw)
#define vmsAUTOLOCKRW_WRITE_UNLOCK(rw) rwalw_##rw.Unlock()

#endif 