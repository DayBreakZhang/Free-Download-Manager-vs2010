/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSUPDATEMGR_H__287BFC6A_1FC7_42E5_9BC8_9DEAA3381DCC__INCLUDED_)
#define AFX_FSUPDATEMGR_H__287BFC6A_1FC7_42E5_9BC8_9DEAA3381DCC__INCLUDED_

#include "fsDownloadMgr.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

#include "list.h"

enum fsUpdateMgrEvent
{
	UME_CONNECTING,				
	
	UME_RETREIVINGUPDLST,	
	UME_RETREIVINGUPDATE,		
	UME_UPDLSTDONE,				
	UME_UPDATEDONE,				
	
	UME_FATALERROR,	
	UME_NEWVERSIONAVAIL,		
	UME_NEWVERSIONNOTAVAIL,		
	UME_ERROR,					
	UME_VERIFYSIGN_ERROR,
};

typedef void (*fntUpdateMgrEventsFunc) (fsUpdateMgrEvent ev, LPVOID lp);
typedef void (*fntUpdateMgrDescEvents) (LPCSTR pszEvent, LPVOID lp);

class fsUpdateMgr
{
	friend class CPrg_UpdatePage;
public:
	enum Flags
	{
		IgnoreUpdateInAutomaticMode		= 1,
	};

	
	void CheckForUpdate(bool bByUser);
	
	
	
	
	void Update (BOOL bByFull);
	
	
	
	
	BOOL StartUpdater();
	
	
	
	BOOL IsStartUpdaterNeeded(BOOL bUpdaterWillBeLaunchedNow = TRUE);
	
	
	void UpdateOnNextStart();
	
	fs::list <CString>* GetWhatNew();
	
	
	LPCSTR GetUpgSize();
	
	LPCSTR GetFullSize();
	
	void Stop();
	
	LPCSTR GetBuildNumber();
	LPCSTR GetVersion();
	
	BOOL IsRunning();
	
	
	void SetDescEventsFunc (fntUpdateMgrDescEvents pfn, LPVOID lpParam);
	void SetEventsFunc (fntUpdateMgrEventsFunc pfn, LPVOID lp);
	
	
	void ReadSettings();
	void SaveSettings();
	
	vmsAutoUpdateType m_enAUT;		
	CString m_strUpdateUrl;	

	fsUpdateMgr();
	virtual ~fsUpdateMgr();

	fsDownloadMgr *m_dldr;	

protected:
	
	
	static void FixIniFileFor9x (LPCSTR pszIni);
	
	bool m_bCheckingByUser;
	CString m_strUpdateFile;	

	
	void Event (LPCSTR pszEvent);
	static void _DownloadMgrDescEvents (fsDownloadMgr *pMgr, fsDownloadMgr_EventDescType enType, LPCSTR pszDesc, LPVOID lp);
	LPVOID m_lpEventsParam;
	fntUpdateMgrEventsFunc m_pfnEvents;
	LPVOID m_lpDescEventsParam;
	fntUpdateMgrDescEvents m_pfnDescEvents;
	void Event (fsUpdateMgrEvent ev);

	CString m_strDlFullInstallPath;		
	CString m_strDlUpgradesPath;		

	
	CString m_strUpgSize, m_strUpgFileName;	
	CString m_strFullSize;	
	CString m_strVersion;	
	CString m_strBN;		
	DWORD m_dwFlags;
	fs::list <CString> m_vWN; 
	
	
	void ProcessUpdateLstFile();
	BOOL m_bChecking;	

	
	static DWORD _DownloadMgrEvents (fsDownloadMgr *pMgr, fsDownloaderEvent, UINT, LPVOID lp);
	BOOL m_bRunning;	
};

#endif 
