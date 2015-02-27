/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "StdAfx.h"
#include "OrbitSupplier.h"
#include "Utils.h"
#include "vmsLogger.h"

COrbitSupplier::COrbitSupplier()
{
}

COrbitSupplier::~COrbitSupplier()
{
}

bool COrbitSupplier::CheckSupplier() const
{
	CRegKey key;
	if (ERROR_SUCCESS == key.Open (HKEY_LOCAL_MACHINE, _T ("SOFTWARE\\Wow6432Node\\Orbit"), KEY_READ) ||
			ERROR_SUCCESS == key.Open (HKEY_LOCAL_MACHINE, _T ("SOFTWARE\\Orbit"), KEY_READ)) {
		return true;
	}

	return false;
}

void COrbitSupplier::Import(informer fnInformer, void* pData, TImportResult& tImportResult) const
{
	try 
	{
		CString sMsg;

		
		OrbitDownloadsArray arrDownloads;
		InitArray(arrDownloads);
		
		retrieveOrbitDownloads(arrDownloads);

		
		tImportResult.nFailure = 0;
		tImportResult.nSuccess = 0;
		tImportResult.nTotal = arrDownloads.GetUpperBound() + 1;
		tImportResult.nUnprocessed = arrDownloads.GetUpperBound() + 1;

		fnInformer(tImportResult.nTotal, tImportResult.nTotal - tImportResult.nUnprocessed, GetSupplierName(), pData);
		
		
		processDldsImportedFromOrbit(arrDownloads, fnInformer, pData, tImportResult);

	} 
	catch (CException* pExc) 
	{
		vmsLogger::WriteLog("COrbitSupplier::Import exception");

		CString sMsg;

		TCHAR szMsg[1024] = {0,};
		if (!pExc->GetErrorMessage(szMsg, 1024)) {
			szMsg[1023] = 0;
			appendDiagnostics(sMsg, szMsg);
		} else {
			sMsg = "Unkown error";
		}
		pExc->Delete();

		throw std::runtime_error((const char*)sMsg);
	}
}

CString COrbitSupplier::GetSupplierName() const
{
	CString sSupplier = LS (L_FILE_IMPORT_OTHER_CLIENTS_ORBIT_DOWNLOADER);
	return sSupplier;
}

void COrbitSupplier::appendDiagnostics(CString&sMsg, const CString& sDiagnostics) const
{
	CString sTmp;
	CString sFmt = LS (L_SYS_DIAGNOSTICS_FMT);
	sTmp.Format((LPCTSTR)sFmt, (LPCTSTR)sDiagnostics);
	sMsg += " ";
	sMsg += sTmp;
}

void COrbitSupplier::appendErrorCode(CString& sMsg, HRESULT hr) const
{
	CString sTmp;
	CString sFmt = LS (L_ERROR_CODE_FMT);
	sTmp.Format((LPCTSTR)sFmt, hr, hr);
	sMsg += " ";
	sMsg += sTmp;
}

void COrbitSupplier::retreivePathToOrbitAppData(CString& sPath) const
{
	CString sMsg;

	
	TCHAR szDownloadListPath[MAX_PATH] = {0,};
	HRESULT hr = SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, szDownloadListPath);

	
	
	
	if (hr == S_FALSE) {
		sMsg = LS (L_CANT_FIND_PATH_TO_ORBIT_APPDATA);
		throw std::runtime_error((const char*)sMsg);
	}

	if ( FAILED(hr) ) {

		DWORD dwErr;
		
		if (!ComErrToSysErrCode(hr, dwErr)) {
			sMsg = LS (L_CANT_DETECT_PATH_TO_ORBIT_APPDATA);
			appendErrorCode(sMsg, hr);
			throw std::runtime_error((const char*)sMsg);
		}

		bool bFailedToRetreive = false; 
		CString sDiagnostics;
		FormatMessageByErrCode(sDiagnostics, dwErr, bFailedToRetreive);

		if (!bFailedToRetreive) {
			appendDiagnostics(sMsg, sDiagnostics);
		} else {
			sMsg = LS (L_CANT_DETECT_PATH_TO_ORBIT_APPDATA);
		}
		throw std::runtime_error((const char*)sMsg);
	}

	sPath = szDownloadListPath;
}

void COrbitSupplier::OpenFile(HANDLE& hFile, const CString& sDldListFilePath, LangPhrase enMsg) const
{
	CString sMsg;
	hFile = CreateFile (sDldListFilePath, GENERIC_READ, FILE_SHARE_READ, NULL,
			OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hFile ==  INVALID_HANDLE_VALUE) {

		DWORD dwErr = GetLastError();
		sMsg = LS (enMsg);
		bool bFailedToRetreive = false; 

		CString sDiagnostics;
		FormatMessageByErrCode(sDiagnostics, dwErr, bFailedToRetreive);

		if (!bFailedToRetreive) {
			appendDiagnostics(sMsg, sDiagnostics);
		}

		throw std::runtime_error((const char*)sMsg);
	}
}

