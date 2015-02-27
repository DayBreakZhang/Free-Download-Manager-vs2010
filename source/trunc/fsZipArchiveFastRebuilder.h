/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSZIPARCHIVEFASTREBUILDER_H__93697060_3D86_4D64_896A_B16DEEDF296B__INCLUDED_)
#define AFX_FSZIPARCHIVEFASTREBUILDER_H__93697060_3D86_4D64_896A_B16DEEDF296B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "fsZipArchiveRebuilder.h"

namespace fsArchive 
{

class fsZipArchiveFastRebuilder : public fsZipArchiveRebuilder  
{
public:
	
	virtual BOOL RebuildArchive(fs::list <fsString> vFileNames);
	virtual fsString GetFileName (int iIndex);
	virtual int GetFileCount();
	fsZipArchiveFastRebuilder();
	virtual ~fsZipArchiveFastRebuilder();

protected:
	virtual DWORD SaveArchiveHeaders_imp();
	void CorrectCDir();
	void RemoveFile (int iIndex);
	virtual DWORD RetreiveArchiveContent();
};

};

#endif 
