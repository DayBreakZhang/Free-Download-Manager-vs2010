/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsMaximumSpeedMeter.h"

vmsMaximumSpeedMeter::vmsMaximumSpeedMeter(void)
{
	m_uMaxSpeed = 0;
	m_uCurrentMaximumSpeed = 0;
}

vmsMaximumSpeedMeter::~vmsMaximumSpeedMeter(void)
{
}

void vmsMaximumSpeedMeter::onCurrentSpeedIs(UINT64 uSpeed)
{
	
	
	if (!uSpeed || uSpeed < m_uMaxSpeed)
		return;

	double dG, dL;
	if (uSpeed > m_uCurrentMaximumSpeed)
	{
		dG = (double)uSpeed;
		dL = (double)m_uCurrentMaximumSpeed;
	}
	else
	{
		dG = (double)m_uCurrentMaximumSpeed;
		dL = (double)uSpeed;
	}
	
	if (dL == 0.0 || dG / dL > 1.1)
	{
		
		
		
		m_uCurrentMaximumSpeed = uSpeed;
		m_ticksValidSpeedMeterStart.Now ();
	}
	else
	{
		
		if (uSpeed > m_uCurrentMaximumSpeed)
			m_uCurrentMaximumSpeed = uSpeed;
		
		
		fsTicksMgr ticksNow;
		if (ticksNow - m_ticksValidSpeedMeterStart >= 15*1000)
		{
			
			
			
			
			m_uMaxSpeed = m_uCurrentMaximumSpeed;
		}
	}
}

bool vmsMaximumSpeedMeter::isMaximumSpeedMeasured(void)
{
	return m_uMaxSpeed != 0;
}
