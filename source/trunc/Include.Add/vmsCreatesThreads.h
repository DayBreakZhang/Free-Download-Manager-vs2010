/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once
class vmsCreatesThreads
{
public:
	vmsCreatesThreads () 
	{
		m_hevShuttingDown = CreateEvent (NULL, TRUE,  FALSE, NULL);
	}
	virtual void Shutdown () 
	{
		SetEvent (m_hevShuttingDown);
	}
	void WaitThreadsForShutdown ()
	{
		for (;;)
		{
			HANDLE hThread = NULL;
			EnterCriticalSection (&m_csThreads);
			if (!m_vhtThreads.empty ())
			{
				hThread = m_vhtThreads [0];
				assert (hThread != NULL);
			}
			LeaveCriticalSection (&m_csThreads);
			if (!hThread)
				return;
			WaitForSingleObject (hThread, INFINITE);
			EnterCriticalSection (&m_csThreads);
			if (!m_vhtThreads.empty () && hThread == m_vhtThreads [0])
				m_vhtThreads.erase (m_vhtThreads.begin ());
			LeaveCriticalSection (&m_csThreads);
		}
	}
	virtual ~vmsCreatesThreads ()
	{
		
		assert (m_vhtThreads.empty ());
		CloseHandle (m_hevShuttingDown);
	}
protected:
	
	void onThreadCreated (HANDLE hThread)
	{
		assert (hThread != NULL);
		if (!hThread)
			return;
		vmsAUTOLOCKSECTION (m_csThreads);
		m_vhtThreads.push_back (hThread);
	}
	
	void onThreadTerminating ()
	{
		HANDLE hThread = GetCurrentThread ();
		vmsAUTOLOCKSECTION (m_csThreads);
		for (std::vector <HANDLE>::iterator it = m_vhtThreads.begin (); it != m_vhtThreads.end (); it++)
		{
			if (*it == hThread)
			{
				m_vhtThreads.erase (it);
				return;
			}
		}
	}
protected:
	std::vector <HANDLE> m_vhtThreads;
	vmsCriticalSection m_csThreads;
	HANDLE m_hevShuttingDown;
};