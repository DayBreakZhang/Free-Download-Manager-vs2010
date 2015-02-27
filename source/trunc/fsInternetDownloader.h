/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSINTERNETDOWNLOADER_H__0EEB4A27_85D5_4B6A_BB66_2B11A70AEB7C__INCLUDED_)
#define AFX_FSINTERNETDOWNLOADER_H__0EEB4A27_85D5_4B6A_BB66_2B11A70AEB7C__INCLUDED_

#include "DownloadProperties.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

#include "list.h"
#include "fsSpeedMeter.h"	
#include "fsMirrorURLsMgr.h" 
#include "fsMutex.h"
#include "fsArchiveInternetStream.h"
#include "fsArchiveRebuilder.h"
#include "vmsCriticalSection.h"
#include "vmsPersistObject.h"

enum fsSectionState
{
	SS_DOWNLOADING,		
	SS_RECONNECTING,	
	SS_ERROR,			
	SS_WRITEERROR,		
	SS_DONE,			
	SS_CREATING,		
	SS_STOPPED,			
	SS_ERRSTOPPED,		
	SS_NEEDSTOP			
};

struct fsSection_v1
{
	UINT uStart, uEnd, uCurrent;	
	UINT uSpeed;					
	fsInternetURLFile *file;		
	fsSectionState state;			
	fsInternetResult lastErr;		
	UINT uSpeedLimit;				
	int iSection;					
	class fsInternetDownloader *pThis;
};

struct fsSection_v2
{
	UINT uStart, uEnd, uCurrent;
	UINT uSpeed;				
	fsInternetURLFile *file;	
	fsSectionState state;		
	fsInternetResult lastErr;	
	UINT uSpeedLimit;			
	int iSection;				
	class fsInternetDownloader *pThis;
	UINT nMirrorURL;
	DWORD adwReserved [20];

	fsSection_v2 ()
	{
		nMirrorURL = UINT_MAX;
		ZeroMemory (adwReserved, sizeof (adwReserved));
	}
};

struct fsSection_v3 
{
	UINT64 uStart, uEnd, uCurrent;
	UINT uSpeed;				
	fsInternetURLFile *file;	
	fsSectionState state;		
	fsInternetResult lastErr;	
	UINT uSpeedLimit;			
	int iSection;				
	class fsInternetDownloader *pThis;
	UINT nMirrorURL;
	DWORD adwReserved [20];

	fsSection_v3 ()
	{
		nMirrorURL = UINT_MAX;
		ZeroMemory (adwReserved, sizeof (adwReserved));
	}
};

struct fsSection
{
	UINT64 uStart, uEnd, uCurrent;	
	UINT uSpeed;					
	fsInternetURLFile *file;		
	fsSectionState state;			
	fsInternetResult lastErr;		
	UINT uSpeedLimit;				
	int iSection;					
	class fsInternetDownloader *pThis;	
	
	
	UINT nMirrorURL;
	UINT64 uDStart, uDEnd, uDCurrent;	

	fsSection ()
	{
		file = NULL;
		nMirrorURL = UINT_MAX;
		iSection = -1;
	}

	fsSection& operator= (fsSection_v1& s)
	{
		uStart = s.uStart;
		uEnd = s.uEnd == UINT_MAX ? _UI64_MAX : s.uEnd;
		uCurrent = s.uCurrent;

		uDStart = uStart;
		uDCurrent = uCurrent;
		uDEnd = uEnd;

		uSpeed = s.uSpeed;
		state = s.state;
		lastErr = s.lastErr;
		uSpeedLimit = s.uSpeedLimit;
		iSection = s.iSection;
		pThis = s.pThis;
		return *this;
	}

	fsSection& operator= (fsSection_v2& s)
	{
		uStart = s.uStart;
		uEnd = s.uEnd == UINT_MAX ? _UI64_MAX : s.uEnd;
		uCurrent = s.uCurrent;

		uDStart = uStart;
		uDCurrent = uCurrent;
		uDEnd = uEnd;

		uSpeed = s.uSpeed;
		state = s.state;
		lastErr = s.lastErr;
		uSpeedLimit = s.uSpeedLimit;
		iSection = s.iSection;
		pThis = s.pThis;
		nMirrorURL = s.nMirrorURL;
		return *this;
	}

