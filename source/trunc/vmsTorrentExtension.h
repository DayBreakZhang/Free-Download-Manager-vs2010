/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSTORRENTEXTENSION_H__027AF6AC_9BCC_4ED2_BF22_2168E5F6E080__INCLUDED_)
#define AFX_VMSTORRENTEXTENSION_H__027AF6AC_9BCC_4ED2_BF22_2168E5F6E080__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsTorrentExtension  
{
public:
	static BOOL CheckAccessRights ();
	
	static BOOL AssociateWith (LPCSTR pszCmdLine);
	static fsString GetCurrentAssociation();
	static BOOL IsAssociatedWithUs();
	
	static BOOL IsAssociationExist();
	
	static BOOL Associate();

	vmsTorrentExtension();
	virtual ~vmsTorrentExtension();

protected:
	
	static fsString get_ShellOpenCommandLine();
};

#endif 
