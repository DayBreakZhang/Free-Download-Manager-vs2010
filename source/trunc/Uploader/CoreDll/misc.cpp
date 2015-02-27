/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "list.h"

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
	LPCSTR ppszX [] = {LS (L_B), LS (L_KB), LS (L_MB), "GB"};
	int i = 0;
	double dBytes = (double) (INT64)uBytes;

	while (dBytes > 9999)
	{
		dBytes /= 1024;
		i++;
	}

	if (pszXVal)
	{
		if (i > 3)
			strcpy (pszXVal, "?");
		else
			strcpy (pszXVal, ppszX [i]);
	}

	*pfXBytes = (FLOAT) dBytes;
}

CString fsBytesToStr (UINT64 uBytes, BOOL bAdd_bytes_String)
{
	CString strBytes; 
	if (bAdd_bytes_String)
	{
		strBytes = " ";
		strBytes += LS (L_B);
	}
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

#ifndef FDM_DLDR__RAWCODEONLY
CString BytesToString (UINT64 uSize)
{
	CString str;

	if (FALSE == _pDllCaller->GetSettings ()->ShowSizesInBytes ())
	{
		float val;
		char szDim [10];
		BytesToXBytes (uSize, &val, szDim);
		str.Format ("%.*g %s", val > 999 ? 4 : 3, val, szDim);
	}
	else
		str = fsBytesToStr (uSize, TRUE);

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
	CHAR szPath [MAX_PATH];
	fsGetPath (pszFilePath, szPath);
	strcpy (pszFileName, pszFilePath + strlen (szPath));
}

BOOL fsBuildPathToFile (LPCSTR pszFileName)
{
	CHAR szPath [MAX_PATH];
	
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
			CHAR szPath2 [MAX_PATH];

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

BOOL fsSetClipboardText (HWND hwnd, LPCSTR psz)
{
	if (FALSE == OpenClipboard (hwnd))
		return FALSE;

	EmptyClipboard ();

	HANDLE hText = GlobalAlloc (GMEM_MOVEABLE, strlen (psz)+1);
	if (hText == NULL)
	{
		CloseClipboard ();
		return FALSE;
	}

	LPSTR pszText = (LPSTR) GlobalLock (hText);
	strcpy (pszText, psz);
	GlobalUnlock (hText);

	SetClipboardData (CF_TEXT, hText);

	CloseClipboard ();

	return TRUE;
}

fsString fsHttpUrlEncode (LPCSTR psz)
{
	if (psz == NULL || *psz == 0)
		return "";

	CString str = "";

	while (*psz)
	{
		if (isdigit (*psz) || isalpha (*psz) || 
				*psz == '$' || *psz == '-' || *psz == '_' ||
				*psz == '.' || *psz == '+' || *psz == '!' || 
				*psz == '*' || *psz == '\'' || *psz == '(' ||
				*psz == ')' || *psz == ',')
		{
			str += *psz;
		}
		else
		{
			char sz [4];
			sprintf (sz, "%%%X", (int)(unsigned char)*psz);
			str += sz;
		}

		psz++;
	}

	return str;
}

fsString fsHtmlUnicodeEncode (LPCSTR psz)
{
	if (psz == NULL || *psz == 0)
		return "";

	CString str;
	wchar_t wsz [10000];
	MultiByteToWideChar (CP_ACP, 0, psz, -1, wsz, 10000);
	LPWSTR pwsz = wsz;
	while (*pwsz)
	{
		char sz [100];
		sprintf (sz, "\\u%04x", (int)*pwsz++);
		str += sz;
	}
	return str;
}

#include "UploadsWnd.h"
void vmsSetClipboardText (LPCSTR psz)
{
	if (FALSE == OpenClipboard (_pwndUploads->m_hWnd))
		return;

	EmptyClipboard ();

	HANDLE hText = GlobalAlloc (GMEM_MOVEABLE, strlen (psz)+1);
	if (hText == NULL)
	{
		CloseClipboard ();
		return;
	}

	LPSTR pszText = (LPSTR) GlobalLock (hText);
	strcpy (pszText, psz);
	GlobalUnlock (hText);

	SetClipboardData (CF_TEXT, hText);

	CloseClipboard ();
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

		*ppszStr = new char [len+1];
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
	delete str.pszString;
	str.pszString = NULL;
	return fsReadStrFromFile (&str.pszString, hFile);
}

void fsSetForegroundWindow (HWND hWnd)
{
	HWND hFor = GetForegroundWindow ();
	int iMyTID = GetCurrentThreadId ();
	int iCurrTID = GetWindowThreadProcessId (hFor, NULL);

	AttachThreadInput (iMyTID, iCurrTID, TRUE);

	SetForegroundWindow (hWnd);

	AttachThreadInput (iMyTID, iCurrTID, FALSE);
}

fsString fsUtf8Encode (LPCSTR psz)
{
	if (psz == NULL || *psz == 0)
		return "";

	fsString str;
	int len = lstrlen (psz);
	wchar_t *pwsz = new wchar_t [len * 3];
	MultiByteToWideChar (CP_ACP, 0, psz, -1, pwsz, len * 3);
	LPSTR psz2 = new char [len * 7];
	WideCharToMultiByte (CP_UTF8, 0, pwsz, -1, psz2, len * 7, NULL, NULL);
	str = psz2;
	delete [] pwsz;
	delete [] psz2;
	return str;
}

fsString fsUtf8HttpUrlEncode (LPCSTR psz)
{
	return fsHttpUrlEncode (fsUtf8Encode (psz));
}