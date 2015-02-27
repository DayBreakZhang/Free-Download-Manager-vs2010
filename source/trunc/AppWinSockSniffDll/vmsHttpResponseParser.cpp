/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsHttpResponseParser.h"

vmsHttpResponseParser::vmsHttpResponseParser()
{
	m_nStatusCode = 0;
}

vmsHttpResponseParser::~vmsHttpResponseParser()
{

}

void vmsHttpResponseParser::ParseHeader(LPCSTR pszHdr)
{
	vmsHttpParser::ParseHeader (pszHdr);

	m_strHttpVersion = m_strResponseResult = "";
	m_nStatusCode = 0;

	while (*pszHdr && *pszHdr != ' ')
		m_strHttpVersion += *pszHdr++;

	if (*pszHdr == 0)
		return;

	while (*pszHdr == ' ')
		pszHdr++;

	while (*pszHdr != '\r' && *pszHdr != '\n' && *pszHdr != 0)
		m_strResponseResult += *pszHdr++;

	m_nStatusCode = atoi (m_strResponseResult.c_str ());
}

LPCSTR vmsHttpResponseParser::getResponseResult() const
{
	return m_strResponseResult.c_str ();
}

UINT vmsHttpResponseParser::getStatusCode() const
{
	return m_nStatusCode;
}
