/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSFILEEXTENSION_H__1766EF58_2E89_440F_B55A_F66F9F07531E__INCLUDED_)
#define AFX_VMSFILEEXTENSION_H__1766EF58_2E89_440F_B55A_F66F9F07531E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsFileExtension  
{
public:
	static tstring GetExtensionName (LPCTSTR pszExt);
	static tstring GetExtensionId (LPCTSTR pszExt);
	static LPCTSTR getExtensionPart (LPCTSTR pszFileName);
	vmsFileExtension();
	virtual ~vmsFileExtension();

};

#endif 
