/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fsZipArchiveFastRebuilder.h"
using namespace fsArchive;

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

fsZipArchiveFastRebuilder::fsZipArchiveFastRebuilder()
{

}

fsZipArchiveFastRebuilder::~fsZipArchiveFastRebuilder()
{
	m_vLocalFiles.clear ();
}

DWORD fsZipArchiveFastRebuilder::RetreiveArchiveContent()
{
	if (m_dwFileSize == 0)
		return ARR_STREAMERROR;

	UINT32 uSig;

	
	int iPosReq = m_dwFileSize - sizeof (fsZipEndOfCentralDirHdr) - 4;

	
	if (FALSE == m_in->Seek (iPosReq, ST_BEGIN))
		return ARR_STREAMERROR;

	
	if (m_in->Read (&uSig, sizeof (uSig)) != sizeof (uSig))
		return ARR_STREAMERROR;

	fsZipEndOfCentralDirHdr ecd;

	if (uSig != ZIP_ENDOFCENTRALDIR_SIG)
	{
		

		if (m_dwFileSize < 65536)
		{
			m_in->Seek (0, ST_BEGIN);
			
			
			return fsZipArchiveRebuilder::RetreiveArchiveContent ();
		}

		
		iPosReq = m_dwFileSize - (65536+sizeof (ecd)+4);

		if (FALSE == m_in->Seek (iPosReq, ST_BEGIN))
			return ARR_STREAMERROR;

		BYTE arbBuf [65536+sizeof (ecd)+4];

		if (sizeof (arbBuf) != m_in->Read (arbBuf, sizeof (arbBuf)))
			return ARR_STREAMERROR;
			
		LPBYTE pS = arbBuf, pE = pS + sizeof (arbBuf) - 4 - sizeof (ecd);
		
		while (pS < pE)
		{
			if (*(LPUINT (pS)) == ZIP_ENDOFCENTRALDIR_SIG)
				break; 

			pS++;
		}

		if (pS == pE)
		{
			m_in->Seek (0, ST_BEGIN);
			return fsZipArchiveRebuilder::RetreiveArchiveContent ();
		}

		pS += 4;
		CopyMemory (&ecd, pS, sizeof (ecd));
		pS += sizeof (ecd);

		m_strZipComment.alloc (ecd.wZipCommentLen);
		CopyMemory (m_strZipComment, pS, ecd.wZipCommentLen);
	}
	else
	{
		if (m_in->Read (&ecd, sizeof (ecd)) != sizeof (ecd))
			return ARR_STREAMERROR;

		m_strZipComment.alloc (ecd.wZipCommentLen);
		if (m_in->Read (m_strZipComment, ecd.wZipCommentLen) != ecd.wZipCommentLen)
			return m_in->GetLastError () != ASE_NOMOREDATA ? ARR_STREAMERROR : ARR_BADARCHIVE;;
	}

	m_hdrEndOfCDir = ecd;

	
	if (FALSE == m_in->Seek (ecd.uStartCDirOffsetWithRespectToStartingDiskNumber, ST_BEGIN))
		return ARR_STREAMERROR;

	

	for (int i = 0; i < ecd.wcCDirEntries; i++)
	{
		

		if (m_in->Read (&uSig, sizeof (uSig)) != sizeof (uSig))
			return m_in->GetLastError () != ASE_NOMOREDATA ? ARR_STREAMERROR : ARR_BADARCHIVE;;

		if (uSig != ZIP_FILEHEADER_SIG)
			return ARR_BADARCHIVE;

		fsZipFileHeader hdr;

		if (m_in->Read (&hdr, sizeof (hdr)) != sizeof (hdr))
			return m_in->GetLastError () != ASE_NOMOREDATA ? ARR_STREAMERROR : ARR_BADARCHIVE;;

		fsString strFileName;
		strFileName.alloc (hdr.wFileNameLen);

		if (m_in->Read (strFileName, hdr.wFileNameLen) != hdr.wFileNameLen)
			return m_in->GetLastError () != ASE_NOMOREDATA ? ARR_STREAMERROR : ARR_BADARCHIVE;;

		BYTE *pbExtra = NULL;
		
		if (hdr.wExtraLen)
		{
			pbExtra = new BYTE [hdr.wExtraLen];

			if (m_in->Read (pbExtra, hdr.wExtraLen) != hdr.wExtraLen)
				return m_in->GetLastError () != ASE_NOMOREDATA ? ARR_STREAMERROR : ARR_BADARCHIVE;;
		}

		fsString strComment;
		strComment.alloc (hdr.wFileCommentLen);
		
		if (m_in->Read (strComment, hdr.wFileCommentLen) != hdr.wFileCommentLen)
			return m_in->GetLastError () != ASE_NOMOREDATA ? ARR_STREAMERROR : ARR_BADARCHIVE;

		fsZipFile file;
		file.hdr = hdr;
		file.strComment = strComment;
		file.pbExtraInfo = pbExtra;
		file.strFileName = strFileName;
		m_vFiles.add (file);

		fsZipLocalFile locfile;
		locfile.position.dwSrcBegin = locfile.position.dwDstBegin = hdr.uLocHdrRelOffset;
		m_vLocalFiles.add (locfile);

		if (m_vLocalFiles.size () > 1)
		{
			fsZipLocalFile* prev = &m_vLocalFiles [m_vLocalFiles.size ()-2];
			prev->position.dwDstEnd = prev->position.dwSrcEnd = locfile.position.dwDstBegin;
		}
		
	}

	fsZipLocalFile* lf = &m_vLocalFiles [m_vLocalFiles.size ()-1];
	lf->position.dwSrcEnd = lf->position.dwDstEnd = ecd.uStartCDirOffsetWithRespectToStartingDiskNumber;

	return NOERROR;
}

