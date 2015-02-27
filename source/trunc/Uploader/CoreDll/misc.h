/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __MISC_H_
#define __MISC_H_

#include "list.h"

extern void DrawVerticalFrame (HDC hdc, int xStart, int xEnd, int yStart, int height);
extern void DrawHorizontalFrame (HDC hdc, int yStart, int yEnd, int xStart, int width);

extern void BytesToXBytes (UINT64 uBytes, float* pfXBytes, LPSTR pszXVal);
extern CString BytesToString (UINT64 uSize);

extern void SystemTimeToStr (SYSTEMTIME *time, LPSTR pszDate, LPSTR pszTime, BOOL bSeconds = TRUE);
extern void FileTimeToStr (FILETIME *time, LPSTR pszDate, LPSTR pszTime, BOOL bSeconds = TRUE);

extern BOOL fsErrorToStr (LPSTR pszErr, DWORD dwMaxSize, DWORD* pdwLastError = NULL);

extern BOOL fsBuildPathToFile (LPCSTR pszFileName);

extern BOOL IsExtInExtsStr (LPCSTR pszExts, LPCSTR pszExt);

extern void fsGetPath (LPCSTR pszFile, LPSTR pszPath);

extern void fsGetFileName (LPCSTR pszFilePath, LPSTR pszFileName);

extern void fsPathToGoodPath (LPSTR pszPath);

extern void fsPathToGoodUrlPath (LPSTR pszPath);

extern BOOL fsSaveStrToFile(LPCSTR pszStr, HANDLE hFile);
extern BOOL fsReadStrFromFile(LPSTR *ppszStr, HANDLE hFile);
extern BOOL fsReadStringFromFile (HANDLE hFile, fsString &str);

extern DWORD fsGetTimeDelta (FILETIME *t1, FILETIME *t2);
extern DWORD fsGetTimeDelta (const SYSTEMTIME *t1, const SYSTEMTIME *t2);

extern CString fsTimeInSecondsToStr (DWORD dwAmount);

extern CString fsBytesToStr (UINT64 uBytes, BOOL bAdd_bytes_String);

extern CString fsGetGrpOTHEROutFolder ();

#define CLR_INQUIRY	RGB (255, 255, 210)
#define CLR_INQUIRY2	RGB (255, 255, 220)
#define CLR_DONE	RGB (230, 255, 250)
#define CLR_RESPONSE_S	RGB (230, 255, 230)
#define CLR_RESPONSE_S2	RGB (250, 255, 240)
#define CLR_RESPONSE_E	RGB (250, 240, 240)
#define CLR_WARNING	RGB (250, 240, 200)

extern BOOL fsSetClipboardText (HWND, LPCSTR psz);

extern INTERNET_SCHEME fsNPToScheme (fsNetworkProtocol np);

extern fsString fsHttpUrlEncode (LPCSTR psz);
extern fsString fsHtmlUnicodeEncode (LPCSTR psz);
extern fsString fsUtf8Encode (LPCSTR psz);
extern fsString fsUtf8HttpUrlEncode (LPCSTR psz);

extern void vmsSetClipboardText (LPCSTR psz);

extern BOOL fsSaveStrToFile(LPCSTR pszStr, HANDLE hFile);
extern BOOL fsReadStrFromFile(LPSTR *ppszStr, HANDLE hFile);
extern BOOL fsReadStringFromFile (HANDLE hFile, fsString &str);

extern void fsSetForegroundWindow (HWND hWnd);

#endif