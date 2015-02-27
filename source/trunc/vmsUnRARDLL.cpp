/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "vmsUnRARDLL.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsUnRARDLL::vmsUnRARDLL(LPCSTR pszDll) :
	vmsDLL (pszDll)
{
	m_pfnRAROpenArchiveEx = NULL;
	m_pfnRARSetCallback = NULL;
	m_pfnRARReadHeader = NULL;
	m_pfnRARProcessFile = NULL;
	m_pfnRARCloseArchive = NULL;
}

vmsUnRARDLL::~vmsUnRARDLL()
{

}

bool vmsUnRARDLL::Load(LPCSTR pszDll)
{
	if (false == vmsDLL::Load (pszDll))
		return false;

	m_pfnRAROpenArchiveEx = (FNRAROAEX) GetProcAddress ("RAROpenArchiveEx");
	m_pfnRARSetCallback = (FNRARSC) GetProcAddress ("RARSetCallback");
	m_pfnRARReadHeader = (FNRARRH) GetProcAddress ("RARReadHeader");
	m_pfnRARProcessFile = (FNRARPF) GetProcAddress ("RARProcessFile");
	m_pfnRARCloseArchive = (FNRARCA) GetProcAddress ("RARCloseArchive");

	return true;
}

void vmsUnRARDLL::Free()
{
	m_pfnRAROpenArchiveEx = NULL;
	m_pfnRARSetCallback = NULL;
	m_pfnRARReadHeader = NULL;
	m_pfnRARProcessFile = NULL;
	m_pfnRARCloseArchive = NULL;
	vmsDLL::Free ();
}

HANDLE vmsUnRARDLL::RAROpenArchiveEx(RAROpenArchiveDataEx *ArchiveData)
{
	if (m_pfnRAROpenArchiveEx == NULL)
		return NULL;

	return m_pfnRAROpenArchiveEx (ArchiveData);
}

void vmsUnRARDLL::RARSetCallback(HANDLE hArcData, UNRARCALLBACK Callback, LONG UserData)
{
	if (m_pfnRARSetCallback == NULL)
		return;

	m_pfnRARSetCallback (hArcData, Callback, UserData);
}

int vmsUnRARDLL::RARReadHeader(HANDLE hArcData, RARHeaderData *HeaderData)
{
	if (m_pfnRARReadHeader == NULL)
		return 0;

	return m_pfnRARReadHeader (hArcData, HeaderData);
}

int vmsUnRARDLL::RARProcessFile(HANDLE hArcData, int Operation, char *DestPath, char *DestName)
{
	if (m_pfnRARProcessFile == NULL)
		return 0;

	return m_pfnRARProcessFile (hArcData, Operation, DestPath, DestName);
}

int vmsUnRARDLL::RARCloseArchive(HANDLE hArcData)
{
	if (m_pfnRARCloseArchive == NULL)
		return 0;

	return m_pfnRARCloseArchive (hArcData);
}
