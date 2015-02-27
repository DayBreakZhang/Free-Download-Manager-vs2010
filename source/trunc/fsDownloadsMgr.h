/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSDOWNLOADSMGR_H__49230334_5704_46DF_95BA_2F7535E427DE__INCLUDED_)
#define AFX_FSDOWNLOADSMGR_H__49230334_5704_46DF_95BA_2F7535E427DE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "list.h"
#include "array.h"
#include "fsDownloadMgr.h"
#include "fsDownloadRegSaver.h"	
#include "vmsFileRecentList.h"

#ifndef FDM_DLDR__RAWCODEONLY
#include "fsIECatchMgr.h"
#include "fsDownloadsHistoryMgr.h"	
#endif

#include "fsArchiveRebuilder.h"
#include "vmsStringRecentList.h"	
#include "fsDownload.h"
#include "vmsPersistableListOfDownloads.h"
#include "StateInfo.h"
#include <map>

enum fsDownloadsMgrEvent
{
	DME_DOWNLOAD_STATE_CHANGED,		
	DME_DOWNLOADEREVENTRECEIVED,	
	DME_EVENTDESCRIPRIONRECEIVED,	
	DME_DOWNLOADWILLBEDELETED,		
	DME_DOWNLOADWASDELETEDFROMLIST,	
	DME_DOWNLOADFILEWILLBEDELETED,	
	DME_NOACTIVEDOWNLOADS,			
	DME_REDIRECTED,					
	DME_DLDSAUTOSTARTMDFD,				
	DME_FILEUPDATED,				
	DME_DOWNLOADSTOPPEDORDONE,		
	DME_SECTIONSTARTED,				
	DME_SECTIONDOWNLOADING,			
	DME_DLMGRTHREADSTARTING,		
	DME_BEFOREDOWNLOADING,			
	DME_DLDADDEDTODELETED,			
	DME_DLDREMOVEDFROMDELETED,		
	DME_DLDWILLBEFULLYDELETED,		
	DME_DLDRESTORED,				
	DME_RECADDEDTOHISTORY,			
	DME_RECDELETEDFROMHISTORY,		
	DME_HISTORYCLEARED,				
	DME_CREATEDLDDIALOG,	
	DME_CLOSEDLDDIALOG,		
	DME_UPDATEDLDDIALOG, 
	DME_DLDAUTODELETED,	
	DME_BEGINDELETEMANYDOWNLOADS, 
	DME_ENDDELETEMANYDOWNLOADS,	
	DME_RECYCLEBINCONTENTCHANGED,	
	DME_BTDLD_STAT_CHANGED,		
	DME_DLD_CHANGED_TO_BT_TYPE,
};

enum fsDeleteDownloadReaction
{
	DDR_ASK				= 0,	
	DDR_FROMLISTONLY	= 1,	
	DDR_WITHFILE		= 2		
};

struct fsServerConnections
{
	CString strName;	
	UINT cConns;		
};

enum vmsBtDownloadErrorState
{
	BTDES_SERVER_INTERNAL_ERROR_500 = BTDS_SERVER_INTERNAL_ERROR_500,
	BTDES_BAD_REQUEST_400 = BTDS_BAD_REQUEST_400,
	BTDES_NO_ERROR,
};

struct vmsDldErrorStamp
{
	vmsBtDownloadErrorState Error;
	DWORD TimeStamp;

	vmsDldErrorStamp()
	{}

	vmsDldErrorStamp(const vmsDldErrorStamp& st)
	{
		Error = st.Error;
		TimeStamp = st.TimeStamp;
	}

	vmsDldErrorStamp(vmsBtDownloadErrorState error)
	{
		Error = error;
		TimeStamp = GetTickCount();
	}
};

const UINT MAX_SUMMS = 24*60*(60/5);

#define DLMGRFILE_CURRENT_VERSION	(1)
#define DLMGRFILE_SIG		"FDM Dl Mgr SI"
struct fsStateInfoFileHdr
{
	char szSig [sizeof (DLMGRFILE_SIG) + 1];
	WORD wVer;

	fsStateInfoFileHdr ()
	{
		strcpy (szSig, DLMGRFILE_SIG);
		wVer = DLMGRFILE_CURRENT_VERSION;
	}
};

