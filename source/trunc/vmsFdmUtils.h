/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once
#include "vmsMagnetExtension.h"
class vmsFdmUtils
{
public:
	static bool AssociateFdmWithMagnetLinks (bool bAssociate)
	{
		if (!bAssociate && vmsMagnetExtension::IsAssociatedWithUs ())
		{
			vmsMagnetExtension::AssociationParameters ap;
			ap.tstrShellOpenCmdLine = _App.Bittorrent_OldMagnetAssociation ();
			ap.tstrUrlProtocol = _App.Bittorrent_OldMagnetUrlProtocol ();
			ap.bUrlProtocolSpecified = ap.tstrUrlProtocol != _T ("-");
			return FALSE != vmsMagnetExtension::AssociateWith (ap);
		}
		else if (bAssociate && !vmsMagnetExtension::IsAssociatedWithUs ())
		{
			vmsMagnetExtension::AssociationParameters ap = vmsMagnetExtension::GetCurrentAssociation ();
			if (!_tcsicmp (ap.tstrShellOpenCmdLine.c_str (), vmsMagnetExtension::get_ShellOpenCommandLine ()))
			{
				_App.Bittorrent_OldMagnetAssociation (ap.tstrShellOpenCmdLine.c_str ());
				_App.Bittorrent_OldMagnetUrlProtocol (ap.bUrlProtocolSpecified ? ap.tstrUrlProtocol.c_str () : _T ("-"));
			}
			else
			{
				_App.Bittorrent_OldMagnetAssociation (_T (""));
				_App.Bittorrent_OldMagnetUrlProtocol (_T ("-"));
			}
			return FALSE != vmsMagnetExtension::Associate ();
		}

		return true;
	}
};

