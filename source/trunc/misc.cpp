/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "list.h"

#ifndef FDM_DLDR__RAWCODEONLY
#include "DownloadsWnd.h"
#endif

#include "downloadproperties.h"
#include "fsDownloadMgr.h"
#include "system.h"

#ifndef FDM_DLDR__RAWCODEONLY
extern CDownloadsWnd* _pwndDownloads;
#endif

void DrawVerticalFrame (HDC hdc, int xStart, int xEnd, int yStart, int height)
{
	HPEN hLightPen, hHilightPen, hShadowPen, hOldPen;

	hLightPen = CreatePen (PS_SOLID, 1, GetSysColor (COLOR_3DLIGHT));
	hHilightPen = CreatePen (PS_SOLID, 1, GetSysColor (COLOR_3DHILIGHT));
	hShadowPen = CreatePen (PS_SOLID, 1, GetSysColor (COLOR_3DSHADOW));

	int yEnd = yStart + height;

	hOldPen = (HPEN) SelectObject (hdc, hLightPen);
	MoveToEx (hdc, xStart, yStart, NULL);
	LineTo (hdc, xStart, yEnd);

	SelectObject (hdc, hHilightPen);
	MoveToEx (hdc, xStart+1, yStart, NULL);
	LineTo (hdc, xStart+1, yEnd);

	SelectObject (hdc, hShadowPen);
	MoveToEx (hdc, xEnd, yStart, NULL);
	LineTo (hdc, xEnd, yEnd);

	SelectObject (hdc, hOldPen);

	DeleteObject (hLightPen);
	DeleteObject (hHilightPen);
	DeleteObject (hShadowPen);
}

void DrawHorizontalFrame (HDC hdc, int yStart, int yEnd, int xStart, int width)
{
	HPEN hLightPen, hDarkPen, hHilightPen, hShadowPen, hOldPen;

	hLightPen = CreatePen (PS_SOLID, 1, GetSysColor (COLOR_3DLIGHT));
	hDarkPen  = CreatePen (PS_SOLID, 1, GetSysColor (COLOR_3DDKSHADOW));
	hHilightPen = CreatePen (PS_SOLID, 1, GetSysColor (COLOR_3DHILIGHT));
	hShadowPen = CreatePen (PS_SOLID, 1, GetSysColor (COLOR_3DSHADOW));

	int xEnd = xStart + width;

	hOldPen = (HPEN) SelectObject (hdc, hLightPen);
	MoveToEx (hdc, xStart, yStart, NULL);
	LineTo (hdc, xEnd, yStart);

	SelectObject (hdc, hHilightPen);
	MoveToEx (hdc, xStart, yStart+1, NULL);
	LineTo (hdc, xEnd, yStart+1);

	SelectObject (hdc, hShadowPen);
	MoveToEx (hdc, xStart, yEnd, NULL);
	LineTo (hdc, xEnd, yEnd);

	SelectObject (hdc, hOldPen);

	DeleteObject (hLightPen);
	DeleteObject (hDarkPen);
	DeleteObject (hHilightPen);
	DeleteObject (hShadowPen);
}

void BytesToXBytes (UINT64 uBytes, float* pfXBytes, LPSTR pszXVal)
{
	LPCSTR apszX [] = {LS (L_B), LS (L_KB), LS (L_MB), "GB", "TB", "PB"};
	int i = 0;
	double dBytes = (double) (INT64)uBytes;

	while (dBytes > 9999)
	{
		dBytes /= 1024;
		i++;
	}

	if (pszXVal)
	{
		if (i >= _countof (apszX))
			strcpy (pszXVal, "?");
		else
			strcpy (pszXVal, apszX [i]);
	}

	*pfXBytes = (FLOAT) dBytes;
}

