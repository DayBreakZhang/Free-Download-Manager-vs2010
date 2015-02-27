/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSCHARSETS_H__BE5E1001_AC7B_45D3_BB32_9334C760D213__INCLUDED_)
#define AFX_VMSCHARSETS_H__BE5E1001_AC7B_45D3_BB32_9334C760D213__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsCharsets  
{
public:
	static void DecodeString (LPCSTR pszString, UINT nCodePage, wstring &wstrResult);
	static UINT GetCpIdFromName (LPCSTR pszName);
	vmsCharsets();
	virtual ~vmsCharsets();

};

#endif 