void COrbitSupplier::ReadFile(HANDLE& hFile, BYTE* bBuffer, DWORD& dwBytesRead, LangPhrase enMsg) const
{
	CString sMsg;

	if (!::ReadFile(hFile, (LPVOID)bBuffer, 1024, &dwBytesRead, NULL)) {

		DWORD dwErr = GetLastError();
		sMsg = LS (enMsg);

		if (!CloseHandle(hFile)) {
			throw std::runtime_error((const char*)sMsg);
		}

		bool bFailedToRetreive = false; 

		CString sDiagnostics;
		FormatMessageByErrCode(sDiagnostics, dwErr, bFailedToRetreive);

		if (!bFailedToRetreive) {
			appendDiagnostics(sMsg, sDiagnostics);
		}

		throw std::runtime_error((const char*)sMsg);
	}
}

void COrbitSupplier::ReadOrbitDldList(const CString& sDldListFilePath, CString& sDldList) const
{
	CString sMsg;

	HANDLE hDldList = 0;
	OpenFile(hDldList, sDldListFilePath, L_CANT_READ_ORBIT_DOWNLOAD_LIST);

	BYTE bBuffer[1024] = {0,};
	DWORD dwBytesRead = 1024;
	std::auto_ptr<BYTE> pDldListBufferGuard;
	DWORD dwTotalBytesRead = 0;

	while (dwBytesRead == 1024) {
		ReadFile(hDldList, bBuffer, dwBytesRead, L_CANT_READ_ORBIT_DOWNLOAD_LIST);

		std::auto_ptr<BYTE> pTmpBufferGuard (new BYTE[dwTotalBytesRead + dwBytesRead + 1]);
		BYTE* pTmpBuffer = pTmpBufferGuard.get();
		if (pTmpBuffer == 0) {
			sMsg = LS (L_OUTOFMEMORY);
			CloseHandle(hDldList);
			throw std::runtime_error((const char*)sMsg);
		}

		memset(pTmpBuffer, 0, dwTotalBytesRead + dwBytesRead + 1);
		memcpy(pTmpBuffer, pDldListBufferGuard.get(), dwTotalBytesRead);
		memcpy((void*)(pTmpBuffer + (int)dwTotalBytesRead), bBuffer, dwBytesRead);
		pDldListBufferGuard = pTmpBufferGuard;
		dwTotalBytesRead += dwBytesRead;
	}

	BYTE* pDldListBuffer = pDldListBufferGuard.get();
	sDldList = (const char*)pDldListBuffer;
}

bool COrbitSupplier::retrieveDownloadFilePath(const TOrbitDownload& tOrbitDownload, CString& sDownloadFilePath) const
{
	
	sDownloadFilePath = tOrbitDownload.sPath;
	sDownloadFilePath.Replace("/", "\\");
	if (sDownloadFilePath.IsEmpty()) {
		
		return false;
	}

	if (sDownloadFilePath.Right(1) != "\\") {
		sDownloadFilePath += "\\";
	}

	CString sDownloadFileName = tOrbitDownload.sFile;
	if (!tOrbitDownload.bIsComplete) {
		sDownloadFileName += ".ob!"; 
	}

	if (sDownloadFileName.IsEmpty()) {
		
		return false;
	}

	sDownloadFilePath += sDownloadFileName;
	if (GetFileAttributes(sDownloadFilePath) == (DWORD)(-1)) {
		
		return false;
	}

	return true;
}

void COrbitSupplier::configureDownloadFileName(const CString& sDownloadFilePath, vmsDownloadSmartPtr dld) const
{
	CString sMsg;

	
	std::auto_ptr<CHAR> pFileNameGuard ( new CHAR[sDownloadFilePath.GetLength() + 1] );
	CHAR* pszFileName = pFileNameGuard.get();
	if (!pszFileName) {
		sMsg = LS (L_OUTOFMEMORY);
		throw std::runtime_error((const char*)sMsg);
	}
	memset(pszFileName, 0, sDownloadFilePath.GetLength() + 1);
	strncpy(pszFileName, (LPCTSTR)sDownloadFilePath, sDownloadFilePath.GetLength());

	delete [] dld->pMgr->GetDownloadMgr ()->GetDP ()->pszFileName;
	dld->pMgr->GetDownloadMgr ()->GetDP ()->pszFileName = pFileNameGuard.release();
}

