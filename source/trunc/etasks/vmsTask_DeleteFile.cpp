/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsTask_DeleteFile.h"

vmsTask_DeleteFile::vmsTask_DeleteFile()
{

}

vmsTask_DeleteFile::~vmsTask_DeleteFile()
{

}

bool vmsTask_DeleteFile::Do()
{
	return DeleteFile (m_tstrFile.c_str ()) != 0;
}

void vmsTask_DeleteFile::setFile(LPCTSTR ptsz)
{
	m_tstrFile = ptsz;
}