class fsDownloadsMgr  
{
	friend class CDownloaderProperties_ListPage;
	friend class CDlg_Options_Downloads;
	friend class CPrg_Data; 
public:
	struct TotalProgress
	{
		UINT64 uDownloaded;
		UINT64 uTotalSize;
		UINT64 uSpeed;
		void clear () {uDownloaded = uTotalSize = uSpeed = 0;}
		TotalProgress () {clear ();}
	};
public:
	bool isAutoDelCompletedDownloads () const {return m_bAutoDelCompleted != 0;}
	BOOL AskToDeleteDownloadFile (vmsDownloadSmartPtr dld, BOOL bNoCancel, fsDeleteDownloadReaction &enDDRResult, bool &bApplyForAll);
	
	void GetDDRs (DLDS_LIST_REF vDlds, BOOL bDeleteCompletedFilesAlso, BOOL bNoCancel, std::vector <fsDeleteDownloadReaction> &vResult);
	void ApplyDDRs (DLDS_LIST_REF vDlds, std::vector <fsDeleteDownloadReaction> &vDDRs, BOOL bNoCancel);
	vmsDownloadSmartPtr findBtDownloadByHash (vmsBtDownloadManager *pMgr);
	vmsDownloadSmartPtr findBtDownloadByHash (LPBYTE pbHash, DWORD dwHashSize);
	const TotalProgress& getTotalProgress () const;
	void ChangeDownloadGroup (fsDownload* dld, vmsDownloadsGroupSmartPtr spGrp, bool bMoveFiles = true);
	
	
	
	DWORD m_dwPDTimeLimit;
	BOOL AllowStartNewDownloads();
	vmsDownloadSmartPtr get_HighestPriorityDownload();
	void AddEvent (vmsDownloadSmartPtr dld, LPCSTR pszEvent, fsDownloadMgr_EventDescType enType = EDT_RESPONSE_S);
	void DownloadStateChanged (vmsDownloadSmartPtr dld);
	
	
	int IsSuchUrlExistsAlready(vmsDownloadSmartPtr dld);
	
	
	
	
	
	void set_HighestPriorityDownload (vmsDownloadSmartPtr dld);
	
	vmsDownloadSmartPtr FindDownloadByBtDownload (vmsBtDownload* pDld);
	vmsDownloadSmartPtr GetDownloadByBtDownloadMgr (vmsBtDownloadManager *pMgr);
	vmsDownloadSmartPtr GetDownloadByTpDownloadMgr (vmsTpDownloadMgr *pMgr);
	
	void AttachToBtSession();
	
	static void GetEventColors (fsDownloadMgr_EventDescType enType,  COLORREF  &clrText, COLORREF &clrBg, int &iImage);
	
	
	BOOL DeleteGroupsDownloads (vmsDownloadsGroupSmartPtr pGroup, BOOL bInclSubgroups);
	
	
	
	
	
	
	void ReorderDownloads (DLDS_LIST_REF vDlds, DLDS_LIST_REF vReqOrder, bool bDldsSorted = false);
	
	
	
	void MoveDownloads (DLDS_LIST_REF vDlds, vmsDownloadSmartPtr pDldPosition, bool bUp);
	
	void LastFilesDownloaded_Clear();
	
	vmsFileRecentList* get_LastFilesDownloaded ();
	
	UINT GetNextDownloadID();
	
	BOOL GenerateDescriptionFile (vmsDownloadSmartPtr dld);
	
	void ApplyAER (fsAlreadyExistReaction enAER);
	
	void Shutdown();
	
	
	
	void LaunchDownload (vmsDownloadSmartPtr dld, UINT nWaitForConfirmation = 0);
	
	void Initialize();
	
	
	void MoveDownloadToEndOfList (vmsDownloadSmartPtr dld);
#ifndef FDM_DLDR__RAWCODEONLY
	fsDownloadsHistoryMgr m_histmgr;	
#endif
	
	BOOL IsRestoringNow();
	
	
	
	BOOL PerformVirusCheck (vmsDownloadSmartPtr dld, BOOL bCheckExtReqs, BOOL bWaitDone);
	
	int RestoreDownloads (DLDS_LIST &vDlds);
	
	int GetDeletedDownloadIndex (vmsDownloadSmartPtr dld);
	
	BOOL IsDeletingDeletedNow();
	
	
	int DeleteDeletedDownloads (DLDS_LIST &vDlds, BOOL bNoCancel = FALSE);
	
	void ClearDeleted();
	
	void ReadDeletedSettings();
	
	vmsDownloadSmartPtr Get_DeletedDownload (int iIndex);
	
	int Get_DeletedDownloadCount();
	
