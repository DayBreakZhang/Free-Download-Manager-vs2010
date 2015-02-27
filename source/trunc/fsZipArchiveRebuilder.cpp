/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fsZipArchiveRebuilder.h"
#include <fsString.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

using namespace fsArchive;

fsZipArchiveRebuilder::fsZipArchiveRebuilder()
{

}

fsZipArchiveRebuilder::~fsZipArchiveRebuilder()
{
	Free ();
}

DWORD fsZipArchiveRebuilder::RetreiveArchiveContent()
{
	UINT32 uSig = 0;
	fsArchiveFilePosition position;
	DWORD dwPos = 0;	
	BOOL bSkipSigRead = FALSE;

	do
	{
		position.dwSrcBegin = dwPos;
		position.dwDstBegin = dwPos;

		if (bSkipSigRead == FALSE)
		{
			if (m_in->Read (&uSig, sizeof (uSig)) != sizeof (uSig))
				return m_in->GetLastError () != ASE_NOMOREDATA ? ARR_STREAMERROR : ARR_BADARCHIVE;

			dwPos += sizeof (uSig);
		}
		else
		{
			position.dwSrcBegin -= sizeof (uSig);
			position.dwDstBegin -= sizeof (uSig);

			bSkipSigRead = FALSE;
		}

		if (uSig != ZIP_LOCALFILEHEADER_SIG)
			break;

		fsZipLocalFileHeader hdr;

		if (m_in->Read (&hdr, sizeof (hdr)) != sizeof (hdr))
			return m_in->GetLastError () != ASE_NOMOREDATA ? ARR_STREAMERROR : ARR_BADARCHIVE;;

		dwPos += sizeof (hdr);

		fsString strFileName;
		strFileName.alloc (hdr.wFileNameLen);

		if (m_in->Read (strFileName, hdr.wFileNameLen) != hdr.wFileNameLen)
			return m_in->GetLastError () != ASE_NOMOREDATA ? ARR_STREAMERROR : ARR_BADARCHIVE;;

		dwPos += hdr.wFileNameLen;

		BYTE *pbExtra = NULL;
		
		if (hdr.wExtraLen)
		{
			pbExtra = new BYTE [hdr.wExtraLen];

			if (m_in->Read (pbExtra, hdr.wExtraLen) != hdr.wExtraLen)
				return m_in->GetLastError () != ASE_NOMOREDATA ? ARR_STREAMERROR : ARR_BADARCHIVE;;

			dwPos += hdr.wExtraLen;
		}

		fsZipLocalFile file;
		
		file.hdr = hdr;
		file.strFileName = strFileName;
		file.pbExtraInfo = pbExtra;
		file.sigAfter = 0;
		
		if (hdr.uSizeComp == 0)
		{
			
		}
		else
		{
			

			if (-1 == m_in->Seek (hdr.uSizeComp, ST_CURRENT))
				return m_in->GetLastError () != ASE_NOMOREDATA ? ARR_STREAMERROR : ARR_BADARCHIVE;;

			dwPos += hdr.uSizeComp;
		}

		if (m_in->Read (&uSig, sizeof (uSig)) == sizeof (uSig) && 
			 (uSig == ZIP_SPLIT_SIG || uSig == ZIP_TEMPSPANNINGMARKER_SIG))
		{
			
			file.sigAfter = uSig;
		}
		else
			bSkipSigRead = TRUE;

		dwPos += sizeof (uSig);

		
		if (hdr.wGenFlags & 0x8)
		{
			

			fsZipDataDescriptor hdr;

			if (bSkipSigRead == FALSE)
			{
				if (m_in->Read (&hdr, sizeof (hdr)) != sizeof (hdr))
					return m_in->GetLastError () != ASE_NOMOREDATA ? ARR_STREAMERROR : ARR_BADARCHIVE;;

				dwPos += sizeof (hdr);
			}
			else
			{
				if (m_in->Read (LPBYTE (&hdr) + 4, sizeof (hdr) - 4) != sizeof (hdr) - 4)
					return m_in->GetLastError () != ASE_NOMOREDATA ? ARR_STREAMERROR : ARR_BADARCHIVE;;

				dwPos += sizeof (hdr) - 4;

				hdr.uCRC = uSig;
				bSkipSigRead = FALSE;
			}

			file.descriptor = hdr;
		}

		if (bSkipSigRead)
		{
			position.dwSrcEnd = dwPos - sizeof (UINT32);
			position.dwDstEnd = dwPos - sizeof (UINT32);
		}
		else
		{
			position.dwSrcEnd = dwPos;
			position.dwDstEnd = dwPos;
		}
		
		file.position = position;

		m_vLocalFiles.add (file);
	}
	while (TRUE);

	

	do
	{
		if (uSig != ZIP_FILEHEADER_SIG)
			break;

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
			return m_in->GetLastError () != ASE_NOMOREDATA ? ARR_STREAMERROR : ARR_BADARCHIVE;;

		

		fsZipFile file;
		file.hdr = hdr;
		file.strComment = strComment;
		file.pbExtraInfo = pbExtra;
		file.strFileName = strFileName;
		m_vFiles.add (file);

		
		if (m_in->Read (&uSig, sizeof (uSig)) != sizeof (uSig))
			return m_in->GetLastError () != ASE_NOMOREDATA ? ARR_STREAMERROR : ARR_BADARCHIVE;;
	}
	while (TRUE);

	

	if (uSig != ZIP_ENDOFCENTRALDIR_SIG)
		return ARR_BADARCHIVE;

	fsZipEndOfCentralDirHdr hdr;

	if (m_in->Read (&hdr, sizeof (hdr)) != sizeof (hdr))
		return m_in->GetLastError () != ASE_NOMOREDATA ? ARR_STREAMERROR : ARR_BADARCHIVE;;

	m_hdrEndOfCDir = hdr;

	m_strZipComment.alloc (hdr.wZipCommentLen);
	if (m_in->Read (m_strZipComment, hdr.wZipCommentLen) != hdr.wZipCommentLen)
		return m_in->GetLastError () != ASE_NOMOREDATA ? ARR_STREAMERROR : ARR_BADARCHIVE;;
	
	return NOERROR;
}

