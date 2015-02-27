/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fsTicksMgr.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

fsTicksMgr::fsTicksMgr()
{
	Now ();
}

fsTicksMgr::~fsTicksMgr()
{

}

void fsTicksMgr::Now()
{
	m_dwTicks = GetTickCount ();
}

DWORD fsTicksMgr::operator -(fsTicksMgr &ticks)
{
	
	if (m_dwTicks >= ticks.m_dwTicks)
		return m_dwTicks - ticks.m_dwTicks;
	else 
		return (0xffffffff - ticks.m_dwTicks + m_dwTicks);
}
