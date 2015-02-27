/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once
class vmsFdmFilesDeleter
{
public:
	vmsFdmFilesDeleter(void);
	~vmsFdmFilesDeleter(void);
	static bool DeleteBrowserPluginFiles(std::vector <std::auto_ptr <vmsBrowserPluginFileDeleter> >& vFiles);
protected:
	static bool onBrowserPluginFileDeleteError(vmsFileDeleter* pDeleter);
};

