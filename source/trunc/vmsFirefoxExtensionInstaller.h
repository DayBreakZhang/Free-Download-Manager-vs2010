/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSFIREFOXEXTENSIONINSTALLER_H__519BE98A_DBFF_49CC_99C7_536B805CEFE8__INCLUDED_)
#define AFX_VMSFIREFOXEXTENSIONINSTALLER_H__519BE98A_DBFF_49CC_99C7_536B805CEFE8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsFirefoxExtensionInstaller  
{
public:
	
	
	
	static bool IsInstalled (LPCSTR pszCID, bool bInDefaultProfileOnly);
	
	
	static bool Do (LPCSTR pszCID, LPCSTR pszExtPath, bool bInstall = true);

	vmsFirefoxExtensionInstaller();
	virtual ~vmsFirefoxExtensionInstaller();

protected:
public:
	static bool ExtractExtensionInfo(LPCTSTR ptszRdf, tstring& tstrVersion);
};

#endif 
