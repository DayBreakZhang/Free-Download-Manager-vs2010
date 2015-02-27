/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"

union BmpColor
{
	DWORD clr;
	struct {
		BYTE r, g, b, a;
	};

	BmpColor (DWORD dw) {clr = dw;}
	BmpColor () {}
};

BmpColor MixColor (BmpColor clr1, BmpColor clr2)
{
	double alpha, notalpha;
	BmpColor res;
	
	alpha = clr1.a / 255.0;
	notalpha = 1.0 - alpha;

	res.r = BYTE (clr1.r*alpha + clr2.b*notalpha + 0.5);
	res.g = BYTE (clr1.g*alpha + clr2.g*notalpha + 0.5);
	res.b = BYTE (clr1.b*alpha + clr2.r*notalpha + 0.5);
	res.a = 0;

	return res;
}

void ConvertBmp32WithAlphaToBmp32WithoutAlpha (CBitmap& bmp, COLORREF clrBk)
{
	int w, h;

	BITMAP bm;
	bmp.GetBitmap (&bm);

	h = bm.bmHeight;
	w = bm.bmWidth;

	DWORD* pdwBmp32plusA = new  DWORD [w*h];
	bmp.GetBitmapBits (w*h*4, pdwBmp32plusA);

	DWORD* pdwBmp32 = new DWORD [w*h];

	for (int i = 0; i < h; i++)
	{
		for (int k = 0; k < w; k++)
		{
			BmpColor clr = MixColor (pdwBmp32plusA [i*w+k], clrBk);
			pdwBmp32 [(h-1)*w - i*w + k] = clr.clr;
		}
	}

	bmp.DeleteObject ();

	HDC dc = GetDC (NULL);
	bmp.CreateCompatibleBitmap (CDC::FromHandle (dc), w, h);

	BITMAPINFO bi;
	ZeroMemory (&bi, sizeof (bi));
	bi.bmiHeader.biSize = sizeof (BITMAPINFOHEADER);
	bi.bmiHeader.biWidth = w;
	bi.bmiHeader.biHeight = h;
	bi.bmiHeader.biPlanes = 1;
	bi.bmiHeader.biCompression = BI_RGB;
	
	bi.bmiHeader.biBitCount = 32;
	SetDIBits (dc, bmp, 0, h, pdwBmp32, &bi, DIB_RGB_COLORS);

	delete [] pdwBmp32plusA;
	delete [] pdwBmp32;
}

char _szAppDataFolder [MY_MAX_PATH] = "";
bool _bNeedRecalcAppDataFolder = false;

void fsGetSystemAppDataFolder (LPSTR pszRes)
{
	LPITEMIDLIST pidl = NULL;
	if (SUCCEEDED (SHGetSpecialFolderLocation (NULL, CSIDL_APPDATA, &pidl)))
	{
		SHGetPathFromIDList (pidl, pszRes);
		if (pszRes [lstrlen (pszRes)-1] != '\\')
			lstrcat (pszRes, "\\");
		IMallocPtr spMalloc;
		SHGetMalloc (&spMalloc);
		spMalloc->Free (pidl);
	}
	else
	{
		GetWindowsDirectory (pszRes, MAX_PATH);
		if (pszRes [3] != 0)
			lstrcat (pszRes, "\\");
		lstrcat (pszRes, "Application Data\\");
	}
}

LPCSTR fsGetAppDataFolder ()
{
	if (_bNeedRecalcAppDataFolder) 
	{
		_bNeedRecalcAppDataFolder = false;
		*_szAppDataFolder = 0;
	}

	if (*_szAppDataFolder)
		return _szAppDataFolder;

	CString str = _App.DataFolder ();
	if (str.IsEmpty () == FALSE)
	{
		lstrcpy (_szAppDataFolder, str);
		if (_szAppDataFolder [lstrlen (_szAppDataFolder)-1] != '\\')
			lstrcat (_szAppDataFolder, "\\");
		return _szAppDataFolder;
	}

	if (IS_PORTABLE_MODE)
	{
		lstrcpy (_szAppDataFolder, ((CFdmApp*)AfxGetApp ())->m_strAppPath);
		lstrcat (_szAppDataFolder, "Data\\");
		return _szAppDataFolder;
	}

	fsGetSystemAppDataFolder (_szAppDataFolder);
	lstrcat (_szAppDataFolder, "Free Download Manager\\");
	return _szAppDataFolder;
}

CString fsGetDataFilePath (LPCSTR pszFile)
{
	fsGetAppDataFolder ();

	CString strPath = _szAppDataFolder;
	strPath += pszFile;

	fsBuildPathToFile (strPath);

	if (strPath != pszFile)
	{
		if (GetFileAttributes (pszFile) != DWORD (-1) &&
				GetFileAttributes (strPath) == DWORD (-1))
			CopyFile (pszFile, strPath, TRUE);
	}

	return strPath;
}

CString fsGetProgramFilePath (LPCTSTR ptszFile)
{
	TCHAR tsz [MY_MAX_PATH] = _T ("");
	GetModuleFileName (NULL, tsz, MY_MAX_PATH);
	LPTSTR ptsz = _tcsrchr (tsz, '\\');
	if (!ptsz)
		return _T ("");
	ptsz [1] = 0;
	CString str = tsz;
	str += ptszFile;
	return str;
}

extern CFdmApp theApp;

LPCSTR fsGetFumProgramFilesFolder ()
{
	static char _szPath [MAX_PATH] = "";
	if (*_szPath == 0)
	{
		CRegKey key;
		DWORD dw = MAX_PATH;
		if (ERROR_SUCCESS == key.Open (HKEY_CURRENT_USER, "Software\\FreeDownloadManager.ORG\\Free Upload Manager"))
			key.QueryValue (_szPath, "Path", &dw);
		
		if (*_szPath != 0)
		{
			CString str = _szPath;
			str += "fum.exe";
			if (GetFileAttributes (str) == DWORD (-1))
				*_szPath = 0;
		}

		if (*_szPath == 0)
		{
			lstrcpy (_szPath, theApp.m_strAppPath);
			lstrcat (_szPath, "fum\\");
		}
	}
	return _szPath;
}

extern CFdmApp theApp;
CString vmsGetAppFolder ()
{
	return theApp.m_strAppPath;
}

void mfcSetForegroundWindow (CWnd *pwnd)
{
	fsSetForegroundWindow (pwnd->m_hWnd);
	pwnd->SetForegroundWindow ();
	pwnd->BringWindowToTop ();
}

void mfcSetTopmostWindow (CWnd *pwnd)
{
	::SetWindowPos (pwnd->GetSafeHwnd (), HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER);
}