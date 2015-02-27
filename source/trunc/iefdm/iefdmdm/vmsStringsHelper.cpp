/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsStringsHelper.h"
#include <mlang.h>
#include <comdef.h>

vmsStringsHelper::vmsStringsHelper()
{

}

vmsStringsHelper::~vmsStringsHelper()
{

}

void vmsStringsHelper::BytesToXBstring(UINT64 nBytes, tstring &tstrRes)
{
	LPCTSTR pptszX [] = {_T ("B"), _T ("KB"), _T ("MB"), _T ("GB"), _T ("TB")};
	int i = 0;
	double dBytes = (double)(INT64)nBytes;
	
	while (dBytes >= 1024 && i < (sizeof (pptszX) / sizeof (LPCTSTR) - 1))
	{
		dBytes /= 1024;
		i++;
	}
	
	TCHAR tsz [100] = _T ("");
	_stprintf (tsz, _T ("%.*g%s"), dBytes > 999 ? 4 : 3, (float)dBytes, pptszX[i]);
	tstrRes = tsz;
}

void vmsStringsHelper::SecondsToString(int nSeconds, tstring &tstrRes)
{
	int nHrs = nSeconds / 3600, 
		nMinutes = (nSeconds - nHrs*3600) / 60, 
		nSeconds0 = nSeconds - nHrs*3600 - nMinutes*60;

	TCHAR tsz [100];

	if (nHrs)
		_stprintf (tsz, _T ("%d hr %d min"), nHrs, nMinutes);
	else if (nMinutes)
		_stprintf (tsz, _T ("%d min %d sec"), nMinutes, nSeconds0);
	else
		_stprintf (tsz, _T ("%d sec"), nSeconds0);

	tstrRes = tsz;
}

void vmsStringsHelper::GetFilePathShortDisplayString(LPCTSTR ptszFilePath, int nCharLimit, tstring &tstrRes)
{
	LPCTSTR ptszLast = _tcsrchr (ptszFilePath, '\\');
	if (!ptszLast)
	{
		tstrRes = ptszFilePath;
		return;
	}
	int nLen = nCharLimit - _tcslen (ptszLast) - 3 ;
	
	if (nLen > 0)
		tstrRes.assign (ptszFilePath, nLen);

	tstrRes += _T ("...");
	tstrRes += ptszLast;
}

tstring vmsStringsHelper::FromUtf8(LPCSTR psz)
{
	wchar_t *pwsz = new wchar_t [strlen (psz) + 1];
	
	MultiByteToWideChar (CP_UTF8, 0, psz, -1, pwsz, strlen (psz) + 1);
	
	USES_CONVERSION;
	tstring tstr = W2T (pwsz);
	
	delete [] pwsz;
	
	return tstr;
}

bool vmsStringsHelper::isUtf8String(LPCSTR psz)
{
	if (psz == NULL || *psz == 0)
		return false;

	_COM_SMARTPTR_TYPEDEF(IMultiLanguage2, __uuidof(IMultiLanguage2));
	IMultiLanguage2Ptr spML;

	spML.CreateInstance (CLSID_CMultiLanguage);
	if (spML == NULL)
		return false;

	DetectEncodingInfo enc = {0};
	int iEncLen = 1;
	LPSTR pszBuf = new char [max (strlen (psz), 1024) + 1];
	strcpy (pszBuf, psz);
	while (strlen (pszBuf) < 300)
		strcat (pszBuf, psz);
	int iLen = strlen (pszBuf);
	if (S_OK == spML->DetectInputCodepage (MLDETECTCP_8BIT, 0, pszBuf, &iLen, &enc, &iEncLen) && iEncLen == 1)
	{
		delete [] pszBuf;
		return enc.nCodePage == CP_UTF8;
	}

	delete [] pszBuf;
	return false;
}
