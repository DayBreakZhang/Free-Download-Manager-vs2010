/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once
#include "vmsFileDeleter.h"
#include "vmsKnownBrowsers.h"
class vmsBrowserPluginFileDeleter : public vmsFileDeleter
{
public:
	vmsBrowserPluginFileDeleter(vmsKnownBrowsers::Browser enBrowser, LPCTSTR ptszFile, DWORD dwDeleteFileError = 0) : 
		vmsFileDeleter (ptszFile, dwDeleteFileError), m_enBrowser (enBrowser)
	{
	}

	~vmsBrowserPluginFileDeleter(void)
	{
	}

	vmsKnownBrowsers::Browser getBrowser () const {return m_enBrowser;}

protected:
	vmsKnownBrowsers::Browser m_enBrowser;
};