	void Apply_MirrParameters (vmsDownloadSmartPtr dld);
	void ReadMirrParameters();
	
	void Apply_MirrParameters();
	
	
	void StartDownloads(DLDS_LIST &vpDlds, BOOL bByUser = FALSE);
	
	void StopDownloads(DLDS_LIST &vDlds, BOOL bByUser = FALSE);
	
	static void Download_CloneSettings (vmsDownloadSmartPtr dst, vmsDownloadSmartPtr src);
	
	void UseDetailedLog (BOOL b);
	
	BOOL IsDeletingNow();
	
	int GetRunningDownloadCount(bool bIncludeBtSeeds = true);
	
	void ReadSettings();
	
	void SaveSettings();
	
	void UnlockList(bool bForRead);
	void LockList (bool bForRead);
	
	void RebuildServerList(BOOL bUpdateSiteList = TRUE);
	
	void AllowStartNewDownloads (BOOL bAllow);
	
	vmsDownloadSmartPtr GetDownloadByID (UINT nID);
	
	BOOL IsRunning();
	
	
	BOOL IsSummarySpeedWasLessThan (UINT uSpeed, UINT uTimeInterval);
	
	
	void StopAllDownloads(BOOL bByUser);
	void StartAllDownloads(BOOL bByUser);
	
	UINT GetAmountConnections ();
	
	
	void StartGroup (vmsDownloadsGroupSmartPtr pGroup);
	void StopGroup (vmsDownloadsGroupSmartPtr pGroup);
	
	
	
	int  DeleteDownloads (DLDS_LIST &vDlds, BOOL bByUser, BOOL bDontConfirmFileDeleting, BOOL bDontDeleteFiles = FALSE);
	
	int GetDownloadIndex (vmsDownloadSmartPtr dld, int nFindStartPos = 0);
	
	BOOL Save ();
	BOOL LoadDownloads();
	
	
	size_t GetCount() {return m_vDownloads.size ();};
	
	vmsDownloadSmartPtr GetDownload (size_t iIndex);
	void SetEventsFunc (fntDownloadsMgrEventFunc pfn, LPVOID lpParam);
	
	vmsDownloadSmartPtr GetDownloadByDownloadMgr(fsDownloadMgr *pMgr);
	
	
	
	UINT Add (vmsDownloadSmartPtr dld, BOOL bKeepIDAsIs = FALSE, bool bPlaceToTop = false);
	
	bool IsStoringLogTurnedOn();
	
	
	
	
	
	
	
	
	fsDownloadsMgr();
	virtual ~fsDownloadsMgr();
	void ProcessDownloads();
protected:
	
	void ApplyTrafficLimit();
	
	
	
	
	
	static DWORD WINAPI _threadEventsDispatcher (LPVOID lp);
	struct BtDownloadManagerEvent
	{
		vmsBtDownloadManagerPtr spMgr;
		vmsBtDownloadManagerEvent ev;
		DWORD dwInfo;
	};
	std::vector <BtDownloadManagerEvent> m_vBtDownloadManagerEvents;
	vmsCriticalSection m_csBtDownloadManagerEvents;
	HANDLE m_htEventsDispatcher;
	HANDLE m_hevNeedDispatchEvents;
	HANDLE m_hevShuttingDown;
	static void findDownloadsIndexes (DLDS_LIST_REF vDldsWhat, DLDS_LIST_REF vDldsWhere, std::vector <int> &vResult);
	static void findDownloadsIndexes (DLDS_LIST_REF vDldsWhat, vmsDownloadList& vDldsWhere, std::vector <int> &vResult);
	BOOL CheckIfDownloadIsMirror (fsDownload* dld);
	bool isAllowedToPDCurrently () const;
	void ManagePD ();
	static DWORD WINAPI _threadStartSeeding (LPVOID lp);
	void EventEx (vmsDownloadSmartPtr dld, LPCSTR pszEvent, fsDownloadMgr_EventDescType enType, int nMaxCharsPerLine);

	
	void GetRunningDownloads (DLDS_LIST &v);
	vmsDownloadSmartPtr m_dldHighestPriority;
	TotalProgress m_totalProgess;
	
	void OnDownloadDescEventRcvd (vmsDownloadSmartPtr dld, fsDownloadMgr_EventDescType enType, LPCSTR pszEvent);
	
	BOOL OnDownloadStoppedOrDone (vmsDownloadSmartPtr dld);
	
