/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fsArchiveRebuilder.h"

using namespace fsArchive;

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

fsArchiveRebuilder::fsArchiveRebuilder()
{
	m_in = m_out = NULL;
	m_uResArchiveSize = 0;
	m_dwFileSize = 0;
	m_dwSFXSize = 0;
}

fsArchiveRebuilder::~fsArchiveRebuilder()
{

}

DWORD fsArchiveRebuilder::OpenArchive(fsArchiveStream *in)
{
	m_in = in;
	return RetreiveArchiveContent ();
}

DWORD fsArchiveRebuilder::SaveArchiveHeaders(fsArchiveStream *out)
{
	m_out = out;
	return SaveArchiveHeaders_imp ();
}

UINT64 fsArchiveRebuilder::GetResultingArchiveSize()
{
	return m_uResArchiveSize;
}

void fsArchiveRebuilder::SetSFXSize(DWORD dw)
{
	m_dwSFXSize = dw;
}

void fsArchiveRebuilder::SetFileSize(DWORD dw)
{
	m_dwFileSize = dw;
}
