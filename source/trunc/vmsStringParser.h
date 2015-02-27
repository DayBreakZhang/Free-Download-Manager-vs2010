/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSSTRINGPARSER_H__0B0F3DCF_14DC_4146_B988_4D092163E586__INCLUDED_)
#define AFX_VMSSTRINGPARSER_H__0B0F3DCF_14DC_4146_B988_4D092163E586__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsStringParser  
{
public:
	static void GetAlphaWord(LPCTSTR &ptsz, tstring &tstr);
	static void GetWordBeforeChar(LPCTSTR &ptsz, TCHAR tch, tstring &tstr);
	static void SkipWhiteChars (LPCTSTR &ptsz);
	static void RemoveNonSpaceWhiteChars (tstring &tstr);
	static void GetTextBeforeChar (LPCTSTR &ptsz, TCHAR tch, tstring &tstr);
	static bool isWhiteChar (TCHAR tch);
	static void GetWord (LPCTSTR &ptsz, tstring &tstr);
	vmsStringParser();
	virtual ~vmsStringParser();

};

#endif 
