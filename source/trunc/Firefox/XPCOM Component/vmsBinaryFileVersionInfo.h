/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSBINARYFILEVERSIONINFO_H__A0856ED4_D8F0_45E4_B883_EBB011DAC2F7__INCLUDED_)
#define AFX_VMSBINARYFILEVERSIONINFO_H__A0856ED4_D8F0_45E4_B883_EBB011DAC2F7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsAppVersion.h"

class vmsBinaryFileVersionInfo  
{
public:
	BOOL Retrieve (LPCTSTR pszFile);

	vmsBinaryFileVersionInfo(LPCTSTR ptszFile = NULL);
	virtual ~vmsBinaryFileVersionInfo();

	std::string m_strCompanyName;
	std::string m_strFileDescription;
	std::string m_strFileVersion;
	std::string m_strInternalName;
	std::string m_strLegalCopyright;
	std::string m_strOriginalFileName;
	std::string m_strProductName;
	std::string m_strProductVersion;

	
	vmsAppVersion m_appVersion;

protected:
	BOOL ExtractVersionInfo (LPVOID pvVer, DWORD dwSize);
};

#endif 
