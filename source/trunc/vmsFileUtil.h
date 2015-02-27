/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSFILEUTIL_H__A3E2F9DA_BF0E_43B9_AF5C_84C1AB7A72A6__INCLUDED_)
#define AFX_VMSFILEUTIL_H__A3E2F9DA_BF0E_43B9_AF5C_84C1AB7A72A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsFile.h"
using namespace vmsFDM;

class vmsFileUtil  
{
public:
	
	
	static void BuildPath (LPCSTR pszPath);
	
	static fsString GetPathFromPathName (LPCSTR pszPathName);
	
	static void BuildPathToFile (LPCSTR pszFileName);
	
	
	static void GetAppDataPath (LPCSTR pszAppName, LPSTR szPath);
	
	static void MakePathOK (LPSTR szPath, bool bNeedBackslashAtEnd = true);
	
	
	static void ReadHeader (vmsFile& file, fsString& strDesc, WORD& wVersion);
	
	static void WriteHeader (vmsFile& file, LPCSTR pszDesc, WORD wVersion);
	
	static void ReadString (vmsFile& file, fsString &str);
	static void WriteString (vmsFile& file, LPCSTR psz);
	static BOOL DirectoryExists(const char* dirName);
};

inline void vmsFILE_SAVE(vmsFile& file, LPCSTR psz) {vmsFileUtil::WriteString (file, psz);}
inline void vmsFILE_SAVE(vmsFile& file, int iValue){file.Write (&iValue, sizeof (int));}
inline void vmsFILE_SAVE(vmsFile& file, UINT uValue){file.Write (&uValue, sizeof (UINT));}
inline void vmsFILE_SAVE(vmsFile& file, DWORD uValue){file.Write (&uValue, sizeof (DWORD));}
inline void vmsFILE_SAVE(vmsFile& file, double fValue){file.Write (&fValue, sizeof (double));}
inline void vmsFILE_SAVE(vmsFile& file, __int64 iValue){file.Write (&iValue, sizeof (__int64));}

inline void vmsFILE_READ(vmsFile& file, fsString& str) {vmsFileUtil::ReadString (file, str);}
inline void vmsFILE_READ(vmsFile& file, int& iValue){file.Read (&iValue, sizeof (int));}
inline void vmsFILE_READ(vmsFile& file, UINT& uValue){file.Read (&uValue, sizeof (UINT));}
inline void vmsFILE_READ(vmsFile& file, DWORD& uValue){file.Read (&uValue, sizeof (DWORD));}
inline void vmsFILE_READ(vmsFile& file, double& fValue){file.Read (&fValue, sizeof (double));}
inline void vmsFILE_READ(vmsFile& file, __int64& iValue){file.Read (&iValue, sizeof (__int64));}

#endif 