	static DWORD _BtDownloadManagerEventHandler (vmsBtDownloadManager* pMgr, vmsBtDownloadManagerEvent ev, DWORD dwInfo, LPVOID lp);
	void onBtDownloadManagerEvent (vmsBtDownloadManager *pMgr, vmsBtDownloadManagerEvent ev, DWORD dwInfo);
	
	static void _BtSessionEventsHandler (class vmsBtSession*, struct vmsBtSessionEvent*, LPVOID lp);
	
	static DWORD _TpDownloadManagerEventHandler(vmsTpDownloadMgr *pMgr, fsDownloaderEvent enEvent, UINT uInfo, LPVOID lp);
	static void _TpDownloadManagerEventDesc(vmsTpDownloadMgr *pMgr, fsDownloadMgr_EventDescType enType, LPCSTR pszDesc, LPVOID lp);
	
	static DWORD WINAPI _threadDeleteDownloadMgrEx (LPVOID lp);
	
	
	BOOL OnDldDone_CheckDownloadIsBittorrent (vmsDownloadSmartPtr dld);
	
	
	
	
	
	void DeletedDownloads_UseTmpList (BOOL bUse);
	
	void DownloadsList_Insert (size_t nIndexBefore, vmsDownloadSmartPtr dld);
	void DownloadsList_Del (size_t nIndex);
	void DownloadsList_Add (vmsDownloadSmartPtr dld);
	
	
	
	BOOL OnDldDone_CheckDownloadIsMetaLink (vmsDownloadSmartPtr dld);
	
	long m_cThreadsRunning;
	
	void OnDldDoneCheckIfNeedDel (vmsDownloadSmartPtr dld);
	
	static DWORD WINAPI _threadIntegrityCheckAndVirCheckAndLaunch (LPVOID lp);
	
	
	
	
	CStateInfo m_siStateInfo;
	
	BOOL SaveStateInformation();
	BOOL LoadStateInformation();
	
	static DWORD WINAPI _threadArchiveDetected (LPVOID lp);
	
	static DWORD WINAPI _threadConfirmZIP (LPVOID lp);
	
	DWORD OnArchiveDetected (vmsDownloadSmartPtr dld, fsArchive::fsArchiveRebuilder* ar);
#ifndef FDM_DLDR__RAWCODEONLY
	
	void Event (fsDLHistoryRecord* rec, fsDownloadsMgrEvent ev);
	DWORD Event (fsDownload* dld, fsDownloadsMgrEvent ev);
	
	static void _HistoryMgrEvents (fsDownloadsHistoryMgrEvent ev, fsDLHistoryRecord *rec, LPVOID);
#endif
	
	static DWORD WINAPI _threadWaitRestoringDlds (LPVOID lp);
	BOOL m_bRestoringNow;	
	
	int RestoreDownloads2(DLDS_LIST* vDlds, BOOL* pbNeedStop, int* piProgress);
	
	static DWORD WINAPI _threadWaitDelDeletingsDlds (LPVOID lp);
	
	int DeleteDeletedDownloads2(DLDS_LIST *vDlds, BOOL bNoCancel, BOOL* pbNeedStop, int* piProgress);
	
	
	BOOL DeleteDownloadFile (vmsDownloadSmartPtr dld);
	
	
	
	vmsDownloadSmartPtr PutDownloadToDeleted (vmsDownloadSmartPtr dld);
	
	
	
	DWORD OnBeforeDownload (vmsDownloadSmartPtr dld);
	
	static DWORD WINAPI _threadWaitDelDlds (LPVOID lp);
	
	int DeleteDownloads2 (DLDS_LIST *vDlds, BOOL bByUser, BOOL bDontConfirmFileDeleting, BOOL bDontDeleteFiles = FALSE, BOOL* pbNeedStop = NULL, int* piProgress = NULL);

	
	BOOL IsMaxConnsReached();
	
	
	BOOL IsServerFilled (LPCSTR pszServer, DWORD dwReqProtocols);

	
	
	void CheckNoActiveDownloads();

	
	BOOL m_bMirrDontSearchIfSizeUnk;
	UINT m_uMirrRecalcSpeedTime;
	UINT m_cMaxMirrs;
	BOOL m_bMirrCalcSpeed;
	UINT m_uMirrFileMinSize;
	BOOL m_bMirrAutoSearch;
	BOOL m_bVirCheck;			
	fsString m_strVirName, m_strVirArgs, m_strVirExts;	
	BOOL m_bDetLog;		
	BOOL m_bDeletingNow, m_bDeletingDeletedNow;		
	vmsCriticalSection m_csQSection;	
	BOOL m_bAllowStart;				
	BOOL m_bDisablePD;	
	
