/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSHTTPHELPER_H__F50071F9_839B_4FE0_A7A5_D0F03526DF53__INCLUDED_)
#define AFX_VMSHTTPHELPER_H__F50071F9_839B_4FE0_A7A5_D0F03526DF53__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsHttpHelper  
{
public:
	static void ExtractHostName (LPCSTR pszUrl, string &strHost);
	static void DecodeUrl (LPCSTR pszUrl, string &strRes);
	static string ExtractPath (LPCSTR pszUrl);
	static string ExtractPathWithoutFileName (LPCSTR pszUrl);
	static string ExtractFileName (LPCSTR pszUrl);
	static void ExtractUrlValues (LPCSTR pszUrl, vector <string> *pvValNames, vector <string> *pvValues);
	vmsHttpHelper();
	virtual ~vmsHttpHelper();

};

#endif 
