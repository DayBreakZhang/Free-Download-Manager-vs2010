/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsSpeedTracker.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsSpeedTracker::vmsSpeedTracker()
{
	m_nLowSpeedFactor = 3;
	m_nLowSpeedDuration = 60;

	Reset ();
}

vmsSpeedTracker::~vmsSpeedTracker()
{

}

void vmsSpeedTracker::CurrentSpeedIs(int nSpeed)
{
	if (m_cAvrSpeedsAtStart < 20)
	{
		

		m_nAvrSpeedAtStart = (m_nAvrSpeedAtStart * m_cAvrSpeedsAtStart + nSpeed) / 
			(m_cAvrSpeedsAtStart + 1);
		m_cAvrSpeedsAtStart++;
	}
	else
	{
		

		if (nSpeed == 0 || m_nAvrSpeedAtStart / nSpeed >= (UINT)m_nLowSpeedFactor)
			m_cTooLowSpeeds++; 
		else
			m_cTooLowSpeeds = 0; 
	}
}

bool vmsSpeedTracker::CheckCurrentSpeedTooLow()
{
	return m_cTooLowSpeeds > m_nLowSpeedDuration;
}

void vmsSpeedTracker::Reset()
{
	m_nAvrSpeedAtStart = 0;
	m_cAvrSpeedsAtStart = 0;
	m_cTooLowSpeeds = 0;
}

void vmsSpeedTracker::set_LowSpeedFactor(int i)
{
	if (i > 1)
		m_nLowSpeedFactor = i;
}

void vmsSpeedTracker::set_LowSpeedDuration(int i)
{
	if (i >= 60)
		m_nLowSpeedDuration = i;
}