BOOL fsZipArchiveRebuilder::RebuildArchive(fs::list <fsString> vFileNames)
{
	for (int i = 0; i < m_vLocalFiles.size (); i++)
	{
		fsZipLocalFile* file = &m_vLocalFiles [i];

		int iFile = vFileNames.find (file->strFileName);

		if (iFile == -1)
			RemoveFile (i--);
	}

	CorrectCDir ();

	return TRUE;
}

int fsZipArchiveRebuilder::GetFileCount()
{
	return m_vLocalFiles.size ();
}

fsString fsZipArchiveRebuilder::GetFileName(int iFile)
{
	return m_vLocalFiles [iFile].strFileName;
}

void fsZipArchiveRebuilder::RemoveFile(int iIndex)
{
	LPCSTR pszFile = m_vLocalFiles [iIndex].strFileName;

	int imvFilesIndex = FindFile (pszFile, iIndex);
	if (imvFilesIndex != -1)
		m_vFiles.del (imvFilesIndex);

	m_vLocalFiles.del (iIndex);
}

void fsZipArchiveRebuilder::CorrectCDir()
{
	DWORD dwPos = 0; 

	int i = 0;
	for (i = 0; i < m_vLocalFiles.size (); i++)
	{
		fsZipLocalFile* file = &m_vLocalFiles [i];

		

		int j = FindFile (file->strFileName, i);
		if (j != -1)
			m_vFiles [j].hdr.uLocHdrRelOffset = dwPos + m_dwSFXSize;

		
		file->position.dwDstBegin = dwPos;

		
		dwPos += sizeof (UINT32) + sizeof (fsZipLocalFileHeader) + 
			file->hdr.wFileNameLen + file->hdr.wExtraLen;

		dwPos += file->hdr.uSizeComp;

		if (file->sigAfter)
			dwPos += sizeof (UINT32);

		if (file->hdr.wGenFlags & 0x8)
			dwPos += sizeof (fsZipDataDescriptor);

		
		file->position.dwDstEnd = dwPos;
	}

	

	m_hdrEndOfCDir.wcCDirEntries = (WORD) GetFileCount ();
	m_hdrEndOfCDir.wcFilesTotal = (WORD) GetFileCount ();
	m_hdrEndOfCDir.uStartCDirOffsetWithRespectToStartingDiskNumber = dwPos + m_dwSFXSize;

	m_hdrEndOfCDir.uCDirSize = 0;
	for (i = 0; i < m_vFiles.size (); i++)
	{
		fsZipFile* file = &m_vFiles [i];

		m_hdrEndOfCDir.uCDirSize += sizeof (UINT32);	
		m_hdrEndOfCDir.uCDirSize += sizeof (fsZipFileHeader);
		m_hdrEndOfCDir.uCDirSize += file->hdr.wFileNameLen;
		m_hdrEndOfCDir.uCDirSize += file->hdr.wExtraLen;
		m_hdrEndOfCDir.uCDirSize += file->hdr.wFileCommentLen;
	}

	dwPos += m_hdrEndOfCDir.uCDirSize;
	dwPos += sizeof (UINT32) + sizeof (m_hdrEndOfCDir);

	m_uResArchiveSize = dwPos;
}

void fsZipArchiveRebuilder::Free()
{
	int i = 0;
	for (i = 0; i < m_vLocalFiles.size (); i++)
	{
		if (m_vLocalFiles [i].pbExtraInfo)
			delete [] m_vLocalFiles [i].pbExtraInfo;
	}

	m_vLocalFiles.clear ();

	for (i = 0; i < m_vFiles.size (); i++)
	{
		if (m_vFiles [i].pbExtraInfo)
			delete [] m_vFiles [i].pbExtraInfo;
	}

	m_vFiles.clear ();
}

