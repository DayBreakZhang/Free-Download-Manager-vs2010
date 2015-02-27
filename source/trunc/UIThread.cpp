/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "UIThread.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(UIThread, CWinThread)

UIThread::UIThread()
{
}

UIThread::~UIThread()
{
}

BOOL UIThread::InitInstance()
{
	OnDoWork ();
	return FALSE;
}

int UIThread::ExitInstance()
{
	
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(UIThread, CWinThread)
	//{{AFX_MSG_MAP(UIThread)
	ON_COMMAND(ID_UITHR_DOWORK, OnDoWork)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void UIThread::set_Thread(LPTHREAD_START_ROUTINE pfn, LPVOID lpParam)
{
	m_pfnThread = pfn;
	m_lpParam = lpParam;
}

extern CFdmApp theApp;

void UIThread::OnDoWork() 
{
	AFX_MANAGE_STATE (theApp.GetModuleState ());
	AfxEndThread (m_pfnThread (m_lpParam));
}

void UIThread::StartDoWork()
{
	while (FALSE == PostThreadMessage (WM_COMMAND, ID_UITHR_DOWORK, 0))
		Sleep (50);
}
