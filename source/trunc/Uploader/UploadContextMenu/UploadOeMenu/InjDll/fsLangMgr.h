/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSLANGMGR_H__24624383_B5E1_4CAA_8F76_0F435FBAFE45__INCLUDED_)
#define AFX_FSLANGMGR_H__24624383_B5E1_4CAA_8F76_0F435FBAFE45__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include <windows.h>
#include "list.h"
#include <string>

extern class fsLangMgr _LngMgr;

#define LS(i)	_LngMgr.GetString (i)
#define LSNP(i) _LngMgr.GetStringNP (i)

struct fsLngFileInfo
{
	std::string strFileName;		
	std::string strLngName;			
};

class fsLangMgr  
{
public:
	
	
	BOOL Initialize (LPCSTR pszFolder);
	
	int GetLngCount();
	
	LPCSTR GetLngName (int iIndex);
	
	LPCSTR GetLngFilePathName (int iIndex);
	
	int FindLngByName (LPCSTR pszName);
	
	BOOL LoadLng (int iIndex);
	
	int GetStringCount();
	
	int GetCurLng();
	
	LPCSTR GetString (int iIndex);
	

	fsLangMgr();
	virtual ~fsLangMgr();

protected:
	void PreprocessLanguageString (std::string &str);
	
	void LoadEngFileStrings();
	
	
	void AddLngFileInfo (fsLngFileInfo& info);
	int m_iCurLng;	
	std::string m_strFolder;	
	fs::list <fsLngFileInfo> m_vLngFiles;	
	fs::list <std::string> m_vStrings;		
	fs::list <std::string> m_vEngStrings;	
};

#endif 
