/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsFirefoxExtensionInstaller.h"
#include "vmsFirefoxUtil.h"
#include "vmsFile.h"
#include "vmsLogger.h"

using namespace vmsFDM;

vmsFirefoxExtensionInstaller::vmsFirefoxExtensionInstaller()
{

}

vmsFirefoxExtensionInstaller::~vmsFirefoxExtensionInstaller()
{

}

bool vmsFirefoxExtensionInstaller::Do(LPCSTR pszCID, LPCSTR pszExtPath, bool bInstall)
{
	FU_STRINGLIST v; int nDefProf;
	vmsFirefoxUtil::GetProfilesPathes (v, nDefProf);

	CString str = _App.Firefox_PortableVersionPath ();
	if (!str.IsEmpty ())
	{
		fsString str2 = (LPCSTR)(str + "\\data\\profile");
		char sz [MY_MAX_PATH];
		GetModuleFileName (NULL, sz, MY_MAX_PATH);
		str2 [0] = sz [0];
		v.add (str2);
	}

	if (v.size () == 0)
		return false;

	for (int i = 0; i < v.size (); i++)
	{
		char sz [MY_MAX_PATH];
		lstrcpy (sz, v [i]);
		lstrcat (sz, "\\extensions\\");
		lstrcat (sz, pszCID);

		if (bInstall)
		{
			fsBuildPathToFile (sz);

			try
			{
				vmsFile file;
				file.Create (sz, GENERIC_WRITE, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL);
				file.Write (pszExtPath, lstrlen (pszExtPath));
				file.Close ();
			}
			catch (const std::exception& ex)
			{
				ASSERT (FALSE);
				vmsLogger::WriteLog("vmsFirefoxExtensionInstaller::Do " + tstring(ex.what()));
				return false;
			}
			catch (...)
			{
				ASSERT (FALSE);
				vmsLogger::WriteLog("vmsFirefoxExtensionInstaller::Do unknown exception");
				return false;
			}
		}
		else
		{
			DeleteFile (sz);
		}
	}

	return true;
}

bool vmsFirefoxExtensionInstaller::IsInstalled(LPCSTR pszCID, bool bInDefaultProfileOnly)
{
	FU_STRINGLIST v; int nDefaultProfile;
	vmsFirefoxUtil::GetProfilesPathes (v, nDefaultProfile);

	CString str = _App.Firefox_PortableVersionPath ();
	if (!str.IsEmpty ())
	{
		fsString str2 = (LPCSTR)(str + "\\data\\profile");
		char sz [MY_MAX_PATH];
		GetModuleFileName (NULL, sz, MY_MAX_PATH);
		str2 [0] = sz [0];
		v.add (str2);
	}

	if (v.size () == 0)	
		return false;

	if (nDefaultProfile == -1 || nDefaultProfile >= v.size ())
		bInDefaultProfileOnly = false;

	for (int i = 0; i < v.size (); i++)
	{
		if (bInDefaultProfileOnly && i != nDefaultProfile)
			continue;

		char sz [MY_MAX_PATH];
		lstrcpy (sz, v [i]);
		lstrcat (sz, "\\extensions\\");
		lstrcat (sz, pszCID);

		if (GetFileAttributes (sz) != DWORD (-1))
			return true;
	}

	return false;
}

bool vmsFirefoxExtensionInstaller::ExtractExtensionInfo(LPCTSTR ptszRdf, tstring& tstrVersion)
{
	USES_CONVERSION;
	IXMLDOMDocumentPtr spXML;
	spXML.CreateInstance (__uuidof (DOMDocument));
	if (!spXML)
		return false;
	spXML->put_async (FALSE);
	VARIANT_BOOL bRes = FALSE;
	spXML->load (COleVariant (ptszRdf), &bRes);
	if (!bRes)
		return false;
	IXMLDOMNodePtr spRDF;
	spXML->selectSingleNode (L"RDF", &spRDF);
	if (!spRDF)
		return false;
	IXMLDOMNodePtr spDesc;
	spRDF->selectSingleNode (L"Description", &spDesc);
	if (!spDesc)
		return false;
	IXMLDOMNodePtr spVer;
	spDesc->selectSingleNode (L"em:version", &spVer);
	if (!spVer)
		return false;
	CComBSTR bstr;
	spVer->get_text (&bstr);
	tstrVersion = W2CT (bstr);
	return true;
}
