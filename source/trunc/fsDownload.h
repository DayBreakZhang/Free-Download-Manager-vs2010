/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __FS_DOWNLOAD_
#define __FS_DOWNLOAD_

#include "vmsDownloadMgrEx.h"
#include "vmsDownloadsGroupsMgr.h"
#include "fsTicksMgr.h"
#include "vmsPersistObject.h"

extern vmsDownloadsGroupsMgr _DldsGrps;

struct fsDownload;

struct fsDownloadEvents
{
	CString strEvent;	
	COLORREF clrBg;		
	COLORREF clrText;	
	FILETIME timeEvent;	
	int iImage;		
};

typedef DWORD (*fntDownloadsMgrEventFunc)(struct fsDownload* dld, struct fsDLHistoryRecord *phst, enum fsDownloadsMgrEvent ev, LPVOID);

#define DLD_CHANGENOTRECOMMENDED		(1 << 0)

#define DLD_DELETEFILEALWAYS			(1 << 1)

#define DLD_DONTUSEMIRRORS				(1 << 2)

#define DLD_CTREQ_HTML					(1 << 3)

#define DLD_NOTIFYBEFOREDOWNLOAD		(1 << 4)

#define DLD_DELETEWHENDONE				(1 << 5)

#define DLD_DONTPUTTOHISTORY			(1 << 6)

#define DLD_DONTPUTTORECYCLE			(1 << 7)

#define DLD_NOTIFICATIONS_LL			(1 << 8)

#define DLD_NOAUTOLAUNCH				(1 << 9)

#define DLD_DELETEFILEATRESTART			(1 << 10)

#define DLD_DONTSHOWDIALOG				(1 << 11)

#define DLD_USEDBYHTMLSPIDER			(1 << 12)

#define DLD_NOAUTOCHANGECURGRPFILTER	(1 << 13)

#define DLD_MALICIOUS_YES				(1 << 14)
#define DLD_MALICIOUS_NO				(1 << 15)
#define DLD_HASOPINIONS_YES				(1 << 16)
#define DLD_HASOPINIONS_NO				(1 << 17)

#define DLD_BATCH						(1 << 18)

#define DLD_MALICIOUS_DISABLE_CHECK		(1 << 19)

#define DLD_FLASH_VIDEO					(1 << 20)

#define DLD_MF_AUTO_CONVERT				(1 << 21)

#define DLD_NEED_ONDONE_FOR_FLASH_VIDEO	(1 << 22)

#define DLD_TORRENT_DOWNLOAD			(1 << 23)

#define DLD_WAS_DELETED					(1 << 24)

#define DLD_TP_DOWNLOAD					(1 << 25)

#define DLDS_FILE_WAS_LAUNCHED_AT_LEAST_ONCE	(1 << 0)
#define DLDS_REGISTERED_IN_TRAFFICUSGMGR		(1 << 1)

struct fsDownload : public vmsObject, public vmsPersistObject
{
	vmsDownloadMgrSmartPtr pMgr;	
	BOOL bAutoStart;		
	vmsDownloadsGroupSmartPtr pGroup;			
	CString strComment;		
	fs::list <fsDownloadEvents> vEvents;	
	tstring tstrLastErrMsg;
	UINT nID;			
	DWORD dwFlags;				
	DWORD dwReserved;
protected:
	DWORD dwState; 
public:
	FILETIME dateAdded;			
	FILETIME dateCompleted;
	
	DWORD adwTimeAllowed [7]; 

	
	fntDownloadsMgrEventFunc pfnDownloadEventsFunc; 
	LPVOID lpEventsParam;				

    #ifndef FDM_DLDR__RAWCODEONLY
	class CDlg_Download *pdlg;			
	#endif

	
	fsTicksMgr ticksLastStopByProcessDownloadsFn;

	fsDownload (fsDownload& dld) 
	{
		*this = dld;
		#ifndef FDM_DLDR__RAWCODEONLY
		pdlg = NULL;
		#endif
	}

	fsDownload& operator= (fsDownload& dld)
	{
		setDownloadMgr (dld.pMgr);
		bAutoStart = dld.bAutoStart;
		pGroup = dld.pGroup;
		strComment = dld.strComment;
		vEvents = dld.vEvents; 
		nID = dld.nID;
		dwFlags = dld.dwFlags;
		dwReserved = 0;
		dwState = 0;
		dateAdded = dld.dateAdded;
		dateCompleted = dld.dateCompleted;
		CopyMemory (adwTimeAllowed, dld.adwTimeAllowed, sizeof (adwTimeAllowed));
		ticksLastStopByProcessDownloadsFn = dld.ticksLastStopByProcessDownloadsFn;

		pfnDownloadEventsFunc = dld.pfnDownloadEventsFunc;
		lpEventsParam = dld.lpEventsParam;

		setDirty();

		return *this;
	}

	fsDownload ()
	{
		pfnDownloadEventsFunc = NULL; dwFlags = 0; 
		pGroup = NULL;
		dwReserved = 0;
		dwState = 0;
		memset (adwTimeAllowed, 0xff, sizeof (adwTimeAllowed));
		#ifndef FDM_DLDR__RAWCODEONLY
		pdlg = NULL;
		#endif
		ticksLastStopByProcessDownloadsFn.m_dwTicks = UINT_MAX;
		ZeroMemory (&dateAdded, sizeof (dateAdded));
		ZeroMemory (&dateCompleted, sizeof (dateCompleted));
		pMgr.CreateInstance ();
		getPersistObjectChildren ()->addPersistObject (pMgr);
	}

	void setDownloadMgr (vmsDownloadMgrEx *a_pMgr)
	{
		if (pMgr)
			getPersistObjectChildren ()->removePersistObject (pMgr);
		pMgr = a_pMgr;
		if (pMgr)
			getPersistObjectChildren ()->addPersistObject (pMgr);
	}

	void getObjectItselfStateBuffer(LPBYTE pb, LPDWORD pdwSize, bool bSaveToStorage);
	bool loadObjectItselfFromStateBuffer(LPBYTE pb, LPDWORD pdwSize, DWORD dwVer);

	BOOL isTorrent () {return (dwFlags & DLD_TORRENT_DOWNLOAD) != 0 || pMgr->IsBittorrent ();}

	void LockStateSection (bool bLock) {
		static vmsCriticalSection _cs;
		if (bLock)
			EnterCriticalSection (&_cs);
		else
			LeaveCriticalSection (&_cs);
	}
	DWORD getState () const {return dwState;}
	void setStateFlags (DWORD dwFlags) {LockStateSection (true); dwState |= dwFlags; LockStateSection (false);}
	void removeStateFlags (DWORD dwFlags) {LockStateSection (true); dwState &= ~dwFlags; LockStateSection (false);}

};

typedef vmsObjectSmartPtr <fsDownload> vmsDownloadSmartPtr;

#include "fsDownloadMgr.h"
#include "vmsBtDownloadManager.h"
#include "vmsTpDownloadMgr.h"

inline void Download_CreateInstance (vmsDownloadSmartPtr &ptr, bool bBittorrent = false, bool bTp = false)
{
	ptr.CreateInstance ();

	if (bBittorrent)
	{
		vmsBtDownloadManagerPtr btmgr; btmgr.CreateInstance ();
		ptr->pMgr->Attach (btmgr);
	} else if (bTp) {
		ptr->pMgr->Attach (new vmsTpDownloadMgr);
	} else {
		ptr->pMgr->Attach (new fsDownloadMgr (ptr));
	}
}

typedef std::vector <vmsDownloadSmartPtr> DLDS_LIST, &DLDS_LIST_REF;

#endif 