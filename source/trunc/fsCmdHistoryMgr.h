/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSCMDHISTORYMGR_H__A0BE2A45_DC68_4ED6_9724_A64D2419D197__INCLUDED_)
#define AFX_FSCMDHISTORYMGR_H__A0BE2A45_DC68_4ED6_9724_A64D2419D197__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "list.h"
#include "vmsPersistObject.h"

class fsCmdHistoryMgr : public vmsPersistObject 
{
public:
	
	void Set_MaxDaysCount (int cMax);
	
	void Set_NoHistory (BOOL b);
	
	void ClearHistory();
	
	void Set_MaxRecordCount (int iMax);
	
	void AddRecord (LPCSTR pszRecord);
	
	LPCSTR GetRecord (int iRec);
	
	int GetRecordCount();
	
	BOOL SaveToFile (HANDLE hFile);
	
	BOOL ReadFromFile (HANDLE hFile);

	virtual void getObjectItselfStateBuffer(LPBYTE pb, LPDWORD pdwSize, bool bSaveToStorage);
	virtual bool loadObjectItselfFromStateBuffer(LPBYTE pb, LPDWORD pdwSize, DWORD dwVer);

	fsCmdHistoryMgr();
	virtual ~fsCmdHistoryMgr();

protected:
	
	struct fs1DayRecords : public vmsObject, public vmsPersistObject
	{
		FILETIME day;	
		
		
		
		fs::list <CString> vRecs;

		virtual void getObjectItselfStateBuffer(LPBYTE pb, LPDWORD pdwSize, bool bSaveToStorage);
		virtual bool loadObjectItselfFromStateBuffer(LPBYTE pb, LPDWORD pdwSize, DWORD dwVer);
	};

	typedef vmsObjectSmartPtr<fs1DayRecords> vms1DayRecordsSmartPtr;

	
	
	
	fs::list <vms1DayRecordsSmartPtr> m_vRecs;
	int m_cMaxRecords;			
	SYSTEMTIME m_curday;	
	BOOL m_bNoHistory;	
	int m_cMaxDays;	
};

#endif 
