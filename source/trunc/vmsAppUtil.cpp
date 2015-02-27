/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fdm.h"
#include "vmsAppUtil.h"
#include "vmsSimpleFileDownloader.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsAppUtil::vmsAppUtil()
{

}

vmsAppUtil::~vmsAppUtil()
{

}

fsInternetResult vmsAppUtil::UrlDownloadToFile(LPCSTR pszUrl, LPCSTR pszFileName)
{
	vmsSimpleFileDownloader dldr;
	dldr.Download (pszUrl, pszFileName);
	while (dldr.IsRunning ())
		Sleep (10);
	return dldr.GetLastError ();
}
