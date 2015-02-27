/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once

#include "vmsCreatesThreads.h"

class vmsAsyncTask
{
public:
	enum State
	{
		Waiting,
		InProgress,
		Done
	};
	enum Flags
	{
		RemoveWhenDone	= 1,		
	};
public:
	vmsAsyncTask () : m_enState (Waiting), m_dwFlags (0), m_lId (0), m_nType (0), m_hevDone (NULL) {}
	virtual ~vmsAsyncTask () 
	{
		if (m_hevDone)
			CloseHandle (m_hevDone);
	}
	virtual void Perform () = NULL;
	virtual bool isEqual (vmsAsyncTask* pTask) {return false;}
	void setState (State enState) {m_enState = enState;}
	State getState () const {return m_enState;}
	void setId (long lId) {m_lId = lId;}
	long getId () const {return m_lId;}
	UINT getType () const {return m_nType;}
	void setType (UINT nType) {m_nType = nType;}
	void setOnDoneEvent (HANDLE hev) {m_hevDone = hev;}
	HANDLE getOnDoneEvent () const {return m_hevDone;}
	void setFlags (DWORD dw) {m_dwFlags = dw;}
	DWORD getFlags () const {return m_dwFlags;}
protected:
	long m_lId;
	UINT m_nType;
	State m_enState;
	DWORD m_dwFlags;
	HANDLE m_hevDone;
};

typedef std::tr1::shared_ptr <vmsAsyncTask> tsp_vmsAsyncTask;

class vmsAsyncTaskMgr : protected vmsCreatesThreads
{
public:
	long AddTask (tsp_vmsAsyncTask spTask)
	{
		long lId = InterlockedIncrement (&m_lNextId);
		spTask->setId (lId);
		spTask->setState (vmsAsyncTask::Waiting);
		vmsAUTOLOCKSECTION (m_csTasks);
		m_vTasks.push_back (spTask);
		vmsAUTOLOCKSECTION_UNLOCK (m_csTasks);
		onTaskAdded ();
		return lId;
	}
	vmsAsyncTaskMgr () : m_lNextId (0), m_u8MaxThreads (3) 
	{
		m_hevHasTasks = CreateEvent (NULL, TRUE, FALSE, NULL);
	}
	~vmsAsyncTaskMgr () 
	{
		Shutdown ();
		WaitThreadsForShutdown ();
	}
	bool HasEqualTask (vmsAsyncTask* pTask, long* plEqualTaskId)
	{
		vmsAUTOLOCKSECTION (m_csTasks);
		for (std::vector <tsp_vmsAsyncTask>::iterator it = m_vTasks.begin (); it != m_vTasks.end (); it++)
		{
			if ((*it)->getType () != pTask->getType ())
				continue;
			if ((*it)->isEqual (pTask))
			{
				if (plEqualTaskId)
					*plEqualTaskId = (*it)->getId ();
				return true;
			}
		}
		return false;
	}
protected:
	std::vector <tsp_vmsAsyncTask> m_vTasks;
	vmsCriticalSection m_csTasks;
	long m_lNextId;
	UINT8 m_u8MaxThreads;
	HANDLE m_hevHasTasks;
protected:
	void onTaskAdded ()
	{
		bool bNeedCreateThread = false;
		bool bMayCreateThread = false;
		EnterCriticalSection (&m_csThreads);
		bMayCreateThread = m_vhtThreads.size () < m_u8MaxThreads;
		LeaveCriticalSection (&m_csThreads);
		vmsAUTOLOCKSECTION (m_csTasks);
		bNeedCreateThread = m_vhtThreads.empty ();
		if (!bNeedCreateThread)
			bNeedCreateThread = WaitForSingleObject (m_hevHasTasks, 0) == WAIT_OBJECT_0;
		if (bNeedCreateThread && bMayCreateThread)
			onThreadCreated ((HANDLE)_beginthreadex (NULL, 0, _threadPerformTasks, this, 0, NULL));
		SetEvent (m_hevHasTasks);
	}
	static UINT WINAPI _threadPerformTasks (LPVOID pvParam)
	{
		vmsAsyncTaskMgr *pthis = (vmsAsyncTaskMgr*)pvParam;

		HANDLE ahev [] = {pthis->m_hevHasTasks, pthis->m_hevShuttingDown};

		int i = _countof (ahev);

		DWORD dw = WaitForMultipleObjects (_countof (ahev), ahev, FALSE, INFINITE);

		while (WaitForMultipleObjects (_countof (ahev), ahev, FALSE, INFINITE) == WAIT_OBJECT_0)
				pthis->SelectAndPerformTask ();

		pthis->onThreadTerminating ();

		return 0;
	}
	void SelectAndPerformTask ()
	{
		tsp_vmsAsyncTask spTask;
		vmsAUTOLOCKSECTION (m_csTasks);
		for (std::vector <tsp_vmsAsyncTask>::iterator it = m_vTasks.begin (); it != m_vTasks.end (); it++)
		{
			if ((*it)->getState () == vmsAsyncTask::Waiting)
			{
				spTask = *it;
				spTask->setState (vmsAsyncTask::InProgress);
				break;
			}
		}
		if (!spTask)
		{
			ResetEvent (m_hevHasTasks);
			return;
		}
		vmsAUTOLOCKSECTION_UNLOCK (m_csTasks);
		spTask->Perform ();
		spTask->setState (vmsAsyncTask::Done);
		HANDLE hevDone = spTask->getOnDoneEvent ();
		if (hevDone)
			SetEvent (hevDone);
		if (spTask->getFlags () & vmsAsyncTask::RemoveWhenDone)
		{
			vmsAUTOLOCKSECTION (m_csTasks);
			for (std::vector <tsp_vmsAsyncTask>::iterator it = m_vTasks.begin (); it != m_vTasks.end (); it++)
			{
				if ((*it)->getId () == spTask->getId ())
				{
					m_vTasks.erase (it);
					break;
				}
			}
		}
	}
};
