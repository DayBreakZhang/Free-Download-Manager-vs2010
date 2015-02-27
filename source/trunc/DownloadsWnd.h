/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DOWNLOADSWND_H__9DDD9136_96AD_4BBB_A7DE_852EED3847E3__INCLUDED_)
#define AFX_DOWNLOADSWND_H__9DDD9136_96AD_4BBB_A7DE_852EED3847E3__INCLUDED_

#include "fsClipboardCatchMgr.h"	
#include "Downloads_Groups.h"	
#include "WndSplitter.h"	
#include "Downloads_Downloads.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

#include "list.h"
#include "fsDownloadRegSaver.h"	
#include "fsDownloadsMgr.h"
#include "fsIECatchMgr.h"	
#include "plugins.h"
#include "fsMutex.h"	
#include "Downloads_History.h"	
#include "Downloads_Deleted.h"	
#include "fsFindDownloadMgr.h"	
#include "fsDownload.h"	

enum fsDLsWndWhatIsNow
{
	DWWN_LISTOFDOWNLOADS,	
	DWWN_HISTORY,			
	DWWN_DELETED,			
};

#define DWCDAP_GROUP					1
#define DWCDAP_FLAGS					(1<<1)
#define DWCDAP_COOKIES					(1<<2)
#define DWCDAP_POSTDATA					(1<<3)
#define DWCDAP_FILENAME					(1<<4)
#define DWCDAP_MEDIA_CONVERT_SETTINGS	(1<<5)
#define DWCDAP_FILESIZE					(1<<6)
struct vmsDWCD_AdditionalParameters
{
	DWORD dwMask;	
	vmsDownloadsGroupSmartPtr pGroup;
	CString strUserAgent;
	CString strOriginalUrl;
	CString strCookies;
	CString strPostData;
	CString strFileName;
	CString strDstFolder;
	UINT64 uFileSize;
	vmsMediaFileConvertSettings stgsMediaConvert;
	DWORD dwFlags;	
	#define DWDCDAP_F_SAVETODESKTOP				(1 << 0)
	#define DWDCDAP_F_SAVETOTEMPFLDR			(1 << 1)
	
	#define DWDCDAP_F_DELWHENDONE				(1 << 2)
	
	#define DWDCDAP_F_IGNOREALLRESTRICTS		(1 << 3)
	
	#define DWDCDAP_F_PLACETOTOP				(1 << 4)
	
	#define DWDCDAP_F_NOGRPAUTOCHANGE			(1 << 5)
	
	#define DWDCDAP_F_SETFOCUSTOOKBTN			(1 << 6)
	
	#define DWDCDAP_F_NO_UI						(1 << 7)
	
	#define DWDCDAP_F_FORCEAUTOSTART			(1 << 8)
	
	#define DWDCDAP_F_DISABLEMALICIOUSCHECK		(1 << 9)
	
	#define DWDCDAP_F_DONTCHECKURLALREADYEXISTS	(1 << 10)
	
	#define DWDCDAP_F_FLASHVIDEODOWNLOAD		(1 << 11)
	
	#define DWDCDAP_F_TORRENTDOWNLOAD			(1 << 12)
	class CFdmUiWindow *pUiWindow;

	vmsDWCD_AdditionalParameters () {
		dwMask = 0;
		uFileSize = _UI64_MAX;
		dwFlags = 0;
		pUiWindow = NULL;
	}
};

#define DWCD_NOFORCEAUTOLAUNCH				((DWORD) -1)

#define DWCD_FORCEAUTOLAUNCH_NOCONF		((DWORD)0)

#define DWCD_FORCEAUTOLAUNCH				((DWORD)1)

#define NDIV_AUTOSTART				1

#define NDIV_AP						2

struct vmsNewDownloadInfo
{
	DWORD dwWhatIsValid;	
	CString strUrl;
	CString strReferer;
	CString strComment;
	BOOL bAddSilent;
	BOOL bAutoStart;
	DWORD dwForceAutoLaunch;
	vmsDWCD_AdditionalParameters ap;
	UINT *pnCreateNewDownloadResult;

	vmsNewDownloadInfo ()
	{
		dwWhatIsValid = 0;
		bAddSilent = false;
		dwForceAutoLaunch = DWCD_NOFORCEAUTOLAUNCH;
		pnCreateNewDownloadResult = NULL;
	}
};

#define WM_DW_CREATEDLDDIALOG				(WM_APP+1000)
#define WM_DW_CLOSEDLDDIALOG				(WM_APP+1001)
#define WM_DW_UPDATEDLDDIALOG				(WM_APP+1002)

