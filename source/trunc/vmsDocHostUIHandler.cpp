/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "vmsDocHostUIHandler.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsDocHostUIHandler::vmsDocHostUIHandler()
{

}

vmsDocHostUIHandler::~vmsDocHostUIHandler()
{

}

STDMETHODIMP vmsDocHostUIHandler::GetHostInfo(DOCHOSTUIINFO *pInfo)
{
	

	pInfo->dwFlags = DOCHOSTUIFLAG_ENABLE_INPLACE_NAVIGATION | 
		DOCHOSTUIFLAG_THEME;

	return S_OK;
}