const fsArchiveFilePosition* fsZipArchiveRebuilder::GetFilePosition(int iFile)
{
	return &m_vLocalFiles [iFile].position;
}

int fsZipArchiveRebuilder::FindFile(LPCSTR pszFile, int iProbIndex)
{
	int imvFilesIndex = -1;
				
	if (iProbIndex != -1 && m_vFiles.size () > iProbIndex && 
			m_vFiles [iProbIndex].strFileName == pszFile)
		imvFilesIndex = iProbIndex;
	else
	{
		for (int j = 0; j < m_vFiles.size (); j++)
		{
			if (m_vFiles [j].strFileName == pszFile)
			{
				imvFilesIndex = j;
				break;
			}
		}
	}

	return imvFilesIndex;
}

DWORD fsZipArchiveRebuilder::SaveArchiveHeaders_imp()
{
	DWORD dwRes;

	dwRes = SaveLocalFilesHeaders ();
	if (dwRes != NOERROR)
		return dwRes;

	dwRes = SaveFilesHeaders ();
	if (dwRes != NOERROR)
		return dwRes;

	dwRes = SaveEndOfCDirRecord ();
	if (dwRes != NOERROR)
		return dwRes;

	return NOERROR;
}

DWORD fsZipArchiveRebuilder::SaveLocalFilesHeaders()
{
	UINT32 uSig = ZIP_LOCALFILEHEADER_SIG;

	for (int i = 0; i < m_vLocalFiles.size (); i++)
	{
		fsZipLocalFile* file = &m_vLocalFiles [i];

		if (m_out->Write (&uSig, sizeof (uSig)) != sizeof (uSig))
			return ARR_STREAMERROR;

		if (m_out->Write (&file->hdr, sizeof (file->hdr)) != sizeof (file->hdr))
			return ARR_STREAMERROR;

		if (m_out->Write (file->strFileName, file->hdr.wFileNameLen) != file->hdr.wFileNameLen)
			return ARR_STREAMERROR;

		if (file->hdr.wExtraLen)
		{
			if (m_out->Write (file->pbExtraInfo, file->hdr.wExtraLen) != file->hdr.wExtraLen)
				return ARR_STREAMERROR;
		}

		if (file->hdr.uSizeComp && -1 == m_out->Seek (file->hdr.uSizeComp, ST_CURRENT))
			return ARR_STREAMERROR;

		if (file->sigAfter)
		{
			if (m_out->Write (&file->sigAfter, sizeof (UINT32)) != sizeof (UINT32)) 
				return ARR_STREAMERROR;
		}

		if (file->hdr.wGenFlags & 0x8)
		{
			if (m_out->Write (&file->descriptor, sizeof (file->descriptor)) != sizeof (file->descriptor))
				return ARR_STREAMERROR;
		}
	}

	return NOERROR;
}

DWORD fsZipArchiveRebuilder::SaveFilesHeaders()
{
	UINT32 uSig = ZIP_FILEHEADER_SIG;

	for (int i = 0; i < m_vFiles.size (); i++)
	{
		fsZipFile* file = &m_vFiles [i];

		if (m_out->Write (&uSig, sizeof (uSig)) != sizeof (uSig))
			return ARR_STREAMERROR;

		if (m_out->Write (&file->hdr, sizeof (file->hdr)) != sizeof (file->hdr))
			return ARR_STREAMERROR;

		if (m_out->Write (file->strFileName, file->hdr.wFileNameLen) != file->hdr.wFileNameLen)
			return ARR_STREAMERROR;
		
		if (file->hdr.wExtraLen)
			if (m_out->Write (file->pbExtraInfo, file->hdr.wExtraLen) != file->hdr.wExtraLen)
				return ARR_STREAMERROR;

		if (file->hdr.wFileCommentLen)
			if (m_out->Write (file->strComment, file->hdr.wFileCommentLen) != file->hdr.wFileCommentLen)
				return ARR_STREAMERROR;
	}

	return NOERROR;
}

DWORD fsZipArchiveRebuilder::SaveEndOfCDirRecord()
{
	UINT32 uSig = ZIP_ENDOFCENTRALDIR_SIG;

	if (m_out->Write (&uSig, sizeof (uSig)) != sizeof (uSig))
		return ARR_STREAMERROR;

	if (m_out->Write (&m_hdrEndOfCDir, sizeof (m_hdrEndOfCDir)) != sizeof (m_hdrEndOfCDir))
		return ARR_STREAMERROR;

	if (m_hdrEndOfCDir.wZipCommentLen)
		if (m_out->Write (m_strZipComment, m_hdrEndOfCDir.wZipCommentLen) != m_hdrEndOfCDir.wZipCommentLen)
			return ARR_STREAMERROR;

	return NOERROR;
}
