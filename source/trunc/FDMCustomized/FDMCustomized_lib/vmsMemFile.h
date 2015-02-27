/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSMEMFILE_H__6156ECB6_6D69_4055_8F29_11A40DD139FF__INCLUDED_)
#define AFX_VMSMEMFILE_H__6156ECB6_6D69_4055_8F29_11A40DD139FF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include <windows.h>

const char* const _pszMemFileError = "memfileerr";

class vmsMemFile  
{
public:
	void WriteFile (LPCVOID pb, DWORD dwSize);
	void ReadFile (LPVOID pb, DWORD dwSize);
	DWORD get_FileBufferSize();
	LPBYTE get_FileBuffer();
	void Done();
	void Use (HANDLE hFile, BOOL bRead);
	vmsMemFile();
	virtual ~vmsMemFile();

protected:
	LPBYTE m_pbFile;
	DWORD  m_dwSize;
	DWORD  m_dwPos;
	BOOL   m_bRead;
	HANDLE m_hFile;
};

#endif 
