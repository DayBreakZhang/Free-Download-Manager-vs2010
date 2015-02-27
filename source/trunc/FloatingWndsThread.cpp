/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "FloatingWndsThread.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CFloatingWndsThread, CWinThread)

CFloatingWndsThread::CFloatingWndsThread()
{
}

CFloatingWndsThread::~CFloatingWndsThread()
{
}

BOOL CFloatingWndsThread::InitInstance()
{
	OleInitialize (NULL);

	m_wndFloating.Create ();
	m_wndFloatingInfo.Create ();

	return TRUE;
}

int CFloatingWndsThread::ExitInstance()
{
	
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CFloatingWndsThread, CWinThread)
	//{{AFX_MSG_MAP(CFloatingWndsThread)
		
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

