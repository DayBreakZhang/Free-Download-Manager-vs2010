/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fsMutex.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

fsMutex::fsMutex()
{
	m_mx = CreateMutex (NULL, FALSE, NULL);
	m_cLocks = 0;
}

fsMutex::~fsMutex()
{
	if (m_mx)
		CloseHandle (m_mx);
}

void fsMutex::Lock()
{
	ASSERT (m_mx != NULL);

	if (m_mx == NULL)
		return;

	const int WAIT_TIME		= 10000;
	const int WAIT_INTERVAL	= 50;

	int i = 0;
	for (i = 0; i < WAIT_TIME/WAIT_INTERVAL; i++)
	{
		DWORD dwRet = WaitForSingleObject (m_mx, WAIT_INTERVAL);
		if (dwRet == WAIT_TIMEOUT)
		{
			MSG msg;
			while (PeekMessage (&msg, 0, 0, 0, PM_REMOVE))
			{
				TranslateMessage (&msg);
				DispatchMessage (&msg);
			}
		}
		else
		{
			
			m_cLocks++;
			break;
		}
	}

	
	
	ASSERT (i != WAIT_TIME/WAIT_INTERVAL);
}

void fsMutex::Unlock()
{
	if (m_mx == NULL || m_cLocks == 0)
		return;
	
	m_cLocks--;
	ReleaseMutex (m_mx);
}