	fsSection& operator= (fsSection_v3& s)
	{
		uStart = s.uStart;
		uEnd = s.uEnd;
		uCurrent = s.uCurrent;

		uDStart = uStart;
		uDCurrent = uCurrent;
		uDEnd = uEnd;

		uSpeed = s.uSpeed;
		state = s.state;
		lastErr = s.lastErr;
		uSpeedLimit = s.uSpeedLimit;
		iSection = s.iSection;
		pThis = s.pThis;
		nMirrorURL = s.nMirrorURL;
		return *this;
	}
};

typedef DWORD (*fsDownloaderEventFunc)(enum fsDownloaderEvent ev, UINT uParam, LPVOID lpAppParam);

enum fsDownloaderEvent
{
	DE_CONNECTING,				
	DE_CONNECTED,				
	DE_FAILCONNECT,				
	DE_PAUSE,					
	
	
	DE_ERROROCCURED,
	
	DE_SECTIONADDED,
	
	DE_SECTIONSTARTED,
	
	DE_SECTIONSTOPPED,
	
	DE_SECTIONDONE,
	
	DE_WRITEERROR,
	
	DE_REDIRECTING,
	
	DE_REDIRECTINGOKCONTINUEOPENING,
	
	DE_NEEDFILE,
	
	
	DE_NEEDFILE_FINALINITIALIZATION,
	
	
	
	DE_SCR,
	
	
	DE_QUERYNEWSECTION,
	
	
	DE_ERRFROMSERVER,
	
	DE_ALLSTOPPEDORDONE,
	
	DE_RESTARTINGBECAUSENORANGES,
	
	
	DE_DIALOGWITHSERVER,
	
	DE_SECTDOWNLOADING,
	
	
	
	DE_EXTERROR,

	
	
	DE_STARTINGSEARCHINGFORMIRRORS,
	
	DE_CONNECTINGMIRRSERVER,
	
	DE_GETTINGMIRRSEARCHRESULTS,
	
	DE_MIRRFOUND,
	
	DE_MEASURINGMIRRSPEED,
	
	DE_MIRRDONE,
	
	DE_MIRRFAILED,
	
	DE_NOMIRRFOUND,
	

	
	DE_TRYINGANOTHERMIRROR,
	
	DE_BADFILESIZE,

	
	
	DE_FILESIZETOOBIG,

	
	
	DE_CONFIRMARCHIVEDETECTION,
	DE_ZIPPREVIEWSTARTED,
	DE_ZIPPREVIEWFAILED,
	
	
	DE_ARCHIVEDETECTED,
	
	DE_MAYADDSECTION,
	
	DE_STARTINGDOWNLOAD,
	DE_STARTINGDOWNLOAD_CONNECTING,
	DE_STARTINGDOWNLOAD_FAILEDTOCONNECT,

	
	
	DE_SPEEDISTOOLOW,

};

struct fsDlgWithServerInfo
{
	fsInetFileDialogDirection dir;	
	LPCSTR pszMsg;					
	int iSection;					
};

enum fsInternetDownloaderStates
{
	IDS_MIRRSEARCHPERFORMED			= 1,
	IDS_ZIPPREVIEWPERFORMED			= 2,
	IDS_ZIPPREVIEWALLOWED			= 4,	
	IDS_USEZIPPREVIEW				= 8,	
	IDS_MIRRORS_HAS_LOCAL_SOURCE	= 16,	
};

#define MAX_NOT_COMPLETED_SECTION_COUNT		20

class fsInternetDownloader  
{
public:
	
	BOOL IsCompletelyStopped ();
	
	static void ResetTotalTrafficInfo();
	
	static UINT64 get_TotalSpeed();
	
