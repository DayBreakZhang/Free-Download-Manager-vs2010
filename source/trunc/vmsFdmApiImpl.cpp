/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fdm.h"
#include "vmsFdmApiImpl.h"
#include "vmsFdmApiDownloadsMgrImpl.h"
#include "MainFrm.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsFdmApiImpl::vmsFdmApiImpl()
{

}

vmsFdmApiImpl::~vmsFdmApiImpl()
{

}

vmsFdmApiImpl& vmsFdmApiImpl::o()
{
	static vmsFdmApiImpl o;
	return o;
}

UINT vmsFdmApiImpl::getFdmBuildNumber()
{
	return atoi (vmsFdmAppMgr::getBuildNumberAsString ());
}

void vmsFdmApiImpl::ShutdownFdm()
{
	AfxGetApp ()->m_pMainWnd->PostMessage (WM_COMMAND, ID_APP_EXIT_2);
}

vmsFdmApiDownloadsMgr* vmsFdmApiImpl::getDownloadsMgr()
{
	return &vmsFdmApiDownloadsMgrImpl::o ();
}

HWND vmsFdmApiImpl::getFdmWindowHandle()
{
	return AfxGetApp ()->m_pMainWnd->m_hWnd;
}
