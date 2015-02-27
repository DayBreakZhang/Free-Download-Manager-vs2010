/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsTask_CopyFile.h"

vmsTask_CopyFile::vmsTask_CopyFile()
{

}

vmsTask_CopyFile::~vmsTask_CopyFile()
{

}

void vmsTask_CopyFile::setSrcFile(LPCTSTR ptszSrc)
{
	m_tstrSrcFile = ptszSrc;
}

void vmsTask_CopyFile::setDstFile(LPCTSTR ptsz)
{
	m_tstrDstFile = ptsz;
}

bool vmsTask_CopyFile::Do()
{
	extern BOOL vmsBuildPathToFile (LPCTSTR pszFileName);
	if (FALSE == vmsBuildPathToFile (m_tstrDstFile.c_str ()))
		return false;
	return CopyFile (m_tstrSrcFile.c_str (), m_tstrDstFile.c_str (), FALSE) != 0;
}
