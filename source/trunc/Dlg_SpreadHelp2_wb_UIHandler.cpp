/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Dlg_SpreadHelp2_wb_UIHandler.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

CDlg_SpreadHelp2_wb_UIHandler::CDlg_SpreadHelp2_wb_UIHandler()
{

}

CDlg_SpreadHelp2_wb_UIHandler::~CDlg_SpreadHelp2_wb_UIHandler()
{

}

STDMETHODIMP CDlg_SpreadHelp2_wb_UIHandler::GetHostInfo(DOCHOSTUIINFO *pInfo)
{
	pInfo->dwFlags = DOCHOSTUIFLAG_DIALOG | DOCHOSTUIFLAG_NO3DBORDER |
		DOCHOSTUIFLAG_NO3DOUTERBORDER | DOCHOSTUIFLAG_SCROLL_NO;
	return S_OK;
}
