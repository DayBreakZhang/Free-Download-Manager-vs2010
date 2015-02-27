/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fdm.h"
#include "vmsStringParser.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsStringParser::vmsStringParser()
{

}

vmsStringParser::~vmsStringParser()
{

}

void vmsStringParser::GetWord(LPCTSTR &ptsz, tstring &tstr)
{
	tstr = _T ("");
	while (isWhiteChar (*ptsz))
		ptsz++;
	while (*ptsz && isWhiteChar (*ptsz) == false)
		tstr += *ptsz++;
}

bool vmsStringParser::isWhiteChar(TCHAR tch)
{
	return tch == ' ' || tch == '\t' || tch == '\r' || tch == '\n';
}

void vmsStringParser::GetTextBeforeChar(LPCTSTR &ptsz, TCHAR tch, tstring &tstr)
{
	tstr = _T ("");
	while (*ptsz && *ptsz != tch)
		tstr += *ptsz++;
}

void vmsStringParser::RemoveNonSpaceWhiteChars(tstring &tstr)
{
	for (int i = 0; i < (int)tstr.length (); i++)
	{
		if (isWhiteChar (tstr [i]))
		{
			if (tstr [i] == ' ')
				continue;
			else if (tstr [i] == '\t')
				tstr [i] = ' ';
			else
				tstr.erase (tstr.begin () + i--);
		}
	}
}

void vmsStringParser::SkipWhiteChars(LPCTSTR &ptsz)
{
	while (isWhiteChar (*ptsz))
		ptsz++;
}

void vmsStringParser::GetWordBeforeChar(LPCTSTR &ptsz, TCHAR tch, tstring &tstr)
{
	tstr = _T ("");
	while (*ptsz && *ptsz != tch && isWhiteChar (*ptsz) == false)
		tstr += *ptsz++;
}

void vmsStringParser::GetAlphaWord(LPCTSTR &ptsz, tstring &tstr)
{
	tstr = _T ("");
	while (isWhiteChar (*ptsz))
		ptsz++;
	while (_istalpha (*ptsz))
		tstr += *ptsz++;
}
