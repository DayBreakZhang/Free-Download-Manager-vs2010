/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once
class vmsMaximumSpeedMeter
{
public:
	vmsMaximumSpeedMeter(void);
	virtual ~vmsMaximumSpeedMeter(void);
	void onCurrentSpeedIs(UINT64 uSpeed);
	bool isMaximumSpeedMeasured(void);
	UINT64 getMaximumSpeed () {return m_uMaxSpeed;}
	UINT64 getCurrentMaximumSpeed () {return m_uCurrentMaximumSpeed;}

protected:
	UINT64 m_uMaxSpeed;
	fsTicksMgr m_ticksValidSpeedMeterStart;
	UINT64 m_uCurrentMaximumSpeed;
};

