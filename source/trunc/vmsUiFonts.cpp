/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fdm.h"
#include "vmsUiFonts.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsUiFonts::vmsUiFonts()
{

}

vmsUiFonts::~vmsUiFonts()
{

}

CFont* vmsUiFonts::Tahoma_11underline()
{
	static CFont fnt; 
	if (fnt.m_hObject == NULL)
		fnt.CreateFont (-11, 0, 0, 0, FW_NORMAL, 0, TRUE, 0, DEFAULT_CHARSET, 0, 0, 0, 0, _T ("Tahoma"));
	return &fnt;
}

CFont* vmsUiFonts::Tahoma_11()
{
	static CFont fnt; 
	if (fnt.m_hObject == NULL)
		fnt.CreateFont (-11, 0, 0, 0, FW_NORMAL, 0, FALSE, 0, DEFAULT_CHARSET, 0, 0, 0, 0, _T ("Tahoma"));
	return &fnt;
}

CFont* vmsUiFonts::Tahoma_11bold()
{
	static CFont fnt; 
	if (fnt.m_hObject == NULL)
		fnt.CreateFont (-11, 0, 0, 0, FW_BOLD, 0, FALSE, 0, DEFAULT_CHARSET, 0, 0, 0, 0, _T ("Tahoma"));
	return &fnt;
}
