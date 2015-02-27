/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FDMCUSTOMIZED_H__F82052EC_1273_4918_8012_EACDD1E1ADF6__INCLUDED_)
#define AFX_FDMCUSTOMIZED_H__F82052EC_1273_4918_8012_EACDD1E1ADF6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		

class CFDMCustomizedApp : public CWinApp
{
public:
	CFDMCustomizedApp();

	
	//{{AFX_VIRTUAL(CFDMCustomizedApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CFDMCustomizedApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
