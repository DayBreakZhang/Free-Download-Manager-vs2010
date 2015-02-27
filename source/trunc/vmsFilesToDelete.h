/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSFILESTODELETE_H__AF54F3E8_DC60_43BE_BFD4_713D289A071C__INCLUDED_)
#define AFX_VMSFILESTODELETE_H__AF54F3E8_DC60_43BE_BFD4_713D289A071C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsFilesToDelete  
{
public:
	
	static void Process();
	
	static void AddFile (LPCSTR pszFile);

	vmsFilesToDelete();
	virtual ~vmsFilesToDelete();

};

#endif 
