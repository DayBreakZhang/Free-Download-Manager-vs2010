/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSSPEEDMETER_H__04BDDC02_9C84_4660_B261_00A72D42DDE0__INCLUDED_)
#define AFX_FSSPEEDMETER_H__04BDDC02_9C84_4660_B261_00A72D42DDE0__INCLUDED_

#include "fsTicksMgr.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

class fsSpeedMeter  
{
public:
	
	void Reset();
	
	
	void Done (DWORD dwDone);
	
	DWORD GetSpeed();
	
	void SetInertness (int val);

	fsSpeedMeter();
	virtual ~fsSpeedMeter();

protected:
	int m_cMeasures;	
	DWORD m_dwSpeed;	
	DWORD m_aPrevSpeed [10]; 
	int m_iCurPrevSpeed; 
	int m_iMaxPrevSpeed;	
	
	void UpdateSpeed();	

	fsTicksMgr m_now;	
	fsTicksMgr m_past;	
	DWORD m_done;		
};

#endif 
