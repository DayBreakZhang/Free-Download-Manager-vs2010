/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLG_SPREADHELP2_WB_UIHANDLER_H__2E5DD0EB_FBF2_4018_BAE1_5090FE0E333C__INCLUDED_)
#define AFX_DLG_SPREADHELP2_WB_UIHANDLER_H__2E5DD0EB_FBF2_4018_BAE1_5090FE0E333C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsDocHostUIHandler.h"

class CDlg_SpreadHelp2_wb_UIHandler : public vmsDocHostUIHandler
{
public:
	STDMETHOD(GetHostInfo)(DOCHOSTUIINFO *pInfo);
	CDlg_SpreadHelp2_wb_UIHandler();
	virtual ~CDlg_SpreadHelp2_wb_UIHandler();

};

#endif 
