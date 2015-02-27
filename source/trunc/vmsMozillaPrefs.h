/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSMOZILLAPREFS_H__7F8AC419_31D2_40FF_BF85_7A989BBE494D__INCLUDED_)
#define AFX_VMSMOZILLAPREFS_H__7F8AC419_31D2_40FF_BF85_7A989BBE494D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include <windows.h>
#include "fsString.h"

#define MOZILLAPREFS_VALUE_NOT_FOUND	"vmsMozillaPrefs::value not found"
#define MOZILLAPREFS_UNEXPECTED_ERROR	"vmsMozillaPrefs::unexp error"

class vmsMozillaPrefs  
{
public:
	
	bool LoadPrefs (LPCSTR pszFile);
	
	
	fsString get_Value (LPCSTR pszPrefName) const;
	
	void Free();
	
	vmsMozillaPrefs();
	virtual ~vmsMozillaPrefs();

protected:
	
	fsString m_strPrefs;
};

#endif 
