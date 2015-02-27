/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __FDMDL_H_
#define __FDMDL_H_

enum vmsFdmApiDownloadState
{
	
	FADS_QUEUED,
	
	FADS_STOPPED,
	
	FADS_STARTING,
	
	FADS_DOWNLOADING,
	
	FADS_FINISHED,
	
	FADS_HAVING_ERROR,
	
	FADS_WAS_DELETED,
};

enum vmsFdmApiDownloadCommand
{
	FADC_START,
	FADC_STOP,
	FADC_OPEN_FOLDER,
	FADC_LAUNCH_FILE,
	
	
	FADC_RESTART,
};

class vmsFdmApiDownload
{
public:
	virtual vmsFdmApiDownloadState getState () = NULL;
	virtual void PerformCommand (vmsFdmApiDownloadCommand enCmd) = NULL;
	virtual void DeleteDownload (BOOL bAskConfirmation) = NULL;
	virtual void DeleteFileOnDisk () = NULL;
	
	
	virtual void getFileName (LPSTR pszFileName) = NULL;	
	virtual void getUrl (LPSTR pszUrl) = NULL;
	virtual float getProgress () = NULL;
	virtual UINT getId () = NULL;
};

#endif 