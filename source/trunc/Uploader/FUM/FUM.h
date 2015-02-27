/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FUM_H__69111AD1_F2D5_4465_8F05_2454820FECD3__INCLUDED_)
#define AFX_FUM_H__69111AD1_F2D5_4465_8F05_2454820FECD3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       
#include "FUM_i.h"

const char* const _pszAppMutex = "Free Upload Manager";

class CFUMApp : public CWinApp
{
public:
	CFUMApp();

	
	//{{AFX_VIRTUAL(CFUMApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

public:
	void RegisterServer();
	AFX_MODULE_STATE* GetModuleState();
	BOOL CheckFUMStartedAlready (BOOL bSetForIfEx);
	BOOL InitLanguage();
	CString m_strAppPath;
	//{{AFX_MSG(CFUMApp)
	afx_msg void OnAppAbout();
		
		
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	BOOL m_bATLInited;
private:
	BOOL InitATL();
protected:
	BOOL IsRecentlyInstalledFumLaunched();
	BOOL MakeSureRecentlyInstalledFumLaunched();
	void IntegrationSettings();
	HANDLE m_hAppMutex;
};

//{{AFX_INSERT_LOCATION}}

#endif 
