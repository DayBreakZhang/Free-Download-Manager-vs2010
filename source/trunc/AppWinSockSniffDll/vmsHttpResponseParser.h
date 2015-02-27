/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSHTTPRESPONSEPARSER_H__BF2D012D_FC17_4BB7_AB61_3662DB293B4E__INCLUDED_)
#define AFX_VMSHTTPRESPONSEPARSER_H__BF2D012D_FC17_4BB7_AB61_3662DB293B4E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsHttpParser.h"

class vmsHttpResponseParser : public vmsHttpParser  
{
public:
	UINT getStatusCode () const;
	LPCSTR getResponseResult () const;
	void ParseHeader (LPCSTR pszHdr);
	vmsHttpResponseParser();
	virtual ~vmsHttpResponseParser();

protected:
	string m_strHttpVersion;
	string m_strResponseResult; 
	UINT m_nStatusCode;
};

#endif 
