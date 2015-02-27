/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSHTMLPARSER_H__793BF9BB_23D1_4BD0_B8A0_7301F7B045A8__INCLUDED_)
#define AFX_VMSHTMLPARSER_H__793BF9BB_23D1_4BD0_B8A0_7301F7B045A8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsHtmlParser  
{
public:
	static void DecodeHtmlSpecEntites (LPCSTR psz, string &strResult);
	static void findAllTagsHeads (LPCSTR pszHtml, LPCSTR pszTagName, vector <string> &vTagsHeads);
	static int findTag (LPCSTR pszHtml, LPCSTR pszTagName);
	static void getTagHead (LPCSTR pszTag, string &strResult);
	vmsHtmlParser();
	virtual ~vmsHtmlParser();

};

#endif 
