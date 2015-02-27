/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSPARTMEDIAPLAYER_H__384930FA_5C16_47F9_8B3B_95612C5F0C9A__INCLUDED_)
#define AFX_FSPARTMEDIAPLAYER_H__384930FA_5C16_47F9_8B3B_95612C5F0C9A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include <windows.h>
#include <dshow.h>
#include <limits.h>
#include "fsFileReader.h"	

#define WM_VIDEONOTIFY	(WM_USER + 100)

enum fsPartMediaPlayerState
{
	VFPS_CLOSED,	
	VFPS_RUNNING,	
	VFPS_PAUSED,	
	VFPS_STOPPED	
};

class fsPartMediaPlayer  
{
public:
	
	HRESULT Set_Volume (long lVolume);
	
	HRESULT HandleGraphEvent();
	
	IMediaSeeking* Get_MediaSeeking ();
	
	fsPartMediaPlayerState Get_State();
	
	HRESULT NotifyOwnerMessage (HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
	
	void AutoSize();
	
	HRESULT Close();
	
	void Initialize (HWND hVideoOutWindow);

	HRESULT Stop();
	HRESULT Pause();
	HRESULT Run();

	
	HRESULT Open (HANDLE hFile, UINT64 uMaxAvail = _UI64_MAX);

	
	HRESULT Open2 (LPCSTR pszFile);

	fsPartMediaPlayer();
	virtual ~fsPartMediaPlayer();

protected:
	HRESULT m_hr;
	fsFileStream m_stream;
	fsFileReader m_reader;
	fsPartMediaPlayerState m_state;
	HWND m_hOutWnd;
	IGraphBuilder* m_pGB;
	IMediaControl* m_pMC;
	IMediaEventEx* m_pME;
	IMediaSeeking* m_pMS;
	IVideoWindow* m_pVW;
	IBasicAudio* m_pBA;
	double m_fVideoRatio; 
};

#endif 
