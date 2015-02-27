/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSFILE_H__F67975E4_9034_4164_9F72_9A601E6872E5__INCLUDED_)
#define AFX_VMSFILE_H__F67975E4_9034_4164_9F72_9A601E6872E5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include <windows.h>
#include <string>

class vmsFile  
{
public:
	bool read (std::string& str);
	void close();
	bool open (LPCSTR pszName, LPCSTR pszMode = "r");
	vmsFile();
	virtual ~vmsFile();

protected:
	FILE* m_file;
};

#endif 
