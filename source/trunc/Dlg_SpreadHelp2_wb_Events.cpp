/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Dlg_SpreadHelp2_wb_Events.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

BEGIN_DISPATCH_MAP(CDlg_SpreadHelp2_wb_Events, vmsWebBrowserEvents)
	DISP_FUNCTION_ID(CDlg_SpreadHelp2_wb_Events, "BeforeNavigate2", DISPID_BEFORENAVIGATE2, OnBeforeNavigate2, VT_EMPTY, VTS_DISPATCH VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PBOOL)
END_DISPATCH_MAP()

CDlg_SpreadHelp2_wb_Events::CDlg_SpreadHelp2_wb_Events(CWebBrowser2 *pWB, IDocHostUIHandler *pUIHandler) :
	vmsWebBrowserEvents (pWB, pUIHandler)
{

}

CDlg_SpreadHelp2_wb_Events::~CDlg_SpreadHelp2_wb_Events()
{

}

void CDlg_SpreadHelp2_wb_Events::OnBeforeNavigate2(LPDISPATCH, VARIANT *vtUrl, VARIANT *, VARIANT *vtTarget, VARIANT *, VARIANT *, BOOL *pbCancel)
{
	CString strUrl = vtUrl->bstrVal;

	if (strUrl.Left (4).CompareNoCase ("http") == 0) 
	{
		*pbCancel = TRUE;
		fsOpenUrlInBrowser (strUrl);
	}
}
