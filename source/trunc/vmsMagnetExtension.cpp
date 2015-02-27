/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "vmsMagnetExtension.h"
#include "vmsFileExtensionInOs.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsMagnetExtension::vmsMagnetExtension()
{

}

vmsMagnetExtension::~vmsMagnetExtension()
{

}

BOOL vmsMagnetExtension::Associate()
{
	AssociationParameters ap;
	ap.tstrShellOpenCmdLine = get_ShellOpenCommandLine ();
	ap.bUrlProtocolSpecified = true;
	return AssociateWith (ap);
}

fsString vmsMagnetExtension::get_ShellOpenCommandLine()
{
	fsString str = _T("\"");

	TCHAR szAppFileName[MAX_PATH] = {0,};
	::GetModuleFileName(NULL, szAppFileName, MAX_PATH);
	szAppFileName[MAX_PATH - 1] = 0; 
	
	str += szAppFileName;

	str += _T("\" \"%1\"");
	return str;
}

BOOL vmsMagnetExtension::IsAssociationExist()
{
	AssociationParameters ap = GetCurrentAssociation ();
	return !ap.tstrShellOpenCmdLine.empty () || ap.bUrlProtocolSpecified;
}

BOOL vmsMagnetExtension::IsAssociatedWithUs()
{
	AssociationParameters ap = GetCurrentAssociation ();
	return ap.bUrlProtocolSpecified && ap.tstrUrlProtocol.empty () && 
		!_tcsicmp (ap.tstrShellOpenCmdLine.c_str (), get_ShellOpenCommandLine ());
}

vmsMagnetExtension::AssociationParameters vmsMagnetExtension::GetCurrentAssociation()
{
	AssociationParameters ap;
	ap.tstrShellOpenCmdLine = vmsFileExtensionInOs::GetAssociation (_T("Magnet"), _T("open"), FALSE);
	ap.bUrlProtocolSpecified = false;
	CRegKey key;
	if (ERROR_SUCCESS == vmsFileExtensionInOs::OpenAssociationKey (key, _T ("Magnet"), false, KEY_READ))
	{
		TCHAR tszValue [MAX_PATH] = _T (""); ULONG nTmp = _countof (tszValue);
		if (ERROR_SUCCESS == key.QueryStringValue (_T ("URL Protocol"), tszValue, &nTmp))
		{
			ap.bUrlProtocolSpecified = true;
			ap.tstrUrlProtocol = tszValue;
		}
	}
	return ap;
}

BOOL vmsMagnetExtension::AssociateWith(const AssociationParameters& ap)
{
	if (!ap.tstrShellOpenCmdLine.empty ())
	{
		BOOL bOK = vmsFileExtensionInOs::SetAssociation (_T("Magnet"), _T("open"), ap.tstrShellOpenCmdLine.c_str (), FALSE);
		if (bOK)
		{
			CRegKey key;
			if (ERROR_SUCCESS == vmsFileExtensionInOs::OpenAssociationKey (key, _T ("Magnet"), true, KEY_WRITE))
			{
				if (ap.bUrlProtocolSpecified)
					key.SetStringValue (_T ("URL Protocol"), ap.tstrUrlProtocol.c_str ());
				else
					key.DeleteValue (_T ("URL Protocol"));
			}
			else
			{
				bOK = FALSE;
			}
		}
		return bOK;
	}
	else
	{
		CRegKey key;
		LONG lRes;
		if (ERROR_SUCCESS != (lRes=key.Open (HKEY_CLASSES_ROOT, _T(""), KEY_READ | KEY_WRITE)))
		{
			SetLastError (lRes);
			return FALSE;
		}
		lRes = key.RecurseDeleteKey (_T("Magnet"));
		if (lRes != ERROR_SUCCESS)
			SetLastError (lRes);
		return lRes == ERROR_SUCCESS;
	}
}

BOOL vmsMagnetExtension::CheckAccessRights ()
{
	CRegKey key;
	LONG lRes = key.Create (HKEY_CLASSES_ROOT, _T ("{C2B9E2CF-1BC9-4672-A267-9DE96290C56F}"));
	if (lRes == ERROR_SUCCESS)
	{
		key.Close ();
		RegDeleteKey (HKEY_CLASSES_ROOT, _T ("{C2B9E2CF-1BC9-4672-A267-9DE96290C56F}"));
		return TRUE;
	}
	return lRes != ERROR_ACCESS_DENIED;
}