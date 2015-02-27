/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSSPEEDTRACKER_H__1E7A996C_6CF4_4DC0_A19B_4C5ED97450A4__INCLUDED_)
#define AFX_VMSSPEEDTRACKER_H__1E7A996C_6CF4_4DC0_A19B_4C5ED97450A4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include <fslist.h>

class vmsSpeedTracker  
{
public:
	
	bool CheckCurrentSpeedTooLow();

	
	
	void CurrentSpeedIs ( int nSpeed);

	
	
	
	void set_LowSpeedDuration (int i);
	
	void set_LowSpeedFactor (int i);

	
	void Reset();
	

	vmsSpeedTracker();
	virtual ~vmsSpeedTracker();

protected:
	
	UINT m_nAvrSpeedAtStart;
	
	int  m_cAvrSpeedsAtStart;
	
	int  m_cTooLowSpeeds;
	
	int  m_nLowSpeedFactor;
	int  m_nLowSpeedDuration;
};

#endif 