#ifndef FDM_DLDR__RAWCODEONLY
CString BytesToString (UINT64 uSize, bool bForceXbytes)
{
	CString str;

	if (bForceXbytes || 
			(_pwndDownloads != NULL && FALSE == _pwndDownloads->IsSizesInBytes ()))
	{
		float val;
		char szDim [10];
		BytesToXBytes (uSize, &val, szDim);
		str.Format ("%.*g %s", val > 999 ? 4 : 3, val, szDim);
	}
	else
		str = fsBytesToStr (uSize);

	return str;
}
#endif

void SystemTimeToStr (SYSTEMTIME *time, LPSTR pszDate, LPSTR pszTime, BOOL bSeconds)
{
	if (pszDate)
		GetDateFormat (LOCALE_USER_DEFAULT, DATE_SHORTDATE, time, NULL, pszDate, 100);
	
	if (pszTime)
	{
		if (bSeconds)
			GetTimeFormat (LOCALE_USER_DEFAULT, 0, time, NULL, pszTime, 100);
		else
			GetTimeFormat (LOCALE_USER_DEFAULT, TIME_NOSECONDS, time, NULL, pszTime, 100);
	}
}

void FileTimeToStr (FILETIME *time, LPSTR pszDate, LPSTR pszTime, BOOL bSeconds)
{
	SYSTEMTIME s;
	FileTimeToSystemTime (time, &s);
	SystemTimeToStr (&s, pszDate, pszTime, bSeconds);
}

BOOL fsErrorToStr (LPSTR pszErr, DWORD dwMaxSize, DWORD* pdwLastError)
{
	LPCSTR pszDesc;
	CString str;
	
	*pszErr = 0;

	switch (pdwLastError ? *pdwLastError : GetLastError ())
	{
		case ERROR_FILE_NOT_FOUND:
			pszDesc = LS (L_FILENOTFOUND);
		break;

		case ERROR_PATH_NOT_FOUND:
			pszDesc = LS (L_PATHNOTFOUND);
			break;

		case ERROR_BAD_FORMAT:
			pszDesc = LS (L_BADEXE);
			break;

		case ERROR_SHARING_VIOLATION:
			pszDesc = LS (L_FILEINUSE);
		break;

		case ERROR_ACCESS_DENIED:
			pszDesc = LS (L_ACCDENIED);
			break;

		case ERROR_NOT_READY:
			pszDesc = LS (L_DEVNOTREADY);
			break;

		case ERROR_DISK_FULL:
			pszDesc = LS (L_DISKFULL);
			break;

		case ERROR_INVALID_NAME:
			pszDesc = LS (L_BADFILENAME);
			break;

		case ERROR_ALREADY_EXISTS:
			pszDesc = LS (L_ALREXISTS);
			break;

		case ERROR_DIRECTORY:
			pszDesc = LS (L_INVALIDDIRNAME);
			break;
		
		default:
			str.Format ("%s - [%d]", LS (L_UNKERR), pdwLastError ? *pdwLastError : GetLastError ());
			pszDesc = str;
	}

	if (strlen (pszDesc) >= dwMaxSize)
		return FALSE;

	strcpy (pszErr, pszDesc);

	return TRUE;
}

void fsGetPath (LPCSTR pszFile, LPSTR pszPath)
{
	strcpy (pszPath, pszFile);
	
	int len = strlen (pszPath) - 1;

	while (len >= 0 && pszPath [len] != '\\' && pszPath [len] != '/')
		len--;

	pszPath [len+1] = 0;
}

void fsGetFileName (LPCSTR pszFilePath, LPSTR pszFileName)
{
	CHAR szPath [MY_MAX_PATH];
	fsGetPath (pszFilePath, szPath);
	strcpy (pszFileName, pszFilePath + strlen (szPath));
}

