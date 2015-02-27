/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsHttpHelper.h"

vmsHttpHelper::vmsHttpHelper()
{

}

vmsHttpHelper::~vmsHttpHelper()
{

}

void vmsHttpHelper::ExtractUrlValues(LPCSTR pszUrl, vector <string> *pvValNames, vector <string> *pvValues)
{
	if (pvValNames)
		pvValNames->clear ();
	if (pvValues)
		pvValues->clear ();

	LPCSTR psz = strstr (pszUrl, "://");
	if (!psz)
		return;

	psz = strchr (psz+3, '/');
	if (!psz)
		return;

	psz = strchr (psz+1, '?');
	if (!psz)
		return;

	psz++;

	ExtractUrlEncodedValues (psz, pvValNames, pvValues);
}

void vmsHttpHelper::ExtractUrlEncodedValues(LPCSTR pszValues, vector <string> *pvValNames, vector <string> *pvValues)
{
	if (pvValNames)
		pvValNames->clear ();
	if (pvValues)
		pvValues->clear ();
	
	LPCSTR psz = pszValues;
	if (!psz)
		return;
	
	while (*psz)
	{
		string strValName;
		string strValue;
		
		while (*psz && *psz != '=')
			strValName += *psz++;
		if (*psz++ == 0)
		{
			if (pvValNames)
				pvValNames->push_back ("");
			if (pvValues && !strValName.empty ())
				pvValues->push_back (strValName);
			return;
		}
		
		while (*psz && *psz != '&')
			strValue += *psz++;
		
		if (*psz)
			psz++;
		
		if (!strValName.empty ())
		{
			if (pvValNames)
				pvValNames->push_back (strValName);
			if (pvValues)
				pvValues->push_back (strValue);
		}
	}
}

string vmsHttpHelper::ExtractFileName(LPCSTR pszUrl)
{
	string strPath = ExtractFilePath (pszUrl);
	LPCSTR psz = strrchr (strPath.c_str (), '/');
	assert (psz != NULL);
	if (!psz)
		return "";
	return psz+1;
}

string vmsHttpHelper::ExtractPathWithoutFileName(LPCSTR pszUrl)
{
	string strPath = ExtractFilePath (pszUrl);
	LPSTR psz = (LPSTR)strrchr (strPath.c_str (), '/');
	assert (psz != NULL);
	if (!psz)
		return "";
	strPath [psz-strPath.c_str ()] = 0;	
	return strPath;
}

string vmsHttpHelper::ExtractFilePath(LPCSTR pszUrl)
{
	pszUrl = strstr (pszUrl, "://");
	if (!pszUrl)
	{
		assert (false);
		return "";
	}

	pszUrl += 3;
	pszUrl = strchr (pszUrl, '/');

	assert (pszUrl != NULL);
	if (!pszUrl)
		return "";

	LPCSTR psz1 = strchr (pszUrl, '?');
	LPCSTR psz2 = strchr (pszUrl, '#');

	LPCSTR pszEnd = pszUrl + strlen (pszUrl);
	if (psz1)
		pszEnd = psz1;
	if (psz2 && pszEnd > psz2)
		pszEnd = psz2;

	string strPath;
	strPath.assign (pszUrl, pszEnd-pszUrl);
	return strPath;
}

void vmsHttpHelper::DecodeUrl(LPCSTR pszUrl, string &strRes)
{
	strRes = "";

	assert (pszUrl != NULL);
	if (pszUrl == NULL)
		return;

	while (*pszUrl)
	{
		if (*pszUrl != '%')
		{
			strRes += *pszUrl++;
		}
		else
		{
			char sz [3];
			sz [0] = *++pszUrl;
			assert (sz [0] != 0);
			if (sz [0] == 0)
				return;
			sz [1] = *++pszUrl;
			pszUrl++;
			assert (sz [1] != 0);
			if (sz [1] == 0)
				return;
			sz [2] = 0;
			int i = 0;
			sscanf (sz, "%x", &i);
			if (i == 0)
				return;
			strRes += (char)i;
		}
	}
}

