/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSMFCLNGHELPER_H__922AC63E_6DBE_4E5A_991A_4403A7A8558D__INCLUDED_)
#define AFX_VMSMFCLNGHELPER_H__922AC63E_6DBE_4E5A_991A_4403A7A8558D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

struct fsDlgLngInfo
{
	UINT nCtrlID;		
	UINT nIDStr;		
	BOOL bAddColon;

	fsDlgLngInfo (UINT u1, UINT u2, BOOL bAddColon = FALSE) : nCtrlID (u1), nIDStr (u2), bAddColon (bAddColon) {}
};

class vmsMfcLngHelper
{
public:
	static void ApplyLanguage(CDialog *dlg, fsDlgLngInfo *lnginfo, int cInfo, UINT uIDStrTitle);
	vmsMfcLngHelper();
	virtual ~vmsMfcLngHelper();

};

#endif 