void COrbitSupplier::configureIncompleteFileExt(vmsDownloadSmartPtr dld) const
{
	CString sMsg;

	
	std::auto_ptr<CHAR> pExtGuard ( new CHAR[8] );
	CHAR* pszExt = pExtGuard.get();
	if (!pszExt) {
		sMsg = LS (L_OUTOFMEMORY);
		throw std::runtime_error((const char*)sMsg);
	}
	memset(pszExt, 0, 8);
	strncpy(pszExt, _T("ob!"), 3);

	delete [] dld->pMgr->GetDownloadMgr ()->GetDP ()->pszAdditionalExt;
	dld->pMgr->GetDownloadMgr ()->GetDP ()->pszAdditionalExt = pExtGuard.release();
	
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
}

void COrbitSupplier::processDldImportedFromOrbit(const TOrbitDownload& tOrbitDownload, TImportResult& tImportResult) const
{
	CImportResultGuard resultGuard(tImportResult);

	
	CString sDownloadFilePath;
	if (!retrieveDownloadFilePath(tOrbitDownload, sDownloadFilePath)) {
		return;
	}

	if (tOrbitDownload.sUrl.IsEmpty()) {
		return;
	}

	vmsDownloadSmartPtr dld;
	Download_CreateInstance (dld);

	if (FALSE == _pwndDownloads->CreateDownloadWithDefSettings (dld, tOrbitDownload.sUrl)) {
		return;
	}

	
	configureDownloadFileName(sDownloadFilePath, dld);

	if (!tOrbitDownload.bIsComplete) {

		
		ATLASSERT(false);

		
		

		
		
		
		
		
		
		

		
		

		
		
		
		
		
	} else {
		
		HANDLE hFile = CreateFile ((LPCTSTR)sDownloadFilePath, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
		DWORD dwSize = GetFileSize(hFile, NULL);
		CloseHandle(hFile);

		dld->pMgr->GetDownloadMgr ()->CreateCompleteDownload((UINT64)dwSize);

	}

	DLDS_LIST v;
	v.push_back (dld);
	_pwndDownloads->CreateDownloads (v, NULL);

	resultGuard.Success(true);

}

void COrbitSupplier::processDldsImportedFromOrbit(OrbitDownloadsArray& arrDownloads, informer fnInformer, void* pData, TImportResult& tImportResult) const
{
	int i = 0;
	for (i = 0; i <= arrDownloads.GetUpperBound(); i++) {
		TOrbitDownload& tOrbitDownload = arrDownloads[i];
		processDldImportedFromOrbit(tOrbitDownload, tImportResult);
		fnInformer(tImportResult.nTotal, tImportResult.nTotal - tImportResult.nUnprocessed, GetSupplierName(), pData);
	}

}

void COrbitSupplier::retrieveOrbitDownloadList(CString& sDldList) const
{
	CString sMsg;

	
	CString sPath;
	retreivePathToOrbitAppData(sPath);

	ASSERT(sPath.GetLength() > 0);

	sPath.Replace("/", "\\"); 
	if (sPath.Right(1) != "\\") {
		sPath += "\\";
	}

	CString sDldListFilePath = sPath;
	sDldListFilePath += "Orbit\\DownloadList.dat";

	
	if (GetFileAttributes(sDldListFilePath) == (DWORD)(-1)) {
		sMsg = LS (L_CANT_FIND_ORBIT_DOWNLOAD_LIST);
		throw std::runtime_error((const char*)sMsg);
	}

	
	ReadOrbitDldList(sDldListFilePath, sDldList);
}

void COrbitSupplier::retrieveOrbitDownloads(OrbitDownloadsArray& arrDownloads) const
{
	CString sDldList;
	
	
	retrieveOrbitDownloadList(sDldList);

	
	parseOrbitDownloadsList(sDldList, arrDownloads);
}

void COrbitSupplier::ReadOrbitDldFile(const CString& sDownloadFilePath, vmsDownloadSmartPtr dld) const
{
	CString sMsg;

	HANDLE hDldList = 0;
	OpenFile(hDldList, sDownloadFilePath, L_CANT_READ_ORBIT_DOWNLOAD_LIST);
	LARGE_INTEGER liFileSize;
	GetFileSizeEx(hDldList, &liFileSize);
	SetFilePointer(hDldList, 0, NULL, FILE_BEGIN);

	BYTE bBuffer[1024] = {0,};
	DWORD dwBytesRead = 1024;
	DWORD dwTotalBytesRead = 0;

	UINT64 nStartPos = 0;
	UINT64 nCurrentSectionPos = 0;
	UINT64 nCurrentPos = 0;
	int nBytesToRead = 0;
	UINT64 nCurrentSectionSize = 1;
	UINT64 nSectionBytesLeft = 0;
	UINT64 nMinSectionSize = 300 * 1024;
	UINT64 nCompleteSize = 0;

	bool bIsFirst = true;
	bool bBeginWithZeroByte = false;
	bool bIsSectionClose = false;
	
	while (dwBytesRead == 1024) {
		ReadFile(hDldList, bBuffer, dwBytesRead, L_CANT_READ_ORBIT_DOWNLOAD_LIST);

		
		if (bIsFirst && dwBytesRead == 0) {
			dld->pMgr->GetDownloadMgr ()->CreateCompleteDownload(0);
			break;
		}

		if (dwBytesRead == 0)
			break;

		if (bIsFirst && dwBytesRead > 0) {
			bIsFirst = false;
			if (bBuffer[0] == 0) {
				 bBeginWithZeroByte = true;
			}
		}

		int i = 0;
		while (i <= dwBytesRead - 1) {

			if (nSectionBytesLeft > 0) {
				if (nSectionBytesLeft <= dwBytesRead - i) {
					i += nSectionBytesLeft;
					nCurrentPos += nSectionBytesLeft;
					nCurrentSectionSize += nSectionBytesLeft;
					nSectionBytesLeft = 0;

					if ((i < dwBytesRead) && bBuffer[i] == 0) {

						++nCurrentPos;
						++i;
						++nCurrentSectionSize;

					} else if (i < dwBytesRead) {

						dld->pMgr->GetDownloadMgr ()->AddSection(nStartPos, nCurrentPos, nCurrentSectionPos);

						
						nCompleteSize += nCurrentSectionPos - nStartPos;

						nStartPos = nCurrentPos;
						nCurrentSectionPos = nCurrentPos;
						bBeginWithZeroByte = false;
						bIsSectionClose = true;
						nCurrentSectionSize = 1;
					}

					continue;

				} else {
					nSectionBytesLeft -= (dwBytesRead - i);
					nCurrentPos += (dwBytesRead - i);
					nCurrentSectionSize += (dwBytesRead - i);
					i = dwBytesRead;
					break;
				}
				bBeginWithZeroByte = false; 
			}

			if (!bBeginWithZeroByte && (nStartPos == nCurrentSectionPos)) {
				if (bBuffer[i] == 0) {
					nCurrentSectionPos = nCurrentPos;
				} else {
					++nCurrentSectionSize;
				}
				bIsSectionClose = false;
			}

			if (bBeginWithZeroByte && (nStartPos == nCurrentSectionPos)) {
				if (bBuffer[i] != 0) {

					if (nCurrentSectionSize < nMinSectionSize) {
						nSectionBytesLeft = nMinSectionSize - (nCurrentPos - nStartPos) - 1; 
						if (liFileSize.QuadPart - 1 < nCurrentPos + nSectionBytesLeft)
							nSectionBytesLeft = liFileSize.QuadPart - nCurrentPos - 1;
						++nCurrentPos;
						++i;
						continue;
					}

					dld->pMgr->GetDownloadMgr ()->AddSection(nStartPos, nCurrentPos, nCurrentSectionPos);

					
					nCompleteSize += nCurrentSectionPos - nStartPos;

					nStartPos = nCurrentPos;
					nCurrentSectionPos = nCurrentPos;
					bBeginWithZeroByte = false;
					bIsSectionClose = true;
					nCurrentSectionSize = 1;
				} else {
					++nCurrentSectionSize;
				}
			}

			if (nStartPos < nCurrentSectionPos) {
				if (bBuffer[i] != 0) {

					if (nCurrentSectionSize < nMinSectionSize) {
						nSectionBytesLeft = nMinSectionSize - (nCurrentPos - nStartPos) - 1;  
						if (liFileSize.QuadPart - 1 < nCurrentPos + nSectionBytesLeft)
							nSectionBytesLeft = liFileSize.QuadPart - nCurrentPos - 1;
						++nCurrentPos;
						++i;
						continue;
					}

					dld->pMgr->GetDownloadMgr ()->AddSection(nStartPos, nCurrentPos, nCurrentSectionPos);

					
					nCompleteSize += nCurrentSectionPos - nStartPos;

					nStartPos = nCurrentPos;
					nCurrentSectionPos = nCurrentPos;
					bIsSectionClose = true;
					nCurrentSectionSize = 1;

				} else {
					++nCurrentSectionSize;
				}
			}
			++nCurrentPos;
			++i;
		}
	}

	if (!bIsSectionClose) {
		dld->pMgr->GetDownloadMgr ()->AddSection(nStartPos, nCurrentPos, nCurrentSectionPos);

		nCompleteSize += nCurrentSectionPos - nStartPos;
		
	}

	CloseHandle(hDldList);
}
