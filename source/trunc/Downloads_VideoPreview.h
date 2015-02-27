/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DOWNLOADS_VIDEOPREVIEW_H__DDAE623A_07E2_462E_9B01_D74ADD37EE11__INCLUDED_)
#define AFX_DOWNLOADS_VIDEOPREVIEW_H__DDAE623A_07E2_462E_9B01_D74ADD37EE11__INCLUDED_

#include "VideoWindow.h"	
#include "DlgVidMan.h"	
#include "DlgVidSeek.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

#include "fsDownload.h"
#include "shockwaveflash.h"	

class CDownloads_VideoPreview : public CWnd
{
	friend class CDownloadsWnd;

public:
	CDownloads_VideoPreview();       
	virtual ~CDownloads_VideoPreview();

public:
	BOOL IsMuteAvail();
	BOOL IsPaused();
	BOOL IsPauseAvail();
	BOOL IsPlaying();
	void set_InFVDownloads(BOOL b);
	void Convert();
	void ApplyLanguage();
	void SaveState();
	
	void UpdateCommand (UINT nID, BOOL* pbEnabled, BOOL* pbChecked);
	
	CString GetDuration();
	
	UINT64 Get_AvailFileSize();
	
	UINT64 Get_FileSize();
	
	CString Get_FileName();
	
	
	void Set_Volume (long lVolume);
	fsPartMediaPlayer* Get_Player();
	
	void Play();
	
	vmsDownloadSmartPtr Get_ActiveDownload();
	
	void Pause();
	
	void Stop();
	
	CVideoWindow m_wndVideo;
	BOOL Create (CWnd* pWndParent);
	
	void Set_ActiveDownload (vmsDownloadSmartPtr dld);

	
	//{{AFX_VIRTUAL(CDownloads_VideoPreview)
	protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

protected:
	BOOL m_bUsingVideo2;
	CShockwaveFlash m_wndVideo2;
	
	BOOL OpenFile();
	
	void CloseFile();
	DWORD m_dwDXVersion;	
	
	afx_msg LRESULT OnGraphMessage(WPARAM, LPARAM);
	
	CDlgVidSeek m_vidseek;
	
	CDlgVidMan m_vidman;
	HANDLE m_hFile; 
	vmsDownloadSmartPtr m_pActiveDownload;

	
	//{{AFX_MSG(CDownloads_VideoPreview)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
