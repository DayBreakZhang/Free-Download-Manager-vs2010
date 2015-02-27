/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "vms7zipArchive.h"

#pragma warning (disable: 4005 310 244)
#define INITGUID
#include <objbase.h>

#define BoolToBOOL(b) ((BOOL)b)
#define BOOLToBool(b) (0 != b)
#define VARIANT_BOOLToBool(v) (v != VARIANT_FALSE)
#include <archive\Defs.h>
#include <archive\IArchive.h>
#include <archive\FileStreams.h>
#include <archive\FileStreams.cpp>
#include <archive\FileIO.cpp>
#include <archive\MyWindows.cpp>
#include <archive\String.cpp>
#include <archive\StringConvert.cpp>
#include <archive\Vector.cpp>
#include <archive\PropVariant.h>
#include <archive\PropVariant.cpp>
#include <archive\PropVariantConversions.h>
#include <archive\PropVariantConversions.cpp>
#include <archive\IntToString.cpp>
#include "vms7zipArchiveExtractCallback.h"

bool g_IsNT = false;
static bool IsItWindowsNT()
{
  OSVERSIONINFO versionInfo;
  versionInfo.dwOSVersionInfoSize = sizeof(versionInfo);
  if (!::GetVersionEx(&versionInfo)) 
    return false;
  return (versionInfo.dwPlatformId == VER_PLATFORM_WIN32_NT);
}

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vms7zipArchive::vms7zipArchive()
{
	g_IsNT = IsItWindowsNT ();
}

vms7zipArchive::~vms7zipArchive()
{

}

bool vms7zipArchive::Extract(LPCSTR pszArchive, LPCSTR pszOutFolder)
{
	CInFileStream *fileSpec = new CInFileStream;
	CMyComPtr <IInStream> spFile = fileSpec;

	m_errExtract = AEE_GENERIC_ERROR;

	if (false == fileSpec->Open(pszArchive))
		return false;

	CMyComPtr <IInArchive> spArc;

	vms7zipFormatDLL dll;
	if (false == Find7zipDLL (dll, pszArchive, true, spFile, spArc) &&
			false == Find7zipDLL (dll, pszArchive, false, spFile, spArc))
		return false; 

	m_errExtract = AEE_NO_ERROR;

	char sz [MY_MAX_PATH];
	fsGetFileName (pszArchive, sz);

	vms7zipArchiveExtractCallback aec (spArc, pszOutFolder, m_pAC, sz);
	HRESULT hr;
	if (FAILED (hr=spArc->Extract (NULL, (UInt32)-1, 0, &aec))) {
		spArc = NULL;
		m_errExtract = aec.is_AbortedByUser () ? AEE_ABORTED_BY_USER : AEE_GENERIC_ERROR;
		return false;
	}

	spArc = NULL;

	if (*aec.get_FurtherExtractFile () != 0) {
		
		bool b = Extract (aec.get_FurtherExtractFile (), pszOutFolder);
		DeleteFile (aec.get_FurtherExtractFile ());
		return b;
	}

	return true;
}

bool vms7zipArchive::Find7zipDLL(vms7zipFormatDLL &dll, LPCSTR pszArchive, bool bByExt, CMyComPtr <IInStream> &spFile, CMyComPtr <IInArchive> &spArc)
{
	WIN32_FIND_DATA wfd;
	HANDLE hFind = FindFirstFile ("Archive\\7-zip\\Formats\\*.dll", &wfd);
	if (hFind == INVALID_HANDLE_VALUE)
		return false;

	bool bFound = false;

	do
	{
		CString str = "Archive\\7-zip\\Formats\\"; str += wfd.cFileName;
		if (false == dll.Load (str))
			continue;
		
		if (bByExt && false == dll.IsSupportedArchive (pszArchive))
			continue;

		GUID guid;
		if (FAILED (dll.get_GUID (&guid)))
			continue;

		dll.CreateObject (&guid, &IID_IInArchive, (void**) &spArc);
		if (spArc == NULL)
			continue;

		spFile->Seek (0, STREAM_SEEK_SET, NULL);

		

		if (spArc->Open (spFile, 0, 0) == S_OK)
			bFound = true; 
		else
			spArc = NULL;
	}
	while (bFound == false && FindNextFile (hFind, &wfd));

	FindClose (hFind);

	return bFound;
}
