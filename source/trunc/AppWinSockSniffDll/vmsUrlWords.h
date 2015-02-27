/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSURLWORDS_H__3E7E22CE_F156_4A5C_B3A7_C44EB92657A4__INCLUDED_)
#define AFX_VMSURLWORDS_H__3E7E22CE_F156_4A5C_B3A7_C44EB92657A4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsUrlWords  
{
public:
	static int GetUrlWordWeight (LPCSTR pszWord);
	
	static void ExtractWordsFromUrlEncodedValues (LPCSTR pszValues, vector <string> &vResult);
	static void ExtractWords2 (LPCSTR pszUrl, vector <string> &vWords);
	static void ExtractWords (LPCSTR pszUrl, string &strHost, vector <string> &vstrFolders, string &strFileName, vector <string> &vUrlValues);
	vmsUrlWords();
	virtual ~vmsUrlWords();

protected:
	static void SplitWord (LPCSTR pszWord, vector <string> &vSubWords);
};

#endif 