int fsZipArchiveFastRebuilder::GetFileCount()
{
	return m_vFiles.size ();
}

fsString fsZipArchiveFastRebuilder::GetFileName(int iIndex)
{
	return m_vFiles [iIndex].strFileName;
}

void fsZipArchiveFastRebuilder::RemoveFile(int iIndex)
{
	m_vLocalFiles.del (iIndex);
	m_vFiles.del (iIndex);
}

BOOL fsZipArchiveFastRebuilder::RebuildArchive(fs::list <fsString> vFileNames)
{
	for (int i = 0; i < m_vFiles.size (); i++)
	{
		fsZipFile* file = &m_vFiles [i];

		int iFile = vFileNames.find (file->strFileName);

		if (iFile == -1)
			RemoveFile (i--);
	}

	
	CorrectCDir ();

	return TRUE;
}

void fsZipArchiveFastRebuilder::CorrectCDir()
{
	DWORD dwPos = 0;
	m_hdrEndOfCDir.uCDirSize = 0;

	for (int i = 0; i < m_vFiles.size (); i++)
	{
		fsZipFile* file = &m_vFiles [i];
		fsZipLocalFile* lf = &m_vLocalFiles [i];

		
		lf->position.dwDstBegin = dwPos;
		file->hdr.uLocHdrRelOffset = dwPos;

		
		DWORD dwSize = lf->position.dwSrcEnd - lf->position.dwSrcBegin;
		dwPos += dwSize;
		lf->position.dwDstEnd = dwPos;

		
		m_hdrEndOfCDir.uCDirSize += sizeof (UINT32);	
		m_hdrEndOfCDir.uCDirSize += sizeof (fsZipFileHeader);
		m_hdrEndOfCDir.uCDirSize += file->hdr.wFileNameLen;
		m_hdrEndOfCDir.uCDirSize += file->hdr.wExtraLen;
		m_hdrEndOfCDir.uCDirSize += file->hdr.wFileCommentLen;
	}

	m_hdrEndOfCDir.wcCDirEntries = (WORD) GetFileCount ();
	m_hdrEndOfCDir.wcFilesTotal = (WORD) GetFileCount ();
	m_hdrEndOfCDir.uStartCDirOffsetWithRespectToStartingDiskNumber = dwPos + m_dwSFXSize;

	dwPos += m_hdrEndOfCDir.uCDirSize;
	dwPos += sizeof (UINT32) + sizeof (m_hdrEndOfCDir);

	m_uResArchiveSize = dwPos;
}

DWORD fsZipArchiveFastRebuilder::SaveArchiveHeaders_imp()
{
	DWORD dwRes;

	if (FALSE == m_out->Seek (m_hdrEndOfCDir.uStartCDirOffsetWithRespectToStartingDiskNumber, ST_BEGIN))
		return ARR_STREAMERROR;

	dwRes = SaveFilesHeaders ();
	if (dwRes != NOERROR)
		return dwRes;

	dwRes = SaveEndOfCDirRecord ();
	if (dwRes != NOERROR)
		return dwRes;

	return NOERROR;
}
