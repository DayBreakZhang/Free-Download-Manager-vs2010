/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSMFCLANGMGR_H__90628146_B368_4966_A4F2_F7F9CB7E50CC__INCLUDED_)
#define AFX_FSMFCLANGMGR_H__90628146_B368_4966_A4F2_F7F9CB7E50CC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "fsLangMgr.h"

struct fsDlgLngInfo
{
	UINT nCtrlID;		
	UINT nIDStr;		
	BOOL bAddColon;

	fsDlgLngInfo (UINT u1, UINT u2, BOOL bAddColon = FALSE) : nCtrlID (u1), nIDStr (u2), bAddColon (bAddColon) {}
};

class fsMFCLangMgr : public fsLangMgr  
{
public:
	
	
	
	
	void ApplyLanguage (CDialog* dlg, fsDlgLngInfo* lnginfo, int cInfo, UINT uIDStrTitle = 0);

	fsMFCLangMgr();
	virtual ~fsMFCLangMgr();

};

#endif 