#define WM_DLD_SHOWOPINIONS					(WM_APP+1003)

#define WM_DLD_CONVERT_MEDIA				(WM_APP+1004)
#define WM_DLD_LAUNCH						(WM_APP+1005)
#define WM_DLD_SHOW_ON_DONE_NOTIFICATION	(WM_APP+1006)
#define WM_DW_DLDSMGR_EVENT					(WM_APP+1007)
#define WM_DW_ONDLDSADDED					(WM_APP+1008)
#define WM_DW_ONSUCHTORRENTEXISTSALREADY	(WM_APP+1009)

extern CDownloadsWnd* _pwndDownloads;

class CDownloadsWnd : public CWnd
{
	friend class CDownloads_Groups;
	friend class CDownloads_Tasks;
	friend class CDownloaderProperties_MonitorPage;
	friend class CDownloaderProperties_ListPage;
	friend class CDlg_Options_Downloads;
	friend class CDlgExportDownloads;
	friend class CMainFrame;

public:
	CDownloadsWnd();

public:

public:

	
	//{{AFX_VIRTUAL(CDownloadsWnd)
	//}}AFX_VIRTUAL

public:
	void onBtDownloadWithSameInfoHashExistsAlready ();
	UINT CreateDownload (vmsNewDownloadInfo *pDld, BOOL bReqTopMostDialog = FALSE);
	void EndCreateDownloads();
	void BeginCreateDownloads();
	void OnBtDownloadDefProperties();
	BOOL CreateNewTorrent();
	static HMENU Plugin_GetViewMenu();
	static HMENU Plugin_GetMainMenu();
	BOOL IsMediaDownload (vmsDownloadSmartPtr dld);
	int DeleteDownloads(DLDS_LIST_REF v, BOOL bByUser, BOOL bDontConfirmFileDeleting);
	void ShowDownloads (DLDS_LIST_REF v);
	
	BOOL CreateBtDownload(
		LPCTSTR pszFile, 
		LPCTSTR pszTorrentUrl, 
		BOOL bSilent = FALSE, 
		BOOL bSeedOnly = FALSE, 
		LPCTSTR pszOutputOrSrcForSeedFolder = NULL, 
		LPCTSTR ptszUserName = NULL, 
		LPCTSTR ptszPassword = NULL, 
		int* pnProirities = 0,
		vmsBtFile* tempTorrent = NULL,
		UINT *pnDownloadId = NULL);
	
	void OnBtDownloadProperties(DLDS_LIST &vDlds, CWnd* pwndParent = NULL);
	
	void OnTpDownloadProperties(DLDS_LIST &vDlds, CWnd* pwndParent = NULL);
	
	void UpdateNumbersOfDownloadsInGroups();
	
	
	void DeleteDeadDownloadsInList();
	
	void OnGroupNameChanged (vmsDownloadsGroupSmartPtr pGroup);
	
	void CheckDldHasOpinions (vmsDownloadSmartPtr dld);
	
	UINT getTotalDownloadingSpeed();
	UINT getTotalUploadingSpeed();
	
	void set_DontUpdateTIPO (BOOL b);
	
	
	void RestartDownload (vmsDownloadSmartPtr dld, BOOL bSelThisDld);
	
	CDownloads_Downloads m_wndDownloads;
	
	BOOL IsFindNextAvail();
	
	void SelectDeletedDownload (vmsDownloadSmartPtr dld);
	
	void ShowDeletedDownloads();
	
	void SelectHistRecord (fsDLHistoryRecord* rec);
	
	void ShowAllHistory();
	
	void FindDownloads_FindNext();
	
	void FindDownloads_Start();
	
	void SelectDownload (vmsDownloadSmartPtr dld);
	
	void ShowAllDownloads();
	
	void ApplyHistoryCurrentFilter();
	
	void Set_DWWN (fsDLsWndWhatIsNow en);
	CDownloads_Deleted m_wndDeleted; 
	
	
	void ApplyDWWN(BOOL bRecalcSize = FALSE);
	
	fsDLsWndWhatIsNow Get_DWWN();
	CDownloads_History m_wndHistory;	
	
	
	BOOL CreateDownloadWithDefSettings (vmsDownloadSmartPtr dld, LPCSTR pszUrl);
	
	BOOL IsSizesInBytes();
	
	fsDldFilter* GetCurrentFilter();
	
	void ApplyCurrentFilter();
	
