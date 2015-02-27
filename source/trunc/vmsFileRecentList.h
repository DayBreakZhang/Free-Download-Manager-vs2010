/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSFILERECENTLIST_H__A4B7CD08_47AB_4114_8532_B8287C88932C__INCLUDED_)
#define AFX_VMSFILERECENTLIST_H__A4B7CD08_47AB_4114_8532_B8287C88932C__INCLUDED_

#include "vmsPersistObject.h"

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsFileRecentList : public vmsPersistObject
{
public:
	void setMaxSize (int i);
	
	int get_Count () const;
	
	LPCSTR get_FilePathName(int nIndex) const;
	
	LPCSTR get_FileDispName (int nIndex) const;
	
	void Clear(bool bDontQueryStoringStateInformation = false);
	
	BOOL Load (HANDLE hFile);
	BOOL Save (HANDLE hFile);
	
	void Add (LPCSTR pszFileDispName, LPCSTR pszFilePathName, bool bDontQueryStoringStateInformation = false);

	virtual void getObjectItselfStateBuffer(LPBYTE pb, LPDWORD pdwSize, bool bSaveToStorage);
	virtual bool loadObjectItselfFromStateBuffer(LPBYTE pb, LPDWORD pdwSize, DWORD dwVer);

	vmsFileRecentList();
	virtual ~vmsFileRecentList();

protected:
	struct _inc_FileInfo
	{
		fsString strPathName;
		fsString strDispName;
	};
	
	std::vector <_inc_FileInfo> m_vList;
	
	int m_nMaxEntries;
	CRITICAL_SECTION m_cs;
};

#endif 