	static UINT64 get_TotalTraffic();
	
	BOOL is_WasAccessedAtLeastOnce();
	FILETIME get_FileDate(); 
	
	fsString get_URL (BOOL bIncludeAuthInfo = FALSE);
	
	BOOL RemoveMirror (int iIndex);
	
	void Set_Timeout (UINT u);
	
	UINT64 GetLDFileSize();
	
	DWORD GetState();
	
	void UseZipPreview (BOOL b);
	
	LPCSTR Get_FileName();
	
	UINT64 GetDownloadedBytesCount();
	
	int GetFoundMirrorCount();
	
	LPCSTR GetContentType();
	
	void Set_MirrPingTime (int iMirr, DWORD dw);
	
	BOOL IsMirrSearchPerformed();
	
	BOOL MeasureMirrorsSpeed();
	
	int GetMirrorRefs (int iMirrorIndex);
	
	void Set_BaseServerPingTime (DWORD dw);
	
	DWORD Get_BaseServerPingTime();
	
	
	
	
	void AddMirror (fsDownload_NetworkProperties* dnp, BOOL bIsGood = TRUE, BOOL bDontMeasureSpeed = FALSE);
	
	void RemoveAllMirrors ();
	
	BOOL GetMirrorIsGood (int iMirr);
	
	DWORD GetMirrorPingTime (int iMirr);
	
	void Set_MirrDontSearchIfSizeUnk (BOOL b);
	void Set_MirrMaxCount(UINT u);
	void Set_MirrFileMinSize(UINT u);
	void Set_MirrCalcSpeed (BOOL b);
	void Set_SearchForMirrors (BOOL bSearch);
	
	BOOL IsSectionCreatingNow ();
	
	fsInternetResult FindMirrors();
	
	fsInternetResult AddMirrorURL (LPCSTR pszUrl, LPCSTR pszUser = NULL, LPCSTR pszPassword = NULL, BOOL bDontMeasureSpeed = FALSE);
	
	int GetMirrorURLCount();
	
	fsDownload_NetworkProperties* MirrorDNP (int iMirror);
	
	
	fsInternetResult StartDownloading(UINT uStartFrom = 0);
	
	void StopDownloading();
	
	void UseDetailedLog (BOOL b = TRUE);
	
	fsInternetResult LaunchOneMoreSection ();
	
	int GetStoppedSectionCount ();
	
	fsInternetResult QuerySize();
	
	LPCSTR GetSuggestedFileName();
	
	void StopSection();
	
	void LockWriteFile (BOOL bLock);
	
	void DeleteAllSections();
	
	int GetCreatingNowSectionCount(UINT nMirror);
	
	float GetPercentDone ();
	
	fsResumeSupportType IsResumeSupported();
	
	UINT GetTrafficLimit();
	
	void StopOnAccDenied (BOOL b);
	
	void StopOnFileNotFound (BOOL b);
	
	void DontRestartIfNoRanges (BOOL b);
	
	void ResetSections();
	
	void SetOutputFile (HANDLE hOutFile);
	
	UINT64 GetBytesLeft();
	
	int GetDoneSectionCount();
	
	int GetDownloadingSectionCount();
	
	BOOL IsAllSectionsOk();
	
	int GetRunningSectionCount();
	
	UINT64 GetSSFileSize();
	
	BOOL IsRunning();
	
	fsInternetResult GetSectionLastError(int iSection);
	
	BOOL IsHavingError();
	
	BOOL IsStoppedByUser();
	
	BOOL IsDone();
	
	
	UINT64 GetSectionMaxSize();
	
	
	void SetMaxReconnectionNumber (UINT uMax);
	
	void SetEventFunc (fsDownloaderEventFunc pfn, LPVOID lpParam);
	
	UINT GetSpeed();
	
	
	void LimitTraffic (UINT uLimit);
	
	BOOL IsDownloading();
	
	
	
	
	BOOL SaveSectionsState (LPBYTE pBuffer, LPDWORD pdwSize);
	
