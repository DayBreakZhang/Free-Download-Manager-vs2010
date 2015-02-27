/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSDOWNLOADMGR_H__DE09A9F2_AF9D_41C0_A7D5_DEBF2CFDBA03__INCLUDED_)
#define AFX_FSDOWNLOADMGR_H__DE09A9F2_AF9D_41C0_A7D5_DEBF2CFDBA03__INCLUDED_

#include "fsInternetDownloader.h"	
#include "DownloadProperties.h"	
#include "fsTicksMgr.h"	
#include "vmsCriticalSection.h"	
#include "vmsPersistObject.h"

#if _MSC_VER > 1000
#pragma once
#endif 

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

enum fsDownloadMgr_ExtError 
{
	DMEE_FILEWASDELETED,	
	DMEE_STOPPEDORDONE,		
	
	
	DMEE_FATALERROR,	
	DMEE_FILEUPDATED,		
	DMEE_USERSTOP,			
	DMEE_STARTING,			
};

enum fsDownloadMgr_EventDescType
{
	EDT_INQUIRY,			
	EDT_RESPONSE_S,			
	EDT_RESPONSE_E,			
	EDT_DONE,				
	EDT_WARNING,			
	EDT_INQUIRY2,			
	EDT_RESPONSE_S2,		
};

typedef DWORD (*fntDownloadMgrEventFunc)(class fsDownloadMgr *pMgr, fsDownloaderEvent, UINT, LPVOID);

typedef void (*fntEventDescFunc)(fsDownloadMgr *pMgr, fsDownloadMgr_EventDescType enType, LPCSTR pszDesc, LPVOID lp);

#define DFF_NEED_INIT_FILE			1
#define DFF_USE_PORTABLE_DRIVE		2

class fsDownloadMgr : public vmsDownloaderWithNetworkUsageAdjustment, public vmsPersistObject
{
public:
	fsString getFileName();
	BOOL HasActivity();
	DWORD get_State();
	int get_ReservingDiskSpaceProgress();
	void AdjustKnownFileSharingSiteSupport();
	
	void Reset();
	
	fsString get_URL();
	
	BOOL MoveToFolder (LPCSTR pszFolder);
	BOOL MoveFile (LPCSTR pszNewFileName);
	
	static void set_GlobalOffline(BOOL bOffline);
	static BOOL is_GlobalOffline();
	
	void set_Download (struct fsDownload* dld);
	
	void RemoveHiddenAttribute();
	
	void MeasureMirrorsSpeed();
	
	fsInternetResult SetToRestartState ();
	
	fsInternetResult FindMirrors();
	
	void Set_MirrRecalcSpeedTime(UINT u);
	
	fsInternetResult StartDownloading();
	void StopDownloading();
	
	void CreateOneMoreSection();
	
	BOOL IsCantStart();
	
	void StopQuering();
	
	
	
	fsInternetResult QuerySize(BOOL bCheckPoss = TRUE);
	
	
	
	void QuerySize2 ();
	
	BOOL IsQueringSize();
	
	void StopSection();
	
	
	fsInternetResult RestartDownloading();
	
	BOOL IsSectionCanBeAdded();
	
	void CloseFile();
	
	BOOL IsFileInit();
	
	
	BOOL InitFile (BOOL bCreateOnDisk = FALSE, LPCSTR pszSetExt = NULL);
	
	fsInternetResult GetLastError();
	
	BOOL DeleteFile ();
	
	void ApplyProperties();
	
	BOOL IsRunning();
	
	BOOL IsDone();
	
	
	
	BOOL LoadState (LPVOID lpBuffer, LPDWORD pdwSize, WORD wVer);
	
	void CloneSettings (fsDownloadMgr* src);
	
	void SetEventDescFunc (fntEventDescFunc pfn, LPVOID lpParam);
	void SetEventFunc (fntDownloadMgrEventFunc pfnEvents, LPVOID lpParam);
	
	void SetOutputFileName (LPCSTR pszName);
	
	
	
	fsInternetResult CreateByUrl (LPCSTR pszUrl, BOOL bAcceptHTMLPathes = FALSE);
	fsInternetDownloader* GetDownloader();
	
	fsDownload_Properties* GetDP();
	
	fsDownload_NetworkProperties* GetDNP();
	
	void CreateCompleteDownload(UINT64 uFileSize);
	
	void AddSection(UINT64 uStart, UINT64 uEnd, UINT64 uCurrent);
	void SetFileSize(UINT64 uFileSize);
	DWORD GetDownloadFileFlag() const;
	void SetDownloadFileFlag(DWORD dwFlag);
	void getObjectItselfStateBuffer(LPBYTE pb, LPDWORD pdwSize, bool bSaveToStorage);
	bool loadObjectItselfFromStateBuffer(LPBYTE pb, LPDWORD pdwSize, DWORD dwVer);
	void SetParentPersistObjectSize(DWORD dwSize);

	bool IsFailedToCreateDestinationFile() const;
	bool IsNotEnoughDiskSpace() const;

