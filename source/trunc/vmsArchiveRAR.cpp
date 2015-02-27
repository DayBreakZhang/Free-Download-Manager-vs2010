/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "vmsArchiveRAR.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsArchiveRAR::vmsArchiveRAR()
{

}

vmsArchiveRAR::~vmsArchiveRAR()
{

}

#pragma warning (disable: 4701)

bool vmsArchiveRAR::Extract(LPCSTR pszArchive, LPCSTR pszOutFolder)
{
	m_errExtract = AEE_GENERIC_ERROR;

	if (m_unrar.is_Loaded () == false) {
		if (false == m_unrar.Load ("Archive\\unrar.dll"))
			return false;
	}

	HANDLE hFile = CreateFile (pszArchive, GENERIC_READ, FILE_SHARE_READ, NULL, 
		OPEN_EXISTING, 0, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
		return false;
	DWORD dwPkdSize = GetFileSize (hFile, NULL);
	CloseHandle (hFile);

	HANDLE hArcData;
	int RHCode, PFCode;
	char CmtBuf [16384];
	RARHeaderData HeaderData;
	RAROpenArchiveDataEx OpenArchiveData;

	ZeroMemory (&OpenArchiveData, sizeof (OpenArchiveData));
	OpenArchiveData.ArcName = (LPSTR)pszArchive;
	OpenArchiveData.CmtBuf = CmtBuf;
	OpenArchiveData.CmtBufSize = sizeof (CmtBuf);
	OpenArchiveData.OpenMode = RAR_OM_EXTRACT;
	
	hArcData = m_unrar.RAROpenArchiveEx (&OpenArchiveData);

	if (hArcData == NULL || OpenArchiveData.OpenResult != 0)
		return false;

	
	

	HeaderData.CmtBuf = NULL;
	DWORD dwProcessed = 0;

	CString strOutFolder = pszOutFolder;
	if (strOutFolder [strOutFolder.GetLength () - 1] != '\\')
		strOutFolder += '\\';

	vmsAC_OverwriteMode enOM;
	bool bAskOverwrite = true;

	TIME_ZONE_INFORMATION tzi;
	GetTimeZoneInformation (&tzi);

	while ((RHCode = m_unrar.RARReadHeader (hArcData, &HeaderData)) == 0)
	{
		bool bSkip = false;

		if (m_pAC) {
			if (false == m_pAC->BeforeExtract (HeaderData.FileName)) {
				RHCode = ERAR_END_ARCHIVE;
				break;
			}

			DWORD dwAttr = GetFileAttributes (strOutFolder + HeaderData.FileName);
			if (dwAttr != DWORD (-1) && (dwAttr & FILE_ATTRIBUTE_DIRECTORY) == 0)
			{
				if (bAskOverwrite)
				{
					vmsOverwriteFileInfo ofi;
					bool bForAll = false;

					CString strFile = strOutFolder + HeaderData.FileName;
					ofi.pszFile = strFile;
					UINT64 u = HeaderData.UnpSize;
					FILETIME time;
					DosDateTimeToFileTime (HIWORD (HeaderData.FileTime),
						LOWORD (HeaderData.FileTime), &time);
					*((UINT64*)&time) += Int32x32To64 (tzi.Bias, 60 * 10000000);
					ofi.ptimeNewLastWrite = &time;
					ofi.puNewSize = &u;

					m_pAC->AskOverwrite (ofi, enOM, bForAll);

					if (enOM == AC_OM_CANCEL) {
						m_errExtract = AEE_ABORTED_BY_USER;
						break;
					}

					if (bForAll)
						bAskOverwrite = false;
				}

				if (enOM == AC_OM_SKIP)
					bSkip = true;
			}
		}

		PFCode = m_unrar.RARProcessFile (hArcData, bSkip ? RAR_SKIP : RAR_EXTRACT, 
			(LPSTR)pszOutFolder, NULL);

		if (PFCode == 0) {
			if (m_pAC) {
				m_pAC->AfterExtract (HeaderData.FileName, AC_ER_OK);
				dwProcessed += HeaderData.PackSize;
				m_pAC->SetProgress (MulDiv (dwProcessed, 100, dwPkdSize));
			}
		}
		else
		{
			if (m_pAC)
				m_pAC->AfterExtract (HeaderData.FileName, AC_ER_FAILED);
			break;
		}
	}

	m_unrar.RARCloseArchive (hArcData);

	if (RHCode == ERAR_END_ARCHIVE)
		m_errExtract = AEE_NO_ERROR;

	return RHCode == ERAR_END_ARCHIVE;
}
