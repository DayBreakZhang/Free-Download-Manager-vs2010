/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "vmsTorrentExtension.h"
#include "vmsFileExtensionInOs.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsTorrentExtension::vmsTorrentExtension()
{

}

vmsTorrentExtension::~vmsTorrentExtension()
{

}

BOOL vmsTorrentExtension::Associate()
{
	return AssociateWith (get_ShellOpenCommandLine ());
}

fsString vmsTorrentExtension::get_ShellOpenCommandLine()
{
	fsString str = "\"";
	str += ((CFdmApp*)AfxGetApp ())->m_strAppPath;
	if (str [str.GetLength () - 1] != '\\')
		str += '\\';
	str += "fdm.exe\" \"%1\"";
	return str;
}

BOOL vmsTorrentExtension::IsAssociationExist()
{
	return GetCurrentAssociation ().IsEmpty () == FALSE;
}

BOOL vmsTorrentExtension::IsAssociatedWithUs()
{
	return stricmp (vmsFileExtensionInOs::GetAssociation ("torrent", "open"),
		get_ShellOpenCommandLine ()) == 0;
}

fsString vmsTorrentExtension::GetCurrentAssociation()
{
	return vmsFileExtensionInOs::GetAssociation ("torrent", "open");
}

BOOL vmsTorrentExtension::AssociateWith(LPCSTR pszCmdLine)
{
	if (pszCmdLine && *pszCmdLine)
	{
		return vmsFileExtensionInOs::SetAssociation ("torrent", "open", pszCmdLine);
	}
	else
	{
		CRegKey key;
		LONG lRes;
		if (ERROR_SUCCESS != (lRes=key.Open (HKEY_CLASSES_ROOT, "", KEY_READ | KEY_WRITE)))
		{
			SetLastError (lRes);
			return FALSE;
		}
		lRes = key.RecurseDeleteKey (".torrent");
		if (lRes != ERROR_SUCCESS)
			SetLastError (lRes);
		return lRes == ERROR_SUCCESS;
	}
}

BOOL vmsTorrentExtension::CheckAccessRights ()
{
	CRegKey key;
	LONG lRes = key.Create (HKEY_CLASSES_ROOT, _T ("{C2B9E2CF-1BC9-4672-A277-9DE96290C56F}"));
	if (lRes == ERROR_SUCCESS)
	{
		key.Close ();
		RegDeleteKey (HKEY_CLASSES_ROOT, _T ("{C2B9E2CF-1BC9-4672-A277-9DE96290C56F}"));
		return TRUE;
	}
	return lRes != ERROR_ACCESS_DENIED;
}