	fsDownloadMgr (struct fsDownload* dld = NULL);
	virtual ~fsDownloadMgr();

protected:
	static DWORD WINAPI _threadReserveDiskSpace (LPVOID lp);
	BOOL m_bDontCreateNewSections;
	DWORD m_dwDownloadFileFlags;
	bool m_bKnownFileSharingSiteSupportAdjusted;
	
	void ProcessFilePathMacroses (CString &str);
	
	void InitFile_ProcessMacroses();
        #ifndef FDM_DLDR__RAWCODEONLY
	class vmsMaliciousDownloadChecker *m_mdc;
	
	BOOL CheckIfMalicious ();
	#endif
	
	static vmsCriticalSectionEx m_csRenameFile;
	
	void SetFileTime (HANDLE hFile);
	
	
	
	BOOL m_bRename_CheckIfRenamed;
	
	
	BOOL m_bNeedStartAgain;
	
	
	void AppendCommentToFileName (BOOL bMoveFile = TRUE);
	
	void CheckDstFileExists();
	
	BOOL OnNeedFile_FinalInit();
	static DWORD WINAPI _threadCalcMirrSpeed (LPVOID lp);
	
	
	void CheckMirrSpeedRecalcRequired();
	
	fsTicksMgr m_tikLastMirrMeasureTime;
	
	UINT m_uMirrRecalcSpeedTime;	
	
	
	void AddSection(BOOL bCheckAdm = TRUE);
	BOOL m_bCantStart;	
	static DWORD WINAPI _threadQSize (LPVOID lp);
	BOOL m_bFatalError;	
	LONG m_iThread;	
	CString m_strExtError;	
	
	void OnDone();
	
	void DescribeAPIError(DWORD* pdwLastError = NULL);
	
	DWORD ProcessSCR (fsSizeChangeReaction scr, BOOL bFirstCall = TRUE);
	
	DWORD OnSCR();
	
	void ApplyAdditionalExt();
	
	BOOL ReserveDiskSpace();
	
	
	BOOL BuildFileName(LPCSTR pszSetExt = NULL);
	
	void Event (LPCSTR pszEvent, fsDownloadMgr_EventDescType enType = EDT_INQUIRY);
	
	DWORD Event (fsDownloaderEvent ev, UINT uInfo);
	
	
	
	BOOL OpenFile(BOOL bFailIfDeleted = TRUE, BOOL bDisableEvents = FALSE);
	
	
	
	
	void RenameFile(BOOL bFormat1 = TRUE);
	
	BOOL OnNeedFile();
	BOOL m_uNeedStartFrom; 
	
	
	void OnSectionStopped();
	
	BOOL SleepInterval ();
	fntEventDescFunc m_pfnEventDesc;	
	LPVOID m_lpEventDescParam;			
	fsTicksMgr m_ticksStart;			
	HANDLE m_hOutFile;					
	
	void StopDownload();
	fsInternetResult m_lastError;	
	
	fsInternetResult StartDownload();
	
	static DWORD _DownloaderEvents (fsDownloaderEvent enEvent, UINT uInfo, LPVOID lp);
	DWORD m_dwState;	
	vmsCriticalSection m_csState;
	void setStateFlags (DWORD dwFlags);
	void setStateFlagsTo (DWORD dwFlags);
	void removeStateFlags (DWORD dwFlags);
	BOOL m_bThreadRunning;	
	
	static DWORD WINAPI _threadDownloadMgr (LPVOID lp);
	
	fsInternetResult CreateInternetSession();
	BOOL InternetAutodial(DWORD dwFlags, HWND hwndParent);
	fsDownload_Properties m_dp;		
	fsInternetDownloader m_dldr;	
	fntDownloadMgrEventFunc m_pfnEvents;	
	LPVOID m_lpParamEvents;		
	BOOL TruncFile(const CString& sFileName);
	void RenameFile(const char* szFileName, BOOL bFormat1 = 1);
	void RemoveIncompleteFileExt();
	bool m_bFailedToCreateDestinationFile;
	bool m_bIsNotEnoughDiskSpace;
private:
	
	
	
	BOOL ApplyAER (fsAlreadyExistReaction enAER, bool bFirstCheck = true);
	fsDownload* m_dld; 
	CString m_sOriginalFile; 
protected:
	void AdjustKnownFileSharingSiteSupport_RapidShare(void);
	void AdjustKnownFileSharingSiteSupport_FileSonic(void);

public:
	UINT64 getSpeed(bool bOfDownload);
	void setSpeedLimit(bool bForDownload, UINT64 uLimit);
	UINT64 getSpeedLimit(bool bOfDownload);
	bool isResumeSupported(void);
	bool isNoSpeedLimit(bool bOfDownload);
	UINT64 getInternalSpeedLimit(bool bOfDownload);
	bool isRequiresTraffic(bool bForDownload);
	bool isSpeedCanBeLimitedBySomeInternalReasons (bool bForDownload);
	bool isInternetTraffic (bool bForDownload);
};

#endif 