	BOOL RestoreSectionsState (LPBYTE pBuffer, DWORD dwSize, DWORD dwVer);
	
	BOOL RestoreSectionsState_vlt5 (LPBYTE pBuffer, DWORD dwSize, DWORD dwVer);
	
	BOOL RestoreSectionsState_vlt4 (LPVOID pBuffer, DWORD dwSize);
	
	
	void SetSectionMinSize (UINT uMinSize);
	
	int GetNumberOfSections();
	
	BOOL SetSection_TrafficLimit (int iSection, UINT uLimit);
	
	
	BOOL GetSectionInfo (int iSection, fsSection* pSection, BOOL bNoCacheAccounting = FALSE);
	
	void SetRetryTime (DWORD dwMilliseconds);
	
	
	
	fsInternetResult AddSection(BOOL bQueryCreation = TRUE);
	
	fsDownload_NetworkProperties* DNP(int nSection = -1);
	
	void ApplyProperties(class fsInternetURLFile *pFile, fsDownload_NetworkProperties* dnp);
	void ApplyProxySettings (fsInternetSession* pSession, fsDownload_NetworkProperties* dnp);
	void CreateCompleteSection(UINT64 uFileSize); 
	void SetFileSize(UINT64 uFileSize); 
	void AddSection(UINT64 uStart, UINT64 uEnd, UINT64 uCurrent);
	void SetManagerPersistObject(vmsPersistObject* pManagerPersistObject);
	void setDirty();

	fsInternetDownloader();
	virtual ~fsInternetDownloader();

protected:
	void CheckIfSuggFileNameEncoded();
	struct _inc_tOU_param {
		fsInternetDownloader *pthis;
		fsInternetURLFile *pFile;
		UINT64 uStartPos;
		fsDownload_NetworkProperties *dnp;
	};
	static DWORD WINAPI _threadOpenUrl (LPVOID lp);
	
	DWORD m_dwForceCacheSizePerSection;
	
	
	
	
	
	
	
	
	DWORD m_dwDataLenInCache;
	
	static void OnDataDownloaded (UINT64 nDataSize);
	
	static UINT64 m_nTotalTraffic;
	
	
	static fsSpeedMeter m_TotalSpeed;
	
	static vmsCriticalSection m_csDataRcvd;
	
	static BOOL m_bPauseMode;
	BOOL m_bWasAccessedAtLeastOnce;
	FILETIME m_fileDate;
	vmsCriticalSection m_csSections;
	
	BOOL m_bAddingSection;
	
	UINT m_uTimeout;
	
	BOOL IsMayZIP (BOOL bIsExeMay);
	
	void ApplyArchiveRebuilding (fsArchive::fsArchiveRebuilder* ar, UINT64 uAddOffset = 0);
	fsArchiveInternetStream* m_pZipPreviewStream;	
	
	
	
	
	
	fsInternetResult CheckIsZIP(UINT64 uStartPosition, fsInternetURLFile **ppFileToCloseIfNeed);
	BOOL RestoreSectionsState_v5(LPBYTE pBuffer, DWORD dwSize);
	fsString m_strContentType;	
	DWORD m_dwState;		
	vmsCriticalSection m_csOpenUrl;	
	
	fsInternetResult Auto_SearchMirrors ();
	
	BOOL m_bMirrDontSearchIfSizeUnk;
	BOOL m_uMirrRecalcSpeedTime;
	UINT m_cMaxMirrs;
	UINT m_uMirrFileMinSize;
	BOOL m_bMirrMeasureSpeed;
	
	
	UINT FindNotBusyMirrorIndex();
	
	static void _MirrMgrEvents (fsMirrorURLsMgrEvent ev, LPVOID lp);
	BOOL m_bSearchForMirrors;	
	
	fsMirrorURLsMgr* m_pMirrURLMgr;
	BOOL m_bDetLog;				
	
	static void _InetFileDialogFunc (fsInetFileDialogDirection dir, LPCSTR pszMsg, LPVOID lp1, LPVOID lp2);
	
