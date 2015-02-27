/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef _CRC32STATIC_H_
#define _CRC32STATIC_H_

#include "Common.h"

class CCrc32Static
{
friend class vmsHash;
public:
	CCrc32Static();
	virtual ~CCrc32Static();

	static DWORD StringCrc32(LPCTSTR szString, DWORD &dwCrc32);
	static DWORD FileCrc32Streams(LPCTSTR szFilename, DWORD &dwCrc32);

protected:
	static bool GetFileSizeQW(const HANDLE hFile, QWORD &qwSize);
	static inline void CalcCrc32(const BYTE byte, DWORD &dwCrc32);

	static DWORD s_arrdwCrc32Table[256];
};

#include "crc32.cpp"

#endif
