/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "fsMFCLangMgr.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

fsMFCLangMgr::fsMFCLangMgr()
{

}

fsMFCLangMgr::~fsMFCLangMgr()
{

}

void fsMFCLangMgr::ApplyLanguage(CDialog *dlg, fsDlgLngInfo *lnginfo, int cInfo, UINT uIDStrTitle)
{
	while (cInfo--)
	{
		if (lnginfo [cInfo].bAddColon == FALSE)
		{
			dlg->SetDlgItemText (lnginfo [cInfo].nCtrlID, LS (lnginfo [cInfo].nIDStr));
		}
		else
		{
			CString str = LS (lnginfo [cInfo].nIDStr);
			str += ':';
			dlg->SetDlgItemText (lnginfo [cInfo].nCtrlID, str);
		}
	}

	if (uIDStrTitle)
		dlg->SetWindowText (LS (uIDStrTitle));
}
