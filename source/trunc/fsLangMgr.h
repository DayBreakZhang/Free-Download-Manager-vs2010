/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSLANGMGR_H__24624383_B5E1_4CAA_8F76_0F435FBAFE45__INCLUDED_)
#define AFX_FSLANGMGR_H__24624383_B5E1_4CAA_8F76_0F435FBAFE45__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "list.h"

#define LS(i)	_LngMgr.GetString (i)
#define LSNP(i) _LngMgr.GetStringNP (i)

struct fsLngFileInfo
{
	CString strFileName;		
	CString strFileNameWoExt;	
	CString strLngName;			
};

class fsLangMgr  
{
public:
	LPCSTR GetLngFileNameWoExt (int iIndex);
	
	BOOL Initialize ();
	
	int GetLngCount();
	
	LPCSTR GetLngName (int iIndex);
	
	int FindLngByName (LPCSTR pszName);
	
	BOOL LoadLng (int iIndex);
	
	int GetStringCount();
	
	int GetCurLng();
	
	LPCSTR GetString (int iIndex);
	
	CString GetStringNP (int iIndex);

	fsLangMgr();
	virtual ~fsLangMgr();

protected:
	void PreprocessLanguageString (CString& str);
	
	void LoadBuiltInLngStrings();
	
	
	void AddLngFileInfo (fsLngFileInfo& info);
	int m_iCurLng;	
	fs::list <fsLngFileInfo> m_vLngFiles;	
	fs::list <CString> m_vStrings;		
	fs::list <CString> m_vBuiltInStrings;	
	CString m_strLngFolder;
};

#endif 
