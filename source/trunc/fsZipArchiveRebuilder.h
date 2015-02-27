/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSZIPARCHIVEREBUILDER_H__223E1FEF_5709_4CAD_A80F_FE09EFF660B4__INCLUDED_)
#define AFX_FSZIPARCHIVEREBUILDER_H__223E1FEF_5709_4CAD_A80F_FE09EFF660B4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "fsArchiveRebuilder.h"
#include <fsString.h>

namespace fsArchive
{

	
const UINT32 ZIP_LOCALFILEHEADER_SIG	= 0x04034b50;
const UINT32 ZIP_FILEHEADER_SIG			= 0x02014b50;
const UINT32 ZIP_ENDOFCENTRALDIR_SIG	= 0x06054b50;
const UINT32 ZIP_SPLIT_SIG				= 0x08074b50;
const UINT32 ZIP_TEMPSPANNINGMARKER_SIG	= 0x30304b50;

const UINT32 ZIP_SFXMAXSIZE				= 150*1024;	
const UINT32 ZIP_BEGIN_SIG				= ZIP_LOCALFILEHEADER_SIG;

#pragma pack (push)
#pragma pack (1)

struct fsZipLocalFileHeader
{
	WORD	wExtractVersion;
	WORD	wGenFlags;
	WORD	wCompMethod;
	WORD	wLastModTime;
	WORD	wLastModDate;
	UINT32	uCRC;
	UINT32	uSizeComp;
	UINT32	uSizeUncomp;
	WORD	wFileNameLen;
	WORD	wExtraLen;
};

struct fsZipDataDescriptor
{
	UINT32	uCRC;
	UINT32	uSizeComp;
	UINT32	uSizeUncomp;
};

struct fsZipFileHeader
{
	WORD	wVerMadeBy;
	WORD	wExtractVer;
	WORD	wGenFlags;
	WORD	wCompMethod;
	WORD	wLastModTime;
	WORD	wLastModDate;
	UINT32	uCRC;
	UINT32	uSizeComp;
	UINT32	uSizeUncomp;
	WORD	wFileNameLen;
	WORD	wExtraLen;
	WORD	wFileCommentLen;
	WORD	wDiskNumberStart;
	WORD	wIntFileAttribs;
	UINT32	uExtFileAttribs;
	UINT32	uLocHdrRelOffset;
};

struct fsZipEndOfCentralDirHdr
{
	WORD	wDiskNumber;
	WORD	wDiskNumberWithCDirStart;
	WORD	wcCDirEntries;
	WORD	wcFilesTotal;
	UINT32	uCDirSize;
	UINT32	uStartCDirOffsetWithRespectToStartingDiskNumber;
	WORD	wZipCommentLen;
};

enum fsZipArchiveRebuilderResult
{
	ZARR_NONSEEKABLEZIP		= ARR_APPRES
};

struct fsZipLocalFile
{
	fsZipLocalFileHeader hdr;
	fsString strFileName;
	LPBYTE pbExtraInfo;
	fsZipDataDescriptor descriptor;
	UINT32 sigAfter;
	fsArchiveFilePosition position;

	fsZipLocalFile () {}

	fsZipLocalFile (fsZipLocalFile& file)
	{
		operator= (file);
	}

	fsZipLocalFile& operator= (fsZipLocalFile& file)
	{
		hdr = file.hdr;
		strFileName = file.strFileName;
		pbExtraInfo = file.pbExtraInfo;
		descriptor = file.descriptor;
		sigAfter = file.sigAfter;
		position = file.position;
		return *this;
	}
};

struct fsZipFile 
{
	fsZipFileHeader hdr;
	fsString strFileName;
	LPBYTE pbExtraInfo;
	fsString strComment;

	fsZipFile () {}

	fsZipFile (fsZipFile& file)
	{
		operator= (file);
	}

	fsZipFile& operator= (fsZipFile& file)
	{
		hdr = file.hdr;
		strFileName = file.strFileName;
		pbExtraInfo = file.pbExtraInfo;
		strComment = file.strComment;
		return *this;
	}
};

#include "list.h"

class fsZipArchiveRebuilder : public fsArchiveRebuilder  
{
public:
	
	const fsArchiveFilePosition* GetFilePosition (int iFile);
	virtual fsString GetFileName (int iFile);
	virtual int GetFileCount();
	virtual BOOL RebuildArchive (fs::list <fsString> vFileNames);
	fsZipArchiveRebuilder();
	virtual ~fsZipArchiveRebuilder();

protected:
	
	DWORD SaveEndOfCDirRecord();
	DWORD SaveFilesHeaders();
	DWORD SaveLocalFilesHeaders();
	
	virtual DWORD SaveArchiveHeaders_imp();
	
	int FindFile (LPCSTR pszFile, int iProbIndex = -1);
	
	void Free();
	
	void CorrectCDir();
	
	void RemoveFile (int iIndex);
	
	virtual DWORD RetreiveArchiveContent();
	fs::list <fsZipLocalFile> m_vLocalFiles;
	fs::list <fsZipFile> m_vFiles;
	fsZipEndOfCentralDirHdr m_hdrEndOfCDir;
	fsString m_strZipComment;
};

#pragma pack (pop)

};

#endif 
