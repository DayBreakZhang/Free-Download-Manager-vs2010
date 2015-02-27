/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsArchive.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsArchive::vmsArchive()
{
	m_pAC = NULL;
	m_errExtract = AEE_NO_ERROR;
}

vmsArchive::~vmsArchive()
{

}

void vmsArchive::set_ArchiveCallback(vmsArchiveCallback *pAC)
{
	m_pAC = pAC;
}

vmsArchiveExtractError vmsArchive::get_LastExtractError()
{
	return m_errExtract;
}
