/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSAPPSETTINGSSTORE_H__232450C9_092A_49EF_9B4E_3D2DA2B9E736__INCLUDED_)
#define AFX_VMSAPPSETTINGSSTORE_H__232450C9_092A_49EF_9B4E_3D2DA2B9E736__INCLUDED_

#include "vmsDataFile.h"	
#include "vmsPersistObject.h"

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsAppSettingsStore : public vmsPersistObject
{
public:
	void SaveSettingsToFile(LPCSTR pszFile);
	void LoadSettingsFromFile (LPCSTR pszFile);

	BOOL WriteProfileBinary (LPCSTR pszSection, LPCSTR pszEntry, LPBYTE pbData, UINT nBytes);
	BOOL GetProfileBinary (LPCSTR pszSection, LPCSTR pszEntry, LPBYTE* ppData, UINT* pBytes);

	BOOL WriteProfileString(LPCSTR pszSection, LPCSTR pszEntry, LPCSTR pszValue);
	CString GetProfileString(LPCSTR pszSection, LPCSTR pszEntry, LPCSTR pszDefault);

	BOOL WriteProfileUint64(LPCSTR pszSection, LPCSTR pszEntry, UINT64 nValue);
	UINT64 GetProfileUint64(LPCSTR pszSection, LPCSTR pszEntry, UINT64 nDefault);

	BOOL WriteProfileInt (LPCSTR pszSection, LPCSTR pszEntry, int nValue);
	UINT GetProfileInt (LPCSTR pszSection, LPCSTR pszEntry, INT nDefault);

	void getObjectItselfStateBuffer(LPBYTE pb, LPDWORD pdwSize, bool bSaveToStorage);
	bool loadObjectItselfFromStateBuffer(LPBYTE pb, LPDWORD pdwSize, DWORD dwVer);

	vmsAppSettingsStore();
	virtual ~vmsAppSettingsStore();

protected:
	
	bool m_bUseRegistry;
	vmsDataFile m_file;
	CWinApp* m_app;
};

#endif 
