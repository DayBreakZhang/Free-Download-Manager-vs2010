/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSUPDATEMGR_H__74871433_D307_4902_BCDD_0DFED73C5541__INCLUDED_)
#define AFX_FSUPDATEMGR_H__74871433_D307_4902_BCDD_0DFED73C5541__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include <wininet.h>

enum UPDATE_RESULT 
{
	UR_CONNECTION_ERROR		= 0,
	UR_NO_FRESH_VERSION		= 1,
	UR_UPDATE_AVAILABLE		= 2
};

class fsUpdateMgr  
{
public:
	void Abort();
	LPCSTR GetNewVersion();
	BOOL DownloadUpdate (LPCSTR pszFile, int *piProgress);
	int GetNewBuildNumber();
	UPDATE_RESULT CheckForUpdates();
	fsUpdateMgr(LPCSTR in_updateURL);
	virtual ~fsUpdateMgr();

protected:
	BOOL m_bNeedStop;
	BOOL UrlDownloadToFile (LPCSTR pszUrl, LPCSTR pszFile, int *piProgress = NULL);
	HINTERNET m_hInet, m_hFile;
	fsString m_strUpdateUrl;
	fsString m_strDistribUrl;
	fsString m_strNewVer;
	int m_newBuild;
};

#endif 
