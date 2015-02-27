/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSSOUNDSMGR_H__2B545D6C_1469_4EBA_AA3C_0EE4A01C8668__INCLUDED_)
#define AFX_FSSOUNDSMGR_H__2B545D6C_1469_4EBA_AA3C_0EE4A01C8668__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

enum fsSoundsMgrEvent
{
	SME_DOWNLOADCOMPLETE,		
	SME_DOWNLOADADDED,			
	SME_NOACTIVEDOWNLOADS,		
	SME_DIALINGOK,				
	SME_DIALINGFAILED,			
	SME_DOWNLOADFAILED,			
};

class fsSoundsMgr  
{
public:
	void PlaySnd (LPCSTR pszSoundFile);
	
	void Event (fsSoundsMgrEvent ev);
	void ReadSettings();
	
	fsSoundsMgr();
	virtual ~fsSoundsMgr();

protected:
	BOOL m_bUseSounds;
	
	fsString m_strDownloadComplete, m_strDownloadAdded, 
		m_strNoActiveDownloads, m_strDialingOK, m_strDialingFailed,
		m_strDownloadFailed;
};

#endif 
