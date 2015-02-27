#ifndef __FDMDL_H_
#define __FDMDL_H_

enum vmsFdmApiDownloadState
{
	// has a hourglass icon
	FADS_QUEUED,
	// stopped due to a fatal error or user's choice
	FADS_STOPPED,
	// connecting to server, etc.
	FADS_STARTING,
	// downloading data
	FADS_DOWNLOADING,
	// download was completed successfully
	FADS_FINISHED,
	// an error, trying to resume downloading...
	FADS_HAVING_ERROR,
	// this download does not exist anymore because it was deleted from list
	FADS_WAS_DELETED,
};

enum vmsFdmApiDownloadCommand
{
	FADC_START,
	FADC_STOP,
	FADC_OPEN_FOLDER,
	FADC_LAUNCH_FILE,
	// download should not be running (i.e. in starting or downloading states) 
	// to perform the restart.
	FADC_RESTART,
};

class vmsFdmApiDownload
{
public:
	virtual vmsFdmApiDownloadState getState () = NULL;
	virtual void PerformCommand (vmsFdmApiDownloadCommand enCmd) = NULL;
	virtual void DeleteDownload (BOOL bAskConfirmation) = NULL;
	virtual void DeleteFileOnDisk () = NULL;
	// pszFileName, out - pointer to buffer that will be filled in with the full path name
	// it should be large enough
	virtual void getFileName (LPSTR pszFileName) = NULL;	
	virtual void getUrl (LPSTR pszUrl) = NULL;
	virtual float getProgress () = NULL;
	virtual UINT getId () = NULL;
};

#endif //__FDMDL_H_