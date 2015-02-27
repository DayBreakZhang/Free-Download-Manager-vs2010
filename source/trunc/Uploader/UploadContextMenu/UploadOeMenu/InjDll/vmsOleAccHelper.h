/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSOLEACCHELPER_H__2EBE1B5A_AA9A_4326_849B_899B96494C07__INCLUDED_)
#define AFX_VMSOLEACCHELPER_H__2EBE1B5A_AA9A_4326_849B_899B96494C07__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include <mshtml.h>
#include <comdef.h>

class vmsOleAccHelper  
{
public:
	static IHTMLDocument2Ptr GetDocumentFromHWND (HWND hwnd);
	vmsOleAccHelper();
	virtual ~vmsOleAccHelper();

};

#endif 
