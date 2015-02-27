/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLG_SPREADHELP2_WB_EVENTS_H__17B9E76E_8D8A_4D94_BD91_A89E04A9943E__INCLUDED_)
#define AFX_DLG_SPREADHELP2_WB_EVENTS_H__17B9E76E_8D8A_4D94_BD91_A89E04A9943E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsWebBrowserEvents.h"

class CDlg_SpreadHelp2_wb_Events : public vmsWebBrowserEvents  
{
public:
	CDlg_SpreadHelp2_wb_Events(CWebBrowser2 *pWB = NULL, IDocHostUIHandler *pUIHandler = NULL);
	virtual ~CDlg_SpreadHelp2_wb_Events();

	DECLARE_DISPATCH_MAP();

protected:
	void OnBeforeNavigate2 (LPDISPATCH, VARIANT *vtUrl, VARIANT *, VARIANT *, VARIANT *, VARIANT *, BOOL* pbCancel);
};

#endif 
