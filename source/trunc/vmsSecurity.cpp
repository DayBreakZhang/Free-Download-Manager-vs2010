/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsSecurity.h"
#include <wincrypt.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsSecurity::vmsSecurity()
{

}

vmsSecurity::~vmsSecurity()
{

}

bool vmsSecurity::VerifySign(LPCTSTR ptszFile, LPCTSTR ptszPubKey)
{
	HCRYPTPROV hProv = NULL;
	BOOL bOK = CryptAcquireContext (&hProv, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT);	
	if (!bOK)
		return false;
	
	BYTE abKey [1000];
	DWORD dwKeySize;
	
	HANDLE h = CreateFile (ptszPubKey, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
	if (h == INVALID_HANDLE_VALUE)
		return false;
	ReadFile (h, abKey, sizeof (abKey), &dwKeySize, NULL);
	CloseHandle (h);
	
	HCRYPTKEY hKey;
	if (FALSE == CryptImportKey (hProv, abKey, dwKeySize, NULL, 0, &hKey))
		return false;
	
	LPBYTE pbData;
	DWORD dwDataSize;
	
	h = CreateFile (ptszFile, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
	if (h == INVALID_HANDLE_VALUE)
		return FALSE;
	dwDataSize = GetFileSize (h, NULL);
	if (dwDataSize < strlen (FdmCryptSignatureMarker))
	{
		CloseHandle (h);
		return false;
	}
	pbData = new BYTE [dwDataSize];
	DWORD dw;
	ReadFile (h, pbData, dwDataSize, &dw, NULL);
	CloseHandle (h);
	
	int nSigLen = strlen (FdmCryptSignatureMarker);
	LPBYTE pbSig = pbData + dwDataSize - nSigLen;
	while (pbSig != pbData && strncmp ((char*)pbSig, FdmCryptSignatureMarker, nSigLen) != 0)
		pbSig--;
	if (pbData == pbSig)
	{
		delete [] pbData;
		return false;
	}
	
	HCRYPTHASH hHash;
	if (FALSE == CryptCreateHash (hProv, CALG_MD5, 0, 0, &hHash))
		return false;
	
	if (FALSE == CryptHashData (hHash, pbData, pbSig - pbData, 0))
		return false;
	
	BOOL bResult = CryptVerifySignature (hHash, pbSig + nSigLen,
		pbData + dwDataSize - pbSig - nSigLen, hKey, NULL, 0);
		
	CryptDestroyHash (hHash);
	
	delete [] pbData;
	
	CryptDestroyKey (hKey);
	
	CryptReleaseContext (hProv, 0);
	
	return bResult != FALSE;
}

bool vmsSecurity::ExtractFileFromSignedFile(LPCTSTR ptszSrcFile, LPCTSTR ptszDstFile)
{
	HANDLE h = CreateFile (ptszSrcFile, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
	if (h == INVALID_HANDLE_VALUE)
		return false;
	DWORD dwFileSize = GetFileSize (h, NULL);
	DWORD dwDataSize = dwFileSize > 5000 ? 5000 : dwFileSize;
	if (dwDataSize < strlen (FdmCryptSignatureMarker))
	{
		CloseHandle (h);
		return false;
	}
	LPBYTE pbData = new BYTE [dwDataSize];
	DWORD dw;
	SetFilePointer (h, dwFileSize - dwDataSize, NULL, FILE_BEGIN);
	ReadFile (h, pbData, dwDataSize, &dw, NULL);
	CloseHandle (h);
	
	int nSigLen = strlen (FdmCryptSignatureMarker);
	LPBYTE pbSig = pbData + dwDataSize - nSigLen;
	while (pbSig != pbData && strncmp ((char*)pbSig, FdmCryptSignatureMarker, nSigLen) != 0)
		pbSig--;
	delete [] pbData;
	if (pbData == pbSig)
		return false;

	UINT nSignatureSize = dwDataSize - (pbSig - pbData);

	if (FALSE == CopyFile (ptszSrcFile, ptszDstFile, FALSE))
		return false;

	h = CreateFile (ptszDstFile, GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
	if (h == INVALID_HANDLE_VALUE)
		return false;

	SetFilePointer (h, -(int)nSignatureSize, NULL, FILE_END);
	SetEndOfFile (h);

	CloseHandle (h);

	return true;
}
