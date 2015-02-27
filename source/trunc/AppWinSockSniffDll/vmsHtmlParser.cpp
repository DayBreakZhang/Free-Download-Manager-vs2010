/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsHtmlParser.h"
#include "vmsHtmlTagParser.h"
#include "shlwapi.h"

vmsHtmlParser::vmsHtmlParser()
{

}

vmsHtmlParser::~vmsHtmlParser()
{

}

void vmsHtmlParser::getTagHead(LPCSTR pszTag, string &strResult)
{
	vmsHtmlTagParser tp;
	int len = tp.Parse (pszTag);

	if (len)
		strResult.assign (pszTag, len);
	else
		strResult = "";
}

int vmsHtmlParser::findTag(LPCSTR pszHtml, LPCSTR pszTagName)
{
	string strTag = "<";
	strTag += pszTagName;
	
	
	
	LPCSTR pszTag = StrStrIA (pszHtml, strTag.c_str ());
	
	if (!pszTag)
		return -1;

	return pszTag - pszHtml;
}

void vmsHtmlParser::findAllTagsHeads(LPCSTR pszHtml, LPCSTR pszTagName, vector <string> &vTagsHeads)
{
	vTagsHeads.clear ();

	int nTagPos;
	
	while (*pszHtml)
	{
		nTagPos = findTag (pszHtml, pszTagName);
		if (nTagPos == -1)
			break;

		pszHtml += nTagPos;
		
		string str;
		getTagHead (pszHtml, str);

		if (!str.empty ())
		{
			vTagsHeads.push_back (str);
			pszHtml += str.length ();
		}
		else
		{
			
			pszHtml++;
		}		
	}
}

void vmsHtmlParser::DecodeHtmlSpecEntites(LPCSTR psz, string &strResult)
{
	strResult = "";

	if (!psz)
		return;

	strResult.reserve (strlen (psz) + 1);

	while (*psz)
	{
		if (*psz != '&')
		{
			strResult += *psz++;
			continue;
		}

		if (psz [1] == '#' && isdigit ((BYTE)psz [2]))
		{
			int chNum = atoi (psz + 2);
			psz += 3;
			while (isdigit ((BYTE)*psz))
				psz++;
			assert (*psz == ';');
			if (*psz == ';')
				psz++;
			if (chNum && chNum < 256) 
				strResult += (char)chNum;
		}

		else if (psz [1] == '#' && psz [2] == 'x' && isdigit ((BYTE)psz [3]))
		{
			int chNum; sscanf (psz + 3, "%x", &chNum);
			psz += 4;
			while (isdigit ((BYTE)*psz))
				psz++;
			assert (*psz == ';');
			if (*psz == ';')
				psz++;
			if (chNum && chNum < 256) 
				strResult += (char)chNum;
		}

		else if (!strncmp (psz+1, "quot;", 5))
		{
			strResult += '"';
			psz += 6; 
		}

		else if (!strncmp (psz+1, "amp;", 4))
		{
			strResult += '&';
			psz += 5;
		}

		else if (!strncmp (psz+1, "lt;", 3))
		{
			strResult += '<';
			psz += 4;
		}

		else if (!strncmp (psz+1, "gt;", 3))
		{
			strResult += '>';
			psz += 4;
		}

		else 
		{
			strResult += '&'; 
			psz++;
		}
	}
}
