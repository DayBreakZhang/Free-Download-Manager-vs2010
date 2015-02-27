/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSHTTPREQUESTPARSER_H__2296CFDE_EB6C_4AA7_8685_9ED62DADF0B2__INCLUDED_)
#define AFX_VMSHTTPREQUESTPARSER_H__2296CFDE_EB6C_4AA7_8685_9ED62DADF0B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsHttpParser.h"

class vmsHttpRequestParser : public vmsHttpParser  
{
public:
	enum RequestType
	{
		GET, 
		POST,
		UNKNOWN,
	};
public:
	RequestType getRequestType () const;
	LPCSTR getPath () const;
	void ParseHeader (LPCSTR pszHdr);
	vmsHttpRequestParser();
	virtual ~vmsHttpRequestParser();

protected:
	RequestType m_enRT;
	string m_strPath; 
	string m_strHttpVersion;
};

#endif 
