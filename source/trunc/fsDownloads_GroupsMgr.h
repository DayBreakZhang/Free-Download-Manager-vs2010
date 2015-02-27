/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSDOWNLOADS_GROUPSMGR_H__735C5C82_46AB_40DB_A0B2_065CA6D69679__INCLUDED_)
#define AFX_FSDOWNLOADS_GROUPSMGR_H__735C5C82_46AB_40DB_A0B2_065CA6D69679__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "list.h"

#define MAX_GROUP_LEN	100

#define MAX_EXTS_LEN	1000

#define GRP_OTHER_NAME	"Other"

struct fsDownloadGroup
{
	CHAR szName [MAX_GROUP_LEN+1];	
	CHAR szOutFolder [MY_MAX_PATH+1];	
	CHAR szExts [MAX_EXTS_LEN+1];	
	BOOL bOther;			

	fsDownloadGroup () {
		bOther = FALSE;
	}
};

class fsDownloads_GroupsMgr
{
public:
	void SetGroupFolder(int iGrp, LPCSTR pszFldr);
	LPCSTR GetGroupFolder (int iGrp);
	
	void CreateGroup (fsDownloadGroup* grp);
	
	void DeleteGroup (LPCSTR pszGroup);
	
	
	int FindGroupByName (LPCSTR pszName);
	
	int FindGroupByExt (LPCSTR pszExt);
	
	LPCSTR GetGroupName (int iGrp);
	
	
	void UpdateGroup (int iGrp, fsDownloadGroup *grp);
	
	BOOL GetGroup (fsDownloadGroup* pGroup, int iGroup);
	
	int GetCount();

	
	BOOL SaveGroups();
	BOOL LoadGroups();

	fsDownloads_GroupsMgr();
	virtual ~fsDownloads_GroupsMgr();

protected:
	
	
	BOOL LastError (LONG lResult);
	
	
	BOOL LoadGroupsFromReg();

	HKEY m_hGroups;				
	fs::list <fsDownloadGroup> m_vGroups;	
};

#endif 
