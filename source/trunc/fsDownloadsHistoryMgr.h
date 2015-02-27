/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSDOWNLOADSHISTORYMGR_H__EDB70A83_62F7_4001_8C36_E948F4B569BF__INCLUDED_)
#define AFX_FSDOWNLOADSHISTORYMGR_H__EDB70A83_62F7_4001_8C36_E948F4B569BF__INCLUDED_

#include "vmsPersistObject.h"

#if _MSC_VER > 1000
#pragma once
#endif 

struct fsDLHistoryRecord : public vmsObject
{
	fsString strFileName;		
	fsString strURL;		
	FILETIME dateAdded;             
	FILETIME dateDownloaded;	
	UINT64 uFileSize;		
	fsString strSavedTo;		
	FILETIME dateRecordAdded;	
	fsString strComment;		

	fsDLHistoryRecord (fsDLHistoryRecord& r)
	{
		*this = r;
	}

	fsDLHistoryRecord& operator = (fsDLHistoryRecord& r)
	{
		strFileName = r.strFileName;
		strURL = r.strURL;
		strComment = r.strComment;
		dateAdded = r.dateAdded;
		dateDownloaded = r.dateDownloaded;
		uFileSize = r.uFileSize;
		strSavedTo = r.strSavedTo;
		dateRecordAdded = r.dateRecordAdded;

		return *this;
	}

	fsDLHistoryRecord () {}
};

typedef vmsObjectSmartPtr <fsDLHistoryRecord> fsDLHistoryRecordPtr;

enum fsDownloadsHistoryMgrEvent
{
	DHME_RECORDADDED,
	DHME_RECORDDELETED,
	DHME_HISTORYCLEARED,
};

typedef void (*fntDHMEEventFunc)(fsDownloadsHistoryMgrEvent ev, fsDLHistoryRecord *rec, LPVOID);

#define DLHISTFILE_CURRENT_VERSION	(1)
#define DLHISTFILE_SIG "FDM Downloads History"

struct fsDownloadsHistMgrFileHdr
{
	char szSig [sizeof (DLHISTFILE_SIG) + 1];
	WORD wVer;

	fsDownloadsHistMgrFileHdr ()
	{
		strcpy (szSig, DLHISTFILE_SIG);
		wVer = DLHISTFILE_CURRENT_VERSION;
	}
};

class fsDownloadsHistoryMgr : public vmsPersistObject
{
public:
	int FindIndex (fsDLHistoryRecord *rec);
	void DeleteRecord (fsDLHistoryRecord* rec);
	fsDLHistoryRecord* GetRecord (int iIndex);
	BOOL LoadHistory();
	BOOL SaveHistory();
	int GetRecordCount();
	void AddToHistory (vmsDownloadSmartPtr dld);
	void SetEventFunc (fntDHMEEventFunc pfn, LPVOID lpParam);
	void ClearHistory ();
	
	void ReadSettings();
	void Lock () {EnterCriticalSection (&m_csRecords);}
	void Unlock () {LeaveCriticalSection (&m_csRecords);}

	virtual void getObjectItselfStateBuffer(LPBYTE pb, LPDWORD pdwSize, bool bSaveToStorage);
	virtual bool loadObjectItselfFromStateBuffer(LPBYTE pb, LPDWORD pdwSize, DWORD dwVer);

	fsDownloadsHistoryMgr();
	virtual ~fsDownloadsHistoryMgr();

protected:
	
	void Event (fsDownloadsHistoryMgrEvent ev, fsDLHistoryRecord *rec = NULL);
	
	
	
	
	
	
	bool loadHistoryRecordStrAttributes(fsDLHistoryRecordPtr& rec, LPBYTE& pbtCurrentPos, LPBYTE pbtBuffer, DWORD pdwSize, DWORD dwVer);
	bool loadHistoryRecordNonStrAttributes(fsDLHistoryRecordPtr& rec, LPBYTE& pbtCurrentPos, LPBYTE pbtBuffer, DWORD dwSize, DWORD dwVer);
	bool loadHistoryRecordAttributes(fsDLHistoryRecordPtr& rec, LPBYTE& pbtCurrentPos, LPBYTE pbtBuffer, DWORD dwSize, DWORD dwVer);

	fntDHMEEventFunc m_pfnEventFunc;
	LPVOID m_lpEvParam;
	
	void ApplySettings();
	BOOL m_bCompOnly;	
	UINT m_cDaysMax;	
	BOOL m_bUse;		
	std::vector <fsDLHistoryRecordPtr> m_vRecords;	
	vmsCriticalSection m_csRecords;
};

#endif 
