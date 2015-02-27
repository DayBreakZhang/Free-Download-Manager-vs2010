/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __MISC_H_
#define __MISC_H_

#include "list.h"
#include "fsDownload.h" 

extern void DrawVerticalFrame (HDC hdc, int xStart, int xEnd, int yStart, int height);
extern void DrawHorizontalFrame (HDC hdc, int yStart, int yEnd, int xStart, int width);

extern void BytesToXBytes (UINT64 uBytes, float* pfXBytes, LPSTR pszXVal);
extern CString BytesToString (UINT64 uSize, bool bForceXbytes = false);

extern void SystemTimeToStr (SYSTEMTIME *time, LPSTR pszDate, LPSTR pszTime, BOOL bSeconds = TRUE);
extern void FileTimeToStr (FILETIME *time, LPSTR pszDate, LPSTR pszTime, BOOL bSeconds = TRUE);

extern BOOL fsErrorToStr (LPSTR pszErr, DWORD dwMaxSize, DWORD* pdwLastError = NULL);

extern BOOL fsBuildPathToFile (LPCSTR pszFileName);
extern BOOL fsBuildPathToFileW (LPCWSTR pszFileName);

extern BOOL DPEntry_IsAllEqual  (DLDS_LIST *pv, int offset, int size, BOOL bString);

extern BOOL DPEntry_IsAllEqual_BitMask (DLDS_LIST *pv, int offset, DWORD dwBitMask);
extern BOOL DNPEntry_IsAllEqual (DLDS_LIST *pv, int offset, int size, BOOL bString);
extern void DPEntry_SetValue  (DLDS_LIST *pv, int offset, int size, BOOL bString, const void* lpNewVal);
extern void DNPEntry_SetValue (DLDS_LIST *pv, int offset, int size, BOOL bString, const void* lpNewVal);

extern void DPEntry_SetValue_BitMask (DLDS_LIST *pv, int offset, DWORD dwMask);

extern void DPEntry_UnsetValue_BitMask (DLDS_LIST *pv, int offset, DWORD dwMask);

extern BOOL DNPEntry_IsAllEqual_BitMask (DLDS_LIST *pv, int offset, DWORD dwBitMask);

extern void DNPEntry_SetValue_BitMask (DLDS_LIST *pv, int offset, DWORD dwMask);

extern void DNPEntry_UnsetValue_BitMask (DLDS_LIST *pv, int offset, DWORD dwMask);

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

extern CString fsBytesToStr (UINT64 uBytes);

extern CString fsGetGrpOTHEROutFolder ();

#define CLR_INQUIRY	RGB (255, 255, 210)
#define CLR_INQUIRY2	RGB (255, 255, 220)
#define CLR_DONE	RGB (230, 255, 250)
#define CLR_RESPONSE_S	RGB (230, 255, 230)
#define CLR_RESPONSE_S2	RGB (250, 255, 240)
#define CLR_RESPONSE_E	RGB (250, 240, 240)
#define CLR_WARNING	RGB (250, 240, 200)

extern void fsOpenBuyPage ();

extern void vmsUtf8ToAscii (LPSTR psz);
extern std::wstring vmsUtf8Unicode (LPCSTR psz);

#endif