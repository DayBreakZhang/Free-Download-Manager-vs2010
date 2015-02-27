/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __MFC_HELP_H_
#define __MFC_HELP_H_

extern void ConvertBmp32WithAlphaToBmp32WithoutAlpha (CBitmap& bmp, COLORREF clrBk);
extern LPCSTR fsGetAppDataFolder ();

extern CString fsGetDataFilePath (LPCSTR pszFile);

extern CString vmsGetAppFolder ();

void fsGetSystemAppDataFolder (LPSTR pszRes);

#endif