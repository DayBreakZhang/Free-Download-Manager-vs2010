/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

extern DWORD fsSysGetOsMajorVersion ();

extern void fsSetForegroundWindow (HWND hWnd);

extern void fsOpenUrlInBrowser (LPCSTR pszUrl);

extern int fsStrCmpNC (LPCSTR psz1, LPCSTR psz2);

extern int fsStrNCmpNC (LPCSTR psz1, LPCSTR psz2, int nCount);

#define WS_EX_LAYERED           0x00080000
#define LWA_ALPHA				0x00000002

extern BOOL fsSetLayeredWindowAttributes (HWND hWnd, COLORREF clrKey, BYTE bAlpha, DWORD dwFlags);

extern void fsOnMemoryError ();
#define fsnew(p, T, L) {p=NULL; while (TRUE) { try { p = new T [L]; if (p == NULL) fsOnMemoryError (); else break; } catch (...) {fsOnMemoryError ();} } }
#define fsnew1(p, T) {p=NULL; while (TRUE) { try { p = new T; if (p == NULL) fsOnMemoryError (); else break; } catch (...) {fsOnMemoryError ();} } }

extern BOOL GetIEVersion(DWORD *pMajor, DWORD *pMinor, DWORD *pBuild, DWORD *pSubBuild);

extern DWORD GetShell32Version ();

extern BOOL fsSetFilePointer (HANDLE hFile, UINT64 uPosition, DWORD dwMethod);

extern UINT64 fsGetFileSize (HANDLE hFile);

extern int fsGetFTimeDaysDelta (FILETIME t1, FILETIME t2);

extern BOOL fsIsSystemInFullScreenMode ();

extern BOOL vmsSetSuspendState (BOOL bHibernate, BOOL bForce, BOOL bDisableWakeEvent);

extern DWORD vmsSHCopyKey (HKEY, LPCSTR, HKEY);
extern LONG fsCopyKey(HKEY hSrcParent, HKEY hTargParent, LPCTSTR szSrcKey, LPCTSTR szTargKey);

extern BOOL vmsDeleteFileAtWinBoot (LPCSTR pszFile);

#endif