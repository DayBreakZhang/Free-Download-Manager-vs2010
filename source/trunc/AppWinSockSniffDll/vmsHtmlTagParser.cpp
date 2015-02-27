/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsHtmlTagParser.h"

vmsHtmlTagParser::vmsHtmlTagParser(LPCSTR pszTagHead)
{
	if (pszTagHead)
		Parse (pszTagHead);
}

vmsHtmlTagParser::~vmsHtmlTagParser()
{

}

int vmsHtmlTagParser::Parse(LPCSTR pszTagHead)
{
	LPCSTR pszTagHeadOrig = pszTagHead;

	assert (*pszTagHead == '<');

	m_strName = "";
	m_vAttribs.clear ();

	if (*pszTagHead != '<')
		return 0;

	pszTagHead++;

	while (isspace ((BYTE)*pszTagHead))
		pszTagHead++;

	while (!isspace ((BYTE)*pszTagHead) && *pszTagHead != '>' && *pszTagHead)
		m_strName += *pszTagHead++;
	
	while (*pszTagHead && *pszTagHead != '>')
	{
		while (isspace ((BYTE)*pszTagHead))
			pszTagHead++;
		if (*pszTagHead == '>')
			break;

		TagAttribute attr;

		while (!isspace ((BYTE)*pszTagHead) && *pszTagHead != '=' && *pszTagHead != '>' && *pszTagHead)
			attr.strName += *pszTagHead++;

		if (attr.strName.empty ())
			break;

		while (isspace ((BYTE)*pszTagHead))
			pszTagHead++;

		if (*pszTagHead == '=')
		{
			pszTagHead++;

			while (isspace ((BYTE)*pszTagHead))
				pszTagHead++;

			if (*pszTagHead == '"' || *pszTagHead == '\'')
			{
				attr.chQ = *pszTagHead++;
				while (*pszTagHead != attr.chQ && *pszTagHead)
					attr.strValue += *pszTagHead++;
				if (*pszTagHead)
					pszTagHead++;
			}
			else
			{
				while (!isspace ((BYTE)*pszTagHead) && *pszTagHead != '>' && *pszTagHead)
					attr.strValue += *pszTagHead++;
			}
		}

		m_vAttribs.push_back (attr);
	}
	
	if (*pszTagHead == '>')
		pszTagHead++;

	return pszTagHead - pszTagHeadOrig;
}

const vmsHtmlTagParser::TagAttribute* vmsHtmlTagParser::findAttribute(LPCSTR pszName) const
{
	for (size_t i = 0; i < m_vAttribs.size (); i++)
	{
		const TagAttribute *attr = &m_vAttribs [i];
		if (!stricmp (attr->strName.c_str (), pszName))
			return attr;
	}

	return NULL;
}

LPCSTR vmsHtmlTagParser::getName() const
{
	return m_strName.c_str ();
}