	void FilterDownloads (fsDldFilter* filter);
	
	
	static void Plugin_SetLanguage (wgLanguage, HMENU hMenuMain, HMENU);
	static void Plugin_GetPluginNames (LPCSTR* ppszLong, LPCSTR* ppszShort);
	static void Plugin_GetMenuViewItems (wgMenuViewItem** ppItems, int* cItems);
	static void Plugin_GetMenuImages (fsSetImage** ppImages, int* pcImages);
	static void Plugin_GetToolBarInfo (wgTButtonInfo** ppButtons, int* pcButtons);
	static HWND Plugin_CreateMainWindow (HWND hParent);
	
	
	void DeleteDownload (vmsDownloadSmartPtr dld, BOOL bByUser, BOOL bDontConfirmFileDeleting = FALSE);
	
	void OnDownloadsGroupChanged ();
	
	void UpdateDownload (vmsDownloadSmartPtr dld, BOOL bWithFile = FALSE);
	
	void OnNewGroupCreated (vmsDownloadsGroupSmartPtr pGroup);
	
	
	void CreateDownload (vmsDownloadSmartPtr dld, struct fsSchedule *task = NULL, BOOL bDontUseSounds = FALSE, bool bPlaceToTop = false);
	
	void ShowAllGroups (BOOL bShow);
	
	
	void SaveAll(DWORD dwWhat);
	
	
	void CreateDownloads(DLDS_LIST &vDlds, struct fsSchedule *task, BOOL bDontUseSounds = FALSE, bool bPlaceToTop = false);
	
	
	void UpdateAllDownloads();
	
	void DeleteCompletedDownloadsInList();
	
	void DeleteDownloadsInList();
	
	void StopDownloadsInList();
	
	void StartDownloadsInList();
	
	void UpdateTrayIconPlusOthers();
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	UINT CreateDownload (LPCSTR pszStartUrl, BOOL bReqTopMostDialog = FALSE, LPCSTR pszComment = NULL, LPCSTR pszReferer = NULL, BOOL bSilent = FALSE, DWORD dwForceAutoLaunch = DWCD_NOFORCEAUTOLAUNCH, BOOL* pbAutoStart = NULL, vmsDWCD_AdditionalParameters* pParams = NULL, UINT* pRes = NULL);
	
	afx_msg void OnDownloadCreate();
	afx_msg void OnTpDownloadCreate();
	
	
	void OnOptimizationWizard();
	
	void OnDownloaderProperties();
	
	void OnDownloadDefProperties();
	
	BOOL DeleteGroup (vmsDownloadsGroupSmartPtr pGroup);
	
	void OnDownloadProperties (DLDS_LIST &vDlds, CWnd* pwndParent = NULL);
	
	void SetActiveDownload (vmsDownloadSmartPtr dld);
	
	BOOL Create (CWnd *pParent);
	CDownloads_Groups m_wndGroups;	

	virtual ~CDownloadsWnd();

	fsClipboardCatchMgr m_ClpbrdCatch;	

	
protected:
	afx_msg LRESULT OnDwSuchTorrentExistsAlready (WPARAM, LPARAM);
	struct WmDwDldsAdded
	{
		DLDS_LIST vDlds;
		bool bPlaceToTop;
		bool bDontUseSounds;
	};
	afx_msg LRESULT OnWmDwDldsAdded (WPARAM, LPARAM);
	void onDownloadsHasBeenAdded_imp(DLDS_LIST &vDlds, bool bPlaceToTop, BOOL bDontUseSounds);
	afx_msg LRESULT OnShowOnDlDoneNotification (WPARAM wp, LPARAM lp);
	BOOL m_bDontUseSoundsForDownloadsHasBeenJustAdded;
	bool m_bDownloadsHasBeenAddedToTop;
	DLDS_LIST m_vDownloadsHasBeenAdded;
	vmsCriticalSection m_csDownloadsHasBeenAdded;
	void onDownloadsHasBeenAdded (DLDS_LIST &vDlds, bool bPlaceToTop, BOOL bDontUseSounds);
	bool m_bCreatingLotOfDownloads;
	afx_msg LRESULT OnWmDldLaunch (WPARAM wp, LPARAM lp);
	DLDS_LIST m_vUploadDownloads;
	afx_msg LRESULT OnDldConvertMedia (WPARAM, LPARAM lp);
	
	bool m_bDeletingManyDownloads;
	
	
	void OnDldHasOpinions (vmsDownloadSmartPtr dld);
	
