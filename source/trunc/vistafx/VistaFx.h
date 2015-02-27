/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __VISTA_FX_H_
#define __VISTA_FX_H_

class VistaFx
{
public:
	BOOL LoadDll (LPCSTR pszFileName) {
		if (m_hDll)
			return TRUE;
		m_hDll = LoadLibrary (pszFileName);
		return m_hDll != NULL;
	}

	BOOL IsProcessElevated () {
		typedef BOOL (*FNIPE)();
		FNIPE pfn = (FNIPE) GetProcAddress (m_hDll, "_IsProcessElevated");
		return pfn ? pfn () : FALSE;
	}

	BOOL RunNonElevatedProcess (LPCSTR pszPath, LPCSTR pszParameters, LPCSTR pszDirectory) {
		typedef BOOL (*FNRNEP)(LPCSTR, LPCSTR, LPCSTR);
		FNRNEP pfn = (FNRNEP) GetProcAddress (m_hDll, "_RunNonElevatedProcess");
		return pfn ? pfn (pszPath, pszParameters, pszDirectory) : FALSE;
	}

	static BOOL IsVistaOrHigher () {
		OSVERSIONINFO osver;
		osver.dwOSVersionInfoSize = sizeof (OSVERSIONINFO);
		return GetVersionEx (&osver) && osver.dwPlatformId == VER_PLATFORM_WIN32_NT && 
			osver.dwMajorVersion > 5;
	}

	VistaFx () { m_hDll = NULL; }
	~VistaFx () { if (m_hDll) FreeLibrary (m_hDll); m_hDll = NULL; }

protected:
	HMODULE m_hDll;

};

#endif 