BOOL fsBuildPathToFile (LPCSTR pszFileName)
{
	CHAR szPath [MY_MAX_PATH];
	
	fsGetPath (pszFileName, szPath);

	int len = strlen (szPath);
	int start = 0;

	
	if (szPath [0] == '\\' && szPath [1] == '\\')
	{
		
		LPCSTR psz = strchr (szPath + 2, '\\');
		
		if (psz)
			psz = strchr (psz+1, '\\');
		if (psz)
			psz++;
		if (psz == NULL)
		{
			
			SetLastError (ERROR_PATH_NOT_FOUND);
			return FALSE;
		}
		
		
		start = psz - szPath;
	}
	else
	{
		if (szPath [1] == ':')
			start = 3;
	}

	for (int i = start; i < len; i++)
	{
		if (szPath [i] == '\\' || szPath [i] == '/')
		{
			
			
			
			
			
			
	
			CHAR szPath2 [MY_MAX_PATH];

			CopyMemory (szPath2, szPath, i);
			szPath2 [i] = 0;

			if (FALSE == CreateDirectory (szPath2, NULL))	
			{
				if (GetLastError () != ERROR_ALREADY_EXISTS)
					return FALSE;
			}
		}
	}

	return TRUE;
}

BOOL fsBuildPathToFileW (LPCWSTR pwszFileName)
{
	LPCWSTR pwsz = pwszFileName;

	for (;;)
	{
		pwsz = wcschr (pwsz + 1, '\\');
		if (pwsz == NULL)
			break;
		if (pwsz - pwszFileName == 2)
			continue;
		wchar_t wsz [MY_MAX_PATH];
		wcsncpy (wsz, pwszFileName, pwsz - pwszFileName);
		wsz [pwsz - pwszFileName] = 0;
		CreateDirectoryW (wsz, NULL);
	}

	return TRUE;
}

#ifndef FDM_DLDR__RAWCODEONLY
BOOL DPEntry_IsAllEqual (DLDS_LIST *pv, int offset, int size, BOOL bString)
{
	int cDlds = pv->size ();

	if (cDlds == 0)
		return FALSE;

	LPVOID dp0 = LPBYTE (pv->at (0)->pMgr->GetDownloadMgr ()->GetDP ()) + offset;
	LPVOID dpn;

	for (int i = 1; i < cDlds; i++)
	{
		dpn = LPBYTE (pv->at (i)->pMgr->GetDownloadMgr ()->GetDP ()) + offset;
		
		if (bString)
		{
			LPCSTR psz1 = *((LPCSTR*) dp0);
			LPCSTR psz2 = *((LPCSTR*) dpn);

			if (strcmp (psz1, psz2))
				return FALSE;
		}
		else
		{
			if (memcmp (dp0, dpn, size))
				return FALSE;
		}
	}

	return TRUE;
}

BOOL DNPEntry_IsAllEqual (DLDS_LIST *pv, int offset, int size, BOOL bString)
{
	int cDlds = pv->size ();

	if (cDlds == 0)
		return FALSE;

	LPVOID dp0 = LPBYTE (pv->at (0)->pMgr->GetDownloadMgr ()->GetDNP ()) + offset;
	LPVOID dpn;

	for (int i = 1; i < cDlds; i++)
	{
		dpn = LPBYTE (pv->at (i)->pMgr->GetDownloadMgr ()->GetDNP ()) + offset;
		
		if (bString)
		{
			LPCSTR psz1 = *((LPCSTR*) dp0);
			LPCSTR psz2 = *((LPCSTR*) dpn);

			if (strcmp (psz1, psz2))
				return FALSE;
		}
		else
		{
			if (memcmp (dp0, dpn, size))
				return FALSE;
		}
	}

	return TRUE;
}

BOOL DPEntry_IsAllEqual_BitMask (DLDS_LIST *pv, int offset, DWORD dwBitMask)
{
	int cDlds = pv->size ();

	if (cDlds == 0)
		return FALSE;

	LPDWORD dp0 = (LPDWORD) (LPBYTE (pv->at (0)->pMgr->GetDownloadMgr ()->GetDP ()) + offset);
	LPDWORD dpn;

	for (int i = 1; i < cDlds; i++)
	{
		dpn = (LPDWORD) (LPBYTE (pv->at (i)->pMgr->GetDownloadMgr ()->GetDP ()) + offset);
		
		if ((*dp0 & dwBitMask) != (*dpn & dwBitMask))
			return FALSE;
	}

	return TRUE;
}