	fs::array <UINT, MAX_SUMMS> m_vSummSpeed;
	
	
	BOOL m_bSkip1Cicle;	
	
	void ManageTraffic();
	
	void OnSectionStop (vmsDownloadSmartPtr dld);
	void Event (vmsDownloadSmartPtr dld, LPCSTR pszEvent, fsDownloadMgr_EventDescType enType = EDT_RESPONSE_S);
	
	
	BOOL OnQueryNewSection (vmsDownloadSmartPtr dld, UINT nUsingMirror);
	BOOL m_bAutoDelCompleted;	
	fsDeleteDownloadReaction m_enDDR;	
	BOOL m_bShuttingDown;			
	vmsCriticalSection m_csShuttingDown;
	static DWORD WINAPI _threadDownloadsMgr (LPVOID lp);
	
	struct threadDeleteDownloadsParams {
		fsDownloadsMgr *pthis;
		DLDS_LIST vDlds;
		std::vector <fsDeleteDownloadReaction> vDldsDDRs;
	};
	static DWORD WINAPI _threadDeleteDownloads(LPVOID lp);
	fsDownloadRegSaver m_saver;	
	DWORD Event (fsDownload* dld, fsDLHistoryRecord *phst, fsDownloadsMgrEvent ev);
	
	static void _DownloadMgrEventDesc (fsDownloadMgr *pMgr, fsDownloadMgr_EventDescType enType, LPCSTR pszEvent, LPVOID lp);
	static DWORD _DownloadMgrEvents (fsDownloadMgr *pMgr, fsDownloaderEvent enEvent, UINT uInfo, LPVOID lp);
	vmsDownloadList m_vDownloads;	
	vmsReaderWriterLock m_rwlDownloads;
	
	
	vmsDownloadList m_vDeletedDownloads;	
	vmsCriticalSection m_csDeletedDownloads;
	vmsCriticalSection m_csRegisterDldInTum;
	
	std::list <vmsDownloadSmartPtr> m_vDeletedDownloads_tmp;
	BOOL m_bBypassBinForDownloads;	
	BOOL m_bBypassBinForCompletedDownloads;	
	UINT m_cMaxDeleted;		
	fntDownloadsMgrEventFunc m_pfnEvents;
	LPVOID m_lpEventsParam;
	bool m_bIsDownloadListChanged; 
	vmsCriticalSection m_csDownloadListChangeGuard;
	bool m_bIsDeletedDownloadListChanged; 
	
	
	
	
	
	bool m_bIsStateInformationChanged; 
	vmsCriticalSection m_csStateInformationChangeGuard;
	vmsCriticalSection m_csModifiedGuard;

	fsTicksMgr m_ticksNeedStartProcessDownloads;
	fsTicksMgr m_ticksNeedStartApplyTrafficLimit;
	fsTicksMgr m_ticksNeedCheckNoActiveDownloads;
	vmsCriticalSection m_csNeedStartXXXX;

public:
	void setNeedProcessDownloads () 
	{
		vmsAUTOLOCKSECTION (m_csNeedStartXXXX); 
		m_ticksNeedStartProcessDownloads.Now ();
		m_ticksNeedStartProcessDownloads += 100; 
	}
	void setNeedApplyTrafficLimit ()
	{
		vmsAUTOLOCKSECTION (m_csNeedStartXXXX); 
		m_ticksNeedStartApplyTrafficLimit.Now ();
		m_ticksNeedStartApplyTrafficLimit += 100;
	}
	void setNeedCheckNoActiveDownloads ()
	{
		vmsAUTOLOCKSECTION (m_csNeedStartXXXX); 
		m_ticksNeedCheckNoActiveDownloads.Now ();
		m_ticksNeedCheckNoActiveDownloads += 100;
	}
	void onCurrentTrafficUsageModeChanged(void);
protected:
	void RegisterDownloadInTum(fsDownload* dld);
	void UnregisterDownloadInTum(fsDownload* dld);

	
	bool IsDownloadSuspended(vmsDownloadSmartPtr);

	
	std::map<vmsBtDownloadErrorState, int> m_errorTimeouts;
	std::map<vmsDownloadSmartPtr, vmsDldErrorStamp> m_dldErrorsMap;
};

#endif 
