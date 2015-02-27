/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "fsDldFilter.h"
#include "ShedulerWnd.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

extern CShedulerWnd *_pwndScheduler;

fsDldFilter::fsDldFilter()
{

}

fsDldFilter::~fsDldFilter()
{

}

BOOL fsDldFilter::IsSatisfies(vmsDownloadSmartPtr )
{
	return TRUE;
}

fsDldGroupFilter::fsDldGroupFilter()
{

}

fsDldGroupFilter::~fsDldGroupFilter()
{

}

void fsDldGroupFilter::SetGroup(vmsDownloadsGroupSmartPtr pGroup)
{
	m_pGrp = pGroup;
}

BOOL fsDldGroupFilter::IsSatisfies(vmsDownloadSmartPtr dld)
{
	return m_pGrp->nId == dld->pGroup->nId;
}

fsDldRunningFilter::fsDldRunningFilter()
{

}

fsDldRunningFilter::~fsDldRunningFilter()
{

}

BOOL fsDldRunningFilter::IsSatisfies(vmsDownloadSmartPtr dld)
{
	return dld->pMgr->IsRunning ();
}

fsDldDoneFilter::fsDldDoneFilter()
{

}

fsDldDoneFilter::~fsDldDoneFilter()
{

}

BOOL fsDldDoneFilter::IsSatisfies(vmsDownloadSmartPtr dld)
{
	return dld->pMgr->IsDone ();
}

fsDldTasksFilter::fsDldTasksFilter()
{

}

fsDldTasksFilter::~fsDldTasksFilter()
{

}

BOOL fsDldTasksFilter::IsSatisfies(vmsDownloadSmartPtr dld)
{
	
	
	BOOL bDone = dld->pMgr->IsDone ();
	BOOL bYes = !bDone;
	if (!bYes)
	{
		
		if (dld->dateCompleted.dwHighDateTime)
			bYes = CompareFileTime (&_timeAppHasStarted, &dld->dateCompleted) != 1;
		else
			bYes = CompareFileTime (&_timeAppHasStarted, &dld->dateAdded) != 1;
	}
	if (!bYes)
	{
		if (dld->dateCompleted.dwHighDateTime)
		{
			
			bYes = fsGetFTimeDaysDelta (_timeAppHasStarted, dld->dateCompleted) == 0;
		}
		else
		{
			SYSTEMTIME st1, st2;
			FileTimeToSystemTime (&_timeAppHasStarted, &st1);
			FileTimeToSystemTime (&dld->dateAdded, &st2);
			bYes = (st1.wDay == st2.wDay) && (st1.wMonth == st2.wMonth) && (st1.wYear == st2.wYear);
		}
	}
	return bYes;
}

fsDldStoppedFilter::fsDldStoppedFilter()
{

}

fsDldStoppedFilter::~fsDldStoppedFilter()
{

}

BOOL fsDldStoppedFilter::IsSatisfies(vmsDownloadSmartPtr dld)
{
	return dld->pMgr->IsRunning () == FALSE && dld->pMgr->IsDone () == FALSE;
}

fsDldScheduledFilter::fsDldScheduledFilter()
{

}

fsDldScheduledFilter::~fsDldScheduledFilter()
{

}

BOOL fsDldScheduledFilter::IsSatisfies(vmsDownloadSmartPtr dld)
{
	return _pwndScheduler->GetMgr ()->IsDownloadScheduled (dld);
}

fsDldFilterType fsDldFilter::GetType()
{
	return DFT_NONE;
}

vmsDownloadsGroupSmartPtr fsDldGroupFilter::GetGroup()
{
	return m_pGrp;
}

fsDldFilterType fsDldGroupFilter::GetType()
{
	return DFT_GROUP;
}

fsDldHistRecFilter::fsDldHistRecFilter()
{

}

fsDldHistRecFilter::~fsDldHistRecFilter()
{

}

BOOL fsDldHistRecFilter::IsSatisfies(fsDLHistoryRecord* )
{
	return TRUE;
}

fsDldHistRecFilter_DuringPeriod::fsDldHistRecFilter_DuringPeriod()
{
	SetPeriod (0);	
}

fsDldHistRecFilter_DuringPeriod::~fsDldHistRecFilter_DuringPeriod()
{

}

fsDldHistRecFilter_Today::fsDldHistRecFilter_Today()
{

}

fsDldHistRecFilter_Today::~fsDldHistRecFilter_Today()
{

}

fsDldHistRecFilter_Yesterday::fsDldHistRecFilter_Yesterday()
{

}

fsDldHistRecFilter_Yesterday::~fsDldHistRecFilter_Yesterday()
{

}

fsDldHistRecFilter_Custom::fsDldHistRecFilter_Custom()
{

}

fsDldHistRecFilter_Custom::~fsDldHistRecFilter_Custom()
{

}

BOOL fsDldHistRecFilter_Custom::IsSatisfies(fsDLHistoryRecord* rec)
{
	if (CompareFileTime (&m_tFrom, &rec->dateAdded) == 1)
		return FALSE;

	if (CompareFileTime (&rec->dateAdded, &m_tTo) == 1)
		return FALSE;
	
	return TRUE;
}

BOOL fsDldHistRecFilter_DuringPeriod::IsSatisfies(fsDLHistoryRecord * rec)
{
	SYSTEMTIME s;
	FILETIME f;

	GetLocalTime (&s);
	SystemTimeToFileTime (&s, &f);

	return fsGetFTimeDaysDelta (f, rec->dateRecordAdded) <= m_lastDays;
}

BOOL fsDldHistRecFilter_Today::IsSatisfies(fsDLHistoryRecord* rec)
{
	SYSTEMTIME s1, s2;

	GetLocalTime (&s1);
	FileTimeToSystemTime (&rec->dateAdded, &s2);

	return s1.wDay == s2.wDay && s1.wMonth == s2.wMonth && s1.wYear == s2.wYear;
}

BOOL fsDldHistRecFilter_Yesterday::IsSatisfies(fsDLHistoryRecord* rec)
{
	SYSTEMTIME s1, s2;

	GetLocalTime (&s1);
	FileTimeToSystemTime (&rec->dateAdded, &s2);

	if (s1.wDay == 0)
	{
		if ((s1.wMonth % 2) || s1.wMonth == 8)
		{
			s1.wDay = 31;
		}
		else
		{
			if (s1.wMonth == 2)
			{
				if (s1.wYear % 4)
					s1.wDay = 28;
				else 
					s1.wDay = 29;
			}
			else
			{
				s1.wDay = 30;
			}
		}

		s1.wMonth--;
	}
	else
		s1.wDay--;

	return s1.wDay == s2.wDay && s1.wMonth == s2.wMonth && s1.wYear == s2.wYear;
}

void fsDldHistRecFilter_DuringPeriod::SetPeriod(int cDays)
{
	m_lastDays = cDays;
}

void fsDldHistRecFilter_Custom::SetTimeRange(FILETIME tFrom, FILETIME tTo)
{
	m_tFrom = tFrom;
	m_tTo = tTo;
}