void DPEntry_SetValue (DLDS_LIST *pv, int offset, int size, BOOL bString, const void* lpNewVal)
{
	LPCSTR pszNewVal = (LPCSTR) lpNewVal;
	int len = 0;

	if (bString)
		len = strlen (pszNewVal);

	for (int i = pv->size () - 1; i >= 0; i--)
	{
		LPVOID dp = LPBYTE (pv->at (i)->pMgr->GetDownloadMgr ()->GetDP ()) + offset;
		
		if (bString)
		{
			LPSTR *ppszVal = (LPSTR*) dp;
			
			SAFE_DELETE_ARRAY (*ppszVal);

			fsnew (*ppszVal, CHAR, len+1);
			strcpy (*ppszVal, pszNewVal);
		}
		else
		{
			memcpy (dp, lpNewVal, size);
		}
		pv->at (i)->pMgr->GetDownloadMgr ()->setDirty();
	}
}

void DPEntry_SetValue_BitMask (DLDS_LIST *pv, int offset, DWORD dwMask)
{
	for (int i = pv->size () - 1; i >= 0; i--)
	{
		LPDWORD dp = (LPDWORD) (LPBYTE (pv->at (i)->pMgr->GetDownloadMgr ()->GetDP ()) + offset);
		*dp |= dwMask;
		pv->at (i)->pMgr->GetDownloadMgr ()->setDirty();
	}
}

void DPEntry_UnsetValue_BitMask (DLDS_LIST *pv, int offset, DWORD dwMask)
{
	for (int i = pv->size () - 1; i >= 0; i--)
	{
		LPDWORD dp = (LPDWORD) (LPBYTE (pv->at (i)->pMgr->GetDownloadMgr ()->GetDP ()) + offset);
		*dp &= ~dwMask;
		pv->at (i)->pMgr->GetDownloadMgr ()->setDirty();
	}
}

void DNPEntry_SetValue (DLDS_LIST *pv, int offset, int size, BOOL bString, const void* lpNewVal)
{
	LPCSTR pszNewVal = (LPCSTR) lpNewVal;
	int len = 0;

	if (bString)
		len = strlen (pszNewVal);

	for (int i = pv->size () - 1; i >= 0; i--)
	{
		LPVOID dnp = LPBYTE (pv->at (i)->pMgr->GetDownloadMgr ()->GetDNP ()) + offset;
		
		if (bString)
		{
			LPSTR *ppszVal = (LPSTR*) dnp;
			
			SAFE_DELETE_ARRAY (*ppszVal);

			fsnew (*ppszVal, CHAR, len+1);
			strcpy (*ppszVal, pszNewVal);
		}
		else
		{
			memcpy (dnp, lpNewVal, size);
		}
		pv->at (i)->pMgr->GetDownloadMgr ()->setDirty();
	}
}

BOOL DNPEntry_IsAllEqual_BitMask (DLDS_LIST *pv, int offset, DWORD dwBitMask)
{
	int cDlds = pv->size ();

	if (cDlds == 0)
		return FALSE;

	LPDWORD dnp0 = (LPDWORD) (LPBYTE (pv->at (0)->pMgr->GetDownloadMgr ()->GetDNP ()) + offset);
	LPDWORD dnpn;

	for (int i = 1; i < cDlds; i++)
	{
		dnpn = (LPDWORD) (LPBYTE (pv->at (i)->pMgr->GetDownloadMgr ()->GetDNP ()) + offset);
		
		if ((*dnp0 & dwBitMask) != (*dnpn & dwBitMask))
			return FALSE;
	}

	return TRUE;
}

void DNPEntry_SetValue_BitMask (DLDS_LIST *pv, int offset, DWORD dwMask)
{
	for (int i = pv->size () - 1; i >= 0; i--)
	{
		LPDWORD dnp = (LPDWORD) (LPBYTE (pv->at (i)->pMgr->GetDownloadMgr ()->GetDNP ()) + offset);
		*dnp |= dwMask;
		pv->at (i)->pMgr->GetDownloadMgr ()->setDirty();
	}
}

