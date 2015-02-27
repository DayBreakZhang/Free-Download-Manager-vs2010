/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_WEBINTERFACE_H__4297E6F9_7ED7_4AE6_B9A4_BB94E75048B2__INCLUDED_)
#define AFX_WEBINTERFACE_H__4297E6F9_7ED7_4AE6_B9A4_BB94E75048B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		
#include "vmsSingleInstance.h"	

class CWebInterfaceApp : public CWinApp
{
public:
	CWebInterfaceApp();

	
	//{{AFX_VIRTUAL(CWebInterfaceApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CWebInterfaceApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
protected:
	vmsSingleInstance m_si;
};

//{{AFX_INSERT_LOCATION}}

#endif 