	static DWORD WINAPI _threadCheckDldHasOpinions (LPVOID lp);
	
	
	afx_msg LRESULT OnDldShowOpinions (WPARAM, LPARAM lp);
	
	UINT m_uTotalSpeed;
	
	LRESULT afx_msg OnDWUpdateDldDialog(WPARAM, LPARAM lp);
	afx_msg LRESULT OnDWCloseDldDialog (WPARAM, LPARAM lp);
	afx_msg LRESULT OnDWCreateDldDialog (WPARAM, LPARAM lp);
	struct DwDldsMgrEventParam
	{
		vmsDownloadSmartPtr dld;
		fsDLHistoryRecordPtr rec;
		fsDownloadsMgrEvent ev;
		int iDldLogEntry; 
	};
	std::vector <DwDldsMgrEventParam> m_vDldsMgrEvents;
	vmsCriticalSection m_csDldsMgrEvents;
	afx_msg LRESULT OnDwDldsMgrEvent (WPARAM, LPARAM);
	
	BOOL m_bDontUpdateTIPO;
	
	fsFindDownloadMgr m_finder;
	
	fsDLsWndWhatIsNow m_enDWWN;
	
	afx_msg LRESULT OnInsert (WPARAM, LPARAM);
	
	
	
	static DWORD WINAPI _threadFilterDownloads (LPVOID lp);
	
	
	void FilterDownloads2 (fsDldFilter *filter, int* pProgress = NULL);
	
	afx_msg void OnDLListShowCol (UINT uCmd);
	
	afx_msg void OnDLLogShowCol (UINT nCmd);
	
	
	void UpdateDLLogColMenu (CMenu* menu);
	void UpdateDLListColMenu (CMenu* menu);
	
	afx_msg LRESULT OnUpdateMenuView (WPARAM, LPARAM lp);
	
	void ApplyLanguageToMenuView (CMenu* menu);

	

	
	afx_msg void OnShowDownloadingInfo ();
	
	afx_msg void OnShowAllGroups ();
	BOOL m_bShowGroups;	
	
	afx_msg LRESULT OnUpdateToolBar (WPARAM wp, LPARAM);
	
	afx_msg LRESULT OnUpdateMenu (WPARAM, LPARAM lp);
	BOOL m_bExiting;	
	
	afx_msg LRESULT OnAppQueryExit (WPARAM, LPARAM);
	
	static DWORD _Events (fsDownload* dld, fsDLHistoryRecord *rec, fsDownloadsMgrEvent ev, LPVOID lp);
	
	afx_msg LRESULT OnAppExit (WPARAM, LPARAM);
	
	BOOL LoadDownloads();
	CWndSplitter m_splitter;	
	long m_cCheckDldHasOpinionsThreads;

	//{{AFX_MSG(CDownloadsWnd)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnDestroy();
	afx_msg void OnDlddelete();
	afx_msg void OnDldlaunch();
	afx_msg void OnDldopenfolder();
	afx_msg void OnDldproperties();
	afx_msg void OnDldstart();
	afx_msg void OnDldstop();
	afx_msg void OnDldschedule();
	afx_msg void OnDldautostart();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnDldaddsection();
	afx_msg void OnDlddelsection();
	afx_msg void OnDldrestart();
	afx_msg void OnDldqsize();
	afx_msg void OnDldcreatebatch();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnDldcheckvir();
	afx_msg void OnDldfind();
	afx_msg void OnDldfindnext();
	afx_msg void OnDldunpack();
	afx_msg void OnDldmovedown();
	afx_msg void OnDldmoveup();
	afx_msg void OnDldcheckintegrity();
	afx_msg void OnDldmovetofolder();
	afx_msg void OnDldmovebottom();
	afx_msg void OnDldmovetop();
	afx_msg void OnDldschedulestop();
	afx_msg void OnDldgrantbandwidthfordld();
	afx_msg void OnDldshowprogressdlg();
	afx_msg void OnDldconvert();
	afx_msg void OnDldenableseeding();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	
	void onEvents(fsDownload* dld, fsDLHistoryRecord *rec, fsDownloadsMgrEvent ev, int iDldLogEntry);
	void OnDownloadPreCreate(fsDownload* dld, vmsDWCD_AdditionalParameters* pParams);
	void OnDownloadPreCreate_AdjustFileSharingSiteSupport(fsDownload* dld, vmsDWCD_AdditionalParameters* pParams);
	LPCSTR isKnownFileSharingSite(fsDownload* dld);
	void OnDownloadPostCreate(fsDownload* dld);
};

//{{AFX_INSERT_LOCATION}}

#endif 