void DNPEntry_UnsetValue_BitMask (DLDS_LIST *pv, int offset, DWORD dwMask)
{
	for (int i = pv->size () - 1; i >= 0; i--)
	{
		LPDWORD dnp = (LPDWORD) (LPBYTE (pv->at (i)->pMgr->GetDownloadMgr ()->GetDNP ()) + offset);
		*dnp &= ~dwMask;
		pv->at (i)->pMgr->GetDownloadMgr ()->setDirty();
	}
}

#endif

LPCSTR strcmp_m (LPCSTR pszWhere, LPCSTR pszWhat)
{
	if (*pszWhere == 0)
		return *pszWhat == 0 ? pszWhere : NULL;

	if (*pszWhat == 0)
		return NULL;

	
	if (*pszWhat == '*')
	{
		
		if (pszWhat [1] == 0)
			return pszWhere;
		
		
		
		LPCSTR psz = strcmp_m (pszWhere, pszWhat+1);
		if (psz)
			return psz;

		
		
		
		return strcmp_m (pszWhere+1, pszWhat);
	}

	

	if (*pszWhat != '?')
	{
		
		if (*pszWhere != *pszWhat)
			return NULL;
	}

	return strcmp_m (pszWhere+1, pszWhat+1) ? pszWhere : NULL;
}

LPCSTR strcmpi_m (LPCSTR pszWhere, LPCSTR pszWhat)
{
	char *psz1 = new char [lstrlen (pszWhere) + 1];
	char *psz2 = new char [lstrlen (pszWhat) + 1];

	lstrcpy (psz1, pszWhere);
	lstrcpy (psz2, pszWhat);

	CharLower (psz1);
	CharLower (psz2);

	LPCSTR psz = strcmp_m (psz1, psz2);
	LPCSTR pszRet = NULL;
	
	if (psz)
		pszRet = pszWhere + (psz - psz1);

	delete [] psz1;
	delete [] psz2;

	return pszRet;
}

BOOL IsExtStrEq (LPCSTR pszMasked, LPCSTR psz2)
{
	return strcmpi_m (psz2, pszMasked) != NULL;
}

BOOL IsExtInExtsStr (LPCSTR pszExts, LPCSTR pszExt)
{
	if (pszExt == NULL)
		return FALSE;

	int len = lstrlen (pszExts);
	int i = 0;
	CHAR szExt [1000]; 

	do
	{
		int j = 0;

		

		while (i < len && pszExts [i] != ' ')
			szExt [j++] = pszExts [i++];

		szExt [j] = 0;
		i++;

		if (IsExtStrEq (szExt, pszExt))
			return TRUE;

	} while (i < len);

	return FALSE;
}

BOOL fsSaveStrToFile(LPCSTR pszStr, HANDLE hFile)
{
	int len;

	if (pszStr == NULL)
		len = -1;
	else
		len = strlen (pszStr);
	
	DWORD dw;

	if (!WriteFile (hFile, &len, sizeof (len), &dw, NULL))
		return FALSE;

	if (len != -1)
		return WriteFile (hFile, pszStr, len, &dw, NULL);
	
	return TRUE;
}

BOOL fsReadStrFromFile(LPSTR *ppszStr, HANDLE hFile)
{
	int len;

	DWORD dw;

	if (!ReadFile (hFile, &len, sizeof (len), &dw, NULL) || dw != sizeof (len))
		return FALSE;

	if (len != -1)
	{
		if (UINT (len) > 100000)
			return FALSE; 

		fsnew (*ppszStr, char, len+1);
		if (!ReadFile (hFile, *ppszStr, len, &dw, NULL))
			return FALSE;

		if (len != int (dw))
			return FALSE;

		(*ppszStr) [len] = 0;
	}
	else
		*ppszStr = NULL;
	
	return TRUE;
}

