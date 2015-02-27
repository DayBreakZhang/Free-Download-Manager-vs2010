/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSSTRINGSHELPER_H__95E1EBBC_8BF7_4A79_8E8C_0F509A2BE04F__INCLUDED_)
#define AFX_VMSSTRINGSHELPER_H__95E1EBBC_8BF7_4A79_8E8C_0F509A2BE04F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsStringsHelper  
{
public:
	
	static bool isUtf8String (LPCSTR psz);
	static tstring FromUtf8 (LPCSTR psz);
	static void GetFilePathShortDisplayString (LPCTSTR pszFilePath, int nCharLimit, tstring &strRes);
	
	static void SecondsToString (int nSeconds, tstring &strRes);
	static void BytesToXBstring (UINT64 nBytes, tstring &strRes);
	vmsStringsHelper();
	virtual ~vmsStringsHelper();

};

#endif 
