/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSFDMISSGENERATOR_H__A2BDF39E_ABE2_42D6_8CFA_D5B0C891BE75__INCLUDED_)
#define AFX_VMSFDMISSGENERATOR_H__A2BDF39E_ABE2_42D6_8CFA_D5B0C891BE75__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsFDMISSGenerator  
{
public:
	void Generate (LPCSTR pszOutputFile);
	vmsFDMISSGenerator();
	virtual ~vmsFDMISSGenerator();

protected:
	BOOL m_bAddDownloadsFile;
	CString m_strDownloadsFile;
	BOOL m_bAddSiteLinkToFavorites;
	BOOL m_bModifyHomepage;
	CString m_strSiteIcoFile;
	BOOL m_bAddSiteLinkToStartMenu;
	CString m_strSiteLink;
	CString m_strOutputFile;
	CString m_strOutputFolder;
	CString m_strVersion;
	CString m_strInstallationName;
	CString m_strInputFolder;
};

#endif 
