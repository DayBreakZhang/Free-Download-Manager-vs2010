/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSXMLHELPER_H__7871CECA_C55A_4EEC_A648_8295717B85C7__INCLUDED_)
#define AFX_VMSXMLHELPER_H__7871CECA_C55A_4EEC_A648_8295717B85C7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsXmlHelper  
{
public:
	static void tstring_Replace (tstring tstr, LPCTSTR ptszOld, LPCTSTR ptszNew);
	static string toUtf8noEncode (const tstring &tstr);
	static tstring FromUtf8(LPCSTR psz);
	static string toUtf8(const tstring &tstr);
	vmsXmlHelper();
	virtual ~vmsXmlHelper();

};

#endif 
