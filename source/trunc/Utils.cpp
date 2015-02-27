/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "StdAfx.h"
#include "Utils.h"
#include "MemHandleGuard.h"

bool ComErrToSysErrCode(HRESULT hr, DWORD& dwErr)
{
	if ((hr & 0xFFFF0000) == MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIN32, 0)) {
		
		dwErr = HRESULT_CODE(hr);
		return true;
	}

	if (hr == S_OK) {
		dwErr = HRESULT_CODE(hr);
		return true;
	}

	
	return false;

}

void FormatMessageByErrCode(CString& sMsg, DWORD dwErr, bool& bFailedToRetreive)
{
	LPVOID lpMsgBuf = 0;
	DWORD dwFlag = FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | 
			FORMAT_MESSAGE_IGNORE_INSERTS;

	CMemHandleGuard mhgMemGuard(lpMsgBuf, bFailedToRetreive);

	if(::FormatMessage(dwFlag, NULL, dwErr, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), 
			(LPTSTR) &lpMsgBuf, 0, NULL) == 0) {
	
			bFailedToRetreive = true;
			return;
	}

	sMsg = (LPCTSTR)lpMsgBuf;
}

void appendDiagnostics(CString&sMsg, const CString& sDiagnostics)
{
	CString sTmp;
	CString sFmt = LS (L_SYS_DIAGNOSTICS_FMT);
	sTmp.Format((LPCTSTR)sFmt, (LPCTSTR)sDiagnostics);
	sMsg += " ";
	sMsg += sTmp;
}

void putStrToBuffer(LPCTSTR tszStr, LPBYTE& pbtCurrentPos, LPBYTE pbtBuffer, DWORD dwBufferSizeSize, DWORD* pdwSizeReuiqred)
{

	int nLen = -1;
	int nBufferSize = 0;
	if (tszStr) {
		nLen = _tcslen(tszStr);
		nBufferSize = sizeof(TCHAR) * nLen;
	}

	if (pbtBuffer == NULL) {
		if (pdwSizeReuiqred) {
			*pdwSizeReuiqred += sizeof(nLen) + nBufferSize;
		}
		return;
	}

	CHECK_BUFFER_BOUNDS(dwBufferSizeSize, sizeof(nLen));
	CopyMemory(pbtCurrentPos, &nLen, sizeof(nLen));
	pbtCurrentPos += sizeof(nLen);

	if (tszStr) {
		CHECK_BUFFER_BOUNDS(dwBufferSizeSize, nBufferSize);
		CopyMemory(pbtCurrentPos, tszStr, nBufferSize);
		pbtCurrentPos += nBufferSize;
	}
}

bool getStrFromBuffer(LPTSTR* ptszStr, LPBYTE& pbtCurrentPos, LPBYTE pbtBuffer, DWORD dwBufferSizeSize)
{
	int nLen = 0;
	BOOLEAN_CHECK_BUFFER_BOUNDS(dwBufferSizeSize, sizeof(nLen));
	CopyMemory(&nLen, pbtCurrentPos, sizeof(nLen));
	pbtCurrentPos += sizeof(nLen);

	if (nLen < -1)
		return false;

	if (nLen == -1) {
		*ptszStr = 0;
		return true;
	}

	if ((UINT)nLen > 100000)
		return false;

	int nBufferSize = sizeof(TCHAR) * (nLen + 1);

	std::auto_ptr<TCHAR> aptszStrGuard( new TCHAR[nLen + 1] );
	LPTSTR tszTmp = aptszStrGuard.get();
	if (tszTmp == 0)
		return false;
	memset(tszTmp, 0, nBufferSize);

	BOOLEAN_CHECK_BUFFER_BOUNDS(dwBufferSizeSize, (sizeof(TCHAR) * nLen));
	CopyMemory(tszTmp, pbtCurrentPos, sizeof(TCHAR) * nLen);
	pbtCurrentPos += sizeof(TCHAR) * nLen;
	*ptszStr = aptszStrGuard.release();

	return true;
}
