/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fsEventsMgr.h"
#include "misc.h"
#include "common.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

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
		delete [] m_vEvents [i].pszEvent;
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
		fsDescEvent *ev = &m_vEvents [i];

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
		fsDescEvent ev;

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

		m_vEvents.add (ev);
	}
	
	return TRUE;
}

UINT fsEventsMgr::GetEventCount()
{
	return m_vEvents.size ();
}

fsDescEvent* fsEventsMgr::GetEvent(UINT uIndex)
{
	return &m_vEvents [uIndex];
}

void fsEventsMgr::add(fsDescEvent *ev)
{
	SYSTEMTIME time;
	GetLocalTime (&time);

	SystemTimeToFileTime (&time, &ev->timeEvent);

	m_vEvents.add (*ev);
}

