/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __DOWNLOADER_LIB
#define __DOWNLOADER_LIB

typedef void*  DLHANDLE;

enum vmsdl_DownloadState
{
	DL_S_CONNECTING,
	DL_S_DOWNLOADING,
	DL_S_STOPPED,
	DL_S_DONE,
	DL_S_FAILED,	
	DL_S_ERROR_NOW,
};

extern BOOL		vmsdl_InitializeLibrary ();
extern DLHANDLE	vmsdl_CreateDownloader (LPCSTR pszURL, LPCSTR pszOutFile);
extern void		vmsdl_SetProxy (DLHANDLE h, LPCSTR pszProxy, LPCSTR pszUser, LPCSTR pszPassword);
extern void		vmsdl_SetMaxRetryCount (DLHANDLE h, int nValue);

extern void		vmsdl_SetRetriesTime (DLHANDLE h, int nValue);

extern void		vmsdl_SetTimeout (DLHANDLE h, int nValue);
extern void		vmsdl_ReleaseDownloader (DLHANDLE);
extern void		vmsdl_StartDownloading (DLHANDLE);
extern void		vmsdl_StopDownloading (DLHANDLE);
extern int		vmsdl_GetProgress (DLHANDLE);
extern	vmsdl_DownloadState vmsdl_GetState (DLHANDLE);
extern	tstring vmsdl_GetLastErrorMessage (DLHANDLE);
extern UINT		vmsdl_GetDownloadingSpeed (DLHANDLE);
extern UINT64	vmsdl_GetFileSize (DLHANDLE);
extern UINT64	vmsdl_GetDownloadedByteCount (DLHANDLE);
extern void vmsdl_DisableCookies (DLHANDLE h, BOOL bDisable);
extern void vmsdl_SetUserAgent (DLHANDLE h, LPCSTR pszAgent);
extern void vmsdl_SetMaxSections(DLHANDLE h, UINT uiMaxSections);
extern void vmsdl_SetMinSectionSize(DLHANDLE h, UINT uiMinSectionSize);
extern LPCTSTR	vmsdl_GetDstFilePathName (DLHANDLE h);
extern LPCSTR	vmsdl_GetContentType (DLHANDLE h);
extern void vmsdl_DumpDownload(DLHANDLE h, LPBYTE pbBuffer, LPDWORD pdwSize);
extern bool vmsdl_LoadDownload(DLHANDLE h, LPBYTE pbBuffer, LPDWORD pdwSize, WORD wVer);
extern WORD vmsdl_GetVersion();
extern void vmsdl_SetResumeMode(DLHANDLE h);
extern bool vmsdl_IsDone(DLHANDLE h);
extern std::string vmsdl_GetDestinationFile(DLHANDLE h);

#endif