UINT64 vmsHttpHelper::DeChunk(LPBYTE pbDataBuf, UINT64 uSize)
{
	LOGFN ("vmsHttpHelper::DeChunk");

	assert (pbDataBuf != NULL && uSize != 0);

	int iChunkSize;
	UINT64 uNewSize = 0;
	LPBYTE pbCurPos = pbDataBuf;

	do 
	{
		iChunkSize = 0;

		char szNumber [30];
		UINT uTmpBufLen = min (uSize, sizeof (szNumber) - 1);
		CopyMemory (szNumber, pbCurPos, uTmpBufLen);
		szNumber [uTmpBufLen] = 0;
		sscanf (szNumber, "%x", &iChunkSize);

		if (iChunkSize < 0)
			return false;
		if (iChunkSize == 0)
			return uNewSize;

		while (uSize > 0 && *pbCurPos != '\r' && *pbCurPos != '\n')
		{
			pbCurPos++;
			uSize--;
		}

		if (uSize < 2 || (*pbCurPos != '\r' && pbCurPos [1] != '\n'))
			return 0; 
		pbCurPos += 2;
		uSize -= 2;

		if (uSize < iChunkSize)
			return 0; 

		CopyMemory (pbDataBuf, pbCurPos, iChunkSize);
		pbDataBuf += iChunkSize;
		uNewSize += iChunkSize;
		pbCurPos += iChunkSize;
		uSize -= iChunkSize;

		if (uSize < 2 || (*pbCurPos != '\r' && pbCurPos [1] != '\n'))
			return 0; 
		pbCurPos += 2;
		uSize -= 2;

		if (uSize == 0)
			return 0; 
	} 
	while (true);
}

bool vmsHttpHelper::ChunkedTE_hasLastChunk(const BYTE* pbDataBuf, UINT64 uSize)
{
	LOGFN ("vmsHttpHelper::ChunkedTE_hasLastChunk");
	
	assert (pbDataBuf != NULL && uSize != 0);
	if (!pbDataBuf || !uSize)
		return false;
	
	int iChunkSize;
	UINT64 uNewSize = 0;
	const BYTE *pbCurPos = pbDataBuf;
	
	do 
	{
		iChunkSize = 0;

		char szNumber [30];
		UINT uTmpBufLen = min (uSize, sizeof (szNumber) - 1);
		CopyMemory (szNumber, pbCurPos, uTmpBufLen);
		szNumber [uTmpBufLen] = 0;
		sscanf (szNumber, "%x", &iChunkSize);

		if (iChunkSize < 0)
			return false;
		if (iChunkSize == 0)
			return true;
		
		while (uSize > 0 && *pbCurPos != '\r' && *pbCurPos != '\n')
		{
			pbCurPos++;
			uSize--;
		}
		
		if (uSize < 2 || (*pbCurPos != '\r' && pbCurPos [1] != '\n'))
			return false; 
		pbCurPos += 2;
		uSize -= 2;
		
		if (uSize < iChunkSize)
			return false; 
		
		pbDataBuf += iChunkSize;
		uNewSize += iChunkSize;
		pbCurPos += iChunkSize;
		uSize -= iChunkSize;
		
		if (uSize < 2 || (*pbCurPos != '\r' && pbCurPos [1] != '\n'))
			return 0; 
		pbCurPos += 2;
		uSize -= 2;
		
		if (uSize == 0)
			return false; 
	} 
	while (true);
}

void vmsHttpHelper::ExtractFileUrl(LPCSTR pszUrl, string &strRes)
{
	LPCSTR psz = strchr (pszUrl, '?');
	if (psz)
		strRes.assign (pszUrl, psz - pszUrl);
	else
		strRes = pszUrl;
}

