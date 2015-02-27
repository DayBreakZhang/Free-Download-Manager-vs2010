/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsHttpParser.h"

vmsHttpParser::vmsHttpParser()
{

}

vmsHttpParser::~vmsHttpParser()
{

}

void vmsHttpParser::ExtractFieldValue(LPCSTR pszHdr, LPCSTR pszFieldName, string *pstrResult)
{
	*pstrResult = "";
	string str = "\r\n";
	str += pszFieldName;
	str += ':';
	LPCSTR psz = strstr (pszHdr, str.c_str ());
	if (psz == NULL)
		return;
	psz += str.length ();
	while (*psz == ' ')
		psz++;
	while (*psz && *psz != '\r' && *psz != '\n')
		*pstrResult += *psz++;
}

void vmsHttpParser::ParseHeader(LPCSTR pszHdr)
{
	m_vFields.clear ();

	pszHdr = strstr (pszHdr, "\r\n"); 
	if (!pszHdr)
		return;
	pszHdr += 2;

	HdrField hdrf;
	while (ExtractHdrField (pszHdr, hdrf))
		m_vFields.push_back (hdrf);
}

bool vmsHttpParser::ExtractHdrField(LPCSTR &pszHdr, HdrField &hdrf)
{
	string strName;
	string strValue;

	while (*pszHdr != ':' && *pszHdr != 0)
		strName += *pszHdr++;

	if (*pszHdr == 0)
		return false;

	pszHdr++;
	while (*pszHdr == ' ')
		pszHdr++;

	while (*pszHdr != 0 && *pszHdr != '\r' && *pszHdr != '\n')
		strValue += *pszHdr++;

	if (*pszHdr == 0)
		return false;
	if (pszHdr [0] != '\r' || pszHdr [1] != '\n')
		return false;
	pszHdr += 2;

	hdrf.strName = strName;
	hdrf.strValue = strValue;

	return true;
}

const vmsHttpParser::HdrField* vmsHttpParser::FieldByName(LPCSTR pszName) const
{
	for (size_t i = 0; i < m_vFields.size (); i++)
	{
		if (stricmp (m_vFields [i].strName.c_str (), pszName) == 0)
			return &m_vFields [i];
	}

	return NULL;
}
