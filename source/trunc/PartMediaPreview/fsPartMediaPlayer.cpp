/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "fsPartMediaPlayer.h"
#include "../common.h"

fsPartMediaPlayer::fsPartMediaPlayer() : 
	m_reader (&m_stream, &m_hr)
{
	m_pGB = NULL;
	m_pMC = NULL;
	m_pME = NULL;
	m_pMS = NULL;
	m_pVW = NULL;
	m_pBA = NULL;
	m_hOutWnd = NULL;

	m_reader.AddRef ();

	m_state = VFPS_CLOSED;

	m_fVideoRatio = 1;
}

fsPartMediaPlayer::~fsPartMediaPlayer()
{
	Close ();
}

HRESULT fsPartMediaPlayer::Open(HANDLE hFile, UINT64 uMaxAvail)
{
	HRESULT hr;

	Close ();

	
	m_stream.Attach (hFile, uMaxAvail);

	
	if (m_stream.Get_MediaType () == NULL)
		return E_FAIL;

	m_reader.Set_MediaType (m_stream.Get_MediaType ());

	

	RIF (CoCreateInstance (CLSID_FilterGraph, NULL, CLSCTX_INPROC,
		IID_IGraphBuilder, (void**) &m_pGB));

	IFilterGraph* pFG = NULL;
	RIF (m_pGB->QueryInterface (IID_IFilterGraph, (void**)&pFG));

	RIF (pFG->AddFilter (&m_reader, NULL));
	pFG->Release ();

	RIF (m_pGB->Render (m_reader.GetPin (0)));

	RIF (m_pGB->QueryInterface (IID_IMediaControl, (void**)&m_pMC));
	RIF (m_pGB->QueryInterface (IID_IMediaEventEx, (void**)&m_pME));
	RIF (m_pGB->QueryInterface (IID_IMediaSeeking, (void**)&m_pMS));
	
	m_pGB->QueryInterface (IID_IVideoWindow, (void**)&m_pVW);
	m_pGB->QueryInterface (IID_IBasicAudio, (void**)&m_pBA);

	IBasicVideo* pBV = NULL;
	m_pGB->QueryInterface (IID_IBasicVideo, (void**) &pBV);
	if (pBV != NULL)
	{
		long nW, nH;
		pBV->get_VideoWidth (&nW);
		pBV->get_VideoHeight (&nH);
		m_fVideoRatio = (double)nW / nH;
		pBV->Release ();
	}
	else
	{
		m_fVideoRatio = 1;
	}

	if (m_pVW)
	{
		if (FAILED (m_pVW->put_MessageDrain ((OAHWND)m_hOutWnd)))
		{
			SAFE_RELEASE (m_pVW);
		}
	}

	RIF (m_pME->SetNotifyWindow ((OAHWND)m_hOutWnd, WM_VIDEONOTIFY, LONG(this)));

	if (m_pVW)
	{
		m_pVW->put_Visible (OAFALSE);
		m_pVW->put_WindowStyle (WS_CHILD);
		m_pVW->put_Owner ((OAHWND)m_hOutWnd);

		AutoSize ();

		m_pVW->put_Visible (OATRUE);

		m_pVW->SetWindowForeground (-1);
	}

	m_state = VFPS_STOPPED;

	return S_OK;
}

HRESULT fsPartMediaPlayer::Run()
{
	m_state = VFPS_RUNNING;
	return m_pMC->Run ();
}

HRESULT fsPartMediaPlayer::Pause()
{
	m_state = VFPS_PAUSED;
	return m_pMC->Pause ();
}

HRESULT fsPartMediaPlayer::Stop()
{
	HRESULT hr;

	m_state = VFPS_STOPPED;

	hr = m_pMC->Stop ();
	if (FAILED (hr))
		return hr;

	
    OAFilterState fs;
    hr = m_pMC->GetState(500, &fs);

	if (m_pMS)
	{
		LONGLONG pos = 0;
		m_pMS->SetPositions (&pos, AM_SEEKING_AbsolutePositioning,
                 NULL, AM_SEEKING_NoPositioning);
	}

	hr = m_pMC->StopWhenReady ();
	if (FAILED (hr))
		return hr;

	return S_OK;
}

void fsPartMediaPlayer::Initialize(HWND hVideoOutWindow)
{
	m_hOutWnd = hVideoOutWindow;
}

HRESULT fsPartMediaPlayer::Close()
{
	HRESULT hr = S_OK;

	if (m_pMC)
		hr = m_pMC->Stop ();

	if (m_pVW)
	{
		m_pVW->put_Visible (OAFALSE);
		m_pVW->put_Owner (NULL);
	}

	SAFE_RELEASE (m_pVW);
	SAFE_RELEASE (m_pBA);
	SAFE_RELEASE (m_pMS);
	SAFE_RELEASE (m_pME);
	SAFE_RELEASE (m_pMC);
	SAFE_RELEASE (m_pGB);

	m_state = VFPS_CLOSED;

	m_stream.Detach ();

	return hr;
}

