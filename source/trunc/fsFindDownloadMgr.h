/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSFINDDOWNLOADMGR_H__058856AC_A45D_4A4E_AA62_3F8AB257CF1C__INCLUDED_)
#define AFX_FSFINDDOWNLOADMGR_H__058856AC_A45D_4A4E_AA62_3F8AB257CF1C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#define SEARCHIN_FILENAME		1
#define SEARCHIN_URL			2
#define SEARCHIN_COMMENT		4

#define SEARCHIN_LOCFILENAME	8

#define SEARCHWH_LISTOFDLDS		16
#define SEARCHWH_HISTOFDLDS		32
#define SEARCHWH_DELETED		64

#define SEARCHU_FILESIZE		128
#define SEARCHU_DLDGROUP		256
#define SEARCHU_TIME			512

class fsFindDownloadMgr  
{
public:
	
	BOOL IsFindNextAvail();
	
	BOOL FindNext();
	
	void PrepareFind();
	
	void ReadSettings();

	fsFindDownloadMgr();
	virtual ~fsFindDownloadMgr();

protected:
	BOOL IsSatisfies (fsDLHistoryRecord* rec);
	
	BOOL IsSatisfies (vmsDownloadSmartPtr dld);
	
	void FindNext_InDeleted (BOOL* pbCancel, int* piProgress);
	void FindNext_InHistoryOfDlds (BOOL* pbCancel, int* piProgress);
	void FindNext_InListOfDlds (BOOL* pbCancel, int* piProgress);
	static DWORD WINAPI _threadFindNext (LPVOID lp);
	void FindNext_imp(BOOL* pbCancel = NULL, int* piProgress = NULL);
	
	int GetElementCount ();
	
	
	int m_iIndex;
	enum fsFDM_WhereIsIndex
	{
		WII_LISTOFDLDS,	
		WII_HISTOFDLDS,	
		WII_DELETED		
	};
	fsFDM_WhereIsIndex m_enWI;	
	LPVOID m_pFoundElement;		
	
	BOOL NextFindSource (fsFDM_WhereIsIndex& wi);

	vmsDownloadsGroupSmartPtr m_pGroup;	
	FILETIME m_tFrom, m_tTo;	
	
	UINT64 m_uFileSizeFrom, m_uFileSizeTo;
	DWORD m_dwFlags;	
	fsString m_strWhat;	
};

#endif 
