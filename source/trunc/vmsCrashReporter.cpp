/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsCrashReporter.h"
#include "vmsPostRequest.h"
#include "vmsZip.h"
#include "vmsXmlHelper.h"

vmsCrashReporter::vmsCrashReporter(void)
{
}

vmsCrashReporter::~vmsCrashReporter(void)
{
}

bool vmsCrashReporter::SubmitDumpToServer(LPCTSTR ptszServerAddr, LPCTSTR ptszScriptPath, LPCTSTR ptszDumpFileName, LPCSTR pszXml)
{
	vmsZip zip;

	TCHAR tszTmpFile [MAX_PATH] = _T ("");
	TCHAR tszTmpPath [MAX_PATH] = _T ("");
	GetTempPath (MAX_PATH, tszTmpPath);
	GetTempFileName (tszTmpPath, _T ("tmp"), 0, tszTmpFile);

	if (FALSE == zip.CreateNewZipFile (tszTmpFile))
	{
		DeleteFile (tszTmpFile);
		return false;
	}

	if (!zip.AddFile (ptszDumpFileName, _T ("dump.dmp")) || 
			!zip.AddBuffer (pszXml, (DWORD)strlen (pszXml), _T ("details.xml")))
	{
		zip.CloseZipFile ();
		DeleteFile (tszTmpFile);
		return false;
	}

	zip.CloseZipFile ();

	HANDLE hZip = CreateFile (tszTmpFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
	if (hZip == INVALID_HANDLE_VALUE)
		return FALSE;
	DWORD dwZipSize = GetFileSize (hZip, NULL);
	std::auto_ptr <BYTE> apbZip (new BYTE [dwZipSize]);
	ReadFile (hZip, apbZip.get (), dwZipSize, &dwZipSize, NULL);
	CloseHandle (hZip);
	DeleteFile (tszTmpFile);		

	vmsPostRequest req;

	onInitializePostRequest (req);

	req.AddPart ("zipfile", "report.zip", apbZip.get (), dwZipSize);
	req.AddPart ("Submit", NULL, "Submit", 6);

	return req.SendMultipart (ptszServerAddr, ptszScriptPath) != FALSE;
}

void vmsCrashReporter::GenerateXml (LPCTSTR ptszAppName, LPCTSTR ptszVersion, LPCTSTR ptszDescription, LPCTSTR ptszFaultModule, DWORD_PTR dwpCrashAddr, LPCSTR pszAdditionalXmlData, std::string& strResult)
{
	strResult = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n";
	
	strResult += "<CrashDumpInfo>\r\n";

	strResult += "<Application Name=\""; strResult += vmsXmlHelper::toUtf8 (ptszAppName);
	strResult += "\" Version=\""; strResult += vmsXmlHelper::toUtf8 (ptszVersion);
	strResult += "\" Platform=\"";
#ifdef _WIN64
	strResult += "x64";
#else
	strResult += "x32";
#endif
	strResult += "\" />\r\n";

	strResult += "<Description>"; strResult += vmsXmlHelper::toUtf8 (ptszDescription);
	strResult += "</Description>\r\n";

	if (ptszFaultModule)
	{
		strResult += "<FaultModule Name=\""; strResult += vmsXmlHelper::toUtf8 (ptszFaultModule); 
		strResult += "\" Address=\"0x";
		char sz [100] = "";
		sprintf_s <100> (sz, "%I64x", (UINT64)dwpCrashAddr);
		strResult += sz; strResult += "\" />\r\n";
	}

	if (pszAdditionalXmlData && *pszAdditionalXmlData)
		strResult += pszAdditionalXmlData;

	strResult += "</CrashDumpInfo>\r\n";
}