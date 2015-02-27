/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "vmsDownloadsListHelper.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsDownloadsListHelper::vmsDownloadsListHelper()
{

}

vmsDownloadsListHelper::~vmsDownloadsListHelper()
{

}

void vmsDownloadsListHelper::GetStat(DLDS_LIST_REF v, BOOL *pbHasRunning, BOOL *pbHasStopped, BOOL *pbHasCompleted, BOOL *pbHasAutostart, BOOL *pbHasNotAutostart)
{
	if (pbHasRunning)
		*pbHasRunning = FALSE;
	if (pbHasStopped)
		*pbHasStopped = FALSE;
	if (pbHasCompleted)
		*pbHasCompleted = FALSE;
	if (pbHasAutostart)
		*pbHasAutostart = FALSE;
	if (pbHasNotAutostart)
		*pbHasNotAutostart = FALSE;

	for (size_t i = 0; i < v.size (); i++)
	{
		vmsDownloadSmartPtr dld = v [i];

		if (pbHasRunning)
		if (*pbHasRunning == FALSE && dld->pMgr->IsRunning ())
			*pbHasRunning = TRUE;

		if (pbHasStopped)
		if (*pbHasStopped == FALSE && dld->pMgr->IsRunning () == FALSE && dld->pMgr->IsDone () == FALSE)
			*pbHasStopped = TRUE;

		if (pbHasCompleted)
		if (*pbHasCompleted == FALSE && dld->pMgr->IsDone ())
			*pbHasCompleted = TRUE;

		if (dld->bAutoStart)
		{
			if (pbHasAutostart)
				*pbHasAutostart = TRUE;
		}
		else
		{
			if (pbHasNotAutostart)
				*pbHasNotAutostart = TRUE;
		}
	}
}
