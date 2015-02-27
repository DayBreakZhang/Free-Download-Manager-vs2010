/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "Iecooks.h"
#include "FDMIEStat.h"
#include "FDMIECookiesBHO.h"

STDMETHODIMP CFDMIEStat::get_DownloadCount(long *pVal)
{
	*pVal = CFDMIEBHO::get_IEDownloadsCount ();
	return S_OK;
}
