/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __TP_DOWNLOAD_MGR_H_
#define __TP_DOWNLOAD_MGR_H_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsDll.h"
#include "msdl\TransferProtocolDownloader.h"
#include "vmsDownloadMgrEx.h"
#include "vmsCriticalSection.h"	
#include "fsInternetDownloader.h"
#include "vmsPersistObject.h"

typedef DWORD fsDownloadState;
#define DS_STOPPED			1	
#define DS_DOWNLOADING		2	
#define DS_NEEDSTART		4	
#define DS_NEEDSTOP			8	
#define DS_DONE				16	
#define DS_NEEDADDSECTION	32	
#define DS_NEEDRESTARTFROM	64	
#define DS_QUERINGSIZE		128	
#define DS_NEEDADDSECTION2	256	
#define DS_RESERVINGSPACE	512	

typedef DWORD (*fntTpDownloadManagerEventHandler)(class vmsTpDownloadMgr*, fsDownloaderEvent, UINT, LPVOID);

typedef void (*fntTpDownloadManagerEventDescFunc)(class vmsTpDownloadMgr*, fsDownloadMgr_EventDescType enType, LPCSTR pszDesc, LPVOID lp);

class vmsTpDownloadMgr : public vmsPersistObject
{
public:
	vmsTpDownloadMgr();
	virtual ~vmsTpDownloadMgr();

	fsInternetResult StartDownloading(BOOL bNeedFile = TRUE);
	fsInternetResult RestartDownloading();
	fsInternetResult SetToRestartState();
	void StopDownloading();
	BOOL IsRunning();
	BOOL DeleteFile();

	TransferProtocolDownloader* CreateTransferProtocolDownloader();

	fsString get_URL();

	BOOL CreateTPDownload (LPCSTR pszUrl, LPCSTR pszOutputPath, LPCSTR pszFileName, int nStreamingSpeed = 1);

	UINT GetSpeed();
	BOOL IsDone();
	BOOL IsCantStart();
	BOOL IsDownloading();

	fsString get_OutputFilePathName();
	fsString get_FileName();
	fsString get_OutputPath();

	float GetPercentDone(bool bSetDirtyFlag = true);
	int get_ConnectionCount();
	TransportProtocolStateEx get_State();
	LPCSTR vmsTpDownloadMgr::get_LastError();

	void SetEventsHandler (fntTpDownloadManagerEventHandler pfn, LPVOID pData);
	void SetEventDescFunc (fntTpDownloadManagerEventDescFunc pfn, LPVOID lpParam);
	void GetSectionInfo(int nIndex, vmsSectionInfo *sect);

	UINT64 GetTotalFilesSize(bool bSetDirtyFlag = true);
	UINT64 GetDownloadedBytesCount(bool bSetDirtyFlag = true);
	int GetNumberOfSections(bool bSetDirtyFlag = true);
	int GetDownloadingSectionCount();
	int GetStreamingSpeed(bool bSetDirtyFlag = true);
	
	BOOL LoadState(LPBYTE lpBuffer, LPDWORD pdwSize, WORD wVer);
	
	BOOL MoveToFolder (LPCSTR pszFolder);
	BOOL MoveFile (LPCSTR pszNewFileName);
	BOOL IsFileInit();

	DWORD get_Flags();
	void enable_Flags(DWORD dw);
	void disable_Flags(DWORD dw);
	
	BOOL SleepInterval();

	BOOL ApplyAER (fsAlreadyExistReaction enAER, bool bFirstCheck = true);
	
	
	
	
	void RenameFile(BOOL bFormat1 = TRUE);
	BOOL CheckDstFileExists();
	bool m_bDontQueryStoringDownloadList;

	
	void getObjectItselfStateBuffer(LPBYTE pb, LPDWORD pdwSize, bool bSaveToStorage);
	bool loadObjectItselfFromStateBuffer(LPBYTE pb, LPDWORD pdwSize, DWORD dwVer);

protected:
	
	DWORD RaiseEvent (fsDownloaderEvent ev, DWORD dw = 0);	
	
	void RaiseEvent (LPCSTR pszEvent, fsDownloadMgr_EventDescType enType = EDT_INQUIRY);
	
	fntTpDownloadManagerEventHandler m_pfnEvHandler;
	LPVOID m_lpEvParam;
	fntTpDownloadManagerEventDescFunc m_pfnEventDesc;	
	LPVOID m_lpEventDescParam;			

	vmsCriticalSection m_csDownload;
	bool m_bDlThreadNeedStop;
	static std::string getTPDllFileName(void);
	bool LoadTPDll (vmsDLL& dll);

	TransferProtocolDownloader* m_dldr;	
	BOOL m_bThreadRunning;	
	static DWORD WINAPI _threadDownloadMgr (LPVOID lp);
	vmsDLL m_dllTPD;
	TransportProtocolStateEx m_state;	

	UINT m_uRetryTime;			

	BOOL m_bRename_CheckIfRenamed;
	fsAlreadyExistReaction m_enAER;

	struct _inc_BtDownloadInfo
	{
		float *pfProgress;
		fsTicksMgr timeLastDataStatAccess;
		LPBYTE pbFastResumeData; DWORD dwFastResumeDataSize;
		fsString strOutputPath;
		fsString strFileName;
		fsString strTrackerUser, strTrackerPassword;
		fsString strTorrentUrl;
		DWORD dwFlags;
		fsString strLastTracker;
		UINT64 nUploadedBytes;
		double fShareRating;
		UINT64 nWastedBytes;
		float fPercentDone;
		BOOL bDone;
		std::vector <bool> vPieces; 
		UINT64 nDownloadedBytes;
		std::vector <BYTE> vFilesPriorities;

		UINT64 nFileSize;
		int nNumSections;
		int nStreamingSpeed;
	};
	_inc_BtDownloadInfo m_info;
};

#endif