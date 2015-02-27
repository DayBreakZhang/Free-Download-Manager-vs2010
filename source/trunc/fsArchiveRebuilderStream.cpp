/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fsArchiveRebuilderStream.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

using namespace fsArchive;

fsArchiveStream::fsArchiveStream()
{
	m_dwLastError = NOERROR;
}

fsArchiveStream::~fsArchiveStream()
{

}