	fsInternetResult QuerySize (fsInternetURLFile* file);
	fsString m_strSuggFileName;	
	
	int m_cBaseSectCreatingNow;	
	fsResumeSupportType m_enRST;	
	vmsCriticalSection m_csDone;	
	
	fsInternetURLFile *m_pOpeningFile;
	
	BOOL m_bStopOnAccDenied;	
	BOOL m_bStopOnFileNotFound;	

	
	BOOL m_bDontRestartIfNoRanges;	
	
	UINT64 m_uSSFileSize;		
	UINT64 m_uLDFileSize;		
	
	void UpdateTrafficLimit();
	fsSpeedMeter m_speed;		
	
	
	
	BOOL SleepInterval();
	vmsCriticalSection m_csAddSection;	
	
	DWORD Event (fsDownloaderEvent enEvent, UINT uDesc = 0);
	UINT m_uTrafficLimit;		
	
	
	volatile UINT m_cThreads, m_cRunningThreads;
	volatile BOOL m_bNeedStop;	
	UINT m_uSectionMinSize;		
	vmsCriticalSection m_csWriteToFile;
	HANDLE m_hOutFile;			
	UINT m_uRetryTime;			
	
	
	
	
	
	
	
	
	fsInternetResult OpenUrl (UINT64 uStartPos, fsInternetURLFile **ppFile, int iSectIndex, UINT &nMirror, BOOL bCheckFileSize = FALSE, LPCSTR pszContentTypeReq = NULL);
	fsInternetResult OpenUrl_imp (UINT64 uStartPos, fsInternetURLFile **ppFile, int iSectIndex, UINT &nMirror, BOOL bCheckFileSize, int iAttempt, LPCSTR pszContentTypeReq = NULL, fsDownload_NetworkProperties *pDNPRedirectedUrl = NULL, bool bIsRedirected = false);
	
	
	static DWORD WINAPI _threadDownload(LPVOID lp);
	
	fsInternetResult CreateAdditionalSection (BOOL bQueryCreation = TRUE);
	
	
	
	BOOL CreateSection (fsSection &sect, BOOL bCreateThread = TRUE, BOOL bReduceSCN = TRUE);
	
	fsInternetResult CreateMainSection (UINT uStartFrom = 0, BOOL bQueryCreation = TRUE);
	BOOL m_bErrDownloading;			
	fsDownload_NetworkProperties m_dnp;	

	struct fsSectionEx : public fsSection
	{
		DWORD dwCacheLen;
		bool bSleep;
	
		fsSectionEx (const fsSection& s) {
			CopyMemory (this, &s, sizeof (s));
			dwCacheLen = 0;
			bSleep = false;
		}

		fsSectionEx () {
			dwCacheLen = 0;
			bSleep = false;
		}
	};
	fs::list <fsSectionEx> m_vSections;	
	fsDownloaderEventFunc m_pfnEvents;
	LPVOID m_lpEvent;
	UINT m_uMaxAttempts;				
	BOOL m_bNoNewSections;	

	struct fsMirrorURLInfo
	{
		fsDownload_NetworkProperties dnp;	
		DWORD dwPingTime;					
		
		
		
		BOOL bIsGood;		
		
		int cSectsCreatingNow;

		fsMirrorURLInfo ()
		{
			dwPingTime = UINT_MAX;
			bIsGood = TRUE;
			cSectsCreatingNow = 0;
		}
	};

	fs::list <fsMirrorURLInfo> m_vMirrs; 
	DWORD m_dwBaseServerPingTime;	
	fsString m_strFileName;	
	
	int m_cMirrsFound;
	
	vmsPersistObject* m_pManagerPersistObject;

private:
	
	
	
	
	
	
	
	static BOOL __threadDownload_flushdata (fsSectionEx* sect, LPBYTE pBuffer, DWORD dwRead,	LPBYTE &pbCache, DWORD &dwCacheSize, DWORD &dwCacheLen);
};

#endif 