BOOL fsReadStringFromFile (HANDLE hFile, fsString &str)
{
	SAFE_DELETE_ARRAY (str.pszString);
	return fsReadStrFromFile (&str.pszString, hFile);
}

typedef ULONGLONG* LPULONGLONG;

DWORD fsGetTimeDelta (FILETIME *t1, FILETIME *t2)
{
	return DWORD ((*LPULONGLONG (t1) - *LPULONGLONG (t2)) / 10000000);
}

DWORD fsGetTimeDelta (const SYSTEMTIME *t1, const SYSTEMTIME *t2)
{
	FILETIME ft1, ft2;
	SystemTimeToFileTime (t1, &ft1);
	SystemTimeToFileTime (t2, &ft2);
	return fsGetTimeDelta (&ft1, &ft2);
}

CString fsTimeInSecondsToStr (DWORD dwAmount)
{
	CString strResult;

	strResult.Format (_T ("%02d:%02d:%02d"), 
		(int)(dwAmount / 3600),				
		(int)((dwAmount % 3600) / 60),		
		(int)(dwAmount % 60));				

	return strResult;
}

#pragma warning (disable:4706)
void fsPathToGoodPath (LPSTR pszPath)
{
	LPSTR pszBad = pszPath;

	while (pszBad = strchr (pszBad, '/'))  
		*pszBad = '\\';
}

void fsPathToGoodUrlPath (LPSTR pszPath)
{
	LPSTR pszBad = pszPath;

	while (pszBad = strchr (pszBad, '\\'))
		*pszBad = '/';
}
#pragma warning (default:4706)

#ifndef FDM_DLDR__RAWCODEONLY
void fsOpenBuyPage ()
{

#ifdef WGET_AFFILIATE_ID
	#pragma message ("================================ AFFILIATE IS ACTIVE!!! ==========================")
	CString str;
	str.Format ("https://www.regnow.com/softsell/nph-softsell.cgi?item=9752-1&affiliate=%d", WGET_AFFILIATE_ID);
	fsOpenUrlInBrowser (str);
#else
	if (stricmp (_LngMgr.GetLngName (_LngMgr.GetCurLng ()), "Russian"))
		fsOpenUrlInBrowser ("http://www.freedownloadmanager.org/buy.html");
	else
		fsOpenUrlInBrowser ("http://www.freedownloadmanager.org/buy.html");
#endif
}

CString fsBytesToStr (UINT64 uBytes)
{
	CString strBytes = " "; 
	strBytes += LS (L_B);
	CString str;
	UINT u;

	do
	{
		 if (uBytes > 1000)
			 u = UINT (uBytes % 1000);
		 else
			 u = 0;

		if (u)
		{
			str.Format (",%d", u);
			if (str.GetLength () == 2)
				str.Insert (1, "00");
			else if (str.GetLength () == 3)
				str.Insert (1, "0");
		}
		else
		{
			if (uBytes < 1000)
				str.Format ("%d", (UINT)uBytes);
			else
			{
				str = ",000";
			}
		}

		uBytes /= 1000;

		strBytes.Insert (0, str);
	}
	while (uBytes);

	return strBytes;
}

CString fsGetGrpOTHEROutFolder ()
{
	return _DldsGrps.FindGroup (GRP_OTHER_ID)->strOutFolder;
}
#endif

void vmsUtf8ToAscii (LPSTR psz)
{
	int len = lstrlen (psz);
	int nRL = MultiByteToWideChar (CP_UTF8, 0, psz, len, NULL, 0);
	wchar_t *pwsz = new wchar_t [nRL+1]; *pwsz = 0;
	MultiByteToWideChar (CP_UTF8, 0, psz, -1, pwsz, nRL+1);
	WideCharToMultiByte (CP_ACP, 0, pwsz, -1, psz, len+1, NULL, NULL);
	delete [] pwsz;
}

std::wstring vmsUtf8Unicode (LPCSTR psz)
{
	wchar_t wsz [100000] = L"";
	MultiByteToWideChar (CP_UTF8, 0, psz, -1, wsz, 99999);
	return wsz;
}