void fsPartMediaPlayer::AutoSize()
{
	if (m_pVW && m_hOutWnd)
	{
		RECT rc;
		GetClientRect (m_hOutWnd, &rc);
		if (rc.right && rc.bottom)
		{
			int w, h;

			if ((double)rc.right / rc.bottom > m_fVideoRatio)
			{
				
				h = rc.bottom;
				w = (int) (h * m_fVideoRatio);
			}
			else
			{
				
				w = rc.right;
				h = (int) (w / m_fVideoRatio);
			}

			m_pVW->SetWindowPosition ((rc.right - w) / 2, (rc.bottom - h) / 2, w, h);
			UpdateWindow (m_hOutWnd);
		}
	}
}

HRESULT fsPartMediaPlayer::NotifyOwnerMessage(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	if (m_pVW)
		return m_pVW->NotifyOwnerMessage (long (hWnd), msg, wp, lp);

	return S_FALSE;
}

fsPartMediaPlayerState fsPartMediaPlayer::Get_State()
{
	return m_state;
}

IMediaSeeking* fsPartMediaPlayer::Get_MediaSeeking()
{
	if (m_pMS)
		m_pMS->AddRef ();
	
	return m_pMS;
}

HRESULT fsPartMediaPlayer::HandleGraphEvent()
{
	LONG evCode, evParam1, evParam2;
	HRESULT hr=S_OK;

	if (!m_pME)
		return S_OK;
    
    while (SUCCEEDED (m_pME->GetEvent (&evCode, &evParam1, &evParam2, 0)))
    {
        if(EC_COMPLETE == evCode)
        {
			Stop ();
		}
	}

	return S_OK;
}

HRESULT fsPartMediaPlayer::Set_Volume(long lVolume)
{
	if (m_pBA)
		return m_pBA->put_Volume (lVolume);

	return S_OK;
}

HRESULT fsPartMediaPlayer::Open2(LPCSTR pszFile)
{
	HRESULT hr;

	Close ();

	RIF (CoCreateInstance (CLSID_FilterGraph, NULL, CLSCTX_INPROC_SERVER, IID_IGraphBuilder, (void**) &m_pGB));

	WCHAR wszFile [MAX_PATH];
	MultiByteToWideChar (CP_ACP, 0, pszFile, -1, wszFile, MAX_PATH);

	RIF (m_pGB->RenderFile (wszFile, NULL));

	RIF (m_pGB->QueryInterface (IID_IMediaControl, (void**) &m_pMC));
    RIF (m_pGB->QueryInterface (IID_IMediaEventEx, (void**) &m_pME));
    RIF (m_pGB->QueryInterface (IID_IMediaSeeking, (void**) &m_pMS));

	m_pGB->QueryInterface (IID_IVideoWindow, (void**) &m_pVW);

	IBasicVideo* pBV = NULL;
	m_pGB->QueryInterface (IID_IBasicVideo, (void**) &pBV);
	if (pBV != NULL)
	{
		long nW, nH;
		pBV->get_VideoWidth (&nW);
		pBV->get_VideoHeight (&nH);
		m_fVideoRatio = (double)nW / nH;
	}
	else
	{
		m_fVideoRatio = 1;
	}

    
    RIF (m_pGB->QueryInterface (IID_IBasicAudio, (void**) &m_pBA));

	BOOL bAudioOnly = m_pVW == NULL || pBV == NULL;

	if (pBV)
		pBV->Release ();

	if (bAudioOnly == FALSE)
	{
		long l;
		if (FAILED (m_pVW->get_Visible (&l)))
			bAudioOnly = TRUE;
	}

	

	if (m_pVW)
	{
		if (FAILED (m_pVW->put_MessageDrain ((OAHWND)m_hOutWnd)))
		{
			SAFE_RELEASE (m_pVW);
		}
	}

	RIF (m_pME->SetNotifyWindow ((OAHWND)m_hOutWnd, WM_VIDEONOTIFY, LONG(this)));

	if (m_pVW)
	{
		m_pVW->put_Visible (OAFALSE);
		m_pVW->put_WindowStyle (WS_CHILD);
		m_pVW->put_Owner ((OAHWND)m_hOutWnd);

		AutoSize ();

		m_pVW->put_Visible (OATRUE);

		m_pVW->SetWindowForeground (-1);
	}

	m_state = VFPS_STOPPED;

	return S_OK;
}
