/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once

#include "vmsLowIntegrityLevel.h"

class vmsAppMutex
{
public:
	vmsAppMutex(LPCTSTR ptszMutexName)
	{
		m_tstrName = ptszMutexName;
		m_hmxApp = NULL;
		m_bAnotherInstanceStartedAlready = false;		
		Create ();
	}

	void Create ()
	{
		assert (!m_hmxApp);
		if (m_hmxApp)
			return;

		OSVERSIONINFO ver;
		ZeroMemory (&ver, sizeof (ver));
		ver.dwOSVersionInfoSize = sizeof (ver);
		GetVersionEx (&ver);

		m_hmxApp = CreateMutex (ver.dwMajorVersion > 5 ? &vmsLowLabelSecurityAttributes () : NULL, TRUE, m_tstrName.c_str ());

		m_bAnotherInstanceStartedAlready = GetLastError () == ERROR_ALREADY_EXISTS;
	}

	void CloseMutex ()
	{
		if (m_hmxApp)
		{
			CloseHandle (m_hmxApp);
			m_hmxApp = NULL;
		}
	}

	bool isAnotherInstanceStartedAlready () const {return m_bAnotherInstanceStartedAlready;}
	LPCTSTR getName () const {return m_tstrName.c_str ();}

	~vmsAppMutex(void)
	{
		CloseMutex ();
	}

protected:
	HANDLE m_hmxApp;
	bool m_bAnotherInstanceStartedAlready;
	tstring m_tstrName;
};

